#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include <GLFW/glfw3.h>
#include <learnopengl/Scene.h>
#include <learnopengl/Data.h>



class Actor
{
public:
	Scene* scene;


	unsigned int VBO, cubeVAO;



	void DrawActor()
	{
		glGenBuffers(1, &VBO);
	}

	Actor()
	{
		
		glGenVertexArrays(1, &cubeVAO);
		glGenBuffers(1, &VBO);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(Data::vertices), Data::vertices, GL_STATIC_DRAW);

		glBindVertexArray(cubeVAO);


		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);




	}

	virtual ~Actor()
	{
		if (scene)
		{
			delete(scene);
		}
	}


};