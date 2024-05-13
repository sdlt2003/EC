/*-------------------------------------

rutinasAtencion.c

-------------------------------------*/



/*

   Importamos los archivos de la NintendoDS y los archivos que hemos creado para poder usar variables, etc.

*/



#include <nds.h> //Incluimos la librería nds.h para poder usar sus funciones		

#include <stdio.h> //Incluimos la librería stdio.h para poder usar sus funciones

#include "definiciones.h" //Incluimos la librería definiciones.h para poder usar las variables globales y sus funciones

#include "perifericos.h" //Incluimos la librería perifericos.h para poder usar las teclas... y sus funciones

#include "fondos.h" //Incluimos la librería fondos.h para poder usar los fondos y sus funciones

#include "funciones.h" //Incluimos la librería funciones.h para poder usar sus funciones

#include "sprites.h" //Incluimos la librería sprites.h para poder usar los sprites y sus funciones



/*

     Varibale para definir el estado en el que se encuentra la máquina

*/

int ESTADO;



/*

     Variable booleana que se usará en este archivo para decidir un final u otro. Esta varibale se usará en las escenas que el jugador deva de escoger. Si pulsa la R su valor será

TRUE; en cambio, si pulsa la tecla L, será FLASE

*/

bool conv = false;



/*

     Variable para saber si ha elegido el cura o la araña

*/

int ex=0;



/*

     La variable X donde el personaje se mueve. Es variable global

*/

int x;



/*

     Variable que cuenta la elección que ha hecho el jugador para luego saber por cual final ir. Es decir, en una escena, la que tiene que elegir si coger opció R u opción L. Si es R,

	 esta variable se multiplicará por dos (si es 0, se sumará dos), y si es L, sumará 1.

*/

contF=0;



/*

     Para la rutina del teclado por interrupción hemos decidido en usar la tecla A para interactuar con los NPCs. Una vez pulsada esa tecla, el juego cambiará de estado.

*/

void RutAtencionTeclado ()

{

   /*

     Con el primer NPC que va hablar será el Rey. Esto se ejecutará si el contador de la cámara (ContMovCam)

		es 1. El método de IteracionNPC  está diseñado para poder conversar con el NPC a una distancia equilibrada

   */

   if (IteracionNPC(200) && ContMovCam==1) 

   {

	if(TeclaPulsada()==A) 

	{

		eleccion = 0; //Se pone a 0 para que no haya opción de elegir

		ESTADO=JuegoConv;	

	}

   }



   /*

     Con el segundo NPC que va hablar será el Árbol. Esto se ejecutará si el contador de la cámara (ContMovCam)

	 es 4. El método de IteracionNPC  está diseñado para poder conversar con el NPC a una distancia equilibrada

   */

   else if (IteracionNPC(175) && ContMovCam==4)

   {

	if(TeclaPulsada()==A) 

	{

		eleccion = 0; //Se pone a 0 para que no haya opción de elegir

		ESTADO=JuegoConv;	

	}

   }



   /*

     Con el tercer NPC que va hablar será la Madre y su hijo medio muerto. Esto se ejecutará si el contador de la cámara (ContMovCam)

	 es 6. El método de IteracionNPC  está diseñado para poder conversar con el NPC a una distancia equilibrada

   */

   else if (IteracionNPC(100) && ContMovCam==6)

   {

	if(TeclaPulsada()==A) 

	{

		eleccion = 1; //Se pone a uno para que haya opción de elegir entre dos opciones que te muestra en el método de la conversación

		ESTADO=JuegoConv;	

	}

   }



   /*

     Con el cuarto NPC que va hablar será con la Araña o con el Cura. Esto dependerá a la hora de elegir si ir arriba (a la iglesia con el cura)

	 o si ir abajo (a la cueva con la araña). Esto se ejecutará si el contador de la cámara (ContMovCam)

	 es 8, cualquira de las opciones que haya escigido el jugador. El método de IteracionNPC  está diseñado para poder conversar con el NPC a una distancia equilibrada

   */

   else if (ContMovCam==8 && IteracionNPC(175))

   {

      if(TeclaPulsada()==A)

      {

	   eleccion = 0; //Se pone a 0 para que no haya opción de elegir

	   ESTADO=JuegoConv;	

      }

   }



   /*

     Con el quinto y último NPC que va hablar será el X. Esto se ejecutará si el contador de la cámara (ContMovCam)

	 es 10. El método de IteracionNPC  está diseñado para poder conversar con el NPC a una distancia equilibrada

   */

   else if (ContMovCam==10 && IteracionNPC(150))

   {

      if(TeclaPulsada()==A)

      {

	   eleccion = 0; //Se pone a 0 para que no haya opción de elegir

	   ESTADO=JuegoConv;	

      }

   }

}





	/*

	   Esta sería la rutina de atención de interrupción del Timer0. En ella, se contrololará el tiempo para mostrar las conversaciones,

	   el texto del inico, los controles... Cada texto durará 20 segundos excepto la presentación del juego.

	*/

