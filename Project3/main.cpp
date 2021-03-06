#include<stdio.h>
#include<stdlib.h>
#include<GLFW/glfw3.h>

#pragma comment(lib, "OpenGL32") 


static void error_callback(int error, const char* description)
{
	fputs(description, stderr);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, GL_TRUE);
	}
}

int main(void)
{
	GLFWwindow* window;
	glfwSetErrorCallback(error_callback);
	if (!glfwInit())
		exit(EXIT_FAILURE);
	window = glfwCreateWindow(800, 800, "SImple example", NULL, NULL);
	if(!window)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	glfwMakeContextCurrent(window);
	glfwSetKeyCallback(window, key_callback);




	

	while (!glfwWindowShouldClose(window))
	{
		float ratio;
		int width, height;
		glfwGetFramebufferSize(window, &width, &height);
		ratio = width / (float)height;

		glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		

		glPointSize(10);
		glBegin(GL_TRIANGLES);

		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f(0.2f, 0.0f);
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex2f(0.2f, 0.4f);
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex2f(-0.2f, 0.0f);
		glEnd();

		glPointSize(10);
		glBegin(GL_TRIANGLES);

		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f(-0.2f, 0.4f);
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex2f(-0.2f, 0.0f);
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex2f(0.2f, 0.4f);
		glEnd();


		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	

	glfwDestroyWindow(window);
	glfwTerminate();
	exit(EXIT_SUCCESS);
}
