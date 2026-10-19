#include <iostream>

using namespace std;

template <typename T>
class ListaCircularSimpleCabecera {
private:
	struct Nodo {
		T dato;
		Nodo* siguiente;
		
		Nodo() : dato(T()), siguiente(NULL) {}
		Nodo(T val, Nodo* sig = NULL) : dato(val), siguiente(sig) {}
	};
	
	Nodo* cabecera;
	
public:
	ListaCircularSimpleCabecera() {
		cabecera = new Nodo();
		cabecera->siguiente = cabecera; 
	}
	
	~ListaCircularSimpleCabecera() {
		Nodo* actual = cabecera->siguiente;
		while (actual != cabecera) {
			Nodo* temp = actual;
			actual = actual->siguiente;
			delete temp;
		}
		delete cabecera;
	}
	
	void insertarInicio(T val) {
		Nodo* nuevo = new Nodo(val, cabecera->siguiente);
		cabecera->siguiente = nuevo;
	}
	
	void insertarFin(T val) {
		Nodo* actual = cabecera;
		while (actual->siguiente != cabecera) {
			actual = actual->siguiente;
		}
		actual->siguiente = new Nodo(val, cabecera);
	}
	
	bool eliminarPorValor(T val) {
		Nodo* actual = cabecera;
		while (actual->siguiente != cabecera && actual->siguiente->dato != val) {
			actual = actual->siguiente;
		}
		if (actual->siguiente == cabecera) return false;
		
		Nodo* aEliminar = actual->siguiente;
		actual->siguiente = aEliminar->siguiente;
		delete aEliminar;
		return true;
	}
	
	void mostrar() const {
		Nodo* actual = cabecera->siguiente;
		cout << "Cabecera -> ";
		while (actual != cabecera) {
			cout << "[" << actual->dato << "] -> ";
			actual = actual->siguiente;
		}
		cout << "(Cabecera)\n";
	}
};

int main() {
	ListaCircularSimpleCabecera<int> lista;
	
	lista.insertarFin(10);
	lista.insertarFin(20);
	lista.insertarInicio(5);
	lista.insertarFin(30);
	
	cout << "Lista actual:\n";
	lista.mostrar();
	
	cout << "\nEliminando el valor 5\n";
	lista.eliminarPorValor(5);
	
	cout << "\nEliminando el valor 20\n";
	lista.eliminarPorValor(20);
	
	
	cout << "\nLista resultante:\n";
	lista.mostrar();
	
	return 0;
}
