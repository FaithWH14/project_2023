#ifndef T3_H
#define T3_H

// LEARN & PRACTICE FROM C++ BOOST LIBRARIES & MODIFY SOME CODE

#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind/bind.hpp>

void print(const boost::system::error_code&, boost::asio::steady_timer *t, int *count) {
	
	if (*count < 10) {
		std::cout << "Count in #" << (10 - *count) << ", 3 seconds wait to next" << std::endl;
		++(*count);

		t->expires_at(t->expiry() + boost::asio::chrono::seconds(3));
		t->async_wait(boost::bind(print, boost::asio::placeholders::error, t, count));
	}
}

int tutorial_3() {

	boost::asio::io_context io;
	int count = 0;
	std::cout << "COUNT STARTED in 1 seconds!" << std::endl;
	boost::asio::steady_timer t(io, boost::asio::chrono::seconds(1));
	t.async_wait(boost::bind(print, boost::asio::placeholders::error, &t, &count));
	io.run();

	std::cout << "The latest value of count is " << count << "\n";

	return 0;
}

#endif
