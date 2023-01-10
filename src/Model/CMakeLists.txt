set(LIB_NAME ModelLib)

set(INCLUDE_PATH ${PROJECT_SOURCE_DIR}/include/Model)
set(THIRD_PARTY_PATH ${PROJECT_SOURCE_DIR}/third_party)

set(HEADERS ${INCLUDE_PATH}/Model.hpp
            ${INCLUDE_PATH}/Singleton.hpp
            ${INCLUDE_PATH}/Device.hpp)

set(SOURCES Model.cpp
            Device.cpp)

add_library(${LIB_NAME} ${HEADERS} ${SOURCES})

target_include_directories(${LIB_NAME} PUBLIC ${INCLUDE_PATH} ${PROJECT_SOURCE_DIR} ${THIRD_PARTY_PATH})

target_link_libraries(${LIB_NAME} PRIVATE InetLib SocketReaderLib)
