//#include <cstdio>
#include <iostream>

using namespace std;

const int TAM = 5;
int vetor[TAM];

void buscamaior()
{
    int maior = vetor[0];

    for(int i=0; i < TAM; i++)
        if(vetor[i]>maior)
            maior = vetor[i];
    cout << "O maior valor é: " << maior << endl;

}

void buscamenor()
{
    int menor = vetor[0];

    for(int i=0; i < TAM; i++)
        if(vetor[i]<menor)
            menor = vetor[i];

    cout << "O menor valor é: " << menor << endl;
}

void conta()
{
    int c, j = 0;
    cout << "Informe qual valor quer contar: ";
    cin >> c;
    for(int i = 0; i < TAM; i++)
        if(vetor[i] == c)
        {
            j++;
            cout << "O número aparece na posição " << i << endl;
        }

    if(j==0) cout << "O valor aparece nenhuma vez";
    else if(j==1) cout << "O valor " << c << " aparece " << j << " vez" << endl;
    else cout << "O valor " << c << " aparece " << j << " vezes" << endl;
}

float calc_media()
{
    float media = 0;
    for(int i = 0; i<TAM; i++)
        media+=vetor[i];

    media/=TAM;
    return media;
}

int main()
{
    cout << "Informe os " << TAM << " valores: ";
    for(int i=0; i < TAM; i++)
        cin >> vetor[i];

    cout << "Os " << TAM << " valores são (Em ordem): " << endl;
    for(int i=0; i < TAM; i++)
        cout << vetor[i] << endl;

    cout << "Os " << TAM << " valores são(Em ordem reversa): " << endl;
    for(int i = TAM-1; i >= 0; i--)
        cout << vetor[i] << endl;

    buscamaior();

    buscamenor();

    conta();

    cout << "A media dos valores é: " <<  calc_media();

    return 0;
}
