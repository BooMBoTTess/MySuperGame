#pragma once
#include <windows.h>




class MainWindow {
public:

	int StartMainWindow();
	static LRESULT CALLBACK MainWindowProcedures(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp);

private:
	WNDCLASSA wcl;
	MSG msg;

	HWND hwnd;
	LPCWSTR ClassName = L"MainWindowClass";
	LPCSTR ClassName2 = "MainWindowClass";
};
