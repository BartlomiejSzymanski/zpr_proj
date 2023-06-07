add_library(aiplayer AiPlayer.cpp)

target_link_libraries(aiplayer PUBLIC game)
target_include_directories(aiplayer PUBLIC .)
