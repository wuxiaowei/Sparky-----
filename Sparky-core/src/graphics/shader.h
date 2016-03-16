#pragma once
#include <vector>
#include <iostream>
#include <GL/glew.h>
#include "../maths/maths.h"

namespace sparky {
	namespace graphics {
		class Shader {
		private:
			const char* m_VertPath;
			const char *m_FragPath;
		public:
			GLuint m_ShaderID;

			void setUniform1f(const char * name, float value);
			void setUniform1i(const char * name, int value);
			void setUniform2f(const GLchar* name, const maths::vec2& vector);
			void setUniform3f(const GLchar* name, const maths::vec3& vector);
			void setUniform4f(const GLchar* name, const maths::vec4& vector);
			void setUniformMat4(const char * name, const maths::mat4& matrix);

			Shader(const char* vertPath, const char * fragPath);
			~Shader();
			void enable() const;
			void disable() const;
		private:
			GLint getUniformLocation(const GLchar * name);

			GLuint load();
		};
	}
}