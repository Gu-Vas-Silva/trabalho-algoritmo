#include<iostream>
#include<conio.h>
#include<string.h>
#define t 2
using namespace std;
struct Cidade {
    int codigo;            
    string nome;
    string uf;        
};

struct Raca {
    int codigo;            
    string descricao;
};

struct Tutor {
    int codigo;            
    string nome;
    float cpf;       
    string endereco;
    int codigo_cidade;     
};

struct Animal {
    int codigo;            
    string nome;
    int codigo_raca;       
    int idade;
    float peso;
    int codigo_tutor;     
};
struct Veterinario {
    int codigo;            
    string nome;
    string endereco;
    int codigo_cidade;     
};

struct Consulta {
    int codigo;                 
    int codigo_animal;         
    int codigo_veterinario;    
    string data;          
    float valor;
};
void registroTutores(Tutor[], Cidade[]);

void leituraCid(struct Cidade v[], int &contCity){
    int i=0;
    for(int saida = 1; i<t && saida != 0; i++ ){
        cout<<"Codigo da city:";
        cin>>v[i].codigo;
        cin.ignore();
        cout<<"Nome da city:";
        getline(cin,v[i].nome);
        cout<<"Uf da city:";
        cin>>v[i].uf;
    }
   contCity = i-1;

}

void leituraRaca(Raca v[], int &contRaca ){
    int i=0;
    for(int saida =1; i<t && saida != 0; i++){
        cout <<"Codigo de Raca:";
        cin >>v[i].codigo;
        cout <<"Descricao do animal:";
        getline(cin,v[i].descricao);
        cin.ignore();
    }

    contRaca = i-1;

}

void leituraTutor(Tutor v[], int &contTutor){
    int i=0;
    for (int saida =1;i<t && saida !=0;i++){
        cout <<"Codigo Tutor:";
        cin>> v[i].codigo;
        cout<<"Nome do Tutor:";
        cin>>v[i].nome;
        cout<<"Cpf do Tutor";
        cin>>v[i].cpf;
        cout<<"Endereco do Tutor";
        cin>>v[i].endereco;
        cout<<"Codigo da Cidade do Tutor:";
        cin>>v[i].codigo_cidade;
    }
    contTutor= i-1;

}
void leituraAnimal(Animal v[], int &contAnimal){
    int i=0;
    for(int saida =1; i<t && saida!=0;i++){
        cout<<"Codigo do Animal:";
        cin>>v[i].codigo;
        cout<<"Nome do Animal:";
        cin>>v[i].nome;
        cout<<"Codigo da Raca:";
        cin>>v[i].codigo_raca;
        cout<<"Idade do Animal:";
        cin>>v[i].idade;
        cout<<"Peso do Animal:";
        cin>>v[i].peso;
        cout<<"Codigo do Tutor:";
        cin>>v[i].codigo_tutor;
    }
    contAnimal=i-1;
}
void leituraVet(Veterinario v[], int &contVet){
    int i=0;
    for(int saida =1;i<t && saida!=0;i++){
        cout<<"Codigo do Vetrinario:";
        cin>>v[i].codigo;
        cout<<"Nome Veterinario:";
        cin>>v[i].nome;
        cout<<"Endereco do Veterinario:";
        cin>>v[i].endereco;
        cout<<"Codigo da Cidade:";
        cin>>v[i].codigo_cidade;
    }
    contVet=i-1;
}

void leituraConsulta(Consulta v[], int &contConsulta){
    int i=0;
    for(int saida=1;i<t && saida!=0;i++){
        cout<<"Codigo da Consulta:";
        cin>>v[i].codigo;
        cout<<"Codigo do Animal:";
        cin>>v[i].codigo_animal;
        cout<<"Codigo do veterinario:";
        cin>>v[i].codigo_veterinario;
        cout<<"Data da consulta:";
        cin>>v[i].data;
        cout<<"Valor da consulta:";
        cin>>v[i].valor;
    }
    contConsulta=i-1;
}
int main(){
    int contcity;
	Cidade cid[t];
	Raca raca[t];
	Tutor tutor[t];
	Animal animal[t];
	Veterinario vet[t];
	Consulta consul[t];
    leituraCid(cid,contcity);
		
}


