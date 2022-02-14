#include <iostream>
#include "../include/CsvReader.hpp"
#include "../include/Reader.hpp"
#include "../include/Interface.hpp"

#include "../test_manager/include/test_manager.h"
/**
* @brief this test uses alice and chalie files and verify the expected results. 
* @author Anny
*/
int main()
{
  Interface interface;

  TestManager tm{"Interator Template Tests"};

  std::cout << "running tests" << std::endl;

  {
    BEGIN_TEST(tm, "Test alice sequence", "Input: data.csv and sequence_alice.txt; Test if returns the right positions.");
    CsvReader csv;
    Reader dna;

    csv.ReadCsv("../data/data.csv");
    string DNA = dna.readDNA("../data/sequence_alice.txt");

    std::vector<int> STRS = dna.DNAProcess(DNA);
    std::vector<int> AGAT_positions;
    std::vector<int> AATG_positions;
    std::vector<int> TATC_positions;

    std::vector<int> expected_result1;
    std::vector<int> expected_result2;
    std::vector<int> expected_result3;

      AGAT_positions = dna.getAGAT();
      AATG_positions = dna.getAATG();
      TATC_positions = dna.getTATC();

      expected_result1.push_back(65);
      expected_result1.push_back(69);
      expected_result1.push_back(73);
      expected_result1.push_back(77);
      expected_result1.push_back(81);
      expected_result2.push_back(101);
      expected_result2.push_back(105);
      expected_result3.push_back(17);
      expected_result3.push_back(21);
      expected_result3.push_back(25);
      expected_result3.push_back(29);
      expected_result3.push_back(33);
      expected_result3.push_back(37);
      expected_result3.push_back(41);
      expected_result3.push_back(45);

    EXPECT_TRUE( equal(AGAT_positions.begin(), AGAT_positions.end(), expected_result1.begin()), "At main.cpp line " + std::to_string(__LINE__));
    EXPECT_TRUE( equal(AATG_positions.begin(), AATG_positions.end(), expected_result2.begin()), "At main.cpp line " + std::to_string(__LINE__));
    EXPECT_TRUE( equal(TATC_positions.begin(), TATC_positions.end(), expected_result3.begin()), "At main.cpp line " + std::to_string(__LINE__));
  }
  {
    BEGIN_TEST(tm, "Test charlie sequence", "Input: data.csv and sequence_charlie.txt; Test if returns the right positions.");
    CsvReader csv;
    Reader dna;

    csv.ReadCsv("../data/data.csv");
    string DNA = dna.readDNA("../data/sequence_charlie.txt");

    std::vector<int> STRS = dna.DNAProcess(DNA);
    std::vector<int> AGAT_positions;
    std::vector<int> AATG_positions;
    std::vector<int> TATC_positions;

    std::vector<int> expected_result1;
    std::vector<int> expected_result2;
    std::vector<int> expected_result3;

      AGAT_positions = dna.getAGAT();
      AATG_positions = dna.getAATG();
      TATC_positions = dna.getTATC();

      expected_result1.push_back(13);
      expected_result1.push_back(17);
      expected_result1.push_back(21);
      expected_result2.push_back(47);
      expected_result2.push_back(51);
      expected_result2.push_back(55);
      expected_result2.push_back(59);
      expected_result2.push_back(63);
      expected_result2.push_back(67);
      expected_result2.push_back(71);
      expected_result3.push_back(104);
      expected_result3.push_back(108);
      expected_result3.push_back(112);
      expected_result3.push_back(116);
      expected_result3.push_back(120);

    EXPECT_TRUE( equal(AGAT_positions.begin(), AGAT_positions.end(), expected_result1.begin()), "At main.cpp line " + std::to_string(__LINE__));
    EXPECT_TRUE( equal(AATG_positions.begin(), AATG_positions.end(), expected_result2.begin()), "At main.cpp line " + std::to_string(__LINE__));
    EXPECT_TRUE( equal(TATC_positions.begin(), TATC_positions.end(), expected_result3.begin()), "At main.cpp line " + std::to_string(__LINE__));
  }

  tm.summary();
  return 0;
}