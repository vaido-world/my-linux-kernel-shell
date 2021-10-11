#include <stdio.h>

/* A simple function declaration */
void function(char * argument){
	printf("\na program function called. ");
	printf(argument);
}

/* A simple function declaration with return type */
int function_with_return_type(char * argument){
	printf("\na program function called. ");
	printf(argument);
	return 123456789;
}


void function_multiple_arguments(char * argument, char * argument2, int argument3){
	printf("\na program function called. ");
	printf(argument);
	printf(argument2);
	printf("%i", argument3);
}



/* __________MAIN FUNCTION___________*/
int main(){
	
	//____Regular function call____
	function("It's Regular function");
	
	
    /*                           Function variables declaration syntax
    	   function_return_type (*new_variable_name)(function_argument, function_argument..)
	*/  
	
	
	//____Pointer function call____
	void (*pointer_to_function) (char *);
	pointer_to_function = function; // alternative syntax:  pointer_to_function = &function;
	pointer_to_function("An actual Pointer function");

	

	
	
	return 0;
}