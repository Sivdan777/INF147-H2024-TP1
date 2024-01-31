cmake_minimum_required(VERSION 3.25)
project(A2023DevoirTCH009 C)

set(CMAKE_C_STANDARD 11)

set(PROJECT_HEADERS
        configuration.h
        udp/port_udp.h
        decodeur/icd.h
        decodeur/a429.h
        decodeur/utilitaire.h)

set(PROJECT_SOURCES
        main.c
        test.c
        udp/port_udp.c
        decodeur/a429.c
        decodeur/utilitaire.c)

if (WIN32)
        link_libraries(ws2_32 wsock32)
endif (WIN32)
add_executable(A2023DevoirTCH009 ${PROJECT_SOURCES} ${PROJECT_HEADERS})
