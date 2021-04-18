/*
 ============================================================================
 Name        : TrabajoPractico_1.c
 Author      : Sassone, Irina.
 Version     :
 Copyright   : Your copyright notice
 Description : Realizar de una calculadora.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

// Definición de variables
int main() {
	setbuf(stdout,NULL);
	int seleccionarOpcion;
	float valorUno;
	float valorDos;
	float resultadoSuma;
	float resultadoResta;
	float resultadoDivision;
	float resultadoMultiplicacion;
	int resultadoFactorialUno;
	int resultadoFactorialDos;
	int banderaValorUno;
	int banderaValorDos;

	banderaValorUno=0;
	banderaValorDos=0;

	// Creación de menú
	do {
		printf("\nSeleccione entre las siguientes opciones:");
		printf("\n1. Para ingresar el primer valor.");
		printf("\n2. Para ingresar el segundo valor.");
		printf("\n3. Para calcular todas las operaciones.");
		printf("\n4. Para obtener los resultados de las operaciones.");
		printf("\n5. Para salir.");
		printf("\nOpción: ");
		scanf("%d",&seleccionarOpcion);
		switch(seleccionarOpcion) {
			case 1:
				printf("Primer valor ingresado: ");
				scanf("%f",&valorUno);
				banderaValorUno=1;
			break;
			case 2:
				printf("Segundo valor ingresado: ");
				scanf("%f",&valorDos);
				banderaValorDos=1;
			break;
			case 3:
				if(banderaValorUno==1 && banderaValorDos==1) {
					printf("a. Calcular la suma: A+B");
					resultadoSuma=sumarValores(valorUno, valorDos);
					printf("\nb. Calcular la resta: A-B");
					resultadoResta=restarValores(valorUno, valorDos);
					printf("\nc. Calcular la division: A/B");
					resultadoDivision=dividirValores(valorUno, valorDos);
					printf("\nd. Calcular la multiplicacion: A*B");
					resultadoMultiplicacion=multiplicarValores(valorUno, valorDos);
					printf("\ne. Calcular el factorial: A! y B!\n");
					resultadoFactorialUno=calcularFactorial(valorUno);
					resultadoFactorialDos=calcularFactorial(valorDos);
				}else{
					printf("\n¡¡ERROR!!\nSe olvidó de ingresar alguno de los valores.\n");
					banderaValorUno=0;
					banderaValorDos=0;
				}
			break;
			case 4:
				if(banderaValorUno==1 && banderaValorDos==1) {
					printf("a. El resultado de A+B es: %.2f",resultadoSuma);
					printf("\nb. El resultado de A-B es: %.2f",resultadoResta);
					if(valorDos==0) {
						resultadoDivision=0;
						printf("\nError. No se puede dividir por cero.");
					}else{
						printf("\nc. El resultado de A/B es: %.2f",resultadoDivision);
					}
					printf("\nd. El resultado de A*B es: %.2f",resultadoMultiplicacion);
					printf("\ne. El factorial de A! es: %d y el factorial de B! es: %d\n",resultadoFactorialUno,resultadoFactorialDos);
				}else{
					printf("\n¡¡ERROR!!\nSe olvidó de ingresar alguno de los valores.\n");
					banderaValorUno=0;
					banderaValorDos=0;
				}

			break;
			case 5:
				printf("\nUsted ha salido de la calculadora.\n");
			break;
		}
	}while(seleccionarOpcion!=5);

	return 0;
}
