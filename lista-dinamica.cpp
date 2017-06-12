#include <iostream>
#include <clocale>

using namespace std;

struct no
{
    int dado;
    struct no *prox;
};

struct no *lista=NULL;

void insereLista(int valor)
{
    struct no *anterior;
    struct no *atual;
    struct no *aux;
    anterior = NULL;
    atual = lista;
    aux = new(struct no);
    aux->dado = valor;

    while(atual!=NULL && valor>atual->dado)
    {
        anterior = atual;
        atual=atual->prox;
    }
    if(anterior != NULL)
    {
        anterior->prox=aux;
        aux->prox=atual;
        return;
    }
    lista=aux;
    lista->prox=NULL;
}

bool vazia()
{
    if(lista==NULL)
    {
        return true;
    }
    return false;
}

void recupera(int pos)
{
    struct no *aux=lista;
    int i, j;
    if(vazia())
    {
        cout << "Lista vazia" << endl;
        return;
    }
    for(i=0; i<pos && aux->prox!=NULL;i++)
    {
        aux=aux->prox;
    }
    if(aux->prox!=NULL)
    {
        cout << "Valor da posição " << pos << " é: " << aux->dado << endl;
        return;
    }
    cout << "Posição inexistente" << endl;
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
        cout << aux->dado << endl;
        aux=aux->prox;
    }
}

void buscaLista(int valor)
{
    struct no *aux=lista;
    int pos=0;
    if(vazia())
    {
        cout << "Lista vazia" << endl;
        return;
    }
    while(aux!=NULL)
    {
        if(valor==aux->dado)
        {
            cout << "Valor encontrado na posição: " << pos << endl;
            return;
        }
        aux=aux->prox;
        pos++;
    }
}

void buscaRepetidosLista(int valor)
{
    struct no *aux=lista;
    int pos=0;
    if(vazia())
    {
        cout << "Lista vazia" << endl;
        return;
    }
    while(aux!=NULL)
    {
        if(valor==aux->dado)
            cout << "Valor encontrado na posição: " << pos << endl;
        aux=aux->prox;
        pos++;
    }
}

void removeLista(int valor)
{
    struct no *anterior;
    struct no *atual;
    struct no *aux;
    anterior = NULL;
    atual = lista;

    if(vazia())
    {
        cout << "Lista vazia" << endl;
        return;
    }
    if(valor==atual->dado)
    {
        lista=atual->prox;
        delete(atual);
        cout << "Elemento excluido" << endl;
        return;
    }
    while(atual!=NULL && valor!=atual->dado)
    {
        anterior = atual;
        atual=atual->prox;
        if(valor<atual->dado)
            break;
    }
    if(atual!=NULL && valor==atual->dado)
    {
        anterior->prox=atual->prox;
        delete(atual);
        cout << "Elemento excluido" << endl;
        return;
    }
    cout << "Elemento não encontrado" << endl;
}

void removeRepetidosLista(int valor)
{
    struct no *anterior;
    struct no *atual;
    struct no *aux;
    anterior = NULL;
    atual = lista;
    bool encontrou=false;

    if(vazia())
    {
        cout << "Lista vazia" << endl;
        return;
    }
    while(!vazia() && valor==lista->dado)
    {
        aux=lista;
        atual=lista->prox;
        lista=lista->prox;
        delete(aux);
        cout << "Elemento deletado" << endl;
        encontrou=true;
    }
    while(atual!=NULL && atual->dado <= valor)
    {
        if(valor==atual->dado)
        {
            anterior->prox=atual->prox;
            delete(atual);
            atual=anterior;
            encontrou=true;
            cout << "Elemento excluido" << endl;
        }
        anterior = atual;
        atual=atual->prox;
    }
    if(!encontrou)
        cout << "Elemento não encontrado" << endl;
    if(vazia())
        cout << "Lista esvaziada" << endl;
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    imprime();

    insereLista(1);
    insereLista(1);
    insereLista(2);
    insereLista(2);
    //imprime();

    //recupera(90);

    //buscaLista(2);
    //buscaRepetidosLista(2);

    //removeLista(1);
    //imprime();

    //buscaRepetidosLista(2);
    //removeLista(2);
    //removeLista(2);
    //imprime();

    //removeLista(2);

    imprime();
    removeRepetidosLista(1);
    removeRepetidosLista(2);
    imprime();

    return 0;
}
