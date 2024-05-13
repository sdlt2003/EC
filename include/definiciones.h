/*-------------------------------------
definiciones.h
-------------------------------------*/
#include <nds.h> 		//librería de la nds
#include <stdio.h>		//librería de entrada/salida estandar de C
#include <stdlib.h>		//librería estandar de C para reserva de memoria y conversiones númericas
#include <unistd.h>		//librería para asegurar la compatibilidad entre sistemas operativos


#define IME		(*(vuint32*)0x04000208) //Interrupt Master Enable -- Habilitar-deshabilitar todas las interrupciones
#define IE		(*(vuint32*)0x04000210) //Interrupt Enable -- Habilitar-deshabilitar las interrupciones de forma individual
#define IF		(*(vuint32*)0x04000214) //Interrupt Flag -- Registro de solicitud de interrupción

// funciones para el tratamiento general de las interrupciones
#define HabilitarInterrupciones() IME=1 //Habilitar todas las interrupciones
#define DeshabilitarInterrrupciones() IME=0 //Deshabilitar todas las interrupciones

//registros del teclado
#define TECLAS_DAT	(*(vu16*)0x4000130) //registro de datos
#define TECLAS_CNT	(*(vu16*)0x4000132) //registro de control

//registros del temporizador Timer0
#define TIMER0_CNT   (*(vuint16*)0x04000102) //registro de control
#define TIMER0_DAT    (*(vuint16*)0x04000100) //registro de datos



//Acceso a los registros de la pantalla táctil
touchPosition PANT_DAT;

// Nombres asignados a las teclas para facilitar la comprensión de nuestro código

#define A				0 
#define B				1
#define SELECT			2 
#define START			3
#define DERECHA			4 
#define IZQUIERDA			5
#define ARRIBA			6 
#define ABAJO			7
#define R				8 
#define L				9

//Nombres asignados a los estados
#define Inicio 0
#define JuegoMov 1 //Estado para que el jugador pueda moverse
#define JuegoConv 2 //Para que el texto salga en la pantalla y el jugador no se pueda mover
#define FinalEscena 3 //Se aplica los ultimos fondos animados para terminar el juego

extern int ESTADO; //Varaible para indicar el estado del juego
extern int TECLA; //Para saber que tecla se ha pulsado
extern touchPosition pos_pantalla; //Si se ha pulsado la pantalla o no
/*
   Variable para contar las escenas del juego. Cuando el jugador llegue a la derecha del todo, esta varibale sumará uno; o 
   después de las conversaciones sumará uno también para se pueda continuar con el juego
*/
extern int ContMovCam;
extern bool conv; //Varaible de las respuestas
extern int eleccion; //Variable para dar permiso para teclear R o L
/*
     Variable booleana que se usará en este archivo para decidir un final u otro. Esta varibale se usará en las escenas que el jugador deva de escoger. Si pulsa la R su valor será
     TRUE; en cambio, si pulsa la tecla L, será FLASE
*/
extern bool conv; 
extern int ex; //Variable para saber si ha elegido el cura o la araña
extern int mov;
/*
     Variable que cuenta la elección que ha hecho el jugador para luego saber por cual final ir. Es decir, en una escena, la que tiene que elegir si coger opció R u opción L. Si es R,
	 esta variable se multiplicará por dos (si es 0, se sumará dos), y si es L, sumará 1.
*/
extern int contF;

