#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;
bool habilitaImpressao=true;

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
    srand(1337);
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

// BUSCA SEQUENCIAL PARA VETORES

void buscaSequencial(int v[], int TAMLista,int chave) // BUSCA SEQUENCIAL NORMAL
{
    for(int i=0; i<TAMLista; i++)
        if(v[i]==chave)
        {
            cout << "Achou " << chave << "na posição " << i << endl;
            return;
        }
    cout << "Não achou" << endl;
}

void buscaSequencialComSentinela(int v[], int TAMLista, int chave) // BUSCA SEQUENCIAL COM SENTINELA
{
    int i;
    v[TAMLista]=chave;
    for(i=0; v[i]!= chave; i++);
    if(i!=TAMLista)
        cout << "Achou " << chave << "na posição " << i << endl;
    else
        cout << "Não achou" << endl;
}

void buscaSequencialMoverPraFrente(int v[], int TAMLista, int chave) // BUSCA SEQUENCIAL COM SENTINELA E MOVER PRA FRENTE
{
    int i;
    v[TAMLista]=chave;
    for(i=0; v[i]!= chave; i++);
    if(i!=TAMLista){
        cout << "Achou " << chave << "na posição " << i << endl;
        for(i; i > 0; i--)
            v[i]=v[i-1];
        v[0]=chave;
    }
    else
        cout << "Não achou" << endl;
}

void buscaSequencialTransposicao(int v[], int TAMLista, int chave) // BUSCA SEQUENCIAL COM SENTINELA E TRANSPOSICAO
{
    int i;
    v[TAMLista]=chave;
    for(i=0; v[i]!= chave; i++);
    if(i!=TAMLista){
        cout << "Achou " << chave << "na posição " << i << endl;
        if(i!=0)
            troca(v[i], v[i-1]);
    }
    else
        cout << "Não achou" << endl;
}

// BUSCA SEQUENCIAL PARA LISTA ENCADEADA
struct no
{
    int dado;
    struct no *prox;
};

struct no *lista=NULL;

void geraLista(int tamanho)
{
    struct no *aux;
    int i=0;
    srand(1337);
    while(i<tamanho)
    {
        aux=new(struct no);
        aux->dado=rand();
        aux->prox=lista;
        lista=aux;
        i++;
    }
}

bool vazia()
{
    if(lista==NULL)
    {
        return true;
    }
    return false;
}

void imprime()
{
    struct no *aux=lista;
    if(vazia())
    {
        cout << "Lista vazia" << endl;
        return;
    }
    while(aux!=NULL)
    {
        cout << aux->dado << " ";
        aux=aux->prox;
    }
    cout << endl;
}

void buscaSequencialListaEncadeada(int chave) // BUSCA SEQUENCIAL NORMAL
{
    struct no*aux=lista;
    int i=0;
    if(vazia())
    {
        cout << "Lista vazia" << endl;
        return;
    }
    while(aux!=NULL)
    {
        if(aux->dado==chave)
        {
            cout << "Achou " << chave << " na posição " << i << endl;
            return;
        }
        i++;
        aux=aux->prox;
    }
    cout << "Não achou" << endl;
}

void buscaSequencialComMoverPraFrenteListaEncadeada(int chave) // BUSCA SEQUENCIAL COM MOVER PRA FRENTE
{
    struct no*anterior=NULL;
    struct no*aux=lista;
    int i=0;
    if(vazia())
    {
        cout << "Lista vazia" << endl;
        return;
    }
    while(aux!=NULL)
    {
        if(aux->dado==chave)
        {
            cout << "Achou " << chave << " na posição " << i << endl;
            if(i!=0){
                anterior->prox=aux->prox;
                aux->prox=lista;
                lista=aux;
            }
            return;
        }
        i++;
        anterior=aux;
        aux=aux->prox;
    }
    cout << "Não achou" << endl;
}

int main()
{
    int TAM=10;
    int vet[TAM+1]; // POR CAUSA DA SENTINELA
    int TAMLista=10;

    preencheVetor(vet, TAMLista);
    imprimeVetor(vet, TAMLista);

    cout << endl << endl;
    buscaSequencial(vet, TAMLista, 4404);
    imprimeVetor(vet, TAMLista);
    cout << endl << endl << endl << endl;
    buscaSequencialComSentinela(vet, TAMLista, 4404);
    imprimeVetor(vet, TAMLista);
    cout << endl << endl << endl << endl;
    buscaSequencialMoverPraFrente(vet, TAMLista, 17763);
    imprimeVetor(vet, TAMLista);
    cout << endl << endl << endl << endl;
    buscaSequencialTransposicao(vet, TAMLista, 4404);
    imprimeVetor(vet, TAMLista);

    cout << endl << endl << endl << endl;
    cout << endl << endl << endl << endl;

    imprime();
    geraLista(10);
    imprime();
    buscaSequencialListaEncadeada(4113);
    buscaSequencialComMoverPraFrenteListaEncadeada(4113);
    imprime();


    return 0;
}
