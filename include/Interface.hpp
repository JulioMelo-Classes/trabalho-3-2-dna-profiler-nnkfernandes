#ifndef INTERFACE_HPP
#define INTERFACE_HPP
#include "../include/CsvReader.hpp"
#include "../include/Reader.hpp"
#include <iostream>
#include <algorithm>

/**
* @brief A class to manage all the cins and couts.
* @author Anny
*/
class Interface
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
    //this vector stores the quantities of each STR, in order we'll need.
    std::vector<int> STRS;

    /**
     * Constructor of Interface class.
     */
    Interface();

    /**
     * Method to starr the program, it receive and parameters
     * the dna_path and csv_path.
     */
    void startProgram(std::string dna_path, std::string csv_path);
    
    /**
     * A messy method to print the representations of str sequences that
     * have a match on the database, just as it is shown in the example.
     * The logic behind it is: it transforms the indexes in a vector of pairs,
     * then it prins the first line with spaces to put it in the right positions
     * and the STR name with the total of STRs in the sequence.
     * After that it goes to the other line the ir prints the spaces to
     * also put it in the right position, then it print the `v` representing the found
     * position in the matched dna. 
     * After that it iterates complete DNA string and prints
     * letter by letter verifying if the position is in the range of matches
     * so it can be printed in green when it is in the range. 
     */ 
    void printResult();
    /**
     * Method to print the validation menssage when the user did not
     * provide files.
     */
    void printHelp();
};
#endif