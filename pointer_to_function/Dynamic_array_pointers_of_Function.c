// Resource: https://stackoverflow.com/questions/30277776/how-do-i-create-a-dynamic-array-of-function-pointers/30277817#30277817
// tcc -b -run Dynamic_array_pointers_of_Function.c
#include <stdio.h>
void declared_function(char *name){
	printf("\nI'm declared function");

}

void declared_function2(char *name){
	printf("\nI'm Second declared function");

}



#include <stdlib.h>


typedef void (*functionType)(char *);           
                          
functionType *functions; // dynamic array

  int static capacity = 0;     // initial capacity
  int static initial_size = 0;  // initial size
	
void add_dynamic_array(void * function_address){
	

	

  functions = malloc(capacity*sizeof(functionType));  // heap dynamic array, instead of stack static array

  // ...

  // adding element and need more space
  if (initial_size >= capacity) {
	 capacity += 1;
     functions = realloc(functions, capacity * sizeof(functionType));
     functions[initial_size++] = function_address;
  }
  
printf("\n array_capacity %i", capacity);

	
	
}



int main() {




  add_dynamic_array(&declared_function);
  add_dynamic_array(&declared_function2);
  functions[1]("asd");
  free(functions);
}