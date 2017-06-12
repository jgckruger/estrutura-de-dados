#include <iostream>
#include <clocale>

using namespace std;

const int TAM = 5;

int fila[TAM];
int topo=0;
int fim=0;
int contador=0;

void insereFila(int valor)
{
    if(contador==TAM)
    {
        cout << "Fila Cheia" << endl;
        return;
    }
    contador++;
    fila[fim]=valor;
    if(fim==TAM-1)
        fim=0;
    else
        fim++;
    cout << "Inserido" << endl;
}

bool vazia()
{
    if(contador==0)
        return true;
    return false;
}

void removeFila()
{
    if(!vazia())
    {
        contador--;
        if(topo==TAM-1)
            topo=0;
        else
            topo++;
    }
    else
        cout << "Fila vazia" << endl;
}

int inicioFila()
{
    if(!vazia)
        return fila[topo];
    return -1;
}

void imprime()
{
    int aux_cont=contador;
    int aux_topo=topo;

    while(aux_cont != 1)
    {
        cout << fila[aux_topo] << endl;
        aux_cont--;
        if(aux_topo==TAM-1)
            aux_topo=0;
        else
            aux_topo++;
    }
}

int main()
{
    insereFila(1);
    insereFila(2);
    insereFila(3);
    insereFila(4);
    insereFila(5);
    imprime();
    cout << "\n" << endl;

    removeFila();
    removeFila();
    imprime();
    cout << "\n" << endl;

    insereFila(6);
    insereFila(7);
    imprime();
    cout << "\n" << endl;

    insereFila(8);
    insereFila(9);
    insereFila(10);
    cout << "\n" << endl;

    removeFila();
    removeFila();
    imprime();
    return 0;
}
