#include "../include/CsvReader.hpp"

CsvReader::CsvReader(){};

void CsvReader::ReadCsv(std::string csv_path)
{
  std::ifstream file;
  //abrindo o arquivo csv
  file.open(csv_path);

  std::string line;

  if (file.is_open())
  {
    //descartando a primeira linha que é o header do csv
    getline(file, line);

    //notificando o usuário sobre o processamento de dados.
    std::cout<<"\033[1;37m[+] Processing data, please wait.\037 \n"<<std::endl;

    //percorrendo o arquivo linha por linha
    while (getline(file, line))
    {
      //dividindo a linha (que é uma string), em substrings, e armazenando
      //em um vetor de strings

      std::vector<std::string> substrings;
      std::string word;
      for(int i = 0; i <= line.size(); i++)
      {
        if(line[i] == ',' || i == line.size())
        {
          substrings.push_back(word);
          word = "";
        }
        else 
        {
          word = word + line[i];
        }
      }

      //acessando a posição do vetor de substrings gerado, 
      //podendo agora dividir o que é o nome e converter 
      //os dados dos STR's para inteiro e armazenar em um vetor de int,
      //que ficará atrelado ao nome da pessoa, em um pair.

      std::string name;
      std::vector<int> sequence;
      for(int i = 0; i < substrings.size(); i++)
      {
        if(i == 0)
        {
          name = substrings[0];
        }
        else
        {
          //tranformando o valor que era string em int
          std::stringstream ss;  
          ss << substrings[i]; 
          int num; 
          ss >> num;  
          //adicionando os valores na sequencia
          sequence.push_back(num);
        }
      }
      profiles.push_back(std::make_pair(name,sequence));
    }
    file.close();
  } 
}

bool CsvReader::findMatch(std::vector<int> STRS)
{ 
  int count_success = 0;

  for(int i = 0; i < profiles.size(); i++)
  { 
    //desmembrando um pouco essa estrutura pra ficar melhor de trabalhar
    //através de variáveis auxiliares, como aux_pair, por exemplo. 

    std::pair<std::string, std::vector<int> > aux_pair = profiles[i];
    std::vector<int> aux_vec = aux_pair.second; 

    for(int j = 0; j < 3; j++)
    {
      if(STRS[j] == aux_vec[j])
      {
        count_success++;
      }
    }

    if(count_success == 3)
    {
      match_name = aux_pair.first;
      return true;
    }

  }

  return false;
}

std::string CsvReader::getMatchName()
{
  //esse nome deve ser atribuido na funcao findMatch
  return match_name;
}



