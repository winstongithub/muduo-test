project(HELLO)
set(SRC_LIST test/counter/count.cpp)
add_executable(count ${SRC_LIST})
TARGET_LINK_LIBRARIES(count pthread)