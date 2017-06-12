#include <iostream>

using namespace std;

struct no
{
    string tipo;
    union
    {
        char operador;
        int operando;
    };
    struct no *dir;
    struct no *esq;
};

int opera(char operador, int a, int b)
{
    switch(operador)
    {
    case '+':
    {
        return a+b;
        break;
    }
    case '-':
    {
        return a-b;
        break;
    }
    case '*':
    {
        return a*b;
        break;
    }
    case '/':
    {
        return a/b;
        break;
    }
    }
}

int resolve(struct no *atual)
{
    int operando1, operando2, resultado;
    if (atual->tipo=="OPERADOR")
    {
        operando1 = resolve(atual->esq);
        operando2 = resolve(atual->dir);
        resultado = opera(atual->operador,operando1,operando2);
        return resultado;
    }
    else return atual->operando;
}

struct no *criaOperando(int valor)
{
    struct no *aux;
    aux=new(struct no);
    aux->tipo="OPERANDO";
    aux->operando=valor;
    aux->esq=NULL;
    aux->dir=NULL;

    return aux;
}

struct no *criaEquacao(char operador, struct no *esq, struct no *dir)
{
    struct no *aux;
    aux=new(struct no);
    aux->tipo="OPERADOR";
    aux->operador=operador;
    aux->esq=esq;
    aux->dir=dir;

    return aux;
}

void emOrdem(struct no *atual)
{
    if(atual!=NULL)
    {
        emOrdem(atual->esq);
        if(atual->tipo=="OPERADOR")
            cout << atual->operador << " ";
        else
            cout << atual->operando << " ";
        emOrdem(atual->dir);
    }
}

void preOrdem(struct no *atual)
{
    if(atual!=NULL)
    {
        if(atual->tipo=="OPERADOR")
            cout << atual->operador << " ";
        else
            cout << atual->operando << " ";
        preOrdem(atual->esq);
        preOrdem(atual->dir);
    }
}

void posOrdem(struct no *atual)
{
    if(atual!=NULL)
    {
        posOrdem(atual->esq);
        posOrdem(atual->dir);
        if(atual->tipo=="OPERADOR")
            cout << atual->operador << " ";
        else
            cout << atual->operando << " ";
    }
}



int main()
{
    struct no *operando1, *operando2, *operando3, *operando4, *operando5;
    struct no *operador1, *operador2, *operador3, *operador4;
    struct no *raiz;

    operando1 = criaOperando(5);
    operando2 = criaOperando(2);
    operando3 = criaOperando(6);
    operando4 = criaOperando(2);
    operando5 = criaOperando(4);

    operador1 = criaEquacao('-',operando1,operando2);
    operador2 = criaEquacao('+',operando3,operando4);
    operador3 = criaEquacao('*',operador1,operador2);

    raiz = criaEquacao('-',operador3,operando5);

    cout << resolve(raiz)<< endl;

    return 0;
}
