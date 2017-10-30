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

#include "lgl_elbow.h"

#include <GL/gl.h>

using namespace lgl;

elbow::elbow(int color, int column, int row, int length, bool right, bool down, string text)
	: object(color), m_column(column), m_row(row), m_length(length),
	  m_right(right), m_down(down), m_text(text) {}

void elbow::draw_shapes(){
	int right_adj = m_right ? 1 : -2;
	int left_adj = m_right ? 2 : -1;
	length_adjusted_rectangle(m_column, m_row, left_adj, right_adj);

	if(m_right){
		half_rectangle(m_column + 1, m_column + 1 + m_length, m_row, m_down);
	}
	else{
		half_rectangle(m_column - 1 - m_length, m_column - 1, m_row, m_down);
	}

	elbow_outside();

	temp_color(0);
	elbow_inside();
	set_color();
}

void elbow::elbow_outside(){
	int center_x, center_y;
	if(m_right){
		center_x = (m_column * (grid_width + gap) + grid_height) * scale_factor;
	}
	else{
		center_x = (m_column * (grid_width + gap) + grid_width - grid_height) * scale_factor;
	}
	if(m_down){
		center_y = (m_row * (grid_height + gap)) * scale_factor;
	}
	else{
		center_y = (m_row * (grid_height + gap) + grid_height) * scale_factor;
	}

	arc(center_x, center_y, grid_height * scale_factor,
	    get_arc_start_angle(m_right, m_down), get_arc_end_angle(m_right, m_down));
}

void elbow::elbow_inside(){
	int center_x, center_y;
	if(m_right){
		center_x = (m_column * (grid_width + gap) + grid_width + grid_height / 2) * scale_factor;
	}
	else{
		center_x = (m_column * (grid_width + gap) - grid_height / 2) * scale_factor;
	}
	if(m_down){
		center_y = m_row * (grid_height + gap) * scale_factor;
	}
	else{
		center_y = (m_row * (grid_height + gap) + grid_height) * scale_factor;
	}

	arc(center_x, center_y, (grid_height / 2.0f) * scale_factor,
	    get_arc_start_angle(m_right, m_down), get_arc_end_angle(m_right, m_down));
}
