#pragma once

#include "lgl_object.h"
#include <iostream>

typedef struct {
	int x;
	int y;
	int x_size;
	int y_size;
} fullscreen_data;

class lgl_fullscreen : public lgl_object {
public:
	lgl_fullscreen(int corner_x, int corner_y, int size_x, int size_y, int era, int color, float scale, std::string main_text, std::string sub_text) : lgl_object(era, color, scale){
		fullscreen.x = fullscreen.x;
		fullscreen.y = fullscreen.y;
		fullscreen.x_size = fullscreen.x_size;
		fullscreen.y_size = fullscreen.y_size;
		
		this->main_text = main_text;
		this->sub_text = sub_text;
	}
	~lgl_fullscreen(){}
	
	int draw();
private:
	fullscreen_data fullscreen;
	std::string main_text;
	std::string sub_text;
};
