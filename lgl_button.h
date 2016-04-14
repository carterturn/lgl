#pragma once

#include "lgl_abstract_button.h"
#include "lgl_const.h"

class lgl_button : public lgl_abstract_button {
public:
	lgl_button(int corner_x, int corner_y, int size, int era, int color, float scale, std::string text) : lgl_abstract_button(era, color, scale, text){
		data.x1 = corner_x;
		data.y1 = corner_y;
		data.x2 = corner_x + lgl_const::button_width;
		data.y2 = corner_y + lgl_const::button_height*size + lgl_const::gap*(size-1);
		
		this->size = size;
	}
	~lgl_button(){}
	
	int draw();

private:
	int size;
};
