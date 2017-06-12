#include <iostream>
#include <clocale>
// insereLista OK
// recuperaLista OK
// buscaLista OK
// removeLista OK
// imprime OK
// verificaRepetidos OK

using namespace std;

int tamanho=0;
const int TAM = 5;
int lista[TAM];

bool vazia()
{
    if(tamanho==0)
        return true;
    return false;
}

void insereLista(int valor)
{
    int i;

    if(tamanho==TAM)
    {
        cout << "Lista Cheia" << endl;
        return;
    }
    for(i = tamanho; i >0 && valor < lista[i-1]; i--)
        lista[i]=lista[i-1];
    lista[i]=valor;
    tamanho++;
    cout << "Elemento inserido" << endl;
}

void recuperaLista(int posicao)
{
    if(vazia())
        cout << "Lista vazia" << endl;
    else if(posicao>=TAM)
        cout << "Posição não existente na lista" << endl;
    else if(posicao>=tamanho)
        cout << "Posição não ocupada" << endl;
    else
        cout << "Elemento " << posicao << ": " << lista[posicao] << endl;
}

void buscaLista(int valor)
{
    int i;
    int cont=0;
    bool achou=false;
    if(vazia())
    {
            cout << "Lista Vazia" << endl;
            return;
    }
    for(i=0; i < tamanho; i++)
        if(lista[i]==valor)
        {
            if(!achou)
            {
                cout << "Valor " << valor << " encontrado na posição " << i << endl;
                achou=true;
            }
            cont++;
        }
    if(!achou)
    {
        cout << "Valor não encontrado" << endl;
        return;
    }
    cout << "Valor encontrado " << cont << " vezes" << endl;

}

void removeLista(int valor)
{
    int i, cont=0, vezes=0, primeiro;
    bool achou = false;
    if(vazia())
    {
        cout << "Lista Vazia" << endl;
        return;
    }
    for(i=tamanho-1;i>=0 && valor <= lista[i];i--)
    {
        if(lista[i]==valor)
        {
            achou=true;
            vezes++;
            primeiro=i;
        }
    }

    cont=vezes;
    tamanho=tamanho-vezes;

    if(achou)
        while(cont!=-2)
        {
            lista[primeiro]=lista[primeiro+vezes];
            cont--;
            primeiro++;
        }
    if(!achou)
    {
        cout << "Elemento não encontrado para remover" << endl;
        return;
    }
    cout << "Elemento encontrado, removido " << vezes << " vezes" << endl;
}

void imprime()
{
    if(vazia())
        cout << "Lista vazia" << endl;
    else
        for(int i = 0; i < tamanho; i++)
            cout << "Elemento " << lista[i] << " na posicao " << i << endl;
}

void verificaRepetidos()
{
    bool achou=false;
    for(int i = 1; i<tamanho;i++)
    {
        if(lista[i]==lista[i-1])
        {
            achou=true;
            break;
        }
    }
    if(!achou)
    {
        cout << "Não existem elementos repetidos" << endl;
        return;
    }
    cout << "Existem elementos repetidos" << endl;
}

int main()
{
    setlocale(LC_ALL,"portuguese");

    return 0;
}
