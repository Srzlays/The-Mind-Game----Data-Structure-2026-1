#include "Juego.h"

//---¡construccion-del-metodo-constructor-de-la-clase-Juego!
Juego::Juego(){
    nivel = 1;
};

//---¡construccion-del-metodo-Iniciar-de-la-clase-Juego!
void Juego::Iniciar(){
    while(true){
        cout << "\n--- Nivel " << nivel << " ---\n";
        
        //---¡se-prueba-con-un-booleano-para-si-gana-o-pierde!
        bool gano = JugarRonda();

        if(gano){
            cout << "Nivel superado!\n";
            nivel++;
            //---¡guardo-cuando-supero-cada-nivel!
            Guardar();
        } else {
            cout << "Perdiste. Fin del juego.\n";
            break;
        };
    };
};

//---¡construccion-del-metodo-JugarRonda-de-la-clase-Juego!
bool Juego::JugarRonda(){
    const int NUM_JUGADORES = 3;

    Jugador jugadores[NUM_JUGADORES] = {
        Jugador(1,"Jugador1",3),
        Jugador(2,"Jugador2",3),
        Jugador(3,"Jugador3",3) 
    };

    Carta cartas[NUM_JUGADORES][nivel];

    //---¡para-generar-cartas-de-la-ronda!
    for(int i = 0; i < NUM_JUGADORES; i++){
        for(int j = 0; j < nivel; j++){
            cartas[i][j] = Carta(1);
            cartas[i][j].SeleccionarCarta();
        }
    };

    //---¡para-generar-las-cartas-de-cada-nivel!
    int totalCartas = NUM_JUGADORES * nivel;
    int jugadas[100];
    int index = 0;

    //---¡índice-de-carta-actual-pora-cada-jugador!
    int cartaActual[NUM_JUGADORES] = {0, 0, 0};
    
    //---¡los-controles-del-juego!
    cout << "Controles:\n";
    cout << "Jugador1; q\n";
    cout << "Jugador2; v\n";
    cout << "Jugador3; p\n";

    //---¡se-genera-la-rutina-para-detectar-las-entradas-por-teclado!
    while(index < totalCartas){
        char tecla;
        cin >> tecla;

        int jugadorIndex = -1;

        if(tecla == 'q') jugadorIndex = 0;
        else if(tecla == 'v') jugadorIndex = 1;
        else if(tecla == 'p') jugadorIndex = 2;

        if(jugadorIndex == -1){
            cout << "Tecla invalida\n";
            continue;
        };

        //---¡verificar-si-aun-tiene-cartas!
        if(cartaActual[jugadorIndex] >= nivel){
            cout << "Ese jugador ya jugo todas sus cartas\n";
            continue;
        };

        //---¡para-jugar-las-carta!
        jugadores[jugadorIndex].JugarCarta(
            cartas[jugadorIndex][cartaActual[jugadorIndex]]
        );

        jugadas[index] = cartas[jugadorIndex][cartaActual[jugadorIndex]].ObtenerIdCarta();

        cartaActual[jugadorIndex]++;
        index++;
    };

    //---¡validar-el-orden-de-las-cartas!
    for(int i = 0; i < totalCartas - 1; i++){
        if(jugadas[i] > jugadas[i+1]){
            return false;
        };
    };

    for(int i = 0; i < totalCartas - 1; i++){
        if(jugadas[i] > jugadas[i+1]){
            //---¡jugador-que-se-equivoca-pierde-la-vida!
            int jugadorIndex = i % NUM_JUGADORES;//---¡el-índice-del-jugador-que-falla!
            jugadores[jugadorIndex].PerderVida(1);
            return false; //---¡la-ronda-termina!
        };
    };

    return true;
};

//---¡construccion-del-metodo-guardar-de-la-clase-Juego!
void Juego::Guardar(){
    ofstream archivo("file.tri", ios::binary);
    archivo.write((char*)&nivel, sizeof(nivel));
};

//---¡construccion-del-metodo-cargar-de-la-clase-Juego!
void Juego::Cargar(){
    ifstream archivo("file.tri", ios::binary);
    if(archivo.is_open()){
        archivo.read((char*)&nivel, sizeof(nivel));
    };
};