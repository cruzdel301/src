#include "commondef.h"
#include "dht11_01.h"
#include "dht11voter.h"
#include "sapi.h"


	float prhum = 0;
	float prtemp = 0;
   float k = 30.5;

int acceptanceTest(int gpio, float *aval){

	if (gpio == 1){
	dht11Init(GPIO1);
	}

	if (gpio == 2){
		dht11Init(GPIO2);
		}

	if (gpio == 3){
		dht11Init(GPIO5);
		}

	if( dht11Read(&prhum, &prtemp ) ) {
		ValuesPrinter (prhum, prtemp );

			*aval = prtemp;
			return 0;

		} else {

			return 1;
		}

}





