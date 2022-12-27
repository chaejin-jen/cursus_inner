// #include <cstdlib>
#include "Zombie.hpp"

// #define NB_ZOMBIE 10

/* new/delete operator
new 연산자로 객체를 할당할 때 생성자가 자동으로 호출됨
delete로 객체를 삭제할 때는 파괴자가 자동으로 호출됨
*/

// static std::string	randomName(int length);

int	main(void)
{
	std::cout << "======== constructor exception ========" << std::endl;
	/* Zombie( void ); */
	Zombie unknown;

	/* Zombie( NullptrFT *ptr ); */
	Zombie znull(NULL);

	/* Zombie( std::string name ); */
	const char s1[] = "aaaa";
	Zombie zs1(s1);
	const char *s2 = "bbbb";
	Zombie zs2(s2);
	char s3[] = "cccc";
	Zombie zs3(s3);
	char *s4 = new char[strlen("dddd")+1];;
	strcpy(s4, "dddd");
	Zombie zs4(s4);

	unknown.announce();
	znull.announce();
	zs1.announce();
	zs2.announce();
	zs3.announce();
	zs4.announce();

	std::cout << "======== zombie is born ========" << std::endl;
	Zombie zombie("stack");
	Zombie *pzombie = newZombie("heap");

	std::cout << "======== announce ========" << std::endl;
	pzombie->announce();
	zombie.announce();

	std::cout << "======== randomCump - constructor, destructor ========" << std::endl;
	randomChump("randomCump(stack1)");
	randomChump("randomCump(stack2)");
	randomChump("randomCump(stack3)");

	
	std::cout << "======== zombie died ========" << std::endl;
	delete pzombie;

	// /* random name */
	// Zombie *z[NB_ZOMBIE];

	// std::cout << NB_ZOMBIE << " Heap Zombies are born" << std::endl;
	// for (int i = 0 ; i < NB_ZOMBIE ; ++i)
	// 	z[i] = newZombie(randomName(4));
	// std::cout << "\n" << NB_ZOMBIE << " Stack Zombies are born" << std::endl;
	
	// for (int i = 0 ; i < NB_ZOMBIE ; ++i)
	// 	randomChump(randomName(4));
	// std::cout << "\n" << NB_ZOMBIE << " Heap Zombies died" << std::endl;
	
	// for (int i = 0 ; i < NB_ZOMBIE ; ++i)
	// 	delete z[i];
	return 0;
}

// static std::string	randomName(int length)
// {
// 	char consonents[] = {'b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','z'};
// 	char vowels[] = {'a','e','i','o','u','y'};

// 	std::string name = "";

// 	int random = rand() % 2;
// 	int count = 0;

// 	for(int i = 0; i < length; i++)
// 	{

// 		if(random < 2 && count < 2)
// 		{
// 			name = name + consonents[rand() % 19];
// 			count++;
// 		}
// 		else {
// 			name = name + vowels[rand() % 5];
// 			count = 0;
// 		}
// 		random = rand() % 2;
// 	}

// 	return name;
// }
