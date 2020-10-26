#include <iostream>
#include <cmath>

using namespace std;

class Gauss{
	double x, y ,z , **matriz, **matriz_resultante;
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
	double aux;
	cout<<"\n\n La Matriz es: "<<endl;
	for(i = 0; i < filas; i++){
		for(j = 0; j < columnas; j++){
			cout<<*(*(matriz + i )+ j)<<" ";	
		}
		cout<<"\n";
	}
	
	for(int i = 1; i<filas; i++){
		for(j=0; j<columnas; j++){
			matriz_resultante[i][j] =  (matriz[0][0] * matriz[i][j] ) -  (matriz[i][0] * matriz[0][j]);
		}
	}
	
	for(int i = 2; i<filas; i++){
		for(j=1; j<columnas; j++){
			matriz_resultante[i][j] =  (matriz[1][1] * matriz[i][j] ) -  (matriz[i][1] * matriz[1][j]);
		}
	}

	cout<<"\n\n La Matriz nueva es: "<<endl;
	for(i = 0; i < filas; i++){
		for(j = 0; j < columnas; j++){
			cout<<matriz_resultante[i][j]<<" ";	
		}
		cout<<"\n";
	}
	
	z = matriz_resultante[2][3]/matriz_resultante[2][2];
	y = (matriz_resultante[1][3] - z*matriz_resultante[1][2])/matriz_resultante[1][1];
	x = (matriz_resultante[0][3] - z*matriz_resultante[0][2] - y*matriz_resultante[0][1])/matriz_resultante[0][0];
	
	cout<<"El valor de x es: "<<x<<"\nEl valor de y es: "<<y<<"\nEl valor de z es: "<<z;
}

int main(void){
	Gauss A;
	
	A.Parametros();
	A.Matriz();
	
	return 0;
}

