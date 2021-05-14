#pragma once

#include <glad/glad.h>

namespace GoL {
	class IndexBuffer {
	public:
		IndexBuffer(GLushort* data, GLsizei count);

		void Bind() const;
		void Unbind() const;

		inline GLuint GetCount() const { return m_Count; }
	private:
		GLuint m_BufferID;
		GLuint m_Count;
	};
}