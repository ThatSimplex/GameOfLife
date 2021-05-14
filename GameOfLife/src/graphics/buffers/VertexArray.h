#pragma once

#include "Buffer.h"
#include <glad/glad.h>
#include <vector>

namespace GoL {
	class VertexArray {
	public:
		VertexArray();
		~VertexArray();

		void AddBuffer(Buffer* buffer, GLuint index);
		void Bind() const;
		void Unbind() const;
	private:
		GLuint m_ArrayID;
		std::vector<Buffer*> m_Buffers;
	};
}