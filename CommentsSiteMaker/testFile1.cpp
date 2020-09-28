/*
@progName Suma Matrices
@desc Programa que en una casilla i,j de la matriz C coloca la suma de los productos de cada valor del renglon i de la matriz A
por cada valor de la columna j de la matriz B.
@author Adriana Fernandez


   @date 18 de enero de 2019
*/
#include <iostream>
using namespace std;

/*
		@funcName cargaMatriz
 @desc Pide al usuario los valores de cada espacio en la matriz
@param size: tamano de la matriz (cuadrada), mat: matriz en la que se guardan los valores
	@return por referencia, matriz con los datos cargados
*/
void cargaMatriz(int size, int mat[20][20]) {
    for (int i=0; i<size; i++) {
        for (int j=0; j<size; j++) {
            cin >> mat[i][j];
        }
    }
}

/*
  @funcName multiplica
@desc multiplica los valores de una matriz por los de la otra y los coloca en la nueva matriz
	@param size: el tamano de las matrices, matA y matB: las matrices que se multiplican, matC: la matriz en la que se colocan los resultados


@return por referencia, nueva matriz con los resultados de las operaciones
*/
void multiplica(int size, int matA[20][20], int matB[20][20], int matC[20][20]) {
    int suma;
    for (int i=0; i<size; i++) {
        for (int j=0; j<size; j++) {
        suma=0;
            for (int x=0; x<size; x++) {
                suma+= matA[i][x] * matB[x][j];
            }
        matC[i][j]=suma;
        }
    }
}

int main () {
    int size, matA[20][20], matB[20][20], matC[20][20];
    cin >> size;
    cargaMatriz(size, matA);
    cargaMatriz(size, matB);
    multiplica(size, matA, matB, matC);
    // mostrar matriz con los resultados
    for (int i=0; i<size; i++) {
        for (int j=0; j<size; j++) {
            cout << matC[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
