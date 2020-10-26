#include <iostream>
#include <cmath>

using namespace std;

class Punto_fijo{
	double valor_inicial, margen, valorx;
	int ceros;
	public:
		Punto_fijo(double, double, int);
		double Iteracionador();
		void leer();
		void escribir();
		double f(double);
		double df(double);
};

double double Punto_fijo::f(double){
	return ( pow(x, 2) - 7 );
}

double double Punto_fijo::df(double){
	return ( x );
}
/*Constructor*/
Punto_fijo::Punto_fijo(double _valor_inicial, double _margen, int _ceros){
	valor_inicial = _valor_inicial;
	margen = _margen;// va a indicar el margen de error tolerable, ejemplo: 0.0001
	ceros = _ceros;//Cantidad de presicion en ceros
}

/*Función para leer y establecer la presicion deseada*/
void Punto_fijo::leer(){
	
	cout<<"Programa del punto fijp para X^2 -1/2"<<endl;
	cout<<"Cuantos Ceros de presición quieres en el resultado (hasta 15): ";
	cin>>ceros;//
	
	valor_inicial = -0.6;//Se establece el valor el cual se va a tomar como valor inicial
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
	int i;
	
	do{
		valor_nuevo = pow(iteracion_pasada,2) -(0.5) + iteracion_pasada; //`valor_nuevo` almacena el valor del punto fijo con el valor de la iteracion pasada, en el caso de la primera iteracion `iteracion_pasada` va a tener como valor `valor_inicial`
		
		error = fabs( (valor_nuevo - iteracion_pasada) / valor_nuevo ); //`error` calcula el error relativo en base a los valores de la iteracion en cuestion  y la pasada
		
		cout.precision(ceros);//Establece cuantos decimales se van a imprimir en pantalla
		cout<<i<<"\t iteracion pasada: "<<iteracion_pasada<<" valor nuevo: "<<valor_nuevo<<" error relativa: "<<error<<" margen: "<<margen<<endl;//Esta linea solo despliega informacion
		i++;//contador para seguir el numero de iteraciones
		
		iteracion_pasada = valor_nuevo; //Antes de pasar a la siguiente iteracion se asigna el valor de la iteracion pasada a el valor de la iteracion actual
		
		
	}while(error > margen);//La condicion de finalizacion se cumple cuando el error relativo es mayor al margen que establecimos anterior mente
	//Ejemplo, 0.00005994 > 0.0001 es falso, por lo tanto se sale del ciclo
	
	return valor_nuevo;//Regresa el valor que adquiro `valor_nuevo` de la ultima iteracion
}

int main(void){

    Punto_fijo s1(0,0,0);
    
    s1.leer();
    s1.escribir();
    
    return 0;
}
