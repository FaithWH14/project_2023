#ifndef T44_H
#define T44_H

// LEARN & PRACTICE FROM C++ BOOST LIBRARIES & MODIFY SOME CODE

#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind/bind.hpp>

class printer {
public:
	printer(boost::asio::io_context& io) : timer_(io, boost::asio::chrono::seconds(1)), count_(0) {
		timer_.async_wait(boost::bind(&printer::print, this));
	}

	~printer() {
		std::cout << "Final count value is: " << count_ << std::endl;
	}

	void print() {
		const int seconds = 3;

		if (count_ < 5) {
			int countdown = 5 - count_;
			std::cout << "Count Down from " << ((countdown - 1) * seconds) << "s" << std::endl;
			++count_;
			timer_.expires_at(timer_.expiry() + boost::asio::chrono::seconds(seconds));
			timer_.async_wait(boost::bind(&printer::print, this));
		}

	};

private:
	boost::asio::steady_timer timer_;
	int count_;
};

void tutorial4() {
	boost::asio::io_context io;
	printer p(io);
	io.run();

	return;
}

#endif
