#ifndef JUGADOR_H
#define JUGADOR_H

#include "Carta.h"
#include <string>

//---¡clase-jugador!
class Jugador{
    ///---¡atribitos-privados!
    private:
        int idJugador;
        string nombreJugador;
        int vidaJugador;
        int idCarta_;
        
    //---¡atributos-publicos!
    public:
        //---¡metodo-constructor!
        Jugador(int idJugador, string nombreJugador, int vidaJugador);
        
        //---¡metodo-JugarCarta!
        void JugarCarta(Carta &carta);

        //---¡metodo-PerderVida!
        void PerderVida(int cantidad); 
};



#endif