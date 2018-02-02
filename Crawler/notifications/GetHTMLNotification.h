/*
 * GetHTMLNotification.h
 *
 *  Created on: Mar 3, 2017
 *      Author: cosmin
 */

#ifndef GETHTMLNOTIFICATION_H_
#define GETHTMLNOTIFICATION_H_

#include "CrawlerNotification.h"

namespace crawler {

class GetHTMLNotification : public CrawlerNotification {
public:
	GetHTMLNotification(const Url& url);
	virtual ~GetHTMLNotification();

	const Url& url() const;

private:
	Url _url;
};

} /* namespace crawler */

#endif /* GETHTMLNOTIFICATION_H_ */
