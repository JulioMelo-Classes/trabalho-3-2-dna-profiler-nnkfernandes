#include "../include/Interface.hpp"

Interface::Interface(){};

void Interface::startProgram(std::string dna_path, std::string csv_path)
{
  std::cout << "\033[1;37m=============================================\037" << std::endl;
  std::cout << "\033[1;37m   Welcome to the Basic DNA Profiler, v1.0   \037" << std::endl;
  std::cout << "\033[1;37m    Copyright (C) 2022, Anny K. Fernandes    \037" << std::endl;
  std::cout << "\033[1;37m=============================================\037\n"
            << std::endl;

  std::cout << "\033[1;34mThis program loads a DNA database and an unknown\nDNA sequence and tries to find a match between\nthe input DNA sequence and the DNA database.\033[0m\n"
            << std::endl;

  std::cout << "\033[1;37m[+] Preparing to read the DNA Database file [\037";
  std::cout << "\033[1;31m" << csv_path << "\037";
  std::cout << "\033[1;37m] \037" << std::endl;

  std::cout << "\033[1;37m[+] Preparing to read the DNA Database file [\037";
  std::cout << "\033[1;31m" << dna_path << "\037";
  std::cout << "\033[1;37m] \037" << std::endl;

  CsvReader csv;
  Reader dna;

  csv.ReadCsv(csv_path);
  DNA = dna.readDNA(dna_path);

  std::cout << "\033[1;37m[+] Input files successfully read.\037" << std::endl;

  std::vector<int> STRS = dna.DNAProcess(DNA);

  std::cout << "\033[1;37m[+] Searching in the database for a match... pease wait.\037 \n"
            << std::endl;
  if (csv.findMatch(STRS))
  {
    std::string name = csv.getMatchName();
    AGAT_positions = dna.getAGAT();
    AATG_positions = dna.getAATG();
    TATC_positions = dna.getTATC();

    std::cout << "\033[1;37mMatch ID (99.9%): " << name << "\037" << std::endl;
    std::cout << "\033[1;37mDNA Profile: \037" << std::endl;
    printResult();
  }
  else
  {
    std::cout << "\033[1;37m\n>>> Sorry, no match in our database.\037" << std::endl;
  }
}

bool comparePairOfInt(const std::pair<std::string, std::vector<int> > &a,
                      const std::pair<std::string, std::vector<int> > &b)
{
  return (a.second[0] < b.second[0]);
}

bool inRange(unsigned low, unsigned high, unsigned x)        
{        
 return (low <= x && x <= high);         
}    

void Interface::printResult()
{
  std::vector<std::pair<std::string, std::vector<int> > > all_positions;
  all_positions.push_back(std::make_pair("AGAT", AGAT_positions));
  all_positions.push_back(std::make_pair("AATG", AATG_positions));
  all_positions.push_back(std::make_pair("TATC", TATC_positions));

  std::sort(all_positions.begin(), all_positions.end(), comparePairOfInt);
  int previus_value = 0;
  for (int i = 0; i < all_positions.size(); i++)
  {
    for (int j = previus_value; j < all_positions[i].second[0]; j++)
    {
      std::cout << " ";
    }
    previus_value = all_positions[i].second[0] + 9;
    std::cout << all_positions[i].first << " [x" << all_positions[i].second.size() << "]";
  }
  std::cout << std::endl;
  previus_value = 0;
  for (int i = 0; i < all_positions.size(); i++)
  {
    for (int j = previus_value; j < all_positions[i].second[0]; j++)
    {
      std::cout << " ";
    }
    previus_value = all_positions[i].second[0] + all_positions[i].second[all_positions[i].second.size() - 1] - all_positions[i].second[0] + 4;
    for (int k = 0; k < all_positions[i].second[all_positions[i].second.size() - 1] - all_positions[i].second[0] + 4; k++)
    {
      std::cout << "v";
    }
  }
  std::cout << std::endl;
  std::vector<int> range1;
  std::vector<int> range2;
  std::vector<int> range3;
  range1.push_back(all_positions[0].second[0]);
  range1.push_back(all_positions[0].second[all_positions[0].second.size() - 1] + 3) ;
  range2.push_back(all_positions[1].second[0]);
  range2.push_back(all_positions[1].second[all_positions[1].second.size() - 1] + 3);
  range3.push_back(all_positions[2].second[0]);
  range3.push_back(all_positions[2].second[all_positions[2].second.size() - 1] + 3);
  for (int i = 0; i < DNA.size(); i++)
  {
    if(
        inRange(range1[0], range1[1], i) ||
        inRange(range2[0], range2[1], i) ||
        inRange(range3[0], range3[1], i)
    )
    {
      std::cout << "\033[1;32m" << DNA[i] << "\037";
      std::cout << "\033[1;37m\037";
    } else {
      std::cout << DNA[i];
    }
  }
  std::cout << std::endl;
}

void Interface::printHelp() {
  std::cout << "Usage: dna_profiler <database_file> <dna_sequence_file>" << std::endl;
  std::cout << "  Where the arguments are:" << std::endl;
  std::cout << "      <database_file>     The DNA database file." << std::endl;
  std::cout << "      <dna_sequence_file> The DNA sequence file you wish to identify (find a match for)." << std::endl;
}