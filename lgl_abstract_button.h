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

#include <iostream>
#include "lgl_object.h"

typedef struct {
	int x1;
	int x2;
	int y1;
	int y2;

} button_data;

class lgl_abstract_button : public lgl_object {
public:
lgl_abstract_button(int era, int color, std::string text) : lgl_object(era, color) {
		this->text = text;
		
		data.x1 = 0;
		data.x2 = 0;
		data.y1 = 0;
		data.y2 = 0;
	}
	~lgl_abstract_button(){}
	
	virtual bool clicked(int click_x, int click_y);
	
	std::string text;
	
	virtual int draw() = 0;

protected:
	button_data data;
};
