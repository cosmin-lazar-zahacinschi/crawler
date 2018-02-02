/*
 * Logger.h
 *
 *  Created on: Mar 3, 2017
 *      Author: cosmin
 */

#ifndef LOGGER_H_
#define LOGGER_H_

#include <Poco/Logger.h>

//#define INFO(...) \
//	crawler::Logger::instance().logger().information(__VA_ARGS__); \

#define INFO(...)

#define WARN(...) \
	crawler::Logger::instance().logger().warning(__VA_ARGS__); \

#define ERR(...) \
	crawler::Logger::instance().logger().error(__VA_ARGS__); \


namespace crawler {

class Logger {
public:
	static Logger& instance();
	virtual ~Logger();

	Poco::Logger& logger() const;

private:
	Logger();
	Logger(const Logger&) = delete;
	Logger& operator=(const Logger&) = delete;

	Poco::Logger* _consoleLogger;
};

} /* namespace crawler */

#endif /* LOGGER_H_ */
