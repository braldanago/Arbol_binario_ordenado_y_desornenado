//BRAYAN STEVEN ALDANA GOMEZ 20152020042
//DIEGO DAYAN GUERRA 20152020024

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <queue>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

struct Nodo{
	int dato;
	Nodo *izq;
	Nodo *der;
};

//////////////////*/*/ ARBOL BINARIO DESORDENADO /*/*/*//////////////////////
class ArbolBinario{
	protected: Nodo *raiz;
	
	//Metodos
	public:
	ArbolBinario();
	Nodo *agregar(Nodo *, int);//agrega un nodo al arbol
	int eliminar();///elimina una hoja al azar y retorna el elemento eliminado
	void mostrarPreorden(Nodo *);//muestra en preorden el arbol
	void mostrarInorden(Nodo *);	//muestra en inorden el arbol
	void mostrarPostorden(Nodo *);//muestra en postorden el arbol
	void mostrarNiveles(Nodo *);	//muestra los niveles que conforman el arbol
	int contarHojas(Nodo *); //cantidad de hojas en el arbol
	int cantidadNodos(Nodo *); //cantidad de nodos que conforman el arbol
	int profundidad(Nodo *);//Calcular la altura o profundidad del arbol
	bool completo(Nodo *);//determinar si es completo o no
	Nodo *buscar(Nodo *,int);//busca recursivamente algun nodo en el arbol
	Nodo *getRaiz();//getter raiz
	void setRaiz(Nodo *);//setter raiz
			
};

ArbolBinario::ArbolBinario(){//constructor de la clase ArbolBinario
	raiz=NULL;
}

Nodo *ArbolBinario::getRaiz(){
	return raiz;
}

void ArbolBinario::setRaiz(Nodo *raiz){
	this->raiz=raiz;
}
Nodo * ArbolBinario::agregar(Nodo *raiz, int dato){//Metodo para agregar nodos al arbol
	if(raiz){
		int rama=rand()%2;
		if(rama==0){
			raiz->izq=agregar(raiz->izq,dato);
		}else{
			raiz->der=agregar(raiz->der,dato);
		}
	}else{
		raiz= new Nodo;
		raiz->dato=dato;
		raiz->izq=NULL;
		raiz->der=NULL;
	}
	return raiz;
} 

void ArbolBinario::mostrarPreorden(Nodo *raiz){//Metodo para mostrar en preorden el arbol ingresado
	if(raiz){
		cout<<raiz->dato<<" ";
		mostrarPreorden(raiz->izq);
		mostrarPreorden(raiz->der);
	}
	
}

void ArbolBinario::mostrarInorden(Nodo *raiz){//Metodo para mostrar en inorden el arbol ingresado
	if(raiz){
		mostrarInorden(raiz->izq);
		cout<<raiz->dato<<" ";
		mostrarInorden(raiz->der);
	}
	
}

void ArbolBinario::mostrarPostorden(Nodo *raiz){//Metodo para mostrar en postorden el arbol ingresado
	if(raiz){
		mostrarInorden(raiz->izq);
		mostrarInorden(raiz->der);
		cout<<raiz->dato<<" ";
	}
}

Nodo * ArbolBinario::buscar(Nodo *raiz, int dato){//Metodo para buscar un nodo en el arbol
	Nodo *valor;
	if(raiz){
		valor=buscar(raiz->izq,dato);
		if(raiz->dato==dato){
			return raiz;
		}else if (valor){
			return valor;	
		}else {
			return buscar(raiz->der,dato);
		}
	}else{
		return NULL;
	}
}

int ArbolBinario::eliminar(){//Metodo que elimina algun nodo del arbol al azar
	Nodo *raiz = this->raiz;
	Nodo *aux,*aux2;
	int dato;
	int rama=rand()%2;
	if(raiz && (raiz->izq || raiz->der)){
		while(raiz->izq || raiz->der){
			rama=rand()%2;
			aux2=raiz;
			if((raiz->izq)==NULL){
				aux=raiz->der;
				rama=1;
			}else if((raiz->der)==NULL){
				aux=raiz->izq;
				rama=0;
			}else if(rama==0){
				aux=raiz->izq;
				cout<<"izq"<<aux2->dato<<endl;
			}else{
				aux=raiz->der;
				cout<<"der"<<aux2->dato<<endl;
			}
			raiz=aux;
		}
		if(rama==0){
			aux2->izq=NULL;
		}else{
			aux2->der=NULL;
		}
		dato=raiz->dato;
		delete aux;
		return dato;
	}else if(raiz){
		dato=raiz->dato;
		this->raiz=NULL;
		return dato;
	}
	return -1;
}

