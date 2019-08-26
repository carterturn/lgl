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

#include <vector>

using std::vector;

namespace lgl {
	struct color{
		float R;
		float G;
		float B;
	};
	
	const int grid_width = 60;
	const int grid_height = 24;
	const int gap = 1;

	extern vector<color> colors;
	extern float scale_factor;
}
