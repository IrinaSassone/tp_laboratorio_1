/*
 * getters.c
 *
 *  Created on: 2 oct. 2020
 *      Author: Sassone, Irina
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"

#define STRING 4096

int getInt(char* msg, char* errorMsg, int min, int max, int retries, int* result) {
	int retorno=-1;
	int buffer;
	if(msg!= NULL && errorMsg!=NULL && result!=NULL && max>min && retries>0) {
		 do {
			 printf("%s", msg);
			 scanf("%d", &buffer);
			 if(isValidInt(buffer, min, max)) {
				 result=buffer;
				 retorno=0;
				 break;
			 }else{
				 printf("%s", errorMsg);
			 }
			 retries--;
		 }while(retries>0);
	}
	return retorno;
}

int getFloat(char* msg, char* errorMsg, int min, int max, int retries, int* result){
	int retorno=-1;
	int buffer;
	if(msg!= NULL && errorMsg!=NULL && result!=NULL && max>min && retries>0) {
		 do {
			 printf("%s", msg);
			 scanf("%f", &buffer);
			 if(isValidFloat(buffer, min, max)) {
				 *result=buffer;
				 retorno=0;
				 break;
			 }else{
				 printf("%s", errorMsg);
			 }
			 retries--;
		 }while(retries>0);
	}
	return retorno;
}

int getChar(char* msg, char* errorMsg, int min, int max, int retries, int* result) {
	int retorno=-1;
	int buffer;
	if(msg!= NULL && errorMsg!=NULL && result!=NULL && max>min && retries>0) {
		 do {
			 printf("%s", msg);
			 __fpurge(stdin); // fflush(stdin);
			 scanf("%c", &buffer);
			 if(isValidChar(buffer, min, max)) {
				 *result=buffer;
				 retorno=0;
				 break;
			 }else{
				 printf("%s", errorMsg);
			 }
			 retries--;
		 }while(retries>0);
	}
	return retorno;
}

int getString(char* msg, char* errorMsg, int min, int max, int retries, int* result) {
    int retorno=-1;
    char buffer[STRING];
	if(msg!= NULL && errorMsg!=NULL && result!=NULL && max>min && retries>0) {
        do {
            printf("%s",msg);
            fgets(buffer, sizeof(buffer), stdin);
            buffer[strlen(buffer)-1] = '\0';
            if(strlen(buffer)>min && strlen(buffer)<max) {
                strncpy(buffer, result, max);
                retorno=0;
                break;
            }
            retries--;
            printf("%s",errorMsg);
        }while(retries>0);
    }
    return retorno;
}

int getName(char* msg, char* errorMsg, int min, int max, int retries, int* result) {
    int retorno=-1;
    char buffer[STRING];
    if(msg!=NULL && errorMsg!=NULL && min<max && retries>0 && result!=NULL) {
        while(retorno==-1) {
            if(!getString(msg, errorMsg, min, max, retries, buffer)) {
                if(isValidName(buffer)) {
                    strncpy(result, buffer, max);
                    retorno=0;
                    break;
                }else{
                	retries--;
                	printf("%s", errorMsg);
                }
            }
        }
    }
    return retorno;
}

int getLastName(char* msg, char* errorMsg, int min, int max, int retries, int* result) {
    int retorno=-1;
    char buffer[STRING];
    if(msg!=NULL && errorMsg!=NULL && min<max && retries>0 && result!=NULL) {
        while(retorno==-1) {
            if(!getString(msg, errorMsg, min, max, retries, buffer)) {
                if(isValidLastName(buffer)) {
                    strncpy(result, buffer, max);
                    retorno=0;
                    break;
                }else{
                	retries--;
                	printf("%s", errorMsg);
                }
            }
        }
    }
    return retorno;
}
