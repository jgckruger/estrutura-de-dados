//#include <cstdio>
#include <iostream>

using namespace std;

const int TAM = 5;
int A[TAM], B[TAM];

int main()
{
    for(int i=0;i<TAM;i++)
        cin >> A[i];
    for(int i=0;i<TAM;i++)
        B[i]=A[TAM-1-i];
    for(int i=0;i<TAM;i++)
        cout << B[i];

    return 0;
}
