#include <stdio.h>
#include <string.h>

#define shell_register_command(command_name) add_command(#command_name)
void add_command(char* command_name){
    printf("Command to be registered: %s", command_name);
	
	char *last_token = strstr(command_name, "command_");
	if (last_token != NULL) {
		printf("\nLast token: '%s'\n", last_token+strlen("command_"));
	}
	
	int command_pointer_address = &command_name;
	printf("\nIs the function declared?: '%i'\n", command_pointer_address);
	
}

void shell_command_cd(){
	
	printf("yes");
}



int main()
    {
	// shell_convert_builtin_function_to_command
    shell_register_command(shell_builtin_command_cd_test);
    shell_register_command(shell_command_goto);
	shell_register_command(shell_command_gotos);

	
	
}