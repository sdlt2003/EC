/*-------------------------------------
perifericos.h
-------------------------------------*/

extern int TeclaDetectada(); //Si se ha detectado una tecla o no
extern int TeclaPulsada(); //Si se ha pulsado una tecla o no
extern void ConfigurarTeclado(int Conf_Tec); //Configurar el teclado
extern void ConfigurarTemporizador(int Latch, int Conf_Tempo); //Configurar el temporizador
extern void HabilitarIntTeclado(); //Habilitar el teclado de interrupciones
extern void InhibirIntTeclado(); //Inhibir el teclado de interrupciones
extern void HabilitarIntTempo(); //Habilitar interrupción del temporizador
extern void InhibirIntTempo(); //Inhibir interrupción del temporizador
extern void PonerEnMarchaTempo(); //Poner en larcha el tiempo
extern void PararTempo(); //Parar el tiempo

