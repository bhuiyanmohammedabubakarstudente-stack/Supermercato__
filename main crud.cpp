

#include <iostream>
#include <string>
using namespace std;
//strutture e funzioni
struct prodotto{
	string nome;
	string categoria;
	float prezzo;	
};

void aggiungi(prodotto pp, prodotto ele[],int &dim){
	ele[dim]=pp;
	dim++;	
}

string visualizza(prodotto ele[], int dim){
	string s;
	for(int i=0;i<dim;i++){
		s+=ele[i].nome+"\t";
		s+=ele[i].categoria+"\t";
		s+=to_string(ele[i].prezzo)+"\n";
	}
	return s;
}
void ricerca(prodotto p, prodotto x[], int dim){
	for(int i=0;i<dim;i++){
		if(p.nome==x[i].nome && p.categoria==x[i].categoria && p.prezzo==x[i].prezzo ){
			cout<<"posizione trovata: "<< i << endl;
			break;
		}
		else{
			cout<< -1<<endl;
		}
	}

}

int main(){
//dichiarazioni delle variabili
prodotto  p;
prodotto elenco[100];
int n=0;

//struttura a menù
int scelta;
do{
//visualizzazione opzioni
cout<<"1 - (C)Aggiunta"<<endl;
cout<<"2 - (R)Visualizzazione"<<endl;
cout<<"3 - RICERCA"<<endl;
///------
cout<<"0 - Fine programma"<<endl;
//scelta dell'opzione
cout<<"scegli l'opzione";

cin>>scelta;
fflush(stdin);
//elaborazione scelta
switch(scelta){
	case 1:
		cout<<"Inserisci il nome ";
		getline(cin,p.nome);
		cout<<"Inserisci la categoria ";
		getline(cin,p.categoria);
		cout<<"Inserisci il prezzo ";
		cin>>p.prezzo;
		aggiungi(p,elenco,n);
		break;
	case 2: 
		
	    cout<<visualizza(elenco,n);
		break;	
	case 3: cout<< ricerca(p,elenco,n)   <<endl;
	
	break;	
	
}
}
while (scelta!=0);
	
}