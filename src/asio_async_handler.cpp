//
// timer.cpp
// ~~~~~~~~~
//
// Copyright (c) 2003-2021 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// Modification by Ching Ping Sun:
//   Replace boost::bind with std::bind, remove dependency to Boost
//

#include <iostream>
#include <functional>
#include <asio.hpp>


void print(const asio::error_code& /*e*/,
	   asio::steady_timer* t, int* count)
{
	if (*count < 5)
	{
		std::cout << *count << std::endl;
		++(*count);

		t->expires_at(t->expiry() + asio::chrono::seconds(1));
		t->async_wait(std::bind(print,
					  std::placeholders::_1, t, count));
	}
}

int async_handler_test()
{
	asio::io_context io;

	int count = 0;
	asio::steady_timer t(io, asio::chrono::seconds(1));
	t.async_wait(std::bind(print,
				 std::placeholders::_1, &t, &count));

	io.run();

	std::cout << "Final count is " << count << std::endl;

	return 0;
}
