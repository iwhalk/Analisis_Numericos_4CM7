#include <iostream>
#include <cmath>

using namespace std;

class Gauss{
	double resultado, **matriz;
	int filas, columnas;
	public:
		void Parametros();
		void Matriz();
};

void Gauss::Parametros(){
	int i, j;
	
	filas = 4;
	columnas = 3;
	matriz = new double*[filas];
	for(int i=0; i < filas; i++){
		matriz[i] = new double[columnas];
	}
	
	i = 0;
	
	cout<<"\n Introduzca los elementos de la matriz\n ";
	for(int i = 0; i<filas; i++){
		for(j=0; j<columnas; j++){
			cout<<"Digite un numero ["<<i<<"]["<<j<<"]: ";
			cin>>*(*(matriz + i )+ j);
		}
	}
	
}

void Gauss::Matriz(){
	int i,j;
	cout<<"\n\n La Matriz es: "<<endl;
	for(i = 0; i < filas; i++){
		for(j = 0; j < columnas; j++){
			cout<<*(*(matriz + i )+ j)<<" ";	
		}
		cout<<"\n";
	}
}

int main(void){
	Gauss A;
	
	A.Parametros();
	A.Matriz();
	
	return 0;
}

