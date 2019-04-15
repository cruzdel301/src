//DEPRECATED no-bias voter continuous for pattern implementation.
/*
 * check issue with the float values. array mismatch recovery at result stance. this may be replaced
 * for the atmod in the future.
 *
 *the depicted function overlap several functions, not recommended for large developments.
 * */

#include <stdlib.h>
#include <stdio.h>


float testnc(float entradas[4]){
	return entradas[1];
}

double nbiasereturn(float entradas[4]){
	int contador[4]={0};
	int count = 0;
	double value = 0;
	double envlim = 0.02;

	for (int i=0; i<4; i++){
		value = entradas[i];

		for (int j=0; j<4; j++){
			double inf=value - envlim;
			double sup=value + envlim;
			if ((inf < entradas[j]) && ( entradas[j] < sup))
			{
				count++;
			}
		}

		contador[i]=count;
		count=0;

	}




	for (int i=0; i<4; i++){

		for (int j=0; j<4; j++){
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



	return entradas[1];
}


