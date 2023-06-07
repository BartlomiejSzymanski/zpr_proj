add_library(game Game.cpp)

target_link_libraries(game PUBLIC controler)
target_include_directories(game PUBLIC .)