#include <iostream>

using namespace std;

template <typename T>
class ListaCircularSimple {
private:
	struct Nodo {
		T dato;
		Nodo* siguiente;
		Nodo(T val, Nodo* sig = nullptr) : dato(val), siguiente(sig) {}
	};
	
	Nodo* cola; 
	
public:
	ListaCircularSimple() : cola(nullptr) {}
	
	~ListaCircularSimple() {
		if (!cola) return;
		Nodo* actual = cola->siguiente;
		cola->siguiente = nullptr;
		while (actual != nullptr) {
			Nodo* temp = actual;
			actual = actual->siguiente;
			delete temp;
		}
	}
	
	void insertarInicio(T val) {
		if (cola == nullptr) {
			cola = new Nodo(val);
			cola->siguiente = cola;
		} else {
			Nodo* nuevo = new Nodo(val, cola->siguiente);
			cola->siguiente = nuevo;
		}
	}
	
	void insertarFin(T val) {
		insertarInicio(val);
		cola = cola->siguiente;
	}
	
	bool eliminarPorValor(T val) {
		if (cola == nullptr) return false;
		
		Nodo* actual = cola->siguiente;
		Nodo* prev = cola;
		
		do {
			if (actual->dato == val) {
				if (actual == cola && actual == cola->siguiente) { 
					cola = nullptr;
				} else {
					prev->siguiente = actual->siguiente;
					if (actual == cola) cola = prev;
				}
				delete actual;
				return true;
			}
			prev = actual;
			actual = actual->siguiente;
		} while (actual != cola->siguiente);
		
		return false;
	}
	
	void mostrar() const {
		if (cola == nullptr) {
			cout << "Lista vacia\n";
			return;
		}
		Nodo* actual = cola->siguiente;
		do {
			cout << "[" << actual->dato << "] -> ";
			actual = actual->siguiente;
		} while (actual != cola->siguiente);
		cout << "(inicio)\n";
	}
};

int main() {
	ListaCircularSimple<int> lista;
	
	cout << "--- Insertando elementos ---\n";
	lista.insertarInicio(10); 
	lista.insertarInicio(20); 
	lista.insertarFin(30);   
	
	cout << "Mostrando lista circular:\n";
	lista.mostrar();
	
	cout << "\n--- Eliminando el valor 10 ---\n";
	lista.eliminarPorValor(10);
	lista.mostrar();
	
	cout << "\n--- Eliminando el valor 20 ---\n";
	lista.eliminarPorValor(20);
	lista.mostrar();
	
	return 0;
}
