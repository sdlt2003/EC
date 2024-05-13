/*---------------------------------------------------------------------------------

Kode hau garatu da dovotoren "Simple sprite demo" adibidean eta Jaeden Ameronen beste

adibide batean oinarrituta.

---------------------------------------------------------------------------------*/



#include <nds.h> 		

#include <stdio.h>		

#include <stdlib.h>		

#include <unistd.h>		



#include "sprites.h"

#include "definiciones.h"



u16* gfxjugadord;

u16* gfxjugadorQd;

u16* gfxjugadori;

u16* gfxjugadorQi;

u16* gfxcura;

u16* gfxrey;

u16* gfxarbol;

u16* gfxmadre;

u16* gfxarana;

u16* gfxX;

u16* gfxAgujero;




/* Reservar memoria para cada sprite que se quiera mostrar en pantalla.*/

void memoriaReserba()

{

	/* Pantaila nagusian gehitu nahi den sprite bakoitzarentzako horrelako bat egin behar da. */

	gfxjugadord= oamAllocateGfx(&oamMain, SpriteSize_16x16, SpriteColorFormat_256Color);

	gfxjugadorQd= oamAllocateGfx(&oamMain, SpriteSize_16x16, SpriteColorFormat_256Color);

	gfxjugadori= oamAllocateGfx(&oamMain, SpriteSize_16x16, SpriteColorFormat_256Color);

	gfxjugadorQi= oamAllocateGfx(&oamMain, SpriteSize_16x16, SpriteColorFormat_256Color);

	gfxcura= oamAllocateGfx(&oamMain, SpriteSize_16x16, SpriteColorFormat_256Color);

	gfxrey= oamAllocateGfx(&oamMain, SpriteSize_16x16, SpriteColorFormat_256Color);

	gfxarbol= oamAllocateGfx(&oamMain, SpriteSize_16x16, SpriteColorFormat_256Color);

	gfxmadre= oamAllocateGfx(&oamMain, SpriteSize_16x16, SpriteColorFormat_256Color);

	gfxarana= oamAllocateGfx(&oamMain, SpriteSize_16x16, SpriteColorFormat_256Color);

	gfxX= oamAllocateGfx(&oamMain, SpriteSize_16x16, SpriteColorFormat_256Color);

	gfxAgujero= oamAllocateGfx(&oamMain, SpriteSize_16x16, SpriteColorFormat_256Color);
}



/* A cada uno de los 256 valores que puede tomar un pixel en la PALETA PRINCIPAL

   se le puede asignar un color. El valor 0 es transparente. Los valores sin definir son negros. 

   MODIFICAR SEGÚN LOS COLORES QUE QUERAIS UTILIZAR EN VUESTROS SPRITES*/

void EstablecerPaletaPrincipal() {



	SPRITE_PALETTE[1] = RGB15(31,0,0);

    	SPRITE_PALETTE[2] = RGB15(31,31,0);

    	SPRITE_PALETTE[3] = RGB15(31,31,31);

    	SPRITE_PALETTE[4] = RGB15(0,31,0);

    	SPRITE_PALETTE[5] = RGB15(0,0,31);

    	SPRITE_PALETTE[6] = RGB15(0,0,0);

    	SPRITE_PALETTE[7] = RGB15(0,31,31);

    	SPRITE_PALETTE[8] = RGB15(31,0,31);

    	SPRITE_PALETTE[9] = RGB15(16,16,16);

    	SPRITE_PALETTE[10] = RGB15(25,25,25);

    	SPRITE_PALETTE[11] = RGB15(8,8,8);

    	SPRITE_PALETTE[12] = RGB15(31,19,0);

    	SPRITE_PALETTE[13] = RGB15(19,0,4);

    	SPRITE_PALETTE[14] = RGB15(25,0,0);

    	SPRITE_PALETTE[15] = RGB15(16,0,16);

    	SPRITE_PALETTE[16] = RGB15(25,19,31);

    	SPRITE_PALETTE[17] = RGB15(31,19,25);

    	SPRITE_PALETTE[18] = RGB15(23,21,21);

    	SPRITE_PALETTE[19] = RGB15(0,0,16);

    	SPRITE_PALETTE[20] = RGB15(0,16,16);

    	SPRITE_PALETTE[21] = RGB15(0,12,0);

    	SPRITE_PALETTE[22] = RGB15(16,16,0);

    	SPRITE_PALETTE[23] = RGB15(19,31,19);

    	SPRITE_PALETTE[24] = RGB15(31,31,19);

}



/* definición de un sprite de 16x16 píxeles para dibujar un rombo */

/* Por la forma que tienen de trabajar los bancos de memoria, la imagen del sprite se divide en bloques de 8x8 píxeles. Los primeros 64 (8x8) píxeles que indicamos

aparecerán en el cuadrante superior izquierdo de la imagen del sprite, los siguientes 64 en el cuadrante superior derecho, los siguientes en el cuadrante inferior izquierdo y los

últimos en el cuadrante inferior derecho. */


