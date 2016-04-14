#include "lgl_abstract_button.h"

bool lgl_abstract_button::clicked(int click_x, int click_y){
	if(click_x < data.x2 && click_x > data.x1 && click_y < data.y2 && click_y > data.y1) return true;
	else return false;
}
