#include "pch.h"
#include "framework.h"

#include "resource.h"
#include <Windowsx.h>

#define MAX_COUNT 1000

int g_count = 0;
POINT g_pos_list[MAX_COUNT];

class CClientDC
{
protected:
    HDC mh_dc;
    HWND mh_wnd;

public:
    CClientDC(HWND ah_wnd)
    {
        mh_wnd = ah_wnd;
        mh_dc = GetDC(mh_wnd);
    }

    ~CClientDC()
    {
        ReleaseDC(mh_wnd, mh_dc);
    }

    HGDIOBJ SelectObject(HGDIOBJ ah_red_brush)
    {
        ::SelectObject(mh_dc, ah_red_brush);
    }

    void Rectangle(int sx, int sy, int ex, int ey)
    {
        ::Rectangle(mh_dc, sx, sy, ex, ey);
    }

    void Ellipse(int sx, int sy, int ex, int ey)
    {
        ::Ellipse(mh_dc, sx, sy, ex, ey);
    }
};


LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    if (uMsg == WM_DESTROY) 
        PostQuitMessage(0);
    else if (uMsg == WM_PAINT) {
        PAINTSTRUCT ps;
        HDC h_dc = BeginPaint(hWnd, &ps);

        POINT* p = g_pos_list;
        for (int i = 0; i < g_count; i++, p++) {
            Rectangle(h_dc, p->x - 10, p->y - 10, p->x + 10, p->y + 10);
        }

        EndPaint(hWnd, &ps);
        return 0;
    }
    else if (uMsg == WM_LBUTTONDOWN) {
        CClientDC dc(hWnd);

        int x = GET_X_LPARAM(lParam);  //  lParam & 0x0000FFFF;
        int y = HIWORD(lParam);  //  (lParam >> 16) & 0x0000FFFF;

        if (g_count < MAX_COUNT) {
            g_pos_list[g_count].x = x;
            g_pos_list[g_count].y = y;
            g_count++;
        }

        HBRUSH h_red_brush = CreateSolidBrush(RGB(255, 0, 0));
        HGDIOBJ h_old_brush = dc.SelectObject(h_red_brush);

        if (wParam & MK_CONTROL) dc.Ellipse(x - 10, y - 10, x + 10, y + 10);
        else dc.Rectangle(x - 10, y - 10, x + 10, y + 10);

        dc.SelectObject(h_old_brush);
        DeleteObject(h_red_brush);
    }
    // 개발자가 처리하지 않은 메시지들을 처리한다!
    return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    // 윈도우 클래스 등록 작업!!
    WNDCLASS wc;

    HBRUSH h_brush = CreateSolidBrush(RGB(0, 255, 0));

    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hbrBackground = h_brush;  // (HBRUSH)COLOR_WINDOW;     // 배경색 지정
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);                // 커서 지정
    wc.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON3));   // 응용 프로그램 로고 아이콘 지정
    wc.hInstance = hInstance;
    wc.lpfnWndProc = WndProc;    // 기본 메시지 처리기 함수 지정
    wc.lpszClassName = L"tipssoft";    // 윈도우 클래스 이름 지정
    wc.lpszMenuName = MAKEINTRESOURCE(IDI_ICON3);
    wc.style = CS_HREDRAW | CS_VREDRAW;
    RegisterClass(&wc);    // 윈도우 클래스 등록

    // 윈도우 생성!
    HWND hWnd = CreateWindowW(L"tipssoft", L"우리 프로그램 제목",
        WS_OVERLAPPEDWINDOW, 100, 90, 400, 350, NULL, NULL, hInstance, NULL);
    ShowWindow(hWnd, nCmdShow);   // 윈도우를 화면에 어떻게 출력할 것인가 지정!
    UpdateWindow(hWnd);    // WM_PAINT 메시지가 대기 상태에 있다면 즉시 수행하도록 한다!

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {   // WM_QUIT 메시지가 발생할때까지 반복한다.
        TranslateMessage(&msg);   // 키보드 메시지 발생시에 추가 메시지를 발생할지 여부 체크
        DispatchMessage(&msg);   // 발생된 메시지를 처리한다!
    }

    DeleteObject(h_brush);

    return msg.wParam;
}