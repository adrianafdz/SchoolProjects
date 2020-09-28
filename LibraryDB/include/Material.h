#ifndef MATERIAL_H
#define MATERIAL_H

class Material
{
    public:
        Material();
        Material(int id, string t);
        virtual void muestra()=0;
        virtual int cantDiasPrestamo()=0;
        void setIdMat(int id) {idMaterial=id;};
        void setTitulo(string t){titulo=t;};
        int getIdMat(){return idMaterial;};
        string getTitulo(){return titulo;};

    protected:
        int idMaterial;
        string titulo;
};

Material::Material() {
    idMaterial=0;
    titulo="-";
}
Material::Material(int id, string t){
    idMaterial=id;
    titulo=t;
}

#endif // MATERIAL_H
