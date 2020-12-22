#Look for installed version of CppUTest
if(DEFINED ENV{CPPUTEST_HOME})
    message(STATUS "Using CppUTest home: $ENV{CPPUTEST_HOME}")
    set(CPPUTEST_INCLUDE_DIRS $ENV{CPPUTEST_HOME}/include)
    set(CPPUTEST_LIBRARIES $ENV{CPPUTEST_HOME}/lib)
    set(CPPUTEST_LDFLAGS CppUTest CppUTestExt)
else()
    find_package(PkgConfig REQUIRED)
    pkg_search_module(CPPUTEST REQUIRED cpputest>=3.8)
    message(STATUS "Found CppUTest version ${CPPUTEST_VERSION}")
endif()


#Set project name
set (TESTABLE_PROJECT Foo)
project(${TESTABLE_PROJECT}Tests)

#Set unit tests sources
set(SOURCES

    TestMain.cpp
)

#Set testable project sources (not Main.cpp!)
set(TESTABLE_SOURCES
    
)

#Set include directories
include_directories(${CPPUTEST_INCLUDE_DIRS} ../Foo)
link_directories(${CPPUTEST_LIBRARIES})

#Build the unit tests objects and link then with the app library
add_executable(${PROJECT_NAME} ${SOURCES} ${TESTABLE_SOURCES})
target_link_libraries(${PROJECT_NAME}
    ${CPPUTEST_LDFLAGS})

#Run the test once the build is done
add_custom_command(TARGET ${PROJECT_NAME} 
    COMMAND ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${PROJECT_NAME} POST_BUILD)