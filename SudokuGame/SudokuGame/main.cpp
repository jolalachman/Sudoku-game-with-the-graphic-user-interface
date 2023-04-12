#include "Interface.h"
#include <windows.h>
#include <string>

int main()
{
    int option = 0;
    Interface sudokuInterface;
    sudokuInterface.login();
    sudokuInterface.newSudoku();
    while (option != 3)
    {
        std::cin >> option;

        switch (option)
        {
        case 1:
        {
            sudokuInterface.addNumber();
            if (sudokuInterface.isComplete())
            {
                sudokuInterface.winSudoku();
                std::cin >> option;
                if (option == 1)
                    sudokuInterface.reloadSudoku();
                else
                {
                    sudokuInterface.endSudoku();
                    option = 3;
                }
            }
            break;
        }

        case 2:
        {
            sudokuInterface.reloadSudoku();
            break;

        }
        case 3:
        {
            sudokuInterface.endSudoku();
            break;
        }
        case 4:
        {
            sudokuInterface.cheat();
            break;
        }
        default:
        {
            break;
        }
        }

    }
    return 0;

}