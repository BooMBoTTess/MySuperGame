#pragma once
#include <windows.h>








class MainWindow {
public:

	int StartMainWindow();
	static LRESULT CALLBACK MainWindowProcedures(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp);
private:
	

	void WinDraw(HDC dc);
	
};

