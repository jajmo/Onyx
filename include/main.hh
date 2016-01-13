#ifndef _MAIN_HH_
#define _MAIN_HH_

#include "global.hh"
#include "keylog.hh"
#include <iostream>
#include <signal.h>
#include <stdlib.h>
#include <sys/termios.h>
#include <termios.h>
#include <unistd.h>

using namespace std;

extern s_gl_env gl_env;

void restoreTerminal();
void runTests();
void setupTerminal();
void shutdown(int sig);
void usage();

#endif
