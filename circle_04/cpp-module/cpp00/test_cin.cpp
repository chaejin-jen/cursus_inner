#include <iostream>

using namespace std;

int	main(void)
{
	string str;

	cout << "\"input : exit\" will program exit" << endl;
	while (1)
	{
		cout << "input : ";
		cin >> str ;
		if (str == "exit")
			break ;
		cout << "str 1 : " << str << endl;
	}

	return 0;
}
