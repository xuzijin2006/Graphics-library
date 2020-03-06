#include "window.h"
#include <windows.h>
#include <tchar.h>
#include <iostream>
using namespace std;

LRESULT CALLBACK winProc(HWND, UINT, WPARAM, LPARAM);

LRESULT CALLBACK winProc (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    window *t;
    t = (window*)GetWindowLong(hwnd,GWL_USERDATA);
    switch (message)                  /* handle the messages */
    {
        case WM_DESTROY:
            PostQuitMessage (0);       /* send a WM_QUIT to the message queue */
            return 0;
        case WM_KEYDOWN:
            t->key=wParam;
            return 0;
        case WM_KEYUP:
            t->key='\0';
            return 0;
        case WM_LBUTTONDOWN:
            t->lb=true;
           return 0;
        case WM_MBUTTONDOWN:
            t->mb=true;
            return 0;
        case WM_RBUTTONDOWN:
            t->rb=true;
            return 0;
        case WM_LBUTTONUP:
            t->lb=false;
            return 0;
        case WM_MBUTTONUP:
            t->mb=false;
            return 0;
        case WM_RBUTTONUP:
            t->rb=false;
            return 0;
        case WM_NULL:
            return 0;
        default:
            break;
    }

    return DefWindowProc (hwnd, message, wParam, lParam);
}
window::window()
{
    wincl.hInstance = GetModuleHandle(NULL) ;
    wincl.lpszClassName = _T("WindowsApp");
    wincl.lpfnWndProc = winProc;
    wincl.style = CS_DBLCLKS;
    wincl.cbSize = sizeof (WNDCLASSEX);
    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;
    wincl.cbClsExtra = 0;
    wincl.cbWndExtra = 0;
    wincl.hbrBackground = (HBRUSH) COLOR_3DDKSHADOW;
    RegisterClassEx (&wincl);
    hwnd = CreateWindowEx (
           0,
           _T("WindowsApp"),         /* Classname */
           _T("NewWindow"),       /* Title Text */
           WS_OVERLAPPEDWINDOW, /* default window */
           CW_USEDEFAULT,       /* Windows decides the position */
           CW_USEDEFAULT,       /* where the window ends up on the screen */
           544,                 /* The programs width */
           375,                 /* and height in pixels */
           HWND_DESKTOP,        /* The window is a child-window to desktop */
           NULL,                /* No menu */
           GetModuleHandle(NULL),       /* Program Instance handler */
           NULL        /* No Window Creation data */
           );
           hdc=GetDC(hwnd);
    bitm=CreateCompatibleBitmap(hdc,544,375);
    SelectObject(hdc,bitm);
    height=544;
    width=255;
    title="NewWindow";
    SetWindowLong(hwnd,GWL_USERDATA,LONG(&(*this)));
    cout<<LONG(&(*this))<<endl;

}


window::window(char* _title,int _width,int _height)
{
    wincl.hInstance = GetModuleHandle(NULL) ;
    wincl.lpszClassName = _T("WindowsApp");
    wincl.lpfnWndProc = winProc;
    wincl.style = CS_DBLCLKS;
    wincl.cbSize = sizeof (WNDCLASSEX);
    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;
    wincl.cbClsExtra = 0;
    wincl.cbWndExtra = 0;
    wincl.hbrBackground = (HBRUSH) COLOR_3DDKSHADOW;
    RegisterClassEx (&wincl);
    hwnd = CreateWindowEx (
           0,
           _T("WindowsApp"),         /* Classname */
           _T(_title),       /* Title Text */
           WS_OVERLAPPEDWINDOW, /* default window */
           CW_USEDEFAULT,       /* Windows decides the position */
           CW_USEDEFAULT,       /* where the window ends up on the screen */
           _width,                 /* The programs width */
           _height,                 /* and height in pixels */
           HWND_DESKTOP,        /* The window is a child-window to desktop */
           NULL,                /* No menu */
           GetModuleHandle(NULL),       /* Program Instance handler */
           NULL                 /* No Window Creation data */
           );
           hdc=GetDC(hwnd);
    bitm=CreateCompatibleBitmap(hdc,_width,_height);
SelectObject(hdc,bitm);
height=_height;
width=_width;
title=_title;
    SetWindowLong(hwnd,GWL_USERDATA,LONG(&(*this)));
}

