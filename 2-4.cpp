//#include <Windows.h>
//#include <tchar.h>
//#include <time.h>
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
//	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
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
//	srand(time(NULL));
//	static TCHAR lpOut[80];
//	static int x = (rand() % 801);
//	static int y = (rand() % 601);
//	static int r = (rand() % 256);
//	static int g = (rand() % 256);
//	static int b = (rand() % 256);
//	static int count = 0;
//
//	
//	switch (iMessage) {
//	case WM_CHAR:
//		hDC = GetDC(hWnd);
//		
//		if (wParam == VK_BACK) {
//			if (count > 0) {
//				count--;
//			}
//		}
//		else if (wParam == VK_RETURN) {
//			y = y + 20;
//		}
//		else if (wParam == VK_ESCAPE) {
//			PostQuitMessage(0);
//			return 0;
//		}
//		else {
//			lpOut[count++] = wParam;
//		}
//		lpOut[count] = '\0';
//		InvalidateRect(hWnd, NULL, true);
//		ReleaseDC(hWnd, hDC);
//		break;
//
//	case WM_PAINT:
//		hDC = BeginPaint(hWnd, &ps);
//		SetTextColor(hDC, RGB(r, g, b));
//		TextOut(hDC, x, y, lpOut, lstrlen(lpOut));
//		
//		EndPaint(hWnd, &ps);
//		break;
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		return 0;
//	}
//	return (DefWindowProc(hWnd, iMessage, wParam, lParam));
//}