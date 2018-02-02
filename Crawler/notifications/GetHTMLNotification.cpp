/*
 * GetHTMLNotification.cpp
 *
 *  Created on: Mar 3, 2017
 *      Author: cosmin
 */

#include "GetHTMLNotification.h"

namespace crawler {

GetHTMLNotification::GetHTMLNotification(const Url& url):
	CrawlerNotification(NotificationType::NTF_GETHTML),
	_url(url) {

}

GetHTMLNotification::~GetHTMLNotification() {

}

const Url& GetHTMLNotification::url() const {
	return _url;
}

} /* namespace crawler */
