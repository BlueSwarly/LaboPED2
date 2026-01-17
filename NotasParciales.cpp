#include <iostream>
#include <string>
using namespace std;


class Estudiante{
public:
    string nombre;
    float notaf;

    Estudiante(){
        nombre = "";
        notaf = 0;
    }

    Estudiante(string n, float no){
        nombre = n;
        notaf = no;
    }

    void imprimir(){
        cout << "Nombre: " << nombre << " | Nota final: " << notaf << endl;
    }
};


struct nodo{
    Estudiante dato;
    nodo *sig;
};


class ListaEnlazada{
private:
    nodo *head;

public:
    ListaEnlazada();
    void AgregarEstudiante(void);
    float calcularPromedioRecursivo(void);
    void imprimirLista(void);
};


ListaEnlazada::ListaEnlazada(){
    head = nullptr;
}


void ListaEnlazada::AgregarEstudiante(void){
    string nombre;
    float nota;

    cout << "Nombre del estudiante: ";
    cin.ignore();
    getline(cin, nombre);

    cout << "Nota final: ";
    cin >> nota;

    nodo* nuevo = new nodo();
    nuevo->dato = Estudiante(nombre, nota);
    nuevo->sig = head;
    head = nuevo;
}


void ListaEnlazada::imprimirLista(void){
    nodo* actual = head;

    while(actual != nullptr){
        actual->dato.imprimir();
        actual = actual->sig;
    }
}


float promedioRecursivoAux(nodo* actual, int &contador){
    if(actual == nullptr){
        return 0;
    }

    contador++;
    return actual->dato.notaf + promedioRecursivoAux(actual->sig, contador);
}


float ListaEnlazada::calcularPromedioRecursivo(void){
    int contador = 0;
    float suma = promedioRecursivoAux(head, contador);

    if(contador == 0){
        cout << "No hay estudiantes registrados." << endl;
        return 0;
    }

    float promedio = suma / contador;
    cout << "Promedio de notas: " << promedio << endl;
    return promedio;
}


int main() {
    ListaEnlazada lista;
    int opcion;

    do {
        cout << "\n1. Agregar estudiante" << endl;
        cout << "2. Lista de estudiantes" << endl;
        cout << "3. Promedio de notas (recursivo)" << endl;
        cout << "4. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            lista.AgregarEstudiante();
            break;
        case 2:
            lista.imprimirLista();
            break;
        case 3:
            lista.calcularPromedioRecursivo();
            break;
        }
    } while (opcion != 4);

    return 0;
}
