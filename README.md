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

ps: tenha piedade na correção, professor 😓

# Avaliação

1. Ler e validar os argumentos da linha de comando | 7 / 10
- faltou validar a ordem dos parâmetros

2. Ler e validar os dados da base de dados e armazená-los em uma classe apropriada | 7 / 10
- Embora sua classe suporte, você não fez uma implementação que suportasse que a base de dados tivesse diferentes colunas

3. Separar a interface textual das demais classes do sistema concentrando os couts e cins em um único objeto | 10 / 10
- ok

4. Implementação de uma classe para armazenar e validar o DNA de um indivíduo bem como realizar as operações de perfil | 5 / 10
- Como conversamos, o algoritmo não está 100%.

5. Implementação eficiente através do uso de referencias, quando você  julgar necessário | 6 / 10
- Vou penalizar neste quesito o fato de que todos os atributos são públicos mesmo você não acessando eles diretamente em muitos casos. Também
em alguns métodos você passa containers por parametro que deveriam ser referencias

## Demais quesitos (Critério | Peso)

1. Organização do código em src, include, data | 5 / 5

2. Documentação do código usando o padrão doxygen | 5 / 5

3. Implementação e documentação de arquivos de teste | 15 / 15
- Da forma como vc vem testando você realmente domina esse quesito, sugiro que invista um pouco em testes de software, é uma área promissora =).