void ArbolBinario::mostrarNiveles(Nodo *raiz){//Metodo que muestra los niveles del arbol(las hojas tienen un punto al lado)
	queue<Nodo> cola;
	Nodo *aux;
	cola.push(*raiz);
	int levelNodes ;
	
	while(!cola.empty()){
		levelNodes = cola.size();
		while(levelNodes>0){
			aux=&cola.front();
			cola.pop();
			cout<<aux->dato;
			if(aux->izq){
				cola.push(*aux->izq);
				
			}
			if(aux->der){
				cola.push(*aux->der);
			}
			if(aux->izq==NULL && aux->der==NULL){
				cout<<".";
			}
			levelNodes--;
		}
		cout<<""<<endl;
	}
}

int ArbolBinario::contarHojas(Nodo *raiz){//Metodo contar las hojas del ¡ arbol ingresado
	if(raiz){
		if(raiz->izq==NULL && raiz->der==NULL){
			return 1;
		}
		else{
			return (contarHojas(raiz->izq)+contarHojas(raiz->der));
		}		
	}else{
		return 0;
	}
}


int ArbolBinario::cantidadNodos(Nodo *raiz){//Metodo para mostrar en inorden el arbol ingresado
	if(raiz){
		if(raiz->izq==NULL && raiz->der==NULL){
			return 1;
		}
		else{
			return (cantidadNodos(raiz->izq)+cantidadNodos(raiz->der))+1;
		}		
	}else{
		return 0;
	}	
}

int ArbolBinario::profundidad(Nodo *raiz){//Método para calcular la profundidad del arbol
	int a=0,b=0;
	if(raiz){
		if (raiz->izq == NULL && raiz->der == NULL){
			return 1;
		}else{
			if(raiz->izq){
				a= profundidad(raiz->izq);
			}
			if(raiz->der){
				b= profundidad(raiz->der);
			}
		    if (a<b){
				return b+1;
			}else{
				return a+1;	
			} 
		}
	}else{
		return 0;
	}
	
}

bool ArbolBinario::completo(Nodo *raiz){//Método para determinar si el arbol es completo o no
	queue<Nodo> cola;
	Nodo *aux;
	cola.push(*raiz);
	int levelNodes;
	
	while(!cola.empty()){
		levelNodes = cola.size();
		while(levelNodes>0){
			aux=&cola.front();
			cola.pop();
			if(aux->izq && aux->der){
				cola.push(*aux->der);
				cola.push(*aux->izq);				
			}		
			if((aux->izq!=NULL && aux->der==NULL) || (aux->der!=NULL && aux->izq==NULL)){
				return false;
				break;
			}
			levelNodes--;
		}		
	}
	return true;
}

////////////////////////    CLASE ARBOL BINARIO ORDENADO     /////////////////////////////
class ArbolBinOrd :public ArbolBinario{
	
	public:
	ArbolBinOrd();
	Nodo * agregar(Nodo *,int);//agrega un nuevo nodo para el arbol ordenado
	Nodo * buscar(Nodo *,int);//busca recursivamente un nodo para un arbol orndenado
	Nodo * buscar(int);//busca iterarivamente un nodo en el arbol ordenado
	
};

ArbolBinOrd::ArbolBinOrd(){
	raiz=NULL;
}

Nodo *ArbolBinOrd::agregar(Nodo *raiz, int dato){//Metodo que agrega un nuevo nodo al arbol ordenado
	if(raiz){
		if(raiz->dato>dato){
			raiz->izq=agregar(raiz->izq,dato);
		}else{
			raiz->der=agregar(raiz->der,dato);
		}
	}else{
		raiz= new Nodo;
		raiz->dato=dato;
		raiz->izq=NULL;
		raiz->der=NULL;
	}
	return raiz;
}

Nodo *ArbolBinOrd::buscar(Nodo *raiz, int dato){///Método que busca un nodo recursivamente ////
	if(raiz){
		if(raiz->dato==dato){
			return raiz;
		}else if(raiz->dato>dato){
			return buscar(raiz->izq,dato);
		}else{
			return buscar(raiz->der,dato);
		}
	}
	return raiz;
}

Nodo *ArbolBinOrd::buscar(int dato){//////Método que busca un nodo iterarivamente en el arbol
	Nodo *p=this->raiz;
	while(p){
		if(p->dato==dato){
			return p;
		}else if(p->dato>dato){
			p=p->izq;
		}else{
			p=p->der;
		}
	}
	return p;
}


