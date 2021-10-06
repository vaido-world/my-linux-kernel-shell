
/**
   @brief Execute shell built-in or launch program.
   @param args Null terminated list of arguments.
   @return 1 if the shell should continue running, 0 if it should terminate
 */
int shell_execute(char **args)
{
  int i;

  if (args[0] == NULL) {
    // An empty command was entered.
    return 1;
  }

  for (i = 0; i < count_shell_number_builtins(); i++) {
    if (strcmp(args[0], shell_builtin_command_list[i]) == 0) {
      return (*shell_array_pointing_builtin_functions[i])(args); // Selects and executes from pointer list pointing to  builtin functions
    }
  }

  return lsh_launch(args);
}
