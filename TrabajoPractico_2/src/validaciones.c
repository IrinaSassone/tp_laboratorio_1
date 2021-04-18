/*
 * validaciones.c
 *
 *  Created on: 2 oct. 2020
 *      Author: Sassone, Irina
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"

int isValidInt(int number, int min, int max) {
	if(number>min && number<max) {
		return 1;
	}else{
		return 0;
	}
}

int isValidFloat(float number, float min, float max) {
	int retorno=0;
	if(number>min && number<max) {
		retorno=1;
	}
	return retorno;
}

int isValidChar(char character, char min, char max) {
	int retorno=0;
	if(character>min && character<max) {
		retorno=1;
	}
	return retorno;
}

int isValidName(char* string) {
	int i;
	int retorno=-1;
	for(i=0; string[i]!='\0'; i++) {
		 if((string[i]>'Z' || string[i]<'A') && (string[i]>'z' || string[i]<'a')) {
			 retorno=0;
			 break;
		 }
	}
	return retorno;
}

int isValidLastName(char* string) {
	int i;
	int retorno=-1;
	for(i=0; string[i]!='\0'; i++) {
		 if((string[i]>'Z' || string[i]<'A') && (string[i]>'z' || string[i]<'a')) {
			 retorno=0;
			 break;
		 }
	}
	return retorno;
}

