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

void mergeSort(int v[], int aux[], int inicio, int fim)
{
    int meio;
    int L, H;
    if(inicio < fim)
    {
        meio=(inicio+fim)/2;
        mergeSort(v, aux, inicio, meio);
        mergeSort(v, aux, meio+1, fim);
        L=inicio;
        H=meio+1;
        for(int i=inicio; i<=fim;i++)
        {
            if(L<=meio && (H>fim || v[L] < v[H])){
                aux[i]=v[L];
                L++;
            }
            else{
                aux[i]=v[H];
                H++;
            }
        }
        for(int i=inicio; i<=fim;i++)
        {
            v[i]=aux[i];
        }
    }
}

void insertionSort(int v[], int TAM)
{
    int aux, i;
    bool achou;
    for(int j=1; j<TAM;j++)
    {
        aux=v[j];
        i=j-1;
        achou=false;
        while(!achou && i>=0)
        {
            if(v[i]>aux)
            {
                troca(v[i+1], v[i]);
                i--;
            }
            else
                achou=true;
        }
    }
}



int main(){

    int TAM=10;
    int vet[TAM];
    clock_t tempo2, tempo1;

    cout << "Merge Sort: " << endl;
    preencheVetor(vet, TAM);
    imprimeVetor(vet, TAM);
    cout << endl << endl;
    tempo1=clock();
    int aux[TAM];
    mergeSort(vet, aux, 0,  TAM-1);
    tempo2=clock();
    imprimeVetor(vet, TAM);
    cout << "Tempo decorrido: " << (float)(tempo2-tempo1)/CLOCKS_PER_SEC<< endl;



    cout << endl << endl << endl << endl;

    cout << "Insertion Sort: " << endl;
    preencheVetor(vet, TAM);
    imprimeVetor(vet, TAM);
    cout << endl << endl;
    tempo1=clock();
    insertionSort(vet, TAM);
    tempo2=clock();
    imprimeVetor(vet, TAM);
    cout << "Tempo decorrido: " << (float)(tempo2-tempo1)/CLOCKS_PER_SEC<< endl;



    return 0;
}
