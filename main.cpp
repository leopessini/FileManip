#include <iostream>
#include <string>
#include <vector>
#include <fstream>

void mostrarDiferentes(std::vector<std::string>& vt1, std::vector<std::string>& vt2)
{
    for(int i = 0; i < vt1.size(); ++i)
    {
        bool achou = false;

        for(int j = 0; j < vt2.size(); ++j)
        {
            if(vt1.at(i) == vt2.at(j)) { achou = true; break; }
        }

        if(achou == false) { std::cout<< vt1.at(i) <<std::endl; }
    }
}

bool lerArquivo(std::string nomeArq, std::vector<std::string>& dadosDestino, size_t ctr = 0)
{
    std::ifstream arquivo(nomeArq);
    if(!arquivo.is_open()) { return false; }

    std::string linhaDoArq;

    while(std::getline(arquivo,linhaDoArq))
    {
        linhaDoArq = linhaDoArq.substr(ctr);
        dadosDestino.push_back(linhaDoArq);
    }

    arquivo.close();
    return true;
}

bool argumentosValidos(const int& argc)
{
    if(argc != 3)
    {
        std::cout << "quantidade de argumentos invalidos!\n";
        std::cout << "o programa deve receber 2 nomes de arquivos por argumento de linha de comando"<< std::endl;
        return false;
    }
    return true;
}

inline void mensagemErroArquivo(std::string nomeArquivo)
{
    std::cout << "erro ao abrir tentar abrir o arquivo: "<< nomeArquivo << std::endl;
}

int main(int argc, char* nomeArquivo[])
{
    if( !argumentosValidos(argc) ) { return 1; }

    std::string nomeArq1 = nomeArquivo[1];
    std::string nomeArq2 = nomeArquivo[2];
    std::vector<std::string> dados1, dados2;

    if( !lerArquivo(nomeArq1, dados1, 2) ) { 
        mensagemErroArquivo(nomeArq1);
        return 1; 
    }

    if( !lerArquivo(nomeArq2, dados2) ){ 
        mensagemErroArquivo(nomeArq2);
        return 1; 
    }
    
    mostrarDiferentes(dados1, dados2);
}