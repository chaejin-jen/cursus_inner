#include <stdio.h>
#include <unistd.h>

/* ===== page 단위 체크 ==== 4096
POSIX runtime long sysconf(int name);
    #include <unistd.h>

    long sysconf(_SC_PAGESIZE);
    

리눅스 getpagesize()
    int page_size=getpagesize();
    바이트 단위의 페이지 크기를 반환
    페이지 크기는 <sys/user.h>에 정의된 PAGE_SIZE매크로에도 정적으로 저장되어 있다. 따라서 페이지 크기를 구하는 세번째 방법은 PAGE_SIZE를 사용

*/
int main(void)
{
    printf("%d\n", sysconf(_SC_PAGESIZE));
    printf("%d\n", getpagesize());
    return (0);
}