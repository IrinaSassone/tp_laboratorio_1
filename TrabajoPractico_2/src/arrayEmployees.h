/*
 * arrayEmployees.h
 *
 *  Created on: 2 oct. 2020
 *      Author: Sassone, Irina
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

typedef struct {
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;
	}Employee;

int initEmployees(Employee list[], int len);
int findEmptyPlace(Employee list[], int len);
int addEmployee(Employee list[], int len, int id, char name[], char lastName[], float salary, int sector);
int findEmployeeById(Employee list[], int len, int id);
int modifyEmployee(Employee list[], int len, int id);
int removeEmployee(Employee list[], int len, int id);
int sortEmployeesInDescendingOrder(Employee list[], int len, int order);
int sortEmployeesInAscendingOrder(Employee list[], int len, int order);
int averageSalary(Employee lista[], int len);
int printEmployees(Employee list[], int len);


#endif /* ARRAYEMPLOYEES_H_ */
