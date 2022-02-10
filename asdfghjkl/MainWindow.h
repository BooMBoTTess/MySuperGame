#pragma once
#include <windows.h>




class MainWindow {
public:

	int StartMainWindow();
	

private:
	WNDCLASSA wcl;
	static LRESULT CALLBACK MainWindowProcedures(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp);
	HANDLE GRAPHThread;
	HANDLE MainThread;
	
	static DWORD WINAPI Graph(LPVOID lp);
	

	LPCWSTR ClassName = L"MainWindowClass";
	LPCSTR ClassName2 = "MainWindowClass";

	
};
