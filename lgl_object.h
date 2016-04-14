#pragma once

class lgl_object {
public:
	lgl_object(int era, int color, float scale) {
		this->era = era;
		this->color = color;
		this->scale = scale;
	}
	~lgl_object(){}
	
	virtual int draw() = 0;

protected:
	int era;
	int color;
	float scale;
};
