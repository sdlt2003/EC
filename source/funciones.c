#include <nds.h> 		//libreria de la nds
#include <stdio.h>		//libreria de entrada/salida estandar de C
#include <stdlib.h>		//libreria estandar de C para reserva de memoria y conversiones numericas
#include <unistd.h>		//libreria para asegurar la compatibilidad entre sistemas operativos


//librerias desarrolladas por nosotros para el proyecto
	
#include "definiciones.h" //Incluimos la librería definiciones.h para poder usar las variables globales y sus funciones
#include "perifericos.h" //Incluimos la librería perifericos.h para poder usar las teclas... y sus funciones
#include "rutinasAtencion.h" //Incluimos la librería rutinasAtencion.h para poder usar us funciones
#include "fondos.h" //Incluimos la librería fondos.h para poder usar los fondos y sus funciones
#include "funciones.h" //Incluimos la librería funciones.h para poder usar sus funciones
#include "sprites.h" //Incluimos la librería sprites.h para poder usar los sprites y sus funciones



int x=6; //Variable x global, que su valor de inicio valdrá 6
int y=159; //Variable y que será "constante" porque será la altura en la que los NPCs y el jugador se encuentran

/*
   Al ser el movimiento por encuesta, cuando pulsas las teclas DERCHA o IZQUIERDA, el jugador se muevo a una velocidad
   bastante alta, y por ello esta variable, para hacer que el jugador no se mueva muy rápido y que lo podamos ver
  
*/
int conTecla;

/*
   Variable para contar las escenas del juego. Cuando el jugador llegue a la derecha del todo, esta varibale sumará uno; o 
   después de las conversaciones sumará uno también para se pueda continuar con el juego
*/
int ContMovCam=0;

int eleccion; //Variable "que decide" si el jugador puede elegir  entre dos opciones o no

/*
   Método para el movimiento del Jugador
*/
void MovimientoJugador(int tc)
{
	conTecla++;
	   if(conTecla==tc) //Cuando llegue a la variable que se le pasa por parámetro, se ejecuta el movimiento
	   {
		if (TeclaPulsada()==DERECHA) //Para ir a la derecha
		{
			MostrarJugadorD(1, x, y); 
			if(x%3==0) //Para que vaya mostrando el otro Sprite y para darle un poco de animación al juego
			{
			   MostrarJugadorQd(1, x, y);
			}
			x=x+2; 
			/*
			  Cuando se pase de 234, sumará uno la varibale ContMovCam y el jugador volverá a la posición 6
			*/
			if (x>234) 
			{
				ContMovCam++;
				x=6;
			}
		}

		if (TeclaPulsada()==IZQUIERDA) //Para ir a la izquierda
		{
			MostrarJugadorI(1, x, y);
			if(x%3==0) //Para que vaya mostrando el otro Sprite y para darle un poco de animación al juego
			{
				MostrarJugadorQi(1, x, y);
			}
			x=x-2;
			/*
			  Cuando sea menos que 6 la x, el jugador se mantendrá en la posición 6
			*/
			if(x<6) 
			{
				x=6;
			}
		}
	
		/*
		   Cuando aparezca el agujero, y si estás encima y si pulsa la tecla ABAJO, irá a la cueva
		   Está por encuesta porque forma parte del movimiento
		*/
   		else if ((TeclaPulsada()==ABAJO && x==150) && ContMovCam==3)
   		{
			ContMovCam=4;
			x=6;	
   		}
		
		/*
		   Para elegir: ir a la cueva o ir a la iglesia
		*/
  		else if (ContMovCam==7)
  	 	{
			if (TeclaPulsada()==ABAJO)
      			{
	   			ex=0;
	   			ContMovCam=8;
	   			x=6;
       			}
       			else if (TeclaPulsada()==ARRIBA)
       			{
	   			ex=1;
	   			ContMovCam=8;
	   			x=6;
			}
   		}

		/*
		   Cuando haya opción para hablar, se ejecuta para las opciones
		*/
		if (ContMovCam==6)
		{
      	   		if(TeclaPulsada()==R)
      	  		{
	      			conv = true;
					eleccion==1;
	      			if (contF==0)
	      			{
	         			contF=contF+2;
   	      			}
	      			else 
	      			{
	         			contF=contF*2;
   	      			}
	   		}
      	   		else if (TeclaPulsada()==L)
      	   		{
	      			conv = false;
					eleccion==0;
	      			contF= contF + 1;
      	   		}
		}
	   conTecla=0;
	}
}


/*
   Método que devuelve un booleano si está cerca del NPC
*/
bool IteracionNPC(int dx)
{ 
	return (x>dx-10);	
}


