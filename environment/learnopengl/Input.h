#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <Data.h>

class Input
{

public:
	static Camera* camera;
	static Camera* GetCamera() const
	{
		if (!camera)
		{
			camera = new Camera(0, 0, 3);
		}
		return camera;
	}

	~Input()
	{
		if (camera)
		{
			delete(camera);
			camera = nullptr;
		}
	}


	static	void framebuffer_size_callback(GLFWwindow* window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}
	static void mouse_callback(GLFWwindow* window, double xposIn, double yposIn)
	{
		float xpos = static_cast<float>(xposIn);
		float ypos = static_cast<float>(yposIn);

		if (firstMouse)
		{
			lastX = xpos;
			lastY = ypos;
			firstMouse = false;
		}

		float xoffset = xpos - lastX;
		float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top

		lastX = xpos;
		lastY = ypos;

		GetCamera().ProcessMouseMovement(xoffset, yoffset);
	}
	static	void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
	{

	}
	static void processInput(GLFWwindow* window)
	{
		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
			glfwSetWindowShouldClose(window, true);

		if (!GetCamera())
		{
			return;
		}
		if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
			GetCamera().ProcessKeyboard(FORWARD, deltaTime);
		if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
			GetCamera().ProcessKeyboard(BACKWARD, deltaTime);
		if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
			GetCamera().ProcessKeyboard(LEFT, deltaTime);
		if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
			GetCamera().ProcessKeyboard(RIGHT, deltaTime);
	}
};