//---¡importar-librerias!
#include <iostream>
#include <cstdlib>
#include <ctime>
//#include <random>

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
        Carta(int tipoCarta);
        
        //---¡metodo-seleccionar-carta!
        void SeleccionarCarta();

};

//---¡construccion-del-metodo-constructor-de-la-clase-Carta!
Carta::Carta(int tipoCarta){
    this -> tipoCarta = tipoCarta;
};

//---¡construccion-del-metodo-seleccionar-carta-de-la-clase-carta!
void Carta::SeleccionarCarta(){
    //---¡se-escoge-1-para-cartas-de-nivel!
    if(tipoCarta == 1){
        //---¡se-supone-que-estogenera-un-numero-aleatorio-entre-1-y100!
        idCarta = rand() % 100 + 1; 
    };
    cout << idCarta << endl;
};

//---¡funcion-principal!
int main(){
    //---¡para-que.inizialice-simpre-la-semilla-y-no-arroje-el-mismo-numero!
    srand(time(0));

    //---¡se-llaman-los-metodos!
    Carta CartaUno(1);
    CartaUno.SeleccionarCarta();
    return 0;
};