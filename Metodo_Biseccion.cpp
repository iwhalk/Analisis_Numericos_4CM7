#include <iostream>
#include <cmath>

using namespace std;

int numero_iteracion = 1;
bool fallo = false;

class Biseccion{
	double auxiliar_inferior, auxiliar_superior, margen;
	int ceros;
	public:
		Biseccion(double, double, double, int);
		double Calcular_valor(double, double);
		double error();
		void leer();
		void escribir();
		double f(double);
};

Biseccion::Biseccion(double _margen, double _auxiliar_inferior, double _auxiliar_superior, int _ceros){
	margen = _margen;// va a indicar el margen de error tolerable, ejemplo: 0.0001
	auxiliar_inferior = _auxiliar_inferior;
	auxiliar_superior = _auxiliar_superior;
	ceros = _ceros;//Cantidad de presicion en ceros
}

/*Función para leer el valor del angulo del que el usuario quiera calcular la función de x. Tambien convierte los angulos a radianes
*/
void Biseccion::leer(){
	
	cout<<"Ingrese el valor inferior del intervalo: ";
	cin>>auxiliar_inferior;
	cout<<"Ingrese el valor superior del intervalo: ";
	cin>>auxiliar_superior;
	cout<<"Presicion en el metodo de biseccion: ";
	cin>>ceros;
	
	margen = pow(10,-ceros);
}

void Biseccion::escribir(){
	
	if (fallo == true)
		cout<<"No hay soluciones en los reales en el intervalo";
	else{
		cout<<"El cero en el intervalo es igual a:  ";
		cout.precision(ceros);
    	double resultado = error();
    	cout<<resultado<<endl;
    }
}



double Biseccion::f(double x){
	//return 2*pow(x,4) - 5*pow(x,3) + 1* pow(x,2) + 4*x - 4;
	return 1*pow(x,4) - 3*pow(x,3) + 5* pow(x,2) - 1*x - 10;
}

double Biseccion::Calcular_valor(double inferior, double superior){
	
	return (inferior + superior) / 2;
}

/*
Función que determina cuantas veces se va a repetir la función Biseccion
*/

double Biseccion::error(){
	
	double producto;
	numero_iteracion++;
	
	if (f(auxiliar_inferior)*f(auxiliar_superior) > 0)
		fallo = true;
		
	while( (fabs( f(Calcular_valor(auxiliar_inferior, auxiliar_superior)) ) > margen) && (fallo == false)){	
		cout<<"iteracion numero: "<<numero_iteracion<<" limite inferior: "<<auxiliar_inferior<<" limite superior: "<<auxiliar_superior<<" punto medio: "<<Calcular_valor(auxiliar_inferior, auxiliar_superior)<<endl;
		producto = f(auxiliar_inferior)*f(Calcular_valor(auxiliar_inferior, auxiliar_superior));
		
		if (producto > 0)
			auxiliar_inferior = Calcular_valor(auxiliar_inferior, auxiliar_superior);
		else if (producto < 0)
			auxiliar_superior = Calcular_valor(auxiliar_inferior, auxiliar_superior);
	}
	
	return Calcular_valor(auxiliar_inferior, auxiliar_superior);
}

int main(void){

    Biseccion s1(0,0,0,0);
    
    s1.leer();
    s1.error();
    s1.escribir();
    
    return 0;
}
