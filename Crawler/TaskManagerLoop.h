/*
 * TaskManagerLoop.h
 *
 *  Created on: Mar 3, 2017
 *      Author: cosmin
 */

#ifndef TASKMANAGERLOOP_H_
#define TASKMANAGERLOOP_H_

#include <Poco/Runnable.h>
#include <Poco/NotificationQueue.h>
#include <Poco/TaskManager.h>
#include <Poco/ThreadPool.h>

#include "Common.h"

namespace Poco {
class TaskFinishedNotification;
}

namespace crawler {

class CrawlerLoop;

class TaskManagerLoop : public Poco::Runnable {
public:
	TaskManagerLoop(CrawlerLoop& parent);
	virtual ~TaskManagerLoop();

	virtual void run() override;

	void requestStartProcess(const Url& url);

	void notifyNewUrls(const Url& origin, const UrlList& list);

	void quit();

	bool hasRunningJobs();

private:
	CrawlerLoop& _parent;
	Poco::NotificationQueue _queue;
	Poco::ThreadPool _tp;
//	Poco::TaskManager _tm;
	bool _running;
};

} /* namespace crawler */

#endif /* TASKMANAGERLOOP_H_ */
