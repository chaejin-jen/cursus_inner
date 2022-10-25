#include <iostream>
#include <fstream>

bool exists( const std::string& fileName );

int	main(int ac, char *av[])
{
	std::ifstream	ifs;
	std::ofstream	ofs;
	std::string		src;
	std::string		dst;

	if (ac != 3 || (!*av[1] || !*av[2])){
		std::cout << "error : arguments" << std::endl;
		return 1;
	}
	if (!exists("test00")){
		std::cout << "error : read-file not exists" << std::endl;
		return 1;
	}
	ifs.open("test01", std::ios::in);
	ifs >> dst;
	std::cout << dst << std::endl;
	ifs.close();


	ofs.open("test00.replace", std::ios::out | std::ios::trunc);

	ofs << "i like ponie a whole damn lot" << std::endl;
	ofs.close();

	// replace를 제외한 모든 std::string 클래스의 멤버 함수들을 사용 가능합니다. 현명하게 사용하세요!

	// 당연히, 에러는 최선을 다해 막아주어야 합니다. C 파일 관리 함수들을 불러오지 마세요. 이건 치팅이구요, 치팅은 나쁘잖아요. 오키?
}

bool exists( const std::string& fileName )
{
	std::ifstream infile(fileName.c_str());
	return infile.good();
}