/*
   Método para la pantalla táctil
*/
touchPosition pos_pantalla;
int TactilTocada() {
 	touchRead(&pos_pantalla);
	return !(pos_pantalla.px==0 && pos_pantalla.py==0);
} 


/*
   Método que borra al jugador (los 4 sprites a la vez)
*/
void BorrarJugador()
{
	BorrarJugadorD(1,x,y);
	BorrarJugadorQd(1,x,y);
	BorrarJugadorI(1,x,y);
	BorrarJugadorQi(1,x,y);
}


/*
   Método para mostrar los controles del juego
*/
void MostrarControles()
{
	iprintf("\x1b[0;0H _____________________________    ");
	iprintf("\x1b[1;0H|                             |   ");
	iprintf("\x1b[2;0H|                             |   ");
	iprintf("\x1b[3;0H|                             |   ");
	iprintf("\x1b[4;0H|          CONTROLES          |   ");
	iprintf("\x1b[5;0H|                             |   ");
	iprintf("\x1b[6;0H|                             |   ");
	iprintf("\x1b[7;0H| Izquierda         Derecha   |   ");
	iprintf("\x1b[8;0H|                             |   ");
        iprintf("\x1b[9;0H _____________________________    ");
       iprintf("\x1b[10;0H|                             |   ");
       iprintf("\x1b[11;0H| *Para interactuar con       |   ");
       iprintf("\x1b[12;0H|   los NPCs, pulse A         |   ");
       iprintf("\x1b[13;0H _____________________________    ");
       iprintf("\x1b[14;0H|                             |   ");
       iprintf("\x1b[15;0H| *Iniciar juego:             |   ");
       iprintf("\x1b[16;0H|   Pulsar la pantalla tactil |   ");
       iprintf("\x1b[17;0H _____________________________    ");
       iprintf("\x1b[18;0H|                             |   ");
       iprintf("\x1b[19;0H|                             |   ");
       iprintf("\x1b[20;0H|                             |   ");
       iprintf("\x1b[21;0H _____________________________    ");
}

/*
   Método para mostrar la presentación del juego
*/
void MostrarJuegoInicio1()
{
	iprintf("\x1b[0;0H _____________________________    ");
	iprintf("\x1b[1;0H|                             |   ");
	iprintf("\x1b[2;0H|    ********************     |   ");
	iprintf("\x1b[3;0H|    *   PROYECTO EC    *     |   ");
	iprintf("\x1b[4;0H|    * CURSO: 2021-2022 *     |   ");
	iprintf("\x1b[5;0H|    *   GRUPO EC-105   *     |   ");
	iprintf("\x1b[6;0H|    ********************     |   ");
	iprintf("\x1b[7;0H|                             |   ");
	iprintf("\x1b[8;0H|         Unai Artano,        |   ");
        iprintf("\x1b[9;0H|      Inigo Berasategui,     |   ");
       iprintf("\x1b[10;0H|    y Sergio de los Toyos    |   ");
       iprintf("\x1b[11;0H|                             |   ");
       iprintf("\x1b[12;0H|        Bienvenid@ a         |   ");
       iprintf("\x1b[13;0H|         BLASFEMOOS          |   ");
       iprintf("\x1b[14;0H _____________________________    ");
       iprintf("\x1b[15;0H| Sera un juego de una gran   |   ");
       iprintf("\x1b[16;0H|  aventura que se creara a   |   ");
       iprintf("\x1b[17;0H| medida que vayas eligiendo  |   ");
       iprintf("\x1b[18;0H|     un dialogo u otro.      |   ");
       iprintf("\x1b[19;0H|  ¡Mucha suerte aventurer@  |    ");
       iprintf("\x1b[20;0H|     y que lo disfrutes!     |   ");
       iprintf("\x1b[21;0H _____________________________    ");
}

/*
   Método para que no muestre nada de texto
*/
void MostrarTextoBlanco()
{
	iprintf("\x1b[0;0H                                  ");
	iprintf("\x1b[1;0H                                  ");
	iprintf("\x1b[2;0H                                  ");
	iprintf("\x1b[3;0H                                  ");
	iprintf("\x1b[4;0H                                  ");
	iprintf("\x1b[5;0H                                  ");
	iprintf("\x1b[6;0H                                  ");
	iprintf("\x1b[7;0H                                  ");
	iprintf("\x1b[8;0H                                  ");
        iprintf("\x1b[9;0H                                  ");
       iprintf("\x1b[10;0H                                  ");
       iprintf("\x1b[11;0H                                  ");
       iprintf("\x1b[12;0H                                  ");
       iprintf("\x1b[13;0H                                  ");
       iprintf("\x1b[14;0H                                  ");
       iprintf("\x1b[15;0H                                  ");
       iprintf("\x1b[16;0H                                  ");
       iprintf("\x1b[17;0H                                  ");
       iprintf("\x1b[18;0H                                  ");
       iprintf("\x1b[19;0H                                  ");
       iprintf("\x1b[20;0H                                  ");
       iprintf("\x1b[21;0H                                  ");
}

