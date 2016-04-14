#include "lgl_endmultibutton.h"
#include "lgl_utils.h"
#include "lgl_shapes.h"

using namespace std;

int lgl_endmultibutton::draw(){

	if(value < 0) value = 0;
	if(value > 999) value = 999;

	lgl_utils::colors(era, color);
	
	lgl_shapes::rectangle(data.x1, data.x1+10, data.y1, data.y2);
	lgl_shapes::rectangle(data.x1+54, data.x2-lgl_const::button_height/2, data.y1, data.y2);
	lgl_shapes::arc(data.x1+72, data.y1+lgl_const::button_height/2, lgl_const::button_height/2, -90, 90);
		
	string number = lgl_utils::its(value);
	if(value < 10) number = "0"+number;
	
	lgl_utils::draw_text(data.x1+15, data.y1+5, 2, scale, number, 0);

	return 0;
}
