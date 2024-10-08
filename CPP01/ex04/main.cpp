/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:59:14 by ajorge-p          #+#    #+#             */
/*   Updated: 2024/10/08 13:07:25 by ajorge-p         ###   ########.fr       */
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



Swap:
std::string buyer ("money");
std::string seller ("goods");

buyer.swap(seller)

Find:
str.find("String to Find");

*/

#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char** argv)
{

	if(argc == 4)
	{
		fstream file;
		file.open(argv[1], ios::in);
		if(!file)
			cout << "File doesn't exist" << endl;
		else
		{
			ifstream inFile(argv[1]);
			string x;
			while(inFile >> x)
				cout << x << " ";
		}
		file.close();
	}
	else{
		cout << "Numero de Argumentos invalidos" << endl;
	}
}

