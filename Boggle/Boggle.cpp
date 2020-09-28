// Adriana Fernandez

#include <iostream>
#include <set>

using namespace std;

/*void print(set<coord> &word) {
    set<coord>::iterator it;
    for (it=word.begin(); it!=word.end(); it++) {
        cout<<it->y<<" "<<it->x<<endl;
    }
}*/

bool notInSet(int x, int y,set<char*> &word, char tablero[4][4]) {
    set<char*>::iterator it;
    it = word.find(&tablero[x][y]);
    for (it=word.begin(); it!=word.end(); it++) {
        if (*it == &tablero[x][y]) {
            //cout<<y<<" "<<x<<" in set";
            return false;
        }
    }
    return true;
}

bool busca(int f, int c, set<char*> &word, string palabra, char tablero[4][4], int posLetra) {
    if (posLetra<palabra.length()) {
        bool found=false;
        for (int i=f-1; i<=f+1 && !found; i++) {
            for (int j=c-1; j<=c+1 && !found; j++) {
                if (i>=0 && i<=3 && j>=0 && j<=3) {
                    //cout<<"revisando "<<tablero[i][j]<< " en " << i << " " << j <<endl;
                    if (palabra[posLetra]==tablero[i][j] && notInSet(i,j, word, tablero)) {
                        //cout<<"----meto nueva----"<<endl;
                        word.emplace(&tablero[i][j]);
                        //print(word);
                        //cout<<"--------"<<endl;
                        found = busca(i, j, word, palabra, tablero, posLetra+1);
                        if (!found) {
                            //cout<<"no encontro " << palabra[posLetra+1]<<endl;
                            word.erase(&tablero[i][j]);
                        }
                        //cout<<"--------"<<endl;
                    }
                }
            }
        }
        return found;
    }
    return true;
}

int buscaPrimera(char tablero[4][4], string palabra) {
    set<char*> word;
    int posLetra=0;
    bool found=false;

    for (int i=0; i<4; i++) {
        for (int j=0; j<4 && !found; j++) {
            if (palabra[posLetra]==tablero[i][j]) {
                //cout<<tablero[i][j]<< "found"<<endl;
                word.insert(&tablero[i][j]);
                found = busca(i, j, word, palabra, tablero, posLetra+1);
            }
        }
    }

    // PUNTAJE
    if (found) {
        switch (palabra.length()) {
        case 3:case 4:
            return 1;
        case 5:
            return 2;
        case 6:
            return 3;
        case 7:
            return 5;
        }
        if (palabra.length()>=8) {
            return 11;
        }
    }
    return 0;
}

int main()
{
    int n, m;
    string palabra, linea;
    char tablero[4][4];

    cin>>n;
    int puntos[n];

    for (int i=0; i<n; i++) {
        //cout<<"GAME "<<i+1<<endl;
        // LEE TABLERO
        for (int i=0; i<4; i++) {
            cin>>linea;
            for (int j=0; j<4; j++) {
                tablero[i][j]=linea[j];
            }
        }
        //cout<<"numero de palabras? ";
        cin>>m;
        puntos[i]=0;
        for (int j=0; j<m; j++){
            cin>>palabra;
            puntos[i] += buscaPrimera(tablero, palabra);
        }
    }

    for (int i=0; i<n; i++) {
        cout<<"Game "<<i+1<<": "<<puntos[i]<<endl;
    }

}
