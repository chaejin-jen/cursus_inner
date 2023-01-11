#include <iostream>
#include <cstdio>

int setAbit(int x, int n, int b);
char *intToBinary(int i);

int main(int ac, char *av[]) {
	if (ac != 2)
		return 1;
	int a(atoi(av[1]));
	
	std::cout << "a is " << a << std::endl;
	
	/* shift */
	// std::cout << "a >> 4 is " << (a >> 4) << " as integer" << std::endl;

	int num = 0;
	printf("%s\n", intToBinary(num));
	// 2진수 출력 결과: 0000000000000000


	// 0번 비트 (맨 우측 비트)를 1로 켜기
	printf("%s\n", intToBinary( setAbit(num, 0, 1) ));
	// 0000000000000001



	printf("\n\n");
	// 0000000000000000 에서, 차례로 1비트씩 켜기 (1로 ON)
	num = 0;
	for (int i = 31; i >= 0; i--) {
	int temp = setAbit(num, i, 1);
		printf("%s = %32d\n", intToBinary(temp), temp);
	}


	printf("\n\n");
	// 1111111111111111 에서, 차례로 1비트씩 끄기 (0으로 OFF)
	num = 0xFFFFFFFF;
	for (int i = 31; i >= 0; i--) {
	int temp = setAbit(num, i, 0);
	printf("%s = %32d\n", intToBinary(temp), temp);
	}

	return 0;
}

// 정수 x 의 n번째 비트를, b로 설정하는 함수
int setAbit(int x, int n, int b) { // setbit()
	if (b == 1)
		return (int) (x | (1 << n));
	return (int) (x & (~(1 << n)));
}

// 32비트 정수를 2진수 문자열로 변환 함수
char *intToBinary(int i) {
	static char s[32 + 1] = { '0', };
	int count = 32;

	do { s[--count] = '0' + (char) (i & 1);
		i = i >> 1;
	} while (count);

	return s;
}