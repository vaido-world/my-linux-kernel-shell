// tcc -b -run heap_dynamic_array_strings.c
#include <stdio.h>
#include <stdlib.h>

void main(){

	size_t termination_symbol_size = 1;
	char * string;
	char * initialcharacters = "Carla_";


	string = malloc(strlen(initialcharacters) + termination_symbol_size);
	strcpy(string, initialcharacters);
	
	char * newcharacters = "$$$$$";
	
	string = realloc(string, strlen(newcharacters) + strlen(initialcharacters) + termination_symbol_size);
	strcat(string, newcharacters);
	
	printf(string);
	free(string);
}