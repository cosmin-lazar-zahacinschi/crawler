/*
 * main.cpp
 *
 *  Created on: Mar 3, 2017
 *      Author: cosmin
 */

#include <iostream>
#include <chrono>

#include "Crawler.h"
#include "Logger.h"

int main(int argc, char** argv) {

	INFO("starting...");
	crawler::Crawler c;

	std::chrono::system_clock::time_point before = std::chrono::system_clock::now();

	crawler::UniqueUrlList list = c.crawl("abc");

	std::chrono::system_clock::time_point after = std::chrono::system_clock::now();

	std::cout << "SIZE: " << list.size() << " " << std::chrono::duration_cast<std::chrono::milliseconds>(after - before).count();

	getchar();

	return 0;
}


