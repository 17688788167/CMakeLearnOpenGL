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
	                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
	unsigned int ActorVBO, ActorVAO;
	float *ActorVertices;
	


	void DrawActor()
	{
		glBindVertexArray(ActorVAO);
		glDrawArrays(GL_TRIANGLES, 0, 36);
	}


	
	Actor(float Scale,float xOffset,float yOffset)
	{
		ActorVerticeData(Scale, xOffset, yOffset);

		BindVAOVBO();
	}

	virtual ~Actor()
	{
		if (scene)
		{
			delete(scene);
		}
		ActorVertices = nullptr;
	}
private:

	void BindVAOVBO()
	{
		glGenVertexArrays(1, &ActorVAO);
		glGenBuffers(1, &ActorVBO);

		glBindVertexArray(ActorVAO);
		glBindBuffer(GL_ARRAY_BUFFER, ActorVBO);
		cout << sizeof(ActorVertices) << endl;
		cout << sizeof(Data::vertices) << endl;
		glBufferData(GL_ARRAY_BUFFER, sizeof(Data::vertices), ActorVertices, GL_STATIC_DRAW);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

	}

	void ActorVerticeData(float Scale, float xOffset, float yOffset)
	{
		int num = sizeof(Data::vertices) / sizeof(float);

		ActorVertices = new float[num];
		for (int i = 0; i < num; ++i)
		{
			ActorVertices[i] = Data::vertices[i] * Scale;
			if (i % 3 == 0)
			{
				ActorVertices[i] += xOffset;
				//cout << ActorVertices[i]<<", ";
			}
			else if (i % 3 == 1)
			{
				ActorVertices[i] += yOffset;
				//cout << ActorVertices[i] << ", ";
			}
			else if (i % 3 == 2)
			{
				//cout << ActorVertices[i] << endl;
			}
		}
	}
};