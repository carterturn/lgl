#pragma once

#include "lgl_abstract_button.h"
#include "lgl_const.h"

class lgl_endbutton : public lgl_abstract_button {
public:
	lgl_endbutton(int corner_x, int corner_y, int orientation, float scale, int era, int color, std::string text) : lgl_abstract_button(era, color, scale, text){
		data.x1 = corner_x;
		data.y1 = corner_y;
		data.x2 = corner_x + lgl_const::button_width;
		data.y2 = corner_y + lgl_const::button_height;
		
		this->orientation = orientation;
	}
	~lgl_endbutton(){}
	
	int draw();
private:
	int orientation;
	
};
