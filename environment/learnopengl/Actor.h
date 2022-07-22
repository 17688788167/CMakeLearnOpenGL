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
	
	Shader* shader;

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

	Actor(float Scale, float xOffset, float yOffset, const char* vsPath, const char* fsPath)
	{
		ActorVerticeData(Scale, xOffset, yOffset);

		BindVAOVBO();
		CreateShader(vsPath, fsPath);
		if (shader)
		{
			shader->use();
		}
	}


	virtual ~Actor()
	{
		if (scene)
		{
			delete scene;
			scene = nullptr;
		}
		if (shader)
		{
			delete shader;
			shader = nullptr;
		}
		ActorVertices = nullptr;
	}
protected:
	virtual void CreateShader(const char * vsPath,const char * fsPath)
	{
		shader = new Shader(vsPath, fsPath);
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
		glBufferData(GL_ARRAY_BUFFER, sizeof(Data::verticesAndTexCoords), ActorVertices, GL_STATIC_DRAW);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		//glBufferData(GL_ARRAY_BUFFER, sizeof(Data::verticesAndTexCoords), Data::verticesAndTexCoords, GL_STATIC_DRAW);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)3);
		glEnableVertexAttribArray(1);

	}

	void ActorVerticeData(float Scale, float xOffset, float yOffset)
	{
		int num = sizeof(Data::verticesAndTexCoords) / sizeof(float);

		ActorVertices = new float[num];
		for (int i = 0; i < num; ++i)
		{
			if (i%5<3)
			{
				ActorVertices[i] = Data::verticesAndTexCoords[i] * Scale;
			}
			
			if (i % 5 == 0)
			{
				ActorVertices[i] += xOffset;
				//cout << ActorVertices[i]<<", ";
			}
			else if (i % 5 == 1)
			{
				ActorVertices[i] += yOffset;
				//cout << ActorVertices[i] << ", ";
			}
			else if (i % 5 == 2)
			{
				//cout << ActorVertices[i] << endl;
			}
		}
	}
};