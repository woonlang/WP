//#include <Windows.h>
//#include <tchar.h>
//
//HINSTANCE g_hInst;
//LPCTSTR lpszClass = L"Window Class Name";
//LPCTSTR lpszWindowName = L"Window Programming Lab";
//
//LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
//
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow)
//{
//	HWND hWnd;
//	MSG Message;
//	WNDCLASSEX WndClass;
//	g_hInst = hInstance;
//
//	WndClass.cbSize = sizeof(WndClass);
//	WndClass.style = CS_HREDRAW | CS_VREDRAW;
//	WndClass.lpfnWndProc = (WNDPROC)WndProc;
//	WndClass.cbClsExtra = 0;
//	WndClass.cbWndExtra = 0;
//	WndClass.hInstance = hInstance;
//	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
//	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
//	WndClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
//	WndClass.lpszMenuName = NULL;
//	WndClass.lpszClassName = lpszClass;
//	WndClass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
//	RegisterClassEx(&WndClass);
//
//	hWnd = CreateWindow(lpszClass, lpszWindowName, WS_OVERLAPPEDWINDOW, 0, 0, 800, 600, NULL, (HMENU)NULL, hInstance, NULL);
//	ShowWindow(hWnd, nCmdShow);
//	UpdateWindow(hWnd);
//
//	while (GetMessage(&Message, 0, 0, 0)) {
//		TranslateMessage(&Message);
//		DispatchMessage(&Message);
//	}
//	return Message.wParam;
//
//}
//
//LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
//{
//	PAINTSTRUCT ps;
//	HDC hDC;
//	RECT rect = { 0,0,200,300 };
//	TCHAR lpOut[100];
//	int x = 2;
//	switch (iMessage) {
//	case WM_PAINT:
//		hDC = BeginPaint(hWnd, &ps);
//
//		for (int i = 2; i < 10; i++) {
//			for (int j = 1; j < 10; j++) {
//					wsprintf(lpOut, L"%d x %d = %d", i, j, i * j);
//					DrawText(hDC, lpOut, lstrlen(lpOut), &rect, DT_CENTER | DT_VCENTER);
//					rect.top += 20;
//			}
//			rect.top = 0;
//			rect.right += 200;
//			
//		}
//
//		EndPaint(hWnd, &ps);
//		break;
//	case WM_TIMER:
//		hDC = GetDC(hWnd);
//		ReleaseDC(hWnd, hDC);
//		break;
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		return 0;
//	}
//	return (DefWindowProc(hWnd, iMessage, wParam, lParam));
//}