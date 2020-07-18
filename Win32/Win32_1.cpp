// Win32.cpp : ���ø����̼ǿ� ���� �������� �����մϴ�.
#include "pch.h"
#include "framework.h"

#include "resource.h"

#define MAX_COUNT  1000

int g_count = 0;
POINT g_pos_list[1000];

/*
    4�� ���ڴ� �����̴�.
    MFC�� cWindowClass�� �� �Լ��� ����Ѵ�.
*/
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    if (uMsg == WM_DESTROY)       // WM_CLOSE ó���Ŀ� ������ �޽���
    {                             // WM_DESTROY�� �����츦 �����Ű�� ������ ������ Procedure�� �����Ű�� ���� �ƴϴ�. 
        PostQuitMessage(0);       // ���� �����찡 �ı��ɶ� �߻��ϴ� WM_DESTROY �޽����� ����, �޽��� ť�� WM_QUIT �޽����� �߰������� �־��ش�!
    }
    else if (uMsg == WM_CLOSE)
    {
        if (IDCANCEL == MessageBox(hWnd, L"�� ����?", L"�����Ͻðڽ��ϱ�?", MB_OKCANCEL | MB_ICONQUESTION)) 
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
    }                                                             // DefWindowProc �Լ��� Window OS�� �߻��ϴ� ���α׷��Ӱ� ó������ ���ϴ� �޽����� ó��
    return DefWindowProc(hWnd, uMsg, wParam, lParam);             // �����ڰ� ó������ ���� �޽������� ó���Ѵ�!
}

/*
    hInstance : Instance Jandle�� ����

    hPrevInstance�� ������ ������, ���� ȣȯ�� ������ �� ������
    ~~~.exe, (����) �߿��� (����)�� IpCmdline�� ����.
    nCmdShow�� â ũ��(UI�� ���� ����)

    ���ξ�(�밡���� �����̼�)
    - h : Hanlde
    - lp : Long Pointer(������ ������ �ʴ�)
    - n : Number of
*/
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    /* --------------------------------- OS�� ���ø����̼ǿ� ���� ����� �͵� --------------------------------- */
                                                                    // ������ Ŭ���� ��� �۾�!!
    WNDCLASS wc;

    HBRUSH h_brush = CreateSolidBrush(RGB(0, 255, 0));

    wc.cbClsExtra = 0;                                              // ����� Shared �޸� �ý����� ���⿡, �� �Ⱦ���
    wc.cbWndExtra = 0;                                              // ����� Shared �޸� �ý����� ���⿡, �� �Ⱦ���
    //wc.hbrBackground = (HBRUSH)COLOR_WINDOW;                      // ���� ����
    //wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1)
    wc.hbrBackground = h_brush;                                     // CUSTOM
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);                       // Ŀ�� ����
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);                     // ���� ���α׷� �ΰ� ������ ����
    //wc.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WIN32));   // CUSTOM 
    wc.hInstance = hInstance;
    wc.lpfnWndProc = WndProc;                                       // �⺻ �޽��� ó���� �Լ� ����
    wc.lpszClassName = L"tipssoft";                                 // ������ Ŭ���� �̸� ����
    //wc.lpszMenuName = NULL;
    wc.lpszMenuName = MAKEINTRESOURCE(IDC_WIN32);                   // �⺻ �޴� ����
    wc.style = CS_HREDRAW | CS_VREDRAW;
    RegisterClass(&wc);                                             // ������ Ŭ���� ���
    /* ------------------------------------------------------------------------------------------------------------ */

    /* ------------------------------------------------------------------------------------------------------------ */    
    HWND hWnd = CreateWindowW(                                      // ������ ����!
        L"tipssoft", L"www.tipssoft.com",     
        WS_OVERLAPPEDWINDOW, 100, 90, 400, 350, NULL, NULL, hInstance, NULL);
    /* OS�� Window�� ����� ��... ���⼭ ��� ��ٸ� �ʿ䰡 �ִ� */
    /* OS�� ������ �޽����� ��ٸ��� */
    ShowWindow(hWnd, nCmdShow);                                     // �����츦 ȭ�鿡 ��� ����� ���ΰ� ����!
    //ShowWindow(hWnd, SW_MAXIMIZE);
    UpdateWindow(hWnd);                                             // WM_PAINT �޽����� ��� ���¿� �ִٸ� ��� �����ϵ��� �Ѵ�!

    /* ------------------------------------------------------------------------------------------------------------ */
    /* ���α׷��� ���޵� �޽����� �����ϰ� �����ϴ� �۾� */
    MSG msg;                                                        
    while (GetMessage(&msg, NULL, 0, 0)) {                          // WM_QUIT �޽����� �߻��Ҷ����� �ݺ��Ѵ�.
        TranslateMessage(&msg);                                     // Ű���� �޽��� �߻��ÿ� �߰� �޽����� �߻����� ���� üũ
        DispatchMessage(&msg);                                      // �߻��� �޽����� ó������ WndProc �Լ��� ȣ���Ѵ�.
    }
    /* ------------------------------------------------------------------------------------------------------------ */
    DeleteObject(h_brush);                                          // ���α׷� ����ÿ� hbrBackground�� ����� 'Brush Object'�� �ڵ� ���� ���� �����Ƿ� ���� ����

    return msg.wParam;
}