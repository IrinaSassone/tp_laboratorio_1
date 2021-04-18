/*
 * arrayEmployees.c
 *
 *  Created on: 2 oct. 2020
 *      Author: Sassone, Irina
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayEmployees.h"
#include "validaciones.h"
#include "getters.h"

#define TRUE 1
#define FALSE 0
#define TRIES 3

/**
 * \brief Indica todas las posiciones del vector que están vacías, esta función pone la
 * bandera (isEmpty) en TRUE en todas las posiciones del vector.
 * @param list Employee list[]: es un puntero al vector de empleados.
 * @param len Es la longitud del vector.
 * @return Si retorno=-1 es un error [invalida la longitud (len) o el puntero es NULL],
 * si retorna=0 salió bien.
 */
int initEmployees(Employee* list, int len) {
	int i;
	int retorno=-1;
	if(list!=NULL && len>0) {
		// Recorre el array
		for(i=0; i<len; i++) {
			// Pone la bandera en TRUE
			list[i].isEmpty=TRUE;
			retorno=0;
		}
	}
	return retorno;
}

/**
 * \brief Recorre el vector buscando si hay una posición libre.
 * @param list Employee list[]: es un puntero al vector de empleados.
 * @param len Es la longitud del vector.
 * @return Si retorno=-1 es un error [invalida la longitud (len) o el puntero es NULL],
 * si retorna=0 salió bien.
 */
int findEmptyPlace(Employee* list, int len) {
	int i;
	int retorno=-1;
	if(list!=NULL && len>0) {
		// Recorre el array
		for(i=0; i<len; i++) {
			// Si lista[indice] es igual a TRUE
			if(list[i].isEmpty==TRUE) {
				retorno=0;
				// Rompe
				break;
			}
		}
	}
	return retorno;
}

/**
 * \brief Agrega en una lista existente de empleados los valores recibidos como parámetro
 * en la primera posición libre.
 * @param list Employee list[]: es un puntero al vector de empleados.
 * @param len Es la longitud del vector.
 * @param id Es el ID del empleado.
 * @param name Es el nombre del empleado.
 * @param lastName Es el apellido del empleado.
 * @param salary Es el salario del empleado.
 * @param sector Es el sector del empleado.
 * @return Si retorno=-1 es un error [invalida la longitud (len) o el puntero es NULL],
 * si retorna=0 salió bien.
 */
int addEmployee(Employee* list, int len, int id, char name[], char lastName[], float salary, int sector) {
	int retorno=-1;
	if(list!=NULL & len>0) {
		// Lista con datos a ingresar
		list[id].id=id;
		strncpy(list[id].name, name, 51);
		strncpy(list[id].lastName, lastName, 51);
		list[id].salary=salary;
		list[id].sector=sector;
		list[id].isEmpty=FALSE;
		retorno=0;
	}else{
		prinf("¡ERROR! Vuelva a intentarlo.\n");
	}
	return retorno;
}

/**
 * \brief Busca un empleado por ID y retorna la posición del índice en el vector.
 * @param list Employee list[]: es un puntero al vector de empleados.
 * @param len Es la longitud del vector.
 * @param id Es el ID del empleado.
 * @return Retorna la posición del índice del empleado o retorna=-1 si la longitud (len) o el puntero es
 * NULL o si no se encontró ningún empleado.
 */
int findEmployeeById(Employee* list, int len, int id) {
	int i;
	int retorno=-1;
	Employee index;
	if(list!=NULL & len>0) {
		printf("Ingrese el id del empleado: ");
		scanf("%d",&id);
		// Recorre el array
		for(i=0; i<len; i++) {
			// Si el indice es igual a la lista[indice]
			if(index.id==list[i].id) {
				retorno=0;
			}else
			{
				printf("¡ERROR! La búsqueda ha fallado.\n");
			}
		}
	}
	return retorno;
}

/**
 * \brief
 * @param list Employee list[]: es un puntero al vector de empleados.
 * @param len Es la longitud del vector.
 * @param id Es el ID del empleado.
 * @return Retorna la posición del índice del empleado o retorna=-1 si la longitud (len) o el puntero es
 * NULL o si no se encontró ningún empleado.
 */
