#ifndef TEMA_H
#define TEMA_H


class Tema
{
    public:
        Tema();
        Tema(int idT, string nom, int idM);
        void setIdTema(int id) {idTema=id;}
        void setNombre(string nom) {nombre=nom;}
        void setIdMateria(int id) {idMateria=id;}
        int getIdTema() {return idTema;}
        string getNombre() {return nombre;}
        int getIdMateria() {return idMateria;}
        void muestra();

    private:
        int idTema;
        string nombre;
        int idMateria;
};

    Tema::Tema() {
        idTema=0;
        nombre="-";
        idMateria=0;
    }
    Tema::Tema(int idT, string nom, int idM) {
        idTema=idT;
        nombre=nom;
        idMateria=idM;
    }
    void Tema::muestra() {
        cout << idTema << " " << idMateria << " " << nombre << endl;
    }

#endif // TEMA_H
