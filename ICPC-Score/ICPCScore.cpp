#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct registro {
    string nombre;
    int bien[10];
    int mal[10];
    int tiempo;
    int correct;
};

bool compare(const registro& r1, registro& r2) {
//    if (r1.nombre==""&&r2.nombre!="") {
//        return false;
//    }
//    if (r1.nombre!=""&&r2.nombre=="") {
//        return true;
//    }
    if (r1.correct==r2.correct) {
        return (r1.tiempo<r2.tiempo);
    }
    return (r1.correct>r2.correct);
}
int main()
{
    int t, p, s, time;
    string nom;
    char prob, check;
    vector <registro> datos;
    cout<<"Numero de equipos y de problemas: ";
    cin>>t>>p;
    if (t >= 1 && t <= 20 && p >= 1 && p <=10) {
        cout<<"Nombres:"<<endl;
        for (int i = 0; i < t ; i++) {
            cin >> nom;
            datos.push_back({nom, {0}, {0}, 0, 0});
            //datos[i].nombre=nom;
        }
    }
    cout<<"Numero de entradas: ";
    cin>>s;
    if (s >= 1 && s <= 1000) {
        //cout<<"Nombre Problema Tiempo Check"<<endl;
        for (int i=0; i<s; i++) {
            cin>>nom>>prob>>time>>check;
            for (int j=0; j<t; j++) {
                if (nom==datos[j].nombre) {
                    if (check=='W') {
                        datos[j].mal[prob-65]+=20;
                    } else if (check=='A') {
                        datos[j].bien[prob-65]+=time;
                        datos[j].correct+=1;
                    }
                }
            }
        }
    }
    // Suma tiempos
    for (int i=0; i<t; i++) {
        for (int j=0; j<p; j++) {
            if (datos[i].bien[j]!=0) {
                datos[i].tiempo+=datos[i].bien[j]+datos[i].mal[j];
            }
        }
    }

    sort(datos.begin(), datos.end(), &compare);

    for (int i=0; i<t; i++) {
        cout<<i+1<<" - "<<datos[i].nombre<<" "<<datos[i].correct<<" ";
        if (datos[i].tiempo==0) {
            cout<<"-"<<endl;
        } else {
            cout<<datos[i].tiempo<<endl;
        }
    }
}
