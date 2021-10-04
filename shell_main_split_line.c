#define SHELL_LINE_TOKEN_BUFFER_SIZE_IN_BYTES 64
#define SHELL_LINE_TOKEN_DELIMITER " \t\r\n\a"
/**
   @brief Split a line into line_tokens (very naively).
   @param line The line.
   @return Null-terminated array of line_tokens.
 */
char **shell_split_line(char *line)
{
  int line_buffer_size = SHELL_LINE_TOKEN_BUFFER_SIZE_IN_BYTES;
  int line_token_position = 0;
  char **line_tokens = malloc(line_buffer_size * sizeof(char*));
  char *line_token;

  if (!line_tokens) {
    fprintf(stderr, "lsh: allocation error\n");
    exit(EXIT_FAILURE);
  }

  line_token = strtok(line, SHELL_LINE_TOKEN_DELIMITER);
  while (line_token != NULL) {
    line_tokens[line_token_position] = line_token;
    line_token_position++;

    if (line_token_position >= line_buffer_size) {
      line_buffer_size += SHELL_LINE_TOKEN_BUFFER_SIZE_IN_BYTES;
      line_tokens = realloc(line_tokens, line_buffer_size * sizeof(char*));
      if (!line_tokens) {
        fprintf(stderr, "shell_split_line: allocation error [source_code_error_number: 28034545]\n");
        exit(EXIT_FAILURE);
      }
    }

    line_token = strtok(NULL, SHELL_LINE_TOKEN_DELIMITER);
  }
  line_tokens[line_token_position] = NULL;
  return line_tokens;
}
