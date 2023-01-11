#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

/* 🐶🐱🐭🐹🐰🦊🐻🐼🐨🐯🦁🐮🐽🐵🐴 */

int main()
{
	//{ /* abstract class type 'Animal' */
	//	const Animal* a = new Animal();
	//	a->getType();
	//}

	{
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		
		//i->seeBrain(); // 안되는게 당연
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		std::cout << "delete Dog" << std::endl;
		delete j;
		std::cout << "delete Cat" << std::endl;
		delete i;
		//system("leaks animal");
	}

	{
		Animal **animal = new Animal*[10];
		for (int i = 0; i < 10 ; i++) {
			if (i < 5)
				animal[i] = new Dog();
			else
				animal[i] = new Cat();
		}
		for (int i = 0; i < 10 ; i++) {
			animal[i]->getType();
			animal[i]->makeSound();
		}
		for (int i = 0; i < 10 ; i++) {
			delete animal[i];
		}
		delete[] animal;
		//system("leaks animal");
	}

	{
		const Dog* j = new Dog();
		const Cat* i = new Cat();
		
		std::cout << "seeBrain Cat" << std::endl;
		i->seeBrain();
		std::cout << "seeBrain Dog" << std::endl;
		j->seeBrain();
		delete j;
		delete i;
		//system("leaks animal");
	}

	{
		std::cout << "Brain b" << std::endl;
		Brain b;
		std::cout << "===================" << std::endl;
		b.setIdea("this is brain", 0);
		//b.putIdeas();
		std::cout << "Cat* j = new Cat()" << std::endl;
		Cat* j = new Cat();
		std::cout << "===================" << std::endl;
		b.setIdea("first", 1);
		b.setIdea("2222", 2);
		b.setIdea("tatat", 3);
		std::cout << "copy brain" << std::endl;
		j->copyBrain(b);
		std::cout << "===================" << std::endl;
		b.setIdea("99999999", 9);
		b.putIdeas();
		j->seeBrain();
		delete j;
		//system("leaks animal");
	}

	std::cout << "Dog basic" << std::endl;
	Dog basic;
	{
		std::cout << "Dog tmp = basic" << std::endl;
		Dog tmp = basic;
		std::cout << "===================" << std::endl;
		//system("leaks animal");
	}
	std::cout << "===================" << std::endl;

	system("leaks animal");
	return 0;
}