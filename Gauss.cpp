#include <iostream>
#include <cmath>

using namespace std;

class Gauss{
	double resultado, **matriz, **matriz_resultante;
	int filas, columnas;
	public:
		void Parametros();
		void Matriz();
};

void Gauss::Parametros(){
	int i, j;
	
	filas = 3;
	columnas = 4;
	
	matriz = new double*[filas];
	for(int i=0; i < filas; i++){
		matriz[i] = new double[columnas];
	}
	
	matriz_resultante = new double*[filas];
	for(int i=0; i < filas; i++){
		matriz_resultante[i] = new double[columnas];
	}
	
	
	
	cout<<"\n Introduzca los elementos de la matriz\n ";
	for(int i = 0; i<filas; i++){
		for(j=0; j<columnas; j++){
			cout<<"Digite un numero ["<<i<<"]["<<j<<"]: ";
			cin>>*(*(matriz + i )+ j);
		}
	}
	
	for(int i = 0; i<filas; i++){
		for(j=0; j<columnas; j++){
			
			matriz_resultante[i][j] = matriz[i][j];
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
	
	for(int i = 1; i<filas; i++){
		for(j=0; j<columnas; j++){
			if(( (matriz[0][0] * matriz[i][0]) * matriz[i][j] ) == ( (matriz[0][0] * matriz[i][0]) * matriz[0][j]))
				matriz_resultante[i][j] = ( (matriz[0][0] * matriz[i][0]) * matriz[i][j] ) - ( (matriz[0][0] * matriz[i][0]) * matriz[0][j]);
			else
				matriz_resultante[i][j] = ( (matriz[0][0] * matriz[i][0]) * matriz[i][j] ) + ( (matriz[0][0] * matriz[i][0]) * matriz[0][j]);
		}
	}

	cout<<"\n\n La Matriz nueva es: "<<endl;
	for(i = 0; i < filas; i++){
		for(j = 0; j < columnas; j++){
			cout<<matriz_resultante[i][j]<<" ";	
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

