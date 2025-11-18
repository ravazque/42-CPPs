/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 03:17:19 by ravazque          #+#    #+#             */
/*   Updated: 2025/11/18 03:27:01 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>

typedef std::string string;

void replaceString(string &content, const string &s1, const string &s2)
{
    size_t pos = 0;
    
    while ((pos = content.find(s1, pos)) != string::npos)
    {
        content.erase(pos, s1.length());
        content.insert(pos, s2);
        pos += s2.length();
    }
}

int main (int argc, char *argv[])
{
	if (argc != 4)
	{
        std::cerr << "Please enter: " << argv[0] << " <filename> <string1> <string2>" << std::endl;
        return (1);
    }

    string file = argv[1];
    string s1 = argv[2];
    string s2 = argv[3];

    std::ifstream inputFile(file.c_str());
    if (!inputFile)
    {
        std::cerr << "Error: Could not open file " << file << std::endl;
        return (1);
    }
    
    std::string contentoffile((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());
    inputFile.close();

    replaceString(contentoffile, s1, s2);

    std::ofstream file2((file + ".replace").c_str());
    
    if (!file2)
    {
        std::cerr << "Error: Could not create output file " << file << ".replace" << std::endl;
        return 1;
    }

    file2 << contentoffile;
    file2.close();

    return (0);
}
