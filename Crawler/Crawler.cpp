/*
 * Crawler.cpp
 *
 *  Created on: Mar 3, 2017
 *      Author: cosmin
 */

#include "Crawler.h"

#include <Poco/Thread.h>

#include "CrawlerLoop.h"
#include "Logger.h"

namespace crawler {

Crawler::Crawler() {

}

Crawler::~Crawler() {
	// TODO Auto-generated destructor stub
}

UniqueUrlList& Crawler::crawl(const std::string& root) {

	Poco::Thread t;

	t.start(_loop);

	INFO("requesting start...");
	_loop.requestStart(root);

	t.join();

	return _loop.visited();

}

} /* namespace crawler */
