#include <iostream>

using namespace std;

const int TAM = 13;

int hash1[TAM];
int tamHash1 = 0;
int hash2[TAM];
int tamHash2 = 0;
int chave;

void preencheVetor(int v[])
{
    for(int i=0; i < TAM; i++)
        v[i]=-1;
}

void imprimeVetor(int v[])
{
    for(int i=0; i < TAM; i++)
        cout << v[i] << endl;
}
int h(int chave)
{
    return chave%TAM;
}

int rh1(int posAtual)
{
    int pos = (posAtual + 1)%TAM;
    return pos;
}

int rh2(int posAtual)
{
    int aux = 1+ h(chave)%(TAM-1);
    int pos = (posAtual + aux)%TAM;
    return pos;
}


void insere(int chave, int vetorHash[], int tamHash, int (*reHash)(int))  // manda funcao de reespalhamento
{
    int pos  = h(chave);
    if(tamHash == TAM)
    {
        cout << "Hash cheia " << endl;
        return;
    }
    tamHash++;
    if(vetorHash[pos]==-1)
        vetorHash[pos]=chave;
    else
    {
        do
        {
            pos =(*reHash)(h(chave));
        }
        while(vetorHash[pos] != -1);
        vetorHash[pos]=chave;
    }
    cout << "Inseriu" << endl;
}

void buscavoid(int chave, int vetorHash[], int tamHash, int (*reHash)(int))  // manda funcao de reespalhamento
{
    int posAtual= h(chave);
    int numBuscas;
    if(vetorHash[posAtual]==-1)
    {
        cout << "Não achou" << endl;
        return;
    }
    while(numBuscas == TAM || vetorHash[posAtual] == -1)
    {
        if(vetorHash[posAtual]==chave)
        {
            cout << "Achou" << endl;
            return;
        }
        else
        {
            posAtual =(*reHash)(posAtual);
        }
        numBuscas++;
    }
    if(numBuscas == TAM || vetorHash[posAtual] == -1)
        cout << "Elemento não encontrado" << endl;
}

int main()
{
    preencheVetor(hash1);
    preencheVetor(hash2);

    chave = 5;
    insere(chave,hash1, tamHash1, rh1);
    chave = 3;
    insere(chave,hash1, tamHash1, rh1);
    chave = 25;
    insere(chave,hash1, tamHash1, rh1);

    imprimeVetor(hash1);

    chave = 5;
    insere(chave,hash2, tamHash2, rh2);
    chave = 3;
    insere(chave,hash2, tamHash2, rh2);
    chave = 25;
    insere(chave,hash2, tamHash2, rh2);

    imprimeVetor(hash2);
    return 0;
}
