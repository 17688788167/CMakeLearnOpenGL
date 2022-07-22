#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include <iostream>
#include <learnopengl/Shader.h>
#include <learnopengl/Data.h>
#include <vector>
#include <learnopengl/Actor.h>


const unsigned int SCR_WIDTH = Data::SCR_WIDTH;
const unsigned int SCR_HEIGHT = Data::SCR_HEIGHT;


void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

int main(int argc, char** argv)
{
	//��ʼ��GLFW
	glfwInit();
	//����GLFW
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);


	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	// glad: load all OpenGL function pointers
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}



	//Shader shader("1.Start/startShader.vs", "1.Start/startShader.fs");

	//shader.use();
	// set up vertex data (and buffer(s)) and configure vertex attributes
	float vertices[] = {
		-0.5f, -0.5f, 0.0f,
		-0.5f, 0.0f, 0.0f,
		0.0f,  -0.5f, 0.0f,
		0.0f, 0.5f, 0.0f

	};

	unsigned int indices1[] = {
		0, 1, 3, // 第一个三角形
		1, 2, 3  // 第二个三角形
	};
	float secondTriangle[] = {
	0.0f, -0.5f, 0.0f,  // left
	0.9f, -0.5f, 0.0f,  // right
	0.45f, 0.5f, 0.0f,  // top 
	0.1f, 0.5f, 0.0f,  // top 
	};

	unsigned int indices2[] = {
	0, 1, 2, // 第一个三角形
	1, 2, 3  // 第二个三角形
	};

	vector<Actor*>ActorVector;
	Actor* actor1 = new Actor(1, 0, 0, "1.Start/startShader.vs", "1.Start/startShader.fs");
	ActorVector.push_back(actor1);

	Actor* actor2 = new Actor(1, 0.2f, 0.3f, "1.Start/Shader1.vs", "1.Start/Shader1.fs");
	ActorVector.push_back(actor2);


	//VAOVector.push_back(1);
	int ActorNum = ActorVector.size();
	//unsigned int* VAOS = new unsigned int[ActorNum];
	//unsigned int* VBOS = new unsigned int[ActorNum];
	//for (int i = 0; i < ActorNum; ++i)
	//{
	//	VAOS[i] = ActorVector[i]->AvtorVAO;
	//	VBOS[i] = ActorVector[i]->ActorVBO;
	//	glGenVertexArrays(1, &VAOS[i]);
	//	glGenBuffers(1, &VBOS[i]);

	//	glBindVertexArray(VAOS[i]);
	//	glBindBuffer(GL_ARRAY_BUFFER, VBOS[i]);
	//	cout << sizeof(ActorVector[i]->ActorVertices) << endl;
	//	cout << sizeof(Data::vertices) << endl;
	//	glBufferData(GL_ARRAY_BUFFER, sizeof(Data::vertices), ActorVector[i]->ActorVertices, GL_STATIC_DRAW);
	//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	//	glEnableVertexAttribArray(0);
	//}
	//glGenVertexArrays(ActorNum, VAOS);





	//unsigned int VAOs[2];
	//glGenVertexArrays(2, VAOs);
	//unsigned int VBOs[2];
	//glGenBuffers(2, VBOs);
	//unsigned int EBOs[2];
	//glGenBuffers(2, EBOs);


	//绑定第一个顶点数组对象
	//glBindVertexArray(VAOs[0]);
	//glBindBuffer(GL_ARRAY_BUFFER, VBOs[0]);
	//glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBOs[0]);
	//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices1), indices1, GL_STATIC_DRAW);
	//glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	//glEnableVertexAttribArray(0);




	////绑定第二个顶点数组对象
	//glBindVertexArray(VAOs[1]);
	//glBindBuffer(GL_ARRAY_BUFFER, VBOs[1]);
	//glBufferData(GL_ARRAY_BUFFER, sizeof(secondTriangle), secondTriangle, GL_STATIC_DRAW);

	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBOs[1]);
	//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices2), indices2, GL_STATIC_DRAW);
	//glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	//glEnableVertexAttribArray(0);


	std::cout << "ssssssssssss" << std::endl;

	while (!glfwWindowShouldClose(window))
	{
		processInput(window);

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);




		//int size = sizeof(VAOs) / sizeof(VAOs[0]);
		for (int i = 0; i < ActorNum; ++i)
		{
			//glBindVertexArray(ActorVector[i]->ActorVAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
			//glDrawArrays(GL_TRIANGLES, 0, 3);
			//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
			ActorVector[i]->DrawActor();
			//glDrawArrays(GL_TRIANGLES, 0, 36);
		}


		//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		// glBindVertexArray(0); // no need to unbind it every time 

		glfwPollEvents();

		glfwSwapBuffers(window);
	}
	for (int i = 0; i < ActorNum; ++i)
	{
		glDeleteVertexArrays(1, &ActorVector[i]->ActorVAO);
		glDeleteBuffers(1, &ActorVector[i]->ActorVBO);
	}

	//glDeleteBuffers(2, EBOs);

	glfwTerminate();


	delete actor1;
	delete actor2;
	ActorVector.empty();
	return 0;
}