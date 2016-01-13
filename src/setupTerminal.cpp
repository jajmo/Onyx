#include "main.hh"

/**
 * Disable ECHO for the terminal using termcaps
 *
 * Precondition: None
 * Postcondition: ECHO is disabled
 */
void setupTerminal()
{
    struct termio modify;

    ioctl(0, TCGETA, &(gl_env.line_backup));
    modify = gl_env.line_backup;

    modify.c_lflag &= ~(ECHO | ICANON);

    ioctl(0, TCSETA, &modify);
}
