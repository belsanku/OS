#include <windows.h>
#include "resource.h"
#include <atlstr.h>

int opr = 0;

LRESULT CALLBACK
DlgProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
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
DlgProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    TCHAR result[100];
    TCHAR firstNumber[100];
    TCHAR secondNumber[100];
    TCHAR tempBuf[100];
    int tempor = IDC_EDIT1;
    int len = 0;
    switch (message)
    {
    case WM_INITDIALOG:
        return TRUE;
    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
        case IDOK:
            if (opr != 0) {
                GetDlgItemText(hDlg, IDC_EDIT1, firstNumber, 100);
                GetDlgItemText(hDlg, IDC_EDIT2, secondNumber, 100);
                if (opr == 1) {
                    _stprintf(result, TEXT("%lld"), (_tstoll(firstNumber) + _tstoll(secondNumber)));
                } else if (opr == 2) {
                    _stprintf(result, TEXT("%lld"), (_tstoll(firstNumber) - _tstoll(secondNumber)));
                } else if (opr == 3) {
                    _stprintf(result, TEXT("%lld"), (_tstoll(firstNumber) * _tstoll(secondNumber)));
                } else if (opr == 4) {
                    if (_tstoll(secondNumber) == 0) {
                        _stprintf(result, TEXT("%s"), TEXT("nan"));
                    } else {
                        _stprintf(result, TEXT("%lld"), (_tstoll(firstNumber) / _tstoll(secondNumber)));
                    }
                }
                SetDlgItemText(hDlg, IDC_EDIT3, result);
                opr = 0;
            } 
            return TRUE;
        case ID_7:
            tempBuf[100];
            if (opr == 0) {
            GetDlgItemText(hDlg, IDC_EDIT1, tempBuf, sizeof(tempBuf) * sizeof(tempBuf[0]));
            len = _tcslen(tempBuf);
            _stprintf(tempBuf + len, TEXT("%d"), 7);
            SetDlgItemText(hDlg, IDC_EDIT1, tempBuf);
            } else {
                GetDlgItemText(hDlg, IDC_EDIT2, tempBuf, sizeof(tempBuf) * sizeof(tempBuf[0]));
            len = _tcslen(tempBuf);
            _stprintf(tempBuf + len, TEXT("%d"), 7);
            SetDlgItemText(hDlg, IDC_EDIT2, tempBuf);
            }
            return TRUE;
        case ID_8:
            tempBuf[100];
            if (opr == 0) {
            GetDlgItemText(hDlg, IDC_EDIT1, tempBuf, sizeof(tempBuf) * sizeof(tempBuf[0]));
            len = _tcslen(tempBuf);
            _stprintf(tempBuf + len, TEXT("%d"), 8);
            SetDlgItemText(hDlg, IDC_EDIT1, tempBuf);
            } else {
                GetDlgItemText(hDlg, IDC_EDIT2, tempBuf, sizeof(tempBuf) * sizeof(tempBuf[0]));
            len = _tcslen(tempBuf);
            _stprintf(tempBuf + len, TEXT("%d"), 8);
            SetDlgItemText(hDlg, IDC_EDIT2, tempBuf);
            }
            return TRUE;
        case ID_9:
            tempBuf[100];
            if (opr == 0) {
            GetDlgItemText(hDlg, IDC_EDIT1, tempBuf, sizeof(tempBuf) * sizeof(tempBuf[0]));
            len = _tcslen(tempBuf);
            _stprintf(tempBuf + len, TEXT("%d"), 9);
            SetDlgItemText(hDlg, IDC_EDIT1, tempBuf);
            } else {
                GetDlgItemText(hDlg, IDC_EDIT2, tempBuf, sizeof(tempBuf) * sizeof(tempBuf[0]));
            len = _tcslen(tempBuf);
            _stprintf(tempBuf + len, TEXT("%d"), 9);
            SetDlgItemText(hDlg, IDC_EDIT2, tempBuf);
            }
            return TRUE;
        case ID_10:
            tempBuf[100];
            if (opr == 0) {
            GetDlgItemText(hDlg, IDC_EDIT1, tempBuf, sizeof(tempBuf) * sizeof(tempBuf[0]));
            len = _tcslen(tempBuf);
            _stprintf(tempBuf + len, TEXT("%d"), 1);
            SetDlgItemText(hDlg, IDC_EDIT1, tempBuf);
            } else {
                GetDlgItemText(hDlg, IDC_EDIT2, tempBuf, sizeof(tempBuf) * sizeof(tempBuf[0]));
            len = _tcslen(tempBuf);
            _stprintf(tempBuf + len, TEXT("%d"), 1);
            SetDlgItemText(hDlg, IDC_EDIT2, tempBuf);
            }
            return TRUE;
        case ID_6:
            tempBuf[100];
            if (opr == 0) {
            GetDlgItemText(hDlg, IDC_EDIT1, tempBuf, sizeof(tempBuf) * sizeof(tempBuf[0]));
            len = _tcslen(tempBuf);
            _stprintf(tempBuf + len, TEXT("%d"), 6);
            SetDlgItemText(hDlg, IDC_EDIT1, tempBuf);
            } else {
                GetDlgItemText(hDlg, IDC_EDIT2, tempBuf, sizeof(tempBuf) * sizeof(tempBuf[0]));
            len = _tcslen(tempBuf);
            _stprintf(tempBuf + len, TEXT("%d"), 6);
            SetDlgItemText(hDlg, IDC_EDIT2, tempBuf);
            }
            return TRUE;
        case ID_5:
            tempBuf[100];
            if (opr == 0) {
            GetDlgItemText(hDlg, IDC_EDIT1, tempBuf, sizeof(tempBuf) * sizeof(tempBuf[0]));
            len = _tcslen(tempBuf);
            _stprintf(tempBuf + len, TEXT("%d"), 5);
            SetDlgItemText(hDlg, IDC_EDIT1, tempBuf);
            } else {
                GetDlgItemText(hDlg, IDC_EDIT2, tempBuf, sizeof(tempBuf) * sizeof(tempBuf[0]));
            len = _tcslen(tempBuf);
            _stprintf(tempBuf + len, TEXT("%d"), 5);
            SetDlgItemText(hDlg, IDC_EDIT2, tempBuf);
            }
            return TRUE;
        case ID_4:
            tempBuf[100];
            if (opr == 0) {
            GetDlgItemText(hDlg, IDC_EDIT1, tempBuf, sizeof(tempBuf) * sizeof(tempBuf[0]));
            len = _tcslen(tempBuf);
            _stprintf(tempBuf + len, TEXT("%d"), 4);
            SetDlgItemText(hDlg, IDC_EDIT1, tempBuf);
            } else {
                GetDlgItemText(hDlg, IDC_EDIT2, tempBuf, sizeof(tempBuf) * sizeof(tempBuf[0]));
            len = _tcslen(tempBuf);
            _stprintf(tempBuf + len, TEXT("%d"), 4);
            SetDlgItemText(hDlg, IDC_EDIT2, tempBuf);
            }
            return TRUE;
        case ID_3:
            tempBuf[100];
            if (opr == 0) {
            GetDlgItemText(hDlg, IDC_EDIT1, tempBuf, sizeof(tempBuf) * sizeof(tempBuf[0]));
            len = _tcslen(tempBuf);
            _stprintf(tempBuf + len, TEXT("%d"), 3);
            SetDlgItemText(hDlg, IDC_EDIT1, tempBuf);
            } else {
                GetDlgItemText(hDlg, IDC_EDIT2, tempBuf, sizeof(tempBuf) * sizeof(tempBuf[0]));
            len = _tcslen(tempBuf);
            _stprintf(tempBuf + len, TEXT("%d"), 3);
            SetDlgItemText(hDlg, IDC_EDIT2, tempBuf);
            }
            return TRUE;
        case ID_20:
            tempBuf[100];
            if (opr == 0) {
            GetDlgItemText(hDlg, IDC_EDIT1, tempBuf, sizeof(tempBuf) * sizeof(tempBuf[0]));
            len = _tcslen(tempBuf);
            _stprintf(tempBuf + len, TEXT("%d"), 2);
            SetDlgItemText(hDlg, IDC_EDIT1, tempBuf);
            } else {
                GetDlgItemText(hDlg, IDC_EDIT2, tempBuf, sizeof(tempBuf) * sizeof(tempBuf[0]));
            len = _tcslen(tempBuf);
            _stprintf(tempBuf + len, TEXT("%d"), 2);
            SetDlgItemText(hDlg, IDC_EDIT2, tempBuf);
            }
            return TRUE;
        case ID_0:
            tempBuf[100];
            if (opr == 0) {
            GetDlgItemText(hDlg, IDC_EDIT1, tempBuf, sizeof(tempBuf) * sizeof(tempBuf[0]));
            len = _tcslen(tempBuf);
            _stprintf(tempBuf + len, TEXT("%d"), 0);
            SetDlgItemText(hDlg, IDC_EDIT1, tempBuf);
            } else {
                GetDlgItemText(hDlg, IDC_EDIT2, tempBuf, sizeof(tempBuf) * sizeof(tempBuf[0]));
            len = _tcslen(tempBuf);
            _stprintf(tempBuf + len, TEXT("%d"), 0);
            SetDlgItemText(hDlg, IDC_EDIT2, tempBuf);
            }
            return true;
        case ID_BTNPLUS:
            tempBuf[100];
            GetDlgItemText(hDlg, IDC_EDIT1, tempBuf, sizeof(tempBuf) * sizeof(tempBuf[0]));
            if (_tstoll(tempBuf) != 0)
            opr = 1;
            return TRUE;
        case ID_BTNMINUS:
            tempBuf[100];
            GetDlgItemText(hDlg, IDC_EDIT1, tempBuf, sizeof(tempBuf) * sizeof(tempBuf[0]));
            if (_tstoll(tempBuf) != 0)
            opr = 2;
            return TRUE;
        case ID_BTNMULT:
            tempBuf[100];
            GetDlgItemText(hDlg, IDC_EDIT1, tempBuf, sizeof(tempBuf) * sizeof(tempBuf[0]));
            if (_tstoll(tempBuf) != 0)
            opr = 3;
            return TRUE;
        case ID_BTNDIV:
            tempBuf[100];
            GetDlgItemText(hDlg, IDC_EDIT1, tempBuf, sizeof(tempBuf) * sizeof(tempBuf[0]));
            if (_tstoll(tempBuf) != 0)
            opr = 4;
            return TRUE;
        case ID_CLEAR:
            SetDlgItemText(hDlg, IDC_EDIT1, TEXT(""));
            SetDlgItemText(hDlg, IDC_EDIT2, TEXT(""));
            SetDlgItemText(hDlg, IDC_EDIT3, TEXT(""));
            opr = 0;
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