//Matriz del Jugador yendo a la derecha 1
u8 jugadord[256] = 
{
0	,	11	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	11	,	11	,	0	,	11	,	11	,	0	,
0	,	0	,	0	,	11	,	11	,	9	,	9	,	11	,	0	,	0	,	0	,	11	,	9	,	13	,	9	,	13	,
0	,	0	,	0	,	11	,	9	,	13	,	9	,	13	,	0	,	0	,	0	,	11	,	9	,	9	,	9	,	9	,
0	,	0	,	0	,	0	,	11	,	9	,	9	,	11	,	0	,	0	,	0	,	0	,	0	,	11	,	11	,	0	,
0	,	0	,	11	,	0	,	0	,	0	,	0	,	0	,	11	,	11	,	0	,	0	,	0	,	0	,	0	,	0	,
11	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	11	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,
11	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	11	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,
0	,	0	,	0	,	0	,	0	,	0	,	0	,	3	,	0	,	0	,	0	,	0	,	0	,	0	,	3	,	0	,
0	,	0	,	11	,	11	,	11	,	9	,	9	,	11	,	0	,	11	,	0	,	0	,	11	,	9	,	9	,	11	,
11	,	0	,	0	,	11	,	9	,	9	,	9	,	9	,	0	,	0	,	0	,	0	,	11	,	9	,	9	,	11	,
0	,	0	,	0	,	11	,	11	,	11	,	11	,	11	,	0	,	0	,	0	,	11	,	0	,	0	,	0	,	0	,
0	,	11	,	11	,	0	,	0	,	0	,	0	,	0	,	0	,	11	,	0	,	0	,	0	,	0	,	0	,	0	,
11	,	11	,	0	,	0	,	0	,	3	,	0	,	0	,	0	,	0	,	11	,	13	,	3	,	0	,	0	,	0	,
11	,	0	,	0	,	11	,	13	,	0	,	0	,	0	,	0	,	0	,	13	,	0	,	0	,	0	,	0	,	0	,
0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	11	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,
0	,	11	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	11	,	11	,	0	,	0	,	0	,	0	,
};


//Matriz del Jugador yendo a la derecha 2
u8 jugadorQd[256] = 
{
0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	11	,	0	,	0	,	0	,	0	,	0	,
0	,	0	,	0	,	11	,	11	,	0	,	11	,	11	,	0	,	0	,	0	,	0	,	11	,	11	,	9	,	9	,
0	,	0	,	0	,	0	,	11	,	9	,	13	,	9	,	0	,	0	,	0	,	0	,	11	,	9	,	13	,	9	,
0	,	0	,	0	,	0	,	11	,	9	,	9	,	9	,	0	,	0	,	0	,	0	,	0	,	11	,	9	,	9	,
0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	11	,	0	,	0	,	0	,	0	,
0	,	11	,	11	,	0	,	0	,	0	,	0	,	0	,	11	,	11	,	0	,	0	,	0	,	0	,	0	,	0	,
13	,	11	,	0	,	0	,	0	,	0	,	0	,	0	,	13	,	11	,	0	,	0	,	0	,	0	,	0	,	0	,
9	,	11	,	0	,	0	,	0	,	0	,	0	,	0	,	11	,	0	,	0	,	0	,	0	,	0	,	0	,	3	,
0	,	0	,	0	,	11	,	11	,	11	,	11	,	11	,	0	,	0	,	11	,	0	,	0	,	11	,	9	,	9	,
0	,	0	,	11	,	0	,	11	,	9	,	9	,	9	,	0	,	0	,	0	,	11	,	0	,	11	,	9	,	9	,
0	,	0	,	0	,	0	,	0	,	11	,	11	,	11	,	0	,	0	,	0	,	0	,	0	,	11	,	0	,	11	,
0	,	0	,	0	,	0	,	0	,	11	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	11	,	11	,	0	,
11	,	11	,	11	,	0	,	0	,	0	,	3	,	0	,	11	,	0	,	11	,	0	,	0	,	3	,	0	,	0	,
9	,	0	,	11	,	13	,	3	,	0	,	0	,	0	,	11	,	0	,	0	,	11	,	13	,	0	,	0	,	0	,
11	,	0	,	13	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,
11	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	11	,	11	,	0	,	0	,	0	,	0	,	0	,
};


//Matriz del Jugador yendo a la izquierda 1
u8 jugadori[256] = 
{
0	,	0	,	0	,	0	,	0	,	11	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	11	,	11	,
0	,	0	,	0	,	0	,	0	,	0	,	0	,	11	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	11	,
0	,	0	,	0	,	0	,	0	,	0	,	0	,	11	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	11	,
3	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	3	,	0	,	0	,	0	,	0	,	0	,	0	,
0	,	0	,	0	,	0	,	0	,	0	,	11	,	0	,	0	,	11	,	11	,	0	,	11	,	11	,	0	,	0	,
11	,	9	,	9	,	11	,	11	,	0	,	0	,	0	,	13	,	9	,	13	,	9	,	11	,	0	,	0	,	0	,
13	,	9	,	13	,	9	,	11	,	0	,	0	,	0	,	9	,	9	,	9	,	9	,	11	,	0	,	0	,	0	,
11	,	9	,	9	,	11	,	0	,	0	,	0	,	0	,	0	,	11	,	11	,	0	,	0	,	0	,	0	,	0	,
0	,	0	,	3	,	0	,	0	,	0	,	11	,	11	,	0	,	0	,	0	,	3	,	13	,	11	,	0	,	0	,
0	,	0	,	0	,	13	,	11	,	0	,	0	,	11	,	0	,	0	,	0	,	0	,	0	,	13	,	0	,	0	,
0	,	0	,	0	,	0	,	0	,	0	,	0	,	11	,	0	,	0	,	0	,	0	,	0	,	0	,	11	,	0	,
0	,	0	,	0	,	0	,	0	,	11	,	0	,	0	,	0	,	0	,	0	,	11	,	11	,	0	,	0	,	0	,
11	,	9	,	9	,	11	,	11	,	11	,	0	,	0	,	11	,	9	,	9	,	11	,	0	,	0	,	11	,	0	,
9	,	9	,	9	,	9	,	11	,	0	,	0	,	11	,	11	,	9	,	9	,	11	,	0	,	0	,	0	,	0	,
11	,	11	,	11	,	11	,	11	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	11	,	0	,	0	,	0	,
0	,	0	,	0	,	0	,	0	,	11	,	11	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	11	,	0	,
};


