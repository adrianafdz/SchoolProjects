//
//  main.cpp
//  funcionesLineas
//
//  Created by Yolanda Martínez on 10/16/13.
//  Copyright (c) 2013 Yolanda Martínez. All rights reserved.
//

#include <iostream>
using namespace std;


/**
  @progName Figuras con Asteriscos
  @desc Este programa hace varias funciones y cada una hace figuras
  @desc De hecho estoy viendo que no se llama la funcion rombo en el main
  @author Yolanda Martinez
  @date Enero de 2015
  */

/**
 @funcName linea
 @desc muestra en la pantalla una linea con cE espacios y cA asteriscos
 
 @param cE es la cantidad de espacios
 @param CA es la cantidad de asteriscos
 */

void linea(int cE, int cA)
{
    for (int i = 0; i < cE; i++)
        cout << " ";
    for (int i = 0; i < cA; i++)
        cout << "*";
    cout << endl;
}

/**
 @funcName rombo
 @desc muestra en la pantalla un rombo de asteriscos
 
 OJO SI SALE ESTA LINEA EL PROGRAMA ESTA SUPER BIEN!!!
 
 */
void rombo()
{
    int esp, ast, n;
    
    cout << " Teclea n ";
    cin >> n;
    esp = n-1;
    ast = 1;
    for (int c = 1; c <= n; c++)
    {
        linea(esp, ast);
        esp--;
        ast += 2;
    }
    
    ast -= 4;
    esp = 1;
    for (int c = 1; c <= n; c++)
    {
        linea(esp, ast);
        esp++;
        ast -= 2;
    }
}

/**
  @funcName escalera
  @desc muestra en la pantalla una escalera con asteriscos,
 
  @param tamaño del escalon
  @param cantidad de escalones
 
  @return No tiene valor de retorno
 */
void escalera()
{
    int n, cantEsc, espIzq;
    
    cout << "tamaño del escalon ";
    cin >> n;
    cout << "Cantidad de escalones ";
    cin >> cantEsc;
    
    // y que pasa si aqui pongo @param o @return
    
    // tambien puedo poner @date o @progName
    
    espIzq = 0;
    for (int c = 1; c <= cantEsc; c++)
    {
        // dibujar un escalon
        for (int i = 1; i <= n; i++)
            linea(espIzq, n);
        
        espIzq += n;
    }
    
}

/**
 @funcName main
 
 @desc Main del programa que manda llamar a la funcion escalera
 
 @author Yolanda Martinez
 @date Agosto del 2013 (creo)
 
 */
int main()
{
    escalera();
    
    return 0;
}
