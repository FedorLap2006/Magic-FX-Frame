#include "MFF.hpp"

class Window : public Widget {
public:
	Window(WHandle *parent);
	Window(Widget *parent);
	Window(Window *parent);
};
