cmake_minimum_required(VERSION 3.16)
project(asio_test)

add_subdirectory(thirdparty)

set(CMAKE_CXX_FLAGS_DEBUG "-g -Wall -Wextra -Wpedantic")
set(CMAKE_CXX_FLAGS_RELEASE "-s -O3 -Wall -Wextra -Wpedantic")

set(CMAKE_CXX_STANDARD 17)

add_executable(asio_client client.cpp)
add_executable(asio_server server.cpp)

if (WIN32)
    set(ASIO_LIBS ws2_32 asio)
else ()
    set(ASIO_LIBS asio)
endif ()

target_link_libraries(
        asio_client
        PRIVATE
        ${ASIO_LIBS}
)

target_link_libraries(
        asio_server
        PRIVATE
        ${ASIO_LIBS}
)
