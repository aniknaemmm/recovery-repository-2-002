// Win32Lesson1.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "Win32Lesson1.h"

#define MAX_LOADSTRING 100




// Global Variables:

double init = 0;
int useZomm = 0;
std::vector<Line> Trapecial{
	Line(   0,   0, 400,   0),
	Line(   0,   0,   0, 400),
	Line( 400, 400, 400,   0),
	Line( 400, 400,   0, 400)
};

std::vector<Cube> cube{
	Cube({ 100, 100,   0 }, { 100, 400,   0 }),
	Cube({ 100, 100,   0 }, { 400, 100,   0 }),
	Cube({ 400, 100,   0 }, { 400, 400,   0 }),
	Cube({ 400, 400,   0 }, { 100, 400,   0 }),//first sq
	Cube({ 100, 100, 200 }, { 100, 400, 200 }),
	Cube({ 100, 100, 200 }, { 400, 100, 200 }),
	Cube({ 400, 100, 200 }, { 400, 400, 200 }),
	Cube({ 400, 400, 200 }, { 100, 400, 200 }),//last sq
	Cube({ 100, 400,   0 }, { 100, 400, 200 }),
	Cube({ 100, 100,   0 }, { 100, 100, 200 }),
	Cube({ 400, 100,   0 }, { 400, 100, 200 }),
	Cube({ 400, 400,   0 }, { 400, 400, 200 })
	 };

Matrix<double> matZ = Matrix<double>::rotateZ(0.01);
Matrix<double> matY = Matrix<double>::rotateY(0.01);
Matrix<double> matX = Matrix<double>::rotateX(0.01);
Matrix<double> matZoomDec = Matrix<double>::zoom(0.99);
Matrix<double> matZoomDecPol = Matrix<double>::zoom(0.5);
Matrix<double> matZoomInc = Matrix<double>::zoom(1.01);
Matrix<double> reflection = Matrix<double>::reflection(0.01);


HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];			// the main window class name

// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
 {
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

 	// TODO: Place code here.
	MSG msg;
	HACCEL hAccelTable;

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_WIN32LESSON1, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WIN32LESSON1));

	// Main message loop:
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
//  COMMENTS:
//
//    This function and its usage are only necessary if you want this code
//    to be compatible with Win32 systems prior to the 'RegisterClassEx'
//    function that was added to Windows 95. It is important to call this function
//    so that the application will get 'well formed' small icons associated
//    with it.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WIN32LESSON1));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_WIN32LESSON1);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // Store instance handle in our global variable

   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   // ��������� ��� � 50 ���������� 
   SetTimer(hWnd, 0, 50, 0);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;

	switch (message)
	{
	case WM_TIMER :
		//initAlpha += 0.01; // �������� �������� ������/����
				InvalidateRgn(hWnd, 0, 1);
		RedrawWindow(hWnd, 0, 0, RDW_ERASE);
		break;
	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// Parse the menu selections:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;

	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		HPEN hPenOld;
		Line::hdc = hdc;
		Cube::hdc = hdc;
		// Draw a red line
		HPEN hLinePen;
		COLORREF qLineColor;
		qLineColor = RGB(255, 0, 0);
		hLinePen = CreatePen(PS_SOLID, 7, qLineColor);
		hPenOld = (HPEN)SelectObject(hdc, hLinePen);
		{
			/*int x = 300;
			int y = 300;
			int size = 200;
			double alpha = initAlpha;

			MoveToEx(hdc, x + size* sin(alpha), y - size* cos(alpha), NULL);


			int rays = 17;
			int skip = 9;

			for (int i = 0; i <= rays*skip; i++) {
				alpha += (360.0 / rays*skip) / 180.0*3.1415;
				LineTo(hdc, x + size* sin(alpha), y - size* cos(alpha));

			}*/
			auto matZoom=matZoomDec;
			int size = 0;
			if (useZomm==0)
			{
				matZoom = matZoomDecPol;
				useZomm++;
			}
			else if (init < 50)
			{
				matZoom = matZoomInc;
				init++;
			}
			else if ((init >= 50) && (init < 100))
			{
				matZoom = matZoomDec;
				init++;
			}
			else
				init = 0;

			for (auto L : Trapecial){
			//	L.Draw();
			}
			for (auto it = cube.begin(); it != cube.end(); ++it)
			{
				(*it) *= matX;
				(*it) *= matY;
				//(*it) *= matZ;
				(*it) *= matZoom;
				//(*it) *= reflection;
			}
			for (auto F : cube){
				F.show();
				//system("pause");
			}
		}
		

		SelectObject(hdc, hPenOld);
		DeleteObject(hLinePen);

		// Draw a blue ellipse
		HPEN hEllipsePen;
		COLORREF qEllipseColor;
		qEllipseColor = RGB(0, 0, 255);
		hEllipsePen = CreatePen(PS_SOLID, 3, qEllipseColor);
		hPenOld = (HPEN)SelectObject(hdc, hEllipsePen);

		//Arc(hdc, 100, 100, 500, 250, 0, 0, 0, 0);

		SelectObject(hdc, hPenOld);
		DeleteObject(hEllipsePen);

		// TODO: Add any drawing code here...
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}

