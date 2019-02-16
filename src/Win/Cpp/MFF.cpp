#include "MFF.hpp"

// Widget::Widget(Widget *parent){

// }
Widget::Widget(Widget *parent,uint wt){
	if (parent == NULL) {
		// do stuff
	}
	this->hl.wtype = wt;
	this->hl.wid = GenID();
	this->hl.parent = parent->GetInstance();
	this->hl.win_params = WP_DEFAULT;
}
// Widget::Widget(WHandle *parent) {

// }

Widget::Widget(WHandle *parent,uint wt) {
	if (parent == NULL) {
		// do stuff
	}
	this->hl.wtype = wt;
	this->hl.wid = GenID();
	this->hl.parent = parent;
	this->hl.win_params = WP_DEFAULT;
}

Widget::Widget(WHandle *parent,uint16_t wp,uint wt) : Widget(parent,wt){
	this->hl.win_params = wp;
}
Widget::Widget(Widget *parent,uint16_t wp,uint wt) : Widget(parent,wp){
	this->hl.win_params = wp;
}
// this->hl.win_params = wp;

WHandle* Widget::GetInstance() {
	/*return nullptr;*/
	return &this->hl;
}

bool Widget::Add(Widget * el)
{
	return false;
}

bool Widget::Add(WHandle * el)
{
	return false;
}
