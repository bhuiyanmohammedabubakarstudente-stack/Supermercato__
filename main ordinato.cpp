
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
int ricerca(string y, prodotto x[], int dim){
	for(int i=0;i<dim;i++){
		if(x[i].nome==y  ){
		return i ;
			;
	 
		
	}

}
return -1;
}

void aggiungiOrdinato(prodotto p;prodotto elenco[];int dim){
	for(int i=0;i<dim;i++){
		if(elenco[i].nome[i]==elenco[i+1].nome[i+1]){
			cout<<"Le lettere sono uguali"<<endl;
		}
		else{
			int z=(int)elenco[i].nome[i];
			int x=(int)elenco[i+1].nome[i+1];
			if(z<x){
			elenco[i].nome[i]=p.nome;
			}	
			}
		}
	}



void modifica(prodotto elenco[],int dim){
   string y;
   cout<<"Inserisci il prodotto da sovrascrivere " << endl;
	cin>>y;
	int indice= ricerca(y,elenco,dim);
	if (indice != -1) {
        cout << " Prodotto trovato! Nome: " <<   elenco[indice].nome <<endl;
        
        cout << "Inserisci nuovo nome "  <<endl;
       cin>>elenco[indice].nome;
       
               cout << "Inserisci nuova categoria "  <<endl;
       cin>>elenco[indice].categoria;
        
              cout << "Inserisci nuovo prezzo"  <<endl;
       cin>>elenco[indice].prezzo;
        
        
        
        cout << "Modifica completata con successo!" << endl;
    } else {
        cout << " Prodotto non trovato." << endl;
    }
}

void cancella(prodotto elenco[],int dim, string x){
	
	cout<<"Inserisci il prodotto da cancellare"<<endl;
	cin>>x;
		int indice= ricerca(x,elenco,dim);
			if (indice == -1) {
				cout<<" Prodotto non trovato"<<endl;
}
else{
	cout<<" Prodotto trovato"<<endl;
	for(int i=indice;i<dim;i++){
		elenco[i]=elenco[i+1];
	}
	dim--;
}
}

int main(){
//dichiarazioni delle variabili
prodotto  p;
prodotto elenco[100];
int n=0;
int pos;
string y;
//struttura a menù
int scelta;
do{
//visualizzazione opzioni
cout<<"0 - Fine programma"<<endl;
cout<<"1 - (C)Aggiunta"<<endl;
cout<<"2 - (R)Visualizzazione"<<endl;
cout<<"3 - RICERCA"<<endl;
cout<<"4 - MODIFICA"<<endl;
cout<<"5 - CANCELLAZIONE"<<endl;
///------
cout<<endl;
//scelta dell'opzione
cout<<"scegli l'opzione";

cin>>scelta;
fflush(stdin);
//elaborazione scelta
switch(scelta){
    
    
    // AGGIUNTA
	case 1:
		cout<<"Inserisci il nome ";
		cin>>p.nome;
		cout<<"Inserisci la categoria ";
		cin>>p.categoria;
		cout<<"Inserisci il prezzo ";
		cin>>p.prezzo;
		aggiungi(p,elenco,n);
		break;
		
		// VISUALIZZA
	case 2: 
		
	    cout<<visualizza(elenco,n);
		break;
		
	//RICERCA	
	case 3: cout<<"inserisci il prodotto da cercare"   <<endl;
	cin>>y;
	 pos = ricerca(y, elenco, n);
    if (pos != -1) 
    cout << "Trovato in posizione: " << pos << endl;
    else 
    cout << "Prodotto non trovato." << endl;
    break;
	
	
	//MODIFICA : Trova un prodotto e lo sovrascrivi
	case 4: modifica(elenco,n);
	
	break;	
	
	case 5: 
	cancella(elenco,n,y);
	
	break;
}
}
while (scelta!=0);
	
}
