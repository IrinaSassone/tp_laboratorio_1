/*
 * getters.h
 *
 *  Created on: 2 oct. 2020
 *      Author: Sassone, Irina
 */

#ifndef GETTERS_H_
#define GETTERS_H_

int getInt(char* msg, char* errorMsg, int min, int max, int retries, int* result);
int getFloat(char* msg, char* errorMsg, int min, int max, int retries, int* result);
int getChar(char* msg, char* errorMsg, int min, int max, int retries, int* result);
int getString(char* msg, char* errorMsg, int min, int max, int retries, int* result);
int getName(char* msg, char* errorMsg, int min, int max, int retries, int* result);
int getLastName(char* msg, char* errorMsg, int min, int max, int retries, int* result);

#endif /* GETTERS_H_ */
