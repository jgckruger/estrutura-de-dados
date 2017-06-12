#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
#include <locale>

using namespace std;

struct noPag{
    int pagina;
    struct noPag *prox;
};

struct no{
    string dado;
    struct noPag *lista;
    struct no *esq;
    struct no *dir;
    int cont;
};

ifstream arquivo;
struct no *raiz=NULL;
const int maxLinhas=3;


bool vazia()
{
    if(raiz==NULL)
        return true;
    return false;
}

struct noPag *ultimoLista(struct noPag *lista)
{
    struct noPag *atual=lista;
    if(lista!=NULL)
        while(atual->prox != NULL)
            atual=atual->prox;
    return atual;
}

void insereArvore(string valor, int pagAtual)
{
    struct no *atual, *anterior, *aux;
    aux=new (struct no);
    aux->dado=valor;
    aux->esq=aux->dir=NULL;

    if(vazia())
    {
        raiz = aux;
        aux->cont=1;
        aux->lista=new (struct noPag);
        aux->lista->pagina=pagAtual;
        aux->lista->prox=NULL;
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
            struct noPag *ultimo=ultimoLista(atual->lista);
            if(ultimo->pagina!=pagAtual){
                ultimo->prox=new(struct noPag);
                ultimo->prox->pagina=pagAtual;
                ultimo->prox->prox=NULL;
            }
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
    aux->lista=new (struct noPag);
    aux->lista->pagina=pagAtual;
    aux->lista->prox=NULL;

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
        cout << endl << endl;
        cout << "Palavra: " << node->dado<< endl;
        cout << "Número de vezes em que apareceu: " << node->cont  << endl;
        cout << "Páginas: " << endl << "    ";
        struct noPag *atual=node->lista;
        while(atual!=NULL)
        {
            cout << atual->pagina;
            atual=atual->prox;
            if(atual!=NULL)// APENAS PARA FINS ESTÉTICOS
                cout << ", ";
        }
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
    int pagAtual=1, linhasPagAtual=1;
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
                if(temp=='\n'){
                    numlinhas++;
                    linhasPagAtual++;
                }
                i++;
                //cout << palavra<<endl;
                if(!palavra.empty())
                    insereArvore(palavra, pagAtual);
                if(linhasPagAtual>maxLinhas) // Estourou o limite de linhas por página
                {
                    pagAtual++;
                    linhasPagAtual=1;
                }
                i=0;
                palavra.clear();
            }
        }
        em_ordem(raiz);
        cout << endl << "Número de linhas: " << numlinhas << endl;
        cout << endl << "Número de páginas: " << pagAtual << endl;
    }
    arquivo.close();
    return 0;
}
