#include <iostream>

using namespace std;

template <typename T>
class ListaDobleCabecera {
private:
	struct Nodo {
		T dato;
		Nodo* siguiente;
		Nodo* anterior;
		Nodo(T val = T(), Nodo* sig = nullptr, Nodo* ant = nullptr)
			: dato(val), siguiente(sig), anterior(ant) {}
	};
	
	Nodo* cabecera; 
	
public:
	ListaDobleCabecera() {
		cabecera = new Nodo(); 
		cabecera->siguiente = nullptr;
		cabecera->anterior = nullptr;
	}
	
	~ListaDobleCabecera() {
		Nodo* actual = cabecera;
		while (actual != nullptr) {
			Nodo* temp = actual;
			actual = actual->siguiente;
			delete temp;
		}
	}
	
	void insertarInicio(T val) {
		Nodo* nuevo = new Nodo(val, cabecera->siguiente, cabecera);
		if (cabecera->siguiente != nullptr) {
			cabecera->siguiente->anterior = nuevo;
		}
		cabecera->siguiente = nuevo;
	}
	
	void insertarFin(T val) {
		Nodo* actual = cabecera;
		while (actual->siguiente != nullptr) {
			actual = actual->siguiente;
		}
		Nodo* nuevo = new Nodo(val, nullptr, actual);
		actual->siguiente = nuevo;
	}
	
	bool eliminarPorValor(T val) {
		Nodo* actual = cabecera->siguiente;
		while (actual != nullptr && actual->dato != val) {
			actual = actual->siguiente;
		}
		if (actual == nullptr) return false;
		
		actual->anterior->siguiente = actual->siguiente;
		if (actual->siguiente != nullptr) {
			actual->siguiente->anterior = actual->anterior;
		}
		delete actual;
		return true;
	}
	
	void mostrarAdelante() const {
		Nodo* actual = cabecera->siguiente;
		cout << "Cabecera <-> ";
		while (actual != nullptr) {
			cout << "[" << actual->dato << "] <-> ";
			actual = actual->siguiente;
		}
		cout << "nullptr\n";
	}
	
	void mostrarAtras() const {
		Nodo* actual = cabecera;

		while (actual->siguiente != nullptr) {
			actual = actual->siguiente;
		}
		
		cout << "nullptr <-> ";
		while (actual != cabecera) {
			cout << "[" << actual->dato << "] <-> ";
			actual = actual->anterior;
		}
		cout << "Cabecera\n";
	}
};

int main() {
	ListaDobleCabecera<int> lista;
	
	cout << "--- Insertando elementos ---\n";
	lista.insertarInicio(10); 
	lista.insertarInicio(20); 
	lista.insertarFin(30);   
	
	cout << "Mostrando hacia adelante:\n";
	lista.mostrarAdelante();
	
	cout << "\nMostrando hacia atras (usando punteros 'anterior'):\n";
	lista.mostrarAtras();
	
	cout << "\n--- Eliminando el valor 10 ---\n";
	lista.eliminarPorValor(10);
	lista.mostrarAdelante();
	
	cout << "\n--- Eliminando el valor 20 ---\n";
	lista.eliminarPorValor(20);
	lista.mostrarAdelante();
	
	return 0;
}