/*
   Método para mostrar la conversación con el Rey
*/
void MostrarConversacionRey()
{
	iprintf("\x1b[0;0H                                  ");
	iprintf("\x1b[1;0H                                  ");
	iprintf("\x1b[2;0H                                  ");
	iprintf("\x1b[3;0H                                  ");
	iprintf("\x1b[4;0H                                  ");
	iprintf("\x1b[5;0H Aah. Al fin has venido. La       ");
	iprintf("\x1b[6;0H espera ha sido larga. Creo       ");
	iprintf("\x1b[7;0H que sabes cual es tu trabajo,    ");
	iprintf("\x1b[8;0H vigilante. Consigue llegar       ");
	iprintf("\x1b[9;0H hasta el pico y entrega la       ");
       iprintf("\x1b[10;0H carta. Recuerda que es una       ");
       iprintf("\x1b[11;0H mision urgente, no te            ");
       iprintf("\x1b[12;0H distraigas con nada ni nadie.    ");
       iprintf("\x1b[13;0H                                  ");
       iprintf("\x1b[14;0H Es una orden del Rey.            ");
       iprintf("\x1b[15;0H                                  ");
       iprintf("\x1b[16;0H Que el aura te acompane.         ");
       iprintf("\x1b[17;0H                                  ");
       iprintf("\x1b[18;0H                                  ");
       iprintf("\x1b[19;0H                                  ");
       iprintf("\x1b[20;0H                                  ");
       iprintf("\x1b[21;0H                                  ");
}

/*
   Método para mostrar parte del inicio de la historia1
*/
void MostrarPresentacion1()
{
	iprintf("\x1b[0;0H                                  ");
	iprintf("\x1b[1;0H                                  ");
	iprintf("\x1b[2;0H                                  ");
	iprintf("\x1b[3;0H                                  ");
	iprintf("\x1b[4;0H                                  ");
	iprintf("\x1b[5;0H Si, en efecto. Es el reino       ");
	iprintf("\x1b[6;0H de Irithyll. Aquel tuvo la       ");
	iprintf("\x1b[7;0H gracia de los dioese. Aquel      ");
	iprintf("\x1b[8;0H que la perdio. Los dioses,       ");
	iprintf("\x1b[9;0H representacion misma del         ");
       iprintf("\x1b[10;0H aura, imbuidos en la soledad     ");
       iprintf("\x1b[11;0H del vacio, crearon el todo.      ");
       iprintf("\x1b[12;0H                                  ");
       iprintf("\x1b[13;0H Y dentro del todo estaba el      ");
       iprintf("\x1b[14;0H reino.                           ");
       iprintf("\x1b[15;0H                                  ");
       iprintf("\x1b[16;0H                                  ");
       iprintf("\x1b[17;0H                                  ");
       iprintf("\x1b[18;0H                                  ");
       iprintf("\x1b[19;0H                                  ");
       iprintf("\x1b[20;0H                                  ");
       iprintf("\x1b[21;0H                                  ");
}

/*
   Método para mostrar parte del inicio de la historia2
*/
void MostrarHistoria2()
{
	iprintf("\x1b[0;0H                                  ");
	iprintf("\x1b[1;0H                                  ");
	iprintf("\x1b[2;0H                                  ");
	iprintf("\x1b[3;0H                                  ");
	iprintf("\x1b[4;0H                                  ");
	iprintf("\x1b[5;0H                                  ");
	iprintf("\x1b[6;0H                                  ");
	iprintf("\x1b[7;0H                                  ");
	iprintf("\x1b[8;0H Como no podia ser de otra        ");
        iprintf("\x1b[9;0H forma el reino prospero.         ");
       iprintf("\x1b[10;0H Grandes reyes se alzaron y       ");
       iprintf("\x1b[11;0H cayeron, no sin antes haber      ");
       iprintf("\x1b[12;0H extendido su poder.              ");
       iprintf("\x1b[13;0H                                  ");
       iprintf("\x1b[14;0H                                  ");
       iprintf("\x1b[15;0H                                  ");
       iprintf("\x1b[16;0H                                  ");
       iprintf("\x1b[17;0H                                  ");
       iprintf("\x1b[18;0H                                  ");
       iprintf("\x1b[19;0H                                  ");
       iprintf("\x1b[20;0H                                  ");
       iprintf("\x1b[21;0H                                  ");
}

