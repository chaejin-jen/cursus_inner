#include "Zombie.hpp"

/* new/delete operator
new 연산자로 객체를 할당할 때 생성자가 자동으로 호출됨
delete로 객체를 삭제할 때는 파괴자가 자동으로 호출됨
*/

int	main(void)
{
	Zombie zombie0;
	Zombie zombie1("stack");
	Zombie *pzombie0 = new Zombie();
	Zombie *pzombie1 = newZombie("heap"); // announce 포함

	randomChump("randomCump(stack)");
	zombie0.announce();
	zombie1.announce();
	pzombie0->announce();
	delete pzombie0;
	delete pzombie1;

	return 0;
}