// Win32.cpp : 애플리케이션에 대한 진입점을 정의합니다.
#include "pch.h"
#include "framework.h"

#include "resource.h"

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    if (uMsg == WM_DESTROY)                           // WM_CLOSE 처리후에 들어오는 메시지
    {                   
        PostQuitMessage(0);                           // 자신의 메시지 큐에 WM_QUIT 메시지를 넣는다!
    }
    if (uMsg == WM_CLOSE) {
        if (IDCANCEL == MessageBox(hWnd, L"나 죽이지마!", L"나 죽이려고?", MB_OKCANCEL | MB_ICONQUESTION)) 
            return 1;
    }
    return DefWindowProc(hWnd, uMsg, wParam, lParam);  // 개발자가 처리하지 않은 메시지들을 처리한다!
}

/*
    hPrevInstance은 쓰이지 않는 인자
*/
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    /* --------------------------------- OS가 어플리케이션에 자주 물어보는 것들 --------------------------------- */
                                                                    // 윈도우 클래스 등록 작업!!
    WNDCLASS wc;

    HBRUSH h_brush = CreateSolidBrush(RGB(0, 255, 0));

    wc.cbClsExtra = 0;                                              // 현재는 Shared 메모리 시스템을 쓰기에, 잘 안쓰임
    wc.cbWndExtra = 0;                                              // 현재는 Shared 메모리 시스템을 쓰기에, 잘 안쓰임
    wc.hbrBackground = (HBRUSH)COLOR_WINDOW;                        // 배경색 지정
    //wc.hbrBackground = h_brush;                                   // CUSTOM
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);                       // 커서 지정
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);                     // 응용 프로그램 로고 아이콘 지정
    //wc.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WIN32));   // CUSTOM 
    wc.hInstance = hInstance;
    wc.lpfnWndProc = WndProc;                                       // 기본 메시지 처리기 함수 지정
    wc.lpszClassName = L"tipssoft";                                 // 윈도우 클래스 이름 지정
    wc.lpszMenuName = NULL;
    wc.style = CS_HREDRAW | CS_VREDRAW;
    RegisterClass(&wc);                                             // 윈도우 클래스 등록
    /* ------------------------------------------------------------------------------------------------------------ */

    /* ------------------------------------------------------------------------------------------------------------ */    
    HWND hWnd = CreateWindowW(L"tipssoft", L"www.tipssoft.com",     // 윈도우 생성!
        WS_OVERLAPPEDWINDOW, 100, 90, 400, 350, NULL, NULL, hInstance, NULL);
    ShowWindow(hWnd, nCmdShow);                                     // 윈도우를 화면에 어떻게 출력할 것인가 지정!
    UpdateWindow(hWnd);                                             // WM_PAINT 메시지가 대기 상태에 있다면 즉시 수행하도록 한다!

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {                          // WM_QUIT 메시지가 발생할때까지 반복한다.
        TranslateMessage(&msg);                                     // 키보드 메시지 발생시에 추가 메시지를 발생할지 여부 체크
        DispatchMessage(&msg);                                      // 발생된 메시지를 처리한다!
    }
    return msg.wParam;
}