//Matriz del Jugador yendo a la izquierda 2
u8 jugadorQi[256] = 
{
0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	11	,	0	,	0	,	0	,
0	,	0	,	0	,	0	,	0	,	11	,	11	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	11	,	11	,
0	,	0	,	0	,	0	,	0	,	0	,	11	,	13	,	0	,	0	,	0	,	0	,	0	,	0	,	11	,	13	,
0	,	0	,	0	,	0	,	0	,	0	,	11	,	9	,	3	,	0	,	0	,	0	,	0	,	0	,	0	,	11	,
0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	11	,	0	,	0	,
11	,	11	,	0	,	11	,	11	,	0	,	0	,	0	,	9	,	9	,	11	,	11	,	0	,	0	,	0	,	0	,
9	,	13	,	9	,	11	,	0	,	0	,	0	,	0	,	9	,	13	,	9	,	11	,	0	,	0	,	0	,	0	,
9	,	9	,	9	,	11	,	0	,	0	,	0	,	0	,	9	,	9	,	11	,	0	,	0	,	0	,	0	,	0	,
0	,	3	,	0	,	0	,	0	,	11	,	11	,	11	,	0	,	0	,	3	,	0	,	0	,	11	,	0	,	11	,
0	,	0	,	0	,	3	,	13	,	11	,	0	,	9	,	0	,	0	,	0	,	13	,	11	,	0	,	0	,	11	,
0	,	0	,	0	,	0	,	0	,	13	,	0	,	11	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,
0	,	0	,	0	,	0	,	0	,	0	,	0	,	11	,	0	,	0	,	0	,	0	,	0	,	11	,	11	,	0	,
11	,	11	,	11	,	11	,	11	,	0	,	0	,	0	,	9	,	9	,	11	,	0	,	0	,	11	,	0	,	0	,
9	,	9	,	9	,	11	,	0	,	11	,	0	,	0	,	9	,	9	,	11	,	0	,	11	,	0	,	0	,	0	,
11	,	11	,	11	,	0	,	0	,	0	,	0	,	0	,	11	,	0	,	11	,	0	,	0	,	0	,	0	,	0	,
0	,	0	,	11	,	0	,	0	,	0	,	0	,	0	,	0	,	11	,	11	,	0	,	0	,	0	,	0	,	0	,
};


//Matriz del NPC Cura
u8 cura[256] = 
{
0	,	0	,	0	,	0	,	0	,	0	,	9	,	9	,	0	,	0	,	0	,	0	,	0	,	9	,	3	,	3	,
0	,	0	,	0	,	0	,	9	,	3	,	12	,	12	,	0	,	0	,	0	,	0	,	9	,	3	,	5	,	12	,
0	,	0	,	0	,	0	,	9	,	3	,	12	,	12	,	0	,	0	,	0	,	0	,	0	,	9	,	3	,	3	,
0	,	0	,	0	,	0	,	0	,	9	,	3	,	2	,	0	,	0	,	0	,	0	,	9	,	3	,	3	,	3	,
9	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	3	,	9	,	0	,	0	,	0	,	0	,	0	,	0	,
12	,	3	,	9	,	0	,	0	,	0	,	0	,	0	,	5	,	3	,	9	,	0	,	0	,	0	,	0	,	0	,
12	,	3	,	9	,	0	,	0	,	0	,	0	,	0	,	3	,	9	,	0	,	0	,	0	,	0	,	0	,	0	,
3	,	9	,	0	,	0	,	0	,	0	,	0	,	0	,	3	,	3	,	9	,	0	,	0	,	0	,	0	,	0	,
0	,	0	,	0	,	9	,	3	,	3	,	12	,	12	,	0	,	0	,	0	,	0	,	9	,	9	,	3	,	3	,
0	,	0	,	0	,	0	,	0	,	9	,	3	,	3	,	0	,	0	,	0	,	0	,	0	,	9	,	3	,	3	,
0	,	0	,	0	,	0	,	0	,	9	,	3	,	3	,	0	,	0	,	0	,	0	,	9	,	3	,	3	,	3	,
0	,	0	,	0	,	9	,	9	,	9	,	9	,	9	,	0	,	0	,	0	,	0	,	0	,	12	,	12	,	0	,
12	,	3	,	3	,	9	,	0	,	0	,	0	,	0	,	3	,	9	,	9	,	0	,	0	,	0	,	0	,	0	,
3	,	9	,	0	,	0	,	0	,	0	,	0	,	0	,	3	,	9	,	0	,	0	,	0	,	0	,	0	,	0	,
3	,	9	,	0	,	0	,	0	,	0	,	0	,	0	,	3	,	3	,	9	,	0	,	0	,	0	,	0	,	0	,
9	,	9	,	9	,	9	,	0	,	0	,	0	,	0	,	12	,	12	,	0	,	0	,	0	,	0	,	0	,	0	,
};

//Matriz del NPC Rey
u8 rey[256] = 
{
0	,	24	,	0	,	0	,	2	,	0	,	2	,	0	,	0	,	24	,	24	,	0	,	0	,	2	,	2	,	2	,
0	,	24	,	24	,	0	,	6	,	11	,	6	,	6	,	0	,	24	,	24	,	6	,	6	,	12	,	12	,	12	,
0	,	24	,	24	,	11	,	12	,	12	,	6	,	12	,	0	,	24	,	24	,	6	,	6	,	12	,	12	,	12	,
0	,	24	,	11	,	6	,	11	,	13	,	13	,	13	,	0	,	24	,	24	,	6	,	13	,	14	,	14	,	1	,
2	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,
11	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	12	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,
6	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	12	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,
11	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	1	,	1	,	0	,	0	,	0	,	0	,	0	,	0	,
0	,	24	,	24	,	2	,	13	,	14	,	14	,	1	,	0	,	24	,	24	,	2	,	13	,	14	,	14	,	1	,
0	,	24	,	24	,	2	,	13	,	12	,	12	,	13	,	0	,	24	,	24	,	2	,	14	,	14	,	14	,	14	,
0	,	24	,	24	,	2	,	2	,	14	,	14	,	14	,	0	,	24	,	24	,	2	,	2	,	2	,	2	,	2	,
0	,	24	,	24	,	24	,	24	,	24	,	24	,	24	,	0	,	24	,	24	,	24	,	24	,	24	,	24	,	24	,
1	,	1	,	1	,	0	,	0	,	0	,	0	,	0	,	1	,	1	,	1	,	0	,	0	,	0	,	0	,	0	,
13	,	13	,	13	,	0	,	0	,	0	,	0	,	0	,	14	,	14	,	14	,	0	,	0	,	0	,	0	,	0	,
14	,	14	,	14	,	14	,	0	,	0	,	0	,	0	,	2	,	2	,	14	,	14	,	0	,	0	,	0	,	0	,
24	,	2	,	6	,	6	,	0	,	0	,	0	,	0	,	24	,	2	,	6	,	6	,	6	,	0	,	0	,	0	,
};

