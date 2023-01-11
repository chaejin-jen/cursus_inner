#include "Zombie.hpp"

/* new/delete operator
new 연산자로 객체를 할당할 때 생성자가 자동으로 호출됨
delete로 객체를 삭제할 때는 파괴자가 자동으로 호출됨
*/

int	main(void)
{
	// Zombie *hzombie3 = zombieHorde(3, "three(heap)");
	// Zombie *hzombie100 = zombieHorde(100, "100(heap)");
	// Zombie *hzombie234 = zombieHorde(234, "234(heap)");

	// delete [] hzombie3;
	// delete [] hzombie100;
	// delete [] hzombie234;
	Zombie *hzombie;
	
	hzombie = zombieHorde(3, "three(heap)");
	delete [] hzombie;

	return 0;
}