#pragma once
#define RPath "../../../src/"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <direct.h>
using namespace std;

class Data
{
public:
	constexpr static unsigned int SCR_WIDTH = 800;
	constexpr static unsigned int SCR_HEIGHT = 600;
	constexpr static char *relativePath= "../../../";
	constexpr static float vertices1[] = {
	-0.5f, -0.5f, 0.0f,
	 0.5f, -0.5f, 0.0f,
	 0.0f,  0.5f, 0.0f
	};

	constexpr static float vertices2[] = {
	0.5f,  0.5f,  0.0f,
	-0.5f, 0.8f, 0.0f,
	 0.0f, 0.5f, 0.0f
	};


	constexpr static  float vertices[] = {
		-0.5f, -0.5f, -0.5f,
		 0.5f, -0.5f, -0.5f,
		 0.5f,  0.5f, -0.5f,
		 0.5f,  0.5f, -0.5f,
		-0.5f,  0.5f, -0.5f,
		-0.5f, -0.5f, -0.5f,

		-0.5f, -0.5f,  0.5f,
		 0.5f, -0.5f,  0.5f,
		 0.5f,  0.5f,  0.5f,
		 0.5f,  0.5f,  0.5f,
		-0.5f,  0.5f,  0.5f,
		-0.5f, -0.5f,  0.5f,

		-0.5f,  0.5f,  0.5f,
		-0.5f,  0.5f, -0.5f,
		-0.5f, -0.5f, -0.5f,
		-0.5f, -0.5f, -0.5f,
		-0.5f, -0.5f,  0.5f,
		-0.5f,  0.5f,  0.5f,

		 0.5f,  0.5f,  0.5f,
		 0.5f,  0.5f, -0.5f,
		 0.5f, -0.5f, -0.5f,
		 0.5f, -0.5f, -0.5f,
		 0.5f, -0.5f,  0.5f,
		 0.5f,  0.5f,  0.5f,

		-0.5f, -0.5f, -0.5f,
		 0.5f, -0.5f, -0.5f,
		 0.5f, -0.5f,  0.5f,
		 0.5f, -0.5f,  0.5f,
		-0.5f, -0.5f,  0.5f,
		-0.5f, -0.5f, -0.5f,

		-0.5f,  0.5f, -0.5f,
		 0.5f,  0.5f, -0.5f,
		 0.5f,  0.5f,  0.5f,
		 0.5f,  0.5f,  0.5f,
		-0.5f,  0.5f,  0.5f,
		-0.5f,  0.5f, -0.5f,
	};

	static std::string GetAbsolutePath(const char* relaPath)
	{
		std::string pathTemp = relaPath;
		return RPath + pathTemp;
	}

	static void OpenFile(const char* relaPath)
	{
		char* buffer;
		buffer = getcwd(NULL, 0);
		if (buffer == NULL)
		{
			cout << "读取路径失败" << endl;
		}
		else
		{
			cout << "读取路径成功" << endl;
			cout << buffer << endl;
		}


		std::ifstream ifs;
		ifs.open(GetAbsolutePath(relaPath), ios::in);
		if (!ifs.is_open())
		{
			cout << "文件打开失败！\a" << GetAbsolutePath(relaPath) <<endl;
		}
		else
		{
			cout << "文件打开成功！\a" << endl;
		}
		char* str = "";
		char c;
		while ((c = ifs.get()) != EOF)
		{
			cout << c;
		}
		cout << endl;
		
	}
};