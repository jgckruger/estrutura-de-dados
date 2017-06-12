#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

const int TAM = 1000;
const int NUMBUSCAS = 1000;
bool habilitaImpressao=false;
int contBinaria=0;
int contSequencial=0;
int contArvoreBinaria=0;
int contArvoreAVL=0;


struct no
{
    int dado;
    struct no *esq;
    struct no *dir;
    int bal; // Não utilizada na árvore de busca binária
};

struct no * raiz = NULL; // Binária
struct no *raiz2=NULL; // AVL

// Funções para vetor
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

// Árvore de busca binária
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
        //cout << "Elemento inserido" << endl;
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

    //cout << "Elemento inserido" << endl;
}

void buscaArvoreBinaria(int valor)
{
    struct no *atual, *anterior;

    if(vazia())
    {
        //cout << "Elemento não encontrado: Lista vazia" << endl;
        return;
    }

    atual=raiz;

    while(atual!=NULL)
    {
        anterior=atual;
        contArvoreBinaria++;
        if(valor<atual->dado)
            atual=atual->esq;
        else
        {
            if(valor==atual->dado)
            {
                //cout << "Valor encontrado" << endl;
                return;
            }
            else
                atual=atual->dir;
        }
    }

    //cout << "Valor não encontrado" << endl;
}

// Árvore AVL

void esquerda(struct no *p)
{

    struct no *q, *hold;

    q = p->dir;
    hold = q->esq;
    q->esq = p;
    p->dir = hold;

}

void direita(struct no *p)
{

    struct no *q, *hold;

    q = p->esq;
    hold = q->dir;
    q->dir = p;
    p->esq = hold;

}

struct no *cria_no(int valor)
{
    struct no *aux = new (struct no);
    aux->dado=valor;
    aux->dir=NULL;
    aux->esq=NULL;
    aux->bal=0;
    return aux;
};


void insere_bal(int chave)
{

    struct no *pp=NULL, *p=raiz2, *pajovem=NULL, *ajovem=raiz2, *q, *filho;
    int imbal;

    if (p==NULL)               /* Arvore vazia */
    {
        raiz2 = cria_no(chave);  /* Funcao para criacao de um novo no */
        return;
    }

    /* Insere chave e descobre ancestral mais jovem a ser desbalanceado */
    while (p!=NULL)
    {
        if (chave < p->dado)
            q = p->esq;
        else q = p->dir;
        if (q!=NULL)
            if (q->bal != 0)
            {
                pajovem=p;
                ajovem=q;
            }
        pp = p;
        p = q;
    }

    q = cria_no(chave);

    if (chave<pp->dado)
        pp->esq=q;
    else pp->dir=q;

    /* Balanceamento de todos os nós entre ajovem e q devem ser ajustados */
    if (chave<ajovem->dado)
        filho = ajovem->esq;
    else filho = ajovem->dir;

    p = filho;

    while (p!=q)
    {
        if (chave < p->dado)
        {
            p->bal=1;
            p=p->esq;
        }
        else
        {
            p->bal = -1;
            p=p->dir;
        }
    }

    if (chave<ajovem->dado)
        imbal = 1;
    else imbal = -1;

    if (ajovem->bal==0)        /*Não houve desbalanceamento */
    {
        ajovem->bal=imbal;
        return;
    }


    if (ajovem->bal!=imbal)     /*Não houve desbalanceamento */
    {
        ajovem->bal=0;
        return;
    }

    /* Houve desbalanceamento */
    if (filho->bal == imbal)
    {
        p=filho;
        if (imbal==1)        /* Faz rotação simples */
            direita(ajovem);
        else esquerda(ajovem);
        ajovem->bal=0;
        filho->bal=0;
    }
    else
    {
        if (imbal==1)  	  /*Faz rotação dupla */
        {
            p=filho->dir;
            esquerda(filho);
            ajovem->esq=p;
            direita(ajovem);
        }
        else
        {
            p=filho->esq;
            direita(filho);
            ajovem->dir=p;
            esquerda(ajovem);
        }
        if (p->bal==0)
        {
            ajovem->bal=0;
            filho->bal=0;
        }
        else
        {
            if (p->bal == imbal)
            {
                ajovem->bal = - imbal;
                filho->bal = 0;
            }
            else
            {
                ajovem->bal = 0;
                filho->bal = imbal;
            }
        }
        p->bal=0;
    }

    if (pajovem == NULL)  /* Ajusta ponteiro do pai do ancestral mais jovem */
        raiz2 = p;
    else if (ajovem==pajovem->dir)
        pajovem->dir = p;
    else pajovem->esq = p;

    return;
}

