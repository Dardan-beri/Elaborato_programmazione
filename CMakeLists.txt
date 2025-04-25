cmake_minimum_required(VERSION 3.24)
project(elaborato_programmazione)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Configurazione wxWidgets
find_package(wxWidgets REQUIRED COMPONENTS core base net gl xrc adv)
include("${wxWidgets_USE_FILE}")

# Libreria core
add_library(core_lib STATIC
        ActivityLog.cpp
        MainFrame.cpp
        DialogAddDay.cpp
        DialogAddActivity.cpp
        DialogViewActivity.cpp
        Time.cpp
        Activity.cpp
        )

target_compile_definitions(core_lib PRIVATE
        -D_LIBCPP_DISABLE_AVAILABILITY
        )

if(APPLE)
    target_compile_options(core_lib PRIVATE
            -stdlib=libc++
            )
endif()

target_link_libraries(core_lib PRIVATE ${wxWidgets_LIBRARIES})

# Eseguibile principale
add_executable(elaborato_programmazione main.cpp)
target_link_libraries(elaborato_programmazione PRIVATE core_lib)

# Configurazione test
option(BUILD_TESTS "Build tests" ON)

if(BUILD_TESTS)
    enable_testing()
    find_package(Threads REQUIRED)
    add_subdirectory(Google_tests)
endif()