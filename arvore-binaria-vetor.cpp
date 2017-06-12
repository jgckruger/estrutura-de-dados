#include <iostream>

using namespace std;

struct no{
    int dado;
    bool usado;
};

const int TAM = 7;
struct no arvore[TAM];

void zeraArvore()
{
    for(int i=0; i<TAM; i++)
    {
        arvore[i].dado=0;
        arvore[i].usado=false;
    }
}

void em_ordem(int pos)
{
    if(pos<TAM && arvore[pos].usado)
    {
        em_ordem(2*pos+1);
        cout << arvore[pos].dado << " " << endl;
        em_ordem(2*pos+2);
    }
}

void insereArvore(int valor)
{
    int atual=0;
    while(atual<TAM && arvore[atual].usado)
    {
        if(arvore[atual].dado>valor)
            atual=atual*2+1;
        else
            atual=atual*2+2;
    }
    if(atual>=TAM)
    {
        cout << "Elemento não inserido" << endl;
        return;
    }
    arvore[atual].usado=true;
    arvore[atual].dado=valor;
    cout << "Elemento inserido" << endl;
}

void insereArvoreSemRepetidos(int valor)
{
    int atual=0;
    bool achou_igual=false;
    while(atual<TAM && !achou_igual && arvore[atual].usado)
    {
        if(arvore[atual].dado>valor)
            atual=atual*2+1;
        else if(arvore[atual].dado==valor)
            achou_igual=true;
        else
            atual=atual*2+2;
    }
    if(!achou_igual)
    {
        arvore[atual].usado=true;
        arvore[atual].dado=valor;
        cout << "Elemento inserido" << endl;
    }
    else
        cout << "Elemento repetido" << endl;
}

bool vazia()
{
    return !arvore[0].usado;
}

void buscaArvore(int valor)
{
    int atual=0;
    bool achou=false;

    while(atual<TAM && arvore[atual].usado && !achou)
    {
        if(arvore[atual].dado>valor)
            atual=atual*2+1;
        else if(arvore[atual].dado==valor)
            achou=true;
        else
            atual=atual*2+2;
    }
    if(achou)
        cout << "Elemento encontrado" << endl;
    else
        cout << "Elemento não encontrado" << endl;
}

int main()
{
    zeraArvore();
    insereArvoreSemRepetidos(5);
    insereArvoreSemRepetidos(4);
    insereArvoreSemRepetidos(6);
    insereArvoreSemRepetidos(7);
    insereArvoreSemRepetidos(6);
    buscaArvore(13);
    buscaArvore(7);
    em_ordem(0);


    return 0;
}
