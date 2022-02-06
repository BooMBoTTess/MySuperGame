#pragma once
#include <windows.h>





LRESULT MainWindowProcedures(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp);


class MainWindow {
public:

	int StartMainWindow();


private:
	

	void WinDraw(HDC dc);
	
};

