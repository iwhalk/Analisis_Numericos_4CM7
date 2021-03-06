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
	int i, j, k;
	
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
	
	for(int k = 0; k < 2; k++){
		for(int i = 1+k; i < filas; i++){
			for(j=0+k; j < columnas; j++){
				matriz[i][j] =  (matriz_resultante[k][k] * matriz[i][j]) - (matriz_resultante[i][0+k] * matriz[k][j]);// -  (matriz[i][k] * matriz[k][j]);
			}
		}
	}
	
	cout<<"\n\n La Matriz nueva es: "<<endl;
	for(i = 0; i < filas; i++){
		for(j = 0; j < columnas; j++){
			cout<<matriz[i][j]<<" ";	
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