int modifyEmployee(Employee* list, int len, int id) {
	int retorno=-1;
	int position;
	int option;
    int auxSector;
    float auxSalary;
	if(list!=NULL && len>0) {
		// Busqueda de empleado por ID
		position=findEmployeeById(list, len, id);
		// Chequea que el ID no sea -1
		if(position!=-1) {
			while(option!=4) {
				// En cada case va una modificación de dato
				switch(option) {
					case 1:
						if (getName("\nIngrese nuevo nombre: \n","Error, nombre no valido.\n", 2, 51, TRIES, list[position].name)==0) {
		                       printf("\nLa modificación ha sido realizada con éxito.");
		                    }else{
		                            printf("\n¡ERROR! No se pudo modificar.");
		                    }
						break;
					case 2:
						 if(getLasName("\nIngrese nuevo apellido: \n","Error, apellido no valido.\n", 2, 51, TRIES, list[position].lastName)==0) {
							 printf("\nLa modificación ha sido realizada con éxito.");
		                    }else{
		                            printf("\n¡ERROR! No se pudo modificar.");
		                    }
						 break;
					case 3:
	                    if(getInt("\nIngrese el nuevo sector: 1. Sector uno.\n2. Sector dos.\n3. Sector tres.\n","Error, sector no valido.", 1, 3, TRIES, &auxSector)==0) {
	                        list[position].sector=auxSector;
	                        printf("Modificacion con exito.\n");
	                    }else{
	                    	printf("Error, no se pudo modificar.\n");
	                    }
	                    break;
					case 4:
	                    if(getFloat("\nIngrese el salario nuevo: \n","Error, salario no valido.\n", 7000, 50000, TRIES, &auxSalary)==0) {
	                        list[position].salary=auxSalary;
	                        printf("Modificacion con exito.\n");
	                    }else{
                            printf("Error, no se pudo modificar.\n");
                        }
	                    break;
	                case 5:
	                    break;
				}
	            retorno=0;
				}
			}else{
				printf("No se encontro el id del empleado.\n");
			}
		}
	}
	return retorno;
}

/**
 * \brief Elimina de forma lógica a un empleado por ID poniendo
 * isEmpty en 1 (TRUE) recibiendo como parámetro dicho ID.
 * @param list Employee list[]: es un puntero al vector de empleados.
 * @param len Es la longitud del vector.
 * @param id Es el ID del empleado.
 * @return Si retorno=-1 es un error [invalida la longitud (len) o el puntero es NULL],
 * si retorna=0 salió bien.
 */
int removeEmployee(Employee* list, int len, int id) {
	int position;
	int retorno=-1;
	if(list!=NULL && len>0) {
		position=findEmployeeById(list, len, id);
		// Chequea que el ID no sea -1
		if(position!=-1) {
			// Si la posición está en 0
			if(list[position].isEmpty==FALSE) {
				// Entonces lo cambia a 1
				list[position].isEmpty=TRUE;
				printf("Se borró con éxito el empleado con ID %d.\n",list[position].id);
				retorno=0;
			}else{
				prinf("No se encontró ningún empleado con ese ID.\n");
			}
		}
	}
	return retorno;
}

/**
 * \brief Ordena los elementos del vector de empleados, el argumento "order"
 * indica el orden ARRIBA o ABAJO.
 * @param list Employee list[]: es un puntero al vector de empleados.
 * @param len Es la longitud del vector.
 * @param order [0] indica ABAJO.
 * @return Si retorno=-1 es un error [invalida la longitud (len) o el puntero es NULL],
 * si retorna=0 salió bien.
 */
int sortEmployeesInDescendingOrder(Employee* list, int len, int order) {
	int i;
	int j;
	Employee buffer;
	int retorno=-1;
	if(list!=NULL && len>0) {
		// Descendiente
		if(order==0) {
			// Recorre el array indice i
			for(i=0; i<=len; i++) {
				// Si i es 1 o si i+1 es 1
				if(list[i].isEmpty==TRUE || list[i+1].isEmpty==TRUE) {
					// Entonces continua
					continue;
				}
				// Recorre el array indice j
				for(j=i+1; j<=len; j++) {
					// Compara entre el apellido i y j y si es menor a 0
					if(strncmp(list[i].lastName, list[j].lastName, 51)<0) {
						buffer=list[i];
						list[i]=list[j];
						list[j]=buffer;
					// Compara entre apellido i y j y si es igual a 0
					}else if(strncmp(list[i].lastName, list[j].lastName, 51)==0) {
						if(list[i].sector<list[j].sector) {
							buffer=list[i];
							list[i]=list[j];
							list[j]=buffer;
						}
					}
					retorno=0;
				}
			}
		}
	}
	return retorno;
}

