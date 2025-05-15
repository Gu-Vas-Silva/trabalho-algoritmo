#include <iostream>
#include <conio.h>
#include <string.h>
#define t 2
using namespace std;
struct Cidade
{
    int codigo;
    string nome;
    string uf;
};

struct Raca
{
    int codigo;
    string descricao;
};

struct Tutor
{
    int codigo;
    string nome;
    string cpf;
    string endereco;
    int codigo_cidade;
};

struct Animal
{
    int codigo;
    string nome;
    int codigo_raca;
    int idade;
    float peso;
    int codigo_tutor;
};

struct Veterinario
{
    int codigo;
    string nome;
    string endereco;
    int codigo_cidade;
};

struct Consulta
{
    int codigo;
    int codigo_animal;
    int codigo_veterinario;
    string data;
    float valor;
};
void registroTutores(Tutor[], Cidade[], int *, int *);
bool validarCpf(Tutor[], int &);
void buscarEstado(Tutor[], Cidade[], int &, int *);
void registroAnimais(Animal[], Raca[], Tutor[], int &);
void buscarRaca(Animal[], Raca[], int&, int&);
void buscarTutor(Animal[], Tutor[], Cidade[], int&, int&);
int main()
{
    int contCid = 1, contTutor = 1, contAnimal;
    Cidade cid[t]{2, "avgre", "sp"};
    Raca raca[t];
    Tutor tutor[t]{1, "asdf", "435.284.888-32", "aaa", 2};
    Animal animal[t];
    Veterinario vet[t];
    Consulta consul[t];
    registroTutores(tutor, cid, &contTutor, &contCid);
    registroAnimais(animal, raca, tutor, cid, contAnimal);
}

