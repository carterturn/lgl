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

#include "lgl_elbow.h"

#include <GL/gl.h>
#include <GL/glut.h>

#include "lgl_utils.h"
#include "lgl_shapes.h"
#include "lgl_const.h"

using namespace std;

int lgl_elbow::draw(){
	lgl_utils::colors(era, color);
	
	if(elbow.x_orient == 0){
		if(elbow.y_orient == 0) draw_x0_y0();
		else draw_x0_y1();
	}
	else{
		if(elbow.y_orient == 0) draw_x1_y0();
		else draw_x1_y1();
	}
}

int lgl_elbow::draw_x0_y0(){
	// Button rectangle
	lgl_shapes::rectangle(elbow.x, elbow.x+lgl_const::button_width, elbow.y,
			      elbow.y+(elbow.size-1)*lgl_const::gap+elbow.size*lgl_const::button_height + 29);
	// Button arc
	lgl_shapes::arc(elbow.x+45,
			elbow.y+(elbow.size-1)*lgl_const::gap+elbow.size*lgl_const::button_height + 29, 45, 90, 180);
	// Filler box
	lgl_shapes::rectangle(elbow.x+45, elbow.x+lgl_const::button_width+27,
			      elbow.y+(elbow.size-1)*lgl_const::gap+elbow.size*lgl_const::button_height + 29,
			      elbow.y+(elbow.size-1)*lgl_const::gap+elbow.size*lgl_const::button_height + 74);
	// Bar
	lgl_shapes::rectangle(elbow.x+lgl_const::button_width+27, elbow.x+lgl_const::button_width+elbow.length+27,
			      elbow.y+(elbow.size-1)*lgl_const::gap+elbow.size*lgl_const::button_height + 29 + 27,
			      elbow.y+(elbow.size-1)*lgl_const::gap+elbow.size*lgl_const::button_height + 74);
	
	glColor3f(0.0, 0.0, 0.0);

	// Erase inner arc portion
	lgl_shapes::arc(elbow.x+lgl_const::button_width+27,
			elbow.y+(elbow.size-1)*lgl_const::gap+elbow.size*lgl_const::button_height + 29, 27, 90, 180);
	lgl_utils::draw_text(elbow.x+5, elbow.y+5, 3, text);
}

int lgl_elbow::draw_x1_y0(){
	// Button rectangle
	lgl_shapes::rectangle(elbow.x+elbow.length+27, elbow.x+elbow.length+27+lgl_const::button_width, elbow.y,
			      elbow.y+(elbow.size-1)*lgl_const::gap+elbow.size*lgl_const::button_height + 29);
	// Button arc
	lgl_shapes::arc(elbow.x+elbow.length+27+(lgl_const::button_width-45),
			elbow.y+(elbow.size-1)*lgl_const::gap+elbow.size*lgl_const::button_height + 29, 45, 0, 90);
	// Filler box
	lgl_shapes::rectangle(elbow.x+elbow.length, elbow.x+elbow.length+27+(lgl_const::button_width-45),
			      elbow.y+(elbow.size-1)*lgl_const::gap+elbow.size*lgl_const::button_height + 29,
			      elbow.y+(elbow.size-1)*lgl_const::gap+elbow.size*lgl_const::button_height + 74);
	// Bar
	lgl_shapes::rectangle(elbow.x, elbow.x+elbow.length,
			      elbow.y+(elbow.size-1)*lgl_const::gap+elbow.size*lgl_const::button_height + 29 + 27,
			      elbow.y+(elbow.size-1)*lgl_const::gap+elbow.size*lgl_const::button_height + 74);
	
	glColor3f(0.0, 0.0, 0.0);

	// Erase inner arc portion
	lgl_shapes::arc(elbow.x+elbow.length,
			elbow.y+(elbow.size-1)*lgl_const::gap+elbow.size*lgl_const::button_height + 29, 27, 0, 90);
	lgl_utils::draw_text(elbow.x+elbow.length+27+5, elbow.y+5, 3, text);
}

int lgl_elbow::draw_x0_y1(){
	// Button rectangle
	lgl_shapes::rectangle(elbow.x, elbow.x+lgl_const::button_width, elbow.y+45,
			      elbow.y+elbow.size*lgl_const::button_height+elbow.size*lgl_const::gap+45+29);
	// Button arc
	lgl_shapes::arc(elbow.x+45, elbow.y+45, 45, 180, 270);
	// Filler box
	lgl_shapes::rectangle(elbow.x+45, elbow.x+lgl_const::button_width+27, elbow.y, elbow.y+45);
	// Bar
	lgl_shapes::rectangle(elbow.x+lgl_const::button_width+27, elbow.x+lgl_const::button_width+elbow.length+27,
			      elbow.y, elbow.y+18);
	
	glColor3f(0.0, 0.0, 0.0);

	// Erase inner arc portion
	lgl_shapes::arc(elbow.x+lgl_const::button_width+27, elbow.y+45, 27, 180, 270);
	lgl_utils::draw_text(elbow.x+5, elbow.y+lgl_const::button_height*(elbow.size+2)-15, 3, text);
}

int lgl_elbow::draw_x1_y1(){
	// Button rectangle
	lgl_shapes::rectangle(elbow.x+elbow.length+27, elbow.x+elbow.length+27+lgl_const::button_width, elbow.y+45,
			      elbow.y+elbow.size*lgl_const::button_height+elbow.size*lgl_const::gap+45+29);
	// Button arc
	lgl_shapes::arc(elbow.x+elbow.length+27+(lgl_const::button_width-45), elbow.y+45, 45, -90, 0);
	// Filler box
	lgl_shapes::rectangle(elbow.x+elbow.length, elbow.x+elbow.length+27+(lgl_const::button_width-45),
			      elbow.y, elbow.y+45);
	// Bar
	lgl_shapes::rectangle(elbow.x, elbow.x+elbow.length, elbow.y, elbow.y+18);
	
	glColor3f(0.0, 0.0, 0.0);

	// Erase inner arc portion
	lgl_shapes::arc(elbow.x+elbow.length, elbow.y+45, 27, -90, 0);
	lgl_utils::draw_text(elbow.x+elbow.length+27+5, elbow.y+lgl_const::button_height*(elbow.size+2)-15, 3, text);
}
