#ifndef LIBRO_H
#define LIBRO_H
#include "Material.h"

class Libro: public Material
{
    public:
        Libro();
        Libro(int id, string t, int n, string a);
        void setNumPag(int n) {numPag=n;};
        void setAutor(string a) {autor=a;};
        int getNumPag() {return numPag;};
        string getAutor(){return autor;};
        void muestra();
        int cantDiasPrestamo() {return 10;};
    private:
        int numPag;
        string autor;
};

Libro::Libro() : Material() {
    numPag=0;
    autor="-";
}
Libro::Libro(int id, string t, int n, string a) : Material(id, t) {
    numPag=n;
    autor=a;
}
void Libro::muestra(){
    cout << "Libro: " << idMaterial << " " << titulo << " " << numPag << " " << autor <<  endl;
}

#endif // LIBRO_H
