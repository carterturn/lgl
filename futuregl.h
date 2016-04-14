#pragma once

#include <iostream>
#include <vector>
#include "lgl_object.h"

#include "lgl_button.h"
#include "lgl_cmdbutton.h"
#include "lgl_endbutton.h"
#include "lgl_multibutton.h"
#include "lgl_endmultibutton.h"
#include "lgl_elbow.h"
#include "lgl_elbowbutton.h"
#include "lgl_bar.h"
#include "lgl_fullscreen.h"

class futuregl {

public:
	futuregl(float scale, int era);
	~futuregl();

	int button(int corner_x, int corner_y, int size, int color, std::string text);
	int cmdbutton(int corner_x, int corner_y, int color, std::string text);
	int endbutton(int corner_x, int corner_y, int orientation, int color, std::string text);
	int multibutton(int corner_x, int corner_y, int extend, int color);
	int endmultibutton(int corner_x, int corner_y, int color);

	int elbow(int corner_x, int corner_y, int length, int size, int orientation_x, int orientation_y, int color, std::string text);
	int elbowbutton(int corner_x, int corner_y, int length, int size, int orientation_x, int orientation_y, int color, std::string text);
	int bar(int corner_x, int corner_y, int length, int color);

	int fullscreen(int corner_x, int corner_y, int size_x, int size_y, int color, std::string main_text, std::string sub_text);
	
	int setmultibutton(int id, int value, bool end=false);
	
	int draw();
	
	std::string getclicked(int mouse_x, int mouse_y);
	
private:
	float scale;
	int era;
	
	std::vector<lgl_button> buttons;
	std::vector<lgl_cmdbutton> cmdbuttons;
	std::vector<lgl_endbutton> endbuttons;
	std::vector<lgl_multibutton> multibuttons;
	std::vector<lgl_endmultibutton> endmultibuttons;
	
	std::vector<lgl_elbow> elbows;
	std::vector<lgl_elbowbutton> elbowbuttons;
	
	std::vector<lgl_bar> bars;
	std::vector<lgl_fullscreen> fullscreens;
};