//Matriz del NPC Árbol
u8 arbol[256] = 
{
0	,	0	,	0	,	0	,	21	,	21	,	21	,	14	,	0	,	0	,	0	,	21	,	21	,	14	,	21	,	21	,
0	,	0	,	0	,	0	,	21	,	21	,	14	,	21	,	0	,	0	,	0	,	0	,	0	,	0	,	14	,	14	,
0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	14	,	14	,	14	,	14	,
0	,	0	,	0	,	14	,	12	,	12	,	12	,	12	,	0	,	0	,	0	,	14	,	6	,	12	,	6	,	12	,
21	,	14	,	21	,	14	,	21	,	21	,	21	,	0	,	14	,	21	,	21	,	14	,	21	,	14	,	21	,	21	,
14	,	21	,	14	,	21	,	14	,	21	,	14	,	14	,	14	,	14	,	14	,	14	,	14	,	21	,	14	,	21	,
0	,	14	,	14	,	0	,	0	,	14	,	21	,	21	,	14	,	14	,	14	,	0	,	0	,	21	,	21	,	0	,
14	,	14	,	14	,	0	,	0	,	0	,	0	,	0	,	14	,	14	,	14	,	0	,	0	,	0	,	0	,	0	,
0	,	0	,	0	,	14	,	12	,	12	,	12	,	12	,	3	,	0	,	0	,	0	,	14	,	12	,	12	,	14	,
0	,	3	,	19	,	12	,	12	,	12	,	12	,	12	,	0	,	19	,	12	,	12	,	0	,	12	,	12	,	14	,
0	,	0	,	0	,	19	,	0	,	14	,	14	,	14	,	0	,	0	,	0	,	0	,	0	,	0	,	14	,	14	,
0	,	0	,	0	,	0	,	14	,	14	,	14	,	14	,	0	,	14	,	14	,	14	,	14	,	22	,	22	,	14	,
14	,	14	,	14	,	0	,	0	,	0	,	0	,	0	,	14	,	14	,	14	,	0	,	0	,	0	,	0	,	0	,
12	,	14	,	14	,	0	,	0	,	0	,	0	,	0	,	12	,	14	,	14	,	0	,	0	,	0	,	0	,	0	,
14	,	14	,	14	,	0	,	0	,	0	,	0	,	0	,	14	,	14	,	14	,	0	,	0	,	0	,	0	,	0	,
14	,	22	,	14	,	14	,	14	,	0	,	0	,	0	,	14	,	22	,	22	,	14	,	14	,	14	,	0	,	0	,
};

//Matriz del NPC Madre y su hijo
u8 madre[256] = 
{
0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,
0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,
0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,
0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,
0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,
0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,
0	,	0	,	9	,	9	,	9	,	9	,	9	,	0	,	0	,	9	,	11	,	11	,	11	,	11	,	9	,	0	,
0	,	9	,	12	,	12	,	11	,	12	,	9	,	0	,	0	,	9	,	6	,	12	,	6	,	12	,	9	,	0	,
0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,
0	,	0	,	0	,	0	,	0	,	0	,	14	,	22	,	0	,	0	,	0	,	14	,	14	,	14	,	14	,	1	,
0	,	0	,	0	,	14	,	14	,	14	,	14	,	12	,	0	,	0	,	0	,	14	,	14	,	0	,	0	,	1	,
0	,	0	,	0	,	14	,	14	,	0	,	0	,	0	,	0	,	0	,	6	,	6	,	6	,	0	,	1	,	1	,
0	,	0	,	9	,	9	,	9	,	9	,	9	,	0	,	0	,	0	,	9	,	9	,	9	,	0	,	0	,	0	,
1	,	22	,	22	,	9	,	9	,	24	,	6	,	24	,	1	,	1	,	22	,	22	,	22	,	24	,	24	,	24	,
12	,	22	,	22	,	12	,	12	,	24	,	6	,	24	,	0	,	22	,	9	,	9	,	9	,	24	,	24	,	24	,
9	,	22	,	9	,	9	,	9	,	9	,	9	,	0	,	9	,	24	,	24	,	9	,	9	,	9	,	9	,	0	,
};

