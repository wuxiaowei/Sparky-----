#include "src/graphics/window.h"
#include "src/maths/maths.h"
#include "src/graphics/shader.h"

int main(int argc, const char * argv[]) {
	// insert code here...
	using namespace sparky;
	using namespace graphics;
	using namespace maths;
	Window window("Sparky", 800, 600);
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);
	std::cout << glGetString(GL_VERSION) << std::endl;


	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);


	Shader shader("src/shaders/basic.vert", "src/shaders/basic.frag");


	while (!window.closed()) {
		window.clear();

		glDrawArrays(GL_ARRAY_BUFFER, 0, 6);

		window.update();
	}

	//    std::cin.get();
	return 0;
}