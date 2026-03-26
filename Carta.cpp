#include "Carta.h"

//---¡construccion-del-metodo-constructor-de-la-clase-Carta!
Carta::Carta(){
    this -> tipoCarta = 1;
    this -> idCarta = 0;
};

//---¡constructor-con-parámetro-de-la-clase-Carta!
Carta::Carta(int tipoCarta){
    this->tipoCarta = tipoCarta;
    this->idCarta = 0;
}


//---¡construccion-del-metodo-seleccionar-carta-de-la-clase-carta!
void Carta::SeleccionarCarta(){
    //---¡se-escoge-1-para-cartas-de-nivel!
    if(tipoCarta == 1){
        //---¡se-supone-que-estogenera-un-numero-aleatorio-entre-1-y100!
        idCarta = rand() % 100 + 1; 
    };
    //---¡voy -a-imprimir-el-id-de-la-carta-para-ver-si-funciona!
    cout << idCarta << endl;
};

//---¡construccion-del-metodo-ObtenerIdCarta-de-la-clase-Carta!
int Carta::ObtenerIdCarta(){
    return idCarta;
};

