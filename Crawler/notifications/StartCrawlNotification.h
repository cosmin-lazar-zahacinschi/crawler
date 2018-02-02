
/*
 * StartCrawlNotification.h
 *
 *  Created on: Mar 3, 2017
 *      Author: cosmin
 */

#ifndef STARTCRAWLNOTIFICATION_H_
#define STARTCRAWLNOTIFICATION_H_

#include "CrawlerNotification.h"

namespace crawler {

class StartCrawlNotification : public CrawlerNotification {
public:
	StartCrawlNotification(const Url& root);
	virtual ~StartCrawlNotification();

	Url root() const;

private:
	Url _root;
};

} /* namespace crawler */

#endif /* STARTCRAWLNOTIFICATION_H_ */