/*
   Método para mostrar parte del inicio de la historia3
*/
void MostrarHistoria3()
{
	iprintf("\x1b[0;0H                                  ");
	iprintf("\x1b[1;0H                                  ");
	iprintf("\x1b[2;0H                                  ");
	iprintf("\x1b[3;0H                                  ");
	iprintf("\x1b[4;0H                                  ");
	iprintf("\x1b[5;0H                                  ");
	iprintf("\x1b[6;0H                                  ");
	iprintf("\x1b[7;0H                                  ");
	iprintf("\x1b[8;0H Pero la avaricia no tiene        ");
    	iprintf("\x1b[9;0H limite. En nuestra insensatez    ");
       iprintf("\x1b[10;0H creimos estar a la altura de     ");
       iprintf("\x1b[11;0H los dioses. Y esa fue nuestra    ");
       iprintf("\x1b[12;0H perdicion.                       ");
       iprintf("\x1b[13;0H                                  ");
       iprintf("\x1b[14;0H                                  ");
       iprintf("\x1b[15;0H                                  ");
       iprintf("\x1b[16;0H                                  ");
       iprintf("\x1b[17;0H                                  ");
       iprintf("\x1b[18;0H                                  ");
       iprintf("\x1b[19;0H                                  ");
       iprintf("\x1b[20;0H                                  ");
       iprintf("\x1b[21;0H                                  ");
}

/*
   Método para mostrar parte del inicio de la historia4
*/
void MostrarHistoria4()
{
	iprintf("\x1b[0;0H                                  ");
	iprintf("\x1b[1;0H                                  ");
	iprintf("\x1b[2;0H                                  ");
	iprintf("\x1b[3;0H                                  ");
	iprintf("\x1b[4;0H                                  ");
	iprintf("\x1b[5;0H                                  ");
	iprintf("\x1b[6;0H                                  ");
	iprintf("\x1b[7;0H                                  ");
	iprintf("\x1b[8;0H El ultimo rey, Askeladd, ante    ");
        iprintf("\x1b[9;0H la desesperacion intento         ");
       iprintf("\x1b[10;0H hacer un ultimo esfuerzo.        ");
       iprintf("\x1b[11;0H Dejar el futuro de Irithyll      ");
       iprintf("\x1b[12;0H en manos de un vigilante.        ");
       iprintf("\x1b[13;0H                                  ");
       iprintf("\x1b[14;0H                                  ");
       iprintf("\x1b[15;0H                                  ");
       iprintf("\x1b[16;0H                                  ");
       iprintf("\x1b[17;0H                                  ");
       iprintf("\x1b[18;0H                                  ");
       iprintf("\x1b[19;0H                                  ");
       iprintf("\x1b[20;0H                                  ");
       iprintf("\x1b[21;0H                                  ");
}

/*
   Método para mostrar la conversación con la madre y su hijo
*/
void ConversacionMadreSprite()
{
	iprintf("\x1b[0;0H                                  ");
	iprintf("\x1b[1;0H                                  ");
	iprintf("\x1b[2;0H                                  ");
	iprintf("\x1b[3;0H Oh. Un vigilante. Jamas pense    ");
	iprintf("\x1b[4;0H que veria uno por aqui. Por      ");
	iprintf("\x1b[5;0H favor ayudame. Mi hijo ha        ");
	iprintf("\x1b[6;0H sido victima de unos miembros    ");
	iprintf("\x1b[7;0H de la hermandad sin              ");
        iprintf("\x1b[8;0H estandartes. Por favor, tiene    ");
        iprintf("\x1b[9;0H que haber alguna forma. No       ");
       iprintf("\x1b[10;0H puedo ver asi a mi hijo…         ");
       iprintf("\x1b[11;0H                                  ");
       iprintf("\x1b[12;0H Entiendo. Entonces por favor     ");
       iprintf("\x1b[13;0H acaba con su sufrimiento. Al     ");
       iprintf("\x1b[14;0H fin y al cabo es lo que mejor    ");
       iprintf("\x1b[15;0H sabeis hacer los vigilantes      ");
       iprintf("\x1b[16;0H ¿no?                             ");
       iprintf("\x1b[17;0H                                  ");
       iprintf("\x1b[18;0H R: Si. Lo cumplire               ");
       iprintf("\x1b[19;0H                                  ");
       iprintf("\x1b[20;0H L: Lo siento pero no             ");
       iprintf("\x1b[21;0H                                  ");
}

