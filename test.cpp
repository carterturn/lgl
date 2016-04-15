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

const float scale = 0.5f;

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

void futureInit(){
	
	future.elbow(2, 133, 157, 4, 0, 0, 6, "FUTURE GUI");
	future.elbow(2, 2, 157, 3, 0, 1, 6, "TEST");
	future.elbow(278, 247, 65, 1, 1, 0, 6, "FUTURE GUI");
	
	future.elbowbutton(278, 2, 65, 1, 1, 1, 7, "RESET ALL");
	
	// Make sure to track the order of initialization
	future.multibutton(370, 57, 1, 3);
	future.multibutton(370, 95, 1, 3);
	future.multibutton(370, 133, 1, 3);
	future.multibutton(370, 171, 1, 3);
	future.multibutton(370, 209, 1, 3);
	
	future.button(278, 57, 1, 4, "INCREASE 0");
	future.button(278, 95, 1, 4, "INCREASE 1");
	future.button(278, 133, 1, 4, "INCREASE 2");
	future.button(278, 171, 1, 4, "INCREASE 3");
	future.button(278, 209, 1, 4, "INCREASE 4");
	
	future.button(186, 57, 1, 5, "DECREASE 0");
	future.button(186, 95, 1, 5, "DECREASE 1");
	future.button(186, 133, 1, 5, "DECREASE 2");
	future.button(186, 171, 1, 5, "DECREASE 3");
	future.button(186, 209, 1, 5, "DECREASE 4");
	
	future.cmdbutton(94, 57, 8, "RESET 0");
	future.endbutton(94, 95, 1, 8, "RESET 1");
	future.endbutton(94, 133, 1, 8, "RESET 2");
	future.endbutton(94, 171, 1, 8, "RESET 3");
	future.endbutton(94, 209, 1, 8, "RESET 4");
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
			
			if(button == "INCREASE 0") iter[0]++;
			if(button == "INCREASE 1") iter[1]++;
			if(button == "INCREASE 2") iter[2]++;
			if(button == "INCREASE 3") iter[3]++;
			if(button == "INCREASE 4") iter[4]++;
			if(button == "DECREASE 0") iter[0]--;
			if(button == "DECREASE 1") iter[1]--;
			if(button == "DECREASE 2") iter[2]--;
			if(button == "DECREASE 3") iter[3]--;
			if(button == "DECREASE 4") iter[4]--;
			if(button == "RESET 0") iter[0] = 0;
			if(button == "RESET 1") iter[1] = 0;
			if(button == "RESET 2") iter[2] = 0;
			if(button == "RESET 3") iter[3] = 0;
			if(button == "RESET 4") iter[4] = 0;
			if(button == "RESET ALL"){
				for(int i = 0; i < 5; i++) iter[i] = 0;
			}
		}
	}
}

int main(int argc, char** argv) {
	for(int i = 0; i < 5; i++) iter[i] = 0;
	glfwInit();
	GLFWwindow * window = glfwCreateWindow(WIN_X, WIN_Y, "FutureGL Test", NULL, NULL);
	if(!window){
		cout << "Error\n";
		return -1;
	}

	glfwMakeContextCurrent(window);
	glfwSetMouseButtonCallback(window, mouse);
 	glOrtho(0, WIN_X/scale, 0, WIN_Y/scale, -1.0, 1.0);
	cout << "OpenGL init complete\n";
	futureInit();
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
