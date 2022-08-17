#include<windows.h>
LRESULT CALLBACK WindowProcedure(HWND,UINT,WPARAM,LPARAM);
int WINAPI WinMain(HINSTANCE curinst, HINSTANCE previnst, LPSTR args, int ncmdshow)
{
	WNDCLASSW wc={0};
	wc.hbrBackground=(HBRUSH)COLOR_WINDOW;
	wc.hCursor=LoadCursor(NULL,IDC_ARROW);
	wc.hInstance=curinst;
	wc.lpszClassName=L"myWindowClass";
	wc.lpfnWndProc=WindowProcedure;
	if(!RegisterClassW(&wc))
	{
		MessageBox(NULL,"Window Registration Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}
	CreateWindowW(L"myWindowClass",L"Notepad Window",WS_OVERLAPPEDWINDOW|WS_VISIBLE,CW_USEDEFAULT,CW_USEDEFAULT,500,500,NULL,NULL,curinst,NULL);
	MSG msg={0};
	while(GetMessage(&msg,NULL,NULL,NULL))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
}
LRESULT CALLBACK WindowProcedure(HWND hwnd,UINT msg1,WPARAM wp,LPARAM lp)
{
	switch(msg1)
	{
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		default:
			return DefWindowProcW(hwnd,msg1,wp,lp);
	}
}
