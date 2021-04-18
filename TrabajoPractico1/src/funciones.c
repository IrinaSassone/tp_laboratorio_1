/*
 * funciones.c
 *
 *  Created on: 12 sep. 2020
 *      Author: Sassone, Irina.
 */

#include <stdio.h>
#include <stdlib.h>

// Desarrollo de funciones
float sumarValores(float valorUno, float valorDos) {
	float resultado;
	resultado=valorUno+valorDos;
	return resultado;
}

float restarValores(float valorUno, float valorDos) {
	float resultado;
	resultado=valorUno-valorDos;
	return resultado;
}

float dividirValores(float valorUno, float valorDos) {
	float resultado;
	resultado=valorUno/valorDos;
	return resultado;
}

float multiplicarValores(float valorUno, float valorDos) {
	float resultado;
	resultado=valorUno*valorDos;
	return resultado;
}

int calcularFactorial(int valor) {
	if(valor<1) {
		return 1;
	}else{
		return(valor*calcularFactorial(valor-1));
	}
}