window::window(string _title,int _width,int _height)
{
    wincl.hInstance = GetModuleHandle(NULL) ;
    wincl.lpszClassName = _T("WindowsApp");
    wincl.lpfnWndProc = winProc;
    wincl.style = CS_DBLCLKS;
    wincl.cbSize = sizeof (WNDCLASSEX);
    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;
    wincl.cbClsExtra = 0;
    wincl.cbWndExtra = 0;
    wincl.hbrBackground = (HBRUSH) COLOR_3DDKSHADOW;
    RegisterClassEx (&wincl);
    hwnd = CreateWindowEx (
           0,
           _T("WindowsApp"),         /* Classname */
           _T(_title.c_str()),       /* Title Text */
           WS_OVERLAPPEDWINDOW, /* default window */
           CW_USEDEFAULT,       /* Windows decides the position */
           CW_USEDEFAULT,       /* where the window ends up on the screen */
           _width,                 /* The programs width */
           _height,                 /* and height in pixels */
           HWND_DESKTOP,        /* The window is a child-window to desktop */
           NULL,                /* No menu */
           GetModuleHandle(NULL),       /* Program Instance handler */
           NULL                 /* No Window Creation data */
           );
           hdc=GetDC(hwnd);
    bitm=CreateCompatibleBitmap(hdc,544,375);
SelectObject(hdc,bitm);
height=_height;
width=_width;
title=_title;
    SetWindowLong(hwnd,GWL_USERDATA,LONG(&(*this)));
}

window::window(string _title,int _width,int _height,int x,int y,HWND father)
{
    wincl.hInstance = GetModuleHandle(NULL) ;
    wincl.lpszClassName = _T("WindowsApp");
    wincl.lpfnWndProc = winProc;
    wincl.style = CS_DBLCLKS;
    wincl.cbSize = sizeof (WNDCLASSEX);
    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;
    wincl.cbClsExtra = 0;
    wincl.cbWndExtra = 0;
    wincl.hbrBackground = (HBRUSH) COLOR_3DDKSHADOW;
    RegisterClassEx (&wincl);
    hwnd = CreateWindowEx (
           0,
           _T("WindowsApp"),         /* Classname */
           _T(_title.c_str()),       /* Title Text */
           WS_OVERLAPPEDWINDOW|WS_CHILD, /* default window */
           x,       /* Windows decides the position */
           y,       /* where the window ends up on the screen */
           _width,                 /* The programs width */
           _height,                 /* and height in pixels */
           father,        /* The window is a child-window to desktop */
           NULL,                /* No menu */
           GetModuleHandle(NULL),       /* Program Instance handler */
           NULL                 /* No Window Creation data */
           );
           hdc=GetDC(hwnd);
    bitm=CreateCompatibleBitmap(hdc,544,375);
SelectObject(hdc,bitm);
height=_height;
width=_width;
title=_title;
    SetWindowLong(hwnd,GWL_USERDATA,LONG(&(*this)));
}

void window::show(){
    ShowWindow (hwnd, 10);

}
bool window::update(){


    if (PeekMessage(&messages, NULL, 0, 0, PM_REMOVE))
		{
			// test if this is a quit msg
			if (messages.message == WM_QUIT)
				return false;

			// translate any accelerator keys
			TranslateMessage(&messages);

			// send the message to the window proc
			DispatchMessage(&messages);
			return true;
		}
		return true;

}
window::~window(){
    //dtor
}



void window::drawPixel(int x,int y,color col){
    SetPixel(hdc,x,y,col);
}
void window::drawLine(int x1,int y1,int x2,int y2){
    MoveToEx(hdc,x1,y1,NULL);
    LineTo(hdc,x2,y2);
}
void window::setPen(int w,color col){
    pen=CreatePen(PS_SOLID,w,col);
    SelectObject(hdc,pen);
}
void window::setBrush(color col){
    brush=CreateSolidBrush(col);
    SelectObject(hdc,brush);
}

void window::setText(color col){
    SetTextColor(hdc,col);
}

void window::drawEllipse(int x1,int y1,int x2,int y2){
    Ellipse(hdc,x1,y1,x2,y2);
}

void window::drawRectangle(int x1,int y1,int x2,int y2){
    Rectangle(hdc,x1,y1,x2,y2);
}

void window::drawRoundRect(int x1,int y1,int x2,int y2,int arcSize){
    RoundRect(hdc,x1,y1,x2,y2,arcSize,arcSize);

}


void window::drawPolygon(point *pointss,int num){
    Polygon(hdc,pointss,num);
}

void window::drawPolyline(point *points,int num){
    Polyline(hdc,points,num);
}

void window::drawText(int x,int y,const char *str){
    TextOut(hdc,x,y,str,strlen(str));
}

void window::drawText(int x,int y,string str){
    TextOut(hdc,x,y,str.c_str(),str.length());
}

