#define UNICODE
#include <windows.h>
#include <gdiplus.h>
#include <vector>
#include <random>
#include <ctime>
#include <sstream>
#pragma comment(lib,"Gdiplus.lib")
using namespace Gdiplus;
using namespace std;
//---------------------------------
//source


struct PP
{
	PP(HWND _id_, int _mina) : id(_id_), mina(_mina), numbMin(0), status(0) {};
	HWND id;
	int mina;
	int numbMin;
	int status;
};


vector<vector<PP>> filed;

void showAllMin()
{

	for (auto it = filed.begin(); it != filed.end(); it++){
		for (auto itit = it->begin(); itit != it->end(); itit++)
		{
			if (itit->mina == 1){
				SetWindowText(itit->id, L"mina");

			}
		}
	}

}

int chwkNumbMin(HWND hWnd)
{
	int num = 0;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (hWnd == filed[i][j].id)
			{
				//i =y
				// j =x

				if (i != 0 && filed[i - 1][j].mina == 1) num++;
				if (i != 0 && j != 0 && filed[i - 1][j - 1].mina == 1)num++;
				if (i != 0 && j != 9 && filed[i - 1][j + 1].mina == 1)num++;

				if (i != 9 && filed[i + 1][j].mina == 1) num++;
				if (i != 9 && j != 0 && filed[i + 1][j - 1].mina == 1)num++;
				if (i != 9 && j != 9 && filed[i + 1][j + 1].mina == 1)num++;

				if (j != 0 && filed[i][j - 1].mina == 1)num++;
				if (j != 9 && filed[i][j + 1].mina == 1)num++;

			}
		}

	}
	return num;
}

//-------------------------------
void generateFiled(HWND hWnd, HINSTANCE hInstance);

void generateFiled(HWND hWnd, HINSTANCE hInstance)
{
	int x = 0;
	for (int j = 0; j < 10; j++){
		vector<PP> tempV1;
		for (int i = 0; i < 10; i++)
		{
			HWND temp = CreateWindow(
				L"BUTTON",  // Predefined class; Unicode assumed 
				L"",      // Button text 
				WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
				0 + (i * 50),         // x position 
				x,         // y position 
				50,        // Button width
				50,        // Button height
				hWnd,     // Parent window
				(HMENU)0,       // button id (h - menu)
				hInstance,
				NULL);

			tempV1.push_back(PP(temp, 1==rand()%4?1:0));//new function logik 
		}
		x += 50;
		filed.push_back(tempV1);
	}



}

int win = 0;
HWND score;
HWND take_money;
VOID OnPaint(HDC hdc);
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HBITMAP hBitmap;
INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, PSTR, INT iCmdShow)
{
	srand(time(NULL));
	HWND                hWnd;
	MSG                 msg;
	WNDCLASS            wndClass;
	GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR           gdiplusToken;
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);
	wndClass.style = CS_HREDRAW | CS_VREDRAW;
	wndClass.lpfnWndProc = WndProc;
	wndClass.cbClsExtra = 0;
	wndClass.cbWndExtra = 0;
	wndClass.hInstance = hInstance;
	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndClass.lpszMenuName = NULL;
	wndClass.lpszClassName = TEXT("EllipseExample");

	RegisterClass(&wndClass);

	hWnd = CreateWindowEx(
		0,		// расширенный стиль окна
		TEXT("EllipseExample"), 	//им€ класса окна
		TEXT(" аркас Windows приложени€"), // заголовок окна
		WS_OVERLAPPEDWINDOW,				// стиль окна
		/* «аголовок, рамка, позвол€юща€ мен€ть размеры, системное меню, кнопки развЄртывани€ и свЄртывани€ окна  */
		CW_USEDEFAULT,	// х-координата левого верхнего угла окна
		CW_USEDEFAULT,	// y-координата левого верхнего угла окна
		515,	// ширина окна
		600,	// высота окна
		NULL,			// дескриптор родительского окна
		NULL,			// дескриптор меню окна
		hInstance,		// идентификатор приложени€, создавшего окно
		NULL);		// указатель на область данных приложени€


	score = CreateWindow(TEXT("Static"), TEXT("score: 0"), WS_CHILD | WS_VISIBLE | WS_BORDER | SS_CENTER | WS_EX_CLIENTEDGE,
		10, 500, 200, 50, hWnd, NULL, hInstance, NULL);

	take_money = CreateWindow(L"BUTTON", L"new game", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
		250,         // x position 
		500,         // y position 
		200,        // Button width
		50,        // Button height
		hWnd,     // Parent window
		(HMENU)0,       // button id (h - menu)
		hInstance,
		NULL);

	generateFiled(hWnd, hInstance);
	ShowWindow(hWnd, iCmdShow);
	UpdateWindow(hWnd);

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	GdiplusShutdown(gdiplusToken);
	return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	
	HDC hdc;
	PAINTSTRUCT ps;
	switch (message)
	{

	case WM_COMMAND:
	{
					   if ((HWND)lParam == take_money)
					   {
						   for (auto it1 = filed.begin(); it1 != filed.end(); it1++){
							   for (auto itit1 = it1->begin(); itit1 != it1->end(); itit1++){
								   SetWindowText(itit1->id, L"");
								   itit1->mina = (1 == rand() % 4 ? 1 : 0);
								   win = 0;
							   }
						   }
					   }
					   for (auto it = filed.begin(); it != filed.end(); it++){
						   for (auto itit = it->begin(); itit != it->end(); itit++){


							   if ((HWND)lParam == itit->id)
							   {
								   if (itit->mina == 1)
								   {
									   showAllMin();
									   SetWindowText(itit->id, L"mina");

								   }
								   else{
									  
									   wstringstream text;
									   int numbMin = chwkNumbMin(itit->id);
									   text << numbMin;
									   
									   if (!numbMin)
									   {
										   //fgf open false point
									   }

									   SetWindowText(itit->id, text.str().c_str());
									   wstringstream texts;
									   win += 50;
									   texts << TEXT("score: ")<< win;
									   SetWindowText(score, texts.str().c_str());
								   }
							   }
						   }

					   }
					   break;
	}
	case WM_INITDIALOG:
		return 0;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		OnPaint(hdc);
		EndPaint(hWnd, &ps);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);

	}
}
VOID OnPaint(HDC hdc)
{
	Graphics graphics(hdc);
	Pen pen(Color(255, 0, 0, 255));
	graphics.DrawEllipse(&pen, 5.0f, 5.0f, 200.0f, 200.0f);
}