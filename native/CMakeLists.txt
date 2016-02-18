
add_definitions(--std=c++11)
add_library(test1 SHARED test1.cpp)

if(APPLE)
add_custom_command(
            TARGET test1 
            POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:test1> ${CMAKE_SOURCE_DIR}/../Assets/Plugins/test1.bundle VERBATIM)
else()
add_custom_command(
            TARGET test1 
            POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:test1> ${CMAKE_SOURCE_DIR}/../Assets/Plugins VERBATIM)
endif()