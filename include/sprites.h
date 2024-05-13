extern u16* gfx;

extern u16* gfx2;

extern u16* gfx3;

extern u16* gfxSub;



extern void memoriaReserba();



/* Para cada uno de los 256 valores que puede tomar un Pixel le da un color en la pantalla principal. El valor 0 es transparente y los valores sin definir negros */

extern void EstablecerPaletaPrindipal();





/* Para cada uno de los 256 valores que puede tomar un Pixel le da un color en la pantalla secundaria. El valor 0 es transparente y los valores sin definir negros */

extern void EstablecerPaletaSecundaria();





/* Carga en memoria los Sprites dibujados.*/

extern void GuardarSpritesMemoria();





/* Esta función dibuja uno de los movimientos del jugador en la posición de pantalla x-y. */

extern void MostrarJugadorD(int indice, int x, int y);





/*Esta función borra uno de los movimientos del jugador */

extern void BorrarJugadorD(int indice, int x, int y);




/* Esta función dibuja uno de los movimientos del jugador en la posición de pantalla x-y. */
extern void MostrarJugadorQd(int indice, int x, int y);

/*Esta función borra uno de los movimientos del jugador */
extern void BorrarJugadorQd(int indice, int x, int y);

/* Esta función dibuja uno de los movimientos del jugador en la posición de pantalla x-y. */
extern void MostrarJugadorI(int indice, int x, int y);

/*Esta función borra uno de los movimientos del jugador */
extern void BorrarJugadorI(int indice, int x, int y);

/* Esta función dibuja uno de los movimientos del jugador en la posición de pantalla x-y. */
extern void MostrarJugadorQi(int indice, int x, int y);

/*Esta función borra uno de los movimientos del jugador */
extern void BorrarJugadorQi(int indice, int x, int y);

/* Esta función dibuja un cura en la posición de pantalla x-y. */
extern void MostrarCura(int indice, int x, int y);

/*Esta función borra un cura */
extern void BorrarCura(int indice, int x, int y);

/* Esta función dibuja un rey en la posición de pantalla x-y. */
extern void MostrarRey(int indice, int x, int y);

/*Esta función borra un rey */
extern void BorrarRey(int indice, int x, int y);

/* Esta función dibuja un árbol en la posición de pantalla x-y. */
extern void MostrarArbol(int indice, int x, int y);

/*Esta función borra un árbol */
extern void BorrarArbol(int indice, int x, int y);

/* Esta función dibuja una madre y su hijo en la posición de pantalla x-y. */
extern void MostrarMadre(int indice, int x, int y);

/*Esta función borra una madre con su hijo */
extern void BorrarMadre(int indice, int x, int y);

/* Esta función dibuja una araña en la posición de pantalla x-y. */
extern void MostrarArana(int indice, int x, int y);

/*Esta función borra una araña */
extern void BorrarArana(int indice, int x, int y);

/* Esta función dibuja un X en la posición de pantalla x-y. */
extern void MostrarX(int indice, int x, int y);

/*Esta función borra un X */
extern void BorrarX(int indice, int x, int y);

/* Esta función dibuja unagujero en la posición de pantalla x-y. */
extern void MostrarAgujero(int indice, int x, int y);

/*Esta función borra un agujero */
extern void BorrarAgujero(int indice, int x, int y);


