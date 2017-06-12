//#include <cstdio>
#include <iostream>

using namespace std;

const int TAM = 5;
int A[TAM], B[TAM];

int main()
{
    int comp, j =0;
    for(int i=0;i < TAM; i++)
        cin >> A[i];
    cout << endl << "Informe o valor para filtrar para o vetor B: ";
    cin >> comp;
    for(int i=0; i < TAM; i++)
        if(A[i]>comp)
        {
            B[j]=A[i];
            j++;
        }

    for(int i=0; i < j; i++)
        cout << B[i] << endl;
    return 0;
}
