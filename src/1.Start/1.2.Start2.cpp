
#include <glad/glad.h>
#include <GLFW/glfw3.h>


#include<iostream>
#include "Actor.h"
#include "Data.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	//0,0是窗口的左下角
	glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window)
{
	//按下esc键退出
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}


int main()
{
	//初始化GLFW
	glfwInit();
	//配置GLFW
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
	//创建一个窗口对象,宽和高作为它的前两个参数,第三个参数表示这个窗口的名称（标题）
	GLFWwindow* window = glfwCreateWindow(Data::SCR_WIDTH, Data::SCR_HEIGHT, "CmakeOpenGL", NULL, NULL);
	if (window == NULL)
	{
		glfwTerminate();
		return -1;
	}
	//通知GLFW将我们窗口的上下文设置为当前线程的主上下文
	glfwMakeContextCurrent(window);
	//需要函数，告诉GLFW我们希望每当窗口调整大小的时候调用这个函数,当窗口被第一次显示的时候framebuffer_size_callback也会被调用
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

		// glad: load all OpenGL function pointers
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	while (!glfwWindowShouldClose(window))
	{
		processInput(window);

		glClearColor(0.2, 0.3, 0.3, 1.0);//设置清空屏幕所用的颜色
		glClear(GL_COLOR_BUFFER_BIT);//清除颜色缓冲


		//函数会交换颜色缓冲（它是一个储存着GLFW窗口每一个像素颜色值的大缓冲），它在这一迭代中被用来绘制，并且将会作为输出显示在屏幕上。
		glfwSwapBuffers(window);
		//函数检查有没有触发什么事件（比如键盘输入、鼠标移动等）、更新窗口状态，并调用对应的回调函数（可以通过回调方法手动设置）。
		glfwPollEvents();
	}

	glfwTerminate();

	return 0;
}