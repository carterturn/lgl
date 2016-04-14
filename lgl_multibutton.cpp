#include "lgl_multibutton.h"
#include "lgl_utils.h"
#include "lgl_shapes.h"

using namespace std;

int lgl_multibutton::setvalue(int value){
	this->value = value;
}

int lgl_multibutton::draw(){

	if(value < 0) value = 0;
	if(value > 99) value = 99;

	lgl_utils::colors(era, color);
	
	lgl_shapes::rectangle(data.x1, data.x1+10, data.y1, data.y2);
	lgl_shapes::rectangle(data.x1+54, data.x1+lgl_const::button_width, data.y1, data.y2+lgl_const::gap*extend);
	
	string number = lgl_utils::its(value);
	if(value < 10) number = "0"+number;
	
	lgl_utils::draw_text(data.x1+15, data.y1+lgl_const::gap, 2, scale, number, 0);

	return 0;
}
