#include <iostream>

using namespace std;

const int TAM = 6;

struct no
{
    int dado;
    struct no *prox;
};

int vertice[TAM];
int cont=0;
struct no *arestas[TAM];

struct no *insereLista(struct no *listaVertice1, int v2)
{
    if(listaVertice1!=NULL)
    {
        struct no *aux = listaVertice1;
        while(aux->prox!=NULL)
        {
            if(aux->dado==v2)
            {
                cout << "Aresta Repetida" << endl;
                return listaVertice1;
            }
            aux=aux->prox;
        }
        if(aux->dado==v2)
        {
            cout << "Aresta Repetida" << endl;
            return listaVertice1;
        }
        aux->prox=new(struct no);
        aux->prox->dado=v2;
        aux->prox->prox=NULL;
        cout << "Aresta inserida" << endl;
        return listaVertice1;
    }
    listaVertice1=new(struct no);
    listaVertice1->dado=v2;
    listaVertice1->prox=NULL;
    cout << "Aresta inserida na raiz" << endl;
    return listaVertice1;
}

void insereAresta(int v1, int v2)
{
    for(int i=0; i<cont; i++)
    {
        if(vertice[i]==v1)
        {
            for(int j=0; j < cont; j++)
            {
                if(vertice[j]==v2){
                    arestas[i]=insereLista(arestas[i], v2);
                    return;
                }
            }
            cout << "Vertice 2 inexistente" << endl;
            return;
        }
    }
    cout << "Vertice 1 inexistente" << endl;
}

void insereVertice(int v)
{
    if(cont==TAM)
    {
        cout << "Numero max de vertices atingidos" << endl;
        return;
    }
    for(int i=0; i<cont; i++)
    {
        if(vertice[i]==v)
        {
            cout << "Vertice ja inserido" << endl;
            return;
        }
    }
    vertice[cont]=v;
    cont++;
    cout << "Vertice inserido" << endl;
}

void imprimeGrafo()
{
    for(int i=0; i <cont ; i++)
    {
        cout << vertice[i] << " -> ";
        struct no *aux = arestas[i];
        while(aux != NULL)
        {
            cout << "<" << vertice[i]<< "," << aux->dado << ">";
            aux=aux->prox;
        }
        cout << endl;
    }
}

void removeAresta(int v1, int v2)
{
    int posv1=-1, posv2=-1;
    struct no *ant=NULL, *aux;
    for(int i=0; i<cont;i++){
        if(vertice[i]==v1)
            posv1=i;
        if(vertice[i]==v2)
            posv2=i;
    }
    if(posv1 == -1 || posv2 == -1)
    {
        cout << "Vertice inexistente" << endl;
        return;
    }
    aux=arestas[posv1];
    while(aux!=NULL)
    {
        if(aux->dado==v2)
        {
            if(ant!=NULL)
                ant->prox=aux->prox;
            else
                arestas[posv1]=aux->prox;
            delete(aux);
            cout << "Aresta removida" << endl;
            return;
        }
        ant=aux;
        aux=aux->prox;
    }
    cout << "Aresta inexistente" << endl;
}


int main()
{
    insereVertice(5);
    insereVertice(20);
    insereVertice(10);
    insereVertice(7);
    insereVertice(5);

    insereAresta(5,10);
    insereAresta(5,20);
    insereAresta(7,10);
    insereAresta(7,20);

    imprimeGrafo();

    removeAresta(4,3);
    removeAresta(4,7);
    removeAresta(7,4);
    removeAresta(5,20);
    removeAresta(5,10);
    imprimeGrafo();

    return 0;
}


