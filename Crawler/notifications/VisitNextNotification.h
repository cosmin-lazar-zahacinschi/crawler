/*
 * VisitNextNotification.h
 *
 *  Created on: Mar 3, 2017
 *      Author: cosmin
 */

#ifndef VISITNEXTNOTIFICATION_H_
#define VISITNEXTNOTIFICATION_H_

#include "CrawlerNotification.h"

namespace crawler {

class VisitNextNotification : public CrawlerNotification {
public:
	VisitNextNotification();
	virtual ~VisitNextNotification();
};

} /* namespace crawler */

#endif /* VISITNEXTNOTIFICATION_H_ */
