#include <iostream>
#include <GLFW/glfw3.h>
#include <unistd.h>

#include "lgl_label.h"
#include "lgl_button.h"
#include "lgl_const.h"
#include "lgl_elbow.h"

using lgl::label;
using lgl::color;
using lgl::callable_function;
using lgl::button;
using lgl::elbow;
using std::cout;
using std::vector;

void l4_callback(){
	cout << "l4 clicked\n";
}
void l5_callback(){
	cout << "l5 clicked\n";
}
void l6_callback(){
	cout << "l6 clicked\n";
}

// #globalization
label * l1;
label * l2;
label * l3;
callable_function * l4_func;
button * l4;
callable_function * l5_func;
button * l5;
callable_function * l6_func;
button * l6;
label * l7;
label * l8;
label * l9;
elbow * e1;
elbow * e2;
elbow * e3;
elbow * e4;

void mouse(GLFWwindow * window, int button, int state, int mods){
	int mouse_button = button == GLFW_MOUSE_BUTTON_LEFT ? lgl::left_mouse_button : lgl::right_mouse_button;
	int mouse_state = state == GLFW_PRESS ? lgl::mouse_down_state : lgl::mouse_up_state;
	
	double Mx, My;
	glfwGetCursorPos(window, &Mx, &My);
	My = 400 - My;
			
	l4->try_click(Mx, My, mouse_button, mouse_state);
	l5->try_click(Mx, My, mouse_button, mouse_state);
	l6->try_click(Mx, My, mouse_button, mouse_state);
}

int main(int argc, char * argv[]){
	lgl::colors = vector<color>({{0.0f, 0.0f, 0.0f}, {1.0f, 1.0f, 0.6f}, {1.0f, 0.6f, 0.2f}});	

	l1 = new label(1, 0, 0, 0, "l1");
	l2 = new label(1, 0, 1, false, true, "l2");
	l3 = new label(1, 0, 2, true, false, "l3");
	l4_func = new callable_function(&l4_callback);
	l4 = new button(1, 0, 3, 0, "l4", l4_func);
	l5_func = new callable_function(&l5_callback);
	l5 = new button(1, 0, 4, true, true, "l5", l5_func);
	l6_func = new callable_function(&l6_callback);
	l6 = new button(1, 0, 5, 0, "l6", l6_func);
	l7 = new label(1, 1, 0, 1, "l7");
	l8 = new label(1, 1, 2, 1, "l8");
	l9 = new label(1, 1, 4, 1, "l9");
	e1 = new elbow(1, 1, 6, 0, true, true, "");
	e2 = new elbow(1, 2, 0, 2, true, false, "");
	e3 = new elbow(1, 7, 6, 3, false, true, "");
	e4 = new elbow(1, 7, 0, 0, false, false, "");

	glfwInit();

	GLFWwindow * window = glfwCreateWindow(400, 400, "Test", NULL, NULL);

	glfwMakeContextCurrent(window);
	glfwSetMouseButtonCallback(window, mouse);
	glOrtho(0, 400, 0, 400, -1, 1);

	while(true){
		glClear(GL_COLOR_BUFFER_BIT);
		glfwWaitEvents();
		l1->draw();
		l2->draw();
		l3->draw();
		l4->draw();
		l5->draw();
		l6->draw();
		l7->draw();
		l8->draw();
		l9->draw();
		e1->draw();
		e2->draw();
		e3->draw();
		e4->draw();
		glfwSwapBuffers(window);
	}

	glfwTerminate();

	delete l1;
	delete l2;
	delete l3;
	delete l4_func;
	delete l4;
	delete l5_func;
	delete l5;
	delete l6_func;
	delete l6;
	delete l7;
	delete l8;
	delete l9;
	delete e1;
	delete e2;
	delete e3;
	delete e4;

	return 0;
}
