#ifndef EJEMPLOVIDEO_H
#define EJEMPLOVIDEO_H
#include "Fecha.h"

class EjemploVideo
{
    public:
        EjemploVideo();
        void setIdVideo(int id) {idVideo=id;}
        int getIdVideo() {return idVideo;}
        void setNombre(string n) {nombre=n;}
        string getNombre() {return nombre;}
        void setIdTema(int id) {idTema=id;}
        int getIdTema() {return idTema;}
        void setFecha(Fecha f) {fechaElaboracion=f;}
        Fecha getFecha() {return fechaElaboracion;}
        int getAutor(int i) {return listaAutores[i];}
        bool agregaAutor(int id);
        int getCantAutores() {return cantidadAutores;}
        void muestra(Autor arr[10], int cant, Tema arrT[10], int cantT, Materia arrM[10], int cantM);
        bool estaAutor(int id);

    private:
        int idVideo;
        string nombre;
        int idTema;
        Fecha fechaElaboracion;
        int cantidadAutores;
        int listaAutores[10];
};

EjemploVideo::EjemploVideo() {
    idVideo=0;
    nombre="-";
    idTema=0;
    fechaElaboracion=Fecha();
    cantidadAutores=0;
}

bool EjemploVideo::agregaAutor(int id) {
    if (cantidadAutores==10) {
        cout << "Se llego al limite de autores (10)" << endl;
        return false;
    }
    for (int i=0;i<cantidadAutores; i++) {
        if (id==listaAutores[i]) {
            cout << "Autor con ID " << id << " repetido." << endl;
            return false;
        }
    }
    listaAutores[cantidadAutores]=id;
    cantidadAutores++;
    //cout << "Autor agregado correctamente" << endl;
    return true;
}

void EjemploVideo::muestra(Autor arr[10], int cant, Tema arrT[10], int cantT, Materia arrM[10], int cantM) {
    cout <<"ID video: "<<idVideo<< " Nombre: " << nombre;
    cout << " Tema:" ;
    for (int i=0; i<cantT; i++) {
        if (idTema==arrT[i].getIdTema()) {
            cout << arrT[i].getNombre() << endl;
            cout << "Materia: " ;
            for (int j=0; j<cantM;j++) {
                if (arrT[i].getIdMateria()==arrM[j].getIdMateria()) {
                    cout << arrM[j].getNombre() << endl;
                }
            }
            break;
        }
    }
    cout << "Fecha de elaboracion: ";
    fechaElaboracion.muestra();
    cout << endl << "Autores: " << endl;
    for (int i=0;i<cantidadAutores;i++) {
        for (int j=0; j<cant; j++) {
            if (arr[j].getIdAutor()==listaAutores[i]) {
                cout <<i+1<<". "<< arr[j].getNombre() << endl;
            }
        }
    }
}

bool EjemploVideo::estaAutor(int id) {
    for (int i=0; i<cantidadAutores; i++) {
        if (id==listaAutores[i]) {
            return true;
        }
    }
    return false;
}

#endif // EJEMPLOVIDEO_H
