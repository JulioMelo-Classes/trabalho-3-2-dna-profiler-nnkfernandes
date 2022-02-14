# Projeto 3.2 da disciplina de Linguagem de Programação 1 - DNA-Profiler

## Executando o programa
* Passo 00 - Para gerar os arquivos iniciais de build, ao rodar o projeto pela primeira vez, use o seguinte comando no diretório raiz: 
> cmake -S ./ -B ./build

* Passo 01 - Para realizar o build do projeto e gerar o arquivo executável, estando em ./build/, use o seguinte comando: 
> cmake --build .

* Passo 02 - Para rodar o programa, utilize, estando em ./build/, o comando:
> ./dna-profiler ../data/data.csv ../data/sequence_alice.txt

ou

> ./dna-profiler ../data/data.csv ../data/sequence_bob.txt

ou

> ./dna-profiler ../data/data.csv ../data/sequence_charlie.txt

ou

> ./dna-profiler ../data/data.csv ../data/sequence_no_match.txt

* Passo 03 - Para testar o programa de forma automática, use o comando abaixo (estando em ./build/):
> ./all_tests

## Autoria

Anny Klarice Fernandes Souza
[anny.klarice.fernandes.127@ufrn.edu.br]
