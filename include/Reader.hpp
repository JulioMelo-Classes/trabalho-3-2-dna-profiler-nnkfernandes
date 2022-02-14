#ifndef READER_HPP
#define READER_HPP


#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <list>

#include "CsvReader.hpp"

/**
* @brief A class to read and process the given dna sequence.
* @author Anny
*/
class Reader
{
  public:
    //this variable will store the given dna sequence extracted from file.
    std::string DNA;

    //this vector stores the positions of the STR AGAT sequence found in DNA.
    std::vector<int> AGAT_positions;

    //this vector stores the positions of the STR AATG sequence found in DNA.
    std::vector<int> AATG_positions;

    //this vector stores the positions of the STR TATC sequence found in DNA.
    std::vector<int> TATC_positions;

    //this vector is really important, it stores the quantities of each STR, in order we'll need.
    std::vector<int> STRS;

    /**
     * Constructor of Reader class.
     */
    Reader();
    
    /**
     * Given the path of txt file with a dna sequence,
     * this method access the content of file so the
     * string variable 'sequence' above.
     */
    std::string readDNA(std::string dna_path);

    /**
     * Search for repetitions of STR's in the given DNA sequence.
     * This is the DNA sequence that is passed by parameter as a 
     * txt file when you run the program.
     * 
     * @return a vector of integer, which each indec corresponds to
     * "AGAT, AATG, TATC" STR's, respectively.
     */
    std::vector<int> DNAProcess(std::string DNA);

    /**
     * Method to @return AGAT positions.
     */
    std::vector<int> getAGAT();

    /**
     * Method to @return AATG positions.
     */
    std::vector<int> getAATG();

    /**
     * Method to @return TATC positions.
     */
    std::vector<int> getTATC();

};

#endif