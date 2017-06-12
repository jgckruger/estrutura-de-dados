#include <iostream>
#include <ctime>
#include <cstdlib>

/*
Alunos: Pedro M.M.M. Neto
        João G. C. Krüger
Parte 1
*/
using namespace std;
bool habilitaImpressao=false;

// -------- FUNÇÕES UNIVERSAIS --------
inline void troca(int &a, int &b)
{
    int c;
    c=a;
    a=b;
    b=c;
}

void preencheVetor(int v[], int TAM)
{
    srand(NULL);
    for(int i=0; i < TAM; i++)
        v[i]=rand();
}

void imprimeVetor(int v[], int TAM)
{
    if(habilitaImpressao)
    {
        for(int i=0; i < TAM; i++)
            cout << v[i] << " ";
        cout << endl;
    }
}

// -------- ALGORITMOS RÁPIDOS --------

// -----------------------------------
/*
Nome: Quick Sort
Complexidade O(n*log n)
Complexidade no pior caso O(n²) (Má escolha do pivô)
Não Estável (Não mantém a ordem original para os repetidos)
Não é In-place
(Utiliza uma pequena quantia de memória por causa da recursão)
*/

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

// -----------------------------------
/*
Nome: Merge Sort
Complexidade O(n*log n)
Estável (mantém a ordem original para os repetidos)
Não é In-place
(Utiliza um vetor auxiliar com o mesmo tamanho do vetor a ser ordenado, usa o dobro da memória)
*/
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
        for(int i=inicio; i<=fim; i++)
        {
            if(L<=meio && (H>fim || v[L] < v[H]))
            {
                aux[i]=v[L];
                L++;
            }
            else
            {
                aux[i]=v[H];
                H++;
            }
        }
        for(int i=inicio; i<=fim; i++)
        {
            v[i]=aux[i];
        }
    }
}

// -----------------------------------
/*
Nome: Heap Sort
Complexidade O(n*log n)
Não é Estável (Não mantém a ordem original para os repetidos)
In-place (Não usa espaço adicional na memória)
*/
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
    for(int i=(TAM/2)-1; i>=0; i--)
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

// -----------------------------------

// -------- ALGORITMOS LENTOS --------

// -----------------------------------
/*
Nome: Insertion Sort
Complexidade O(n²)
Complexidade O(n) para conjuntos quase ordenados
Estável (mantém a ordem original para os repetidos)
In-place (Não usa espaço adicional na memória)
*/
void insertionSort(int v[], int TAM)
{
    int aux, i;
    bool achou;
    for(int j=1; j<TAM; j++)
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

// -----------------------------------

/*
Nome: Selection Sort
Complexidade O(n²)
Estável mas Pode ser Estável ou não (mantém a ordem original para os repetidos)
In-place (Não usa espaço adicional na memória)
*/
void selectionSort(int v[], int TAM)
{
    int atual;
    for(int i=0; i<TAM-1; i++)
    {
        atual=i;
        for(int j=i+1; j<TAM; j++)
        {
            if(v[atual]>v[j])
            {
                atual=j;
            }
        }
        troca(v[i],v[atual]);
    }
}

// -----------------------------------

/*
Nome: Bubble Sort
Complexidade O(n²)
Complexidade O(n) para conjuntos quase ordenados
Estável (mantém a ordem original para os repetidos)
In-place (Não usa espaço adicional na memória)
*/
void bubbleSort(int v[], int TAM)
{
    int passado=0;
    bool ordenado=false;

    while(!ordenado && passado<TAM)
    {
        ordenado=true;
        for(int i=0; i <TAM-passado-1; i++)
            if(v[i]>v[i+1])
            {
                troca(v[i],v[i+1]);
                ordenado=false;
            }
        passado++;
    }
}

// -----------------------------------

int main()
{

    int TAM=10000;
    int vet[TAM];
    clock_t tempo2, tempo1;

    cout << " -------- ALGORITMOS RÁPIDOS --------" << endl<< endl;

    cout << "Quick Sort: " << endl;
    preencheVetor(vet, TAM);
    imprimeVetor(vet, TAM);
    cout << endl << endl;
    tempo1=clock();
    quickSort(vet, TAM,0, TAM-1);
    tempo2=clock();
    imprimeVetor(vet, TAM);
    cout << "Tempo decorrido: " << (float)(tempo2-tempo1)/CLOCKS_PER_SEC<< endl;

    cout << endl << endl << endl << endl;





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
    cout << endl << endl << endl << endl;





    cout << " -------- ALGORITMOS LENTOS --------" << endl<< endl;

    cout << "Insertion Sort: " << endl;
    preencheVetor(vet, TAM);
    imprimeVetor(vet, TAM);
    cout << endl << endl;
    tempo1=clock();
    insertionSort(vet, TAM);
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

    cout << endl << endl << endl << endl;





    cout << "Bubble Sort: " << endl;
    preencheVetor(vet, TAM);
    imprimeVetor(vet, TAM);
    cout << endl << endl;
    tempo1=clock();
    bubbleSort(vet, TAM);
    tempo2=clock();
    imprimeVetor(vet, TAM);
    cout << "Tempo decorrido: " << (float)(tempo2-tempo1)/CLOCKS_PER_SEC<< endl;

    cout << endl << endl << endl << endl;

    return 0;
}

