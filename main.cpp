#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    int nr = 0;
    clock_t c_start = clock();


    for(int i = 0; i < 100000; i++)
        for(int j = 0; j < 100000; j++)
            nr += i*j;

    clock_t c_end = clock();
    long double time_elapsed_ms = 1000*(c_end-c_start) / CLOCKS_PER_SEC;
    cout << time_elapsed_ms/1000;
    return 0;
}
