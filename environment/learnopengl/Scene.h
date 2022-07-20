#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include <GLFW/glfw3.h>

class Scene 
{
	const float YAW = -90.0f;
	const float PITCH = 0.0f;
	const float SPEED = 2.5f;
	const float SENSITIVITY = 0.1f;
	const float FOV = 45.0f;

public:
	glm::quat MyRotation;
	glm::vec3 MyPosition;

	float ShowPitch = PITCH;
	float ShowYaw = YAW;
	float ShowRoll = 0.0f;
	glm::quat GetQuatByEulerAngles()
	{
		MyRotation = glm::quat(glm::vec3(glm::radians(ShowPitch), glm::radians(ShowYaw), glm::radians(ShowRoll)));
		//glm::quat();
	}

	Scene(const glm::quat q)
	{
		glm::vec3 eulerAngle = glm::eulerAngles(q);
		ShowPitch = eulerAngle.x;
		ShowYaw = eulerAngle.y;
		ShowRoll = eulerAngle.z;
	}


};