void registroTutores(Tutor a[], Cidade b[], int *contA, int *contCid)
{
    Tutor c[t];
    int contC = 0, i = 0, j = 0, k = 0, contT;
    cout << "valores para a inclusao: " << endl;
    for (int saida = 1; i < t && saida != 0; i++)
    {
        cout << "codigo: " << endl;
        cin >> c[i].codigo;
        cin.ignore();
        cout << "nome: " << endl;
        getline(cin, c[i].nome);
        cout << "cpf: " << endl;
        getline(cin, c[i].cpf);
        if (validarCpf(c, i) != true)
        {
            cout << "cpf invalido!!!!!!";
            break;
        }
        cout << "endereco: " << endl;
        getline(cin, c[i].endereco);
        cout << "codigo da cidade" << endl;
        cin >> c[i].codigo_cidade;
        cin.ignore();
        buscarEstado(c, b, i, contCid);
        cout << "digite 0 para sair ou qualquer outro numero para continuar: " << endl;
        cin >> saida;
        cin.ignore();
    }
    contC = i;
    contT = contC + *contA;
    Tutor tutorAtt[contT];
    for (i = 0; j < *contA && k < contC; i++)
    {
        if (c[k].codigo < a[j].codigo)
        {
            tutorAtt[i].codigo = c[k].codigo;
            tutorAtt[i].nome = c[k].nome;
            tutorAtt[i].endereco = c[k].endereco;
            tutorAtt[i].cpf = c[k].cpf;
            tutorAtt[i].codigo_cidade = c[k].codigo_cidade;
            k++;
        }
        if (c[k].codigo > a[j].codigo)
        {
            tutorAtt[i].codigo = a[j].codigo;
            tutorAtt[i].nome = a[j].nome;
            tutorAtt[i].endereco = a[j].endereco;
            tutorAtt[i].cpf = a[j].cpf;
            tutorAtt[i].codigo_cidade = a[j].codigo_cidade;
            j++;
        }
    }
    while (j < *contA)
    {
        tutorAtt[i].codigo = a[j].codigo;
        tutorAtt[i].nome = a[j].nome;
        tutorAtt[i].endereco = a[j].endereco;
        tutorAtt[i].cpf = a[j].cpf;
        tutorAtt[i].codigo_cidade = a[j].codigo_cidade;
        j++;
        i++;
    }
    while (k < contC)
    {
        tutorAtt[i].codigo = c[k].codigo;
        tutorAtt[i].nome = c[k].nome;
        tutorAtt[i].endereco = c[k].endereco;
        tutorAtt[i].cpf = c[k].cpf;
        tutorAtt[i].codigo_cidade = c[k].codigo_cidade;
        k++;
        i++;
    }
    contT = i;
    for (i = 0; i < contT; i++)
    {
        cout << "\ncodigo: " << tutorAtt[i].codigo;
        cout << "\nnome: " << tutorAtt[i].nome;
        cout << "\nendereco: " << tutorAtt[i].endereco;
        cout << "\ncpf: " << tutorAtt[i].cpf;
        cout << "\ncodigo cidade: " << tutorAtt[i].codigo_cidade;
    }
}
void registroAnimais(Animal a[], Raca raca[], Tutor tutor[], Cidade cidade[], int &contA)
{
    Animal b[t];
    int contB, i = 0, contT, k = 0, j = 0;
    for (int saida = 1; i < t && saida != 0; i++)
    {
        cout << "\ncodigo do animal: ";
        cin >> a[i].codigo;
        cin.ignore();
        cout << "\nnome: ";
        getline(a[i].nome);
        cout << "\ncodigo da raca: ";
        cin >> a[i].codigo_raca;
        buscarRaca(a, raca, i, contA);
        cout << "\nidade: ";
        cin >> a[i].idade;
        cout << "\npeso: ";
        cin >> a[i].peso;
        cout << "\ncodigo tutor: ";
        cin >> a[i].codigo_tutor;
        buscarTutor(a, tutor, cidade, i, contA);
        cout << "\ndigite 0 para parar";
        cin >> saida;
    }
    contB = i;
    contT = contA + contB;
    Animal attAnimal[contT];
    for (i = 0; j < contA && k < contB; i++)
    {
        if (a[i].codigo < b[i].codigo)
        {
            attAnimal[i].codigo = a[j++].codigo;
            strcpy(attAnimal[i].nome, a[j].nome);
            attAnimal[i].codigo_raca= a[j].codigo_raca;
            attAnimal[i].idade= a[j].idade;
            attAnimal[i].peso= a[j].peso;
            attAnimal[i].codigo_tutor= a[j].codigo_tutor;
        }
        if (a[i].codigo > b[i].codigo)
        {
            attAnimal[i].codigo = b[k++].codigo;
            strcpy(attAnimal[i].nome, b[k].nome);
            attAnimal[i].codigo_raca= b[k].codigo_raca;
            attAnimal[i].idade= b[k].idade;
            attAnimal[i].peso= b[k].peso;
            attAnimal[i].codigo_tutor= b[k].codigo_tutor;
        }
    }
    while(j<contA){
        attAnimal[i].codigo = a[j++].codigo;
            strcpy(attAnimal[i].nome, a[j].nome);
            attAnimal[i].codigo_raca= a[j].codigo_raca;
            attAnimal[i].idade= a[j].idade;
            attAnimal[i].peso= a[j].peso;
            attAnimal[i].codigo_tutor= a[j].codigo_tutor;
            i++;
    }
    while(k<contB){
        attAnimal[i].codigo = b[k++].codigo;
            strcpy(attAnimal[i].nome, b[k].nome);
            attAnimal[i].codigo_raca= b[k].codigo_raca;
            attAnimal[i].idade= b[k].idade;
            attAnimal[i].peso= b[k].peso;
            attAnimal[i].codigo_tutor= b[k].codigo_tutor;
    }
}
void buscarRaca(Animal a[], Raca b[], int &i, int &contA){
    int achou=0;
    for(int j=0; j<contA; j++){
        if(a[i].codigo_raca == b[j].codigo){
            cout<<"\ncodigo da raca encontrada: "<< b[i].descricao;
            achou++;
        }
    }
    if(achou == 0){
        cout<<"\ncodigo da raca nao encontrado";
    }
}
void buscarTutor(Animal a[], Tutor b[], Cidade c[], int& i, int& contA){
    int achou=0, k;
    for(int j=0; j<contA; j++){
        if(a[i].codigo_tutor == b[j].codigo){
            cout<<"\nnome do tutor: "<<b[i].nome;
            achou++;
            k=i;
        }
    }
    for(int j=0; j<contA; j++){
        if(b[k].codigo_cidade== c[j].codigo){
            cout<<"\ncidade: "<<c[j].nome;
        }
    }
    if(achou == 0){
        cout<<"tutor nao encontrado";
    }
}
bool validarCpf(Tutor a[], int &i)
{
    string numeros;
    for (char c : a[i].cpf)
    {
        if (isdigit(c))
        {
            numeros += c;
        }
    }
    if (numeros.length() != 11)
    {
        return false;
    }
    bool todosIguais = true;
    for (int j = 1; j < 11; j++)
    {
        if (numeros[j] != numeros[0])
        {
            todosIguais = false;
            break;
        }
    }
    if (todosIguais)
        return false;
    int soma = 0;
    for (int j = 0; j < 9; j++)
    {
        soma += (numeros[j] - '0') * (10 - j);
    }
    int primeiroDigito = (soma * 10) % 11;
    if (primeiroDigito == 10)
        primeiroDigito = 0;

    if (primeiroDigito != (numeros[9] - '0'))
    {
        return false;
    }
    soma = 0;
    for (int j = 0; j < 10; j++)
    {
        soma += (numeros[j] - '0') * (11 - j);
    }
    int segundoDigito = (soma * 10) % 11;
    if (segundoDigito == 10)
        segundoDigito = 0;

    if (segundoDigito != (numeros[10] - '0'))
    {
        return false;
    }

    return true;
}
void buscarEstado(Tutor a[], Cidade b[], int &i, int *contCid)
{
    int cont = 0;
    for (int j = 0; j < *contCid; j++)
    {
        if (a[i].codigo_cidade == b[j].codigo)
        {
            cout << "\ncidade: " << b[j].nome;
            cout << "\nestado: " << b[j].uf;
            cont++;
        }
    }
    if (cont == 0)
    {
        cout << "cidade e estado nao encontrados";
    }
}
