#include "Jugador.h"

//---¡construccion-del-metodo-constructor-de-la-clase-Jugador!
Jugador::Jugador(int idJugador, string nombreJugador, int vidaJugador ){
    this -> idJugador = idJugador;
    this -> nombreJugador = nombreJugador;
    this -> vidaJugador = vidaJugador;
    this -> idCarta_ = 0;
    //this -> entrada = '1';
};

//---¡construccion-del-metodo-JugarCarta-de-la-claseJugador!
void Jugador::JugarCarta(Carta &carta){
    idCarta_ = carta.ObtenerIdCarta();
    cout << nombreJugador << " juega la carta: " << idCarta_ << endl;
};

//---¡construccion-del-metodo-perder-vida-de-la-clase-Jugador!
void Jugador::PerderVida(int cantidad){
    vidaJugador -= cantidad;
    if(vidaJugador < 0) vidaJugador = 0;  //---¡para-evitar-valores-negativos!
    cout << nombreJugador << " pierde " << cantidad << " de vida. Vida actual: " << vidaJugador << endl;
};