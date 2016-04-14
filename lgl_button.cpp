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

#include "lgl_button.h"
#include "lgl_shapes.h"
#include "lgl_utils.h"

using namespace std;

int lgl_button::draw(){
	lgl_utils::colors(era, color);
	
	lgl_shapes::rectangle(data.x1, data.x2, data.y1, data.y2);
	
	lgl_utils::draw_text(data.x1+5, data.y1+5, 3, scale, text);
	
	return 0;
}
