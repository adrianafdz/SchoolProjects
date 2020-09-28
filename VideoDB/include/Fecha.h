#ifndef FECHA_H
#define FECHA_H


class Fecha
{
    public:
        Fecha() {dd=1;mm=1;aa=2000;}
        int getD() {return dd;}
        int getM() {return mm;}
        int getA() {return aa;}
        void setFecha(int d, int m, int a);
        void muestra();

    private:
        int dd;
        int mm;
        int aa;
};

void Fecha::setFecha(int d, int m, int a) {
    dd=d;
    mm=m;
    aa=a;
}

void Fecha::muestra() {
    cout << dd << "/" << mm << "/" << aa << " " ;
}
#endif // FECHA_H
