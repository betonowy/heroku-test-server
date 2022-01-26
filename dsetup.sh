#!/bin/bash

# clone repository
git clone --depth 1 --recursive --shallow-submodules https://github.com/betonowy/heroku-test-server.git sources || exit 1

mkdir build || exit 1
cd build || exit 1
cmake ../sources || exit 1

# git no longer necessary
apt-get purge -y --auto-remove git || exit 1

# build
cmake --build . || exit 1

# remove sources
rm -r ../sources || exit 1

# build system no longer necessary
apt-get purge -y --auto-remove cmake gcc || exit 1

# copy executables
mv -v asio_server ../server || exit 1
mv -v asio_client ../client || exit 1
cd .. || exit 1

# remove build directory
rm -r build || exit 1
