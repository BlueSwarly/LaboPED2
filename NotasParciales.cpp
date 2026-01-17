#include <iostream>

using namespace std;

class Estudiante{
    public:
    string nombre;
    float notaf;
    
    Estudiante estudiantes(string n, float no){
        nombre =n;
        notaf =no;
    }   
    void imprimir()
{ cout<<nombre<<"su nota final es "<<notaf<<endl;
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

void ListaEnlazada::imprimirLista(void){

    nodo* actual = head;

    while(actual != nullptr)
    {
        cout << "Nombre: "<< actual->dato.nombre<< endl;
        actual = actual->sig;
    }
}

int main() {
    ListaEnlazada lista;
    int opcion;

    do {
        cout << "1. Agregar estudiante" << endl
            << "2. Listas de estudiantes" << endl
            << "3. Promedio de notas" << endl
            << "4. Salir" << endl;
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