/*
   Método para mostrar la conversación con el Árbol
*/
void ConversacionArbolSprite()
{
	iprintf("\x1b[0;0H                                  ");
	iprintf("\x1b[1;0H                                  ");
	iprintf("\x1b[2;0H Saludos. Me podrias sacar        ");
	iprintf("\x1b[3;0H de aqui por favor? Jeje.         ");
	iprintf("\x1b[4;0H Es broma… Los vigilantes         ");
	iprintf("\x1b[5;0H no teneis el sentido del         ");
	iprintf("\x1b[6;0H humor muy desarrollado eh…       ");
	iprintf("\x1b[7;0H En fin. Se de tu mision          ");
  	iprintf("\x1b[8;0H vigilante. Igual que lo se       ");
        iprintf("\x1b[9;0H todo. Soy un arbol al fin y      ");
       iprintf("\x1b[10;0H al cabo. Como podras ver tu      ");
       iprintf("\x1b[11;0H camino se bifurca. Puedes ir     ");
       iprintf("\x1b[12;0H por la iglesia y encontrarte     ");
       iprintf("\x1b[13;0H con mi viejo amigo Tyr o ir      ");
       iprintf("\x1b[14;0H por la cueva y encontrarte a     ");
       iprintf("\x1b[15;0H la temible bestia.               ");
       iprintf("\x1b[16;0H                                  ");
       iprintf("\x1b[17;0H La decisiones tuya companero,    ");
       iprintf("\x1b[18;0H a mi me es indiferente. Al       ");
       iprintf("\x1b[19;0H fin y al  cabo, soy un arbol.    ");
       iprintf("\x1b[20;0H                                  ");
       iprintf("\x1b[21;0H                                  ");
}

/*
   Método para mostrar la conversación con la Araña
*/
void ConversacionAranalSprite()
{
	iprintf("\x1b[0;0H                                  ");
	iprintf("\x1b[1;0H                                  ");
	iprintf("\x1b[2;0H                                  ");
	iprintf("\x1b[3;0H                                  ");
	iprintf("\x1b[4;0H Hola. Encantado de conocerte.    ");
	iprintf("\x1b[5;0H Es un hermoso dia,               ");
	iprintf("\x1b[6;0H no es asi?                       ");
	iprintf("\x1b[7;0H Las gotas fluyen, los ninos      ");
	iprintf("\x1b[8;0H se divierten. Que triste!        ");
        iprintf("\x1b[9;0H De mi todos huyen o en           ");
       iprintf("\x1b[10;0H comida se convierten. Pero       ");
       iprintf("\x1b[11;0H no tengo tela que atrape a       ");
       iprintf("\x1b[12;0H mis presas. La edad pasa         ");
       iprintf("\x1b[13;0H factura, no es ninguna           ");
       iprintf("\x1b[14;0H sorpresa.                        ");
       iprintf("\x1b[15;0H                                  ");
       iprintf("\x1b[16;0H No tendras tela para darle a     ");
       iprintf("\x1b[17;0H esta arana y ayudar a la         ");
       iprintf("\x1b[18;0H empresa?                         ");
       iprintf("\x1b[19;0H                                  ");
       iprintf("\x1b[20;0H                                  ");
       iprintf("\x1b[21;0H                                  ");
}

/*
   Método para mostrar la conversación con el Cura
*/
void ConversacionCuralSprite()
{
	iprintf("\x1b[0;0H                                  ");
	iprintf("\x1b[1;0H                                  ");
	iprintf("\x1b[2;0H                                  ");
	iprintf("\x1b[3;0H                                  ");
	iprintf("\x1b[4;0H Noto una presencia cerca.        ");
	iprintf("\x1b[5;0H Hay alguien ahi? Oh, un          ");
	iprintf("\x1b[6;0H vigilante en una iglesia.        ");
	iprintf("\x1b[7;0H No vienes a confesar tus         ");
	iprintf("\x1b[8;0H pecados, de eso estoy seguro.    ");
        iprintf("\x1b[9;0H Mis companeros se fueron,        ");
       iprintf("\x1b[10;0H abandonaron la fe y a mi con     ");
       iprintf("\x1b[11;0H ella. Soy el unico habitante     ");
       iprintf("\x1b[12;0H de esta iglesia. O eso creo,     ");
       iprintf("\x1b[13;0H no lo puedo ver. Estoy ciego     ");
       iprintf("\x1b[14;0H y la cantidad de tomos en        ");
       iprintf("\x1b[15;0H braile disponible es minima.     ");
       iprintf("\x1b[16;0H Ojala tener mas material. El     ");
       iprintf("\x1b[17;0H estudio y la fe son mi unica     ");
       iprintf("\x1b[18;0H salvacion ante la muerte que     ");
       iprintf("\x1b[19;0H se aproxima…                     ");
       iprintf("\x1b[20;0H                                  ");
       iprintf("\x1b[21;0H                                  ");
}

