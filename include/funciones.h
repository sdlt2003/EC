#include <nds.h>
#include <stdio.h>
#include <stdlib.h>		// srand, rand,...
#include <unistd.h>
#include <time.h>       // time 


#include <fondos.h>
#include <graficos.h>
#include <perifericos.h>		
#include <rutinasAtencion.h>
#include <sprites.h>

//Declarar las funciones. 

extern void MovimientoJugador(int tc); //Para el moviento del jugador
extern bool IteracionNPC(int dx); //Para la iteración del NPC
extern int TactilTocada(); //Para la pantalla tactil
extern void MostrarControles(); //Para mostrar los controles
extern void MostrarJuegoInicio1(); //Para mostrar la presentación del juego
extern void MostrarTextoBlanco(); //Para "resetear" el texto
extern void BorrarJugador(); //Para borrar el jugador (borrar los 4 sprites)
extern void MostrarConversacionRey(); //Para mostrar la conversacion del rey
extern void MostrarPresentacion1(); //Para mostrar uno de los inicios de la historia del juego
extern void MostrarHistoria2(); //Para mostrar otro de los inicios de la historia del juego
extern void MostrarHistoria3(); //Para mostrar otro de los inicios de la historia del juego
extern void MostrarHistoria4(); //Para mostrar el final de los inicios de la historia del juego
extern void ConversacionMadreSprite(); //Para mostrar la conversacion con la madre
extern void ConversacionArbolSprite(); //Para mostrar la conversacion con la árbol
extern void ConversacionAranalSprite(); //Para mostrar la conversacion con la araña
extern void ConversacionCuralSprite(); //Para mostrar la conversacion con la cura
extern void ConversacionX1Sprite(); //Para mostrar la conversacion con la X primera parte
extern void ConversacionX2Sprite(); //Para mostrar la conversacion con la X segunda parte
extern void ConversacionFinal1(); //Para mostrar uno de los finales de la historia del juego
extern void ConversacionFinal2_1(); //Para mostrar otro de los finales de la historia del juego 1
extern void ConversacionFinal2_2(); //Para mostrar otro de los finales de la historia del juego 2
extern void ConversacionFinal3_1(); //Para mostrar otro de los finales de la historia del juego 1
extern void ConversacionFinal3_2(); //Para mostrar otro de los finales de la historia del juego 2
extern void ConversacionFinal4_1(); //Para mostrar final de los finales de la historia del juego 1
extern void ConversacionFinal4_2(); //Para mostrar final de los finales de la historia del juego 2




