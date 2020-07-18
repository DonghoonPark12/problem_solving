// Win32.cpp : 애플리케이션에 대한 진입점을 정의합니다.
#include "pch.h"
#include "framework.h"

#include "resource.h"

#define MAX_COUNT  1000

int g_count = 0;
POINT g_pos_list[1000];

/*
    4개 인자는 고정이다.
    MFC에 cWindowClass가 본 함수를 대신한다.
*/
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    if (uMsg == WM_DESTROY)       // WM_CLOSE 처리후에 들어오는 메시지
    {                             // WM_DESTROY는 윈도우를 종료시키는 것이지 윈도우 Procedure를 종료시키는 것이 아니다. 
        PostQuitMessage(0);       // 메인 윈도우가 파괴될때 발생하는 WM_DESTROY 메시지일 경우는, 메시지 큐에 WM_QUIT 메시지를 추가적으로 넣어준다!
    }
    else if (uMsg == WM_CLOSE)
    {
        if (IDCANCEL == MessageBox(hWnd, L"나 저장?", L"저장하시겠습니까?", MB_OKCANCEL | MB_ICONQUESTION)) 
            return 1;
    }
    else if (uMsg == WM_PAINT)
    {
        PAINTSTRUCT ps;
        HDC h_dc = BeginPaint(hWnd, &ps);
        /* ------------------------------------------------------------------------- */
        HBRUSH h_red_brush = CreateSolidBrush(RGB(0, 255, 255));
        HGDIOBJ h_old_brush = SelectObject(h_dc, h_red_brush);

        POINT* p = g_pos_list;
        for (int i = 0; i < g_count; i++, p++)
        {
            Rectangle(h_dc, p->x - 10, p->y - 10, p->x + 10, p->y + 10);
        }

        SelectObject(h_dc, h_old_brush);
        DeleteObject(h_red_brush);
        /* ------------------------------------------------------------------------- */
        EndPaint(hWnd, &ps);
        ReleaseDC(hWnd, h_dc);
        return 0;
    }
    else if (uMsg == WM_LBUTTONDOWN)
    {
        HDC h_dc = GetDC(hWnd);

        int x = lParam & 0x0000FFFF;         //LOWORD(lParam);
        int y = (lParam >> 16) & 0x0000FFFF; //HIWORD(lParam);

        if (g_count < MAX_COUNT)
        {
            g_pos_list[g_count].x = x;
            g_pos_list[g_count].y = y;
            g_count++;
        }

        HBRUSH h_red_brush = CreateSolidBrush(RGB(0, 255, 255));
        HGDIOBJ h_old_brush = SelectObject(h_dc, h_red_brush); //?

        if (wParam & MK_CONTROL) 
            Ellipse(h_dc, x - 10, y - 10, x + 10, y + 10);
        else 
            Rectangle(h_dc, x - 10, y - 10, x + 10, y + 10);

        SelectObject(h_dc, h_old_brush);
        DeleteObject(h_red_brush);

        ReleaseDC(hWnd, h_dc);
    }                                                             // DefWindowProc 함수는 Window OS가 발생하는 프로그래머가 처리하지 못하는 메시지를 처리
    return DefWindowProc(hWnd, uMsg, wParam, lParam);             // 개발자가 처리하지 않은 메시지들을 처리한다!
}

/*
    hInstance : Instance Jandle을 저장

    hPrevInstance는 쓰이지 않지만, 하위 호환성 때문에 못 없엔다
    ~~~.exe, (인자) 중에서 (인자)가 IpCmdline에 들어간다.
    nCmdShow는 창 크기(UI로 조정 가능)

    접두어(헝가리안 노테이션)
    - h : Hanlde
    - lp : Long Pointer(지금은 쓰이지 않는)
    - n : Number of
*/
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    /* --------------------------------- OS가 어플리케이션에 자주 물어보는 것들 --------------------------------- */
                                                                    // 윈도우 클래스 등록 작업!!
    WNDCLASS wc;

    HBRUSH h_brush = CreateSolidBrush(RGB(0, 255, 0));

    wc.cbClsExtra = 0;                                              // 현재는 Shared 메모리 시스템을 쓰기에, 잘 안쓰임
    wc.cbWndExtra = 0;                                              // 현재는 Shared 메모리 시스템을 쓰기에, 잘 안쓰임
    //wc.hbrBackground = (HBRUSH)COLOR_WINDOW;                      // 배경색 지정
    //wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1)
    wc.hbrBackground = h_brush;                                     // CUSTOM
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);                       // 커서 지정
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);                     // 응용 프로그램 로고 아이콘 지정
    //wc.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WIN32));   // CUSTOM 
    wc.hInstance = hInstance;
    wc.lpfnWndProc = WndProc;                                       // 기본 메시지 처리기 함수 지정
    wc.lpszClassName = L"tipssoft";                                 // 윈도우 클래스 이름 지정
    //wc.lpszMenuName = NULL;
    wc.lpszMenuName = MAKEINTRESOURCE(IDC_WIN32);                   // 기본 메뉴 생성
    wc.style = CS_HREDRAW | CS_VREDRAW;
    RegisterClass(&wc);                                             // 윈도우 클래스 등록
    /* ------------------------------------------------------------------------------------------------------------ */

    /* ------------------------------------------------------------------------------------------------------------ */    
    HWND hWnd = CreateWindowW(                                      // 윈도우 생성!
        L"tipssoft", L"www.tipssoft.com",     
        WS_OVERLAPPEDWINDOW, 100, 90, 400, 350, NULL, NULL, hInstance, NULL);
    /* OS가 Window를 만드는 중... 여기서 잠깐 기다릴 필요가 있다 */
    /* OS가 날리는 메시지를 기다린다 */
    ShowWindow(hWnd, nCmdShow);                                     // 윈도우를 화면에 어떻게 출력할 것인가 지정!
    //ShowWindow(hWnd, SW_MAXIMIZE);
    UpdateWindow(hWnd);                                             // WM_PAINT 메시지가 대기 상태에 있다면 즉시 수행하도록 한다!

    /* ------------------------------------------------------------------------------------------------------------ */
    /* 프로그램에 전달된 메시지를 번역하고 실행하는 작업 */
    MSG msg;                                                        
    while (GetMessage(&msg, NULL, 0, 0)) {                          // WM_QUIT 메시지가 발생할때까지 반복한다.
        TranslateMessage(&msg);                                     // 키보드 메시지 발생시에 추가 메시지를 발생할지 여부 체크
        DispatchMessage(&msg);                                      // 발생된 메시지를 처리기인 WndProc 함수를 호출한다.
    }
    /* ------------------------------------------------------------------------------------------------------------ */
    DeleteObject(h_brush);                                          // 프로그램 종료시에 hbrBackground에 저장된 'Brush Object'는 자동 제거 되지 않으므로 직접 제거

    return msg.wParam;
}