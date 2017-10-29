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

#pragma once

#include "lgl_const.h"
#include "lgl_callable.h"

namespace lgl {

	const int left_mouse_button = 1;
	const int right_mouse_button = 2;
	const int mouse_down_state = 1;
	const int mouse_up_state = 2;
	
	class clickable {
	public:
		clickable(callable * call_on_click, int mouse_button=left_mouse_button,
			  int mouse_state=mouse_down_state);
		
		bool try_click(int click_x, int click_y, int mouse_button, int mouse_state);
		
	protected:
		virtual bool clicked(int click_x, int click_y) = 0;

	private:
		callable * m_call_on_click;
		
		int m_mouse_button;
		int m_mouse_state;
	};

};
