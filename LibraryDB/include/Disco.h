#ifndef DISCO_H
#define DISCO_H
#include "Material.h"

class Disco: public Material
{
    public:
        Disco();
        Disco(int id, string t, int d);
        void setDuracion(int d) {duracion=d;};
        int getDuracion(){return duracion;};
        void muestra();
        int cantDiasPrestamo() {return 3;};

    private:
        int duracion;
};

Disco::Disco() : Material() {
    duracion=0;
}
Disco::Disco(int id, string t, int d) : Material(id, t) {
    duracion=d;
}
void Disco::muestra(){
    cout << "Disco: " << idMaterial << " " << titulo << " " << duracion <<  endl;
}

#endif // DISCO_H
