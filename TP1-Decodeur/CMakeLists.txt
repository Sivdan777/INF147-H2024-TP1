cmake_minimum_required(VERSION 3.24)
project(H2024TP1 C)

set(CMAKE_C_STANDARD 11)

set(PROJECT_HEADERS
        configuration.h
        decodeur/icd.h
        decodeur/a429.h
        decodeur/utilitaire.h
        udp/port_udp.h)

set(PROJECT_SOURCES
        main.c
        test.c
        decodeur/a429.c
        decodeur/utilitaire.c
        udp/port_udp.c
        )

if (WIN32)
        link_libraries(ws2_32 wsock32)
endif (WIN32)
add_executable(H2024TP1 ${PROJECT_SOURCES} ${PROJECT_HEADERS})
