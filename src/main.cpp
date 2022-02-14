#include <iostream>
#include "../include/CsvReader.hpp"
#include "../include/Reader.hpp"
#include "../include/Interface.hpp"


int main(int argc, char *argv[])
{   
    //validation of args
    Interface interface;
    if(argc < 3) {
        interface.printHelp();
        return 0;
    }
    std::string csv_path = argv[1];
    std::string dna_path = argv[2];
    

    interface.startProgram(dna_path, csv_path);

    return 0;

}