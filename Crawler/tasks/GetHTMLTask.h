/*
 * GetHTMLTask.h
 *
 *  Created on: Mar 3, 2017
 *      Author: cosmin
 */

#ifndef GETHTMLTASK_H_
#define GETHTMLTASK_H_

#include <Poco/Runnable.h>
#include <Poco/Mutex.h>

#include "../Common.h"

namespace crawler {

class TaskManagerLoop;

class GetHTMLTask : public Poco::Runnable {
public:
	GetHTMLTask(TaskManagerLoop& parent, const Url& url);
	virtual ~GetHTMLTask();

private:
	virtual void run() override;

private:
	const Url _url;
	TaskManagerLoop& _parent;

	Poco::Mutex _tmpMtx;
};

} /* namespace crawler */

#endif /* GETHTMLTASK_H_ */
