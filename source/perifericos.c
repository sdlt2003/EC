/*-------------------------------------
perifericos.c
-------------------------------------*/

#include <nds.h>
#include <stdio.h>
#include "definiciones.h"


int tecla; //variable para guardar la tecla pulsada


//Detecta si se ha pulsado una tecla
int TeclaDetectada() 
{
	if ((~TECLAS_DAT & 0x03ff)!=0) return 1;
	else return 0;

}

//Devuelve la tecla que se ha pulsado
int TeclaPulsada() 
{
	if ((TECLAS_DAT & 0x0001)==0) return A;
	else if ((TECLAS_DAT & 0x0002)==0) return B;
	else if ((TECLAS_DAT & 0x0004)==0) return SELECT;
	else if ((TECLAS_DAT & 0x0008)==0) return START;
	else if ((TECLAS_DAT & 0x0010)==0) return DERECHA;
	else if ((TECLAS_DAT & 0x0020)==0) return IZQUIERDA;
	else if ((TECLAS_DAT & 0x0040)==0) return ARRIBA;
	else if ((TECLAS_DAT & 0x0080)==0) return ABAJO;
	else if ((TECLAS_DAT & 0x0100)==0) return R;
	else if ((TECLAS_DAT & 0x0200)==0) return L;

}

//Configuración para el teclado
void ConfigurarTeclado(int Conf_Tec)
{
	TECLAS_CNT=TECLAS_CNT|Conf_Tec;
	
	
}

//Configuracion del temporizador
void ConfigurarTemporizador(int Latch, int Conf_Tempo)
{
	TIMER0_DAT=Latch;
	TIMER0_CNT=TIMER0_CNT|Conf_Tempo;

	
}

//Habilitamos las interrupciones del teclado
void HabilitarIntTeclado()
{
	IME=0;

	IE |= 0x00001000;
	
	IME=1;
}

//Inhibimos la interrupcion del teclado
void InhibirIntTeclado()
{

	IME=0;

	IE &= 0xFFFFEFFF;

	IME=1;
}  

//Habilitamos el temporizado
void HabilitarIntTempo()
{ 
	IME=0;

	IE |= 0x00000008;
	
	IME=1;
}

//Inhibimos la interrupcion del temporizador
void InhibirIntTempo()
{
	IME=0;

	//IE &= 0xFFFFFFF8;
	IE &= 0xFFFFFFF7;
	
	IME=1;

}

//Para poner en marcha el temporizador
void PonerEnMarchaTempo()
{

	TIMER0_CNT |= 0x0080;
	
}

//Para parar el temporizador
void PararTempo()
{

	TIMER0_CNT &= 0xFF7F;
	
}
