#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void troca(int &a, int &b)
{
    int c;
    c=a;
    a=b;
    b=c;
}

void bubbleSort(int v[], int TAM)
{
    int passado=0;
    bool ordenado=false;

    while(!ordenado && passado<TAM)
    {
        ordenado=true;
        for(int i=0; i <TAM-passado-1;i++)
            if(v[i]>v[i+1])
            {
                troca(v[i],v[i+1]);
                ordenado=false;
            }
        passado++;
    }
}

int divide(int v[], int TAM, int inicio, int fim)
{
    int pivo=v[inicio];
    int i=inicio-1;
    int j=fim+1;
    while(true)
    {
        do
            j--;
        while(v[j]>pivo); // Pula os maiores que o pivo na direita

        do
            i++;
        while(v[i]<pivo); // Pula os menores que o pivo na esquerda

        if(i<j)
            troca(v[i], v[j]); // Joga número maior que o pivô para a direita
        else
            return j; // Passou, divide vetor no meio
    }
}

void quickSort(int v[], int TAM, int inicio, int fim)
{
    if(inicio < fim)
    {
        int meio=divide(v, TAM, inicio, fim);
        quickSort(v, TAM, inicio, meio);
        quickSort(v, TAM, meio+1, fim);
    }
}

void preencheVetor(int v[], int TAM)
{
    srand(1337);
    for(int i=0; i < TAM; i++)
        v[i]=rand();
}

void imprimeVetor(int v[], int TAM)
{
    for(int i=0; i < TAM; i++)
        cout << v[i] << " ";
    cout << endl;
}


int main()
{
    int TAM=100000;
    int vet[TAM];
    clock_t tempo2, tempo1;

    cout << "Bubble Sort: " << endl;
    preencheVetor(vet, TAM);
    //imprimeVetor(vet, TAM);
    cout << endl << endl;
    tempo1=clock();
    bubbleSort(vet, TAM);
    tempo2=clock();
    //imprimeVetor(vet, TAM);
    cout << "Tempo decorrido: " << (float)(tempo2-tempo1)/CLOCKS_PER_SEC<< endl;



    cout << endl << endl << endl << endl;

    cout << "Quick Sort: " << endl;
    preencheVetor(vet, TAM);
    //imprimeVetor(vet, TAM);
    cout << endl << endl;
    tempo1=clock();
    quickSort(vet, TAM,0, TAM-1);
    tempo2=clock();
    //imprimeVetor(vet, TAM);
    cout << "Tempo decorrido: " << (float)(tempo2-tempo1)/CLOCKS_PER_SEC<< endl;



    return 0;
}
