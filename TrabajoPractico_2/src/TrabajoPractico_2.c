/*
 ============================================================================
 Name        : TrabajoPractico_2.c
 Author      : Sassone, Irina
 Version     :
 Copyright   : Your copyright notice
 Description : Sistema para administrar su nómina de empleados.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayEmployees.h"
#include "getters.h"
#include "validaciones.h"

#define ELEMENTS 1000

int main(void) {
	int option;
	int flagMenu=0;
	int positionFree;
	int idEmployee=0;
	char auxName[51];
	char auxLastName[51];
	float auxSalary;
	int auxSector;
	int order;

    Employee anEmployee [ELEMENTS];
    initEmployees(anEmployee,ELEMENTS);

		do {
			printf("\n\t\t\t|| SISTEMA PARA ADMINISTRAR NÓMINA DE EMPLEADOS ||\t\t\t");
			printf("\nMENU DE OPCIONES:");
			printf("\n1. Dar de alta un empleado.");
			printf("\n2. Hacer modificación de algún dato del empleado.");
			printf("\n3. Dar de baja un empleado.");
			printf("\n4. Informar.");
			printf("\n5. Salida.");
			printf("\nSeleccione una opción: ");
			scanf("%d",&option);
			switch(option) {
				case 1:

					break;
				case 2:
					printf("Acá se hacen las modificaciones.\n");
					break;
				case 3:
					if(flagMenu==1) {
						printEmployees(anEmployee, ELEMENTS);
						removeEmployee(anEmployee, idEmployee, ELEMENTS);
					}else{
						printf("\n¡ERROR!No hay empleados cargados.");
					}
					break;
				case 4:
					if(flagMenu==1) {
						switch(order) {

						}
					}
					break;
				default:
					break;
			}
		}while(option!=5);

	return 0;
}
