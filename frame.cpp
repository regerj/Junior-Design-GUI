#include "frame.h"

// Frame constructor
frame::frame()
{
    // Triple for loop that instantiates the array as
    // all 'x' which represents OFF.
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            for(int k = 0; k < 8; k++)
            {
                array[i][j][k] = 'x';
            }
        }
    }
}

// Transmit a frame to the arduino handler function.
void frame::transmit()
{
    // Open the comm port with permissions.
    std::cout << "Opeining comm port" << std::endl;
    HANDLE hComm;
    hComm = CreateFileA("\\\\.\\COM1", GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);

    // Error handle if comm port was not opened correctly.
    if(hComm == INVALID_HANDLE_VALUE)
    {
        std::cout << "Invalid handle value" << std::endl;
        CloseHandle(hComm);
        return;
    }

    // Bool to check if write to comm port was successful
    bool status;

    // Triple for loop that writes every char in the array to the comm port
    // and also writes it to a file for debugging purposes. It is denoted.
    for(int i = 0; i < 8; i++)
    {
        char temp[10];                                                                  // Temp buffer
        sprintf(temp, "Plane %d\n", i);                                                 // Fill buffer with incrementing plane count
        outputFile.write(temp, 8);                                                      // Write plane count
        for(int j = 0; j < 8; j++)                                                      // Second for loop
        {
            for(int k = 0; k < 8; k++)                                                  // Third for loop
            {
                status = WriteFile(hComm, (LPCVOID)&array[k][j][i], 1, NULL, NULL);     // Write the current array char to the comm port
                outputFile.write(&array[k][j][i], 1);                                   // Write it to the file as well
                outputFile.write("   ", 3);                                             // Style

                // Debug stuff
                if(status)
                {
                    //std::cout << "Write Successful" << std::endl;
                }
                else
                    std::cout << "Write Failed" << std::endl;

            }
            outputFile.write("\n", 1);                                                  // Output file style
        }
        outputFile.write("\n", 1);                                                      // Output file style
    }

    std::cout << "Write complete" << std::endl;

    // Close handle to comm port
    CloseHandle(hComm);

    return;
}