/// /// FIN CLASE ARBOL BINARIO ORDENADO /// ///*/*/*/*/*//**/*/*/*/*/*/*/*/*/*/


char menu2();//
char menuPrincipal();
void opcMenu2(ArbolBinario);
void opcMenu3(ArbolBinOrd);

//    //    MAIN    //   //
int main(int argc, char** argv) {
	srand(time(NULL));
	int opcion,dato;
	Nodo *raiz,*resultado;
	ArbolBinario arbol;
	ArbolBinOrd arbolOrd;
	do{
		opcion=menuPrincipal();
		switch(opcion){
			case 'b':
			case 'B':{//Opcion para arbol binario desordenado
				opcMenu2(arbol);//Método para las opciones del arbol binario desordenado
				break;
			}
			case 'o'://Opcion para el arbol ordenado
			case 'O':{
				opcMenu3(arbolOrd);
				break;
			}
		}
	}while(opcion != 't' && opcion != 'T');   
	return 0;
}

char menuPrincipal(){//Metodo para las opciones del menu principal
	char opcion;
	cout<<"\nBienvenido, seleccione una opcion: \n"<<endl;
	cout<<"(B)inario"<<endl;
	cout<<"Binario (O)rdenado"<<endl;
	cout<<"(T)erminar"<<endl;
	cin>>opcion;
	return opcion;
}

char menu2(){//MENU SECUNDARIO
	char opcion;
	cout<<"\nBienvenido, seleccione una opcion: \n"<<endl;
	cout<<"(A)gregar"<<endl;
	cout<<"(E)liminar"<<endl;
	cout<<"(M)ostrar"<<endl;
	cout<<"(B)uscar"<<endl;
	cout<<"(C)ontar"<<endl;
	cout<<"(P)rofundidad"<<endl;
	cout<<"Complet(O)"<<endl;
	cout<<"(R)egresar"<<endl;
	cin>>opcion;
	return opcion;
}

void opcMenu2(ArbolBinario arbol){//Método para las opciones del arbol binario desordenado
	srand(time(NULL));
	int opcion,dato;
	Nodo *raiz,*resultado;
	do{
		opcion=menu2();
		switch(opcion){
			case 'a':
			case 'A':{//Opcion agregar
				cout<<"Digite el elemento: ";
				cin>>dato;
				raiz=arbol.getRaiz();
				arbol.setRaiz(arbol.agregar(raiz,dato));
				break;
			}
			case 'e'://Opcion eliminar
			case 'E':{
				int resultado =arbol.eliminar();
				if(resultado!=(-1)){
					cout<<"Se eliminara una hoja: "<<resultado<<endl;	
				}else{
					cout<<"No hay elementos en el arbol"<<endl;
				}
    			break;
			}
			case 'm'://Opcion mostrar
			case 'M':{
				char opc;
				cout<<"(P)reorden"<<endl;
				cout<<"(I)norden"<<endl;
				cout<<"Post(O)rden"<<endl;
				cout<<"(N)iveles"<<endl;
				cout<<"Ingrese su opcion: ";
				cin>>opc;
				raiz=arbol.getRaiz();
				
				if(opc=='P' || opc=='p'){
					cout<<"Arbol en preorden: ";
					arbol.mostrarPreorden(raiz);
				}else if (opc=='I' || opc=='i'){
					cout<<"\nArbol en inorden: ";
					arbol.mostrarInorden(raiz);
				}else if(opc=='o' || opc=='O'){
					cout<<"\nArbol en postorden: ";
					arbol.mostrarPostorden(raiz);
				}else if(opc=='N' || opc=='n'){
					cout<<"Nota: las hojas tienen un punto al lado derecho"<<endl;
					cout<<"Niveles del arbol: "<<endl;
					arbol.mostrarNiveles(raiz);
				}
				break;
			}
			case 'b':
			case 'B':{//Opcion buscar
						
				cout<<"Digite el elemento a buscar: ";
				cin>>dato;
				resultado=arbol.buscar(raiz,dato);
				if(resultado){
					cout<<"El valor fue encontrado"<<endl;
				}else{
					cout<<"El valor no fue encontrado\n"<<endl;
				}
				break;
			}
			case 'c':
			case 'C':{//Opcion de contar 
				char opc;
				cout<<"(N)odos"<<endl;
				cout<<"(H)ojas"<<endl;
				cout<<"Ingrese su opcion: ";
				cin>>opc;
				raiz=arbol.getRaiz();
				
				if(opc=='H' || opc=='h'){
					int numero=0;
					cout<<"La cantidad de hojas del arbol es: ";
					numero=arbol.contarHojas(raiz);
					cout<<numero<<endl;
					
				}else if(opc=='N' || opc=='n'){
					cout<<"Cantidad de nodos en el arbol: ";
					cout<<arbol.cantidadNodos(raiz);
				}
				break;
			}
			case 'p':
			case 'P':{//Calcular la profundidad del arbol(número de niveles)
				raiz=arbol.getRaiz();
				cout<<"La profundidad del arbol es: ";
				cout<<arbol.profundidad(raiz);
				break;
			}
			case 'o':
			case 'O':{//determinar si el arboles completo o no
				raiz=arbol.getRaiz();
				if(arbol.completo(raiz)){
					cout<<"El arbol es completo";
				}else{
					cout<<"El arbol es no es completo";
				}
				break;
			}
		}
	}while(opcion != 'r' && opcion != 'R'); 
}

