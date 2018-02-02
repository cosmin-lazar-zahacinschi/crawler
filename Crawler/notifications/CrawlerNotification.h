/*
 * CrawlerNotification.h
 *
 *  Created on: Mar 3, 2017
 *      Author: cosmin
 */

#ifndef CRAWLERNOTIFICATION_H_
#define CRAWLERNOTIFICATION_H_

#include <Poco/Notification.h>

#include "../Common.h"

namespace crawler {

class CrawlerNotification : public Poco::Notification {
public:
	CrawlerNotification(NotificationType type);
	virtual ~CrawlerNotification();

	NotificationType type() const;

private:
	NotificationType _type;
};

} /* namespace crawler */

#endif /* CRAWLERNOTIFICATION_H_ */