//Matriz del NPC Araña
u8 arana[256] = 
{
0	,	6	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	6	,	0	,	0	,	0	,	0	,	0	,	0	,
0	,	6	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	11	,	0	,	0	,	0	,	0	,	0	,	0	,
0	,	6	,	0	,	0	,	0	,	0	,	6	,	6	,	11	,	0	,	6	,	6	,	6	,	6	,	6	,	6	,
0	,	6	,	0	,	0	,	6	,	11	,	6	,	6	,	0	,	0	,	6	,	6	,	6	,	11	,	6	,	11	,
0	,	0	,	0	,	0	,	0	,	0	,	6	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	6	,	0	,
0	,	0	,	0	,	0	,	0	,	0	,	6	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	11	,	0	,
6	,	6	,	0	,	0	,	0	,	0	,	6	,	0	,	6	,	6	,	6	,	6	,	6	,	6	,	0	,	11	,
6	,	6	,	11	,	6	,	0	,	0	,	6	,	0	,	11	,	6	,	11	,	6	,	6	,	6	,	0	,	0	,
0	,	0	,	0	,	0	,	6	,	11	,	6	,	6	,	0	,	0	,	6	,	6	,	6	,	11	,	6	,	11	,
0	,	6	,	0	,	0	,	6	,	11	,	6	,	6	,	6	,	0	,	0	,	6	,	6	,	6	,	6	,	6	,
11	,	0	,	6	,	0	,	0	,	0	,	13	,	6	,	0	,	6	,	0	,	0	,	0	,	0	,	6	,	13	,
0	,	6	,	0	,	0	,	0	,	0	,	13	,	6	,	0	,	11	,	0	,	0	,	0	,	6	,	0	,	0	,
6	,	6	,	11	,	6	,	0	,	0	,	0	,	0	,	11	,	6	,	11	,	6	,	6	,	6	,	0	,	0	,
6	,	6	,	11	,	6	,	0	,	0	,	6	,	0	,	6	,	6	,	6	,	6	,	6	,	0	,	0	,	6	,
6	,	13	,	0	,	0	,	0	,	6	,	0	,	11	,	13	,	6	,	0	,	0	,	0	,	0	,	6	,	0	,
6	,	13	,	0	,	0	,	0	,	0	,	6	,	0	,	0	,	0	,	6	,	0	,	0	,	0	,	11	,	0	,
};

//Matriz del NPC X
u8 X[256] = 
{
0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	18	,	0	,	0	,	19	,
0	,	0	,	0	,	18	,	0	,	0	,	15	,	15	,	0	,	0	,	18	,	0	,	0	,	15	,	19	,	16	,
0	,	18	,	0	,	0	,	15	,	18	,	18	,	8	,	0	,	0	,	0	,	15	,	18	,	18	,	8	,	16	,
0	,	0	,	15	,	19	,	18	,	8	,	16	,	19	,	0	,	19	,	15	,	16	,	8	,	16	,	19	,	8	,
0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	19	,	0	,	0	,	18	,	0	,	0	,	0	,	0	,
15	,	15	,	0	,	0	,	18	,	0	,	0	,	0	,	16	,	19	,	15	,	0	,	0	,	18	,	0	,	0	,
8	,	18	,	18	,	15	,	0	,	0	,	18	,	0	,	16	,	8	,	18	,	18	,	15	,	0	,	0	,	0	,
19	,	16	,	8	,	18	,	19	,	15	,	0	,	0	,	8	,	19	,	16	,	8	,	16	,	15	,	19	,	0	,
0	,	19	,	15	,	16	,	8	,	16	,	19	,	8	,	0	,	0	,	15	,	19	,	18	,	8	,	16	,	19	,
0	,	0	,	0	,	15	,	18	,	18	,	8	,	16	,	0	,	18	,	0	,	0	,	15	,	18	,	18	,	8	,
0	,	0	,	18	,	0	,	0	,	15	,	19	,	16	,	0	,	0	,	0	,	18	,	0	,	0	,	15	,	15	,
0	,	0	,	0	,	0	,	18	,	0	,	0	,	19	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,
8	,	19	,	16	,	8	,	16	,	15	,	19	,	0	,	19	,	16	,	8	,	18	,	19	,	15	,	0	,	0	,
16	,	8	,	18	,	18	,	15	,	0	,	0	,	0	,	8	,	18	,	18	,	15	,	0	,	0	,	18	,	0	,
16	,	19	,	15	,	0	,	0	,	18	,	0	,	0	,	15	,	15	,	0	,	0	,	18	,	0	,	0	,	0	,
19	,	0	,	0	,	18	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,
};

//Matriz del Agujero
u8 Agujero[256] = 
{
0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,
0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,
0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,
0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	6	,	6	,
0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,
0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,
0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,
0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	6	,	6	,	0	,	0	,	0	,	0	,	0	,	0	,
0	,	0	,	0	,	0	,	0	,	6	,	11	,	11	,	0	,	0	,	0	,	0	,	6	,	11	,	11	,	11	,
0	,	0	,	0	,	6	,	11	,	11	,	11	,	11	,	0	,	0	,	0	,	0	,	6	,	11	,	11	,	11	,
0	,	0	,	0	,	0	,	0	,	6	,	11	,	11	,	0	,	0	,	0	,	0	,	0	,	0	,	6	,	6	,
0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,
11	,	11	,	6	,	0	,	0	,	0	,	0	,	0	,	11	,	11	,	11	,	6	,	0	,	0	,	0	,	0	,
11	,	11	,	11	,	11	,	6	,	0	,	0	,	0	,	11	,	11	,	11	,	6	,	0	,	0	,	0	,	0	,
11	,	11	,	6	,	0	,	0	,	0	,	0	,	0	,	6	,	6	,	0	,	0	,	0	,	0	,	0	,	0	,
0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,
};


/* Carga en memoria cada uno de los sprites que hemos dibujado. */



