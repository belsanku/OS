#include <windows.h>
#include <conio.h>
#include <iostream>

using namespace std;
 

typedef void (*VoidReturnFunc)();
 
int main()
{
   HINSTANCE a = LoadLibrary(TEXT("lib1"));
   VoidReturnFunc myFunc;
   VoidReturnFunc myFunc1;
   myFunc = (VoidReturnFunc) GetProcAddress(a, "Kuka");
   myFunc1 = (VoidReturnFunc) GetProcAddress(a, "Buka");
   myFunc();
   myFunc1();
   int exit = 0;
   cin>>exit;
   getch();
   system("pause");
   return 0;
}