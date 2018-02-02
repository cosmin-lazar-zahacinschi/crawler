/*
 * Crawler.h
 *
 *  Created on: Mar 3, 2017
 *      Author: cosmin
 */

#ifndef CRAWLER_H_
#define CRAWLER_H_

#include "CrawlerLoop.h"
#include "Common.h"

namespace crawler {

class Crawler {
public:

public:
	Crawler();
	virtual ~Crawler();

	UniqueUrlList& crawl(const std::string& root);

private:
	CrawlerLoop _loop;
};

} /* namespace crawler */

#endif /* CRAWLER_H_ */
