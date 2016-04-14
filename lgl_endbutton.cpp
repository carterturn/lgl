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

#include "lgl_endbutton.h"
#include "lgl_utils.h"
#include "lgl_shapes.h"

using namespace std;

int lgl_endbutton::draw(){
	lgl_utils::colors(era, color);
	
	lgl_shapes::rectangle(data.x1+(lgl_const::button_height/2 * orientation), data.x2+(lgl_const::button_height/2 * (orientation - 1)), data.y1, data.y2);
	
	if(orientation == 1) lgl_shapes::arc(data.x1+lgl_const::button_height/2, data.y1+lgl_const::button_height/2, lgl_const::button_height/2, 90, 270);
	if(orientation == 0) lgl_shapes::arc(data.x2-lgl_const::button_height/2, data.y1+lgl_const::button_height/2, lgl_const::button_height/2, -90, 90);
	
	lgl_utils::draw_text(data.x1+(lgl_const::button_height/2 * orientation)+5, data.y1+5, 3, text);
	
	return 0;
}
