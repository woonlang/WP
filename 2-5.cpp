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
//	static int count = 0;
//	int r = rand() % 256;
//	int g = rand() % 256;
//	int b = rand() % 256;
//	static int x = 400;
//	static int y1 = 300;
//	static int y2 = 300;
//
//	switch (iMessage) {
//	case WM_CHAR:
//		hDC = GetDC(hWnd);
//		
//		if (wParam == VK_RETURN) {
//			count = 0;
//			x -= 5;
//			y1 += 20;
//			y2 -= 20;
//		}
//		else {
//			lpOut[count++] = wParam;
//		}
//		lpOut[count] = '\0';
//		SetTextColor(hDC, RGB(r, g, b));
//		TextOut(hDC, x, y1, lpOut, lstrlen(lpOut));
//		TextOut(hDC, x, y2, lpOut, lstrlen(lpOut));
//		ReleaseDC(hWnd, hDC);
//		break;
//
//	case WM_KEYDOWN:
//		hDC = GetDC(hWnd);
//		if (wParam == VK_ESCAPE) {
//			PostQuitMessage(0);
//			return 0;
//		}
//		else if (wParam == VK_F1) { // 화면 초기화 및 다시 출력할 수 있게
//			InvalidateRgn(hWnd, NULL, true);
//			count = 0;
//			x = 400;
//			y1 = 300;
//			y2 = 300;
//		}
//
//		ReleaseDC(hWnd, hDC);
//		break;
//
//	case WM_PAINT:
//		hDC = BeginPaint(hWnd, &ps);
//		
//
//		EndPaint(hWnd, &ps);
//		break;
//
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		return 0;
//	}
//	return (DefWindowProc(hWnd, iMessage, wParam, lParam));
//}