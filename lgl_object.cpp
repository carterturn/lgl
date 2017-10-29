/*
  Copyright 2017 Carter Turnbaugh

  This file is part of LGL.

  LGL is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  LGL is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with LGL.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "lgl_object.h"

#include <GL/gl.h>
#include <cmath>
#include <iostream>

using namespace lgl;
using std::cerr;
using std::cout;
using std::endl;

object::object(){
	font = new FTTextureFont(font_path.c_str());
	if(font->Error()){
		cerr << "Font not found" << endl;
		return;
	}
	
	font->FaceSize(60);
}

object::~object(){
	delete font;
}

void object::draw(int color){
	glColor3f(colors[color].R, colors[color].G, colors[color].B);
	
	draw_shapes();
}

void object::draw_text(int grid_x, int grid_y, string text){
	glColor3f(0.0f, 0.0f, 0.0f);

	int font_size = 61;
	
	int right = 0;
	int top = 0;
		
	do {
		font->FaceSize(font_size - 1);
		FTBBox bounding_box = font->BBox(text.c_str(), text.length());
		right = bounding_box.Upper().X();
		top = bounding_box.Upper().Y();
		font_size--;
	} while(right > grid_width * 3.0/4.0 || top > grid_height * 3.0/4.0);

	int left = grid_x * (grid_width + gap) + grid_width * 1.0/8.0;
	int bottom = grid_y * (grid_height + gap) + gap;

	glTranslated(left, bottom, 0);

	font->Render(text.c_str());

	glTranslated(-left, -bottom, 0);
}

void object::full_rectangle(int grid_left, int grid_right, int grid_bottom, int grid_top){
	int left = grid_left * (grid_width + gap);
	int right = grid_right * (grid_width + gap) + grid_width;
	int bottom = grid_bottom * (grid_height + gap);
	int top = grid_top * (grid_height + gap) + grid_height;
	
	glBegin(GL_QUADS);
	
	glVertex2i(left, top);
	glVertex2i(right, top);
	glVertex2i(right, bottom);
	glVertex2i(left, bottom);
	
	glEnd();
}

void object::half_rectangle(int grid_left, int grid_right, int grid_bottom, int grid_top, bool at_top){
	int left = grid_left * (grid_width + gap);
	int right = grid_right * (grid_width + gap) + grid_width;
	int bottom = grid_bottom * (grid_height + gap);
	int top = grid_top * (grid_height + gap);

	if(at_top){
		bottom += grid_height / 2;
	}
	else{
		top -= grid_height / 2;
	}
	
	glBegin(GL_QUADS);
	
	glVertex2i(left, top);
	glVertex2i(right, top);
	glVertex2i(right, bottom);
	glVertex2i(left, bottom);
	
	glEnd();
}

float object::get_arc_start_angle(bool left, bool down){
	if(left && down) return 90;
	if(left && !down) return 180;
	if(!left && down) return 0;
	return 270;
}

float object::get_arc_end_angle(bool left, bool down){
	if(left && down) return 180;
	if(left && !down) return 270;
	if(!left && down) return 90;
	return 360;
}

void object::full_arc(int grid_x, int grid_y, bool left, bool down){
	int center_x, center_y;
	if(left){
		center_x = grid_x * (grid_width + gap) + grid_height;
	}
	else{
		center_x = grid_x * (grid_width + gap) + grid_width - grid_height;
	}
	if(down){
		center_y = grid_y * (grid_height + gap);
	}
	else{
		center_y = grid_y * (grid_height + gap) + grid_height;
	}

	float start_angle = get_arc_start_angle(left, down);
	float end_angle = get_arc_end_angle(left, down);
	float radius =  grid_height;
	
	glBegin(GL_POLYGON);
	glVertex2i(center_x,center_y);
	for(float i = start_angle; i < end_angle; i+=0.02){
		float angle = i/57.3;
		float x2 = center_x+cos(angle)*radius;
		float y2 = center_y+sin(angle)*radius;
		glVertex2f(x2,y2);
	}
	glEnd();
}

void object::half_arc(int grid_x, int grid_y, bool left, bool at_top, bool down){
	int center_x, center_y;
	if(left){
		center_x = grid_x * (grid_width + gap) + grid_height;
	}
	else{
		center_x = grid_x * (grid_width + gap) + grid_width - grid_height;
	}
	if(down){
		center_y = grid_y * (grid_height + gap);
		if(at_top){
			center_y += grid_height / 2;
		}
	}
	else{
		center_y = grid_y * (grid_height + gap) + grid_height;
		if(!at_top){
			center_y -= grid_height / 2;
		}
	}

	float start_angle = get_arc_start_angle(left, down);
	float end_angle = get_arc_end_angle(left, down);
	float radius =  grid_height / 2.0f;
	
	glBegin(GL_POLYGON);
	glVertex2i(center_x,center_y);
	for(float i = start_angle; i < end_angle; i+=0.02){
		float angle = i/57.3;
		float x2 = center_x+cos(angle)*radius;
		float y2 = center_y+sin(angle)*radius;
		glVertex2f(x2,y2);
	}
	glEnd();
}

vector<color> lgl::colors = vector<color>();
float lgl::scale_factor = 1.0f;
string lgl::font_path = "./font.ttf";
