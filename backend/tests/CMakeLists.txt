include(FetchContent)

FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG origin/devel
    )
    
FetchContent_MakeAvailable(Catch2)    
    
add_executable(GameTest src/GameTest.cpp)

target_link_libraries(GameTest PRIVATE Catch2::Catch2WithMain Game)

include(CTest)
enable_testing()
add_test(GameTest GameTest) 