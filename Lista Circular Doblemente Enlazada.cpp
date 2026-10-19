#include <iostream>

using namespace std;

template <typename T>
class ListaCircularDoble {
private:
	struct Nodo {
		T dato;
		Nodo* siguiente;
		Nodo* anterior;
		
		Nodo(T val, Nodo* sig = NULL, Nodo* ant = NULL)
			: dato(val), siguiente(sig), anterior(ant) {}
	};
	
	Nodo* cabeza;
	
public:
	ListaCircularDoble() : cabeza(NULL) {}
	
	~ListaCircularDoble() {
		if (!cabeza) return;
		Nodo* actual = cabeza;
		cabeza->anterior->siguiente = NULL; 
		while (actual != NULL) {
			Nodo* temp = actual;
			actual = actual->siguiente;
			delete temp;
		}
	}
	
	void insertarInicio(T val) {
		if (cabeza == NULL) {
			cabeza = new Nodo(val);
			cabeza->siguiente = cabeza;
			cabeza->anterior = cabeza;
		} else {
			Nodo* ultimo = cabeza->anterior;
			Nodo* nuevo = new Nodo(val, cabeza, ultimo);
			cabeza->anterior = nuevo;
			ultimo->siguiente = nuevo;
			cabeza = nuevo;
		}
	}
	
	void insertarFin(T val) {
		insertarInicio(val);
		cabeza = cabeza->siguiente;
	}
	
	bool eliminarPorValor(T val) {
		if (cabeza == NULL) return false;
		
		Nodo* actual = cabeza;
		do {
			if (actual->dato == val) {
				if (actual->siguiente == actual) { 
					cabeza = NULL;
				} else {
					actual->anterior->siguiente = actual->siguiente;
					actual->siguiente->anterior = actual->anterior;
					if (actual == cabeza) cabeza = actual->siguiente;
				}
				delete actual;
				return true;
			}
			actual = actual->siguiente;
		} while (actual != cabeza);
		
		return false;
	}
	
	void mostrarAdelante() const {
		if (!cabeza) {
			cout << "Lista vacia\n";
			return;
		}
		Nodo* actual = cabeza;
		cout << "Adelante: ";
		do {
			cout << "[" << actual->dato << "] <-> ";
			actual = actual->siguiente;
		} while (actual != cabeza);
		cout << "(inicio)\n";
	}
	
	void mostrarAtras() const {
		if (!cabeza) {
			cout << "Lista vacia\n";
			return;
		}
		Nodo* actual = cabeza->anterior;
		cout << "Atras:    ";
		do {
			cout << "[" << actual->dato << "] <-> ";
			actual = actual->anterior;
		} while (actual != cabeza->anterior);
		cout << "(fin)\n";
	}
};

int main() {
	ListaCircularDoble<int> lista;
	
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
	
	cout << "\n--- Eliminando la cabeza (5) ---\n";
	lista.eliminarPorValor(5);
	lista.mostrarAdelante();
	
	return 0;
}
