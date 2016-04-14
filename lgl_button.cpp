#include "lgl_button.h"
#include "lgl_shapes.h"
#include "lgl_utils.h"

using namespace std;

int lgl_button::draw(){
	lgl_utils::colors(era, color);
	
	lgl_shapes::rectangle(data.x1, data.x2, data.y1, data.y2);
	
	lgl_utils::draw_text(data.x1+5, data.y1+5, 3, scale, text);
	
	return 0;
}
