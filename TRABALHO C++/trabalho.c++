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

void leituraCid(struct Cidade v[], int &cont){
    int i=0;
    for(int saida = 1; i<t && saida != 0; i++ ){
        cout<<"Codigo da city:";
        cin>>v[i].codigo;
        cout<<"Nome da city:";
        cin>>v[i].nome;
        cout<<"Uf da city:";
        cin>>v[i].uf;
    }
   cont = i-1;

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

