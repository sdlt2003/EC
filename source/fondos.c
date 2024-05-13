
#include <nds.h> //Incluimos la librería nds.h para poder usar sus funciones		
#include <stdio.h> //Incluimos la librería stdio.h para poder usar sus funciones	
#include <stdlib.h>	//Incluimos la librería stdlib.h para poder usar sus funciones	
#include <unistd.h>	//Incluimos la librería unistd.h para poder usar sus funciones	

/* Si queremos visualizar distintos fondos, aquí se debe incluir el fichero de cabecera (fichero .h) de cada fondo. Estos ficheros de cabecera se generan automáticamente durante la compilación. */

#include "fondos.h" //Incluimos el fondo.h para los fondos
#include "graficos.h" //Incluimos el graficos.h para los gráficos
#include "ciudad1.h" //Incluimos ciudad1.h para poder cargar el fondo ciudad1
#include "Ciudad2.h" //Incluimos Ciudad2.h para poder cargar el fondo ciudad2
#include "Cueva1Aranas.h" //Incluimos CuevaArañas.h para poder cargar el fondo cueva con arañas
#include "Cueva2NoAranas.h" //Incluimos Cueva2NoAranas.h para poder cargar el fondo cueva sin arañas
#include "IglesiaPriv.h" //Incluimos IglesiaPriv.h para poder cargar el fondo de la iglesia
#include "SalaFinal.h" //Incluimos SalaFinal.h para poder cargar el fondo de la sala final
#include "SalonTrono.h" //Incluimos SalonTrono.h para poder cargar el fondo salón del Rey
#include "assaas.h" //Incluimos assaas.h para poder cargar uno de los fondos finales del juego
#include "osads.h" //Incluimos osads.h para poder cargar uno de los fondos finales del juego
#include "pixilframe0.h" //Incluimos pixilframe0.h para poder cargar uno de los fondos finales del juego
#include "SSSS.h" //Incluimos SSSS.h para poder cargar uno de los fondos finales del juego
#include "Castillo.h" //Incluimos Castillo.h para poder cargar uno de los fondos iniciales del juego
#include "IKK.h" //Incluimos IKK.h para poder cargar uno de los fondos iniciales del juego
#include "NombramientoMision.h" //Incluimos NombramientoMision.h para poder cargar uno de los fondos iniciales del juego
#include "PresentaDioses.h" //Incluimos PresentaDioses.h para poder cargar uno de los fondos iniciales del juego
#include "NegroNDS.h" //Incluimos NegroNDS.h para "resetear" los fondos

/* Se elige el canal de DMA que se utilizará para copiar las imágenes en memoria.*/
static const int DMA_CHANNEL = 3;

/* Para cada fondo que se quiera visualizar hay que escribir un procedimiento como el siguiente */
/*
   Visualizar el fondo de Ciudad1
*/
void visualizarCiudad1() {
		
    dmaCopyHalfWords(DMA_CHANNEL,
                     ciudad1Bitmap, /* Variable que se genera automaticamente */
                     (uint16 *)BG_BMP_RAM(0), /* Dirección del fondo principal */
                     ciudad1BitmapLen); /* Longitud en bytes, variable que se genera automáticamente */
}

/*
   Visualizar el fondo de Ciudad2
*/
void visualizarCiudad2() {
		
    dmaCopyHalfWords(DMA_CHANNEL,
                     Ciudad2Bitmap, /* Variable que se genera automaticamente */
                     (uint16 *)BG_BMP_RAM(0), /* Dirección del fondo principal */
                     Ciudad2BitmapLen); /* Longitud en bytes, variable que se genera automáticamente */
}

/*
   Visualizar el fondo cueva con arañas
*/
void visualizarCueva1Aranas() {
		
    dmaCopyHalfWords(DMA_CHANNEL,
                     Cueva1AranasBitmap, /* Variable que se genera automaticamente */
                     (uint16 *)BG_BMP_RAM(0), /* Dirección del fondo principal */
                     Cueva1AranasBitmapLen); /* Longitud en bytes, variable que se genera automáticamente */
}

/*
   Visualizar el fondo cueva sin arañas
*/
void visualizarCueva2NoAranas() {
		
    dmaCopyHalfWords(DMA_CHANNEL,
                     Cueva2NoAranasBitmap, /* Variable que se genera automaticamente */
                     (uint16 *)BG_BMP_RAM(0), /* Dirección del fondo principal */
                     Cueva2NoAranasBitmapLen); /* Longitud en bytes, variable que se genera automáticamente */
}

/*
   Visualizar el fondo iglesia
*/
void visualizarIglesiaPriv() {
		
    dmaCopyHalfWords(DMA_CHANNEL,
                     IglesiaPrivBitmap, /* Variable que se genera automaticamente */
                     (uint16 *)BG_BMP_RAM(0), /* Dirección del fondo principal */
                     IglesiaPrivBitmapLen); /* Longitud en bytes, variable que se genera automáticamente */
}

