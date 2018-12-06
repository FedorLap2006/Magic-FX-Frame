#include <windows.h>
#include <string>
#include <functional>
#include <stdarg.h>
#include <map>
using namespace std;

#define cbmsg __callbackmsg__

typedef LRESULT lres;
typedef UINT Uint;
typedef unsigned int uint;
typedef DWORD dword;

typedef struct {
    HWND hL;
    HINSTANCE hI;
    string message;
    string *args; 
    int argc;
}__callbackmsg__;

#define setOn(name) setOn##name(function<void(__callbackmsg__)> cfunc);

class Widget{
protected:
    HWND hL;
    HINSTANCE hI;
    COORD c;
    HWND parent;
    DWORD Id;
    function<lres(__callbackmsg__)> func;
public:
    virtual void setOn(Action);
    virtual lres operator()(cbmsg funcparams);
};

class Button : public Widget{
public:
	void setOn(Action);
	void setOn(Clicked);
	
};

class Application{
public:
    void launch(int carg,char ** argv);
};
