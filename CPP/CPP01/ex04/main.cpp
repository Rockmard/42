/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 01:41:38 by tpipi             #+#    #+#             */
/*   Updated: 2025/01/27 19:25:40 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <string>
#include <sys/stat.h>

static std::string	build_file(std::ifstream *file)
{
	std::string	line;
	std::string whole_file;
	while (std::getline(*file, line))
		whole_file.append(line + "\n");
	if (whole_file.size() > 0)
		whole_file.pop_back();
	return (whole_file);
}

static void replace(std::string file, std::ofstream *new_file, std::string s1, std::string s2)
{
	std::size_t	pos;
	std::size_t	i = 0;
	while (1) {
		pos = file.find(s1, i);
		if (pos == std::string::npos) {
			while (file[i])
			{
				*new_file << file[i];
				i++;
			}
			break ;
		}
		else
		{
			while (i < pos)
			{
				*new_file << file[i];
				i++;
			}
			*new_file << s2;
			i += s1.size();
		}
	}
}

int	sed(int ac, char **av)
{	
	struct stat 	s;

	if (ac != 4) {
		std::cerr << "Wrong usage - Inputs must be : <filename> <string_to_replace> <new_string>" << std::endl;
		return (1);
	}
	std::string	filePath = av[1];
	if (filePath.empty()) {
		std::cerr << "File name can't be empty" << std::endl;
		return (1);
	}
	std::string	s1 = av[2];
	if (s1.empty()) {
		std::cerr << "String to replace can't be empty" << std::endl;
		return (1);
	}
	std::string	s2 = av[3];
	if(stat(av[1], &s) == 0 && (s.st_mode & S_IFDIR)) {
		std::cerr << filePath << " leads to a directory" << std::endl;
		return (1);	
	}
	std::ifstream	file(filePath);
	if (!file.is_open()) {
		std::cerr << "Failed to open file : " << filePath << std::endl;
		return (1);
	}
	std::ofstream	new_file(filePath + ".replace");
	if (!new_file.is_open()) {
		std::cerr << "Failed to create new file : " << filePath + ".replace" << std::endl;
		file.close();
		return (1);
	}

	std::string whole_file = build_file(&file);
	replace(whole_file, &new_file, s1, s2);
	
	file.close();
	new_file.close();
	return (0);
}

int	main(int ac, char **av)
{
	int	res = 0;

	res = sed(ac, av);
	return (res);
}