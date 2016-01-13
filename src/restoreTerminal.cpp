#include "main.hh"

/**
 * Restore the terminal to its original state
 *
 * Precondition: None
 * Postcondition: The terminal is restored
 */
void restoreTerminal()
{
    ioctl(0, TCSETA, &(gl_env.line_backup));
}
