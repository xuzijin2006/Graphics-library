#ifndef WINDOW_H
#define WINDOW_H
#include<windows.h>
#include<string>
#include "def.h"
using namespace std;
class window
{
    public:
        window();
        void drawPixel(int x,int y,color col);
        window(char* _title,int width,int height);
        window(string _title,int _width,int _height);
        bool update();
        virtual ~window();
        void show();
        bool isQuiting();
        void setText(color col);
        void drawLine(int x1,int y1,int x2,int y2);
        void drawEllipse(int x1,int y1,int x2,int y2);
        void drawRectangle(int x1,int y1,int x2,int y2);
        void drawRoundRect(int x1,int y1,int x2,int y2,int arcSize);
        void drawPolygon(point *points,int num);
        void drawPolyline(point *points,int num);
        void drawText(int x,int y,const char *str);
        void drawText(int x,int y,string str);
        char getKey();
        bool leftMouseDown();
        bool mediumMouseDown();
        bool rightMouseDown();
        void clear();
        void erase(int x1,int y1,int x2,int y2);
        void fillRect(int x1,int y1,int x2,int y2);
        void drawBitmap(int x,int y,char* address);
        void drawBitmap(int x,int y,string address);
        color getPixelColor(int x,int y);
        int getWidth();
        int getHeight();
        string getTitle();
        point getWindowPos();
        void hide();
        void resize(int _width,int _height);
        void setPen(int w,color col);
        void setBrush(color col);
    protected:
		
    private:
        int width,height;
        char key;
        HBITMAP bitm;
        HPEN pen;
        HBRUSH brush;
	    string title;
	    HWND hwnd;
   	 	MSG messages;
		WNDCLASSEX wincl;
    	HDC hdc;

};
extern point XY(int x,int y);
int getDesktopWidth();
int getDesktopHeight();
point getMousePos();
void getMousePos(int &x,int &y);
void setMousePos(point p);
void setMousePos(int x,int y);
#endif // WINDOW_H
