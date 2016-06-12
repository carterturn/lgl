/*
  Copyright 2015 Carter Turnbaugh

  This file is part of FutureGL.

  FutureGL is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  FutureGL is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with FutureGL.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include <sstream>
#include <iostream>

#include <unistd.h>

#include <futuregl.h>

using namespace std;

#define WIN_X 1600
#define WIN_Y 756

const float scale = 2.0f;

futuregl future(3);

short iter[5];

string its(int in){
	stringstream a;
	a << in;
	return a.str();
}

void draw(){
	
	future.setmultibutton(0, iter[0]);
	future.setmultibutton(1, iter[1]);
	future.setmultibutton(2, iter[2]);
	future.setmultibutton(3, iter[3]);
	future.setmultibutton(4, iter[4]);
	
	future.draw();
}

void mouse(GLFWwindow * window, int button, int state, int mods) {
	if(state == GLFW_PRESS){
		if(button == GLFW_MOUSE_BUTTON_LEFT){
			double Mx, My;
			glfwGetCursorPos(window, &Mx, &My);
			
			My = WIN_Y - My;
			Mx = Mx/scale;
			My = My/scale;
			string button = future.getclicked(Mx, My);
			
			if(button != "") cout << button << " clicked\n";
			
			if(button == "INCREASE_0") iter[0]++;
			if(button == "INCREASE_1") iter[1]++;
			if(button == "INCREASE_2") iter[2]++;
			if(button == "INCREASE_3") iter[3]++;
			if(button == "INCREASE_4") iter[4]++;
			if(button == "DECREASE_0") iter[0]--;
			if(button == "DECREASE_1") iter[1]--;
			if(button == "DECREASE_2") iter[2]--;
			if(button == "DECREASE_3") iter[3]--;
			if(button == "DECREASE_4") iter[4]--;
			if(button == "RESET_0") iter[0] = 0;
			if(button == "RESET_1") iter[1] = 0;
			if(button == "RESET_2") iter[2] = 0;
			if(button == "RESET_3") iter[3] = 0;
			if(button == "RESET_4") iter[4] = 0;
			if(button == "RESET_ALL"){
				for(int i = 0; i < 5; i++) iter[i] = 0;
			}
		}
	}
}

int main(int argc, char* argv[]) {
	for(int i = 0; i < 5; i++) iter[i] = 2;
	glfwInit();
	GLFWwindow * window = glfwCreateWindow(WIN_X, WIN_Y, "FutureGL Test", NULL, NULL);
	if(!window){
		cout << "Error\n";
		return -1;
	}
	cout << "Window create complete\n";
	glfwMakeContextCurrent(window);
	glfwSetMouseButtonCallback(window, mouse);
 	glOrtho(0, WIN_X/scale, 0, WIN_Y/scale, -1.0, 1.0);
	cout << "OpenGL init complete\n";
	future.load_config("test_config.conf");
	cout << "future init complete\n";

	while(true){
		glClear(GL_COLOR_BUFFER_BIT);
		draw();
		glfwSwapBuffers(window);
		glfwPollEvents();
		usleep(1000);
	}

	glfwTerminate();
	return 0;
}
