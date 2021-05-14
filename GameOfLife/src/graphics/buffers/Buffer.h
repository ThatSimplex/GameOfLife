#pragma once

#include <glad/glad.h>

namespace GoL {
	class Buffer {
	public:
		Buffer(GLfloat* data, GLsizei count, GLuint componentCount);
		
		void Bind() const;
		void Unbind() const;

		inline GLuint GetComponentCount() const { return m_ComponentCount; }
	private:
		GLuint m_BufferID;
		GLuint m_ComponentCount;
	};
}