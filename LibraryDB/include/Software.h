#ifndef SOFTWARE_H
#define SOFTWARE_H
#include "Material.h"

class Software: public Material
{
    public:
        Software();
        Software(int id, string t, string s);
        void setSisOp(string s) {sistemaOper=s;};
        string getSisOp() {return sistemaOper;};
        void muestra();
        int cantDiasPrestamo() {return 1;};

    private:
        string sistemaOper;
};
Software::Software():Material(){
    sistemaOper="-";
}
Software::Software(int id, string t, string s):Material(id,t){
    sistemaOper=s;
}
void Software::muestra(){
    cout << "Software: " << idMaterial << " " << titulo << " " << sistemaOper <<  endl;
}


#endif // SOFTWARE_H
