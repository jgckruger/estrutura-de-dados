#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

const int TAM = 13;
const int NUMVEZES = 5;

struct no
{
    int dado;
    struct no *prox;
};
struct no *vetorHash[TAM];
int chave;

void preencheVetor(struct no * v[])
{
    for(int i=0; i < TAM; i++)
        v[i]=NULL;
}

int h(int chave)
{
    return chave%TAM;
}


void insere(int chave)
{
    int pos  = h(chave);
    struct no *aux;
    aux = new(struct no);
    aux->dado=chave;
    aux->prox=vetorHash[pos];
    vetorHash[pos]=aux;
}

int busca(int chave)
{
    int pos  = h(chave);
    struct no *atual=vetorHash[pos];
    int col;

    while(1)
    {
        if(atual==NULL)
            break;
        else
            if(atual->dado!=chave){
                atual=atual->prox;
                col++;
            }
            else
                break;
    }
    if(atual!=NULL && atual->dado==chave)
    {
        cout << "Achou " << endl << "Colisoes " << col << endl;
        return col;
    }
    cout << "Não achou" << endl << "Colisoes " << col << endl;
    return col;
}

void deleta(int chave)
{
    int pos  = h(chave);
    struct no *atual=vetorHash[pos];
    struct no *anterior=NULL;

    while(1)
    {
        if(atual==NULL)//nao tem
            return;
        else
            if(atual->dado!=chave){
                anterior=atual;
                atual=atual->prox;
            }
            else
            {
                if(anterior==NULL)
                    vetorHash[pos]=atual->prox;
                else
                    anterior->prox=atual->prox;
                delete(atual);
                return;
            }
    }
}

void imprime()
{
    struct no *atual;

    for(int i=0; i<TAM; i++)
    {
        atual=vetorHash[i];
        while(atual!=NULL)
        {
            cout << atual->dado << " ";
            atual=atual->prox;
        }
        cout << endl;
    }
}


int main()
{
    int contCol=0;
    preencheVetor(vetorHash);
    srand(45);
    for(int i=0; i<NUMVEZES; i++)
        insere(rand());
            insere((5926+1)*2);
    for(int i=0; i<NUMVEZES; i++)
        contCol+=busca(rand());
    imprime();
    deleta(11854);
    imprime();
    cout << contCol/NUMVEZES;
    return 0;
}
