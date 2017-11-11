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

#include "lgl_object.h"

#include <string>

using std::string;

namespace lgl {
	
	class elbow : public object {
	public:
		elbow(int color, int column, int row, int length, bool right, bool down, string text);

		int max_grid_left();
		int max_grid_right();
		int max_grid_top();
		int max_grid_bottom();

	protected:
		void draw_shapes();
		
		void elbow_outside();
		void elbow_inside();

		int m_column, m_row, m_length;
		bool m_right, m_down;
		string m_text;
	};
	
};
