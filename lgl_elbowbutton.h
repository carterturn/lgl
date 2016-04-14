#pragma once

#include "lgl_elbow.h"
#include "lgl_abstract_button.h"
#include "lgl_const.h"

class lgl_elbowbutton : public lgl_elbow, public lgl_abstract_button {
public:
	lgl_elbowbutton(int corner_x, int corner_y, int length, int size, int orientation_x, int orientation_y, int era, int color, float scale, std::string text) 
: lgl_elbow(corner_x, corner_y, length, size, orientation_x, orientation_y, era, color, scale, text), lgl_abstract_button(era, color, scale, text){
		if(orientation_x == 0){
			if(orientation_y == 0){
				data.x1 = corner_x;
				data.y1 = corner_y;
				data.x2 = corner_x + lgl_const::button_width;
				data.y2 = corner_y + 20 + lgl_const::button_height*(size-1) + 2*(size-1);
			}	
			else{
				data.x1 = corner_x;
				data.y1 = corner_y + 35;
				data.x2 = corner_x + lgl_const::button_width;
				data.y2 = corner_y + 45 + 10 + lgl_const::button_height*(size-1) + 2*(size-1);
			}
		}
		else {
			if(orientation_y == 0){
				data.x1 = corner_x + length + 27;
				data.y1 = corner_y;
				data.x2 = corner_x + length + 27 + lgl_const::button_width;
				data.y2 = corner_y + 20 + lgl_const::button_height*(size-1) + 2*(size-1);
			}
			else{
				data.x1 = corner_x + length + 27;
				data.y1 = corner_y + 35;
				data.x2 = corner_x + length + 27 + lgl_const::button_width;
				data.y2 = corner_y + 45 + 10 + lgl_const::button_height*(size-1) + 2*(size-1);
			}
		}
	}
	~lgl_elbowbutton(){}
	
	int draw(){
		lgl_elbow::draw();
		return 0;
	}
	
	std::string gettext(){
		return lgl_abstract_button::text;
	}
};