point XY(int x,int y){
    point t;
    t.x=x;
    t.y=y;
    return t;
}
/*
char window::getKey(){
    return key;
}

bool window::leftMouseDown(){
    return lb;
}
bool window::mediumMouseDown(){
    return mb;
}
bool window::rightMouseDown(){
    return rb;
}*/

void window::clear(){
	RECT rect;

	SetRect(&rect, 0, 0, width, height);
	setBrush(WHITE);
	FillRect(hdc, &rect, brush);
	drawRectangle(0,0,width,height);
}

void window::erase(int x1,int y1,int x2,int y2){
	RECT rect;
	SetRect(&rect, x1, x2, y1, y2);
	brush = CreateSolidBrush(WHITE);
	FillRect(hdc, &rect, brush);
}

void window::fillRect(int x1,int y1,int x2,int y2){
    RECT rect;
	SetRect(&rect, x1, x2, y1, y2);
	FillRect(hdc, &rect, brush);
}

void window::drawBitmap(int x,int y,char* address){
    HDC temp;
    temp  = CreateCompatibleDC(hdc);
    HBITMAP hbmp;
    BITMAP bmp;
    hbmp = (HBITMAP)LoadImage(NULL, address, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE|LR_CREATEDIBSECTION);
    GetObject(hbmp, sizeof(BITMAP), &bmp);
    SelectObject(temp, hbmp);
    BitBlt(hdc, x, y, bmp.bmWidth, bmp.bmHeight, temp, 0, 0, SRCCOPY);
}

void window::drawBitmap(int x,int y,string address){
	HDC temp;
    temp  = CreateCompatibleDC(hdc);
    HBITMAP hbmp;
    BITMAP bmp;
    hbmp = (HBITMAP)LoadImage(NULL, address.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE|LR_CREATEDIBSECTION);
    GetObject(hbmp, sizeof(BITMAP), &bmp);
    SelectObject(temp, hbmp);
    BitBlt(hdc, x, y, bmp.bmWidth, bmp.bmHeight, temp, 0, 0, SRCCOPY);
}

color window::getPixelColor(int x,int y){
    return GetPixel(hdc,x,y);
}

int window::getWidth(){
	return width;
}

int window::getHeight(){
	return height;
}

string window::getTitle(){
	return title;
}

void window::hide(){
	ShowWindow(hwnd, SW_HIDE);
}

point window::getWindowPos(){
	RECT rect;
	GetWindowRect(hwnd,&rect);
	return XY(rect.left,rect.top);
}

point window::getMousePos(){
	point p,pp;
	pp=getWindowPos();
	GetCursorPos(&p);
	p.x-=pp.x;
	p.y-=pp.y;
	return p;
}

void window::getMousePos(int &x,int &y){
	point p,pp;
	GetCursorPos(&p);
	pp=getWindowPos();
	p.x-=pp.x;
	p.y-=pp.y;
	x=p.x;
	y=p.y;
}

void window::setMousePos(point p){
    point pp;
	pp=getWindowPos();
	GetCursorPos(&p);
	p.x+=pp.x;
	p.y+=pp.y;
	SetCursorPos(p.x,p.y);
}

void window::setMousePos(int x,int y){
    point p;
	p=getWindowPos();
	SetCursorPos(x+p.x,y+p.y);
}

void window::resize(int _width,int _height){
	point p=getWindowPos();
	MoveWindow(hwnd,p.x,p.y,_width,_height,false);
}

void window::maxSize()
{
	ShowWindow(hwnd,SW_MAXIMIZE);
}
void window::fullScreen()
{
    int cx = GetSystemMetrics(SM_CXSCREEN);
    int cy = GetSystemMetrics(SM_CYSCREEN);
    LONG l_WinStyle = GetWindowLong(hwnd,GWL_STYLE);
    SetWindowLong(hwnd,GWL_STYLE,(l_WinStyle | WS_POPUP | WS_MAXIMIZE) & ~WS_CAPTION & ~WS_THICKFRAME & ~WS_BORDER);
    SetWindowPos(hwnd, HWND_TOP, 0, 0, cx, cy, 0);
}
void window::normalScreen()
{
	LONG l_WinStyle = GetWindowLong(hwnd,GWL_STYLE);
	SetWindowLong(hwnd, GWL_STYLE,(l_WinStyle | WS_POPUP | WS_MAXIMIZE) | WS_CAPTION | WS_THICKFRAME | WS_BORDER);
}
int window::clickingButton(){
    int t=0;
    if(lb)t+=1;
    if(mb)t+=2;
    if(rb)t+=4;
    return t;
}
HWND window::getHwnd(){
    return hwnd;
}

void window::setHwnd(HWND hWnd){
    hwnd=hWnd;
}
