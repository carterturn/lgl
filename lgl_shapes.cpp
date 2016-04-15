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
#include <cmath>

using namespace std;

namespace lgl_shapes{
	void rectangle(int corner_x_left, int corner_x_right, int corner_y_bottom, int corner_y_top){
	
		glBegin(GL_QUADS);
	
		glVertex2i(corner_x_left, corner_y_bottom);
		glVertex2i(corner_x_right, corner_y_bottom);
		glVertex2i(corner_x_right, corner_y_top);
		glVertex2i(corner_x_left, corner_y_top);
	
		glEnd();
	
	}
	
	void arc(int center_x, int center_y, int radius, int start_angle, int end_angle){
		
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
	
}
