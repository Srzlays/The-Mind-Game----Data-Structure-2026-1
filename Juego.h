#ifndef JUEGO_H
#define JUEGO_H

#include "Carta.h"
#include "Jugador.h"

//---¡clase-Juego!
class Juego{
    //---¡atributos-privados!
    private:
        int nivel;

    //---¡atributos-publicos!
    public:
        //---¡metodo-cosntructor!
        Juego();

        //---¡metodo-Iniciar-la-partida!
        void Iniciar();

        //---¡metodo-JugarRonda!
        bool JugarRonda();

        //---¡metodo-guardar-partida!
        void Guardar();

        //---¡metodo-cargar-partida!
        void Cargar();
};

#endif