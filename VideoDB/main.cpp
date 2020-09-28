// ADRIANA FERNANDEZ LOPEZ, A01197148
// 3 DE MARZO DE 2019

#include <iostream>
#include <fstream>

using namespace std;

#include "Autor.h"
#include "Tema.h"
#include "Materia.h"
#include "EjemploVideo.h"

void hayVid(bool hay) {
    if (!hay) {
        cout << "NO HAY VIDEOS REGISTRADOS" << endl;
    }
}
bool existe(const char *nombre) {
    ifstream infile(nombre);
    return infile.good();
}
void pedirNombre(string &nom) {
    do {
        cin >> nom;
        cout << endl;
        nom+=".txt";
        if (!existe(nom.c_str())) {
            cout << "No exite un archivo con ese nombre." << endl << "Ingresalo de nuevo: ";
        }
    } while (!existe(nom.c_str()));
}
bool buscarMat(int id, Materia arr[5], int cant) {
    for (int i=0; i<cant; i++) {
        if (id==arr[i].getIdMateria()) {
            return true;
        }
    }
    return false;
}
bool buscarTema(int id, Tema arr[10], int cant) {
    for (int i=0; i<cant; i++) {
        if (id==arr[i].getIdTema()) {
            return true;
        }
    }
    return false;
}
bool buscarAutor(int id, Autor arr[10], int cant) {
    for (int i=0; i<cant; i++) {
        if (id==arr[i].getIdAutor()) {
            return true;
        }
    }
    return false;
}
bool buscarVid(int id, EjemploVideo arr[20], int cant) {
    for (int i=0; i<cant; i++) {
        if (id==arr[i].getIdVideo()) {
            return true;
        }
    }
    return false;
}

