#include <iostream>
#include <GLFW/glfw3.h>
#include <unistd.h>

#include "lgl_label.h"

using lgl::label;
using lgl::color;
using std::cout;
using std::vector;

int main(int argc, char * argv[]){
	lgl::colors = vector<lgl::color>({{0.0f, 0.0f, 0.0f}, {1.0f, 1.0f, 0.6f}});
	lgl::scale_factor = 2.0f;
	
	label l1(0, 0, 0, "l1");
	label l2(0, 1, 0, "l2");
	label l3(0, 2, 0, "l3");
	label l4(0, 3, 0, "l4");
	label l5(0, 4, 0, "l5");
	label l6(0, 5, 0, "l6");
	label l7(1, 0, 1, "l7");
	label l8(1, 2, 1, "l8");
	label l9(1, 4, 1, "l9");
	label l10(2, 0, 2, "l10");
	label l11(2, 3, 2, "l11");
	label l12(3, 0, 5, "l12");

	glfwInit();

	GLFWwindow * window = glfwCreateWindow(400, 400, "Test", NULL, NULL);

	glfwMakeContextCurrent(window);
	glOrtho(0, 400, 0, 400, -1, 1);

	while(true){
		glClear(GL_COLOR_BUFFER_BIT);
		l1.draw(1);
		l2.draw(1);
		l3.draw(1);
		l4.draw(1);
		l5.draw(1);
		l6.draw(1);
		l7.draw(1);
		l8.draw(1);
		l9.draw(1);
		l10.draw(1);
		l11.draw(1);
		l12.draw(1);
		glfwSwapBuffers(window);
		usleep(10000);
	}

	glfwTerminate();

	return 0;
}