/**
 * \brief Ordena los elementos del vector de empleados, el argumento "order"
 * indica el orden ARRIBA o ABAJO.
 * @param list list Employee list[]: es un puntero al vector de empleados.
 * @param len len Es la longitud del vector.
 * @param order [1] indica ABAJO.
 * @return Si retorno=-1 es un error [invalida la longitud (len) o el puntero es NULL],
 * si retorna=0 salió bien.
 */
int sortEmployeesInAscendingOrder(Employee* list, int len, int order) {
	int i;
	int j;
	Employee buffer;
	int retorno=-1;
	if(list!=NULL && len>0) {
		// Ascendente
		if(order==1) {
			// Recorre el array indice i
			for(i=0; i<=len; i++) {
				// Si i es 1 o si i+1 es 1
				if(list[i].isEmpty==TRUE || list[i+1].isEmpty==TRUE) {
					// Entonces continua
					continue;
				}
				// Recorre el array indice j
				for(j=i+1; j<=len; j++) {
					// Compara entre el apellido i y j y si es mayor a 0
					if(strncmp(list[i].lastName, list[j].lastName, 51)>0)
					{
						buffer=list[i];
						list[i]=list[j];
						list[j]=buffer;
						// Compara entre apellido i y j y si es igual a 0
					}else if(strncmp(list[i].lastName, list[j].lastName, 51)==0) {
						if(list[i].sector>list[j].sector) {
							buffer=list[i];
							list[i]=list[j];
							list[j]=buffer;
						}
					}
					retorno=0;
				}
			}
		}
	}
	return retorno;
}

/**
 * \brief Calcula el total de salarios, promedio total y la cantidad de empleados que superan
 * el salario promedio.
 * @param lista Employee list[]
 * @param len Es la longitud del vector.
 * @return Si retorno=-1 es un error [invalida la longitud (len) o el puntero es NULL],
 * si retorna=0 salió bien.
 */
int averageSalary(Employee* list, int len) {
	int i;
	int j;
	int retorno=-1;
	float average=0;
	float auxAverage=0;
	int employeeCounter=0;
	int auxEmployeeCounter=0;
	if(list!=NULL & len>0) {
		// Recorre el array i
		for(i=0; i<len; i++) {
			// Si i es 0
			if(list[i].isEmpty==FALSE) {
				// Acumula salarios
				auxAverage=auxAverage+list[i].salary;
				// Cuenta empleados
				employeeCounter++;
			}
		}
		// Saca promedio
		average=auxAverage/employeeCounter;
		printf("El total de los salarios es: %.2f", employeeCounter);
		printf("El promedio de los salarios es: %.2f", average);
		// Recorre el array j
		for(j=0; j<len; j++) {
			// Si i es 0
			if(list[j].isEmpty==FALSE) {
				// Compara si j.salary es mayor a promedio
				if(list[j].salary>average) {
					// Cuenta esos empleados
					auxEmployeeCounter++;
				}
			}
		}
		printf("La cantidad de empleados que superan el salario promedio es: %.2f", auxEmployeeCounter);
		retorno=0;
	}
	return retorno;
}

/**
 * \brief Imprime el contenido del vector de empleados.
 * @param list Employee list[]: es un puntero al vector de empleados.
 * @param len Es la longitud del vector.
 * @return Retorna un entero.
 */
int printEmployees(Employee* list, int len) {
	int i;
	printf("\t\tListado de empleados.\t\t");
	// Recorre el array
	for(i=0; i<len; i++) {
		// Si i.isEmpty es 0
		if(list[i].isEmpty==FALSE) {
			printf("ID del empleado: %d", list[i].id);
			printf("Nombre del empleado: %s", list[i].name);
			printf("Apellido del empleado: %s", list[i].lastName);
			printf("Salario del empleado: %.2f", list[i].salary);
			printf("Sector del empleado: %d", list[i].sector);
		}
	}
	return 0;
}
