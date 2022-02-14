#ifndef CSVREADER_HPP
#define CSVREADER_HPP

#include "Reader.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include<cstring>
#include <sstream>


/**
* @brief A class to read and process the csv file and its data.
* @author Anny
*/
class CsvReader
{
  public:

    /**
     * Constructor of CsvReader class.
     */
    CsvReader();

    /**
     * Method that opens the csv file, and processing the data to 
     * generate pairs with the NAME and the a vector of integer that represents
     * the STRs sequences we need, just like they are in the csv file.
     * It fills the `profiles` vector.
     */
    void ReadCsv(std::string csv_path);
    
    //I'll use this to verify if the user's STRs match.
    std::vector<std::pair<std::string, std::vector<int> > > profiles;
    
    //name of user that matched the dna sequence, it is usefull to print in the interface.
    std::string match_name;

    /**
     * Method to @return the match_name, so it can be printed in the interface.
     */
    std::string getMatchName();

    /**
     * It receives as parameter a vector of the quantities of founded STR sequences, just like 
     * the format that is linked in the database every profile. so, it is a vector of integers.
     * It will verify if the given STRS matches with any of the profiles.
     * @return true if there is a match, and false if there is not a match.
     */
    bool findMatch(std::vector<int> STRS);

};
#endif