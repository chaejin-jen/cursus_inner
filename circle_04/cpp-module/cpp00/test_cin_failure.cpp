#include <iostream>

using namespace std;

int	main(void)
{
	string str;

	cout << "\"input : exit\" will program exit" << endl;
	while (1){
		//cout << "input : ";
		if (cin >> str){
			if (str.empty())
				cout << "!str empty!" << endl;
			if (str == "exit")
				break ;
			cout << "str 1 : " << str << endl;
		}
		else
			cout << "cin failure " << endl;
	}

	return 0;
}
