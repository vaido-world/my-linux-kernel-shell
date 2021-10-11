# pointer_function.md

A pointer function is a variable that points to a function.

### Syntax
`function_return_type (*new_variable_name)(function_argument, function_argument..) = &name_of_the_function;`  
`int (*example1)(int, char *) = &func`  
Ampersand is not required and is only for readability.

### Simple pointer pointing to function example

```
void function(char * argument){
	printf("\na program function called. ");
	printf(argument);
}

int main(){
	function("It's Regular function");
	
	//____Pointer function call____
	void (*pointer_to_function) (char *) = &function;
	pointer_to_function("An actual Pointer function");
	
	return 0;
}


```

Output:
```
a program function called. It's Regular function
a program function called. An actual Pointer function
```
![snapshot](https://user-images.githubusercontent.com/21064622/136798780-f6348f9d-51f9-49b3-9876-a34b21f4673b.png)

