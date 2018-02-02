/*
 * CrawlerNotification.cpp
 *
 *  Created on: Mar 3, 2017
 *      Author: cosmin
 */

#include "CrawlerNotification.h"

namespace crawler {

CrawlerNotification::CrawlerNotification(NotificationType type) :
		Notification(), _type(type) {

}

CrawlerNotification::~CrawlerNotification() {
}

NotificationType CrawlerNotification::type() const {
	return _type;
}

} /* namespace crawler */
