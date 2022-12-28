// ref : pointer (address)를 string으로 저장해서 전송하기 https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=atelierjpro&logNo=221052456510

// 이해 못합... ptr_str : �����

#include <iostream>
#include <string>

int	main(void)
{
	int var = 1024;	// target variable
	// char *var = "1024";	// char variable
	std::cout << "variable : "  << var << std::endl;

	void *ptr_var = (void *)&var; // cast to void pointer

	std::cout << "ptr_var : " << ptr_var << std::endl;

	std::string	ptr_str;
	ptr_str.resize(sizeof(void *));
	sprintf(&ptr_str[0], (char *)&ptr_var);
	// sprintf(&ptr_str[0], "%d", *(int *)ptr_var);

	std::cout << "ptr_str : "  << ptr_str << std::endl;

	void *ptr_back = NullptrFT; // restore void pointer from string (초기화 중요)
	sprintf((char *)&ptr_back, ptr_str.c_str());

	std::cout << "ptr_back : "  << ptr_back << std::endl;

	int *int_ptr_back = (int *)ptr_back; // cast void pointer to int pointer again
	*int_ptr_back = 2048;
	// char **char_ptr_back = (char **)&ptr_back; // cast void pointer to int pointer again
	// *char_ptr_back = "2048";

	std::cout << "variable : "  << var << std::endl;
}
