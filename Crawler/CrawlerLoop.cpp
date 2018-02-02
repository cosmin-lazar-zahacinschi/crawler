/*
 * CrawlerLoop.cpp
 *
 *  Created on: Mar 3, 2017
 *      Author: cosmin
 */

#include "CrawlerLoop.h"

#include <Poco/Thread.h>
#include <Poco/NotificationCenter.h>
#include <Poco/Observer.h>

#include <iostream>

#include "Logger.h"
#include "notifications/StartCrawlNotification.h"
#include "notifications/VisitNextNotification.h"
#include "notifications/NewUrlListNotification.h"

namespace crawler {

CrawlerLoop::CrawlerLoop() :
		Runnable(), _running(true),  _tmLoop(*this) {
	Poco::NotificationCenter::defaultCenter().addObserver(
			Poco::Observer<CrawlerLoop, NewUrlListNotification>(*this,
					&CrawlerLoop::handleNewUrlsNotification));
	_requests = 0;
}

CrawlerLoop::~CrawlerLoop() {
}

void CrawlerLoop::requestStart(const Url& root) {
	_queue.enqueueNotification(new StartCrawlNotification(root));
}

void CrawlerLoop::newUrlReceived(const Url& origin, const UrlList& list) {
	_queue.enqueueNotification(new NewUrlListNotification(origin, list));
}

void CrawlerLoop::run() {
	Poco::Thread t;
	INFO("Starting task manager loop...");
	t.start(_tmLoop);
	while (_running) {
		CrawlerNotification* ntf =
				dynamic_cast<CrawlerNotification*>(_queue.waitDequeueNotification());
		if (ntf != nullptr) {
			switch (ntf->type()) {
			case NotificationType::NTF_START: {
				INFO("Received NTF_START");
				StartCrawlNotification* scn =
						static_cast<StartCrawlNotification*>(ntf);
				_toVisit.push(scn->root());
				_queue.enqueueNotification(new VisitNextNotification);
			}
				break;
			case NotificationType::NTF_VISITNEXT: {
				if (!_toVisit.empty()) {
					Url next = _toVisit.front();
					_toVisit.pop();
//					std::cout << _toVisit.size() << " " << next << " " << _toVisitIdx << std::endl;
					_tmLoop.requestStartProcess(next);
					_requests++;
					_queue.enqueueNotification(new VisitNextNotification);
				}
			}
				break;
			case NotificationType::NTF_NEWURLLIST: {

				NewUrlListNotification* nuln =
						static_cast<NewUrlListNotification*>(ntf);

				handleNewUrlsNotification(nuln);
				if (!_toVisit.empty()) {
					_queue.enqueueNotification(new VisitNextNotification);
				} else if (_requests == 0) {
					_running = false;
					_queue.dispatch(Poco::NotificationCenter::defaultCenter());
				}
			}
				break;
			default:
				break;
			}
			ntf->release();
		}
	}
	_tmLoop.quit();
	t.join();
}

void CrawlerLoop::handleNewUrlsNotification(NewUrlListNotification* pNF) {
//	std::cout << "Received new urls from " << pNF->origin() << std::endl;;
	_requests--;
	UrlList list = pNF->list();
//	std::cout << "!!!! " << pNF->list().size() << std::endl;
	_visited.insert(pNF->origin());
	for (int i = 0; i < (int) list.size(); i++) {

		if (!list[i].empty() && _visited.find(list[i]) == _visited.end()) {
//			std::cout << "xxxx " << list[i] << std::endl;
			_toVisit.push(list[i]);
		}
	}
}

UniqueUrlList& CrawlerLoop::visited() {
	return _visited;
}

} /* namespace crawler */
