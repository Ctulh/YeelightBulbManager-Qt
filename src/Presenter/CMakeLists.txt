set(LIB_NAME ViewModelLib)

set(LIB_INCLUDE_PATH ${PROJECT_SOURCE_DIR}/include/Presenter)
set(PROJECT_PATH ${PROJECT_SOURCE_DIR})
set(INCLUDE_PATH ${PROJECT_SOURCE_DIR}/include)

set(HEADERS ${LIB_INCLUDE_PATH}/Presenter.hpp
            ${LIB_INCLUDE_PATH}/Publisher.hpp)

set(SOURCES Presenter.cpp
            Publisher.cpp)

add_library(${LIB_NAME} ${HEADERS} ${SOURCES})

target_include_directories(${LIB_NAME} PUBLIC ${INCLUDE_PATH} ${LIB_INCLUDE_PATH} ${PROJECT_PATH})
target_link_directories(${LIB_NAME} PRIVATE ModelLib)
