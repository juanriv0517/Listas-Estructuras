#include <iostream>

using namespace std;

template <typename T>
class ListaSimpleCabecera {
private:
	struct Nodo {
		T dato;
		Nodo* siguiente;
		Nodo(T val = T(), Nodo* sig = nullptr) : dato(val), siguiente(sig) {}
	};
	
	Nodo* cabecera;
	
public:
	ListaSimpleCabecera() {
		cabecera = new Nodo();
	}
	
	~ListaSimpleCabecera() {
		Nodo* actual = cabecera;
		while (actual != nullptr) {
			Nodo* temp = actual;
			actual = actual->siguiente;
			delete temp;
		}
	}
	
	void insertarInicio(T val) {
		Nodo* nuevo = new Nodo(val, cabecera->siguiente);
		cabecera->siguiente = nuevo;
	}
	
	void insertarFin(T val) {
		Nodo* actual = cabecera;
		while (actual->siguiente != nullptr) {
			actual = actual->siguiente;
		}
		actual->siguiente = new Nodo(val);
	}
	
	bool eliminarPorValor(T val) {
		Nodo* actual = cabecera;
		while (actual->siguiente != nullptr && actual->siguiente->dato != val) {
			actual = actual->siguiente;
		}
		if (actual->siguiente == nullptr) return false;
		
		Nodo* aEliminar = actual->siguiente;
		actual->siguiente = aEliminar->siguiente;
		delete aEliminar;
		return true;
	}
	
	void mostrar() const {
		Nodo* actual = cabecera->siguiente;
		cout << "Cabecera -> ";
		while (actual != nullptr) {
			cout << "[" << actual->dato << "] -> ";
			actual = actual->siguiente;
		}
		cout << "nullptr\n";
	}
};

int main() {

	ListaSimpleCabecera<int> lista;
	
	cout << "--- Insertando elementos ---\n";
	lista.insertarInicio(10);
	lista.insertarInicio(20); 
	lista.insertarFin(30);  
	lista.mostrar();
	
	cout << "\n--- Eliminando el valor 10 ---\n";
	lista.eliminarPorValor(10);
	lista.mostrar();
	
	cout << "\n--- Eliminando el valor 20 ---\n";
	lista.eliminarPorValor(20);
	lista.mostrar();
	
	return 0;
}
