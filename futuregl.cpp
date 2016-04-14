#include "futuregl.h"

using namespace std;

futuregl::futuregl(float scale, int era){
	this->scale = scale;
	this->era = era;
	
	buttons.clear();
	cmdbuttons.clear();
	endbuttons.clear();
	multibuttons.clear();
	endmultibuttons.clear();
	
	elbows.clear();
	elbowbuttons.clear();
	
	bars.clear();
	fullscreens.clear();
}

futuregl::~futuregl(){}

int futuregl::button(int corner_x, int corner_y, int size, int color, std::string text){
	lgl_button button(corner_x, corner_y, size, era, color, scale, text);
	buttons.push_back(button);
	return 0;
}

int futuregl::cmdbutton(int corner_x, int corner_y, int color, std::string text){
	lgl_cmdbutton cmdbutton(corner_x, corner_y, scale, era, color, text);
	cmdbuttons.push_back(cmdbutton);
	return 0;
}

int futuregl::endbutton(int corner_x, int corner_y, int orientation, int color, std::string text){
	lgl_endbutton endbutton(corner_x, corner_y, orientation, scale, era, color, text);
	endbuttons.push_back(endbutton);
	return 0;
}

int futuregl::multibutton(int corner_x, int corner_y, int extend, int color){
	lgl_multibutton multibutton(corner_x, corner_y, extend, era, color, scale);
	multibuttons.push_back(multibutton);
	return 0;
}

int futuregl::endmultibutton(int corner_x, int corner_y, int color){
	lgl_endmultibutton endmultibutton(corner_x, corner_y, era, color, scale);
	endmultibuttons.push_back(endmultibutton);
	return 0;
}

int futuregl::elbow(int corner_x, int corner_y, int length, int size, int orientation_x, int orientation_y, int color, std::string text){
	lgl_elbow elbow(corner_x, corner_y, length, size, orientation_x, orientation_y, era, color, scale, text);
	elbows.push_back(elbow);
	return 0;
}

int futuregl::elbowbutton(int corner_x, int corner_y, int length, int size, int orientation_x, int orientation_y, int color, std::string text){
	lgl_elbowbutton elbowbutton(corner_x, corner_y, length, size, orientation_x, orientation_y, era, color, scale, text);
	elbowbuttons.push_back(elbowbutton);
	return 0;
}

int futuregl::bar(int corner_x, int corner_y, int length, int color){
	lgl_bar bar(corner_x, corner_y, length, era, color, scale);
	bars.push_back(bar);
	return 0;
}

int futuregl::fullscreen(int corner_x, int corner_y, int size_x, int size_y, int color, std::string main_text, std::string sub_text){
	lgl_fullscreen fullscreen(corner_x, corner_y, size_x, size_y, era, color, scale, main_text, sub_text);
	fullscreens.push_back(fullscreen);
	return 0;
}

int futuregl::setmultibutton(int id, int value, bool end){
	if(!end) multibuttons[id].setvalue(value);
	else endmultibuttons[id].setvalue(value);
	
	return 0;
}

int futuregl::draw(){
	
	for(int i = 0; i < buttons.size(); i++) buttons[i].draw();
	for(int i = 0; i < cmdbuttons.size(); i++) cmdbuttons[i].draw();
	for(int i = 0; i < endbuttons.size(); i++) endbuttons[i].draw();
	for(int i = 0; i < multibuttons.size(); i++) multibuttons[i].draw();
	for(int i = 0; i < endmultibuttons.size(); i++) endmultibuttons[i].draw();
	for(int i = 0; i < elbows.size(); i++) elbows[i].draw();
	for(int i = 0; i < elbowbuttons.size(); i++) elbowbuttons[i].draw();
	for(int i = 0; i < bars.size(); i++) bars[i].draw();
	for(int i = 0; i < fullscreens.size(); i++) fullscreens[i].draw();
	
	return 0;
}

string futuregl::getclicked(int mouse_x, int mouse_y){
	string clicked_title = "";
	
	for(int i = 0; i < buttons.size(); i++){
		if(buttons[i].clicked(mouse_x, mouse_y)) clicked_title = buttons[i].text;
	}
	for(int i = 0; i < cmdbuttons.size(); i++){
		if(cmdbuttons[i].clicked(mouse_x, mouse_y)) clicked_title = cmdbuttons[i].text;
	}
	for(int i = 0; i < endbuttons.size(); i++){
		if(endbuttons[i].clicked(mouse_x, mouse_y)) clicked_title = endbuttons[i].text;
	}
	for(int i = 0; i < elbowbuttons.size(); i++){
		if(elbowbuttons[i].clicked(mouse_x, mouse_y)) clicked_title = elbowbuttons[i].gettext();
	}
	
	return clicked_title;
}
