cmake_minimum_required(VERSION 3.0.0)

set(VERSION_NUMBER  V001) 
string(TIMESTAMP COMPILE_TIME %Y%m%d_%H%M%S)
project(PLC2PCTEST VERSION 0.1.0)
# set (Demo_VERSION_MAJOR 1)
# set (Demo_VERSION_MINOR 0)
include(CTest)
set(PROJECT_VERSION 0)
enable_testing()

 # 查找gsl.lib gslcblas.lib库文件
 find_package(GSL REQUIRED)
 include_directories(${GSL_INCLUDE_DIRS})
 include_directories(D:\\doawd\\freeglut-3.2.2.tar\\freeglut-3.2.2\\include)
# link_directories("D:\\doawd\\freeglut-3.2.2.tar\\freeglut-3.2.2\\build\\lib\\libfreeglut_static.a")
# target_link_libraries(test1 libfreeglut_static.a)
# 添加libevent
link_directories(
  /usr/local/lib
  D:\\msys64\\mingw64\\lib
)
include_directories(
  /usr/local/include/
  /usr/include
)
# Set_Target_Properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS_RELEASE "/SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")

add_compile_options(-Wall)
set(CMAKE_C_STANDARD 11)
set(ADDRESS_MODEL 64)
set(NODE_TARGET X64)
set(PROJECT_VERSION ${COMPILE_TIME})
FILE(GLOB SC_FILES "*.c" "*.h" )
add_executable(${PROJECT_NAME} WIN32 ${SC_FILES})
add_link_options(CTray PRIVATE -mwindows)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# set(PROJECT_NAME 1)
configure_file(config.h.in config.h)
include_directories(D:\\msys64\\mingw64\\include\\modbus)
find_package(PkgConfig REQUIRED)
# pkg_check_modules (find_package(Glib REQUIRED))

# 在include_directories加入${Glib_INCLUDE_DIRS}
# include_directories(${PROJECT_NAME} ${Glib_INCLUDE_DIRS})

# # 在target_link_libraries加入${Glib_LIBRARY}
# target_link_libraries(${PROJECT_NAME} ${Glib_LIBRARY})
# pkg_check_modules(GTK REQUIRED gtk+-3.0)

include_directories (${GTK_INCLUDE_DIRS})
link_directories (${GTK_LIBRARY_DIRS})

# link_directories(D:\\msys64\\mingw64\\lib)
add_definitions (${GTK_CFLAGS_OTHER})
target_link_libraries (${PROJECT_NAME} ${GTK_LIBRARIES})
target_link_libraries(${PROJECT_NAME} ${GSL_LIBRARIES})

target_link_libraries(${PROJECT_NAME} libevent_core.lib)
target_link_libraries(${PROJECT_NAME} libevent_extra.lib)
target_link_libraries(${PROJECT_NAME} sqlite3.lib)
# link_libraries(${PROJECT_NAME} ws2_32)
# link_libraries(${PROJECT_NAME} wsock32.lib)

find_path(MODBUS_INCLUDE_DIR NAMES modbus.h modbus/modbus.h REQUIRED)
message(STATUS "MODBUS_INCLUDE_DIR: ${MODBUS_INCLUDE_DIR}")


find_library(MODBUS_LIBRARY NAMES modbus REQUIRED)
message(STATUS "MODBUS_LIBRARY: ${MODBUS_LIBRARY}")

target_link_libraries(${PROJECT_NAME} modbus.a)
# target_link_libraries(${PROJECT_NAME} gthread-2.0.a  intl.a iconv.a )
target_link_libraries(${PROJECT_NAME} wsock32 ws2_32)

INCLUDE_DIRECTORIES(${PROJECT_BINARY_DIR})
include(CPack)