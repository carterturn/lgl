#include <iostream>

#include "lgl_core.h"
#include "lgl_callable.h"

using namespace std;

void l4_callback(){
	cout << "l4 clicked\n";
}
void l5_callback(){
	cout << "l5 clicked\n";
}
void l6_callback(){
	cout << "l6 clicked\n";
}
void l9_callback(){
	cout << "l9 clicked\n";
}

int main(int argc, char * argv[]){

	lgl::colors = vector<lgl::color>({{0.0f, 0.0f, 0.0f}, {1.0f, 1.0f, 0.6f}, {1.0f, 0.6f, 0.2f}});
	
	lgl::core gui;

	gui.add_label(1, 0, 0, 0, "l1");
	gui.add_label(1, 0, 1, true, false, "l2");
	gui.add_label(1, 0, 2, true, false, "l3");
	lgl::callable_function l4_func(&l4_callback);
	gui.add_button(1, 0, 3, 0, "l4", &l4_func);
	lgl::callable_function l5_func(&l5_callback);
	gui.add_button(1, 0, 4, true, false, "l5", &l5_func);
	lgl::callable_function l6_func(&l6_callback);
	gui.add_button(1, 0, 5, 0, "l6", &l6_func);
	gui.add_label(1, 1, 0, 1, "l7");
	gui.add_label(1, 1, 2, 1, "l8");
	lgl::callable_function l9_func(&l9_callback);
	gui.add_button(1, 1, 4, 1, "l9", &l9_func);
	gui.add_elbow(1, 1, 6, 0, true, true, "");
	gui.add_elbow(1, 2, 0, 2, true, false, "");
	gui.add_elbow(1, 7, 6, 3, false, true, "");
	gui.add_elbow(1, 7, 0, 0, false, false, "");
	int i_one = gui.add_indicator(1, 2, 1, false, false);
	int i_two = gui.add_indicator(1, 2, 2, false, true);
	int i_three = gui.add_indicator(1, 2, 3, false, true);
	int i_four = gui.add_indicator(1, 2, 4, false, true);

	gui.set_indicator(i_one, "1221");
	gui.set_indicator(i_two, "3323");
	gui.set_indicator(i_three, "1001");
	gui.set_indicator(i_four, "9968");

	gui.initialize();

	gui.loop();
	
	return 0;
}
