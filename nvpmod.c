#include "commondef.h"
#include "nbiasvoter.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>


//Presentation of the NVP pattern implementation
//gathering of the entries
_Bool Nflag=0;
_Bool Gatheredflag=0;

int terminate = 0;


int array_entries[NVERSION];

int getrandom(){
	srand(time(NULL));
	int temp = rand() % 8;
	return temp;
}

int getprogram(int ind){
//int temp = getrandom();
	int bias = getrandom();
	switch(ind) {

	   case 0  :
		   bias = getrandom();
	      return bias;
	      break;

	   case 1  :
		   bias = getrandom();
	      return bias;
	      break;

	   case 2  :

	   	  return -7;
	   	  break;

	   case 3  :
	   	  return bias;
	   	  break;

	   default :
	   return getrandom();
	}
}

void gathering(int arr[4]){

	for(int i=0; i<NVERSION; i++){

		arr[i] = getprogram(i);

	}


}


void cleaning(){
	for(int i=0; i<NVERSION; i++){

			array_entries[i] = -2;

		}
}



void nvpsequence(){
int b;
//reunir las entradas
gathering(array_entries);
for (int i=0; i<NVERSION; i++){
	b = array_entries[i];
printf("%i	",b);
}


int actual = nbiasreturn(array_entries);
cleaning(array_entries);


printf(" resultado es %i", actual);
//enviar al nbiasvoter
//mostrar resultado


}
