#pragma once

#include <Poco\Mutex.h>

namespace crawler {
	class PornGenerator 
	{
	public:
		static std::string getNextString();

	private:
		static Poco::Mutex _mtx;
	};
}