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
int array_capacity = 0; // initial capacity
int array_capacity_in_bytes = 0; // initial capacity
int array_initial_size = 0;   // initial size

void add_to_heap_dynamic_array(void * function_address){
	array_capacity++;
	array_capacity_in_bytes=array_capacity * sizeof(functionType);
    functions = realloc(functions, array_capacity_in_bytes);
    functions[array_initial_size++] = function_address;  
	printf("array_capacity %i\n", array_capacity);
    printf("array_capacity_in_bytes: %i\n", array_capacity_in_bytes);
	
	
}



int main() {
  functions = malloc(array_capacity*sizeof(functionType));  // heap dynamic array, instead of stack static array; // dynamic array
  add_to_heap_dynamic_array(&declared_function);
  add_to_heap_dynamic_array(&declared_function2);
  functions[0]("asd");
  functions[1]("asd");

  free(functions);
}
