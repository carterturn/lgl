#pragma once

#include "lgl_object.h"
#include <iostream>

typedef struct {
	int x;
	int y;
	int length;
	int size;
	int x_orient;
	int y_orient;
} elbow_data;

class lgl_elbow : public lgl_object {
public:
	lgl_elbow(int corner_x, int corner_y, int length, int size, int orientation_x, int orientation_y, int era, int color, float scale, std::string text) : lgl_object(era, color, scale){
		elbow.x = corner_x;
		elbow.y = corner_y;
		elbow.length = length;
		elbow.size = size - 1;
		elbow.x_orient = orientation_x;
		elbow.y_orient = orientation_y;
		
		this->text = text;
	}
	~lgl_elbow(){}
	
	virtual int draw();
	
	std::string text;
	
protected:
	elbow_data elbow;
	
	int draw_x0_y0();
	int draw_x1_y0();
	int draw_x0_y1();
	int draw_x1_y1();
};
