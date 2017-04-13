/*
  Copyright 2015 Carter Turnbaugh

  This file is part of FutureGL.

  FutureGL is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  FutureGL is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with FutureGL.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "futuregl.h"
#include <fstream>
#include <cstdlib>

using namespace std;

futuregl::futuregl(int era) : era(era){
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

int futuregl::button(int corner_x, int corner_y, int size, int color, std::string text){
	lgl_button button(corner_x, corner_y, size, era, color, text);
	buttons.push_back(button);
	return 0;
}

int futuregl::cmdbutton(int corner_x, int corner_y, int color, std::string text){
	lgl_cmdbutton cmdbutton(corner_x, corner_y, era, color, text);
	cmdbuttons.push_back(cmdbutton);
	return 0;
}

int futuregl::endbutton(int corner_x, int corner_y, int orientation, int color, std::string text){
	lgl_endbutton endbutton(corner_x, corner_y, orientation, era, color, text);
	endbuttons.push_back(endbutton);
	return 0;
}

int futuregl::multibutton(int corner_x, int corner_y, int extend, int color){
	lgl_multibutton multibutton(corner_x, corner_y, extend, era, color);
	multibuttons.push_back(multibutton);
	return 0;
}

int futuregl::endmultibutton(int corner_x, int corner_y, int color){
	lgl_endmultibutton endmultibutton(corner_x, corner_y, era, color);
	endmultibuttons.push_back(endmultibutton);
	return 0;
}

int futuregl::elbow(int corner_x, int corner_y, int length, int size, int orientation_x, int orientation_y, int color, std::string text){
	lgl_elbow elbow(corner_x, corner_y, length, size, orientation_x, orientation_y, era, color, text);
	elbows.push_back(elbow);
	return 0;
}

int futuregl::elbowbutton(int corner_x, int corner_y, int length, int size, int orientation_x, int orientation_y, int color, std::string text){
	lgl_elbowbutton elbowbutton(corner_x, corner_y, length, size, orientation_x, orientation_y, era, color, text);
	elbowbuttons.push_back(elbowbutton);
	return 0;
}

int futuregl::bar(int corner_x, int corner_y, int length, int color){
	lgl_bar bar(corner_x, corner_y, length, era, color);
	bars.push_back(bar);
	return 0;
}

int futuregl::fullscreen(int corner_x, int corner_y, int size_x, int size_y, int color, std::string main_text, std::string sub_text){
	lgl_fullscreen fullscreen(corner_x, corner_y, size_x, size_y, era, color, main_text, sub_text);
	fullscreens.push_back(fullscreen);
	return 0;
}

int futuregl::setmultibutton(int id, int value, bool end){
	if(!end){
		if(id >= multibuttons.size()){
			return -1;
		}
		multibuttons[id].setvalue(value);
	}
	else{
		if(id >= endmultibuttons.size()){
			return -1;
		}
		endmultibuttons[id].setvalue(value);
	}
	
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

vector<string> split_string(string data, char splitter){
	vector<string> tokens = vector<string>();
	string tmp = "";
	for(int i = 0; i < data.length(); i++){
		if(data[i] == splitter){
			tokens.push_back(tmp);
			tmp = "";
		}
		else{
			tmp += data[i];
		}
	}
	tokens.push_back(tmp);
	return tokens;
}

int futuregl::load_config(string path){

	fstream configfile;
	configfile.open(path.c_str());

	while(!configfile.eof()){
		string line;
		getline(configfile, line);

		vector<string> data = split_string(line, ' ');

		if(data[0] == "button"){
			button(atoi(data[1].c_str()), // corner_x
			       atoi(data[2].c_str()), // corner_y
			       atoi(data[3].c_str()), // size
			       atoi(data[4].c_str()), // color
			       data[5]); // text
		}
		else if(data[0] == "cmdbutton"){
			cmdbutton(atoi(data[1].c_str()), // corner_x
				  atoi(data[2].c_str()), // corner_y
				  atoi(data[3].c_str()), // color
				  data[4]); // text
		}
		else if(data[0] == "endbutton"){
			endbutton(atoi(data[1].c_str()), // corner_x
				  atoi(data[2].c_str()), // corner_y
				  atoi(data[3].c_str()), // orientation
				  atoi(data[4].c_str()), // color
				  data[5]); // text
		}
		else if(data[0] == "multibutton"){
			multibutton(atoi(data[1].c_str()), // corner_x
				    atoi(data[2].c_str()), // corner_y
				    atoi(data[3].c_str()), // extend
				    atoi(data[4].c_str())); //color
		}
		else if(data[0] == "endmultibutton"){
			endmultibutton(atoi(data[1].c_str()), // corner_x
				       atoi(data[2].c_str()), // corner_y
				       atoi(data[3].c_str())); //color
		}
		else if(data[0] == "elbow"){
			elbow(atoi(data[1].c_str()), // corner_x
			      atoi(data[2].c_str()), // corner_y
			      atoi(data[3].c_str()), // length
			      atoi(data[4].c_str()), // size
			      atoi(data[5].c_str()), // orientation_x
			      atoi(data[6].c_str()), // orientation_y
			      atoi(data[7].c_str()), // color
			      data[8]); // text
		}
		else if(data[0] == "elbowbutton"){
			elbowbutton(atoi(data[1].c_str()), // corner_x
			      atoi(data[2].c_str()), // corner_y
			      atoi(data[3].c_str()), // length
			      atoi(data[4].c_str()), // size
			      atoi(data[5].c_str()), // orientation_x
			      atoi(data[6].c_str()), // orientation_y
			      atoi(data[7].c_str()), // color
			      data[8]); // text
		}
		else if(data[0] == "bar"){
			bar(atoi(data[1].c_str()), // corner_x
			    atoi(data[2].c_str()), // corner_y
			    atoi(data[3].c_str()), // length
			    atoi(data[4].c_str())); // color
		}
		else if(data[0] == "fullscreen"){
			fullscreen(atoi(data[1].c_str()), // corner_x
				   atoi(data[2].c_str()), // corner_y
				   atoi(data[3].c_str()), // size_x
				   atoi(data[4].c_str()), // size_y
				   atoi(data[5].c_str()), // color
				   data[6], // main_text
				   data[7]); // sub_text
		}
	}

	configfile.close();

	return 0;
}
