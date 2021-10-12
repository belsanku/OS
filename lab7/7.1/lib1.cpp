#include <iostream>
#include "lab1.h"

using namespace std;
extern "C" __declspec(dllexport) void __stdcall Kuka()
{
   for(int i = 0; i < 5; i++)
   {
      cout << i << "sasha";
      cout << endl;
   }
}

extern "C" __declspec(dllexport) void __stdcall Buka()
{
   for(int i = 0; i < 3; i++)
   {
      cout << i << "Roma";
      cout << endl;
   }
}