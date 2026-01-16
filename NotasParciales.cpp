#include <iostream>

using namespace std;

struct Estudiante{
    string nombre;
    int NotaFinal;
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

void ListaEnlazada::imprimirLista(void){

    nodo* actual = head;

    while(actual != nullptr)
    {
        cout << "Nombre: "<< actual->dato.nombre<< endl;
        actual = actual->sig;
    }
}
