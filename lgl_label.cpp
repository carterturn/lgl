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

#include "lgl_label.h"

using namespace lgl;

label::label(int color, int column, int row, int height, string text)
	: object(color), m_column(column), m_row(row), m_height(height), m_text(text),
	  m_left_cap(false), m_right_cap(false) {}

label::label(int color, int column, int row, bool left_cap, bool right_cap, string text)
	: object(color), m_column(column), m_row(row), m_height(0), m_text(text),
	  m_left_cap(left_cap), m_right_cap(right_cap) {}

void label::draw_shapes(){
	if(!m_left_cap && !m_right_cap){
		full_rectangle(m_column, m_column, m_row, m_row + m_height);
	}
	else{
		short left_adj = m_left_cap ? 1 : 0;
		short right_adj = m_right_cap ? -1 : 0;

		length_adjusted_rectangle(m_column, m_row, left_adj, right_adj);
	}

	if(m_left_cap){
		cap(true);
	}
	if(m_right_cap){
		cap(false);
	}

	draw_text(m_column, m_row, m_text);
}

void label::cap(bool left){
	int center_x;
	if(left){
		center_x = (m_column * (grid_width + gap) + grid_height / 2) * scale_factor;
	}
	else{
		center_x = (m_column * (grid_width + gap) + grid_width - grid_height / 2) * scale_factor;
	}

	float start_angle, end_angle;
	if(left){
		start_angle = 90;
		end_angle = 270;
	}
	else{
		start_angle = -90;
		end_angle = 90;
	}
	
	arc(center_x, m_row * (grid_height + gap) + grid_height / 2, grid_height / 2, start_angle, end_angle);
}
