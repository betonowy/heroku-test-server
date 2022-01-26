#include <iostream>
#include <asio.hpp>

int main() {
    asio::io_context io_context;

    asio::ip::tcp::acceptor acceptor(io_context, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), 13));

    try {
        for (;;) {
            asio::ip::tcp::socket socket(io_context);

            std::cout << "Waiting...\n";
            acceptor.accept(socket);

            std::string message("I woke!");

            asio::error_code ignored_error;
            asio::write(socket, asio::buffer(message), ignored_error);
            std::cout << "Sent message\n";
        }
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return EXIT_SUCCESS;
}
