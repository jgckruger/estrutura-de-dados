#include <iostream>
#include <string>

using namespace std;

string exp;
string pilha;

int TAM;
int topo=-1;

bool vazia()
{
    if(topo==-1) return true;
    else return false;
}

void push(char n)
{
        topo++;
        pilha[topo]=n;
}

void pop()
{
    if(!vazia())
        topo--;
}

int main()
{
    cin >> exp;
    for(int i=0; i<exp.size(); i++)
    {
        if(exp[i]=='(' || exp[i]=='[' || exp[i]=='{')
            push(exp[i]);
        else if(exp[i]==')' && pilha[topo] == '(')
            pop();
        else if(exp[i]==']' && pilha[topo] == '[')
            pop();
        else if(exp[i]=='}' && pilha[topo] == '{')
            pop();
        else if(exp[i]==')' || exp[i]==')' || exp[i]==')')
            break;
    }
    if (topo==-1) cout << "Sucesso";
    else cout << "Falha" << endl << " TOPO: " << topo << endl;
    return 0;
}
