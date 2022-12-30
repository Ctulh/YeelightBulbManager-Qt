set(LIB_NAME WidgetsLib)

set(INCLUDE_PATH ${PROJECT_SOURCE_DIR}/include/Widgets)

set(HEADERS ${INCLUDE_PATH}/SettingsButton.hpp
            ${INCLUDE_PATH}/DeviceWidget.hpp
            ${INCLUDE_PATH}/DeviceButton.hpp
            ${INCLUDE_PATH}/ToggleButton.hpp
            ${INCLUDE_PATH}/FlowLayout.hpp
            ${INCLUDE_PATH}/AddDeviceButton.hpp
            ${INCLUDE_PATH}/AuthWidget.hpp)

set(SOURCES SettingsButton.cpp
            DeviceWidget.cpp
            DeviceButton.cpp
            ToggleButton.cpp
            FlowLayout.cpp
            AddDeviceButton.cpp
            AuthWidget.cpp)


find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)


add_library(${LIB_NAME} ${HEADERS} ${SOURCES})

target_link_libraries(${LIB_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Widgets FileReaderLib)
target_include_directories(${LIB_NAME} PUBLIC ${INCLUDE_PATH} ${PROJECT_SOURCE_DIR}/include/Utils)
