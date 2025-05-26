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
void leituraConsulta(Consulta[], int&, Animal[], Tutor [], Raca[], Veterinario[], Cidade[] , int&, int &,int &, int&);
void leituraVet(Veterinario [], Cidade[], int&, int &);
void leituraAnimal(Animal [], int &, Tutor[], Cidade[], Raca[], int&, int &, int&);
void leituraTutor(Tutor [], Cidade[], int&, int &);
void leituraRaca(Raca [], int &);
void leituraCid( Cidade [], int &);


void registroTutores(Tutor[], Cidade[], int *, int *);
void validarCpf(Tutor[], int &);
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
void intervaloDataVet(Consulta[], Animal[], Veterinario[], int&, int&);
void mostrarConsultaPorIntervaloVet(Consulta[], Animal[], Veterinario[], string&, string&, int&, int&, int&);
int main()
{
    int contCid = 1, contTutor = 1, contAnimal = 1, contConsul = 1, contVet = 1, contRaca = 1;
    Cidade cid[100]; cid[0]={1, "Candido-Mota", "sp"};
    Raca raca[100]; raca[0]={1, "rato"};
    Tutor tutor[100];tutor[0]={1, "Gustavo", "435.284.888-32", "aaa", 1};
    Animal animal[100]; animal[0]={1, "toto", 1, 12, 10.2, 1};
    Veterinario vet[100]; vet[0]={1, "Duzao", "Rua A", 1};
    Consulta consul[100];consul[0]={1, 1, 1," 10/10/2010", 120.00};
    int c;
    c=0;
    while(c != 6){
        cout<<"\n\n========================================================"<<endl;
         cout<<"Digite o numero 1 caso queria resgistrar o Tutor: \n Digite o numero 2 caso queira registrar o animal:\n Digite o numero 3 caso queria realizar consulta:\n Digite 4 caso queira buscar uma consulta por data:\n Digite o numero 5 caso queira buscar consultas em determinada data por determinado veterinario:\n Digite 6 para sair;";
          cout<<"\n\n========================================================"<<endl;
         cin>>c;
		switch (c){
            case 1:
                registroTutores(tutor, cid, &contTutor, &contCid);
            break;

            case 2:
                registroAnimais(animal, raca, tutor, cid, contAnimal, contRaca, contCid, contTutor);
            break;

            case 3:
	            realizarConsulta(consul, animal, tutor, raca, vet, cid, contConsul, contRaca, contAnimal, contVet, contCid);
            break;

            case 4:
                intervaloData(consul, animal, vet, contConsul);
            break;

            case 5:
                intervaloDataVet(consul, animal, vet, contVet, contConsul);
            break;

            default :
            cout<<"END";
            break;
        }
    }
    leituraCid(cid, contCid);
    leituraTutor(tutor, cid, contTutor, contCid);
    leituraVet(vet, cid, contVet, contCid);
    leituraRaca(raca, contRaca);
    leituraAnimal(animal, contAnimal, tutor, cid, raca, contTutor, contCid, contRaca);
    leituraConsulta(consul, contConsul, animal, tutor, raca,vet,cid, contAnimal, contRaca,contVet,contCid);
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
        validarCpf(c, i);
        cout << "endereco: " << endl;
        getline(cin, c[i].endereco);
        cout << "codigo da cidade" << endl;
        cin >> c[i].codigo_cidade;
        cin.ignore();
        buscarEstado(c, b, i, *contCid);
        cout << "digite 0 para sair ou qualquer outro numero para continuar: " << endl;
        cin >> saida;
        cin.ignore();
    }
    contC = i;
    contT = contC + *contA;
    cout<<"\n\ncontT = "<<contT;
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
        i++;
        j++;
    }
    while (k < contC)
    {
        tutorAtt[i].codigo = c[k].codigo;
        tutorAtt[i].nome = c[k].nome;
        tutorAtt[i].endereco = c[k].endereco;
        tutorAtt[i].cpf = c[k].cpf;
        tutorAtt[i].codigo_cidade = c[k].codigo_cidade;
        i++;
        k++;
    }
    contT = i;
    for (i = 0; i < contT; i++)
    {
        a[i].codigo = tutorAtt[i].codigo;
        a[i].nome = tutorAtt[i].nome;
        a[i].endereco = tutorAtt[i].endereco;
        a[i].cpf = tutorAtt[i].cpf;
        a[i].codigo_cidade = tutorAtt[i].codigo_cidade;
    }
    *contA = contT;
}

