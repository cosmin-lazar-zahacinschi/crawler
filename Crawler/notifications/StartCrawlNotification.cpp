/*
 * StartCrawlNotification.cpp
 *
 *  Created on: Mar 3, 2017
 *      Author: cosmin
 */

#include "StartCrawlNotification.h"

namespace crawler {

StartCrawlNotification::StartCrawlNotification(const Url& root) :
		CrawlerNotification(NotificationType::NTF_START), _root(root) {

}

StartCrawlNotification::~StartCrawlNotification() {
}

Url StartCrawlNotification::root() const {
	return _root;
}

} /* namespace crawler */
