#include <iostream>

const int TAM = 5;

int pilha[TAM]; // Pilha de inteiros
int topo=-1; // Topo

using namespace std;

void push(int n)
{
    if(topo==TAM-1)
        cout << "Pilha cheia" << endl;
    else
    {
        topo++;
        pilha[topo]=n;
    }
}

bool vazia()
{
    if(topo==-1) return true;
    else return false;
}

void pop()
{
    if(!vazia()) topo--;
    else cout << "Pilha já está vazia" << endl;
}

void topoPilha()
{
    cout << "Elemento do topo: " << pilha[topo] << endl;
}

void imprime()
{
    if(!vazia())
        for(int i=topo; i>=0;i--)
            cout << "Elemento " << i << ": " << pilha[i]<< endl;
    else cout << "Pilha Vazia" << endl;
}

int main()
{
    int sai =1;
    int m;
    while(sai==1 || sai == 2 || sai == 3 || sai == 4)
    {
        cout << "1- Imprime pilha" << endl;
        cout << "2- Push" << endl;
        cout << "3- Pop" << endl;
        cout << "4- Elemento do topo da pilha"<< endl;
        cout << "Qualquer outra coisa para sair" << endl;
        cout << "Digite: ";
        cin >> sai;
        if(sai==1)
        {
            imprime();
        }
        else if(sai==2)
        {
            cout << "Informe um valor: ";
            cin >> m;
            push(m);
        }
        else if(sai==3)
            pop();
        else if(sai==4)
            topoPilha();
    }
}
