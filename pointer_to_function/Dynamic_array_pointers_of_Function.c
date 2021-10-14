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
functionType *functions_calls_heap_dynamic_array;    
                          
int functions_calls_array_capacity_in_elements = 0; // initial capacity
int functions_calls_array_capacity_in_bytes = 0; // initial capacity
int functions_calls_array_initial_size = 0;   // initial size

int functions_names_array_capacity_in_elements = 0;
int functions_names_array_capacity_in_bytes = 0; //
int functions_names_array_initial_size = 0;   // 

void add_function_to_heap_dynamic_array(void * function_address){
	functions_calls_array_capacity_in_elements++;
	functions_calls_array_capacity_in_bytes = functions_calls_array_capacity_in_elements * sizeof(functionType);
	
    functions_calls_heap_dynamic_array = realloc(functions_calls_heap_dynamic_array, functions_calls_array_capacity_in_bytes);
    functions_calls_heap_dynamic_array[functions_calls_array_initial_size++] = function_address;  
	
	printf("functions_calls_array_capacity_in_elements %i\n", functions_calls_array_capacity_in_elements);
    printf("functions_calls_array_capacity_in_bytes: %i\n", functions_calls_array_capacity_in_bytes);
	
	
}



int main() {

  functions_calls_heap_dynamic_array = malloc(functions_calls_array_capacity_in_bytes);  // heap dynamic array, instead of stack static array; // dynamic array
  
  add_function_to_heap_dynamic_array(&declared_function);
  add_function_to_heap_dynamic_array(&declared_function2);
  
  functions_calls_heap_dynamic_array[0]("asd");
  functions_calls_heap_dynamic_array[1]("asd");

  free(functions_calls_heap_dynamic_array);
}
