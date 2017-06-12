#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
#include <locale>

using namespace std;

struct no{
    string dado;
    struct no *esq;
    struct no *dir;
    int cont;
};

ifstream arquivo;
struct no *raiz=NULL;

bool vazia()
{
    if(raiz==NULL)
        return true;
    return false;
}

void insereArvore(string valor)
{
    struct no *atual, *anterior, *aux;
    aux=new (struct no);
    aux->dado=valor;
    aux->esq=aux->dir=NULL;

    if(vazia())
    {
        raiz = aux;
        aux->cont=1;
        cout << "Arvore criada, elemento inserido" << endl;
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
            cout << "Elemento inserido, aumentado o contador" << endl;
            atual->cont++;
            return;
        }
        else
            atual=atual->dir;
    }

    if(valor<anterior->dado)
        anterior->esq=aux;
    else
        anterior->dir=aux;
    aux->cont=1;

    cout << "Elemento inserido" << endl;
}

void buscaArvore(string valor)
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
            cout << "Elemento encontrado" << endl;
            return;
        }
        else
            atual=atual->dir;
    }

    cout << "Elemento não encontrado" << endl;
}

void em_ordem(struct no *node)
{
    if(node!=NULL)
    {
        em_ordem(node->esq);
        cout << node->dado << " - " << node->cont  << endl;
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

bool abreArquivo()
{
    arquivo.open("texto.txt");
    if(!arquivo.is_open())
    {
        cout << "Erro" << endl;
        return false;
    }
    return true;
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int numlinhas=0, i=0;
    char temp;
    string palavra;
    if(abreArquivo())
    {
        numlinhas++;
        while(!arquivo.eof())
        {
            temp=arquivo.get();
            if(isalpha(temp))
            {
                tolower(temp);
                palavra.push_back(temp);
                //cout << palavra[i];
            }
            else
            {
                if(temp=='\n')
                    numlinhas++;
                i++;
                //cout << palavra<<endl;
                if(!palavra.empty())
                    insereArvore(palavra);
                i=0;
                palavra.clear();
            }
        }

        em_ordem(raiz);
        cout << endl << "Número de linhas: " << numlinhas << endl;
    }

    return 0;
}
