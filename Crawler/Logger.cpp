/*
 * Logger.cpp
 *
 *  Created on: Mar 3, 2017
 *      Author: cosmin
 */

#include "Logger.h"

#include <Poco/Logger.h>
#include <Poco/PatternFormatter.h>
#include <Poco/FormattingChannel.h>
#include <Poco/Message.h>
#include <Poco/ConsoleChannel.h>

namespace crawler {

Logger::Logger() {
	Poco::FormattingChannel* pFCConsole = new Poco::FormattingChannel(
			new Poco::PatternFormatter("[%q][%I][%H:%M:%S:%i]\t%t"));
	pFCConsole->setChannel(new Poco::ConsoleChannel);
	pFCConsole->open();

	_consoleLogger = &Poco::Logger::create("consoleLogger", pFCConsole, Poco::Message::PRIO_INFORMATION);
}

Logger::~Logger() {

}

Poco::Logger& Logger::logger() const {
	return *_consoleLogger;
}

Logger& Logger::instance() {
	static Logger instance;
	return instance;
}

} /* namespace crawler */
