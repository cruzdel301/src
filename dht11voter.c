/*
 * dht11voter.c
 *
 *  Created on: 21 feb. 2019
 *      Author: user
 */

#include "commondef.h"
#include <stdlib.h>
#include <stdio.h>

float dht11md(float entradas[NVERSION]){

	float buff =0;
	for (int i=0; i<NVERSION; i++){
		buff = buff+ entradas[i];
	}

	float  result = (buff / NVERSION) ;
return 	result;

}

int nbiasreturn(int entradas[NVERSION]){
	int contador[NVERSION];
	int count = 0;
	float value = 0;

	for (int i=0; i<NVERSION; i++){
		value = entradas[i];

		for (int j=0; j<NVERSION; j++){
			if (entradas[j] == value)
			{
				count++;
			}
		}

		contador[i]=count;
		count=0;

	}




	for (int i=0; i<NVERSION; i++){

		for (int j=0; j<NVERSION; j++){
			if (contador[j] < contador[i])
						{
							int tmp = contador[i];
							int tmpd = entradas[i];
							contador[i] = contador[j];
							contador[j] = tmp;

							entradas[i] = entradas[j];
							entradas[j] = tmpd;
						}

		}
	}


	int capture = (int) entradas[1];
	return capture;
}

