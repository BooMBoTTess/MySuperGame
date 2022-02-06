#pragma once
#include <windows.h>








class MainWindow {
public:

	int StartMainWindow();
	static LRESULT CALLBACK MainWindowProcedures(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp);
	
private:
	
	void ObjectsDraw(HDC dc);
	void WNDraw(HDC dc);
	void ObjectsMove(HDC dc);
	
};

