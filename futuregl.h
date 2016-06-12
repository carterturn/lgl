/*
  Copyright 2015 Carter Turnbaugh

  This file is part of FutureGL.

  FutureGL is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  FutureGL is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with FutureGL.  If not, see <http://www.gnu.org/licenses/>.
*/

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
	futuregl(int era);

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

	int load_config(std::string path);
	
private:
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
