// Adriana Fernandez

#include <iostream>
#include <fstream>
#include <typeinfo>
using namespace std;
#include "Libro.h"
#include "Disco.h"
#include "Software.h"
#include "Reserva.h"

void muestraReserva(Material *arrM[20], int posM, Reserva arrR[50], int posR, bool c) {
    cout<<"Inicio: "<<arrR[posR].getFechaRes()<<endl<<"Termina: "<<arrR[posR].calcFechaFinReservacion(arrM[posM]->cantDiasPrestamo())
        <<endl<<arrM[posM]->getTitulo()<<" ";
    if (c) {
        cout << "ID Cliente: " << arrR[posR].getIdCli();
    }
    cout<<endl<<endl;
}
bool buscaMat(int id, Material *arr[20], int cant, int &pos) {
    for (int i=0;i<cant; i++) {
        if (id==arr[i]->getIdMat()) {
            pos=i;
            return true;
        }
    }
    return false;
}
bool buscaRes(int id, Reserva arr[50], int cant, int &pos) {
    for (int i=0;i<cant; i++) {
        if (id==arr[i].getIdMat()) {
            pos=i;
            return true;
        }
    }
    return false;
}
template <class T>
void muestraTipo(Material *arrM[20], int posM, Reserva arrR[50], int contM, int contR, T mat) {
    for (int i=0; i<contM; i++) {
        if (typeid(*arrM[i])==typeid(T)) {
            if (buscaRes(arrM[i]->getIdMat(), arrR, contR, posM)) {
                muestraReserva(arrM,i,arrR,posM, false);
            }
        }
    }
}
int main()
{
    // LEER ARCHIVO DE MATERIALES
    ifstream ArchMaterial;
    Material *listaMat[20];
    int idM, numP, dur, contM=0;
    string tit, aut, sis;
    char tipo;
    ArchMaterial.open("Material.txt");
    while (ArchMaterial>>idM>>tit>>tipo) {
        if (tipo=='L') {
            ArchMaterial>>numP>>aut;
            listaMat[contM++]= new Libro(idM,tit,numP,aut);
        }
        if (tipo=='D') {
            ArchMaterial>>dur;
            listaMat[contM++]= new Disco(idM, tit,dur);
        }
        if (tipo=='S') {
            ArchMaterial>>sis;
            listaMat[contM++]= new Software(idM, tit, sis);
        }
    }
    ArchMaterial.close();

    // LEER ARCHIVO DE RESERVACIONES
    ifstream ArchReserva;
    Reserva listaRes[50];
    Fecha f;
    int idCli, contR=0;
    ArchReserva.open("Reserva.txt");
    while (ArchReserva>>f>>idM>>idCli) {
        listaRes[contR].setFechaRes(f);
        listaRes[contR].setIdCli(idCli);
        listaRes[contR++].setIdMat(idM);
    }
    ArchReserva.close();

    // MENU
    char opcion;
    bool esta, guarda;
    int posM, posR;
    do {
        cout << endl;
        cout << "a) Consultar lista de Materiales" << endl;
        cout << "b) Consultar la lista de reservaciones" << endl;
        cout << "c) Consultar las reservaciones de un material dado" << endl;
        cout << "d) Consular las reservaciones de una fecha dada" << endl;
        cout << "e) Hacer una reservacion" << endl;
        cout << "f) Terminar" << endl;
        cin >> opcion;
        cout << endl;
        switch (tolower(opcion)) {
        case 'a':
            cout << "MATERIALES:" << endl;
            for (int i=0;i<contM; i++) {
                listaMat[i]->muestra();
            }
            break;
        case 'b':
            cout << "RESERVACIONES" << endl;
            for (int i=0;i<contR; i++) {
                if (buscaMat(listaRes[i].getIdMat(),listaMat,contM,posM)) {
                    muestraReserva(listaMat,posM,listaRes,i, true);
                }
            }
            break;
        case 'c':
            do {
                cout<<"ID Material: ";
                cin>>idM;
                esta=buscaMat(idM, listaMat, contM, posM);
                if (!esta) {
                    cout<<"No hay material con este ID, ingrese de nuevo" << endl;
                } else {
                    if (buscaRes(idM, listaRes, contR, posR)) {
                        for (int i=0;i<contR; i++) {
                            if (listaRes[i].getIdMat()==idM) {
                                muestraReserva(listaMat,posM,listaRes,i, false);
                            }
                        }
                    } else {
                        cout << "No hay reservaciones para este material" << endl;
                    }
                }
            } while (!esta);
            break;
        case 'd':
            esta=false;
            cout << "Ingresa fecha (dd mm aa): ";
            cin >> f;
            for (int i=0;i<contR; i++) {
                buscaMat(listaRes[i].getIdMat(),listaMat,contM,posM);
                if (listaRes[i].getFechaRes()<=f&&listaRes[i].calcFechaFinReservacion(listaMat[posM]->cantDiasPrestamo())>=f) {
                    muestraReserva(listaMat,posM,listaRes,i, true);
                    esta=true;
                }
            }
            if (!esta) {
                cout << "No hay reservaciones en esta fecha" << endl;
            }
            break;
        case 'e':
            Reserva temp;
            cout << "ID Cliente: ";
            cin>>idCli;
            do {
                guarda=true;
                cout<<"ID Material: ";
                cin>>idM;
                esta=buscaMat(idM, listaMat, contM, posM);
                if (!esta) {
                    cout<<"No hay material con este ID, ingrese de nuevo" << endl;
                } else {
                    cout << "Fecha: ";
                    cin>>f;
                    temp.setFechaRes(f);
                    temp.setIdCli(idCli);
                    temp.setIdMat(idM);
                    for (int i=0;i<contR; i++) {
                        if (idM==listaRes[i].getIdMat()) {
                            if ((listaRes[i].getFechaRes()<=f&&listaRes[i].calcFechaFinReservacion(listaMat[posM]->cantDiasPrestamo())>=f)||
                                (listaRes[i].getFechaRes()<=temp.calcFechaFinReservacion(listaMat[posM]->cantDiasPrestamo())&&listaRes[i].calcFechaFinReservacion(listaMat[posM]->cantDiasPrestamo())>=temp.calcFechaFinReservacion(listaMat[posM]->cantDiasPrestamo()))){
                                cout << "Ya esta reservado esa fecha" << endl;
                                guarda=false;
                            }
                            break;
                        }
                    }
                    if (guarda) {
                        listaRes[contR++]=temp;
                    }
                }
            } while (!esta);
            break;
        }
    } while (tolower(opcion)!='f');

    // GUARDAR CAMBIOS
    ofstream ArchReservaNuevo;
    ArchReservaNuevo.open("Reserva.txt");
    for (int i=0; i<contR; i++) {
        ArchReservaNuevo<<listaRes[i].getFechaRes().getDia()<<" "<<listaRes[i].getFechaRes().getMes()<<" "<<listaRes[i].getFechaRes().getAno()<<" "
            <<listaRes[i].getIdMat()<<" "<<listaRes[i].getIdCli()<<endl;
    }
    ArchReservaNuevo.close();
    return 0;
}
