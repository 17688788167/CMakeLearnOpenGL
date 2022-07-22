
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <learnopengl/Actor.h>
#include <learnopengl/Data.h>
#include <learnopengl/Shader.h>




void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	//0,0�Ǵ��ڵ����½�
	glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window)
{
	//����esc���˳�
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}


int main()
{
	//��ʼ��GLFW
	glfwInit();
	//����GLFW
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

	//����һ�����ڶ���,��͸���Ϊ����ǰ��������,������������ʾ������ڵ����ƣ����⣩
	GLFWwindow* window = glfwCreateWindow(Data::SCR_WIDTH, Data::SCR_HEIGHT, "CmakeOpenGL", NULL, NULL);
	if (window == NULL)
	{
		glfwTerminate();
		return -1;
	}
	//֪ͨGLFW�����Ǵ��ڵ�����������Ϊ��ǰ�̵߳���������
	glfwMakeContextCurrent(window);
	//��Ҫ����������GLFW����ϣ��ÿ�����ڵ�����С��ʱ������������,�����ڱ���һ����ʾ��ʱ��framebuffer_size_callbackҲ�ᱻ����
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

		// glad: load all OpenGL function pointers
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	//����һ�����㻺��VBO����
	unsigned int VBO1;
	glGenBuffers(1, &VBO1);
	//���´����Ļ���󶨵�GL_ARRAY_BUFFERĿ����
	glBindBuffer(GL_ARRAY_BUFFER, VBO1);

	unsigned int VBO2;
	glGenBuffers(1, &VBO2);
	glBindBuffer(GL_ARRAY_BUFFER, VBO2);

	glBufferData(GL_ARRAY_BUFFER, sizeof(Data::vertices1), Data::vertices1, GL_STATIC_DRAW);

	std::cout << sizeof(Data::vertices1) << std::endl;

	Shader shader("startShader.vs", "startShader.fs");
	shader.use();



	while (!glfwWindowShouldClose(window))
	{
		processInput(window);

		glClearColor(0.2, 0.3, 0.3, 1.0);//���������Ļ���õ���ɫ
		glClear(GL_COLOR_BUFFER_BIT);//�����ɫ����


		//�����ύ����ɫ���壨����һ��������GLFW����ÿһ��������ɫֵ�Ĵ󻺳壩��������һ�����б��������ƣ����ҽ�����Ϊ�����ʾ����Ļ�ϡ�
		glfwSwapBuffers(window);
		//���������û�д���ʲô�¼�������������롢����ƶ��ȣ������´���״̬�������ö�Ӧ�Ļص�����������ͨ���ص������ֶ����ã���
		glfwPollEvents();
	}

	glfwTerminate();

	return 0;
}