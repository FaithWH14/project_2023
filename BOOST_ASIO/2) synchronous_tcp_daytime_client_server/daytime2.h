#ifndef DAYTIME2_H
#define DAYTIME2_H

#include <iostream>
#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <ctime>

using boost::asio::ip::tcp;

std::string make_daytime_string() {
	using namespace std;

	time_t now = time(0);

	return ctime(&now);
}

int daytime2_test() {
	try {
		boost::asio::io_context io_context;
		tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v4(), 13));

		for (;;) {
			tcp::socket socket(io_context);
			acceptor.accept(socket);

			std::string message = make_daytime_string();

			boost::system::error_code ignored_error;

			boost::asio::write(socket, boost::asio::buffer(message), ignored_error);
		}
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}

#endif
