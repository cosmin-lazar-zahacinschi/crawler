/*
 * Common.h
 *
 *  Created on: Mar 3, 2017
 *      Author: cosmin
 */

#ifndef COMMON_H_
#define COMMON_H_

#include <string>
#include <vector>
#include <set>

namespace crawler {

typedef std::string Url;
typedef std::vector<std::string> UrlList;
typedef std::set<std::string> UniqueUrlList;

enum class NotificationType {
	NTF_START = 0, NTF_VISITNEXT, NTF_GETHTML, NTF_NEWURLLIST,

	NTF_COUNT
};

}

#endif /* COMMON_H_ */
