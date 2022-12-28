set(LIB_NAME FileReaderLib)

set(INCLUDE_PATH ${PROJECT_SOURCE_DIR}/include/Utils/FileReader)

set(HEADERS ${INCLUDE_PATH}/FileReader.hpp)

set(SOURCES FileReader.cpp)

configure_file(${INCLUDE_PATH}/config.h.in ${INCLUDE_PATH}/config.h)

add_library(${LIB_NAME} ${HEADERS} ${SOURCES})

target_include_directories(${LIB_NAME} PUBLIC ${INCLUDE_PATH})