void registroAnimais(Animal a[], Raca raca[], Tutor tutor[], Cidade cidade[], int &contA, int &contRaca, int &contCid, int& contTutor)
{
    Animal b[100];
    int contB, i = 0, contT, k = 0, j = 0;
    for (int saida = 1; i < 100 && saida != 0; i++)
    {
        cout << "\ncodigo do animal: ";
        cin >> b[i].codigo;
        cin.ignore();
        cout << "\nnome: ";
        getline(cin, b[i].nome);
        cout << "\ncodigo da raca: ";
        cin >> b[i].codigo_raca;
        buscarRaca(b, raca, i, contRaca);
        cout << "\nidade: ";
        cin >> b[i].idade;
        cout << "\npeso: ";
        cin >> b[i].peso;
        cout << "\ncodigo tutor: ";
        cin >> b[i].codigo_tutor;
        buscarTutor(b, tutor, cidade, i, contCid, contTutor);
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
            i++;
    }
    for(i = 0; i<contT; i++){
           a[i].codigo = attAnimal[i].codigo; 
           a[i].nome = attAnimal[i].nome;
           a[i].codigo_raca = attAnimal[i].codigo_raca;
           a[i].idade = attAnimal[i].idade;
           a[i].peso = attAnimal[i].peso;
           a[i].codigo_tutor = attAnimal[i].codigo_tutor; 
    }
    contA = contT;
}

void realizarConsulta(Consulta a[], Animal animal[], Tutor tutor[], Raca raca[], Veterinario vet[], Cidade cid[], int &contA, int& contRaca, int& contAnimal, int& contVet, int& contCid){
	int i= contA;
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
         cout << "\ndigite 0 para parar";
        cin >> saida;
	}
    contA= i;
}

void intervaloData(Consulta a[], Animal animal[], Veterinario vet[], int &contA){
    string dataInicial, dataFinal;
    cout<<"\ndigite a data inicial: ";
    cin>>dataInicial;
    cout<<"\ndigite a data final: ";
    cin>>dataFinal;
    mostrarConsultaPorIntervalo(a, animal, vet, dataInicial, dataFinal, contA);
}

