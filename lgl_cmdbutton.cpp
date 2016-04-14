#include "lgl_cmdbutton.h"
#include "lgl_utils.h"
#include "lgl_shapes.h"

using namespace std;

int lgl_cmdbutton::draw(){
	lgl_utils::colors(era, color);
	
	lgl_shapes::rectangle(data.x1+lgl_const::button_height/2, data.x2-lgl_const::button_height/2, data.y1, data.y2);
	lgl_shapes::arc(data.x1+lgl_const::button_height/2, data.y1+lgl_const::button_height/2, lgl_const::button_height/2, 90, 270);
	lgl_shapes::arc(data.x2-lgl_const::button_height/2, data.y1+lgl_const::button_height/2, lgl_const::button_height/2, -90, 90);
	
	lgl_utils::draw_text(data.x1+lgl_const::button_height/2+5, data.y1+5, 3, scale, text);
	
	return 0;
}
