#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
int main()
{
    srand((unsigned int)time(NULL));
    for (int i = 1; i <= 500;i++)
    {
        cout << rand() % 10<<endl;
    }
}