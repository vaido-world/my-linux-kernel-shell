int function(char * argument){
	printf("\na program function called. ");
	printf(argument);
	return 1212;
}

int main(){
	function("It's Regular function");
	
	int (*pointer_to_function) (char *) = &function;
	int returned = pointer_to_function("An actual Pointer function");
	printf("\nreturnedvalue: %i",returned);
	return 0;
}
