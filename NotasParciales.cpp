#include<iostream>
using namespace std;
class Estudiante{
    private:
    string nombre;
    float notaf;
    public:
    Estudiante estudiantes(string n, float no){
        nombre =n;
        notaf =no;
    }   
    void imprimir()
{ cout<<nombre<<"su nota final es "<<notaf<<endl;
}
};