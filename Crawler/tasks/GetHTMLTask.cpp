/*
 * GetHTMLTask.cpp
 *
 *  Created on: Mar 3, 2017
 *      Author: cosmin
 */

#include "GetHTMLTask.h"

#include <sstream>

#include "../Logger.h"
#include "../TaskManagerLoop.h"
#include "../PornGenerator.h"

namespace crawler {

GetHTMLTask::GetHTMLTask(TaskManagerLoop& parent, const Url& url) :
		Runnable(), _url(url), _parent(parent) {
}

GetHTMLTask::~GetHTMLTask() {
}

void GetHTMLTask::run() {
	INFO("Running GetHTMLTask for %s", _url);

	static int x = 0;
	UrlList list;

	_tmpMtx.lock();

	for (int i = 0; i < 2 && x < 1000000; i++) {
		std::stringstream ss;
		ss << "porn " << x++;
		list.push_back(ss.str());
	}

	_parent.notifyNewUrls(_url, list);

	_tmpMtx.unlock();

	delete this;
}

} /* namespace crawler */
