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

void heapify(int v[], int TAM, int tamHeap, int atual)
{
    int esq=2*atual+1;
    int dir=2*atual+2;
    int maior;

    if(esq<tamHeap && v[esq]>v[atual])
        maior=esq;
    else
        maior=atual;
    if(dir<tamHeap && v[dir]>v[maior])
        maior=dir;
    if(maior!=atual)
    {
        troca(v[atual], v[maior]);
        heapify(v,TAM,tamHeap,maior);
    }
}

void buildHeap(int v[], int TAM)
{
    int tamHeap=TAM;
    for(int i=(TAM/2)-1; i>=0;i--)
        heapify(v,TAM,tamHeap,i);
}

void heapSort(int v[], int TAM)
{
    int tamHeap = TAM;
    buildHeap(v, TAM);
    for(int i=TAM-1; i>=1; i--)
    {
        troca(v[0],v[i]);
        tamHeap--;
        heapify(v, TAM, tamHeap, 0);
    }
}

void selectionSort(int v[], int TAM)
{
    int atual;
    for(int i=0;i<TAM-1;i++)
    {
        atual=i;
        for(int j=i+1;j<TAM;j++){
            if(v[atual]>v[j])
            {
                atual=j;
            }
        }
        troca(v[i],v[atual]);
    }
}


int main()
{
    int TAM=10;
    int vet[TAM];
    clock_t tempo2, tempo1;

    cout << "Heap Sort: " << endl;
    preencheVetor(vet, TAM);
    imprimeVetor(vet, TAM);
    cout << endl << endl;
    tempo1=clock();
    heapSort(vet, TAM);
    tempo2=clock();
    imprimeVetor(vet, TAM);
    cout << "Tempo decorrido: " << (float)(tempo2-tempo1)/CLOCKS_PER_SEC<< endl;



    cout << endl << endl << endl << endl;

    cout << "Selection Sort: " << endl;
    preencheVetor(vet, TAM);
    imprimeVetor(vet, TAM);
    cout << endl << endl;
    tempo1=clock();
    selectionSort(vet, TAM);
    tempo2=clock();
    imprimeVetor(vet, TAM);
    cout << "Tempo decorrido: " << (float)(tempo2-tempo1)/CLOCKS_PER_SEC<< endl;



    return 0;
}
