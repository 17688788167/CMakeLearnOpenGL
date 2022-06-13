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
set(GLM_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/environment/glm)
set(ENVIRONMENT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/environment)
set(IMAGE_DIR ${PROJECT_SOURCE_DIR}/environment/image)


set(GLAD_SRC ${PROJECT_SOURCE_DIR}/environment/glad/src/glad.c)
set(SRC ${PROJECT_SOURCE_DIR}/src)
set(START ${SRC}/1.Start)
#D:\CMakeTest\CMakeLearnOpenGL\src\1.1.Start.cpp

#添加依赖的头文件
include_directories(
    ${GLFW_INCLUDE_DIR}
    ${GLAD_INCLUDE_DIR}
	${GLM_INCLUDE_DIR}
	${SRC}
	${ENVIRONMENT_INCLUDE_DIR}
	${IMAGE_DIR}
)

# 添加库目录
link_directories(${PROJECT_SOURCE_DIR}/environment/glfw/lib-vc2019)

#收集文件
file(GLOB SOURCES ${CMAKE_SOURCE_DIR}/*.cpp)
file(GLOB HEADERS ${CMAKE_SOURCE_DIR}/*.h)
file(GLOB SRC_Start ${START}/*.cpp)

# 将源代码添加到此项目的可执行文件。这个貌似只能加一次，搜集好所有的，都加进去，注意glad.c
add_executable (${PROJECT_NAME}
	${HEADERS}
	${SOURCES}
	"CMakeTest.cpp"
	"CMakeTest.h"
	${GLAD_SRC}
 "src/2.lighting/1.colors/color.cpp" "src/Data.h" "src/Camera.h" "src/Actor.h")
target_link_libraries(${PROJECT_NAME} ${GLFW_LIB})


foreach(exe ${SRC_Start})
string (REPLACE ${START} "" exename ${exe})
string (REPLACE "/" "" exename ${exename})

add_executable (${exename} ${exe} "src/2.lighting/1.colors/color.cpp" "src/Data.h" "src/Camera.h" "src/Actor.h" 	${GLAD_SRC})
target_link_libraries(${exename} ${GLFW_LIB})

endforeach(exe ${SRC_Start})