/*
   Método para mostrar la conversación con el X (primera parte)
*/
void ConversacionX1Sprite()
{
	iprintf("\x1b[0;0H                                  ");
	iprintf("\x1b[1;0H                                  ");
	iprintf("\x1b[2;0H                                  ");
	iprintf("\x1b[3;0H                                  ");
	iprintf("\x1b[4;0H                                  ");
	iprintf("\x1b[5;0H                                  ");
	iprintf("\x1b[6;0H Al fin llegas. Se de tu          ");
	iprintf("\x1b[7;0H mision. El rey te ha             ");
	iprintf("\x1b[8;0H enviado a por el aura.           ");
        iprintf("\x1b[9;0H Cual es su intencion?            ");
       iprintf("\x1b[10;0H Ganar poder para poder           ");
       iprintf("\x1b[11;0H extender un poco mas lo          ");
       iprintf("\x1b[12;0H inevitable? Por un par de        ");
       iprintf("\x1b[13;0H anos mas de dominacion           ");
       iprintf("\x1b[14;0H sobre los otros reinos?          ");
       iprintf("\x1b[15;0H                                  ");
       iprintf("\x1b[16;0H                                  ");
       iprintf("\x1b[17;0H                                  ");
       iprintf("\x1b[18;0H                                  ");
       iprintf("\x1b[19;0H                                  ");
       iprintf("\x1b[20;0H                                  ");
       iprintf("\x1b[21;0H                                  ");
}

/*
   Método para mostrar la conversación con el X (segunda parte)
*/
void ConversacionX2Sprite()
{
	iprintf("\x1b[0;0H                                  ");
	iprintf("\x1b[1;0H                                  ");
	iprintf("\x1b[2;0H                                  ");
	iprintf("\x1b[3;0H                                  ");
	iprintf("\x1b[4;0H No es la primera vez que         ");
	iprintf("\x1b[5;0H algo asi se hace. Pero si        ");
	iprintf("\x1b[6;0H bajo estas circunstancias…       ");
	iprintf("\x1b[7;0H El egoismo ciega la mente.       ");
	iprintf("\x1b[8;0H a caida de los grandes           ");
        iprintf("\x1b[9;0H senores solo trae que unos       ");
       iprintf("\x1b[10;0H nuevos surjan. Pero cada uno     ");
       iprintf("\x1b[11;0H de ellos solo quiere             ");
       iprintf("\x1b[12;0H mantenerse en pie tanto como     ");
       iprintf("\x1b[13;0H le sea posible, incluso si       ");
       iprintf("\x1b[14;0H eso supone danar a otros.        ");
       iprintf("\x1b[15;0H Se te ha encomendado una         ");
       iprintf("\x1b[16;0H mision pero… Quieres seguir      ");
       iprintf("\x1b[17;0H con este ciclo?                  ");
       iprintf("\x1b[18;0H                                  ");
       iprintf("\x1b[19;0H                                  ");
       iprintf("\x1b[20;0H                                  ");
       iprintf("\x1b[21;0H                                  ");
}

/*
   Método para mostrar un final de la historia
*/
void ConversacionFinal1()
{
	iprintf("\x1b[0;0H                                  ");
	iprintf("\x1b[1;0H                                  ");
	iprintf("\x1b[2;0H                                  ");
	iprintf("\x1b[3;0H Los dioses ven a la raza         ");
	iprintf("\x1b[4;0H humana como meros pasatiempos.   ");
	iprintf("\x1b[5;0H Pero no por ello ignorarian      ");
	iprintf("\x1b[6;0H una ultima peticion. La carta    ");
	iprintf("\x1b[7;0H del rey, pidiendo un ultimo      ");
	iprintf("\x1b[8;0H resquicio de aura logro su       ");
        iprintf("\x1b[9;0H efecto. Askeladd tomo el aura    ");
       iprintf("\x1b[10;0H y la uso para intentar emerger   ");
       iprintf("\x1b[11;0H como un nuevo dios. Un ser       ");
       iprintf("\x1b[12;0H omnisciente, inmortal. Crearia   ");
       iprintf("\x1b[13;0H el reino eterno. O eso queria.   ");
       iprintf("\x1b[14;0H La corona aguanto siglos. Todos   ");
       iprintf("\x1b[15;0H ellos bajo un rey en decadencia.   ");
       iprintf("\x1b[16;0H La epoca fue conocida como 'los   ");
       iprintf("\x1b[17;0H anos oscuros'. El rey murio con   ");
       iprintf("\x1b[18;0H su deseo. Y con el su reino.     ");
       iprintf("\x1b[19;0H                                  ");
       iprintf("\x1b[20;0H                                  ");
       iprintf("\x1b[21;0H                                  ");
}