/*
   Visualizar el fondo sala final
*/
void visualizarSalaFinal() {
		
    dmaCopyHalfWords(DMA_CHANNEL,
                     SalaFinalBitmap, /* Variable que se genera automaticamente */
                     (uint16 *)BG_BMP_RAM(0), /* Dirección del fondo principal */
                     SalaFinalBitmapLen); /* Longitud en bytes, variable que se genera automáticamente */
}

/*
   Visualizar el fondo salon del rey
*/
void visualizarSalonTrono() {
		
    dmaCopyHalfWords(DMA_CHANNEL,
                     SalonTronoBitmap, /* Variable que se genera automaticamente */
                     (uint16 *)BG_BMP_RAM(0), /* Dirección del fondo principal */
                     SalonTronoBitmapLen); /* Longitud en bytes, variable que se genera automáticamente */
}

/*
   Visualizar el fondo final opción 1
*/
void visualizarFondoFInal1() {
		
    dmaCopyHalfWords(DMA_CHANNEL,
                     pixilframe0Bitmap, /* Variable que se genera automaticamente */
                     (uint16 *)BG_BMP_RAM(0), /* Dirección del fondo principal */
                     pixilframe0BitmapLen); /* Longitud en bytes, variable que se genera automáticamente */
}

/*
   Visualizar el fondo final opción 2
*/
void visualizarFondoFInal2() {
		
    dmaCopyHalfWords(DMA_CHANNEL,
                     SSSSBitmap, /* Variable que se genera automaticamente */
                     (uint16 *)BG_BMP_RAM(0), /* Dirección del fondo principal */
                     SSSSBitmapLen); /* Longitud en bytes, variable que se genera automáticamente */
}

/*
   Visualizar el fondo final opción 3
*/
void visualizarFondoFInal3() {
		
    dmaCopyHalfWords(DMA_CHANNEL,
                     osadsBitmap, /* Variable que se genera automaticamente */
                     (uint16 *)BG_BMP_RAM(0), /* Dirección del fondo principal */
                     osadsBitmapLen); /* Longitud en bytes, variable que se genera automáticamente */
}

/*
   Visualizar el fondo final opción 4
*/
void visualizarFondoFInal4() {
		
    dmaCopyHalfWords(DMA_CHANNEL,
                     assaasBitmap, /* Variable que se genera automaticamente */
                     (uint16 *)BG_BMP_RAM(0), /* Dirección del fondo principal */
                     assaasBitmapLen); /* Longitud en bytes, variable que se genera automáticamente */
}

/*
   Visualizar el primero fondo inicio
*/
void visualizarFondoInicio1() {
		
    dmaCopyHalfWords(DMA_CHANNEL,
                     CastilloBitmap, /* Variable que se genera automaticamente */
                     (uint16 *)BG_BMP_RAM(0), /* Dirección del fondo principal */
                     CastilloBitmapLen); /* Longitud en bytes, variable que se genera automáticamente */
}

/*
   Visualizar el segndo fondo inicio
*/
void visualizarFondoInicio2() {
		
    dmaCopyHalfWords(DMA_CHANNEL,
                     PresentaDiosesBitmap, /* Variable que se genera automaticamente */
                     (uint16 *)BG_BMP_RAM(0), /* Dirección del fondo principal */
                     PresentaDiosesBitmapLen); /* Longitud en bytes, variable que se genera automáticamente */
}

/*
   Visualizar el tercer fondo inicio
*/
void visualizarFondoInicio3() {
		
    dmaCopyHalfWords(DMA_CHANNEL,
                     IKKBitmap, /* Variable que se genera automaticamente */
                     (uint16 *)BG_BMP_RAM(0), /* Dirección del fondo principal */
                     IKKBitmapLen); /* Longitud en bytes, variable que se genera automáticamente */
}

/*
   Visualizar el cuarto fondo inicio
*/
void visualizarFondoInicio4() {
		
    dmaCopyHalfWords(DMA_CHANNEL,
                     NombramientoMisionBitmap, /* Variable que se genera automaticamente */
                     (uint16 *)BG_BMP_RAM(0), /* Dirección del fondo principal */
                     NombramientoMisionBitmapLen); /* Longitud en bytes, variable que se genera automáticamente */
}

/*
   Visualizar el fondo negro para poder "resetear" los fondos
*/
void visualizarFondoNegroNDS() {
		
    dmaCopyHalfWords(DMA_CHANNEL,
                     NegroNDSBitmap, /* Variable que se genera automaticamente */
                     (uint16 *)BG_BMP_RAM(0), /* Dirección del fondo principal */
                     NegroNDSBitmapLen); /* Longitud en bytes, variable que se genera automáticamente */
}
