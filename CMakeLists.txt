cmake_minimum_required(VERSION 3.15)
project (discord_gamesdk)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_JS_INC} include "./")

file(GLOB SOURCE_FILES "include/*.h" "include/*.cpp" "src/backend/*.cpp" "src/backend/*.h")

add_library(${PROJECT_NAME} MODULE ${SOURCE_FILES} ${CMAKE_JS_SRC})

set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "" SUFFIX ".node")

find_library(DISCORD_GAME_SDK 
NAMES discord_game_sdk discord_game_sdk.dll
HINTS ${CMAKE_SOURCE_DIR} ./lib ./
REQUIRED)

target_link_libraries(${PROJECT_NAME} ${CMAKE_JS_LIB})
target_link_libraries(${PROJECT_NAME} ${DISCORD_GAME_SDK})

get_target_property(OUT ${PROJECT_NAME} LINK_LIBRARIES)
message(STATUS "Linked libraries: " ${OUT})

# Include N-API wrappers
execute_process(COMMAND node -p "require('node-addon-api').include"
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        OUTPUT_VARIABLE NODE_ADDON_API_DIR
        )
string(REPLACE "\n" "" NODE_ADDON_API_DIR ${NODE_ADDON_API_DIR})
string(REPLACE "\"" "" NODE_ADDON_API_DIR ${NODE_ADDON_API_DIR})
target_include_directories(${PROJECT_NAME} PRIVATE ${NODE_ADDON_API_DIR})
add_definitions(-DNAPI_VERSION=3)