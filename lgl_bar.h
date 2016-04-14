#pragma once

#include "lgl_object.h"
#include "lgl_const.h"

typedef struct{
	int x1;
	int x2;
	int y1;
	int y2;
} bar_data;

class lgl_bar : public lgl_object {
public:
	lgl_bar(int corner_x, int corner_y, int length, int era, int color, float scale) : lgl_object(era, color, scale){
		data.x1 = corner_x;
		data.x2 = corner_x + length;
		data.y1 = corner_y;
		data.y2 = corner_y + lgl_const::button_height/2;
	}
	~lgl_bar(){}
	
	int draw();
private:
	bar_data data;
};
