/***************************************************************************//**

  @file         main.c

  @author       Stephen Brennan

  @date         Thursday,  8 January 2015

  @brief        LSH (Libstephen SHell)

*******************************************************************************/

#include "shell_headers.h"

/*
  Function Declarations for builtin shell commands:
 */
int shell_builtin_command_cd(char **args);
int shell_builtin_command_help(char **args);
int shell_builtin_command_exit(char **args);

/*
  List of builtin commands, followed by their corresponding functions.
 */
char *shell_builtin_command_list[] = {
  "cd",
  "help",
  "exit"
};

/*

The next part is an array of builtin command names, followed by an array of their corresponding functions. This is so that, in the future, builtin commands can be added simply by modifying these arrays, rather than editing a large “switch” statement somewhere in the code. If you’re confused by the declaration of builtin_func, that’s OK! I am too. It’s an array of function pointers (that take array of strings and return an int). Any declaration involving function pointers in C can get really complicated. I still look up how function pointers are declared myself!1
*/

/* Corresponding shell pointers to the commands below */
/*On return in shell_execute.c, the functions are executed by a pointer adressses & */

/*Array of pointers pointing to builtin shell functions*/
// https://stackoverflow.com/questions/252748/how-can-i-use-an-array-of-function-pointers

// https://stackoverflow.com/questions/5488608/how-define-an-array-of-function-pointers-in-c/5488718#5488718
// https://www.ibm.com/docs/en/zos/2.2.0?topic=functions-pointers



// Points to char array and returns int

// Adds "pointers to functions that take char** as arguments" to an array shell_array_pointing_builtin_functions[] 
int (*shell_array_pointing_builtin_functions[]) (char **) = {
  &shell_builtin_command_cd,
  &shell_builtin_command_help,
  &shell_builtin_command_exit
};

int count_shell_number_builtins() {
  return sizeof(shell_builtin_command_list) / sizeof(char *);
}

int return_count_shell_number_builtins_calls() {
  return sizeof(shell_array_pointing_builtin_functions) / sizeof(char *);
}

/*
  Builtin function implementations.
*/

/**
   @brief Bultin command: change directory.
   @param args List of args.  args[0] is "cd".  args[1] is the directory.
   @return Always returns 1, to continue executing.
 */
int shell_builtin_command_cd(char **args)
{
  printf("%s", __func__);
  if (args[1] == NULL) {
    fprintf(stderr, "lsh: expected argument to \"cd\"\n");
  } else {
    if (chdir(args[1]) != 0) {
      perror("lsh");
    }
  }
  return 1;
}

/**
   @brief Builtin command: print help.
   @param args List of args.  Not examined.
   @return Always returns 1, to continue executing.
 */
int shell_builtin_command_help(char **args)
{
  int i;
  printf("Public Domain Shell by a cooked egg\n");
  printf("Type program names and arguments, and hit enter.\n");
  printf("The following are built in:\n");

  for (i = 0; i < count_shell_number_builtins(); i++) {
    printf("  %s\n", shell_builtin_command_list[i]);
  }

  printf("Use the man command for information on other programs.\n");
  return 1;
}

/**
   @brief Builtin command: exit.
   @param args List of args.  Not examined.
   @return Always returns 0, to terminate execution.
 */
int shell_builtin_command_exit(char **args)
{
  return 0;
}


#include "shell_main_execute.c"
#include "shell_main_read_command_line.c"
#include "shell_main_split_command_line.c"
#include "shell_main_command_loop.c"
/*Reverse dependecy: lowest include is most depenant on the others above*/

/**
   @brief Main entry point.
   @param argc Argument count.
   @param argv Argument vector.
   @return status code
 */
int main(int argc, char **argv)
{
	
	
	printf("%i commands are available", return_count_shell_number_builtins_calls());
	shell_array_pointing_builtin_functions[return_count_shell_number_builtins_calls() +1] = &shell_builtin_command_exit;
	printf("%i commands are available", return_count_shell_number_builtins_calls());
	
	
/*
  int i;
  char str[200];
  for (i = 0; i < count_shell_number_builtins(); i++) {

 
	
    printf("%s\n", *shell_array_pointing_builtin_functions[i]);
    }
*/ 	
	
  // Load config files, if any.

  // Run command loop.
  shell_command_loop();

  // Perform any shutdown/cleanup.

  return EXIT_SUCCESS;
}
