// Adriana Fernández

#include <iostream>
using namespace std;

bool checa(int arr[9][9]) {
    bool estaFila, estaCol, estaCuadro;
    // RES = NUMERO QUE ESTA REVISANDO QUE ESTE
    for (int res=1; res<=9; res++) {
        for (int i=0; i<9; i++) {
            estaFila=false;
            estaCol=false;
            for (int j=0; j<9; j++) {
                // CHECA FILA
                if (arr[i][j]==res) {
                    // SI YA ESTABA (SE REPITE) ESTA MAL
                    if (estaFila) {
                        //cout << "NUM " << res << " repetido" << endl;
                        return false;
                    }
                    estaFila=true;
                }
                // CHECA COLUMNA
                if (arr[j][i]==res) {
                    // SE REPITE
                    if (estaCol) {
                        //cout << "NUM " << res << " repetido" << endl;
                        return false;
                    }
                    estaCol=true;
                }
            }
            // SI NO LO ENCUENTRA EN UNA FILA O COLUMNA, ESTA MAL
            if (!estaCol || !estaFila) {
                //cout<<"No esta num " << res << endl;
                return false;
            }
        }
        // CHECAR POR CUADROS 3X3
        // DIVIDIR TODO EL CUADRO EN 3X3
        for (int cFila=0; cFila<9; cFila=cFila+3) {
            for (int cCol=0; cCol<9; cCol=cCol+3) {
                estaCuadro=false;
                // CHECAR EN CADA CUADRITO SI ESTA EL NUMERO
                for (int i=0;i<3; i++) {
                    for (int j=0; j<3; j++) {
                        if (res==arr[cFila+i][cCol+j]) {
                            // SI SE REPITE, ESTA MAL
                            if (estaCuadro) {
                                //cout << "NUM " << res << " repetido" << endl;
                                return false;
                            }
                            estaCuadro=true;
                        }
                    }
                }
                // SI NO LO ENCONTRO, ESTA MAL
                if (!estaCuadro) {
                    //cout<<"No esta num " << res << endl;
                    return false;
                }
            }
        }
    }
    return true;
}
int main()
{
    int sudoku[9][9];
    for (int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            cin>>sudoku[i][j];
        }
    }
    if (checa(sudoku)) {
        cout<<"YES"<<endl;
    } else {
        cout<<"NO"<<endl;
    }
}
