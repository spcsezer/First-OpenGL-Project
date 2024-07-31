#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

using namespace std;

const GLint WIDTH = 800, HEIGHT = 600;

int main() {

	if (!glfwInit()) {

		cout << "GLFW intialization is failed.";
		glfwTerminate();
		return 1;
	}

	//window properties
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_COMPAT_PROFILE, GLFW_TRUE);

	GLFWwindow* mainWindow = glfwCreateWindow(WIDTH, HEIGHT, "FirstOpenGLProject", NULL, NULL);
	if (!mainWindow) {

		cout << "Window creation is failed";
		glfwTerminate();
		return 1;

	}

	//Buffer size

	int bufferWidth, bufferHeight;
	glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight);


	//Glew context (You can switch screen for games)
	glfwMakeContextCurrent(mainWindow);

	//Allow modern extension
	glewExperimental = GLFW_TRUE;

	if (glewInit() != GLEW_OK) {

		cout << "Glew init failed";
		glfwDestroyWindow(mainWindow);
		glfwTerminate();
		return 1;

	}

	//set viewport
	glViewport(0, 0, bufferWidth, bufferHeight);

	//loop
	while (!glfwWindowShouldClose(mainWindow)) {

		//user events
		glfwPollEvents();

		//clear window
		glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(mainWindow);

	}

	return 0;
}