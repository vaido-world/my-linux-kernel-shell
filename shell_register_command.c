#include <stdio.h>
#include <string.h>

#define shell_register_command(command_name) add_command(#command_name)
void add_command(char* command_name){
    printf("Command to be registered: %s", command_name);
	
	char *last = strrchr(command_name, '_');
	if (last != NULL) {
		printf("\nLast token: '%s'\n", last+1);
	}

	
}


int main()
    {
    shell_register_command(shell_command_cd);
	

	
	
}