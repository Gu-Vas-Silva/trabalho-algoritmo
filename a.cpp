#include<ctime>
#include <iostream>
#include <conio.h>
#include <string.h>
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
void buscarEstado(Tutor[], Cidade[], int &, int&);
void registroAnimais(Animal[], Raca[], Tutor[], Cidade[], int &, int &, int&, int&);
void buscarRaca(Animal[], Raca[], int&, int&);
void buscarTutor(Animal[], Tutor[], Cidade[], int&, int&, int&);
void realizarConsulta(Consulta[], Animal[], Tutor[], Raca[], Veterinario[], Cidade[], int&, int&, int&, int&, int&);
void buscarAnimal(Consulta[], Animal[], Tutor[], Raca[], int&, int&, int&);
void buscarVeterinario(Consulta[], Veterinario[], Cidade[], int&, int&, int&);
void intervaloData(Consulta[], Animal[], Veterinario[], int&);
time_t converterStringParaData(string&);
void mostrarConsultaPorIntervalo(Consulta[], Animal[], Veterinario[], string&, string&, int&);
void intervaloDataVet(Consulta[], Animal[], Veterinario[], Cidade[], int&, int&);
void mostrarConsultaPorIntervaloVet(Consulta[], Animal[], Veterinario[], string&, string&, int&, int&, int&);
int main()
{
    int contCid = 1, contTutor = 1, contAnimal, contConsul, contVet, contRaca;
    Cidade cid[100]{2, "avgre", "sp"};
    Raca raca[100];
    Tutor tutor[100]{1, "asdf", "435.284.888-32", "aaa", 2};
    Animal animal[100];
    Veterinario vet[100];
    Consulta consul[100];
    registroTutores(tutor, cid, &contTutor, &contCid);
    registroAnimais(animal, raca, tutor, cid, contAnimal, contRaca, contCid, contTutor);
	realizarConsulta(consul, animal, tutor, raca, vet, cid, contConsul, contRaca, contAnimal, contVet, contCid);
    intervaloData(consul, animal, vet, contConsul);
    intervaloDataVet(consul, animal, vet, cid, contVet, contConsul);
}

void registroTutores(Tutor a[], Cidade b[], int *contA, int *contCid)
{
    Tutor c[100];
    int contC = 0, i = 0, j = 0, k = 0, contT;
    cout << "valores para a inclusao: " << endl;
    for (int saida = 1; i < 100 && saida != 0; i++)
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

void registroAnimais(Animal a[], Raca raca[], Tutor tutor[], Cidade cidade[], int &contA, int &contRaca, int &contCid, int& contTutor)
{
    Animal b[100];
    int contB, i = 0, contT, k = 0, j = 0;
    for (int saida = 1; i < 100 && saida != 0; i++)
    {
        cout << "\ncodigo do animal: ";
        cin >> a[i].codigo;
        cin.ignore();
        cout << "\nnome: ";
        getline(cin, a[i].nome);
        cout << "\ncodigo da raca: ";
        cin >> a[i].codigo_raca;
        buscarRaca(a, raca, i, contRaca);
        cout << "\nidade: ";
        cin >> a[i].idade;
        cout << "\npeso: ";
        cin >> a[i].peso;
        cout << "\ncodigo tutor: ";
        cin >> a[i].codigo_tutor;
        buscarTutor(a, tutor, cidade, i, contCid, contTutor);
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
            attAnimal[i].nome = a[j].nome;
            attAnimal[i].codigo_raca= a[j].codigo_raca;
            attAnimal[i].idade= a[j].idade;
            attAnimal[i].peso= a[j].peso;
            attAnimal[i].codigo_tutor= a[j].codigo_tutor;
        }
        if (a[i].codigo > b[i].codigo)
        {
            attAnimal[i].codigo = b[k++].codigo;
            attAnimal[i].nome = b[k].nome;
            attAnimal[i].codigo_raca= b[k].codigo_raca;
            attAnimal[i].idade= b[k].idade;
            attAnimal[i].peso= b[k].peso;
            attAnimal[i].codigo_tutor= b[k].codigo_tutor;
        }
    }
    while(j<contA){
        attAnimal[i].codigo = a[j++].codigo;
            attAnimal[i].nome = a[j].nome;
            attAnimal[i].codigo_raca= a[j].codigo_raca;
            attAnimal[i].idade= a[j].idade;
            attAnimal[i].peso= a[j].peso;
            attAnimal[i].codigo_tutor= a[j].codigo_tutor;
            i++;
    }
    while(k<contB){
        attAnimal[i].codigo = b[k++].codigo;
            attAnimal[i].nome = b[k].nome;
            attAnimal[i].codigo_raca= b[k].codigo_raca;
            attAnimal[i].idade= b[k].idade;
            attAnimal[i].peso= b[k].peso;
            attAnimal[i].codigo_tutor= b[k].codigo_tutor;
    }
}

