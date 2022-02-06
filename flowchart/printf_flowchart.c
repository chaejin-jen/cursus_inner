flag, type 체크를 bits로 하고
*function 로 type 별 실행
보너스
	bit mask
	binary file 관점 or man page syntax 대로 하는지
		linux, window 에선 형식(순서) 안지키면 출력 안해주는데, apple 은 워닝떠도 컴파일 됨 (binary file 은 되니까ㅏㅏ아)
	finite automata (상태랑 입력에 따라서 작성된 action table) -> 요즘엔 객체지향..? 


크게
	string 체크(cspdiuxX%), 뒤에 가변인자 파싱해서 넣기
	cspdiuxX% 참고 (https://dojang.io/mod/page/view.php?id=736)
		%c char
			// int     i
			char    c
		%s char *
			char    *s
			// wchar_t *l

		%p void * 를 hexadecimal (16진수)
			void *

		%d signed decimal (base 10) number
		%i signed 10진수 integer
			int i
			// signed char hh
			// short int   h
			long int    l
			// long long int   ll
			// intmax_t    j
			size_t  z
			// ptrdiff_t   t

		%u unsigned decimal (base 10) number
		%x unsigned hexadecimal (base 16) number, with lowercase
		%X unsigned hexadecimal (base 16) number, with uppercase
			unsigned int    u_i
			// unsigned char   u_hh
			// unsigned short int  u_h
			unsigned long int   u_l
			// unsigned long long int	u_ll
			// uintmax_t   u_j
			// size_t      z
			// ptrdiff_t   t

		%% 퍼센트 기호 (%)
	[보너스-플래그 구현] '-0.'과 각 서식 지정자별 최소 폭 서식 지정자별 최소 폭, '# +'
		[플래그(flag)][폭(width)][.정밀도]

		d, i, u, x, X, p
		'-' [플래그] 왼쪽 정렬
		'숫자' [폭] 지정한 숫자만큼 폭을 지정하여 출력, 실수는 . (점), e+까지 폭에 포함됨
			'숫자'(오른쪽 정렬, 스페이스)
			'-숫자'(왼쪽 정렬, 스페이스)
			'0숫자'(오른쪽 정렬, 0)
			//'숫자' 는 INT_MAX 까지 (그 뒤엔 어떻게 되는지 찾아보기!)
		'.숫자'	[정밀도] 지정한 숫자만큼 소수점 아래 자리 출력
			'.0' -> '.' || '.' -> '.0'
			'.숫자' ("%.3d", 12 -> 012, -12 -> -012)
			'+.숫자' 숫자 폭만큼 찍고 부호, 부호사이, 0 채움("%+.3d", 12 -> +012, -12 -> -012)
				' ' 는 '+' 플래그랑 올 땐, 무시 되므로 0 채움
				'+숫자' 부호까지 해서 폭잼("%+03d", 12 -> +12, -12 -> -12)
			'숫자.숫자' 
		d, i, u, x, X
		'0'	[플래그] 출력하는 폭의 남는 공간에 0으로 채움
			출력될 숫자수가 더 길 땐, 신경쓸 필요 없음
			'-' 플래그랑 올 땐, 무시 ('-0숫자' -> '-숫자'(왼쪽 정렬, 스페이스))

		d, i
		'+' [플래그] 양수일 때는 + 부호, 음수일 때는 - 부호 출력
		'공백' [플래그] 양수일 때는 부호를 출력하지 않고 공백으로 표시, 음수 일 때는 - 부호 출력
			'+' 플래그랑 올 땐, 무시 ('+ ' || ' +' -> '+')

		x, X
		'#' [플래그] 진법에 맞게 숫자 앞에 0(o), 0x(x), 0X(X)를 붙임

		<???> '-0.' 각 서식 지정자별 최소 폭

		예시 코드
			/*
			printf("%0+14i^\n", -2147473648);
			printf("%+.14i^\n", -2147473648);
			printf("%0+14i^\n", 2147473648);
			printf("%+.14i^\n", 2147473648);
			printf("%.14i^\n", 2147473649);
			printf("%+0.14i^\n", 2147473649);
			printf("%+014i^\n", 2147473649);
			printf("%-14s^\n", "abcdefg");
			*/
예외 처리
	stirng 유효 한지
	XXX string 서식 지정자와 가변인자 다르면 에러처리
	XXX 가변인자 갯수 서식 지정자 갯수 달라도 에러처리
공부할꺼
	가변 인자란? stdarg.h 헤더파일
	(type) va_list: 가변 인자의 메모리 주소를 저장하는 포인터
	(fn)   va_start: 가변 인자를 가져올 수 있도록 포인터를 설정
	(fn)   va_arg: 가변 인자 포인터에서 특정 자료형 크기만큼 값을 가져옴
	(fn)   va_end: 가변 인자 처리가 끝났을 때 포인터를 NULL로 초기화
	printf.c apple 소스 확인
/*******************************/
va_list arg_ptr;
// va_list args_copy;

va_start(arg_ptr, 가변인자이름);
va_copy(args_copy, arg_ptr);

while (*s)
	char    * s = va_arg(arg_ptr, char *); // 뒤에 오는 data type 크기에 따라, 가변 인자 목록 포인터에서 값을 가져온 뒤, 포인터 이동 시킴
	int     n = va_arg(arg_ptr, int);
va_end(arg_ptr); // 포인터를 NULL로 초기화