#pragma once

#ifndef LGL_SHAPES
#define LGL_SHAPES 0

#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include <cmath>

using namespace std;

class lgl_shapes{
public:
	static void rectangle(int corner_x_left, int corner_x_right, int corner_y_bottom, int corner_y_top){
	
		glBegin(GL_QUADS);
	
		glVertex2i(corner_x_left, corner_y_bottom);
		glVertex2i(corner_x_right, corner_y_bottom);
		glVertex2i(corner_x_right, corner_y_top);
		glVertex2i(corner_x_left, corner_y_top);
	
		glEnd();
	
	}
	
	static void arc(int center_x, int center_y, int radius, int start_angle, int end_angle){
		
		glBegin(GL_POLYGON);
		glVertex2i(center_x,center_y);
		for(float i = start_angle; i < end_angle; i+=0.02){
			float angle = i/57.3;
			float x2 = center_x+cos(angle)*radius;
			float y2 = center_y+sin(angle)*radius;
			glVertex2f(x2,y2);
		}
		glEnd();
	
	}
	
};

#endif