void GuardarSpritesMemoria(){ 

	

int i;

	//sprite de 16*16

	for(i = 0; i < 16 * 16 / 2; i++) 

	{	

		gfxjugadord[i] = jugadord[i*2] | (jugadord[(i*2)+1]<<8);				

	}
	
	
	//sprite de 16*16
	for(i = 0; i < 16 * 16 / 2; i++) 

	{	

		gfxjugadorQd[i] = jugadorQd[i*2] | (jugadorQd[(i*2)+1]<<8);				

	}
	
	
	//sprite de 16*16
	for(i = 0; i < 16 * 16 / 2; i++) 

	{	

		gfxjugadori[i] = jugadori[i*2] | (jugadori[(i*2)+1]<<8);				

	}
	
	//sprite de 16*16

	for(i = 0; i < 16 * 16 / 2; i++) 

	{	

		gfxjugadorQi[i] = jugadorQi[i*2] | (jugadorQi[(i*2)+1]<<8);				

	}
	
	//sprite de 16*16

	for(i = 0; i < 16 * 16 / 2; i++) 

	{	

		gfxcura[i] = cura[i*2] | (cura[(i*2)+1]<<8);				

	}
	
	//sprite de 16*16

	for(i = 0; i < 16 * 16 / 2; i++) 

	{	

		gfxrey[i] = rey[i*2] | (rey[(i*2)+1]<<8);				

	}
	
	//sprite de 16*16

	for(i = 0; i < 16 * 16 / 2; i++) 

	{	

		gfxarbol[i] = arbol[i*2] | (arbol[(i*2)+1]<<8);				

	}
	
	//sprite de 16*16

	for(i = 0; i < 16 * 16 / 2; i++) 

	{	

		gfxmadre[i] = madre[i*2] | (madre[(i*2)+1]<<8);				

	}
	
	//sprite de 16*16
	
	for(i = 0; i < 16 * 16 / 2; i++) 

	{	

		gfxarana[i] = arana[i*2] | (arana[(i*2)+1]<<8);				

	}
	
	//sprite de 16*16

	for(i = 0; i < 16 * 16 / 2; i++) 

	{	

		gfxX[i] = X[i*2] | (X[(i*2)+1]<<8);				

	}
	
	//sprite de 16*16

	for(i = 0; i < 16 * 16 / 2; i++) 

	{	

		gfxAgujero[i] = Agujero[i*2] | (Agujero[(i*2)+1]<<8);				

	}

}





//Esta función dibuja el sprite del movimiento en la posición x-y de pantalla.
void MostrarJugadorD(int indice, int x, int y)

{ 

oamSet(&oamMain, //main graphics engine context

		indice,           //oam index (0 to 127)  

		x, y,   //x and y pixle location of the sprite

		0,                    //priority, lower renders last (on top)

		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	

		SpriteSize_16x16,     

		SpriteColorFormat_256Color, 

		gfxjugadord,//+16*16/2,                  //pointer to the loaded graphics

		-1,                  //sprite rotation data  

		false,               //double the size when rotating?

		false,			//hide the sprite?

		false, false, //vflip, hflip

		false	//apply mosaic

		); 

	  

oamUpdate(&oamMain);  

}



//Esta función borra el sprite del movimiento en la posición x-y de pantalla.
void BorrarJugadorD(int indice, int x, int y)

{

oamSet(&oamMain, //main graphics engine context

		indice,           //oam index (0 to 127)  

		x, y,   //x and y pixle location of the sprite

		0,                    //priority, lower renders last (on top)

		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	

		SpriteSize_16x16,     

		SpriteColorFormat_256Color, 

		gfxjugadord,//+16*16/2,                  //pointer to the loaded graphics

		-1,                  //sprite rotation data  

		false,               //double the size when rotating?

		true,			//hide the sprite?

		false, false, //vflip, hflip

		false	//apply mosaic

		); 

oamUpdate(&oamMain); 



}


//Esta función dibuja el sprite del movimiento en la posición x-y de pantalla.
void MostrarJugadorQd(int indice, int x, int y)

{ 

 

oamSet(&oamMain, //main graphics engine context

		indice,           //oam index (0 to 127)  

		x, y,   //x and y pixle location of the sprite

		0,                    //priority, lower renders last (on top)

		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	

		SpriteSize_16x16,     

		SpriteColorFormat_256Color, 

		gfxjugadorQd,//+16*16/2,                  //pointer to the loaded graphics

		-1,                  //sprite rotation data  

		false,               //double the size when rotating?

		false,			//hide the sprite?

		false, false, //vflip, hflip

		false	//apply mosaic

		); 

	  

oamUpdate(&oamMain);  

}




//Esta función borra el sprite del movimiento en la posición x-y de pantalla.
void BorrarJugadorQd(int indice, int x, int y)

{



oamSet(&oamMain, //main graphics engine context

		indice,           //oam index (0 to 127)  

		x, y,   //x and y pixle location of the sprite

		0,                    //priority, lower renders last (on top)

		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	

		SpriteSize_16x16,     

		SpriteColorFormat_256Color, 

		gfxjugadorQd,//+16*16/2,                  //pointer to the loaded graphics

		-1,                  //sprite rotation data  

		false,               //double the size when rotating?

		true,			//hide the sprite?

		false, false, //vflip, hflip

		false	//apply mosaic

		); 

oamUpdate(&oamMain); 



}

//Esta función dibuja el sprite del movimiento en la posición x-y de pantalla.
void MostrarJugadorI(int indice, int x, int y)

{ 

 

oamSet(&oamMain, //main graphics engine context

		indice,           //oam index (0 to 127)  

		x, y,   //x and y pixle location of the sprite

		0,                    //priority, lower renders last (on top)

		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	

		SpriteSize_16x16,     

		SpriteColorFormat_256Color, 

		gfxjugadori,//+16*16/2,                  //pointer to the loaded graphics

		-1,                  //sprite rotation data  

		false,               //double the size when rotating?

		false,			//hide the sprite?

		false, false, //vflip, hflip

		false	//apply mosaic

		); 

	  

oamUpdate(&oamMain);  

}




//Esta función borra el sprite del movimiento en la posición x-y de pantalla.
void BorrarJugadorI(int indice, int x, int y)

{



oamSet(&oamMain, //main graphics engine context

		indice,           //oam index (0 to 127)  

		x, y,   //x and y pixle location of the sprite

		0,                    //priority, lower renders last (on top)

		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	

		SpriteSize_16x16,     

		SpriteColorFormat_256Color, 

		gfxjugadori,//+16*16/2,                  //pointer to the loaded graphics

		-1,                  //sprite rotation data  

		false,               //double the size when rotating?

		true,			//hide the sprite?

		false, false, //vflip, hflip

		false	//apply mosaic

		); 

oamUpdate(&oamMain); 



}


