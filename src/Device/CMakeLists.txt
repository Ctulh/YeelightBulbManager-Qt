set(LIB_NAME DeviceLib)

set(INCLUDE_PATH ${PROJECT_SOURCE_DIR}/include/Device)

set(HEADERS ${INCLUDE_PATH}/IDevice.hpp
            ${INCLUDE_PATH}/Device.hpp
            ${INCLUDE_PATH}/DeviceController.hpp)

set(SOURCES DeviceController.cpp)

add_library(${LIB_NAME} ${HEADERS} ${SOURCES})
