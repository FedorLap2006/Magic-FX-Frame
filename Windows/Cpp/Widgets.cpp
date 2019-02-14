#include "Widgets.hpp"

Window::Window(WHandle * parent) : Widget(parent,TW_WIN){
}

Window::Window(Widget * parent) : Widget(parent,TW_WIN) {

}

Window::Window(Window * parent) : Widget(parent,TW_WIN) {
}
