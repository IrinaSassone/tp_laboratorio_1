/*
 ============================================================================
 Name        : TrabajoPractico1.c
 Author      : Sassone, Irina
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
	setbuf(stdout, NULL);
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
		printf("CALCULADORA.\nSeleccione entre las siguientes opciones: ");
		if(banderaValorUno=1) {
			printf("\n1. Para ingresar el primer valor. (A=%.2f)", valorUno);
		}else{
			printf("\n1. Para ingresar el primer valor. (A=x)");
		}
		if(banderaValorDos=1) {
			printf("\n2. Para ingresar el segundo valor. (B=%.2f)", valorDos);
		}else{
			printf("\n2. Para ingresar el segundo valor. (B=y)");
		}
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
					printf("Primer valor ingresado: A=%.2f\nSegundo valor ingresado: B=%.2f\n\n", valorUno, valorDos);
					printf("a. Calcular la suma: %.2f+%.2f", valorUno, valorDos);
					resultadoSuma=sumarValores(valorUno, valorDos);
					printf("\nb. Calcular la resta: %.2f-%.2f", valorUno, valorDos);
					resultadoResta=restarValores(valorUno, valorDos);
					printf("\nc. Calcular la division: %.2f/%.2f", valorUno, valorDos);
					resultadoDivision=dividirValores(valorUno, valorDos);
					printf("\nd. Calcular la multiplicacion: %.2f*%.2f", valorUno, valorDos);
					resultadoMultiplicacion=multiplicarValores(valorUno, valorDos);
					printf("\ne. Calcular el factorial: %.2f! y %.2f!", valorUno, valorDos);
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
					printf("a. El resultado de %.2f+%.2f es: %.2f", valorUno, valorDos, resultadoSuma);
					printf("\nb. El resultado de %.2f-%.2f es: %.2f", valorUno, valorDos, resultadoResta);
					if(resultadoDivision!=0) {
						printf("\nc. El resultado de %.2f/%.2f es: %.2f", valorUno, valorDos, resultadoDivision);
					}else{
						printf("\nError. No se puede dividir por cero.");
					}
					printf("\nd. El resultado de %.2f*%.2f es: %.2f", valorUno, valorDos, resultadoMultiplicacion);
					printf("\ne. El factorial de %.2f! es: %.2f y el factorial de %.2f es: %.2f!\n", valorUno, valorDos, resultadoFactorialUno, resultadoFactorialDos);
				}else{
					printf("\n¡¡ERROR!!\nSe olvidó de ingresar alguno de los valores.\n");
					banderaValorUno=0;
					banderaValorDos=0;
				}
			break;
			case 5:
				printf("\nUsted ha salido de la calculadora.\n\a");
			break;
		}
	}while(seleccionarOpcion!=5);

	return 0;
}

