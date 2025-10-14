cmake_minimum_required(VERSION 3.16)
project(BankQueueSim C)

set(CMAKE_C_STANDARD 11)

# Include directories
include_directories(include)

# Source files
set(SOURCES
        src/main.c
        src/sim.c
        src/customer.c
        src/teller.c

)

# Set output directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# Create executable
add_executable(qSim ${SOURCES})

# Set executable name with .exe extension for Windows
if(WIN32)
    set_target_properties(qSim PROPERTIES OUTPUT_NAME "qSim")
    set_target_properties(qSim PROPERTIES SUFFIX ".exe")
endif()

# Link math library
target_link_libraries(qSim m)
