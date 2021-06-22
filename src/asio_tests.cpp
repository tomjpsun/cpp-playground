#include <iostream>
#include <thread>
#include <string>

#include "asio.hpp"

using namespace std;
using namespace std::chrono_literals;

std::string readLine(asio::serial_port& serial)
    {
        //Reading data char by char, code is optimized for simplicity, not speed
        char c;
        std::string result;
        for(;;)
        {
            asio::read(serial, asio::buffer(&c,1));
	    result+=c;
	    if ( result.size() > 10 )
		    break;
        }
	return result;
    }
void serial_test() {
	asio::io_service io;
	asio::serial_port port(io, "/dev/ttyUSB0");
	port.set_option(asio::serial_port_base::baud_rate(115200));
	port.set_option(asio::serial_port_base::character_size(8));
	port.set_option(asio::serial_port_base::stop_bits(asio::serial_port_base::stop_bits::one));
	port.set_option(asio::serial_port_base::parity(asio::serial_port_base::parity::none));
	port.set_option(asio::serial_port_base::flow_control(asio::serial_port_base::flow_control::none));
	string cmd("\nV\r");
	asio::write(port, asio::buffer(cmd.c_str(), cmd.size()));
	this_thread::sleep_for(100ms);
	string result = readLine(port);
	cout << "result = " << result << endl;

        //char szSend[128];
	//char szRecv[128];
	//snprintf(szSend, sizeof(szSend), "\n%s\r", "V"); // 0x0A 0x56 0x0D
	//asio::write(port, asio::buffer(szSend, 128));
	//this_thread::sleep_for(100ms);
	//asio::read(port, asio::buffer(szRecv, 128));

}

void asio_tests()
{
	serial_test();
}