//Esta función dibuja el sprite del movimiento en la posición x-y de pantalla.
void MostrarJugadorQi(int indice, int x, int y)

{ 

 

oamSet(&oamMain, //main graphics engine context

		indice,           //oam index (0 to 127)  

		x, y,   //x and y pixle location of the sprite

		0,                    //priority, lower renders last (on top)

		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	

		SpriteSize_16x16,     

		SpriteColorFormat_256Color, 

		gfxjugadorQi,//+16*16/2,                  //pointer to the loaded graphics

		-1,                  //sprite rotation data  

		false,               //double the size when rotating?

		false,			//hide the sprite?

		false, false, //vflip, hflip

		false	//apply mosaic

		); 

	  

oamUpdate(&oamMain);  

}




//Esta función borra el sprite del movimiento en la posición x-y de pantalla.
void BorrarJugadorQi(int indice, int x, int y)

{



oamSet(&oamMain, //main graphics engine context

		indice,           //oam index (0 to 127)  

		x, y,   //x and y pixle location of the sprite

		0,                    //priority, lower renders last (on top)

		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	

		SpriteSize_16x16,     

		SpriteColorFormat_256Color, 

		gfxjugadorQi,//+16*16/2,                  //pointer to the loaded graphics

		-1,                  //sprite rotation data  

		false,               //double the size when rotating?

		true,			//hide the sprite?

		false, false, //vflip, hflip

		false	//apply mosaic

		); 

oamUpdate(&oamMain);
}


//Esta función dibuja el cura en la posición x-y de pantalla.
void MostrarCura(int indice, int x, int y)

{ 

oamSet(&oamMain, //main graphics engine context

		indice,           //oam index (0 to 127)  

		x, y,   //x and y pixle location of the sprite

		0,                    //priority, lower renders last (on top)

		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	

		SpriteSize_16x16,     

		SpriteColorFormat_256Color, 

		gfxcura,//+16*16/2,                  //pointer to the loaded graphics

		-1,                  //sprite rotation data  

		false,               //double the size when rotating?

		false,			//hide the sprite?

		false, false, //vflip, hflip

		false	//apply mosaic

		); 

	  

oamUpdate(&oamMain);  

}




//Esta función borra el sprite del cura en la posición x-y de pantalla.
void BorrarCura(int indice, int x, int y)

{

oamSet(&oamMain, //main graphics engine context

		indice,           //oam index (0 to 127)  

		x, y,   //x and y pixle location of the sprite

		0,                    //priority, lower renders last (on top)

		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	

		SpriteSize_16x16,     

		SpriteColorFormat_256Color, 

		gfxcura,//+16*16/2,                  //pointer to the loaded graphics

		-1,                  //sprite rotation data  

		false,               //double the size when rotating?

		true,			//hide the sprite?

		false, false, //vflip, hflip

		false	//apply mosaic

		); 

oamUpdate(&oamMain); 



}


//Esta función dibuja el rey en la posición x-y de pantalla.
void MostrarRey(int indice, int x, int y)

{ 

oamSet(&oamMain, //main graphics engine context

		indice,           //oam index (0 to 127)  

		x, y,   //x and y pixle location of the sprite

		0,                    //priority, lower renders last (on top)

		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	

		SpriteSize_16x16,     

		SpriteColorFormat_256Color, 

		gfxrey,//+16*16/2,                  //pointer to the loaded graphics

		-1,                  //sprite rotation data  

		false,               //double the size when rotating?

		false,			//hide the sprite?

		false, false, //vflip, hflip

		false	//apply mosaic

		); 

	  

oamUpdate(&oamMain);  

}




//Esta función borra el sprite del rey en la posición x-y de pantalla.
void BorrarRey(int indice, int x, int y)

{

oamSet(&oamMain, //main graphics engine context

		indice,           //oam index (0 to 127)  

		x, y,   //x and y pixle location of the sprite

		0,                    //priority, lower renders last (on top)

		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	

		SpriteSize_16x16,     

		SpriteColorFormat_256Color, 

		gfxrey,//+16*16/2,                  //pointer to the loaded graphics

		-1,                  //sprite rotation data  

		false,               //double the size when rotating?

		true,			//hide the sprite?

		false, false, //vflip, hflip

		false	//apply mosaic

		); 

oamUpdate(&oamMain); 



}


//Esta función dibuja el árbol en la posición x-y de pantalla.
void MostrarArbol(int indice, int x, int y)

{ 

oamSet(&oamMain, //main graphics engine context

		indice,           //oam index (0 to 127)  

		x, y,   //x and y pixle location of the sprite

		0,                    //priority, lower renders last (on top)

		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	

		SpriteSize_16x16,     

		SpriteColorFormat_256Color, 

		gfxarbol,//+16*16/2,                  //pointer to the loaded graphics

		-1,                  //sprite rotation data  

		false,               //double the size when rotating?

		false,			//hide the sprite?

		false, false, //vflip, hflip

		false	//apply mosaic

		); 

	  

oamUpdate(&oamMain);  

}




//Esta función borra el sprite del árbol en la posición x-y de pantalla.
void BorrarArbol(int indice, int x, int y)

{

oamSet(&oamMain, //main graphics engine context

		indice,           //oam index (0 to 127)  

		x, y,   //x and y pixle location of the sprite

		0,                    //priority, lower renders last (on top)

		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	

		SpriteSize_16x16,     

		SpriteColorFormat_256Color, 

		gfxarbol,//+16*16/2,                  //pointer to the loaded graphics

		-1,                  //sprite rotation data  

		false,               //double the size when rotating?

		true,			//hide the sprite?

		false, false, //vflip, hflip

		false	//apply mosaic

		); 

oamUpdate(&oamMain); 



}


