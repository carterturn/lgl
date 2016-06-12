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
#include <iostream>

typedef struct {
	int x;
	int y;
	int x_size;
	int y_size;
} fullscreen_data;

class lgl_fullscreen : public lgl_object {
public:
	lgl_fullscreen(int corner_x, int corner_y, int size_x, int size_y, int era, int color, std::string main_text, std::string sub_text) : lgl_object(era, color){
		fullscreen.x = fullscreen.x*(lgl_const::button_width + lgl_const::gap);
		fullscreen.y = fullscreen.y*(lgl_const::button_height + lgl_const::gap);
		fullscreen.x_size = fullscreen.x_size;
		fullscreen.y_size = fullscreen.y_size;
		
		this->main_text = main_text;
		this->sub_text = sub_text;
	}
	
	int draw();
private:
	fullscreen_data fullscreen;
	std::string main_text;
	std::string sub_text;
};
