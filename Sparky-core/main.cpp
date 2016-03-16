#include "src/graphics/window.h"
#include "src/maths/maths.h"
#include "src/graphics/shader.h"

int main(int argc, const char * argv[]) {
	// insert code here...
	using namespace sparky;
	using namespace graphics;
	using namespace maths;
	Window window("Sparky", 960, 540);
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	std::cout << glGetString(GL_VERSION) << std::endl;


	GLuint vbo;

	GLfloat vertices[] = {
		+0, 0, 0,
		+8, 0, 0,
		+0, 3, 0,
		+0, 3, 0,
		+8, 3, 0,
		+8, 0, 0
	};
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);

	mat4 ortho = mat4::orthographic(0.0f,16.0f, 0.0f, 9.0f, -1.0f, 1.0f);

	Shader shader("src/shaders/basic.vert", "src/shaders/basic.frag");
	shader.enable();
	//glUniformMatrix4fv(glGetUniformLocation(shader.m_ShaderID, "pr_matrix"), 1, GL_FALSE, ortho.elements);
	shader.setUniformMat4("pr_matrix", ortho);
	shader.setUniformMat4("ml_matrix", mat4::translation(vec3(2, 2, 0)));
	shader.setUniform4f("colour", vec4(0.0, 0.0, 1, 1.0));
	shader.setUniform2f("light_pos", vec2(8.0, 4.0));
	while (!window.closed()) {
		window.clear();

		glDrawArrays(GL_TRIANGLES, 0, 6);

		window.update();
	}

	//    std::cin.get();
	return 0;
}