//Esta función dibuja la madre y su hijo en la posición x-y de pantalla.
void MostrarMadre(int indice, int x, int y)

{ 

oamSet(&oamMain, //main graphics engine context

		indice,           //oam index (0 to 127)  

		x, y,   //x and y pixle location of the sprite

		0,                    //priority, lower renders last (on top)

		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	

		SpriteSize_16x16,     

		SpriteColorFormat_256Color, 

		gfxmadre,//+16*16/2,                  //pointer to the loaded graphics

		-1,                  //sprite rotation data  

		false,               //double the size when rotating?

		false,			//hide the sprite?

		false, false, //vflip, hflip

		false	//apply mosaic

		); 

	  

oamUpdate(&oamMain);  

}



//Esta función borra el sprite de la amdre y su hijo en la posición x-y de pantalla.

void BorrarMadre(int indice, int x, int y)

{

oamSet(&oamMain, //main graphics engine context

		indice,           //oam index (0 to 127)  

		x, y,   //x and y pixle location of the sprite

		0,                    //priority, lower renders last (on top)

		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	

		SpriteSize_16x16,     

		SpriteColorFormat_256Color, 

		gfxmadre,//+16*16/2,                  //pointer to the loaded graphics

		-1,                  //sprite rotation data  

		false,               //double the size when rotating?

		true,			//hide the sprite?

		false, false, //vflip, hflip

		false	//apply mosaic

		); 

oamUpdate(&oamMain); 



}


//Esta función dibuja la araña en la posición x-y de pantalla.
void MostrarArana(int indice, int x, int y)

{ 

oamSet(&oamMain, //main graphics engine context

		indice,           //oam index (0 to 127)  

		x, y,   //x and y pixle location of the sprite

		0,                    //priority, lower renders last (on top)

		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	

		SpriteSize_16x16,     

		SpriteColorFormat_256Color, 

		gfxarana,//+16*16/2,                  //pointer to the loaded graphics

		-1,                  //sprite rotation data  

		false,               //double the size when rotating?

		false,			//hide the sprite?

		false, false, //vflip, hflip

		false	//apply mosaic

		); 

	  

oamUpdate(&oamMain);  

}




//Esta función borra el sprite de la araña en la posición x-y de pantalla.
void BorrarArana(int indice, int x, int y)

{

oamSet(&oamMain, //main graphics engine context

		indice,           //oam index (0 to 127)  

		x, y,   //x and y pixle location of the sprite

		0,                    //priority, lower renders last (on top)

		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	

		SpriteSize_16x16,     

		SpriteColorFormat_256Color, 

		gfxarana,//+16*16/2,                  //pointer to the loaded graphics

		-1,                  //sprite rotation data  

		false,               //double the size when rotating?

		true,			//hide the sprite?

		false, false, //vflip, hflip

		false	//apply mosaic

		); 

oamUpdate(&oamMain); 



}


//Esta función dibuja X en la posición x-y de pantalla.
void MostrarX(int indice, int x, int y)

{ 

oamSet(&oamMain, //main graphics engine context

		indice,           //oam index (0 to 127)  

		x, y,   //x and y pixle location of the sprite

		0,                    //priority, lower renders last (on top)

		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	

		SpriteSize_16x16,     

		SpriteColorFormat_256Color, 

		gfxX,//+16*16/2,                  //pointer to the loaded graphics

		-1,                  //sprite rotation data  

		false,               //double the size when rotating?

		false,			//hide the sprite?

		false, false, //vflip, hflip

		false	//apply mosaic

		); 

	  

oamUpdate(&oamMain);  

}



//Esta función borra el sprite del X en la posición x-y de pantalla.

void BorrarX(int indice, int x, int y)

{

oamSet(&oamMain, //main graphics engine context

		indice,           //oam index (0 to 127)  

		x, y,   //x and y pixle location of the sprite

		0,                    //priority, lower renders last (on top)

		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	

		SpriteSize_16x16,     

		SpriteColorFormat_256Color, 

		gfxX,//+16*16/2,                  //pointer to the loaded graphics

		-1,                  //sprite rotation data  

		false,               //double the size when rotating?

		true,			//hide the sprite?

		false, false, //vflip, hflip

		false	//apply mosaic

		); 

oamUpdate(&oamMain); 



}


//Esta función dibuja el agujero en la posición x-y de pantalla.
void MostrarAgujero(int indice, int x, int y)

{ 

oamSet(&oamMain, //main graphics engine context

		indice,           //oam index (0 to 127)  

		x, y,   //x and y pixle location of the sprite

		0,                    //priority, lower renders last (on top)

		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	

		SpriteSize_16x16,     

		SpriteColorFormat_256Color, 

		gfxAgujero,//+16*16/2,                  //pointer to the loaded graphics

		-1,                  //sprite rotation data  

		false,               //double the size when rotating?

		false,			//hide the sprite?

		false, false, //vflip, hflip

		false	//apply mosaic

		); 

	  

oamUpdate(&oamMain);  

}



//Esta función borra el sprite del agujero en la posición x-y de pantalla.

void BorrarAgujero(int indice, int x, int y)

{

oamSet(&oamMain, //main graphics engine context

		indice,           //oam index (0 to 127)  

		x, y,   //x and y pixle location of the sprite

		0,                    //priority, lower renders last (on top)

		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	

		SpriteSize_16x16,     

		SpriteColorFormat_256Color, 

		gfxAgujero,//+16*16/2,                  //pointer to the loaded graphics

		-1,                  //sprite rotation data  

		false,               //double the size when rotating?

		true,			//hide the sprite?

		false, false, //vflip, hflip

		false	//apply mosaic

		); 

oamUpdate(&oamMain); 



}
