#include "lgl_core.h"

#include "lgl_button.h"
#include "lgl_elbow.h"
#include "lgl_label.h"

#include <algorithm>

#include <iostream>

using std::cout;

using std::min_element;
using std::max_element;

using namespace lgl;

core::core(){}

core::~core(){
	for(int i = 0; i < objects.size(); i++){
		delete objects[i];
	}
}

void core::initialize(){
	glfwInit();
	
	int x_min = (*min_element(objects.begin(), objects.end(), [](object * i, object * j)
				 {return i->max_grid_left() < j->max_grid_left();}))->max_grid_left();
	int x_max = (*max_element(objects.begin(), objects.end(), [](object * i, object * j)
				 {return i->max_grid_right() < j->max_grid_right();}))->max_grid_right() + 1;
	int y_min = (*min_element(objects.begin(), objects.end(), [](object * i, object * j)
				 {return i->max_grid_top() < j->max_grid_top();}))->max_grid_top();
	int y_max = (*max_element(objects.begin(), objects.end(), [](object * i, object * j)
				 {return i->max_grid_bottom() < j->max_grid_bottom();}))->max_grid_bottom() + 1;

	m_mouse_y_max = y_max * (grid_height + gap) - gap;
	m_window_width = (x_max - x_min) * (grid_width + gap) - gap;
	m_window_height = (y_max - y_min) * (grid_height + gap) - gap;
	
	m_window = glfwCreateWindow(m_window_width, m_window_height, "Test", NULL, NULL);

	glfwMakeContextCurrent(m_window);

	glfwSetWindowUserPointer(m_window, this);

	glfwSetKeyCallback(m_window, s_keyboard_callback);
	glfwSetMouseButtonCallback(m_window, s_mouse_callback);

	glOrtho(x_min * (grid_width + gap), x_max * (grid_width + gap) - gap,
		y_min * (grid_height + gap), y_max * (grid_height + gap) - gap, -1, 1);
}

void core::loop(){
	while(true){
		glfwWaitEvents();
		glClear(GL_COLOR_BUFFER_BIT);

		for(int i = 0; i < objects.size(); i++){
			objects[i]->draw();
		}

		glfwSwapBuffers(m_window);
	}
}

void core::mouse_callback(int button, int state, int modifiers){
	if(button == GLFW_MOUSE_BUTTON_LEFT){
		button = left_mouse_button;
	}
	else if(button == GLFW_MOUSE_BUTTON_RIGHT){
		button = right_mouse_button;
	}
	if(state == GLFW_PRESS){
		state = mouse_down_state;
	}
	else if(state == GLFW_RELEASE){
		state = mouse_up_state;
	}
	
	double click_x, reversed_click_y;
	glfwGetCursorPos(m_window, &click_x, &reversed_click_y);
	int click_y = m_mouse_y_max - (int) reversed_click_y;

	for(clickable * c : clickable_objects){
		c->try_click((int) click_x, click_y, button, state);
	}

	glfwPostEmptyEvent();
}

void core::s_mouse_callback(GLFWwindow * window, int button, int state, int modifiers){
	((core *) glfwGetWindowUserPointer(window))->mouse_callback(button, state, modifiers);
}

void core::keyboard_callback(int key, int scancode, int action, int mods){
	glfwPostEmptyEvent();
}

void core::s_keyboard_callback(GLFWwindow * window, int key, int scancode, int action, int mods){
	((core *) glfwGetWindowUserPointer(window))->keyboard_callback(key, scancode, action, mods);
}

void core::add_button(int color, int column, int row, int height, string text, callable * call_on_click){
	button * b = new button(color, column, row, height, text, call_on_click);
	objects.push_back(b);
	clickable_objects.push_back(b);
}

void core::add_button(int color, int column, int row, bool left_cap, bool right_cap,
		      string text, callable * call_on_click){
	button * b = new button(color, column, row, left_cap, right_cap, text, call_on_click);
	objects.push_back(b);
	clickable_objects.push_back(b);
}

void core::add_elbow(int color, int column, int row, int length, bool right, bool down, string text){
	elbow * e = new elbow(color, column, row, length, right, down, text);
	objects.push_back(e);
}

int core::add_indicator(int color, int column, int row, bool left_cap, bool right_cap){
	indicator * i = new indicator(color, column, row, left_cap, right_cap);
	objects.push_back(i);
	indicator_objects.push_back(i);
	cout << indicator_objects.size() - 1;
	return indicator_objects.size() - 1;
}

void core::set_indicator(int index, string text){
	indicator_objects[index]->set_text(text);
}

void core::add_label(int color, int column, int row, int height, string text){
	label * l = new label(color, column, row, height, text);
	objects.push_back(l);
}

void core::add_label(int color, int column, int row, bool left_cap, bool right_cap, string text){
	label * l = new label(color, column, row, left_cap, right_cap, text);
	objects.push_back(l);
}
