#pragma once
#include <Windows.h>
#include "unit.h"




class GraphicsView
{
public:
	GraphicsView(HWND hwnd, RECT& SCREEN);
	void BGDraw();
	void ObjectsDraw();
	void WNDraw();
private:
	HDC dc;
	HDC memDC;
	RECT& SCREEN;
	HBITMAP memBM;
	
	
	
	
};