void realizarConsulta(Consulta a[], Animal animal[], Tutor tutor[], Raca raca[], Veterinario vet[], Cidade cid[], int &contA, int& contRaca, int& contAnimal, int& contVet, int& contCid){
	int i= contA + 1;
	for(int saida=1;i<100&&saida!=0;i++){
		a[i].codigo = i;
		cout<<"\ncodigo do animal: ";
		cin>>a[i].codigo_animal;
		buscarAnimal(a, animal, tutor, raca, i, contRaca, contAnimal);
		cout<<"\ncodigo do veterinario: ";
		cin>>a[i].codigo_veterinario;
		buscarVeterinario(a, vet, cid, i, contVet, contCid);
		cin.ignore();
		cout<<"\ndata: ";
		getline(cin, a[i].data);
		cout<<"\nvalor da consulta: ";
		cin>>a[i].valor;
	}
}

void intervaloData(Consulta a[], Animal animal[], Veterinario vet[], int &contA){
    string dataInicial, dataFinal;
    cout<<"\ndigite a data inicial: ";
    cin>>dataInicial;
    cout<<"\ndigite a data final: ";
    cin>>dataFinal;
    mostrarConsultaPorIntervalo(a, animal, vet, dataInicial, dataFinal, contA);
}

void intervaloDataVet(Consulta a[], Animal animal[], Veterinario vet[], Cidade cidade[], int &contVet, int &contA){
    string dataInicial, dataFinal;
    int codigo;
    cout<<"\ndigite o codigo do veterinario: ";
    cin>>codigo;
    buscarVeterinario(a, vet, cidade, contVet);
    cout<<"\ndigite a data inicial: ";
    cin>>dataInicial;
    cout<<"\ndigite a data final: ";
    cin>>dataFinal;
    mostrarConsultaPorIntervaloVet(a, animal, vet, dataInicial, dataFinal, codigo, contA, contVet);
}

void mostrarConsultaPorIntervalo(Consulta a[], Animal animal[], Veterinario vet[], string &dataInicial, string &dataFinal, int &contA){
    time_t inicio = converterStringParaData(dataInicial);
    time_t final = converterStringParaData(dataFinal);
    float s=0;
    int j=0, achou;
    for(int i=0; i<contA; i++){
        string data = a[i].data;
        time_t dataConsulta = converterStringParaData(data);
        if(dataConsulta >= inicio && dataConsulta <= final){
            cout<<"\nconsulta na data: "<< a[i].data;
            cout<<"\nno valor: "<<a[i].valor;
            s= s+a[i].valor;
            achou=0;
                while(achou == 0){
                    if(a[i].codigo_animal == animal[j].codigo){
                    cout<<"\nanimal consultado: "<< animal[j].nome;
                    }
                    if(a[i].codigo_veterinario == vet[j].codigo){
                    cout<<"\nnome do veterinario que consultou: " << vet[j].nome;
                    achou++;
                    }
                    j++;
            }
        }
    }
    if(s == 0){
        cout<<"\nnenhuma consulta encontrada!!!!";
    }else{
        cout<<"\nvalor total da consulta: "<< s;
    }    
}