int main()
{
    ifstream archMaterias, archTemas, archAutores, archVideo;
    Materia mats[5];
    Tema temas[10];
    Autor autores[10];
    EjemploVideo vid[20];
    string nomArch;
    // LEER MATERIAS
    int idMat, cantM=0;
    string nomMateria;
    cout << "Nombre archivo con lista de materias: " ;
    pedirNombre(nomArch);
    archMaterias.open(nomArch.c_str());
    while (archMaterias>>idMat) {
        getline(archMaterias,nomMateria);
        if (!buscarMat(idMat,mats,cantM)) {
            mats[cantM].setIdMateria(idMat);
            mats[cantM].setNombre(nomMateria);
            cantM++;
        } else {
            cout << "Materia con ID " << idMat << " repetida." << endl;
        }
    }
    archMaterias.close();

    // LEER TEMAS
    int idTem, cantT=0;
    string nomTema;
    cout << "Nombre archivo con lista de temas: " ;
    pedirNombre(nomArch);
    archTemas.open(nomArch.c_str());
    while (archTemas>>idTem>>idMat) {
        getline(archTemas, nomTema);
        if(!buscarTema(idTem, temas, cantT)) {
            if (buscarMat(idMat, mats, cantM)) {
                temas[cantT].setIdMateria(idMat);
                temas[cantT].setIdTema(idTem);
                temas[cantT++].setNombre(nomTema);
            } else {
                cout << "Materia con clave " << idMat << " no existe." << endl << "Tema " << nomTema << " no queda registrado." << endl;
            }
        } else {
            cout << "Tema con ID " << idTem << " repetido." << endl;
        }
    }
    archTemas.close();

    // LEER AUTORES
    int idAut, cantA=0;
    string nomAut;
    cout << "Nombre archivo con lista de autores: " ;
    pedirNombre(nomArch);
    archAutores.open(nomArch.c_str());
    while (archAutores>>idAut) {
        getline(archAutores, nomAut);
        if (!buscarAutor(idAut,autores,cantA)) {
            autores[cantA].setIdAutor(idAut);
            autores[cantA++].setNombre(nomAut);
        } else {
            cout << "Autor con ID " << idAut << " repetido." << endl;
        }
    }
    archAutores.close();

    // LEER EJEMPLOVIDEO
    Fecha f;
    int idVid, d, m, a, cantAutores, cantV=0, temporal[10];
    string nomVid;
    cout << "Nombre archivo con lista de videos: " ;
    pedirNombre(nomArch);
    archVideo.open(nomArch.c_str());
    bool graba;
    while (archVideo>>idVid>>nomVid>>idTem) {
        graba=false;
        if (!buscarVid(idVid, vid, cantV)) {
            if (buscarTema(idTem, temas, cantT)) {
                archVideo>>d>>m>>a>>cantAutores;
                if (cantAutores>10) {
                    cout << "No se pueden tener mas de 10 autores" << endl;
                } else {
                    for (int i=0; i<cantAutores; i++) {
                        archVideo>>idAut;
                        if (buscarAutor(idAut, autores, cantA)) {
                            graba=true;
                            temporal[i]=idAut;
                        } else {
                            cout << "No existe autor con ID " << idAut << endl;
                            graba=false;
                            break;
                        }
                    }
                }
            } else {
                cout << "No existe tema con ID " << idTem << endl;
            }
        } else {
            cout << "Video con ID " << idVid << " repetido." << endl;
        }
        if (graba) {
            f.setFecha(d,m,a);
            vid[cantV].setFecha(f);
            vid[cantV].setIdTema(idTem);
            vid[cantV].setIdVideo(idVid);
            for (int i=0; i<cantAutores; i++) {
                vid[cantV].agregaAutor(temporal[i]);
            }
            vid[cantV++].setNombre(nomVid);
        } else {
            archVideo.ignore(256,'\n');
            cout << "Video con ID " << idVid << " no queda registrado." << endl << endl;
        }
    }

    cout << "CANTIDAD DE VIDEOS REGISTRADOS CORRECTAMENTE: " << cantV << endl << endl;
    archVideo.close();

    // MENU
    char opcion;
    bool esta;
    bool hay;
    do {
    cout << endl << "MENU" << endl;
    cout << "a) Consulta info de materias, temas y autores" << endl;
    cout << "b) Dar de alta Videos de Ejemplo" << endl;
    cout << "c) Consultar lista de videos por tema" << endl;
    cout << "d) Consultar lista de videos por materia" << endl;
    cout << "e) Consultar lista de videos" << endl;
    cout << "f) Consultar videos por autor" << endl;
    cout << "g) terminar" << endl;
    cin >> opcion;
    opcion=tolower(opcion);
    hay=false;
    switch (opcion) {
    case 'a': // INFO
        cout << endl << "MATERIAS:" << endl;
        for (int i=0; i<cantM; i++) {
            mats[i].muestra();
        }
        cout << endl << "TEMAS: " << endl;
        for (int i=0; i<cantT; i++) {
            temas[i].muestra();
        }
        cout << endl << "AUTORES: " << endl;
        for (int i=0; i<cantA; i++) {
            autores[i].muestra();
        }
        break;
    case 'b': // DAR DE ALTA
        if (cantV!=20) {
            do {
                cout << "ID Video: ";
                cin>>idVid;
                esta=buscarVid(idVid,vid,cantV);
                if (esta) {
                    cout<<"ID ya exite"<<endl;
                }
            } while (esta);
            vid[cantV].setIdVideo(idVid);
            cout << "Nombre video: ";
            cin >> nomVid;
            vid[cantV].setNombre(nomVid);
            do {
                cout << "ID Tema: ";
                cin >> idTem;
                esta=buscarTema(idTem,temas,cantT);
                if (!esta) {
                    cout << "No existe tema con ID " << idTem << endl;
                }
            } while (!esta);
            vid[cantV].setIdTema(idTem);
            cout << "Fecha (dia mes ano): " ;
            cin >> d >> m >> a;
            f.setFecha(d,m,a);
            vid[cantV].setFecha(f);
            do {
                cout << "Cantidad de autores: " ;
                cin >> cantAutores;
                if (cantAutores<=10) {
                    for (int i=0; i<cantAutores; i++) {
                        do {
                            graba=false;
                            cout << "ID de autor " << i+1 << ": ";
                            cin >> idAut;
                            if (!buscarAutor(idAut, autores, cantA)) {
                                cout << "Autor con ID " << idAut << " no existe. Repite." << endl;
                            } else {
                                if (vid[cantV].agregaAutor(idAut)==true) {
                                    graba=true;
                                }
                            }
                        } while (!graba);
                    }
                } else {
                    cout << "No se pueden tener mas de 10 autores por video" << endl;
                }
            } while (cantAutores>10);
            cantV++;
        } else {
            cout << "Maximo 20 videos registrados" << endl;
        }
        break;
        case 'c': // POR TEMA
        do {
            cout << "ID Tema: ";
            cin >> idTem;
            esta=buscarTema(idTem, temas, cantT);
            if (esta) {
                for (int i=0; i<cantV; i++) {
                    if (idTem==vid[i].getIdTema()) {
                        hay=true;
                        cout << endl << "VIDEO " << i+1 << ":" << endl;
                        vid[i].muestra(autores, cantA, temas, cantT, mats, cantM);
                    }
                }
            } else {
                cout << "ID " << idTem << " no existe." << endl << endl;
            }
        } while (!esta);
        hayVid(hay);
        break;
    case 'd': // POR MATERIA
        do {
            cout << "ID Materia: ";
            cin >> idMat;
            esta=buscarMat(idMat, mats, cantM);
            if (esta) {
                for (int i=0; i<cantT; i++) {
                    if (idMat==temas[i].getIdMateria()) {
                        for (int j=0; j<cantV; j++) {
                            if (temas[i].getIdTema()==vid[j].getIdTema()) {
                                hay=true;
                                cout << endl << "VIDEO " << j+1 << ":" << endl;
                                vid[j].muestra(autores,cantA, temas, cantT, mats, cantM);
                            }
                        }
                    }
                }
            } else {
                cout << "ID " << idMat << " no existe." << endl << endl;
            }
        } while (!esta);
        hayVid(hay);
        break;
    case 'e': // TODOS LOS VIDEOS
        for (int i=0;i<cantV;i++) {
            cout << endl << "VIDEO " << i+1 << ":" << endl;
            vid[i].muestra(autores, cantA, temas, cantT, mats, cantM);
        }
        break;
    case 'f': // POR AUTOR
        do {
            cout << "ID Autor: ";
            cin >> idAut;
            esta=buscarAutor(idAut, autores, cantA);
            if (esta) {
                for (int i=0; i<cantV; i++) {
                    if (vid[i].estaAutor(idAut)) {
                        hay=true;
                        cout << endl << "VIDEO " << i+1 << ":" << endl;
                        vid[i].muestra(autores,cantA, temas, cantT, mats, cantM);
                    }
                }
            } else {
                cout << "ID " << idAut << " no existe." << endl << endl;
            }
        } while (!esta);
        hayVid(hay);
        break;
    }

    } while (opcion!='g');
    return 0;
}
