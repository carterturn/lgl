#include "lgl_bar.h"
#include "lgl_shapes.h"
#include "lgl_utils.h"

using namespace std;

int lgl_bar::draw(){
	
	lgl_utils::colors(era, color);
	
	lgl_shapes::rectangle(data.x1, data.x2, data.y1, data.y2);
	
}
