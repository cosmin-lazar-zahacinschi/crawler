#include "PornGenerator.h"

#include <sstream>

namespace crawler {

	Poco::Mutex PornGenerator::_mtx;

	std::string crawler::PornGenerator::getNextString()
	{
		static int x = 0;
		std::string retValue;
		_mtx.lock();
		std::stringstream ss;
		ss << "porn " << x++;
		retValue = ss.str();
		_mtx.unlock();
		return retValue;
	}
}