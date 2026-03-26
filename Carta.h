#ifndef CARTA_H
#define CARTA_H

//---¡importar-librerias!
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
//#include <random>
#include <cstring>

//---¡para-usar-cout-y-ednl!
using namespace std;

//---¡clase-carta!
class Carta{
    //---¡atributos-privados!
    private:
        int idCarta;
        int tipoCarta;

    //---¡atributos-publicos!
    public:
        //---¡metodo-constructor!
        Carta();
        Carta(int tipoCarta);
        
        //---¡metodo-seleccionar-carta!
        void SeleccionarCarta();
        
        //---¡metodo-obtener-id-de-la-carta!
        int ObtenerIdCarta();
};

#endif