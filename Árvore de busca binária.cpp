#include <iostream>

using namespace std;

struct no{
    int dado;
    struct no *esq;
    struct no *dir;
};

struct no *raiz=NULL;

bool vazia()
{
    if(raiz==NULL)
        return true;
    return false;
}

void insereArvore(int valor)
{
    struct no *atual, *anterior, *aux;
    aux = new (struct no);
    aux->dado=valor;
    aux->esq=aux->dir=NULL;

    if(vazia())
    {
        raiz = aux;
        cout << "Elemento inserido" << endl;
        return;
    }

    atual=raiz;

    while(atual!=NULL)
    {
        anterior=atual;
        if(valor<atual->dado)
            atual=atual->esq;
        else
            atual=atual->dir;
    }

    if(valor<anterior->dado)
        anterior->esq=aux;
    else
        anterior->dir=aux;

    cout << "Elemento inserido" << endl;
}

void insereArvoreSemRepetidos(int valor)
{
    struct no *atual, *anterior, *aux;
    aux=new (struct no);
    aux->dado=valor;
    aux->esq=aux->dir=NULL;

    if(vazia())
    {
        raiz = aux;
        cout << "Elemento inserido" << endl;
        return;
    }

    atual=raiz;

    while(atual!=NULL)
    {
        anterior=atual;
        if(valor<atual->dado)
            atual=atual->esq;
        else if(valor==atual->dado)
        {
            cout << "Valor repetido, não foi inserido" << endl;
            return;
        }
        else
            atual=atual->dir;
    }

    if(valor<anterior->dado)
        anterior->esq=aux;
    else
        anterior->dir=aux;

    cout << "Elemento inserido" << endl;
}

void buscaArvore(int valor)
{
    struct no *atual, *anterior;

    if(vazia())
    {
        cout << "Elemento não encontrado: Lista vazia" << endl;
        return;
    }

    atual=raiz;

    while(atual!=NULL)
    {
        anterior=atual;
        if(valor<atual->dado)
            atual=atual->esq;
        else if(valor==atual->dado)
        {
            cout << "Valor encontrado" << endl;
            return;
        }
        else
            atual=atual->dir;
    }

    cout << "Valor não encontrado" << endl;
}

void em_ordem(struct no *node)
{
    if(node!=NULL)
    {
        em_ordem(node->esq);
        cout << node->dado << " ";
        em_ordem(node->dir);
    }
}

void apagaArvore(struct no *node)
{
    if(node!=NULL)
    {
        apagaArvore(node->esq);
        apagaArvore(node->dir);
        if(node==raiz)
            raiz=NULL;
        delete (node);
    }
}

int main()
{
    insereArvore(10);
    insereArvore(5);
    insereArvore(9);
    insereArvore(11);
    insereArvore(13);
    insereArvoreSemRepetidos(5);
    insereArvoreSemRepetidos(14);
    buscaArvore(5);
    buscaArvore(16);
    buscaArvore(2);
    em_ordem(raiz);
    apagaArvore(raiz);
    em_ordem(raiz);


    return 0;
}
