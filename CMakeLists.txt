# CMakeList.txt: CMakeTest 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)

project ("CMakeTest")

# TODO: 如有需要，请添加测试并安装目标。
# 检查cmake的最低版本
# 设置在VS中建立文件夹
SET_PROPERTY( GLOBAL PROPERTY USE_FOLDERS ON )

# 用${PROJECT_SOURCE_DIR}代替绝对目录

set(GLFW_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/environment/glfw/include)
# 这个不用指明路径，有库目录指定就行
set(GLFW_LIB glfw3.lib)
set(GLAD_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/environment/glad/include)
set(GLAD_SRC ${PROJECT_SOURCE_DIR}/environment/glad/src/glad.c)

#添加依赖的头文件
include_directories(
    ${GLFW_INCLUDE_DIR}
    ${GLAD_INCLUDE_DIR}
)

# 添加库目录
link_directories(${PROJECT_SOURCE_DIR}/environment/glfw/lib-vc2019)

#收集文件
file(GLOB SOURCES ${CMAKE_SOURCE_DIR}/*.cpp)
file(GLOB HEADERS ${CMAKE_SOURCE_DIR}/*.h)

# 将源代码添加到此项目的可执行文件。这个貌似只能加一次，搜集好所有的，都加进去，注意glad.c
add_executable (CMakeTest
	${HEADERS}
	${SOURCES}
	"CMakeTest.cpp"
	"CMakeTest.h"
	${GLAD_SRC}
)

#生成可执行程序
#add_executable(${PROJECT_NAME}
#	${HEADERS}
#	${SOURCES}
#	${GLAD_INCLUDE_DIR}/../src/glad.c
#)

#此处添加依赖库
target_link_libraries(${PROJECT_NAME}
	${GLFW_LIB}
)