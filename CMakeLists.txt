cmake_minimum_required(VERSION 3.22)
project(QtWebEngineExample)

set(USE_SYSTEM_QT_IN_LINUX "ON")

# Find required Qt modules
find_package(Qt5 REQUIRED COMPONENTS WebEngine WebEngineWidgets WebChannel)

# Collect source files
file(GLOB SRC_FILES src/*.cpp)

# Automatically run moc
set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# ✅ Add resources.qrc
qt5_add_resources(GENERATED_RESOURCES resources.qrc)

# Add executable and include the resource file
add_executable(${PROJECT_NAME}
  ${SRC_FILES}
  ${GENERATED_RESOURCES}
)

# Include the binary dir
target_include_directories(${PROJECT_NAME}
  PRIVATE
  ${CMAKE_CURRENT_BINARY_DIR}
)

# Link all Qt libraries
target_link_libraries(${PROJECT_NAME}
  PRIVATE
  Qt::Core
  Qt::Quick
  Qt::Network
  Qt::WebEngineWidgets
  Qt::WebEngine
  Qt::WebChannel
)
