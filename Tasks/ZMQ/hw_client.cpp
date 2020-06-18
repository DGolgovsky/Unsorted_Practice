/*
 * Hello World client in C++
 * Connects REQ socket to tcp://localhost:5555
 * Sends "Hello" to server, expects "World" back
 */

#include <zmq.hpp>
#include <string>
#include <iostream>

int main() {
	zmq::context_t context(1);
	zmq::socket_t socket(context, ZMQ_REQ);

	std::cout << "Connecting to server.." << std::endl;
	socket.connect("tcp://localhost:5555");

	// Do 10 requests, waiting each time for a response
	for (int request_nbr = 0; request_nbr < 11; ++request_nbr) {
		zmq::message_t request(5);
		memcpy(request.data(), "Hello", 5);
		std::cout << "Sending: " << (char *) request.data() << " [" << request_nbr << "]\n";
		socket.send(request);

		// Get the reply
		zmq::message_t reply;
		socket.recv(&reply);
		std::cout << "Received: " << (char *) reply.data() << "[" << request_nbr << "]\n";
	}

	return 0;
}
