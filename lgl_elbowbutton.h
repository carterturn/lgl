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

#include "lgl_elbow.h"
#include "lgl_abstract_button.h"
#include "lgl_const.h"

class lgl_elbowbutton : public lgl_elbow, public lgl_abstract_button {
public:
	lgl_elbowbutton(int corner_x, int corner_y, int length, int size, int orientation_x, int orientation_y, int era, int color, std::string text) 
: lgl_elbow(corner_x, corner_y, length, size, orientation_x, orientation_y, era, color, text), lgl_abstract_button(era, color, text){
		if(orientation_x == 0){
			if(orientation_y == 0){
				data.x1 = corner_x*(lgl_const::button_width + lgl_const::gap);
				data.y1 = corner_y*(lgl_const::button_height + lgl_const::gap) - lgl_const::gap;
				data.x2 = corner_x*(lgl_const::button_width + lgl_const::gap)
					+ lgl_const::button_width;
				data.y2 = (corner_y + size)*(lgl_const::button_height + lgl_const::gap);
			}	
			else{
				data.x1 = corner_x*(lgl_const::button_width + lgl_const::gap);
				data.y1 = corner_y*(lgl_const::button_height + lgl_const::gap) + 35;
				data.x2 = corner_x*(lgl_const::button_width + lgl_const::gap)
					+ lgl_const::button_width;
				data.y2 = (corner_y + size)*(lgl_const::button_height + lgl_const::gap) + 36;
			}
		}
		else {
			if(orientation_y == 0){
				data.x1 = corner_x*(lgl_const::button_width + lgl_const::gap) + length + 27;
				data.y1 = corner_y*(lgl_const::button_height + lgl_const::gap) - lgl_const::gap;
				data.x2 = corner_x*(lgl_const::button_width + lgl_const::gap)
					+ length*lgl_const::button_width + 27 + lgl_const::button_width;
				data.y2 = (corner_y + size)*(lgl_const::button_height + lgl_const::gap);
			}
			else{
				data.x1 = corner_x*(lgl_const::button_width + lgl_const::gap)
					+ length*lgl_const::button_width + 27;
				data.y1 = corner_y*(lgl_const::button_height + lgl_const::gap) + 35;
				data.x2 = corner_x*(lgl_const::button_width + lgl_const::gap)
					+ length*lgl_const::button_width + 27 + lgl_const::button_width;
				data.y2 = (corner_y + size)*(lgl_const::button_height + lgl_const::gap) + 36;
			}
		}
	}
	
	int draw(){
		lgl_elbow::draw();
		return 0;
	}
	
	std::string gettext(){
		return lgl_abstract_button::text;
	}
};
