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

#include "lgl_button.h"

using namespace lgl;

button::button(int color, int column, int row, int height, string text, callable * call_on_click)
	: label(color, column, row, height, text), clickable(call_on_click) {}

button::button(int color, int column, int row, bool left_cap, bool right_cap, string text, callable * call_on_click)
	: label(color, column, row, left_cap, right_cap, text), clickable(call_on_click) {}

bool button::clicked(int grid_click_x, int grid_click_y, int mouse_button, int mouse_state){
	bool clicked = grid_click_x == m_column && (m_row <= grid_click_y && m_row + m_height >= grid_click_y);
	if(clicked && mouse_state == m_mouse_state && mouse_button == m_mouse_button){
		if(colors.size() > m_original_color + 1){
			set_color(m_original_color + 1);
		}
	}
	else{
		reset_color();
	}
	return clicked;
}
