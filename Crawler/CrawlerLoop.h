/*
 * CrawlerLoop.h
 *
 *  Created on: Mar 3, 2017
 *      Author: cosmin
 */

#ifndef CRAWLERLOOP_H_
#define CRAWLERLOOP_H_

#include <Poco/Runnable.h>
#include <Poco/NotificationQueue.h>

#include <queue>

#include "Common.h"
#include "notifications/CrawlerNotification.h"
#include "TaskManagerLoop.h"

namespace crawler {

class NewUrlListNotification;

class CrawlerLoop : public Poco::Runnable {
public:
	CrawlerLoop();
	virtual ~CrawlerLoop();

	void requestStart(const Url& root);

	void newUrlReceived(const Url& origin, const UrlList& list);

	UniqueUrlList& visited();

private:
	virtual void run() override;

	void handleNewUrlsNotification(NewUrlListNotification* pNF);

private:
	Poco::NotificationQueue _queue;
	bool _running;

	std::queue<std::string> _toVisit;
	UniqueUrlList _visited;
	//unsigned int _toVisitIdx;

	TaskManagerLoop _tmLoop;

	int _requests;
};

} /* namespace crawler */

#endif /* CRAWLERLOOP_H_ */
