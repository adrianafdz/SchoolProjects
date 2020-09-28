// Adriana Fernandez A0119148
// Fecha: 12 de febrero de 2019
// Descripcion: crea un archivo html donde muestra la descripcion (que este comentada) del programa y
//              la de cada funcion que este en el archivo de entrada

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// REVISA QUE EXISTA EL ARCHIVO CON EL NOMBRE INDICADO POR EL USUARIO
bool existe(const char *nombre) {
    ifstream infile(nombre);
    return infile.good();
}
// ELIMINA ESPACIOS Y TABS AL INICIO DE CADA LINEA DE LOS COMENTARIOS
void borraEspacios(string &texto) {
    while (texto[0]==' ' || texto[0]=='\t') {
        texto.erase(0,1);
    }
}
int main()
{
    ifstream archLeer;
    ofstream archSalida;
    string linea,comentario, clase,nomArch, nomHTML;
    bool existeArch;

    // PIDE NOMBRE DEL ARCHIVO HASTA QUE SE INGRESE UNO QUE SI EXISTA
    do {
        cout << "Nombre del archivo (sin extension): " ;
        cin >> nomArch;
        nomHTML=nomArch + "-documentacion.html";
        nomArch+=".cpp";
        existeArch=existe(nomArch.c_str());

        if (existeArch){
            archLeer.open(nomArch.c_str());
            archSalida.open(nomHTML.c_str());

            // HEADER HTML Y CSS
            archSalida<<"<!DOCTYPE html><html><head><meta charset='UTF-8'><title>Documentacion: " << nomArch <<"</title>" <<
            "<link href='https://fonts.googleapis.com/css?family=Inconsolata' rel='stylesheet'></head><body>" << endl <<
            "<style>* {color:#505050 ; font-family: 'Inconsolata', monospace;} body h1 {color:black;text-align:center;}" <<
            "body b {color:black;}body #cuadro {width: 45vw;background-color: #f5f5f5;padding:0px 50px 40px 50px;margin:40px 0px;" <<
            "border-radius:10px;position: relative;left: 50%;transform: translate(-50%);} body h3 {text-align:center; margin:0px;} body p{margin:0px;}</style>" << endl;
            archSalida<<"<div id=cuadro>"<< endl;

            while (getline(archLeer, linea)) {
                // DETECTA DONDE COMIENZA UN COMENTARIO DEL TIPO DESCRIPCION
                borraEspacios(linea);
                if (linea=="/**") {
                    //archSalida<<"<p>"<<endl;
                    do {
                        getline(archLeer, comentario);
                        borraEspacios(comentario);
                        // REVISA QUE TIPO DE DESCRIPCION ES Y LA COLOCA EN EL ARCHIVO HTML
                        if (comentario.substr(0,1)=="@") {
                            archSalida<<"<br>"<<endl;
                            clase = comentario.substr(1,comentario.find(' ')-1);
                            comentario.erase(0,comentario.find(' ')+1);
                            if(clase=="progName") {
                                archSalida<< "<p><h1>" << comentario << "</h1>";
                            }
                            if (clase=="desc") {
                                archSalida<< "<b>Descripcion: </b>" ;
                            }
                            if (clase=="author") {
                                archSalida<<"<b>Autor: </b>" ;
                            }
                            if (clase=="date"){
                                archSalida<<"<b>Fecha: </b>" ;
                            }
                            if (clase=="funcName") {
                                archSalida<<"<p><h3><b>Funcion: </b>" << comentario << "</h3>";
                            }
                            if (clase=="param") {
                                archSalida<<"<b>Parametros: </b>" ;
                            }
                            if (clase=="return") {
                                archSalida<<"<b>Return: </b>" ;
                            }
                            // AGREGA EL RESTO DE LA DESCRIPCION
                            if (clase!="progName" && clase!="funcName") {
                                archSalida<< comentario << endl;
                            }

                        }
                        // AGREGA LA DESCRIPCION SI SE CONTINUO EN COMENTARIO EN OTRA LINEA
                        else if (comentario!="*/") {
                            archSalida << comentario << endl;
                        }
                        // TERMINA UNA DE LAS DESCRIPCIONES
                        else {
                            archSalida<<"</p><br><hr>"<<endl;
                        }

                    } while (comentario!="*/");
                }
            }
            // CIERRA HTML
            archSalida<<"</div></body></html>" ;
            cout << "ARCHIVO LISTO" << endl;
            archLeer.close();
            archSalida.close();
        } else {
            cout << "NO EXISTE ARCHIVO" << endl << endl;
        }
    } while (!existeArch);
}
