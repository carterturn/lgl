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

#pragma once

#include "lgl_abstract_button.h"
#include "lgl_const.h"

class lgl_button : public lgl_abstract_button {
public:
	lgl_button(int corner_x, int corner_y, int size, int era, int color, std::string text) : lgl_abstract_button(era, color, text){
		data.x1 = corner_x*(lgl_const::button_width + lgl_const::gap);
		data.y1 = corner_y*(lgl_const::button_height + lgl_const::gap);
		data.x2 = corner_x*(lgl_const::button_width + lgl_const::gap) + lgl_const::button_width;
		data.y2 = corner_y*(lgl_const::button_height + lgl_const::gap) + lgl_const::button_height*size
			+ lgl_const::gap*(size-1);
		
		this->size = size;
	}
	
	int draw();

private:
	int size;
};