void opcMenu3(ArbolBinOrd arbol){//Método para las opciones del arbol binario ordenado
	srand(time(NULL));
	int opcion,dato;
	Nodo *raiz,*resultado;
	do{
		opcion=menu2();
		switch(opcion){
			case 'a':
			case 'A':{//Opcion agregar
				cout<<"Digite el elemento: ";
				cin>>dato;
				raiz=arbol.getRaiz();
				arbol.setRaiz(arbol.agregar(raiz,dato));
				break;
			}
			case 'e'://Opcion eliminar
			case 'E':{
				int resultado =arbol.eliminar();
				if(resultado!=(-1)){
					cout<<"Se eliminara una hoja: "<<resultado<<endl;	
				}else{
					cout<<"No hay elementos en el arbol"<<endl;
				}
    			break;
			}
			case 'm'://Opcion mostrar
			case 'M':{
				char opc;
				cout<<"(P)reorden"<<endl;
				cout<<"(I)norden"<<endl;
				cout<<"Post(O)rden"<<endl;
				cout<<"(N)iveles"<<endl;
				cout<<"Ingrese su opcion: ";
				cin>>opc;
				raiz=arbol.getRaiz();
				
				if(opc=='P' || opc=='p'){
					cout<<"Arbol en preorden: ";
					arbol.mostrarPreorden(raiz);
				}else if (opc=='I' || opc=='i'){
					cout<<"\nArbol en inorden: ";
					arbol.mostrarInorden(raiz);
				}else if(opc=='o' || opc=='O'){
					cout<<"\nArbol en postorden: ";
					arbol.mostrarPostorden(raiz);
				}else if(opc=='N' || opc=='n'){
					cout<<"Nota: las hojas tienen un punto al lado derecho"<<endl;
					cout<<"Niveles del arbol: "<<endl;
					arbol.mostrarNiveles(raiz);
				}
				break;
			}
			case 'b':
			case 'B':{//Opcion buscar
						
				cout<<"Digite el elemento a buscar: ";
				cin>>dato;
				resultado=arbol.buscar(raiz,dato);
				if(resultado){
					cout<<"El valor fue encontrado"<<endl;
				}else{
					cout<<"El valor no fue encontrado\n"<<endl;
				}
				resultado=arbol.buscar(dato);
				if(resultado){
					cout<<"El valor fue encontrado iterativamente"<<endl;
				}else{
					cout<<"El valor no fue encontrado iterativamente\n"<<endl;
				}
				break;
			}
			case 'c':
			case 'C':{//Opcion de contar 
				char opc;
				cout<<"(N)odos"<<endl;
				cout<<"(H)ojas"<<endl;
				cout<<"Ingrese su opcion: ";
				cin>>opc;
				raiz=arbol.getRaiz();
				
				if(opc=='H' || opc=='h'){
					int numero=0;
					cout<<"La cantidad de hojas del arbol es: ";
					numero=arbol.contarHojas(raiz);
					cout<<numero<<endl;
					
				}else if(opc=='N' || opc=='n'){
					cout<<"Cantidad de nodos en el arbol: ";
					cout<<arbol.cantidadNodos(raiz);
				}
				break;
			}
			case 'p':
			case 'P':{//Calcular la profundidad del arbol(número de niveles)
				raiz=arbol.getRaiz();
				cout<<"La profundidad del arbol es: ";
				cout<<arbol.profundidad(raiz);
				break;
			}
			case 'o':
			case 'O':{//determinar si el arboles completo o no
				raiz=arbol.getRaiz();
				if(arbol.completo(raiz)){
					cout<<"El arbol es completo";
				}else{
					cout<<"El arbol es no es completo";
				}
				break;
			}
		}
	}while(opcion != 'r' && opcion != 'R'); 
}

