#include <iostream>
#include <clocale>

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

void recupera(int pos)
{
    if(vazia())
        cout << "Lista vazia" << endl;
    else if(pos>=tamanho)
        cout << "Posição não ocupada" << endl;
    else
        cout << "Elemento" << pos << ": " << lista[pos] << endl;
}

void busca(int valor)
{
    int i;
    bool achou=false;
    if(vazia())
    {
            cout << "Lista Vazia" << endl;
            return;
    }
    for(i=0; i < tamanho; i++)
        if(lista[i]==valor)
        {
            cout << "Valor " << valor << " encontrado na posição " << i << endl;
            achou=true;
            break;
        }
    if(!achou)
        cout << "Valor não encontrado" << endl;
}

void buscaRepetidos(int valor)
{
    int i;
    int cont=0;
    if(vazia())
    {
            cout << "Lista Vazia" << endl;
            return;
    }
    for(i=0; i < tamanho; i++)
        if(lista[i]==valor)
        {
            cout << "Valor " << valor << " encontrado na posição " << i << endl;
            cont++;
        }
    if(cont==0)
        cout << "Valor não encontrado" << endl;
}

void removeLista(int valor)
{
    int i;
    bool achou = false;
    if(vazia())
    {
        cout << "Lista Vazia" << endl;
        return;
    }
    for(i=0; i < tamanho; i++)
    {
        if(lista[i]==valor && !achou)
        {
            achou=true;
            tamanho--;
        }
        if(achou)
        {
            lista[i]=lista[i+1];
            cout << "Elemento removido" << endl;
        }
    }
    if(!achou)
        cout << "Elemento não encontrado para remover" << endl;
}

void removeTodos(int valor)
{
    int i;
    bool achou = false, found = false;
    if(vazia())
    {
        cout << "Lista Vazia" << endl;
        return;
    }
    for(i=0; i < tamanho; i++)
    {
        if(lista[i]==valor && !achou)
        {
            achou=true;
            found=true;
            tamanho--;
        }
        if(achou)
        {
            lista[i]=lista[i+1];
            i--;
            achou=false;
            cout << "Elemento removido" << endl;
        }
    }
    if(!found)
        cout << "Elemento não encontrado para remover" << endl;
}

void imprimeLista()
{
    if(vazia())
        cout << "Lista vazia" << endl;
    else
        for(int i = 0; i < tamanho; i++)
            cout << "Elemento " << lista[i] << " na posicao " << i << endl;
}

int main()
{
    setlocale(LC_ALL,"portuguese");
    if(vazia())
        cout << "Lista vazia" << endl;
    insereLista(1);
    insereLista(2);
    insereLista(3);
    insereLista(4);
    insereLista(5);
    insereLista(6); // Erro
    cout << "\n\n\n\n";

    imprimeLista();
    cout << "\n\n\n\n";

    removeLista(5);
    cout << "\n\n\n\n";

    removeLista(7);
    cout << "\n\n\n\n";

    imprimeLista();
    cout << "\n\n\n\n";
    busca(2);
    busca(7); // Erro
    busca(5); // Erro
    cout << "\n\n\n\n";

    removeLista(4);
    removeLista(3);
    cout << "\n\n\n\n";

    imprimeLista();
    cout << "\n\n\n\n";

    insereLista(2);
    insereLista(2);
    insereLista(2);
    insereLista(2);
    insereLista(2);
    cout << "\n\n\n\n";

    imprimeLista();
    cout << "\n\n\n\n";

    removeLista(2);
    cout << "\n\n\n\n";

    imprimeLista();
    cout << "\n\n\n\n";

    busca(2);
    cout << "\n\n\n\n";

    buscaRepetidos(2);
    cout << "\n\n\n\n";

    imprimeLista();
    cout << "\n\n\n\n";

    removeTodos(2);
    cout << "\n\n\n\n";

    imprimeLista();
    cout << "\n\n\n\n";


    return 0;
}
