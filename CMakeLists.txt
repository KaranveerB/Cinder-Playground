cmake_minimum_required(VERSION 3.27)
project(cinder_playground)

set(CMAKE_CXX_STANDARD 17)

# Windows builds are only supported with MSVC

# Setup variables
set(CINDER_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib/Cinder)

# Setup functions
function(setup_win_cinder)
    # Setup Cinder for Windows. This may or may not actually be required but it fixed some issues for me?

    # Create build directory if it doesn't exist
    file(MAKE_DIRECTORY ${CINDER_DIR}/build)
    # Run CMake configuration
    execute_process(
            COMMAND ${CMAKE_COMMAND} -B ${CINDER_DIR}/build -S ${CINDER_DIR}
    )
endfunction()

set(APP_TYPE "")

# Perform setup
if(WIN32)
    setup_win_cinder()
    set(APP_TYPE "WIN32")
ENDIF(WIN32)

# Configure libraries
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/lib/Cinder)

# Configure program
add_executable(cinder_playground ${APP_TYPE} main.cpp)

# Link
target_link_libraries(cinder_playground PRIVATE cinder)