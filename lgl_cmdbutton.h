#pragma once

#include "lgl_abstract_button.h"
#include "lgl_const.h"

class lgl_cmdbutton : public lgl_abstract_button {
public:
	lgl_cmdbutton(int corner_x, int corner_y, float scale, int era, int color, std::string text) : lgl_abstract_button(era, color, scale, text){
		data.x1 = corner_x;
		data.y1 = corner_y;
		data.x2 = corner_x + lgl_const::button_width;
		data.y2 = corner_y + lgl_const::button_height;
	}
	~lgl_cmdbutton(){}
	
	int draw();
};
