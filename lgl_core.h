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
#include "lgl_clickable.h"
#include "lgl_indicator.h"

#include <GLFW/glfw3.h>

namespace lgl {
	
	class core {
	public:
		core(string window_title = "");
		~core();

		void initialize();
		void loop();

		void add_button(int color, int column, int row, int height, string text, callable * call_on_click);
		void add_button(int color, int column, int row, bool left_cap, bool right_cap,
				string text, callable * call_on_click);
		void add_elbow(int color, int column, int row, int length, bool right, bool down, string text);
		int add_indicator(int color, int column, int row, bool left_cap, bool right_cap);
		void add_label(int color, int column, int row, int height, string text);
		void add_label(int color, int column, int row, bool left_cap, bool right_cap, string text);

		void set_indicator(int index, string text);

	protected:
		void mouse_callback(int button, int state, int modifiers);
		static void s_mouse_callback(GLFWwindow * window, int button, int state, int modifiers);
		
		void keyboard_callback(int key, int scancode, int action, int mods);
		static void s_keyboard_callback(GLFWwindow * window, int key, int scancode, int action, int mods);

	private:
		GLFWwindow * m_window;
		string m_window_title;

		vector<object *> objects;
		vector<clickable *> clickable_objects;
		vector<indicator *> indicator_objects;

		int m_mouse_y_max, m_window_width, m_window_height;
	};
	
};
