#define SHELL_READ_LINE_BUFFER_SIZE_IN_BYTES 1024
/**
   @brief Read a line of input from stdin.
   @return The line from stdin.
 */
char *shell_read_line(void)
{
  int line_buffer_size = SHELL_READ_LINE_BUFFER_SIZE_IN_BYTES;
  int line_token_position = 0;
  char *line_buffer = malloc(sizeof(char) * line_buffer_size);


  if (!line_buffer) {
    fprintf(stderr, "shell_main_read_command_line: allocation error [#555555]\n");
    exit(EXIT_FAILURE);
  }
  
  int loop_forever;

  do {
    int line_character = getchar();
	
	// If we hit EOF, replace it with a null line_character and return.
    if (line_character == EOF || line_character == '\n') {
      line_buffer[line_token_position] = '\0';
      return line_buffer;
    } 
	
	// line_character assignation
	line_buffer[line_token_position] = line_character;
	line_token_position++;
	
    // If we have exceeded the line_buffer, reallocate.
    if (line_token_position >= line_buffer_size) {
      line_buffer_size += SHELL_READ_LINE_BUFFER_SIZE_IN_BYTES;
      line_buffer = realloc(line_buffer, line_buffer_size);
      if (!line_buffer) {
        fprintf(stderr, "shell_main_read_command_line: allocation error [#666666]\n");
        exit(EXIT_FAILURE);
      }
    }
	  
  } while( loop_forever = 1 );
  
  
  
  

}