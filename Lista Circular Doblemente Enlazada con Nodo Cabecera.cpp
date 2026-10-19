#include <iostream>

using namespace std;
template <typename T>
class ListaCircularDobleCabecera {
private:
	struct Nodo {
		T dato;
		Nodo* siguiente;
		Nodo* anterior;
		
		Nodo() : dato(T()), siguiente(NULL), anterior(NULL) {}
		Nodo(T val, Nodo* sig = NULL, Nodo* ant = NULL)
			: dato(val), siguiente(sig), anterior(ant) {}
	};
	
	Nodo* cabecera;
	
public:
	ListaCircularDobleCabecera() {
		cabecera = new Nodo();
		cabecera->siguiente = cabecera;
		cabecera->anterior = cabecera;
	}
	
	~ListaCircularDobleCabecera() {
		Nodo* actual = cabecera->siguiente;
		while (actual != cabecera) {
			Nodo* temp = actual;
			actual = actual->siguiente;
			delete temp;
		}
		delete cabecera;
	}
	
	void insertarInicio(T val) {
		Nodo* nuevo = new Nodo(val, cabecera->siguiente, cabecera);
		cabecera->siguiente->anterior = nuevo;
		cabecera->siguiente = nuevo;
	}
	
	void insertarFin(T val) {
		Nodo* nuevo = new Nodo(val, cabecera, cabecera->anterior);
		cabecera->anterior->siguiente = nuevo;
		cabecera->anterior = nuevo;
	}
	
	bool eliminarPorValor(T val) {
		Nodo* actual = cabecera->siguiente;
		while (actual != cabecera && actual->dato != val) {
			actual = actual->siguiente;
		}
		if (actual == cabecera) return false;
		
		actual->anterior->siguiente = actual->siguiente;
		actual->siguiente->anterior = actual->anterior;
		delete actual;
		return true;
	}
	
	void mostrarAdelante() const {
		Nodo* actual = cabecera->siguiente;
		cout << "Cabecera <-> ";
		while (actual != cabecera) {
			cout << "[" << actual->dato << "] <-> ";
			actual = actual->siguiente;
		}
		cout << "(Cabecera)\n";
	}
	
	void mostrarAtras() const {
		Nodo* actual = cabecera->anterior;
		cout << "(Cabecera) <-> ";
		while (actual != cabecera) {
			cout << "[" << actual->dato << "] <-> ";
			actual = actual->anterior;
		}
		cout << "Cabecera\n";
	}
};

int main() {
	ListaCircularDobleCabecera<int> lista;
	
	cout << "--- Insertando elementos ---\n";
	lista.insertarFin(10);
	lista.insertarFin(20);
	lista.insertarInicio(5);
	lista.insertarFin(30);
	
	lista.mostrarAdelante();
	lista.mostrarAtras();
	
	cout << "\n--- Eliminando el valor 20 ---\n";
	lista.eliminarPorValor(20);
	lista.mostrarAdelante();
	
	cout << "\n--- Eliminando el primer elemento (5) ---\n";
	lista.eliminarPorValor(5);
	lista.mostrarAdelante();
	
	return 0;
}
