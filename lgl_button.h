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

#include "lgl_label.h"
#include "lgl_clickable.h"

namespace lgl {
	
	class button : public label, public clickable {
	public:
		button(int color, int column, int row, int height, string text, callable * call_on_click);
		button(int color, int column, int row, bool left_cap, bool right_cap,
		       string text, callable * call_on_click);

	protected:
		bool clicked(int grid_click_x, int grid_click_y, int mouse_button, int mouse_state);
	};
	
};