/*
   Método para mostrar otro final de la historia (parte 1)
*/
void ConversacionFinal2_1()
{
	iprintf("\x1b[0;0H                                  ");
	iprintf("\x1b[1;0H                                  ");
	iprintf("\x1b[2;0H                                  ");
	iprintf("\x1b[3;0H                                  ");
	iprintf("\x1b[4;0H Los dioses ven a la raza         ");
	iprintf("\x1b[5;0H humana como meros                ");
	iprintf("\x1b[6;0H pasatiempos. Pero no por         ");
	iprintf("\x1b[7;0H ello ignorarian una ultima       ");
	iprintf("\x1b[8;0H peticion. La carta del rey,      ");
        iprintf("\x1b[9;0H pidiendo un ultimo resquicio     ");
       iprintf("\x1b[10;0H de aura logro su efecto.         ");
       iprintf("\x1b[11;0H Askeladd tomo el aura y la       ");
       iprintf("\x1b[12;0H uso para intentar emerger        ");
       iprintf("\x1b[13;0H como un nuevo dios. Un ser       ");
       iprintf("\x1b[14;0H omnisciente, inmortal. Crearia   ");
       iprintf("\x1b[15;0H el reino eterno. O eso queria.   ");
       iprintf("\x1b[16;0H                                  ");
       iprintf("\x1b[17;0H                                  ");
       iprintf("\x1b[18;0H                                  ");
       iprintf("\x1b[19;0H                                  ");
       iprintf("\x1b[20;0H                                  ");
       iprintf("\x1b[21;0H                                  ");
}

/*
   Método para mostrar otro final de la historia (parte 2)
*/
void ConversacionFinal2_2()
{
	iprintf("\x1b[0;0H                                  ");
	iprintf("\x1b[1;0H                                  ");
	iprintf("\x1b[2;0H                                  ");
	iprintf("\x1b[3;0H                                  ");
	iprintf("\x1b[4;0H                                  ");
	iprintf("\x1b[5;0H                                  ");
	iprintf("\x1b[6;0H El rey murio al dia siguiente    ");
	iprintf("\x1b[7;0H a manos del vigilante. El reino  ");
	iprintf("\x1b[8;0H aguanto milenios, todos ellos    ");
        iprintf("\x1b[9;0H bajo el mando del vigilante,     ");
       iprintf("\x1b[10;0H cuya aura era superior a la de   ");
       iprintf("\x1b[11;0H cualquier morta, practimente al  ");
       iprintf("\x1b[12;0H nivel de los dioses. Con el      ");
       iprintf("\x1b[13;0H tiempo el vigilante abandono su  ");
       iprintf("\x1b[14;0H trono. Y con ello murio el       ");
       iprintf("\x1b[15;0H reino.                           ");
       iprintf("\x1b[16;0H                                  ");
       iprintf("\x1b[17;0H                                  ");
       iprintf("\x1b[18;0H                                  ");
       iprintf("\x1b[19;0H                                  ");
       iprintf("\x1b[20;0H                                  ");
       iprintf("\x1b[21;0H                                  ");
}

/*
   Método para mostrar otro final de la historia (parte 1)
*/
void ConversacionFinal3_1()
{
	iprintf("\x1b[0;0H                                  ");
	iprintf("\x1b[1;0H                                  ");
	iprintf("\x1b[2;0H                                  ");
	iprintf("\x1b[3;0H                                  ");
	iprintf("\x1b[4;0H                                  ");
	iprintf("\x1b[5;0H Asi concluyeron los anos de      ");
	iprintf("\x1b[6;0H dominio del reino de Irythill.   ");
	iprintf("\x1b[7;0H El rey Askeladd sumido en la     ");
	iprintf("\x1b[8;0H desesperacion procuro            ");
        iprintf("\x1b[9;0H mantenerse en pie tanto como     ");
       iprintf("\x1b[10;0H le fue posible. Pero poco pudo   ");
       iprintf("\x1b[11;0H hacer ante las revueltas y       ");
       iprintf("\x1b[12;0H ataques extranjeros. El aura     ");
       iprintf("\x1b[13;0H se esfumo de la corona. Pero     ");
       iprintf("\x1b[14;0H esta no se destruye ni se crea.  ");
       iprintf("\x1b[15;0H                                  ");
       iprintf("\x1b[16;0H                                  ");
       iprintf("\x1b[17;0H                                  ");
       iprintf("\x1b[18;0H                                  ");
       iprintf("\x1b[19;0H                                  ");
       iprintf("\x1b[20;0H                                  ");
       iprintf("\x1b[21;0H                                  ");
}