void RutAtencionTempo()

{

	/*

	   La variable Tick se irá sumando 5 ticks por segundo con una frecuencia de 256 MHz

	*/

	static int tick=0;

	

	/*

	   La variable seg se irá sumando cada vez que Tick llegue a 5. Esta variable es la que se encarga del tiempo; es decir, es la que 

	   marca el tiempo que se muestran los textos

	*/

	static int seg=0;

	



	/*

	   En el estado Inicio se mostrarán los controles, la presentación, y los 4 textos que son el inicio de la historia

	   de nuestro juego

	*/

if (ESTADO==Inicio)

{

   tick++; 

   if(tick==5)

   {

      seg++;

      tick=0;

      if((seg>=0 && seg<5))

      {

        MostrarJuegoInicio1(); //Entre el segundo 0 y el segundo 5 muestra la presentación del juego

	visualizarFondoNegroNDS(); //Muestra un fondo negro porque luego pasará al estado Inicio y al pasar, no se elimina el fondo

      }

      else if ((seg>=5 && seg<20))

      {

	     MostrarPresentacion1(); //Entre el segundo 5 y el segundo 20 muestra la primera parte del inicio del juego

         visualizarFondoInicio1(); //Muestra el fondo que le corresponde con ese texto

      }

      else if ((seg>=20 && seg<35))

      { 

         MostrarHistoria2(); //Entre el segundo 20 y el segundo 35 muestra la segunda parte del inicio del juego

         visualizarFondoInicio2(); //Muestra el fondo que le corresponde con ese texto

      }

      else if ((seg>=35 && seg<50))

      {

         MostrarHistoria3(); //Entre el segundo 35 y el segundo 50 muestra la tercera parte del inicio del juego

         visualizarFondoInicio3(); //Muestra el fondo que le corresponde con ese texto

      }

      else if ((seg>=50 && seg<65))

      {

	     MostrarHistoria4(); //Entre el segundo 50 y el segundo 65 muestra la cuarta y última parte del inicio del juego

         visualizarFondoInicio4(); //Muestra el fondo que le corresponde con ese texto

      }

      else if ((seg>=65 && seg<80))

      {

	 MostrarControles(); //Entre el segundo 65 y el segundo 80 muestra los controles básicos del juego.

         seg=0;

      }

   }

}



/*

   Estado de las conversaciones del juego

*/

if(ESTADO==JuegoConv)

{

   //Una vez que se ha pulsado la A cerca del Rey y cuando la variable ContMovCam valga 1, se mostrará el texto que te dice el Rey

   if(ContMovCam==1 && IteracionNPC(200))

   {

      tick++;

      if(tick==5)

      {

	  /*

	     Mismas variables de antes con la misma funcionalidad y utilidad

	  */

	 seg++;

	 tick=0;

         if(seg>=0 && seg<=20) //Va trancurriendo el tiempo y se va mostrando la conversación con el Rey

         {

            MostrarConversacionRey(); //Llama la función para que salga el texto

            /*

			   Cuando hayan pasado 20 segundos, la pantalla superior no mostrará texto, se eliminará el rey en la posición que esté, ContMovCam se sumará 1

			   y la variable seg se reiniciará y cambiará de estado

			*/

			if(seg==20) 

	    {

	      MostrarTextoBlanco(); 

	      BorrarRey(1,200,159);

	      ContMovCam=2;

	      seg=0;

	      ESTADO=JuegoMov;

 	    }

         } 

      }

   }

  

   //Una vez que se ha pulsado la A cerca del Árbol y cuando la variable ContMovCam valga 4, se mostrará el texto que te dice el Árbol

   else if (ContMovCam==4 && IteracionNPC(175))

   {

      tick++;

      if(tick==5)

      {

	 /*

	     Mismas variables de antes con la misma funcionalidad y utilidad

	  */

	 seg++;

	 tick=0;

         if(seg>=0 && seg<=20) //Va trancurriendo el tiempo y se va mostrando la conversación con el Árbol

         {

            ConversacionArbolSprite(); //Llama la función para que salga el texto

			/*

			   Cuando hayan pasado 20 segundos, la pantalla superior no mostrará texto, se eliminará el Árbol en la posición que esté, ContMovCam se sumará 1

			   y la variable seg se reiniciará, y cambiará de estado

			*/

            if(seg==20)

	    {

	      MostrarTextoBlanco();

	      BorrarArbol(1,175,159);

	      ContMovCam=5;

	      seg=0;

	      ESTADO=JuegoMov;

 	    }

         } 

      }

   }



   //Una vez que se ha pulsado la A cerca de la Madre y su hijo y cuando la variable ContMovCam valga 6, se mostrará el texto que te dice la Madre y el hijo

   else if (ContMovCam==6 && IteracionNPC(100))

   {

      tick++;

      if(tick==5)

      {

	  /*

	     Mismas variables de antes con la misma funcionalidad y utilidad

	  */

	 seg++;

	 tick=0;

         if(seg>=0 && seg<=20)

         {

            ConversacionMadreSprite(); //Llama la función para que salga el texto

			/*

			   Cuando hayan pasado 20 segundos, la pantalla superior no mostrará texto, se eliminará la madre y su hijo en la posición que esté, ContMovCam se sumará 1

			   y la variable seg se reiniciará, y cambiará de estado

			*/

            if(seg==20)

	    {

	      MostrarTextoBlanco();

	      BorrarMadre(1,100,159);

	      ContMovCam=7;

	      seg=0;

	      ESTADO=JuegoMov;

 	    }

         } 

      }

   }



	/*

	   Dependiendo de la opción que haya elegido el jugador si pulsar la tecla ARRIBA para ir a la iglesia hablar con el cura

	   o pulsar la tecla ABAJO para ir a la cueva hablar con la araña. Cuando estén cerca de esos NPCs y si pulsa la tecla A cerca de

	   ellos y cuando la variable ContMovCam valga 8, se mostrará el texto correspondiente del NPC

	   

	*/

   else if (ContMovCam==8 && IteracionNPC(200))

   {

      tick++;

      if(tick==5)

      {

	  /*

	     Mismas variables de antes con la misma funcionalidad y utilidad

	  */

	 seg++;

	 tick=0;

	 if (ex==0)

	 {

         	if(seg>=0 && seg<=20)

         	{

		 ConversacionAranalSprite(); //Llama la función para que salga el texto de la araña

			/*

			   Cuando hayan pasado 20 segundos, la pantalla superior no mostrará texto, se eliminará la araña en la posición que esté, ContMovCam se sumará 1

			   y la variable seg se reiniciará, y cambiará de estado, y la posición del jugador se moverá a la izquierda del todo

			*/

           	 if(seg==20)

	    	 {

			MostrarTextoBlanco();

	      		BorrarCura(1,200,159);

	     		ContMovCam=9;

	      		seg=0;

				x=6;

	      		ESTADO=JuegoMov;

 	   	 }

         	} 

      	 }

	 else if (ex==1)

	 {

         	if(seg>=0 && seg<=20)

         	{

		 ConversacionCuralSprite(); //Llama la función para que salga el texto

			/*

			   Cuando hayan pasado 20 segundos, la pantalla superior no mostrará texto, se eliminará el cura en la posición que esté, ContMovCam se sumará 1

			   y la variable seg se reiniciará, y cambiará de estado, y la posición del jugador se moverá a la izquierda del todo

			*/

           	 if(seg==20)

	    	 {

			MostrarTextoBlanco();

	      		BorrarArana(1,200,159);

	     		ContMovCam=9;

	      		seg=0;

				x=6;

	      		ESTADO=JuegoMov;

 	   	 }

         	} 

      	}

    }

  }



   /*

       Cuando ContMovCam valga 9, hemos puesto que seg valga 0 porque nos solucionó un error pequeño que teníamos

   */

   else if (ContMovCam==9)

   {

	seg=0;

   }



	//Una vez que se ha pulsado la A cerca del X y cuando la variable ContMovCam valga 10, se mostrará el texto que te dice el X

   else if (ContMovCam==10 && IteracionNPC(150))

   {

      tick++;

      if(tick==5)

      {

	  /*

	     Mismas variables de antes con la misma funcionalidad y utilidad

	  */

	 seg++;

	 tick=0;

	 if (seg<20)

	 {

	    ConversacionX1Sprite(); //Llama la función para que salga el texto (primera parte del texto)

	 }

	 else if (seg>=20 && seg<40)

	 {

	    ConversacionX2Sprite(); //Llama la función para que salga el texto (segunda parte del texto)

	 }

	 /*

		Cuando hayan pasado 40 segundos, la pantalla superior no mostrará texto, se eliminará el cura en la posición que esté, ContMovCam se sumará 1

		y la variable seg se reiniciará, y cambiará de estado

	*/

	 else if (seg==40)

	 {

	    MostrarTextoBlanco();

	    BorrarX(1,150,159);

	    seg=0;

	    ESTADO=FinalEscena;

         }

      }

   }

}



if (ESTADO==FinalEscena)

{

   tick++; 

   if(tick==5)

   {

	  /*

	     Uno de los finales dependiendo la opciñon que haya elegido

	  */

      if ((contF%2==0)&&conv==true)

      {

	  /*

	     Mismas variables de antes con la misma funcionalidad y utilidad

	  */

	seg++;

    tick=0;

	if((seg>=0 && seg<10))

	{

	  ConversacionFinal1(); //Llama la función para que salga el texto

      visualizarFondoFInal1(); //Muestra el fondo que le corresponde con ese texto

	  seg=0; //Se reinicia la variable seg 

	  ESTADO=Inicio; //Cambia de estado

	}

      }



	  /*

	     Otro de los finales dependiendo la opciñon que haya elegido

	  */

      else if ((contF%2!=0)&&conv==true)

      {

	  /*

	     Mismas variables de antes con la misma funcionalidad y utilidad

	  */

	seg++;

    tick=0;

	if(seg<20)

	{

	 ConversacionFinal2_1(); //Llama la función para que salga el texto (primera parte)

     visualizarFondoFInal2(); //Muestra el fondo que le corresponde con ese texto

	}

	else if (seg>=20 && seg<40)

	 {

	   ConversacionFinal2_2(); //Llama la función para que salga el texto (segunda parte)

       visualizarFondoFInal2(); //Muestra el fondo que le corresponde con ese texto

	   seg=0; //Se reinicia la variable seg 

	   ESTADO=Inicio; //Cambia de estado

	 }

      }



      /*

	     Otro de los finales dependiendo la opciñon que haya elegido

	  */

      else if ((contF%2==0)&&conv==false)

      {

	  /*

	     Mismas variables de antes con la misma funcionalidad y utilidad

	  */

	seg++;

    tick=0;

	if(seg<20)

	{

	 ConversacionFinal3_1(); //Llama la función para que salga el texto (primera parte)

     visualizarFondoFInal3(); //Muestra el fondo que le corresponde con ese texto

	}

	else if (seg>=20 && seg<40)

	 {

	   ConversacionFinal3_2(); //Llama la función para que salga el texto (segunda parte)

       visualizarFondoFInal3(); //Muestra el fondo que le corresponde con ese texto

	   seg=0; //Se reinicia la variable seg 

	   ESTADO=Inicio; //Cambia de estado

	 }

      }



	  /*

	     Último de los finales dependiendo la opciñon que haya elegido

	  */

      else if ((contF%2!=0)&& conv==false)

      {

	  /*

	     Mismas variables de antes con la misma funcionalidad y utilidad

	  */

	seg++;

    tick=0;

	if(seg<20)

	{

	 ConversacionFinal4_1(); //Llama la función para que salga el texto (primera parte)

     	 visualizarFondoFInal4(); //Muestra el fondo que le corresponde con ese texto

	}

	else if (seg>=20 && seg<40)

	 {

	   ConversacionFinal4_2(); //Llama la función para que salga el texto (segunda parte)

       visualizarFondoFInal4(); //Muestra el fondo que le corresponde con ese texto

	 }

	else if (seg==40)

	{

	   seg=0; //Se reinicia la variable seg 

	   ESTADO=Inicio; //Cambia de estado

	}

      }

   }	

 }

}



/*

   Método para establecer los vectores de interrupción que hemos usado

*/

void EstablecerVectorInt()

{

	irqSet(IRQ_TIMER0,RutAtencionTempo); //Para establecer el vector de interrupciones del Timer0

	irqSet(IRQ_KEYS,RutAtencionTeclado); //Para establecer el vector de interrupciones del Teclado

}









