#pragma once

#include "lgl_multibutton.h"

class lgl_endmultibutton : public lgl_multibutton {
public:
	lgl_endmultibutton(int corner_x, int corner_y, int era, int color, float scale) : lgl_multibutton(corner_x, corner_y, 0, era, color, scale){}
	~lgl_endmultibutton(){}
	
	int draw();
};
