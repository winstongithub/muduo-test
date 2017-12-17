include_directories()
set(SRC_LIST test1.cpp)
add_executable(test1 ${SRC_LIST})
TARGET_LINK_LIBRARIES(test1 pthread muduo)

set(SRC_TEST2 test2.cpp)
add_executable(test2 ${SRC_TEST2})
TARGET_LINK_LIBRARIES(test2 pthread muduo)

set(SRC_TEST3 test3.cpp)
add_executable(test3 ${SRC_TEST3})
TARGET_LINK_LIBRARIES(test3 pthread muduo)