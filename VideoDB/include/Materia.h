#ifndef MATERIA_H
#define MATERIA_H


class Materia
{
    public:
        Materia() {idMateria=0; nombre="-";}
        Materia(int id, string nom){idMateria=id;nombre=nom;}
        void setIdMateria(int id) {idMateria=id;}
        void setNombre(string nom){nombre=nom;}
        int getIdMateria() {return idMateria;}
        string getNombre() {return nombre;}
        void muestra();

    private:
        int idMateria;
        string nombre;
};

void Materia::muestra() {
    cout << idMateria << " " << nombre << endl;
}

#endif // MATERIA_H
