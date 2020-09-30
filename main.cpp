#include <iostream>
#include <opencv2/opencv.hpp>
#include <libconfig.h++>

#include "utils.h"

int main(int argc, char **argv)
{
    // init config file
    if (argc < 2)
    {
        std::cerr << "[ERROR] Number of argumets is not enough!" << std::endl;
        return -1;
    }
    bool isRead = utls::initConfig(argv[1]);
    if(!isRead)
    {
        retrun -1;
    }
    


    std::cout << "\n\t***END PROGRAM!***" << std::endl;
}