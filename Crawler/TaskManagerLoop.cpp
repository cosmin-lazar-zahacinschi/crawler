/*
 * TaskManagerLoop.cpp
 *
 *  Created on: Mar 3, 2017
 *      Author: cosmin
 */

#include "TaskManagerLoop.h"

#include <Poco/Environment.h>
#include <Poco/TaskNotification.h>
#include <Poco/Observer.h>

#include <iostream>

#include "CrawlerLoop.h"
#include "Logger.h"
#include "notifications/CrawlerNotification.h"
#include "notifications/GetHTMLNotification.h"

#include "tasks/GetHTMLTask.h"

namespace crawler {

TaskManagerLoop::TaskManagerLoop(CrawlerLoop& parent) :
		Runnable(), _parent(parent), _tp(1,
				2), _running(true) {

}

TaskManagerLoop::~TaskManagerLoop() {
	_tp.joinAll();
}

void TaskManagerLoop::run() {
	INFO("TaskManagerLoop running");
	while (_running) {
		CrawlerNotification* ntf =
				dynamic_cast<CrawlerNotification*>(_queue.waitDequeueNotification());
		if (ntf != nullptr) {
			switch (ntf->type()) {
			case NotificationType::NTF_GETHTML: {
				GetHTMLNotification* ghn =
						static_cast<GetHTMLNotification*>(ntf);

				if (_tp.available() == 0) {

					_queue.enqueueNotification(
							new GetHTMLNotification(ghn->url()));
				} else {
					_tp.start(*new GetHTMLTask(*this, ghn->url()));
				}
			}
				break;
			default:
				break;
			}
			ntf->release();
		}
	}
}

void TaskManagerLoop::requestStartProcess(const Url& url) {
	INFO("Requesting start processing %s", url);
	_queue.enqueueNotification(new GetHTMLNotification(url));
}

void TaskManagerLoop::notifyNewUrls(const Url& origin, const UrlList& list) {
	_parent.newUrlReceived(origin, list);
}

bool TaskManagerLoop::hasRunningJobs() {
	return _tp.available() < _tp.capacity();
}

void TaskManagerLoop::quit() {
	_running = false;
	_queue.wakeUpAll();
}

} /* namespace crawler */
