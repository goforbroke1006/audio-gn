cmake_minimum_required(VERSION 3.10)
project(audio-gn)

set(CMAKE_CXX_STANDARD 11)

if (WIN32)
    set(CMAKE_INSTALL_PREFIX "C:\\Program Files\\audio-gn\\")
elseif (UNIX)
    set(CC, /usr/bin/clang)
    set(CXX, /usr/bin/clang++)
    set(CMAKE_INSTALL_PREFIX /usr/local/bin/)
endif ()

add_executable(audio-gn main.cpp wav.h)

install(TARGETS audio-gn DESTINATION ${CMAKE_INSTALL_PREFIX})
