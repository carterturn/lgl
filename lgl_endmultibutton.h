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

#include "lgl_multibutton.h"

class lgl_endmultibutton : public lgl_multibutton {
public:
	lgl_endmultibutton(int corner_x, int corner_y, int era, int color, float scale) : lgl_multibutton(corner_x, corner_y, 0, era, color, scale){}
	~lgl_endmultibutton(){}
	
	int draw();
};
