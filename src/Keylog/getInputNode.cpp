#include "keylog.hh"

/**
 * Get the input node for the keyboard
 *
 * Precondition: The program is running as root
 * Postcondition: None
 *
 * @return string The full path to the input node
 */
string Keylog::getInputNode()
{
    string node;
    FILE* in;
    char buff[512];

    if(!(in = popen("grep -E 'Handlers|EV=' /proc/bus/input/devices | grep -B1 'EV=120013' | grep -Eo 'event[0-9]+'", "r")))
    {
        cout << "Unable to reliably determine input node" << endl;
        cout << "Using default device: " << INPUT_DEVICE << endl;
        node = INPUT_DEVICE;
    }
    else
    {
        fgets(buff, sizeof(buff), in);
        string nodeName(buff);
        nodeName.erase(remove(nodeName.begin(), nodeName.end(), '\n'), nodeName.end()); //Get rid of the newline at the end
        if(nodeName.size() == 0)
        {
            cout << "Unable to reliably determine input node" << endl;
            cout << "Using default device: " << INPUT_DEVICE << endl;
            node = INPUT_DEVICE;
        }
        else
        {
            node = "/dev/input/" + nodeName;
        }
    }

    return node;
}
