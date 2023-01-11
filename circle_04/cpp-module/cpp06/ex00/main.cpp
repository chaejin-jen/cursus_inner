#include "Convert.hpp"

int main(int argc, char *argv[]){
	if (argc != 2){ //|| *argv[1] == 0){
		std::cerr << "error : arguments\n[hint] ./convert <literal>" << std::endl;
		return 1;
	}

	Convert cvt(argv[1]);

	cvt.putChar();
	cvt.putInt();
	cvt.putFloat();
	cvt.putDouble();
	//1.798E+308

	return 0;
}
