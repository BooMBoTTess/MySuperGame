#pragma once

#include <windows.h>


struct TPoint {	float x, y;};

TPoint point(float x, float y);

LRESULT MainWindowProcedures(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp);


class MainWindow {
public:

	int StartMainWindow();


private:
	

	void WinDraw(HDC dc);
	
};

