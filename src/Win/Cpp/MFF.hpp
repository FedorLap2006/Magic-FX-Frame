#pragma once
#include <windows.h>
#include <string>
#include <functional>
#include <stdarg.h>
#include <map>
#include <vector>
#include <iterator>
#include <stdint.h>
#include <cstdlib>
// #include <variant>
#include <cmath>

using namespace std;

// typedef unsigned int uint;
typedef LRESULT lres;
typedef UINT Uint;
typedef unsigned int uint;
typedef DWORD dword; 
typedef WPARAM wparam;
typedef LPARAM lparam;


int64_t lastw=0;


uint64_t GenID(){
	return rand() << lastw % 32 | (rand() | lastw & 10);
}

typedef function<lres(struct callback_msg*)> cbfunc;

enum {
	TW_BASE,
	TW_WIN
};

enum{
	WP_CHILD = WS_CHILD,
	WP_VISIBLE = WS_VISIBLE,
	WP_DECORATE,
	WP_FULLSCREEN,
	WP_DEFAULT = WP_VISIBLE
};

typedef union Prop {
	int iv;
	uint uiv;
	dword uliv;
	int64_t l64iv;
	uint64_t ul64iv;
	char *sv;
}Prop; 

typedef struct WHandle {
	map<string, Prop> props;
	map<Uint, cbfunc> cbfuncs;
	uint32_t win_params; // bit mask
	uint wtype; // widget type(window,label,button,...)
	uint64_t wid;
	HWND hLink;
	HINSTANCE hI;
	COORD ppos;
	int w;
	int h;
	struct WHandle *parent;
	vector<struct WHandle> childs;
}WHandle;


enum{
	CB_OPEN,
	CB_CLOSE,
	CB_FOCUS
};



typedef struct callback_msg {
	WHandle *widget;
	cbfunc cbfunc;
	uint msg;
	/*wparam wp;
	lparam lp;*/
	void* params[2];
	int argc;
}callback_msg;

class Widget {
protected:
	WHandle hl;
public:
	// Widget(Widget *parent);
	Widget(Widget *parent,uint wt);
	// Widget(WHandle *parent); // id for widget - auto rand generate or increment generate
	Widget(WHandle *parent,uint wt); // id for widget - auto rand generate or increment generate
	Widget(WHandle *parent,uint16_t wp,uint wt);
	Widget(Widget *parent,uint16_t wp,uint wt);
	~Widget() = default;
	virtual WHandle* GetInstance();
	virtual bool Add(Widget* el);
	virtual bool Add(WHandle* el);
};