void intervaloDataVet(Consulta a[], Animal animal[], Veterinario vet[], int &contVet, int &contA){
    string dataInicial, dataFinal;
    int codigo;
    cout<<"\ndigite o codigo do veterinario: ";
    cin>>codigo;
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
    for(int i=0; i<=contA; i++){
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
    int j=0, achouVet=0, achou, i;
     while(achouVet == 0){
        for(i=0; i<=contVet; i++){
            string data = a[i].data;
            time_t dataConsulta = converterStringParaData(data);
            achou=0;
                if(vet[i].codigo == codigo){
                cout<<"\nVeterinario: "<<vet[i].nome;
                while(j<= contA && achou == 0){
                if(dataConsulta >= inicio && dataConsulta <= final){
                cout<<"\nconsulta na data: "<< a[i].data;
                cout<<"\nno valor: "<<a[i].valor;
                s= s+a[i].valor;
                achou++;
                j++;
                }               
            }
            achouVet++;
        }
        if(achouVet == 0){
            cout<<"codigo nao encontrado. Digite o codigo novamente: ";
            cin>>codigo;
        }
     }
     for(; j<contA; j++){
        if(a[i].codigo_animal == animal[j].codigo){
          cout<<"\nanimal consultado: "<< animal[j].nome;
          }
        if(a[i].codigo_veterinario == vet[j].codigo){
          cout<<"\nnome do veterinario que consultou: " << vet[j].nome;
        }
     }
}
if(s==0){
        cout<<"\nNao recebeu nada!!!!!!!!!!!!!!!";
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
		for(int j=0; j<=contRaca; j++){
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
	for(int j=0; j<=contTutor; j++){
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

void validarCpf(Tutor a[], int &i)
{
    bool valido = false;
    while(valido == false){
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
        cout<<"\ncpf com menos ou mais de 11 digitos. Tente denovo: ";
        cin>>a[i].cpf;
    }else{
        bool todosIguais = true;
        for (int j = 1; j < 11; j++)
        {
        if (numeros[j] != numeros[0])
        {
            todosIguais = false;
        }
    }
    if (todosIguais){
        cout<<"\ntodos os numeros do cpf sao iguais. Tente denovo: ";
        cin>>a[i].cpf;
    }else{
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
        cout<<"\ncpf invalido. Tente denovo: ";
        cin>>a[i].cpf;
    }else{
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
        cout<<"cpf invalido. Tente denovo: ";
        cin>>a[i].cpf;
    }else{
        valido = true;
    }
    }
    }  
    }
    }     
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


void leituraCid(Cidade v[], int &contCity){
    int i=0;
    for(int saida = 1; i<100 && saida != 0; i++ ){
        cout<<"Codigo da city:";
        cin>>v[i].codigo;
        cin.ignore();
        cout<<"Nome da city:";
        getline(cin,v[i].nome);
        cout<<"Uf da city:";
        cin>>v[i].uf;
        contCity++;
        cout<<"\ndigite 0 para parar:";
        cin>>saida;
    }
}

void leituraRaca(Raca v[], int &contRaca ){
    int i=0;
    for(int saida =1; i<100 && saida != 0; i++){
        cout <<"Codigo de Raca:";
        cin >>v[i].codigo;
        cin.ignore();
        cout <<"Descricao do animal:";
        getline(cin,v[i].descricao);
        contRaca++;
        cout<<"\ndigite 0 para parar:";
        cin>>saida;
    }
}

void leituraTutor(Tutor v[], Cidade cidade[], int &contTutor, int &contCid){
    int i=0;
    for (int saida =1;i<100 && saida !=0;i++){
        cout <<"Codigo Tutor:";
        cin>> v[i].codigo;
        cin.ignore();
        cout<<"Nome do Tutor:";
        getline(cin, v[i].nome);
        cin.ignore();
        cout<<"Cpf do Tutor";
        getline(cin, v[i].cpf);
        validarCpf(v, i);
        cin.ignore();
        cout<<"Endereco do Tutor";
        getline(cin, v[i].endereco);
        cout<<"Codigo da Cidade do Tutor:";
        cin>>v[i].codigo_cidade;
        buscarEstado(v, cidade, i, contCid);
        contTutor++;
        cout<<"\ndigite 0 para parar:";
        cin>>saida;
    }
}
void leituraAnimal(Animal v[], int &contAnimal, Tutor b[],Cidade c[], Raca raca[], int &contTutor, int &contCid, int &contRaca){
    int i=0;
    for(int saida =1; i<100 && saida!=0;i++){
        cout<<"Codigo do Animal:";
        cin>>v[i].codigo;
        cin.ignore();
        cout<<"Nome do Animal:";
        getline(cin, v[i].nome);
        cout<<"Codigo da Raca:";
        cin>>v[i].codigo_raca;
        buscarRaca(v, raca, i, contRaca);
        cout<<"Idade do Animal:";
        cin>>v[i].idade;
        cout<<"Peso do Animal:";
        cin>>v[i].peso;
        cout<<"Codigo do Tutor:";
        cin>>v[i].codigo_tutor;
        buscarTutor( v,b,c,i, contTutor, contCid);
        contAnimal++;
        cout<<"\ndigite 0 para parar:";
        cin>>saida;
    }
}
void leituraVet(Veterinario v[], Cidade cid[], int &contVet, int& contCid){
    int i=0;
    for(int saida =1;i<100 && saida!=0;i++){
        int achou=0;
        cout<<"\nCodigo do Veterinario:";
        cin>>v[i].codigo;
        cin.ignore();
        cout<<"\nNome Veterinario:";
        getline(cin, v[i].nome);
        cin.ignore();
        cout<<"\nEndereco do Veterinario:";
        getline(cin, v[i].endereco);
        cout<<"\nCodigo da Cidade:";
        cin>>v[i].codigo_cidade;
        contVet++;
        while(achou == 0){
            for(int j=0; j<contCid; j++){
                if(v[i].codigo_cidade == cid[j].codigo){
                    cout<<"\nCidade: "<< cid[j].nome;
                    achou++;
                }
            }
            if(achou == 0){
                cout<<"\nCodigo de cidade nao encontrado. Tente denovo: ";
                cin>>v[i].codigo_cidade;
            }
        }
        cout<<"\ndigite 0 para parar:";
        cin>>saida;
    }
}

void leituraConsulta(Consulta v[], int &contConsulta, Animal b[], Tutor c[], Raca d[], Veterinario vet[], Cidade cid[],int &contAnimal, int &contRaca, int& contVet, int& contCid){
    int i=0;
    for(int saida=1;i<100 && saida!=0;i++){
        cout<<"\nCodigo da Consulta:";
        cin>>v[i].codigo;
        cout<<"\nCodigo do Animal:";
        cin>>v[i].codigo_animal;
        buscarAnimal( v, b, c,d, i, contAnimal, contRaca);
        cout<<"\nCodigo do veterinario:";
        cin>>v[i].codigo_veterinario;
        buscarVeterinario(v, vet, cid, i, contVet, contCid);
        cout<<"\nData da consulta:";
        cin>>v[i].data;
        cout<<"\nValor da consulta:";
        cin>>v[i].valor;
        contConsulta++;
        cout<<"\ndigite 0 para parar:";
        cin>>saida;
    }
}
