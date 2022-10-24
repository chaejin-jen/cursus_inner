#include "Zombie.hpp"

/* new/delete operator
new 연산자로 객체를 할당할 때 생성자가 자동으로 호출됨
delete로 객체를 삭제할 때는 파괴자가 자동으로 호출됨
*/

int	main(void)
{
	Zombie zombie("stack");
	Zombie *pzombie = newZombie("heap"); // announce 포함

	randomChump("randomCump(stack)");
	zombie.announce();
	delete pzombie;

	return 0;
}