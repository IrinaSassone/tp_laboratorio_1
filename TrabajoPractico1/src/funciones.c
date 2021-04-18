/*
 * funciones.c
 *
 *  Created on: 12 sep. 2020
 *      Author: Sassone, Irina.
 */
#include <stdio.h>
#include <stdlib.h>

// Desarrollo de funciones
/** \brief sumarValores: Es la función donde se suma los números con decimal para obtener el resultado.
 *
 * \param valorUno: Es el primer número con decimal que se va a sumar.
 * \param valorDos: Es el segundo número con decimal que se va a sumar.
 * \return resultado: Devuelve el resultado de la suma.
 *
 */
float sumarValores(float valorUno, float valorDos) {
	float resultado;
	resultado=valorUno+valorDos;
	return resultado;
}

/** \brief restarValores: Es la función donde se resta los números con decimal para obtener el resultado.
 *
 * \param valorUno: Es el primer número con decimal que se va a restar.
 * \param valorDos: Es el segundo número con decimal que se va a restar.
 * \return resultado: Devuelve el resultado de la resta.
 *
 */
float restarValores(float valorUno, float valorDos) {
	float resultado;
	resultado=valorUno-valorDos;
	return resultado;
}

/** \brief dividirValores: Es la función donde se divide los números con decimal para obtener el resultado,
 *	excepto que el dividendo sea 0.
 * \param valorUno: Es el número con decimal que se va a dividir (divisor).
 * \param valorDos: Es el número con decimal que se va a dividir (dividendo), excepto que sea 0.
 * \return resultado: Devuelve el resultado de la división.
 *
 */
float dividirValores(float valorUno, float valorDos) {
	float resultado;
	resultado=valorUno/valorDos;
	return resultado;
}

/** \brief multiplicarValores: Es la función donde se multiplica los números con decimal para obtener el resultado.
 *
 * \param valorUno: Es el número con decimal que se va a multiplicar.
 * \param valorDos: Es el número con decimal por el que se va a multiplicar.
 * \return resultado: Devuelve el resultado de la multiplicación.
 *
 */
float multiplicarValores(float valorUno, float valorDos) {
	float resultado;
	resultado=valorUno*valorDos;
	return resultado;
}

/** \brief calcularFactorial: Es la función donde se va a calcular la función recursiva de un número.
 *
 * \param valor: Es el número que se va calcular la función factorial.
 * \return return: Va a retornar a 1 si el valor ingresado es menor a ese número, sino el factorial retorna
 * si el valor ingresado es igual o mayor a 1.
 *
 */
int calcularFactorial(int valor) {
	if(valor<1) {
		return 1;
	}else{
		return(valor*calcularFactorial(valor-1));
	}
}

