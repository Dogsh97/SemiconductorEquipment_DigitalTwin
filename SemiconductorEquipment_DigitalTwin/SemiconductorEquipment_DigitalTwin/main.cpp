#include "Logger.h"
#include <iostream>

int main()
{
    Logger logger;

    logger.Log("hi");
    logger.PrintHistory();
    logger.ResetHistory();

    return 0;
}