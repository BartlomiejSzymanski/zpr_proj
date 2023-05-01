add_library(AiPlayer AiPlayer.cpp)

target_link_libraries(AiPlayer PUBLIC Player)
target_include_directories(AiPlayer PUBLIC .)