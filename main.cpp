#include "Carta.h"
#include "Jugador.h"
#include "Juego.h"

//---¡para-usar-cout-y-ednl!
using namespace std;

//---¡funcion-principal!
int main(){
    //---¡para-que.inizialice-simpre-la-semilla-y-no-arroje-el-mismo-numero!
    srand(time(0));

    //---¡se-llama-a-la-clase-juego-y-se-inicia-el-juego-con-el-metodo-Iniciar!
    Juego juego;
    juego.Cargar();
    juego.Iniciar();

    return 0;
};