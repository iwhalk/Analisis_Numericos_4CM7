#include <iostream>
#include <cmath>

using namespace std;

class Punto_fijo{
	double valor_inicial, margen, x;
	int ceros;
	public:
		Punto_fijo(double, double, double, int);
		double Iteracionador();
		void leer();
		void escribir();
		double f(double);
		double df(double);
};

/*Funcion a evaluar en el metodo de Newton*/
double Punto_fijo::f(double x){
	return ( pow(x, 2) - 7 );
	//return ( pow(x, 3) - 3*x + 1 );
}

/*Derivada de la funcion*/
double Punto_fijo::df(double x){
	return ( 2 * x );
	//return ( 3 * pow(x, 2) - 3);
}

/*Constructor*/
Punto_fijo::Punto_fijo(double _valor_inicial, double _margen, double _x, int _ceros){
	valor_inicial = _valor_inicial;
	margen = _margen;// va a indicar el margen de error tolerable, ejemplo: 0.0001
	ceros = _ceros;//Cantidad de presicion en ceros
	x = _x;//Variable para iterar las funciones
}

/*Función para leer y establecer la presicion deseada*/
void Punto_fijo::leer(){
	
	cout<<"Programa del punto fijp para X^2 -7"<<endl;
	cin>>x;
	x = x * (M_PI / 180.0);//'M_PI invoca el valor de pi de la libreria math'
	cout<<"Cuantos Ceros de presición quieres en el resultado (hasta 15): ";
	cin>>ceros;//
	
	valor_inicial = 0;
	margen = pow(10,-ceros);//El margen es el valor que se va a utilizar para terminar la funcion que determina el numero iteraciones que se van a realizar
	//Ejemplo, si "ceros" es igual 5, "margen" va tener como valor 0.00001
}

/*Función para escribir el resultado, tambien manda a llamar a la funcion que calcula el resultado */
void Punto_fijo::escribir(){
    double resultado = Iteracionador();
    cout<<"La raiz de la ecuacion es:  ";
	cout.precision(ceros);
    cout<<resultado<<endl;
}

/*Función que calcula la raiz de la ecuacion con el metodo del punto fijo. Retorna la respuesta que solucion la ecuacion como double*/

double Punto_fijo::Iteracionador(){
	
	double iteracion_pasada = valor_inicial;
	double valor_nuevo, error;
	double factorial, numerador;
	float fac = 1;
	int i = 0, j;
	
	do{
		
		numerador = ( pow(-1, i) * pow(x, 2*i+1 ) );
		cout<<"numerador: "<<numerador;
		factorial = 2 * i +1	;
		cout<<"  factorial: "<<factorial;
		
		if(factorial == 0){
			fac = 1;
		}
		else{
			for(j = 1; j <= factorial; j++){
				fac = fac * j;
			}
		}
		
		cout<<" fac: "<<fac;
		
		valor_nuevo = iteracion_pasada + numerador / fac;
		
		error = fabs( (valor_nuevo - iteracion_pasada) / valor_nuevo );
		
		cout<<"  numero veces"<<i<<"\t iteracion pasada: "<<iteracion_pasada<<" Valor del angulo: "<<x<<" valor nuevo: "<<valor_nuevo<<" margen de error: "<<margen<<" error relativo: "<<error<<endl;//Esta linea solo despliega informacion
		iteracion_pasada = valor_nuevo;
		
		i++;
		fac = 1;
		
	}while(error > margen);//La condicion de finalizacion se cumple cuando el error relativo es mayor al margen que establecimos anterior mente
	//Ejemplo, 0.00005994 > 0.0001 es falso, por lo tanto se sale del ciclo
	
	return valor_nuevo;//Regresa el valor que adquiro `valor_nuevo` de la ultima iteracion
}

int main(void){

    Punto_fijo s1(0,0,0,0);
    
    s1.leer();
    s1.escribir();
    
    return 0;
}
