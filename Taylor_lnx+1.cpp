#include <iostream>
#include <cmath>

using namespace std;

class Taylor{
	double valor, margen, valorx;
	int num, ceros;
	public:
		Taylor(double, int, double, double, int);
		double Calcular_valor(int);
		double error();
		void leer();
		void escribir();
};

Taylor::Taylor(double _valor, int _num, double _margen, double _valorx, int _ceros){
	valor = _valor;//Valor predefinido de e
	num = _num;//Entero que indica el numero de terminos de la serie
	margen = _margen;// va a indicar el margen de error tolerable, ejemplo: 0.0001
	valorx = _valorx;//Numero que el usuario ingresa en grados para calcular el seno
	ceros = _ceros;//Cantidad de presicion en ceros  qur 
}

/*Función para leer el valor del angulo del que el usuario quiera calcular la función de x. Tambien convierte los angulos a radianes
*/
void Taylor::leer(){
	
	cout<<"Ingrese un de x para calcular la funcion ln( 1 + x ): ";
	cin>>valorx;
	cout<<"Cuantos Ceros de presición quieres en el resultado: ";
	cin>>ceros;
	
	valor = log(1 + valorx);
	
	margen = pow(10,-ceros);
}

void Taylor::escribir(){
	cout<<"El ln( 1 + x) de x es igual a:  "<<endl;
    cout.precision(ceros);
    cout<<error()<<endl;
}

/*
Función recursiva que calcula el coseno de x con la serie de Taylor

Acepta un entero ´n´ que utiliza para determinar el numero de recursiones que va a realizar la funcion (el if (n == 0) indica el fin de la recursion)
*/

double Taylor::Calcular_valor(int n){
	
	double termino_pasado,numerador;
	
	if (n == 0)
		return valorx;
			
	termino_pasado = Calcular_valor(n-1);
	numerador = pow(-1,n + 1) * pow(valorx, n);
    
	return(termino_pasado + (numerador/n));
}

/*
Función que determina cuantas veces se va a iterar la función Taylor, compara lo que retorna Taylor con el parametro actual de iteraciones (dado por num) y la compara con el valor 'real' de la funcion seno,
si la diferencia entre ellas es mayor a la tolerancia de error se repite.
*/

double Taylor::error(){
	
	double error = 1;
	
	while(error > margen){
		error = fabs(valor - Calcular_valor(num));
		num = num + 1;
	}
	return Calcular_valor(num);
}

int main(void){

    Taylor s1(0,0,0,0,0);
    
    s1.leer();
    s1.error();
    s1.escribir();
    
    return 0;
}