void buscaArvoreAVL(int valor)
{
    struct no *atual=raiz2;

    if(raiz2==NULL)
    {
        //cout << "Elemento não encontrado: Lista vazia" << endl;
        return;
    }

    while(atual!=NULL)
    {
        contArvoreAVL++;
        if(valor==atual->dado)
        {
            //cout << "Valor encontrado" << endl;
            return;
        }
        else
        {
            if(valor<atual->dado)
                atual=atual->esq;
            else
                atual=atual->dir;
        }
    }
    //cout << "Valor não encontrado" << endl;
}


void insereArvoreAVL(int v[], int TAM)
{
    for(int i=0; i < TAM; i++)
    {
        insere_bal(v[i]);
    }
}

void insereArvoreBinaria(int v[], int TAM)
{
    for(int i=0; i < TAM; i++)
    {
        insereArvore(v[i]);
    }
}

void buscaSequencial(int v[], int TAMLista,int chave) // BUSCA SEQUENCIAL NORMAL
{
    for(int i=0; i<TAMLista; i++)
    {
        contSequencial++;
        if(v[i]==chave)
        {
            //cout << "Achou " << chave << "na posição " << i << endl;
            return;
        }
    }
    //cout << "Não achou" << endl;
}

void buscaBinaria(int v[], int TAM, int chave)
{
    int inicio=0;
    int fim=TAM-1;
    int meio;

    while(inicio<=fim)
    {
        meio=(inicio+fim)/2;
        contBinaria++;
        if(chave==v[meio])
        {
            //cout << "Achou" << endl;
            return;
        }
        if(chave<v[meio])
            fim=meio-1;
        else
            inicio=meio+1;
    }
    //cout << "Não achou" << endl;
}

int divide(int v[], int TAM, int inicio, int fim)
{
    int pivo=v[inicio];
    int i=inicio-1;
    int j=fim+1;
    while(true)
    {
        do
            j--;
        while(v[j]>pivo); // Pula os maiores que o pivo na direita

        do
            i++;
        while(v[i]<pivo); // Pula os menores que o pivo na esquerda

        if(i<j)
            troca(v[i], v[j]); // Joga número maior que o pivô para a direita
        else
            return j; // Passou, divide vetor no meio
    }
}

void quickSort(int v[], int TAM, int inicio, int fim)
{
    if(inicio < fim)
    {
        int meio=divide(v, TAM, inicio, fim);
        quickSort(v, TAM, inicio, meio);
        quickSort(v, TAM, meio+1, fim);
    }
}


int main()
{
    int v[TAM];
    double contMediaBinaria=0;
    double contMediaSequencial=0;
    double contMediaArvoreBinaria=0;
    double contMediaArvoreAVL=0;
    int buscado;
    preencheVetor(v, TAM);
    insereArvoreBinaria(v, TAM);
    insereArvoreAVL(v, TAM);
    quickSort(v, TAM, 0, TAM-1);
    imprimeVetor(v,TAM);
    for(int i=0; i<NUMBUSCAS; i++)
    {
        buscado = rand();
        buscaSequencial(v, TAM, buscado);
        buscaBinaria(v, TAM, buscado);
        buscaArvoreBinaria(buscado);
        buscaArvoreAVL(buscado);

        contMediaBinaria+=contBinaria;
        contMediaSequencial+=contSequencial;
        contMediaArvoreBinaria+=contArvoreBinaria;
        contMediaArvoreAVL+=contArvoreAVL;

        contBinaria=0;
        contSequencial=0;
        contArvoreBinaria=0;
        contArvoreAVL=0;
    }

    cout << "Sequencial: " << (int)contMediaSequencial/NUMBUSCAS << endl;
    cout << "Binaria: " << (int)contMediaBinaria/NUMBUSCAS << endl;
    cout << "Arvore binaria: " << (int)contMediaArvoreBinaria/NUMBUSCAS << endl;
    cout << "Arvore AVL: " << (int)contMediaArvoreAVL/NUMBUSCAS << endl;
}
