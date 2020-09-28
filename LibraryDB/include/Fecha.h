#ifndef FECHA_H
#define FECHA_H


class Fecha
{
    friend istream& operator>>(istream &is, Fecha &f);
    friend ostream& operator<<(ostream &os, Fecha f);

    public:
        Fecha();
        Fecha(int d, int m, int a);
        int getDia() {return dd;};
        int getMes() {return mm;};
        int getAno() {return aa;};
        void setFecha(int d, int m, int a);
        Fecha operator+(int cant);
        bool operator>(Fecha f);
        bool operator<(Fecha f);
        bool operator==(Fecha f);
        bool operator<=(Fecha f);
        bool operator>=(Fecha f);

    private:
        int dd;
        int mm;
        int aa;
        string nombreMes();
        bool esBisiesto();
};

Fecha::Fecha() {
    dd=1;
    mm=1;
    aa=1;
}
Fecha::Fecha(int d, int m, int a) {
    dd=d;
    mm=m;
    aa=a;
}
void Fecha::setFecha(int d, int m, int a) {
    dd=d;
    mm=m;
    aa=a;
}
string Fecha::nombreMes() {
    string meses[12]={"Ene","Feb","Mar","Abr","May","Jun","Jul","Ago","Sep","Oct","Nov","Dic"};
    return meses[mm-1];
}
bool Fecha::esBisiesto() {
    if (aa%4==0) {
        return true;
    }
    return false;
}
Fecha Fecha::operator+(int cant) {
    Fecha temp(dd+cant, mm, aa);
    if ((mm==1||mm==3||mm==5||mm==7||mm==8||mm==10||mm==12)&&temp.dd>31) {
        ++temp.mm;
        temp.dd-=31;
    } else if (mm!=2 && temp.dd>30) {
        ++temp.mm;
        temp.dd-=30;
    } else if (mm==2&&temp.dd>28) {
        if (esBisiesto()&&temp.dd>29) {
            temp.dd-=29;
        } else {
            temp.dd-=28;
        }
        ++temp.mm;
    }
    if (temp.mm>12) {
        temp.mm-=12;
        ++temp.aa;
    }
    return temp;
}
bool Fecha::operator==(Fecha f) {
    if (dd==f.dd&&mm==f.mm&&aa==f.aa) {
        return true;
    }
    return false;
}
bool Fecha::operator>(Fecha f) {
    if (*this==f) {
        return false;
    }
    if (aa>f.aa) {
        return true;
    } else if (aa<f.aa) {
        return false;
    } else {
        if (mm>f.mm) {
            return true;
        } else if (mm<f.mm) {
            return false;
        } else {
            if (dd>f.dd) {
                return true;
            } else {
                return false;
            }
        }
    }
}
bool Fecha::operator<(Fecha f) {
    if (*this>f||*this==f) {
        return false;
    }
    return true;
}
bool Fecha::operator<=(Fecha f) {
    if (*this>f) {
        return false;
    }
    return true;
}
bool Fecha::operator>=(Fecha f) {
    if (*this<f) {
        return false;
    }
    return true;
}

istream& operator>>(istream &is, Fecha &f) {
    is>>f.dd>>f.mm>>f.aa;
    return is;
}
ostream& operator<<(ostream &os, Fecha f) {
    os << f.dd << "  " << f.nombreMes() << " " << f.aa;
    return os;
}

#endif // FECHA_H