/*
   Método para mostrar otro final de la historia (parte 2)
*/
void ConversacionFinal3_2()
{
	iprintf("\x1b[0;0H                                  ");
	iprintf("\x1b[1;0H                                  ");
	iprintf("\x1b[2;0H                                  ");
	iprintf("\x1b[3;0H                                  ");
	iprintf("\x1b[4;0H                                  ");
	iprintf("\x1b[5;0H                                  ");
	iprintf("\x1b[6;0H Y en otras tierras, otros        ");
	iprintf("\x1b[7;0H senores tomaron el relevo de     ");
	iprintf("\x1b[8;0H esta. Mas grandes reinos se      ");
        iprintf("\x1b[9;0H todos tomarian Irythill como     ");
       iprintf("\x1b[10;0H ejemplo de que hasta las mas     ");
       iprintf("\x1b[11;0H grandes dinastias estan          ");
       iprintf("\x1b[12;0H destinadas a morir algun dia.    ");
       iprintf("\x1b[13;0H                                  ");
       iprintf("\x1b[14;0H                                  ");
       iprintf("\x1b[15;0H                                  ");
       iprintf("\x1b[16;0H                                  ");
       iprintf("\x1b[17;0H                                  ");
       iprintf("\x1b[18;0H                                  ");
       iprintf("\x1b[19;0H                                  ");
       iprintf("\x1b[20;0H                                  ");
       iprintf("\x1b[21;0H                                  ");
}

/*
   Método para mostrar el último final de la historia (parte 1)
*/
void ConversacionFinal4_1()
{
	iprintf("\x1b[0;0H                                  ");
	iprintf("\x1b[1;0H                                  ");
	iprintf("\x1b[2;0H                                  ");
	iprintf("\x1b[3;0H                                  ");
	iprintf("\x1b[4;0H                                  ");
	iprintf("\x1b[5;0H                                  ");
	iprintf("\x1b[6;0H                                  ");
	iprintf("\x1b[7;0H Asi concluyeron los anos de      ");
	iprintf("\x1b[8;0H dominio del reino de             ");
        iprintf("\x1b[9;0H Irythill. El rey Askeladd        ");
       iprintf("\x1b[10;0H sumido en la desesperacion       ");
       iprintf("\x1b[11;0H procuro mantenerse en pie        ");
       iprintf("\x1b[12;0H tanto como le fue posible.       ");
       iprintf("\x1b[13;0H                                  ");
       iprintf("\x1b[14;0H                                  ");
       iprintf("\x1b[15;0H                                  ");
       iprintf("\x1b[16;0H                                  ");
       iprintf("\x1b[17;0H                                  ");
       iprintf("\x1b[18;0H                                  ");
       iprintf("\x1b[19;0H                                  ");
       iprintf("\x1b[20;0H                                  ");
       iprintf("\x1b[21;0H                                  ");
}

/*
   Método para mostrar el último final de la historia (parte 2)
*/
void ConversacionFinal4_2()
{
	iprintf("\x1b[0;0H                                  ");
	iprintf("\x1b[1;0H                                  ");
	iprintf("\x1b[2;0H                                  ");
	iprintf("\x1b[3;0H                                  ");
	iprintf("\x1b[4;0H                                  ");
	iprintf("\x1b[5;0H Pero poco pudo hacer ante las    ");
	iprintf("\x1b[6;0H revueltas y ataques              ");
	iprintf("\x1b[7;0H extranjeros. El aura se          ");
	iprintf("\x1b[8;0H esfumo de la corona. Pero        ");
        iprintf("\x1b[9;0H esta no se destruye ni se        ");
       iprintf("\x1b[10;0H crea. Fluye en las personas      ");
       iprintf("\x1b[11;0H que profesan su fe. No habia     ");
       iprintf("\x1b[12;0H ser con mas aura que el          ");
       iprintf("\x1b[13;0H vigilante. Que desafio a los     ");
       iprintf("\x1b[14;0H dioses y gano. Todo volvio al    ");
       iprintf("\x1b[15;0H vacio del inicio.                ");
       iprintf("\x1b[16;0H                                  ");
       iprintf("\x1b[17;0H                                  ");
       iprintf("\x1b[18;0H                                  ");
       iprintf("\x1b[19;0H                                  ");
       iprintf("\x1b[20;0H                                  ");
       iprintf("\x1b[21;0H                                  ");
}

