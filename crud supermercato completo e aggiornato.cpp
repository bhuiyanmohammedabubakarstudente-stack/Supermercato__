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


bool modifica(prodotto elenco[], int dim, int indice, prodotto nuovo) {
    if (indice >= 0 && indice < dim) {
        elenco[indice] = nuovo;
        return true;
    }
    return false;
}

int cancella(prodotto elenco[], int dim, int indice) {
    // Partiamo dall'indice del prodotto da eliminare
    // e spostiamo tutti i successivi a sinistra
    for (int i = indice; i < dim - 1; i++) {
        elenco[i] = elenco[i + 1];
    }
    
    // Diminuiamo la dimensione logica dell'array
    dim--; 
    return dim;
}
int main(){
//dichiarazioni delle variabili
prodotto  p;
prodotto elenco[100];
int n=0;
int pos;
string y;
int indice;
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
	case 4:
	cout << "Prodotto da sovrascrivere: "; cin >> y;
    indice = ricerca(y, elenco, n);
    if (indice != -1) {
    prodotto nuovo;
    cout << "Nuovo nome: "; cin >> nuovo.nome;
    cout << "Nuova categoria: "; cin >> nuovo.categoria;
    cout << "Nuovo prezzo: "; cin >> nuovo.prezzo;
    modifica(elenco, n, indice, nuovo);
    cout << "Modifica completata!" << endl;
    } 
    else {
    cout << "Prodotto non trovato." << endl;
    }
    break;
	
	// CANCELLAZIONE
	case 5: 
    string prodottoDaEliminare;
    cout << "Inserisci il nome del prodotto da cancellare: ";
    cin >> prodottoDaEliminare;

    // 1. Cerchiamo l'indice
     indice = ricerca(prodottoDaEliminare, elenco, n);

    if (indice != -1) {
        // 2. Prodotto trovato, eseguiamo la cancellazione "fisica"
        n = cancella(elenco, n, indice); 
        cout << "Prodotto eliminato con successo. Nuova dimensione: " << n << endl;
    } else {
        // 3. Gestione errore
        cout << "Errore: Prodotto '" << prodottoDaEliminare << "' non trovato." << endl;
    }
    break;
}

}
while (scelta!=0);
	
}