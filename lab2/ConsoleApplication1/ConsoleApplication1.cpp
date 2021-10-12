#define _CRT_SECURE_NO_WARNINGS_
#include <windows.h>
#include <iostream>
#include <string>
#include <atlstr.h>
#include <fileapi.h>

using namespace std;

string DefineProcessorArch(WORD temp)
{
	string Arch = "";
	if (temp == WORD(9))
	{
		Arch = "x64";
	}
	else if (temp == WORD(5))
	{
		Arch = "ARM";
	}
	else if (temp == WORD(12))
	{
		Arch = "ARM64";
	}
	else if (temp == WORD(6))
	{
		Arch = "Intel Itanium-based";
	}
	else if (temp == WORD(0))
	{
		Arch = "x86";
	}
	else if (temp == WORD(0xffff))
	{
		Arch = "Unknown architecture";
	}
	return Arch;
}

string DefineProcessorType(int defProcType)
{
	string Type = "";

	return Type;
}

int main() {
	setlocale(LC_ALL, "Russian");
	CString winDir;
	CString winTempDir;
	SYSTEM_INFO systemInfo;
	MEMORYSTATUSEX memoryInfo;
	memoryInfo.dwLength = sizeof(memoryInfo);
	if (GetWindowsDirectory(winDir.GetBuffer(MAX_PATH), MAX_PATH) != 0);
	GetTempPath(MAX_PATH, winTempDir.GetBuffer(MAX_PATH));
	GetSystemInfo(&systemInfo);
	GlobalMemoryStatusEx(&memoryInfo);
	_tprintf(_T("%s\n"), (LPCTSTR)winDir);
	_tprintf(_T("%s\n"), (LPCTSTR)winTempDir);
	_tprintf(TEXT("Количество ядер процессора: %u\n"), systemInfo.dwNumberOfProcessors);

	WORD defArchitec = systemInfo.wProcessorArchitecture;

	_tprintf(_T("Архитектура процессора: %s\n"), (LPCTSTR)(CString)(DefineProcessorArch(defArchitec).c_str()));
	_tprintf(_T("MinimumApplicationAddress: %lp\n"), (LPCTSTR)systemInfo.lpMinimumApplicationAddress);
	_tprintf(_T("MaximumApplicationAddress: %lp\n"), (LPCTSTR)systemInfo.lpMaximumApplicationAddress);
	_tprintf(_T("Memory phys: %llu \n"), memoryInfo.ullAvailPhys);
	_tprintf(_T("Memory virtual: %llu \n"), memoryInfo.ullTotalPageFile);

	return 0;
}