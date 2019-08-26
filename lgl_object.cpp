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
#include <algorithm>
#include <iostream>

using namespace lgl;
using std::cerr;
using std::cout;
using std::endl;
using std::min;
using std::max;

string lgl::font_path = "./font.ttf";

object::object(int color) : m_color(color), m_original_color(color){
	font = new FTTextureFont(font_path.c_str());
	if(font->Error()){
		cerr << "Font not found at " << font_path << endl;
		return;
	}
	
	font->FaceSize(60);
}

object::~object(){
	delete font;
}

void object::set_color(int color){
	m_color = color;
	
	glColor3f(colors[m_color].R, colors[m_color].G, colors[m_color].B);	
}

void object::set_color(){
	glColor3f(colors[m_color].R, colors[m_color].G, colors[m_color].B);	
}

void object::temp_color(int color){
	glColor3f(colors[color].R, colors[color].G, colors[color].B);
}

void object::reset_color(){
	m_color = m_original_color;
	
	glColor3f(colors[m_color].R, colors[m_color].G, colors[m_color].B);	
}

void object::draw(){
	glColor3f(colors[m_color].R, colors[m_color].G, colors[m_color].B);
	
	draw_shapes();
}

void object::draw_text(int grid_x, int grid_y, string text){
	int font_size = 61;
	
	int right = 0;
	int top = 0;
		
	do {
		font->FaceSize(font_size - 1);
		FTBBox bounding_box = font->BBox(text.c_str(), text.length());
		right = bounding_box.Upper().X();
		top = bounding_box.Upper().Y();
		font_size--;
	} while(right > (grid_width - grid_height) * scale_factor
		|| top > grid_height * 7.0/8.0 * scale_factor);

	int left = (grid_x * (grid_width + gap) + grid_height / 2) * scale_factor;
	int bottom = (grid_y * (grid_height + gap) + gap) * scale_factor;

	glTranslated(left, bottom, 0);

	font->Render(text.c_str());

	glTranslated(-left, -bottom, 0);
}

void object::full_rectangle(int grid_left, int grid_right, int grid_bottom, int grid_top){
	int left = (grid_left * (grid_width + gap)) * scale_factor;
	int right = (grid_right * (grid_width + gap) + grid_width) * scale_factor;
	int bottom = (grid_bottom * (grid_height + gap)) * scale_factor;
	int top = (grid_top * (grid_height + gap) + grid_height) * scale_factor;
	
	glBegin(GL_QUADS);
	
	glVertex2i(left, top);
	glVertex2i(right, top);
	glVertex2i(right, bottom);
	glVertex2i(left, bottom);
	
	glEnd();
}

void object::half_rectangle(int grid_left, int grid_right, int grid_y, bool at_top){
	int left = (grid_left * (grid_width + gap)) * scale_factor;
	int right = (grid_right * (grid_width + gap) + grid_width) * scale_factor;
	int bottom = (grid_y * (grid_height + gap)) * scale_factor;
	int top = (grid_y * (grid_height + gap) + grid_height) * scale_factor;

	if(at_top){
		bottom += (grid_height / 2) * scale_factor;
	}
	else{
		top -= (grid_height / 2) * scale_factor;
	}
	
	glBegin(GL_QUADS);
	
	glVertex2i(left, top);
	glVertex2i(right, top);
	glVertex2i(right, bottom);
	glVertex2i(left, bottom);
	
	glEnd();
}

void object::length_adjusted_rectangle(int grid_x, int grid_y, short left_adj, short right_adj){
	int left = (grid_x * (grid_width + gap)
		    + left_adj * grid_height / 2) * scale_factor;
	int right = (grid_x * (grid_width + gap) + grid_width
		     + right_adj * grid_height / 2) * scale_factor;
	int bottom = (grid_y * (grid_height + gap)) * scale_factor;
	int top = (grid_y * (grid_height + gap) + grid_height) * scale_factor;
	
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

void object::arc(int center_x, int center_y, float radius, float start_angle, float end_angle){
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
