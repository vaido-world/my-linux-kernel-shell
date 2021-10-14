// Resource: https://stackoverflow.com/questions/30277776/how-do-i-create-a-dynamic-array-of-function-pointers/30277817#30277817
// TODO: https://levelup.gitconnected.com/alternatives-to-global-variables-34982becfcc
// tcc -b -run Dynamic_array_pointers_of_Function.c
#include <stdio.h>
#include <stdlib.h>

void declared_function(char *args){
	printf("I'm declared function\n");

}

void declared_function2(char *args){
	printf("I'm Second declared function \n");

}


typedef void (*functionType)(char *);  
functionType *functions;    
                          
int commands_array_capacity_in_elements = 0; // initial capacity
int commands_array_capacity_in_bytes = 0; // initial capacity
int commands_array_initial_size = 0;   // initial size

void add_to_heap_dynamic_array(void * function_address){
	commands_array_capacity_in_elements++;
	commands_array_capacity_in_bytes=commands_array_capacity_in_elements * sizeof(functionType);
	
    functions = realloc(functions, commands_array_capacity_in_bytes);
    functions[commands_array_initial_size++] = function_address;  
	
	printf("commands_array_capacity_in_elements %i\n", commands_array_capacity_in_elements);
    printf("commands_array_capacity_in_bytes: %i\n", commands_array_capacity_in_bytes);
	
	
}



int main() {
  commands_array_capacity_in_bytes=commands_array_capacity_in_elements * sizeof(functionType);
  functions = malloc(commands_array_capacity_in_bytes);  // heap dynamic array, instead of stack static array; // dynamic array
  
  add_to_heap_dynamic_array(&declared_function);
  add_to_heap_dynamic_array(&declared_function2);
  
  functions[0]("asd");
  functions[1]("asd");

  free(functions);
}
