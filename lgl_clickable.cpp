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

clickable::clickable(callable * call_on_click) : m_call_on_click(call_on_click) {}

bool clickable::try_click(int click_x, int click_y){
	bool was_clicked = clicked(click_x, click_y);
	if(was_clicked){
		m_call_on_click->call();
	}
	return was_clicked;
}