void mostrarConsultaPorIntervaloVet(Consulta a[], Animal animal[], Veterinario vet[], string &dataInicial, string &dataFinal, int &codigo, int &contA, int &contVet){
    time_t inicio = converterStringParaData(dataInicial);
    time_t final = converterStringParaData(dataFinal);
    float s=0;
    int j=0, achou;
    for(int i=0; i<contVet; i++){
        string data = a[i].data;
        time_t dataConsulta = converterStringParaData(data);
            if(vet[i].codigo == codigo){
                cout<<"\nVeterinario: "<<vet[i].nome;
             while(j< contA){
             if(dataConsulta >= inicio && dataConsulta <= final){
            cout<<"\nconsulta na data: "<< a[i].data;
            cout<<"\nno valor: "<<a[i].valor;
            s= s+a[i].valor;
            achou=0;
             }
           }
        }
        j=0;
        while(achou == 0){
           if(a[i].codigo_animal == animal[j].codigo){
             cout<<"\nanimal consultado: "<< animal[j].nome;
             }
           if(a[i].codigo_veterinario == vet[j].codigo){
             cout<<"\nnome do veterinario que consultou: " << vet[j].nome;
             achou++;
           }
                    j++;
            }
        }
        if(s == 0){
        cout<<"\nnenhuma consulta encontrada!!!!";
    }else{
        cout<<"\nvalor total que o veterinario rendeu: "<< s;
    }  
}
      
time_t converterStringParaData(string &data){
    tm tm = {};
    sscanf(data.c_str(), "%d/%d/%d", &tm.tm_mday, &tm.tm_mon, &tm.tm_year);
    tm.tm_mon -= 1;            
    tm.tm_year -= 2020;         
    return mktime(&tm);

}

void buscarRaca(Animal a[], Raca b[], int &i, int &contRaca){
    int achou=0;
	while(achou == 0){
		for(int j=0; j<contRaca; j++){
        if(a[i].codigo_raca == b[j].codigo){
            cout<<"\ncodigo da raca encontrada: "<< b[j].descricao;
            achou++;
        }
    }
    if(achou == 0){
        cout<<"\ncodigo da raca nao encontrado. Tente denovo";
		cin>>a[i].codigo_raca;
    }
	}
}

void buscarTutor(Animal a[], Tutor b[], Cidade c[], int& i, int& contTutor, int& contCid){
    int achou=0, k;
	while(achou == 0){
	for(int j=0; j<contTutor; j++){
        if(a[i].codigo_tutor == b[j].codigo){
            cout<<"\nnome do tutor: "<<b[j].nome;
            k=i;
			achou++;
        }
    }
    if(achou == 0){
        cout<<"\ntutor nao encontrado. Digite o codigo novamente: ";
		cin>>a[i].codigo_tutor;
	} 
}
	for(int j=0; j<contCid; j++){
        if(b[k].codigo_cidade== c[j].codigo){
            cout<<"\ncidade: "<<c[j].nome;
        }
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

void buscarEstado(Tutor a[], Cidade b[], int &i, int &contCid)
{
    int cont = 0;
	while(cont == 0){
	for (int j = 0; j < contCid; j++)
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
        cout << "\ncidade e estado nao encontrados. Digite o codigo novamente: ";
		cin>>a[i].codigo_cidade;
    }
	}  
}

void buscarAnimal(Consulta a[], Animal b[], Tutor c[], Raca d[], int& i, int &contAnimal, int &contRaca){
	int k, achou=0;
	while(achou == 0){
		for(int j=0; j<contAnimal; j++){
		if(a[i].codigo_animal == b[j].codigo){
			cout<<"\nAnimal: "<<b[j].nome;
			k=j;
			achou++;
		}
	}
	if(achou==0){
		cout<<"\nanimal nao encontrado. Digite o codigo novamente: ";
		cin>>a[i].codigo_animal;
	}
	}
	for(int j=0; j<contRaca; j++){
		if(b[k].codigo_raca== d[j].codigo){
			cout<<"\nRaca: "<<d[j].descricao;
		}
		if(b[k].codigo_tutor == c[j].codigo){
			cout<<"\nTutor: "<<c[j].nome;
		}
	}
}

void buscarVeterinario(Consulta a[], Veterinario b[], Cidade c[], int& i, int& contVet, int& contCid){
	int achou=0, k;
	while(achou == 0){
		for(int j=0;j<contVet;j++){
		if(a[i].codigo_veterinario == b[j].codigo){
			cout<<"\nVeterinario: "<<b[j].nome;
			achou++;
			k=j;
		}
	}
	if(achou == 0){
		cout<<"\nVeterinario nao encontrado. Digite o codigo novamente: ";
		cin>>a[i].codigo_veterinario;
	}
	}
		for(int j=0;j<contCid;j++){
			if(b[k].codigo_cidade == c[j].codigo){
				cout<<"\ncidade: "<<c[j].nome;
			}
		}
}

