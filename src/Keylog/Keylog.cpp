#include "keylog.hh"

/**
 * Create a new keylog instance
 *
 * Precondition: file is not null
 * Postcondition: The filewriter is instantiated
 *
 * @param const char* file The output file name
 * @param bool verbose If verbose output is required or not
 */
Keylog::Keylog(const char* file, bool verbose)
{
    const char* inputNode;

    inputNode = getInputNode().c_str();

    if((this->inputFd = open(inputNode, O_RDONLY)) < 0)
    {
        cerr << "Error opening input device " << inputNode;
        exit(1);
    }

    this->verbose = verbose;

    if(file != NULL)
    {
        this->fileOutput = new FileWriter(file);
        this->writer = true;
    }
    else
    {
        this->writer = false;
    }
}
