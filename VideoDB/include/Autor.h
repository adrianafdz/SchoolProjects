#ifndef AUTOR_H
#define AUTOR_H


class Autor
{
    public:
        Autor() {idAutor=0; nombre="-";}
        Autor(int id, string nom) {idAutor=id; nombre=nom;}
        int getIdAutor(){return idAutor;}
        string getNombre() {return nombre;}
        void setIdAutor(int id) {idAutor=id;}
        void setNombre(string nom) {nombre=nom;}
        void muestra();

    private:
        int idAutor;
        string nombre;
};

void Autor::muestra() {
    cout << idAutor << " " << nombre << endl;
}


#endif // AUTOR_H
