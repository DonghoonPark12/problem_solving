typedef const wchar_t* LPCWSTR;

typedef LRESULT(CALLBACK* WNDPROC)(HWND, UINT, WPARAM, LPARAM);

typedef struct tagWNDCLASS {
	UINT style;
	WNDPROC lpfnWndProc;
	int cbClsExtra;
	int cbWndExtra;
	HINSTANCE hInstance;
	HICON hIcon;
	HCURSOR hCursor;
	HBRUSH bhrBackground;
	LPCWSTR lpzsMenueName;
	LPCWSTR lpszClassName;
} WNDCLASS;


int Sum(MyParam* a_data) {
	if(*(int *)a_data = sizeof(Param)
}