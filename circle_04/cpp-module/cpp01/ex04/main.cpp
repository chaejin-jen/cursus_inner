#include <iostream>
#include <fstream>
#include <string>

static int	check_argv(char **av);
static int	open_ifs_ofs(std::ifstream &ifs, std::ofstream &ofs, std::string filename);
static int	write_replace(std::ifstream &ifs, std::ofstream &ofs, char *s1, char *s2);
static void	getlines(std::ifstream &ifs, std::string &str, int cnt);
static std::string &replacelines(std::string &str, const std::string &src, const std::string &dst);

int	main(int ac, char *av[])
{
	std::ifstream	ifs;
	std::ofstream	ofs;

	if (ac != 4 || check_argv(av) != 0)
		return (1);
	if (open_ifs_ofs(ifs, ofs, av[1]) != 0)
		return (1);
	if (write_replace(ifs, ofs, av[2], av[3]) != 0)
		return (1);
	ifs.close();
	ofs.close();
	return (0);
}

static int	check_argv(char **av){
	if (!*av[1] || !*av[2] ||!*av[3]){
		std::cerr << "error : arguments" << std::endl;
		return 1;
	}
	return 0;
}

static int	open_ifs_ofs(std::ifstream &ifs, std::ofstream &ofs, std::string filename){
	ifs.open(filename, std::ios::in);
	if (ifs.is_open() == false){
		std::cerr << "error : open failed (read-file)" << std::endl;
		return 1;
	}
	ofs.open(std::string(filename) + ".replace", std::ios::out | std::ios::trunc);
	if (ofs.is_open() == false){
		std::cerr << "error : open failed (write-file)" << std::endl;
		return 1;
	}
	return 0;
}

static int	write_replace(std::ifstream &ifs, std::ofstream &ofs, char *s1, char *s2){
	std::string	src(s1);
	std::string	dst(s2);
	int	newline_cnt(0);

	for (std::string::iterator it = src.begin(); it != src.end(); it++){
		if (*it == '\n')
			newline_cnt++;
	}
	while (!ifs.eof()){
		std::string	lines;
		getlines(ifs, lines, newline_cnt);
		ofs << replacelines(lines, src, dst);
		if (ofs.fail()){
			std::cerr << "error : write failed" << std::endl;
			return 1;
		}
	}
	return (0);
}

static void	getlines(std::ifstream &ifs, std::string &lines, int cnt){
	if (cnt == 0){
		getline(ifs, lines);
		if (ifs.eof() == false)
			lines += "\n";
		return ;
	}
	for (int i = -1; i != cnt; i++){
		std::string	line;
		getline(ifs, line);
		lines += line;
		if (ifs.eof() == false)
			lines += "\n";
		else
			break;
	}
}

static std::string &replacelines(std::string &lines, const std::string &src, const std::string &dst)
{
	std::string	tmp(lines);

	for (std::string::iterator it = tmp.begin(); it != tmp.end(); it++){
		if (std::string(it, tmp.end()).find(src) == 0){
			lines = std::string(tmp.begin(), it) + dst + std::string(it + src.length(), tmp.end());
			tmp = lines;
		}
	}
	return lines;
}
