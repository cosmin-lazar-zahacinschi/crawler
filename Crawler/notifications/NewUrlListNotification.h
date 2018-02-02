/*
 * NewUrlListNotification.h
 *
 *  Created on: Mar 3, 2017
 *      Author: cosmin
 */

#ifndef NEWURLLISTNOTIFICATION_H_
#define NEWURLLISTNOTIFICATION_H_

#include "CrawlerNotification.h"

namespace crawler {

class NewUrlListNotification : public CrawlerNotification {
public:
	NewUrlListNotification(const Url& origin, const UrlList& list);
	virtual ~NewUrlListNotification();

	UrlList list();
	Url origin() const;

private:
	Url _origin;
	UrlList _list;
};

} /* namespace crawler */

#endif /* NEWURLLISTNOTIFICATION_H_ */
