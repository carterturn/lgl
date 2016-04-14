#pragma once

#ifndef LGL_UTILS
#define LGL_UTILS 0

#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include <FTGL/ftgl.h>
#include <sstream>
#include <iostream>

using namespace std;

class lgl_utils {
public:
	static string its(int in){
		stringstream ss;
		ss << in;
		return ss.str();
	}
	
	static void colors(int era, int choice){
		if(era == 1){
			if(choice == 1) glColor3f(0.5f, 0.5f, 0.5f);
			else if(choice == 2) glColor3f(1.0f, 1.0f, 0.6f);
			else if(choice == 3) glColor3f(1.0f, 0.8f, 0.6f);
			else if(choice == 4) glColor3f(1.0f, 0.6f, 0.2f);
			else if(choice == 5) glColor3f(0.4f, 0.267f, 0.4f);
			else if(choice == 6) glColor3f(0.8f, 0.6f, 0.8f);
			else if(choice == 7) glColor3f(0.6f, 0.8f, 1.0f);
			else if(choice == 8) glColor3f(0.2f, 0.4f, 0.8f);
			else if(choice == 9) glColor3f(0.0f, 0.4f, 0.6f);
			else if(choice == 10) glColor3f(0.0f, 0.0f, 0.0f);
		}
		else if(era == 2){
			if(choice == 1) glColor3f(0.5f, 0.5f, 0.5f);
			else if(choice == 2) glColor3f(0.6f, 0.6f, 0.9f);
			else if(choice == 3) glColor3f(0.6f, 0.6f, 0.8f);
			else if(choice == 4) glColor3f(0.8f, 0.6f, 0.8f);
			else if(choice == 5) glColor3f(0.8f, 0.0f, 0.6f);
			else if(choice == 6) glColor3f(0.8f, 0.4f, 0.4f);
			else if(choice == 7) glColor3f(1.0f, 0.6f, 0.4f);
			else if(choice == 8) glColor3f(1.0f, 0.6f, 0.0f);
			else if(choice == 9) glColor3f(1.0f, 0.8f, 0.4f);
			else if(choice == 10) glColor3f(0.0f, 0.0f, 0.0f);
		}
		else if(era == 3){
			if(choice == 1) glColor3f(0.5f, 0.5f, 0.5f);
			else if(choice == 2) glColor3f(0.4f, 0.533f, 0.8f);
			else if(choice == 3) glColor3f(0.267f, 0.333f, 0.722f);
			else if(choice == 4) glColor3f(0.6f, 0.467f, 0.667f);
			else if(choice == 5) glColor3f(0.467f, 0.267f, 0.4f);
			else if(choice == 6) glColor3f(0.867f, 0.4f, 0.267f);
			else if(choice == 7) glColor3f(0.667f, 0.333f, 0.2f);
			else if(choice == 8) glColor3f(0.722f, 0.4f, 0.133f);
			else if(choice == 9) glColor3f(0.933f, 0.6f, 0.333f);
			else if(choice == 10) glColor3f(0.0f, 0.0f, 0.0f);
		}
		else if(era == 4){
			if(choice == 1) glColor3f(0.5f, 0.5f, 0.5f);
			else if(choice == 2) glColor3f(0.8f, 0.867f, 1.0f);
			else if(choice == 3) glColor3f(0.333f, 0.6f, 1.0f);
			else if(choice == 4) glColor3f(0.2f, 0.4f, 1.0f);
			else if(choice == 5) glColor3f(0.0f, 0.067f, 0.933f);
			else if(choice == 6) glColor3f(0.0f, 0.0f, 0.533f);
			else if(choice == 7) glColor3f(0.733f, 0.667f, 0.333f);
			else if(choice == 8) glColor3f(0.733f, 0.267f, 0.067f);
			else if(choice == 9) glColor3f(0.533f, 0.133f, 0.067f);
			else if(choice == 10) glColor3f(0.0f, 0.0f, 0.0f);
		}
		else {
			cout << "Coloring is null\n";
		}
	}
	
	static int draw_text(int corner_x, int corner_y, int size, float scale, string text, int color=10){
	
		if((size > 4 || size < 1) && size < 10 ){
			cout << "LCARS GL only supports 4 font sizes\nPlease adapt your code. Sorry.\n";
			return -1;
		}
	
		colors(1, color);
		glRasterPos2f(corner_x, corner_y);
	
		// Create a pixmap font from a TrueType file.
		FTGLPixmapFont *font = new FTGLPixmapFont("font.ttf");
	
		// If something went wrong, bail out.
		if(font->Error()){
		    cout << "Font not found\n";
		    return -1;
		}
	
		// Set the font size and render a small text.
		
		if(size == 1) font->FaceSize(36*scale);
		else if(size == 2) font->FaceSize(18*scale);
		else if(size == 3) font->FaceSize(8*scale);
		else if(size == 4) font->FaceSize(8*scale);
		else font->FaceSize(size*scale);
		font->Render(text.c_str());

		delete(font);
	
		return 0;
	}

};

#endif
