#include "pipex.h"
#include <stdlib.h> // For exit function

void exit_with_error(const char *message, int exit_code)
{
    // Print an error message and exit with the specified exit code
    fprintf(stderr, "Error: %s\n", message);
    exit(exit_code);
}
