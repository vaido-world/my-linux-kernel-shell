# pointer_function.md

A pointer function is a variable that points to a function.

![snapshot-1](https://user-images.githubusercontent.com/21064622/136799684-267cbc4c-3053-43b1-a6e0-303ffa831e54.png)



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

Annoation made with https://sourceforge.net/projects/hotshots/
