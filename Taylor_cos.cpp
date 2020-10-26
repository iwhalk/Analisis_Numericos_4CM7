#include <iostream>
#include <cmath>

using namespace std;

double factorial = 1;//Por la recursividad  la variable factorial es global

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
	ceros = _ceros;//Cantidad de presicion en ceros
}

/*Función para leer el valor del angulo del que el usuario quiera calcular la función de x. Tambien convierte los angulos a radianes
*/
void Taylor::leer(){
	
	cout<<"Ingrese un valor en grados para calcular la funcion coseno: ";
	cin>>valorx;
	cout<<"Cuantos Ceros de presición quieres en el resultado: ";
	cin>>ceros;
	
	valorx = valorx * (M_PI / 180.0);//'M_PI invoca el valor de pi de la libreria math'
	valor = cos(valorx);
	
	margen = pow(10,-ceros);
}

void Taylor::escribir(){
	cout<<"El coseno del angulo es igual a:  "<<endl;
    cout.precision(ceros);
    cout<<error()<<endl;
}

/*
Función recursiva que calcula el coseno de x con la serie de Taylor

Acepta un entero ´n´ que utiliza para determinar el numero de recursiones que va a realizar la funcion (el if (n == 0) indica el fin de la recursion)
*/

double Taylor::Calcular_valor(int n){
	
	double termino_pasado,numerador,fac;
	int i;
	
	fac = 1;
	if (n == 0)
		return 1;
			
	termino_pasado = Calcular_valor(n-1);
	numerador = pow(-1,n) * pow(valorx, 2*n);
	factorial = 2 * n ; //define el numero al cual se le va aplicar el factorial
	for (i = 1; i <= factorial; i++){//Calcula el factorial i veces 
         fac = fac * i;
    }
    
	return(termino_pasado + (numerador/fac));

}

/*
Función que determina cuantas veces se va a iterar la función Taylor, compara lo que retorna Taylor con el parametro actual de iteraciones (dado por num) y la compara con el valor 'real' de la funcion seno,
si la diferencia entre ellas es mayor a la tolerancia de error se repite.
*/

double Taylor::error(){
	
	double error = 1;
	
	while(error > margen){
		error = fabs(valor - Calcular_valor(num));
		factorial = 1;
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
