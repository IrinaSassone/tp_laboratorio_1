/*
 * validaciones.h
 *
 *  Created on: 2 oct. 2020
 *      Author: Sassone, Irina
 */

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_

int isValidInt(int number, int min, int max);
int isValidFloat(float number, float min, float max);
int isValidChar(char character, char min, char max);
int isValidName(char* string);
int isValidLastName(char* string);

#endif /* VALIDACIONES_H_ */
