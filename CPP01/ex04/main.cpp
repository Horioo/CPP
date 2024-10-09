/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:59:14 by ajorge-p          #+#    #+#             */
/*   Updated: 2024/10/09 17:24:18 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Criar um programa que recebe 3 parametros (Ficheiro, 2 strings (s1,s2))

Vai abrir o ficheiro e copia o content para dentro de um ficheiro novo
Trocando todas as ocurrencias de s1 para s2

Nao se pode usar C file manipulation e std::string::replace

File Manipulation C++:

fstream library (#include <fstream>)
fstream FileName
FileName.open(nomedoficheiro, modo)
Ver(https://www.mygreatlearning.com/blog/file-handling-in-cpp/#GettingStarted)


Abrir Ficheiros
Copiar o conteudo do ficheiro para um buffer
Procurar str1 no buffer e trocar por str2
Mover a "agulha" para o ponto depois do str2 (found + 1)


Erase e insert - usar estes para fazer a troca das strings

Find:
str.find("String to Find");

*/

#include <iostream>
#include <fstream>

int main(int argc, char** argv)
{

	if(argc == 4)
	{
		std::fstream file;
		std::fstream replaceFile;
		std::string newFileName = argv[1];
		std::string tmp = argv[2];
		std::string tmp2 = argv[3];
		size_t found = 0;
		file.open(argv[1], std::ios::in);
		if(!file)
			std::cout << "File doesn't exist" << std::endl;
		else
		{
			std::string buffer;
			newFileName.append(".replace");
			//Usar o c.str() para converter o string para char *
			replaceFile.open(newFileName.c_str(),std::ios::out);
			if(!replaceFile)
				std::cerr << "Error opening File" << newFileName << std::endl;
			while(getline(file, buffer, '\0'))
			{
				found = buffer.find(tmp, found);
				while(found != std::string::npos)
				{
					buffer.erase(found, tmp.length());
					buffer.insert(found, tmp2);
					found = buffer.find(tmp, found + tmp2.length());
				}
				replaceFile << buffer;
			}
		}
		replaceFile.close();
		file.close();
	}
	else{
		std::cout << "Invalid Number of Arguments" << std::endl;
	}
}

