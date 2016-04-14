#pragma once

#include <iostream>
#include "lgl_object.h"

typedef struct {
	int x1;
	int x2;
	int y1;
	int y2;

} button_data;

class lgl_abstract_button {
public:
	lgl_abstract_button(int era, int color, float scale, std::string text){
		this->era = era;
		this->color = color;
		this->scale = scale;
		this->text = text;
		
		data.x1 = 0;
		data.x2 = 0;
		data.y1 = 0;
		data.y2 = 0;
	}
	~lgl_abstract_button(){}
	
	virtual bool clicked(int click_x, int click_y);
	
	std::string text;
	
	virtual int draw() = 0;

protected:
	int era;
	int color;
	float scale;
	button_data data;
};
