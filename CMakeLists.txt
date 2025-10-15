cmake_minimum_required(VERSION 3.16)
project(BankQueueSim C)

set(CMAKE_C_STANDARD 11)

include_directories(include)

set(SOURCES
        src/main.c
        src/sim.c
        src/customer.c
        src/teller.c

)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

add_executable(qSim ${SOURCES})

if(WIN32)
    set_target_properties(qSim PROPERTIES OUTPUT_NAME "qSim")
    set_target_properties(qSim PROPERTIES SUFFIX ".exe")
endif()

target_link_libraries(qSim m)
