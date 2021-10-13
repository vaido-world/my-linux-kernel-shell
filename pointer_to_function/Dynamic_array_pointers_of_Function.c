// Resource: https://stackoverflow.com/questions/30277776/how-do-i-create-a-dynamic-array-of-function-pointers/30277817#30277817
// tcc -b -run Dynamic_array_pointers_of_Function.c
#include <stdio.h>
void declared_function(char *name){
	printf("\nI'm declared function");

}



#include <stdlib.h>


typedef void (*functionType)(char *);           
                          
functionType *functions; // dynamic array
	
void add_dynamic_array(){
	

	
  int capacity = 0;     // initial capacity
  int initial_size = 0;  // initial size
  functions = malloc(capacity*sizeof(functionType));  // heap dynamic array, instead of stack static array

  // ...

  // adding element and need more space
  if (initial_size >= capacity) {
	 capacity += 1;
     functions = realloc(functions, capacity * sizeof(functionType));
     functions[initial_size++] = &declared_function;
  }
  
printf("\n array_capacity %i", capacity);
functions[0]("asd");
	
	
}



int main() {




  add_dynamic_array();
  free(functions);
}