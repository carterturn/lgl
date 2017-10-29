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

#include <FTGL/ftgl.h>

#include <vector>
#include <string>

using std::vector;
using std::string;

namespace lgl {
	
	struct color{
		float R;
		float G;
		float B;
	};
	
	const int grid_width = 45;
	const int grid_height = 18;
	const int gap = 1;

	extern vector<color> colors;
	extern float scale_factor;
	extern string font_path;

	class object {
	public:
		object();
		~object();

		void draw(int color);
	protected:
		virtual void draw_shapes() = 0;
		
		void draw_text(int grid_left, int grid_bottom, string text);

		void full_rectangle(int grid_left, int grid_right, int grid_bottom, int grid_top);
		void half_rectangle(int grid_left, int grid_right, int grid_bottom, int grid_top, bool at_top);
		void full_arc(int grid_x, int grid_y, bool left, bool down);
		void half_arc(int grid_x, int grid_y, bool left, bool at_top, bool down);
	private:
		float get_arc_start_angle(bool left, bool down);
		float get_arc_end_angle(bool left, bool down);
		
		FTTextureFont * font;
	};
};
