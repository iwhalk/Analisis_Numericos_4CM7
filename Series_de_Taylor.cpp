#include <iostream>
#include <cmath>

using namespace std;

double factorial = 1;//Por la recursividad  la variable factorial es global

class Taylor{
	double euler, margen;
	int num;
	public:
		Taylor(double, int, double);
		double Calcular_euler(int);
		double error(double);
};

Taylor::Taylor(double _euler, int _num, double _margen){
	euler = _euler;//Valor predefinido de e
	num = _num;//Entero que indica el numero de terminos de la serie
	margen = _margen;// va a indicar el margen de error tolerable, ejemplo: 0.0001
}

/*
Función recursiva que 'e' con la serie de Taylor

Acepta un entero ´n´ que utiliza para determinar el numero de recursiones que va a realizar la funcion (el if (n == 0) indica el fin de la recursion)
*/

double Taylor::Calcular_euler(int n){
	
	double termino_pasado;
	
	if (n == 0)
		return 1;
			
	termino_pasado = Calcular_euler(n-1);
	factorial = factorial * n; //calcula el factorial correspondiente al termino definido por n
	
	return  (termino_pasado + (1/factorial));
}

/*
Función que determina cuantas veces se va a iterar la función Taylor, compara lo que retorna Taylor con el parametro actual de iteraciones (dado por num) y la compara con el valor 'real' de e,
si la diferencia entre ellas es mayor a la tolerancia de error se repite.
*/

double Taylor::error(double margen){
	
	double error = 1;
	
	while(error > margen){
		error = fabs(euler - Calcular_euler(num));//El "fabs" es redundante, lo puse para complacer a la profesora
		factorial = 1;
		num = num + 1;
	}
	return Calcular_euler(num);
}

int main(void){

    cout<<"La constante de euler es igual a: "<<endl;
    
    Taylor s1(2.7182818284590455,1,0);//se crea objeto con el numero 'e' de referencia, '1' y '0' solo son para inicializar el objeto
    
    cout.precision(16);//se establece la presicion en 16 digitos
    cout<<s1.error(0.000000001);
    
    return 0;
}


