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

#include "lgl_clickable.h"

using namespace lgl;

clickable::clickable(callable * call_on_click, int mouse_button, int mouse_state)
	: m_call_on_click(call_on_click), m_mouse_button(mouse_button), m_mouse_state(mouse_state) {}

bool clickable::try_click(int click_x, int click_y, int mouse_button, int mouse_state){
	int grid_x = click_x / ((grid_width + gap) * scale_factor);
	int grid_y = click_y / ((grid_height + gap) * scale_factor);
	
	bool was_clicked = clicked(grid_x, grid_y, mouse_button, mouse_state);
	if(was_clicked && mouse_button == m_mouse_button && mouse_state == m_mouse_state){
		m_call_on_click->call();
	}
	return was_clicked;
}
