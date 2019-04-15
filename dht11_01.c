
#include "atest.h"
#include "sapi.h"        // <= Biblioteca sAPI
#include "dynvoter.h"

/*==================[definiciones y macros]==================================*/

// UART list:
//  - UART_USB or UART_ENET
//  - UART_232
//  - UART_GPIO or UART_485

#define UART_DEBUG UART_USB

/*==================[definiciones de datos internos]=========================*/

//CONSOLE_PRINT_ENABLE
DEBUG_PRINT_ENABLE

/*==================[definiciones de datos externos]=========================*/

/*==================[declaraciones de funciones internas]====================*/
float sums, sum;
int total;
float mediafinal;
static void format( float valor, char *dst, uint8_t pos );



char buffout[64];
int main( void ){

   // ---------- CONFIGURACIONES ------------------------------

   // Inicializar y configurar la plataforma
   boardConfig();

   // Inicializar UART_USB como salida de consola
   debugPrintConfigUart( UART_DEBUG, 115200 );


   int result = 0;
   int result2 = 0;
   int result3 = 0;
   int count = 0;
   int count2 = 0;
   int count3 = 0;

  while(1){

	  debugPrintString( "GPIO1" );
	  	  debugPrintEnter();
  result = acceptanceTest(1,&sum);
  sums = sums + sum;
  delay(500);




debugPrintString( "GPIO2" );
	  	  debugPrintEnter();

  result2 = acceptanceTest(2,&sum);
  sums = sums + sum;
  delay(500);




  debugPrintString( "GPIO5" );
	  	  debugPrintEnter();

  result3 = acceptanceTest(3,&sum);
  sums = sums + sum;
  delay(500);


count = count + result;
count2 = count2 + result2;
count3 = count3 + result3;



if(count == 5){
debugPrintString( "FALLA TOTAL EN GPIO1" );
	  debugPrintEnter();
	  count = 0;
  }

  if(count2 == 5){
  debugPrintString( "FALLA TOTAL EN GPIO2" );
 	  debugPrintEnter();
 	 count2 = 0;
  }

if(count3 == 5){
debugPrintString( "FALLLA TOTAL EN GPIO5" );
	  debugPrintEnter();
	  count3 = 0;
  }

total = 3 - result - result2 - result3;
mediafinal = sums / total;

float tot = total;
debugPrintString( "participaron  " );

format( tot, buffout, 0 );
debugPrintString( buffout );
debugPrintEnter();

debugPrintString( "Valor de consenso es:" );

format( mediafinal, buffout, 0 );
debugPrintString( buffout );
debugPrintEnter();


/*debugPrintInt(Intp);
debugPrintString( "." );
debugPrintInt(Idec);
	  debugPrintEnter();
*/


sum = 0;
sums = 0;
mediafinal = 0;
  }


}








static void format( float valor, char *dst, uint8_t pos ){
	uint16_t val;
	val = 10 * valor;
	val = val % 1000;
	dst[pos] = (val / 100) + '0';
	pos++;
	dst[pos] = (val % 100) / 10 + '0';
	pos++;
	dst[pos] = '.';
	pos++;
	dst[pos] = (val % 10)  + '0';
	pos++;
	dst[pos] = '\0';
}




void ValuesPrinter (float h, float t){



	format( t, buffout, 0 );
	  debugPrintString( buffout );
	  debugPrintEnter();

}

void SumValue(float Valueparam){
	debugPrintString( "VALUEPARAMES" );
	sums = sums + Valueparam;
	 format( Valueparam, buffout, 0 );
		  debugPrintString( buffout );
		  debugPrintEnter();

			debugPrintString( "//////" );
}



/*==================[definiciones de funciones externas]=====================*/

/*==================[fin del archivo]========================================*/

