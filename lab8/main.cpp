#include <iostream>
#include <string>
#include <inttypes.h>
#include <windows.h>
#include <thread>

using namespace std;

int cow = 0;

void powTwo(int counter)
{
    for (size_t i = 0; i < counter; i++)
    {
        cow+=2;
    }
}

int main(void)
{
    cow = 0;
    std::thread testThread1(powTwo, 100000);
    std::thread testThread2(powTwo, 100000);
    std::thread testThread3(powTwo, 100000);

    printf("id:%" PRIu32 "\nid:%" PRIu32 "\nid:%" PRIu32 "\n",
           (*(uint32_t *)&testThread1.get_id()),
           (*(uint32_t *)&testThread2.get_id()),
           (*(uint32_t *)&testThread3.get_id()));

    testThread1.join();
    testThread2.join();
    testThread3.join();

    cout << "Theoretical: " << 600000 << "\n";
    cout << "Practice: " << cow << "\n";

    return EXIT_SUCCESS;
}
