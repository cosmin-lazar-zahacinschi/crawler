/*
 * NewUrlListNotification.cpp
 *
 *  Created on: Mar 3, 2017
 *      Author: cosmin
 */

#include "NewUrlListNotification.h"

namespace crawler {

NewUrlListNotification::NewUrlListNotification(const Url& origin, const UrlList& list) :
		CrawlerNotification(NotificationType::NTF_NEWURLLIST), _origin(origin), _list(list) {
	// TODO Auto-generated constructor stub

}

NewUrlListNotification::~NewUrlListNotification() {
	// TODO Auto-generated destructor stub
}

UrlList NewUrlListNotification::list() {
	return _list;
}

Url NewUrlListNotification::origin() const {
	return _origin;
}

} /* namespace crawler */
