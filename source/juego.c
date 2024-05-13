/*---------------------------------------------------------------------------------
Este código se ha desarrollado basándose en el código de dovoto "Simple sprite demo" 
y en otro ejemplo de Jaeden Ameronen
---------------------------------------------------------------------------------*/


#include <nds.h> 		//librería de la nds
#include <stdio.h>		//librería de entrada/salida estándar de C
#include <stdlib.h>		//librería estándar de C para reserva de memoria y conversiones númericas
#include <unistd.h>		//librería para asegurar la compatibilidad entre sistemas operativos

//librerías desarrolladas por nosotros para el proyecto
	
#include "definiciones.h" //librería de las deficiones para las variables globales y utilizar las funciones
#include "perifericos.h" //librería los periféricos para poder usarlos 
#include "rutinasAtencion.h" //librería de las rutinas de atención
#include "fondos.h" //libreria de los fondos para poder usarlos
#include "funciones.h" //libreria de las funciones para usar los métodos

int x; //Variable x global
int y; //Variable y global

int ex; //Variable ex global que dice si el jugador ha escogido ir a la cueva o a la iglesia

int ContMovCam; //Contador para las escenas

mov=75; //Varíable global y constante que marcará el ritmo del movimiento del jugador

void juego()
{	
	ESTADO=Inicio;	//El juego empieza en el estado inicio
	
	HabilitarIntTeclado(); //Para poder habilitar las rutinas del teclado
	HabilitarIntTempo(); //Para poder habilitar las rutinas del temporizador
	ConfigurarTemporizador(39322, 0x00C2); //Configuración del teclado. 5 ticks por segundo con fecuencia 256 MHz
	ConfigurarTeclado(0x4001); //única tecla para configurar el teclado por interrupción es la A
	EstablecerVectorInt(); //Establecemos el vector de interrupciones
	

	


	while(1)
	{	
		/*
		   Estado inicio se ejecuta la presentación del juego, los controles y la historia del inicio del juego
		*/
		if(ESTADO==Inicio)
		{
			BorrarJugador(); //Borrar los 4 sprites del jugador para que no se muestre el jugador
			BorrarAgujero(1, 100, 159);//Se borra el agujero porque la variable ContMovCam es 0
			/*
			   La pantalla tactil va por encuesta, y cuando la pantalla táctil se ha pulsado, cambia de estado
			*/
			if (TactilTocada()!=0)
			{
				MostrarTextoBlanco();
				ESTADO=JuegoMov;
			}
		}
	        if(ESTADO==JuegoMov)
		{
			/*
			   Cuando ContMovCam valga 0 y 1, visualiza el salón del Rey. Visualiza el Rey cuando ContMovCam valga 1. Mostrará
			   un texto en la pantalla superior indicando donde se situa el NPC e indicando la posición del jugador; ya que 
			   no se muestra el jugador en movimiento
			*/
			if (ContMovCam<=1)
			{
				visualizarSalonTrono();
				MovimientoJugador(mov);
				if(ContMovCam==1)
				{	
					MostrarRey(1,200,159);
					iprintf("\x1b[5;0H Acercate al NPC que se              ");
					iprintf("\x1b[6;0H encuentra en x=200.       X=%d",x);
					iprintf("\x1b[7;0H Luego, pulsa A                      ");
				}
			}
			
			/*
			   Cuando ContMovCam valga 2, visualiza el salón del Rey. El jugador tendrá un poco de livertad antes de seguir con la historia
			*/
			if (ContMovCam==2)
			{
				MovimientoJugador(mov);
				visualizarSalonTrono();
				iprintf("\x1b[5;0H                               ");
				iprintf("\x1b[6;0H                               ");
				iprintf("\x1b[7;0H                               ");
			}
			
			/*
			   Cuando ContMovCam valga 3, visualiza la ciudad y el agujero. Mostrará un texto en la pantalla superior indicando donde se situa el agujero e indicando la posición del jugador; ya que 
			   no se muestra el jugador en movimiento
			*/
			if (ContMovCam==3)
			{
				MovimientoJugador(mov);
				MostrarAgujero(1, 150, 159);
				visualizarCiudad1();
				iprintf("\x1b[5;0H Ve al agujero (x=150) X=%d  ",x);
				iprintf("\x1b[6;0H y pulsa para ABAJO para bajar   ");
				iprintf("\x1b[7;0H                                 ");
			}
			
			/*
			   Cuando ContMovCam valga 4, visualiza la cueva y el árbol. Mostrará un texto en la pantalla superior indicando donde se situa el NPC e indicando la posición del jugador; ya que 
			   no se muestra el jugador en movimiento
			*/
			if (ContMovCam==4)
			{
				MovimientoJugador(mov);
				BorrarAgujero(1, 150, 159);
				MostrarArbol(1,175,159);
				visualizarCueva2NoAranas();
				iprintf("\x1b[5;0H Acercate al NPC (x=175) X=%d",x);
				iprintf("\x1b[6;0H y habla con el arbol            ");
				iprintf("\x1b[7;0H                                 ");
			}
			
			/*
			   Cuando ContMovCam valga 5, visualiza la cueva. El jugador tendrá un poco de livertad antes de seguir con la historia
			*/
			if (ContMovCam==5)
			{
				MovimientoJugador(mov);
				visualizarCueva2NoAranas();
				iprintf("\x1b[5;0H                               ");
				iprintf("\x1b[6;0H                               ");
				iprintf("\x1b[7;0H                               ");
			}
			
			/*
			   Cuando ContMovCam valga 6, visualiza la cueva y la madre. Mostrará un texto en la pantalla superior indicando donde se situa el NPC e indicando la posición del jugador; ya que 
			   no se muestra el jugador en movimiento
			*/
			if (ContMovCam==6)
			{
				eleccion = 1;
				MovimientoJugador(mov);
				MostrarMadre(1,100,159);
				visualizarCueva2NoAranas();
				iprintf("\x1b[5;0H Acercate a la madre para         ");
				iprintf("\x1b[6;0H hablar  (x=100)       X=%d  ",x);
				iprintf("\x1b[7;0H                                  ");
			}
			
			/*
			   Cuando ContMovCam valga 7, visualiza la cuidad. El jugador tendrá un poco de livertad antes de seguir con la historia. Además, aquí tiene que decidir si ir a la cueva o a la iglesia
			*/
			if (ContMovCam==7)
			{
				MovimientoJugador(mov);
				visualizarCiudad2();
				iprintf("\x1b[5;0H ABAJO: Ir a la cueva             ");
				iprintf("\x1b[6;0H ARRIBA: Ir a la iglesia          ");
				iprintf("\x1b[7;0H                                  ");
			}
			
			/*
			   Cuando ContMovCam valga 8, dependiendo de lo que haya elegido, visualizará la iglesia con el cura, o la cueva con la araña. Mostrará un texto en la pantalla superior indicando donde se situa el NPC e indicando la posición del jugador; ya que 
			   no se muestra el jugador en movimiento
			*/
			if (ContMovCam==8)
			{
	  			if (ex==0)
	   			{
					MovimientoJugador(mov);
					visualizarCueva1Aranas();
					MostrarArana(1,200,159);
					iprintf("\x1b[5;0H Acercate al NPC(x=200) X=%d ",x);
					iprintf("\x1b[6;0H Y pulsa A para interactuar       ");
					iprintf("\x1b[7;0H                                  ");
				}
				else if (ex==1)
				{
					MovimientoJugador(mov);
					visualizarIglesiaPriv();
					MostrarCura(1,200,159);
					iprintf("\x1b[5;0H Acercate al NPC(x=200) X=%d ",x);
					iprintf("\x1b[6;0H Y pulsa A para interactuar       ");
					iprintf("\x1b[7;0H                                  ");
				}
			}
			
			/*
			   Cuando ContMovCam valga 9, visualiza la cuidad. El jugador tendrá un poco de livertad antes de seguir con la historia.
			*/
			if (ContMovCam==9)
			{
				MovimientoJugador(mov);
				visualizarCiudad2();
				iprintf("\x1b[5;0H                                  ");
				iprintf("\x1b[6;0H                                  ");
				iprintf("\x1b[7;0H                                  ");
			}
			
			/*
			   Cuando ContMovCam valga 10, visualiza la sala final y el X. Mostrará un texto en la pantalla superior indicando donde se situa el NPC e indicando la posición del jugador; ya que 
			   no se muestra el jugador en movimiento
			*/
			if (ContMovCam==10)
			{
				MovimientoJugador(mov);
				visualizarSalaFinal();
				MostrarX(1,150,159);
				iprintf("\x1b[5;0H Acercate al NPC(x=150) X=%d ",x);
				iprintf("\x1b[6;0H Y pulsa A para interactuar       ");
				iprintf("\x1b[7;0H                                  ");
			}
		}

	}
}



