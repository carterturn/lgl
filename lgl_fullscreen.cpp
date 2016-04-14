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

#include "lgl_fullscreen.h"

#include <GL/gl.h>

#include "lgl_shapes.h"
#include "lgl_utils.h"
#include "lgl_const.h"

using namespace std;

int lgl_fullscreen::draw(){
	lgl_utils::colors(era, color);
	
	lgl_shapes::rectangle(fullscreen.x+18*4/5, fullscreen.x+fullscreen.x_size-18*4/5, fullscreen.y, fullscreen.y+(lgl_const::button_height*4/5));
	lgl_shapes::rectangle(fullscreen.x+18, fullscreen.x+fullscreen.x_size-18, fullscreen.y+fullscreen.y_size-lgl_const::button_height, fullscreen.y+fullscreen.y_size);
	
	lgl_shapes::arc(fullscreen.x+18*4/5, fullscreen.y+18*4/5, 18*4/5, 90, 270);
	lgl_shapes::arc(fullscreen.x+18, fullscreen.y+fullscreen.y_size-18, 18, 90, 270);
	lgl_shapes::arc(fullscreen.x+fullscreen.x_size-18*4/5, fullscreen.y+18*4/5, 18*4/5, -90, 90);
	lgl_shapes::arc(fullscreen.x+fullscreen.x_size-18, fullscreen.y+fullscreen.y_size-18, 18, -90, 90);
	
	glColor3f(0.0, 0.0, 0.0);
	
	lgl_shapes::rectangle(fullscreen.x+fullscreen.x_size*1/9, fullscreen.x+fullscreen.x_size*1/9+sub_text.length()*12, fullscreen.y, fullscreen.y+(lgl_const::button_height*4/5));
	lgl_shapes::rectangle(fullscreen.x+fullscreen.x_size*5/9, fullscreen.x+fullscreen.x_size*5/9+main_text.length()*14, fullscreen.y+fullscreen.y_size-lgl_const::button_height, fullscreen.y+fullscreen.y_size);
	
	lgl_utils::draw_text(fullscreen.x+fullscreen.x_size*1/9, fullscreen.y, 2, scale, sub_text, 1);
	lgl_utils::draw_text(fullscreen.x+fullscreen.x_size*5/9, fullscreen.y+fullscreen.y_size-lgl_const::button_height, 1, scale, main_text, 1);
	
	glColor3f(0.0, 0.0, 0.0);
	
	lgl_shapes::rectangle(fullscreen.x+fullscreen.x_size*33/36, fullscreen.x+fullscreen.x_size*17/18, fullscreen.y, fullscreen.y+(lgl_const::button_height*4/5));
	lgl_shapes::rectangle(fullscreen.x+fullscreen.x_size*1/18, fullscreen.x+fullscreen.x_size*3/36, fullscreen.y+fullscreen.y_size-lgl_const::button_height, fullscreen.y+fullscreen.y_size);
}
