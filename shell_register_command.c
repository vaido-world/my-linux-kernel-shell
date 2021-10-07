#include <stdio.h>

#define shell_register_command(command_name) add_command(#command_name)
void add_command(char* command_name){
	 printf("Command to be registered: %s", command_name);
	
}


int main()
    {
    shell_register_command(shell_command_cd);
}