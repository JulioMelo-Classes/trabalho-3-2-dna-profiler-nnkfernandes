#include "../include/Reader.hpp"
Reader::Reader(){};

std::string Reader::readDNA(std::string dna_path)
{
    std::ifstream file(dna_path);
    std::string line;
    if (file.is_open())
    {
      getline(file, line);

      DNA = line;

      file.close();
    }

    return DNA;

}
/**
 * Funtion to find a sequence of a given STR. The point of this
 * function is to be called only here, to help the findSTR function bellow.
 * This is the non recursive way to do that.
 * @return A vector with the STR sequence members indexes.
 */
std::vector<int> STRPositions(std::string DNA, std::string STR)
{
  std::vector<int> founded_positions;
  int lastfound = 0;
  while (DNA.find(STR, lastfound) != std::string::npos) {
    //vai começar sempre com 0 na posição 0 do founded_positions
    int pos = DNA.find(STR, lastfound);
    if (lastfound - 1 == pos - STR.size()) {
      if (founded_positions.size() == 0) {
        founded_positions.push_back(lastfound - 1);
      }
      founded_positions.push_back(pos);
    }
    lastfound = pos + 1;
  }
  return founded_positions;
}

std::vector<int> Reader::DNAProcess(std::string user_sequence)
{ 
  
  AGAT_positions = STRPositions(DNA, "AGAT");
  AATG_positions = STRPositions(DNA, "AATG");
  TATC_positions = STRPositions(DNA, "TATC");

  STRS.push_back(AGAT_positions.size());
  STRS.push_back(AATG_positions.size());
  STRS.push_back(TATC_positions.size());

  return STRS;
  
}

std::vector<int> Reader::getAGAT()
{
      return AGAT_positions;
}
std::vector<int> Reader::getAATG()
{
      return AATG_positions;
}
std::vector<int> Reader::getTATC()
{
      return TATC_positions;
}