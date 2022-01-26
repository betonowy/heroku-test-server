#include <iostream>

#include <asio.hpp>

int main() {
    std::cout << "Starting client...\n";

    asio::io_context io_context;

    asio::ip::tcp::resolver resolver(io_context);

    asio::ip::tcp::resolver::results_type endpoints = resolver.resolve("localhost", "13");

    asio::ip::tcp::socket socket(io_context);

    asio::connect(socket, endpoints);

    if (socket.is_open()) {
        std::cout << "Ok!\n";
    } else {
        std::cout << "NO!\n";
        return EXIT_FAILURE;
    }

    try {
        for (;;) {
            constexpr size_t ARR_SIZE = 128;

            std::array<char, ARR_SIZE> buffer{};

            asio::error_code error;

            std::streamsize len = static_cast<std::streamsize>(socket.read_some(asio::buffer(buffer), error));

            if (error == asio::error::eof) {
                break;
            } else if (error) {
                throw asio::system_error(error);
            }

            std::cout.write(buffer.data(), len);
        }
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return EXIT_SUCCESS;
}
