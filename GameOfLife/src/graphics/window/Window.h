#pragma once

#include <iostream>
#include <GLFW/glfw3.h>

namespace GoL {
	class Window {
	public:
		Window(int width, int height, const char* title);
		~Window();
		void Clear();
		void Update();
		bool Closed();
	private:
		int m_Width;
		int m_Height;
		const char* m_Title;
		GLFWwindow* m_Window;

		bool Init();
	};
}
