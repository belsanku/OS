#include <windows.h>
#include "recieverRes.h"

LRESULT CALLBACK
DlgProc(HWND hDlg, UINT message, WPARAM wParam,
        LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine,
                   int nCmdShow)
{
    MSG msg;
    DialogBox(hInstance, (LPCTSTR)IDD_DLGTEST, NULL,
              (DLGPROC)DlgProc);
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return msg.wParam;
}

LRESULT CALLBACK
DlgProc(HWND hDlg, UINT message, WPARAM wParam,
        LPARAM lParam)
{
    TCHAR strText[100];
    switch (message)
    {
    case WM_INITDIALOG:
        return TRUE;
    case WM_COPYDATA:
        {
            SetDlgItemText(hDlg, IDC_MESSAGE, TEXT((char *)(((COPYDATASTRUCT *)lParam)->lpData)));
        }
    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
        case ID_SEND:
            GetDlgItemText(hDlg, IDC_MESSAGE, strText, sizeof(strText) * sizeof(strText[0]));
            HWND hWnd;
            COPYDATASTRUCT data;
            hWnd = FindWindow(TEXT("#32770"), TEXT("dialog1"));
            data.cbData = _tcslen(strText);
            data.lpData = strText;
            SendMessage(hWnd, WM_COPYDATA,
                        (WPARAM)GetFocus(),
                        (LPARAM)&data);
            return TRUE;
        case IDCANCEL:
            PostQuitMessage(0);
            return TRUE;
        }
        break;
    default:
        return FALSE;
    }
}