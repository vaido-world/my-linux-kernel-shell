// tcc -b -run heap_dynamic_array_dynamic_strings.c
#include <stdio.h>
#include <stdlib.h>

void main(){

	size_t termination_symbol_size = 1;
	char * dynamic_string;
	char * initialcharacters = "Carla_";


	dynamic_string = malloc(strlen(initialcharacters) + termination_symbol_size);
	strcpy(dynamic_string, initialcharacters);
	
	char * newcharacters = "$$$$$";
	
	dynamic_string = realloc(dynamic_string, strlen(newcharacters) + strlen(initialcharacters) + termination_symbol_size);
	strcat(dynamic_string, newcharacters);
	
	printf(dynamic_string);
	free(dynamic_string);
}