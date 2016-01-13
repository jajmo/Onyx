#include "keylog.hh"

/**
 * Get the index in an array
 *
 * Precondition: None
 * Postcondition: The index is returned, or -1 if not found
 *
 * @param unsigned short &code The keyboard input code
 * @param int* values The array of keyboard input values
 * @param int size The size of the array
 * @return The index, or -1 if not found
 */
int Keylog::getIndex(unsigned short &code, int* values, int size)
{
    int count;

    for(count = 0; count < size; count++)
    {
        if(values[count] == code)
        {
            return count;
        }
    }

    return -1;
}
