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

#include "lgl_object.h"
#include "lgl_const.h"

typedef struct {
	int x1;
	int x2;
	int y1;
	int y2;
} multibutton_data;

class lgl_multibutton : public lgl_object {
public:
	lgl_multibutton(int corner_x, int corner_y, int extend, int era, int color) : lgl_object(era, color){
		data.x1 = corner_x*(lgl_const::button_width + lgl_const::gap);
		data.x2 = corner_x*(lgl_const::button_width + lgl_const::gap) + lgl_const::button_width;
		data.y1 = corner_y*(lgl_const::button_height + lgl_const::gap);
		data.y2 = corner_y*(lgl_const::button_height + lgl_const::gap) + lgl_const::button_height;
		
		this->extend = extend; 
	}
	
	int setvalue(int value);
	
	virtual int draw();
protected:
	int value;
	multibutton_data data;
private:
	int extend;
};
