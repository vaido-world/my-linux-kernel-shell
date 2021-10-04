/**
   @brief Loop getting input and executing it.
 */
void shell_command_loop(void)
{
  char *shell_line;
  char **shell_args;
  int shell_status;

  do {
    printf("> ");
    shell_line = lsh_read_line();
    shell_args = shell_split_line(shell_line);
    shell_status = lsh_execute(shell_args);

    free(shell_line);
    free(shell_args);
  } while (shell_status);
}
