#include "Socket.h"
#include <iostream>
#include <string>

int main()
{
	Socket listen_sock = Socket();

	listen_sock.create();

	listen_sock.bind(8000);

	while(1)
	{
		listen_sock.listen();
		std::cout << "Server is listening..." << std::endl;

		Socket conn_sock = Socket();

		listen_sock.accept(conn_sock);

		while(1)
		{
			std::string recv_str;
			conn_sock.recv(recv_str);
			std::cout << "recved: " << recv_str << std::endl;

			conn_sock.send(recv_str);
		}
	}
}