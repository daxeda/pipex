#include "pipex.h"
#include <stdlib.h> // For exit function

void error_exit(const char *message, int exit_code)
{
    // Print an error message and exit with the specified exit code
    fprintf(stderr, "Error: %s\n", message);
    exit(exit_code);
}
