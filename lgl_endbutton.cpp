#include "lgl_endbutton.h"
#include "lgl_utils.h"
#include "lgl_shapes.h"

using namespace std;

int lgl_endbutton::draw(){
	lgl_utils::colors(era, color);
	
	lgl_shapes::rectangle(data.x1+(lgl_const::button_height/2 * orientation), data.x2+(lgl_const::button_height/2 * (orientation - 1)), data.y1, data.y2);
	
	if(orientation == 1) lgl_shapes::arc(data.x1+lgl_const::button_height/2, data.y1+lgl_const::button_height/2, lgl_const::button_height/2, 90, 270);
	if(orientation == 0) lgl_shapes::arc(data.x2-lgl_const::button_height/2, data.y1+lgl_const::button_height/2, lgl_const::button_height/2, -90, 90);
	
	lgl_utils::draw_text(data.x1+(lgl_const::button_height/2 * orientation)+5, data.y1+5, 3, scale, text);
	
	return 0;
}
