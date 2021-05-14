#include "Window.h"

namespace GoL {
	void WindowResizeCallback(GLFWwindow* window, int width, int height);

	Window::Window(int width, int height, const char* title) {
		m_Width = width;
		m_Height = height;
		m_Title = title;

		if (!Init()) {
			glfwTerminate();
		}
	}

	Window::~Window() {
		glfwTerminate();
	}

	void Window::Clear() {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void Window::Update() {
		glfwSwapBuffers(m_Window);
		glfwPollEvents();
	}

	bool Window::Closed() {
		return glfwWindowShouldClose(m_Window) == 1;
	}

	bool Window::Init() {
		if (!glfwInit()) {
			std::cout << "Failed to initialize GLFW!" << std::endl;
			return false;
		}

		m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);

		if (!m_Window) {
			std::cout << "Failed to create GLFW window!" << std::endl;
			return false;
		}

		glfwMakeContextCurrent(m_Window);
		glfwSetWindowSizeCallback(m_Window, WindowResizeCallback);
		return true;
	}

	void WindowResizeCallback(GLFWwindow* window, int width, int height) {
		glViewport(0, 0, width, height);
	}
}