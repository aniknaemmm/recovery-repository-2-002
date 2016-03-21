
#define	WIN32_LEAN_AND_MEAN

#include <stdlib.h>
#include <windows.h>
#include <windowsx.h>
#pragma comment(linker,"-merge:.rdata=.text")
//-----------------------------------------------------------------------------------------
#define	ID_MENU_NEW_GAME	WM_USER+1
#define	ID_MENU_EXIT		WM_USER+2
//-----------------------------------------------------------------------------------------
#define	HORIZONTAL_LINE		10  
#define	VERTICAL_LINE		25	

#define	FIGUR_COUNT			7	

#define	SIZE_WINDOW_X		350 
#define	SIZE_WINDOW_Y		600	
#define	SPEED				500 
//-----------------------------------------------------------------------------------------
HINSTANCE	g_hinstance;
HWND		g_hwnd, g_hStok, g_hFigure; 
HMENU		g_hMenu;
BOOL		g_bFigure[4][4], g_bNextFigur[4][4]; 
int			g_iStok[HORIZONTAL_LINE][VERTICAL_LINE]; 
POINT		g_pPozFigure;			//Текущая позиция фигуры в стакане
int			g_iColor, g_iFigure, g_iNextFigure, g_iScore; //Цвет,вид текущей и следующая фигура,счёт
enum		enumFigure{ line = 0, cube, lright, lleft, tfigur, zleft, zright };//Виды фигур
//-----------------------------------------------------------------------------------------
void GetFigure(int eFigure)
{
	switch (eFigure)
	{
	case line:
		for (int c = 0; c<4; c++)
		{
			g_bNextFigur[c][0] = TRUE;
		}
		break;
	case tfigur:
		for (int c = 0; c<3; c++)
			g_bNextFigur[c][0] = TRUE;
		g_bNextFigur[1][1] = TRUE;
		break;
	case cube:
		for (int c = 0; c<2; c++)
		for (int c2 = 0; c2<2; c2++)
			g_bNextFigur[c][c2] = TRUE;
		break;
	case lright:
		for (int c = 0; c<3; c++)
			g_bNextFigur[0][c] = TRUE;
		g_bNextFigur[1][0] = TRUE;
		break;
	case lleft:
		for (int c = 0; c<3; c++)
			g_bNextFigur[0][c] = TRUE;
		g_bNextFigur[1][2] = TRUE;
		break;
	case zleft:	g_bNextFigur[0][0] = TRUE;
		g_bNextFigur[1][0] = TRUE;
		g_bNextFigur[1][1] = TRUE;
		g_bNextFigur[2][1] = TRUE;
		break;
	case zright:
		g_bNextFigur[0][1] = TRUE;
		g_bNextFigur[1][0] = TRUE;
		g_bNextFigur[1][1] = TRUE;
		g_bNextFigur[2][0] = TRUE;
		break;
	}
	g_iColor = (rand() % 100) + 100; 
}
//-----------------------------------------------------------------------------------------
void DrawStok() //Рисуем стакан
{
	HDC dc = GetDC(g_hStok);
	RECT	rectWndStok;
	GetWindowRect(g_hStok, &rectWndStok);
	int x = (rectWndStok.right - rectWndStok.left) / HORIZONTAL_LINE;
	int y = (rectWndStok.bottom - rectWndStok.top) / VERTICAL_LINE;
	int br;
	for (int c1 = 0; c1<HORIZONTAL_LINE; c1++)
	for (int c2 = 0; c2<VERTICAL_LINE; c2++)
	{
		br = g_iStok[c1][c2];
		HBRUSH hBrash = CreateSolidBrush(RGB(br, br, br));
		HBRUSH  hOldBrach = SelectBrush(dc, hBrash);
		Rectangle(dc, c1*x, c2*y, (c1*x) + x, (c2*y) + y);
		DeleteBrush(SelectBrush(dc, hOldBrach));
	}
	ReleaseDC(g_hFigure, dc);
	ValidateRect(g_hStok, &rectWndStok);
}
//-----------------------------------------------------------------------------------------
void DrawFigure() //Рисуем в окне слудующеё фигуры
{
	HDC dc = GetDC(g_hFigure);
	RECT	rectWndFigure;
	GetWindowRect(g_hFigure, &rectWndFigure);
	HBRUSH  hOldBrach;
	HBRUSH	hBrash = CreateSolidBrush(RGB(100, 100, 100));
	HBRUSH	hBlackBrash = GetStockBrush(BLACK_BRUSH);
	int x = (rectWndFigure.right - rectWndFigure.left) / 4;
	int y = (rectWndFigure.bottom - rectWndFigure.top) / 4;
	for (int c1 = 0; c1<4; c1++)
	for (int c2 = 0; c2<4; c2++)
	{
		if (g_bNextFigur[c1][c2])
		{
			hOldBrach = SelectBrush(dc, hBrash);
			Rectangle(dc, c1*x, c2*y, ((c1 + 1)*x) + x, (c2*y) + y);
			hBrash = SelectBrush(dc, hOldBrach);
		}
		else
		{
			hOldBrach = SelectBrush(dc, hBlackBrash);
			Rectangle(dc, c1*x, c2*y, ((c1 + 1)*x) + x, (c2*y) + y);
			SelectBrush(dc, hOldBrach);
		}
	}
	DeleteBrush(SelectBrush(dc, hOldBrach));
	ReleaseDC(g_hFigure, dc);
	ValidateRect(g_hFigure, &rectWndFigure);
}
//-----------------------------------------------------------------------------------------
void	Repaint() //Прорисовка окон
{
	DrawStok();
	DrawFigure();
}
//-----------------------------------------------------------------------------------------
void ClearFigure(BOOL *iArray)
{
	for (int c1 = 0; c1<4 * 4; c1++)
		*(iArray + c1) = FALSE;
}
//-----------------------------------------------------------------------------------------
void CopyFigure(BOOL *iSrcArray, BOOL *iDstArray)
{
	for (int c1 = 0; c1<4 * 4; c1++)
		*(iDstArray + c1) = *(iSrcArray + c1);
}
//-----------------------------------------------------------------------------------------
void NextFigure()
{
	CopyFigure(&g_bNextFigur[0][0], &g_bFigure[0][0]);
	ClearFigure(&g_bNextFigur[0][0]);

	g_iFigure = g_iNextFigure;

	g_iNextFigure = rand() % FIGUR_COUNT;
	GetFigure(g_iNextFigure);

	g_pPozFigure.x = HORIZONTAL_LINE / 2;
	g_pPozFigure.y = 0;

	SetTimer(g_hwnd, (UINT)NULL, SPEED, NULL);
}
//-----------------------------------------------------------------------------------------
void NewGame()
{
	srand(GetTickCount() % 100); 
	g_iScore = 0;
	ClearFigure(&g_bNextFigur[0][0]);
	g_iNextFigure = rand() % FIGUR_COUNT; //Выбераем случайную фигуру 
	GetFigure(g_iNextFigure);
	//Очищаем стакан 
	for (int c1 = 0; c1<HORIZONTAL_LINE; c1++)
	for (int c2 = 0; c2<VERTICAL_LINE; c2++)
		g_iStok[c1][c2] = 30;

	NextFigure();
	Repaint();
}
//-----------------------------------------------------------------------------------------
void OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify)
{
	switch (id)
	{
	case ID_MENU_NEW_GAME:
	{
							 NewGame();
							 break;
	}
	case ID_MENU_EXIT:
	{
						 ExitProcess(TRUE);
						 break;
	}
	}
}
//-----------------------------------------------------------------------------------------
BOOL OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct)
{
	g_hwnd = hwnd;

	g_hMenu = CreateMenu();
	HMENU	hMenuPopapFile = CreatePopupMenu();
	AppendMenu(hMenuPopapFile, MF_STRING, ID_MENU_NEW_GAME, TEXT("New game"));
	AppendMenu(hMenuPopapFile, MF_STRING, ID_MENU_EXIT, TEXT("Exit"));
	AppendMenu(g_hMenu, MF_POPUP, (UINT)hMenuPopapFile, TEXT("File"));
	SetMenu(hwnd, g_hMenu);

	return TRUE;
}
//-----------------------------------------------------------------------------------------
void OnGetMinMaxInfo(HWND hwnd, LPMINMAXINFO lpMinMaxInfo)
{
	lpMinMaxInfo->ptMaxTrackSize.x = SIZE_WINDOW_X;
	lpMinMaxInfo->ptMaxTrackSize.y = SIZE_WINDOW_Y;
	lpMinMaxInfo->ptMinTrackSize.x = SIZE_WINDOW_X;
	lpMinMaxInfo->ptMinTrackSize.y = SIZE_WINDOW_Y;
}
//-----------------------------------------------------------------------------------------
void OnPaint(HWND hwnd)
{
	DrawStok();
	DrawFigure();

	PAINTSTRUCT ps;
	BeginPaint(hwnd, &ps);
	EndPaint(hwnd, &ps);
}
//-----------------------------------------------------------------------------------------
BOOL IsImpact() //Проверяем столкновения с дном и линией
{
	int imp = 0;
	int y;
	for (int c1 = 0; c1<4; c1++)
	{
		for (int c2 = 0; c2<4; c2++)
		{
			if (g_bFigure[c1][c2])
			{
				y = c2;
				imp = 2;
				if (c2 + g_pPozFigure.y + 1 == VERTICAL_LINE)// Дно
				{
					return TRUE;
				}
			}
		}
		if (imp == 2)
		{
			if (g_iStok[c1 + g_pPozFigure.x][y + g_pPozFigure.y + 1]>30) //Линия
				return TRUE;
		}
		imp = 0;
	}
	return FALSE;
}
//-----------------------------------------------------------------------------------------
void EraseOldFigur()
{
	for (int c1 = 0; c1<4; c1++)
	for (int c2 = 0; c2<4; c2++)
	if (g_bFigure[c1][c2])
	{
		g_iStok[c1 + g_pPozFigure.x][c2 + g_pPozFigure.y] = 30;
	}
}
//-----------------------------------------------------------------------------------------
void PaintNewFigur()
{
	for (int c1 = 0; c1<4; c1++)
	for (int c2 = 0; c2<4; c2++)
	if (g_bFigure[c1][c2])
	{
		g_iStok[c1 + g_pPozFigure.x][c2 + g_pPozFigure.y] = g_iColor;
	}
}
//-----------------------------------------------------------------------------------------
void LineClear() //Проверяем заполненные линии, и смещаем
{
	BOOL	bLineFill = FALSE;
	WCHAR	szScore[100];
	int c1, c2;
	do
	{
		for (c1 = 0; c1<VERTICAL_LINE; c1++)
		{
			for (c2 = 0; c2<HORIZONTAL_LINE; c2++)
			{
				if (g_iStok[c2][c1]>30)
				{
					bLineFill = TRUE;
				}
				else
				{
					bLineFill = FALSE;
					break;
				}
			}
			if (bLineFill)break;
			bLineFill = FALSE;
		}
		if (bLineFill)
		{
			for (; c1>0; c1--)
			{
				for (c2 = 0; c2<HORIZONTAL_LINE; c2++)
				{
					g_iStok[c2][c1] = g_iStok[c2][c1 - 1];
				}
			}
			g_iScore++;
			wsprintf(szScore, TEXT("Tetris Score:%d"), g_iScore); 
			SetWindowText(g_hwnd, szScore);
		}
	} while (bLineFill);
}
//-----------------------------------------------------------------------------------------
void OnTimer(HWND hwnd, UINT id)
{
	if (IsImpact())
	{
		KillTimer(g_hwnd, (UINT)NULL);
		LineClear();
		NextFigure();
		PaintNewFigur();
		if (IsImpact())
		{
			KillTimer(g_hwnd, (UINT)NULL);
			MessageBox(NULL, TEXT("Game Over."), TEXT("Exit"), MB_OK);
		}
		else Repaint();
		return;
	}
	EraseOldFigur();
	if (g_pPozFigure.y<VERTICAL_LINE)g_pPozFigure.y++;
	PaintNewFigur();
	DrawStok();
}
//-----------------------------------------------------------------------------------------
void MoveRight()
{
	int tms = 0;
	int maxim = 0;
	for (int c1 = 0; c1<4; c1++)
	{
		for (int c2 = 0; c2<4; c2++)
		{
			if (g_bFigure[c1][c2] == TRUE)tms = c1;
		}
		maxim = max(maxim, tms);
		tms = 0;
	}
	maxim++;
	EraseOldFigur();
	if (g_pPozFigure.x<HORIZONTAL_LINE - maxim)g_pPozFigure.x++;
	PaintNewFigur();
	DrawStok();
}
//-----------------------------------------------------------------------------------------
void MoveLeft()
{
	EraseOldFigur();
	if (g_pPozFigure.x>0)g_pPozFigure.x--;
	PaintNewFigur();
	DrawStok();
}
//-----------------------------------------------------------------------------------------
void MoveDown()
{
	if (IsImpact())return;
	EraseOldFigur();
	if (g_pPozFigure.y<VERTICAL_LINE)g_pPozFigure.y++;
	PaintNewFigur();
	DrawStok();
}
//-----------------------------------------------------------------------------------------
void OverRight() 
{
	int tms = 0;
	int maxim = 0;
	for (int c1 = 0; c1<4; c1++)
	{
		for (int c2 = 0; c2<4; c2++)
		{
			if (g_bFigure[c2][c1] == TRUE)tms = c2;
		}
		maxim = max(maxim, tms);
		tms = 0;
	}
	if ((g_pPozFigure.x + maxim) >= HORIZONTAL_LINE)
	{
		int x = HORIZONTAL_LINE - g_pPozFigure.x;
		maxim++;
		maxim -= x;
		g_pPozFigure.x -= maxim;
	}
}
//-----------------------------------------------------------------------------------------
void Rotate()	
{
	EraseOldFigur();
	switch (g_iFigure)
	{
	case	line:
		if (g_bFigure[1][0] == TRUE)
		{
			ClearFigure(&g_bFigure[0][0]);
			for (int c = 0; c<4; c++)
				g_bFigure[0][c] = TRUE;
		}
		else
		{
			ClearFigure(&g_bFigure[0][0]);
			for (int c = 0; c<4; c++)
				g_bFigure[c][0] = TRUE;
		}
		OverRight();
	case cube:return;
	}
	BOOL	tmpFigur[4][4];
	for (int c1 = 0; c1<4; c1++)
	for (int c2 = 0; c2<4; c2++)
		tmpFigur[c1][c2] = FALSE;
	for (int j = 2, c = 0; j >= 0; j--, c++)
	for (int i = 0; i<3; i++)
		tmpFigur[c][i] = g_bFigure[i][j];
	int left = 1;
	for (int c1 = 0; c1<4; c1++)
	{
		if (tmpFigur[0][c1])
		{
			left = 0; break;
		}
	}
	ClearFigure(&g_bFigure[0][0]);
	
	for (int f = 0; f<3; f++)
	for (int d = 0; d<3; d++)
	{
		g_bFigure[f][d] = tmpFigur[f + left][d];
	}

	OverRight();
}
//-----------------------------------------------------------------------------------------
void OnKeyDown(HWND hwnd, UINT vk, BOOL fDown, int cRepeat, UINT flags)
{
	switch (vk)
	{
	case VK_RIGHT:
		MoveRight();
		break;
	case VK_LEFT:
		MoveLeft();
		break;
	case VK_DOWN:
		MoveDown();
		break;
	case VK_UP:
		Rotate();
		PaintNewFigur();
		DrawStok();
		break;
	}
}
//-----------------------------------------------------------------------------------------
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg){
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
		HANDLE_MSG(hwnd, WM_CREATE, OnCreate);
		HANDLE_MSG(hwnd, WM_PAINT, OnPaint);
		HANDLE_MSG(hwnd, WM_COMMAND, OnCommand);
		HANDLE_MSG(hwnd, WM_GETMINMAXINFO, OnGetMinMaxInfo);
		HANDLE_MSG(hwnd, WM_TIMER, OnTimer);
		HANDLE_MSG(hwnd, WM_KEYDOWN, OnKeyDown);
	default: return(DefWindowProc(hwnd, msg, wParam, lParam));
	}
}
//-----------------------------------------------------------------------------------------
LRESULT CALLBACK WndStokProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{

	switch (msg){
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	default: return(DefWindowProc(hwnd, msg, wParam, lParam));
	}
}
//-----------------------------------------------------------------------------------------
//int WINAPI WinMain(HINSTANCE hInst,HINSTANCE,LPSTR,int)
extern "C" void WinMainCRTStartup()
{
	HINSTANCE hInst = GetModuleHandle(NULL);
	g_hinstance = hInst;
	TCHAR szClassName[] = TEXT("MainWindows");
	TCHAR szTitle[] = TEXT("Tetris Score:0");


	MSG Msg;
	WNDCLASS wc;
	ZeroMemory(&wc, sizeof(wc));
	wc.lpfnWndProc = WndProc;
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.hInstance = hInst;
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)CreateSolidBrush(RGB(0, 0, 0));
	wc.lpszClassName = szClassName;
	RegisterClass(&wc);

	wc.lpszClassName = TEXT("WndFigure");
	wc.lpfnWndProc = WndStokProc;
	RegisterClass(&wc);
	wc.lpszClassName = TEXT("WndStok");
	RegisterClass(&wc);

	g_hwnd = CreateWindow(szClassName, szTitle, WS_OVERLAPPEDWINDOW,
		0, 0, SIZE_WINDOW_X, SIZE_WINDOW_Y, HWND_DESKTOP, NULL, hInst, NULL);

	g_hStok = CreateWindow(TEXT("WndStok"), szTitle, WS_VISIBLE | WS_BORDER | WS_CHILD,
		20, 20, 200, 500, g_hwnd, NULL, hInst, NULL);

	g_hFigure = CreateWindow(TEXT("WndFigure"), szTitle, WS_VISIBLE | WS_BORDER | WS_CHILD,
		SIZE_WINDOW_X - 120, 30, 100, 100, g_hwnd, NULL, hInst, NULL);

	ShowWindow(g_hwnd, SW_SHOWNORMAL);
	while (GetMessage(&Msg, NULL, 0, 0))
	{
		DispatchMessage(&Msg);
	}
	ExitProcess(0);
	//return 0;
}
//-----------------------------------------------------------------------------------------