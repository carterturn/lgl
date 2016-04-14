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
#include <iostream>

typedef struct {
	int x;
	int y;
	int length;
	int size;
	int x_orient;
	int y_orient;
} elbow_data;

class lgl_elbow : public lgl_object {
public:
	lgl_elbow(int corner_x, int corner_y, int length, int size, int orientation_x, int orientation_y, int era, int color, std::string text) : lgl_object(era, color){
		elbow.x = corner_x;
		elbow.y = corner_y;
		elbow.length = length;
		elbow.size = size - 1;
		elbow.x_orient = orientation_x;
		elbow.y_orient = orientation_y;
		
		this->text = text;
	}
	~lgl_elbow(){}
	
	virtual int draw();
	
	std::string text;
	
protected:
	elbow_data elbow;
	
	int draw_x0_y0();
	int draw_x1_y0();
	int draw_x0_y1();
	int draw_x1_y1();
};
