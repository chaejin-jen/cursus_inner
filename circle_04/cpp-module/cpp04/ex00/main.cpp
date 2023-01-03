#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

/* 🐶🐱🐭🐹🐰🦊🐻🐼🐨🐯🦁🐮🐽🐵🐴 */

int main()
{
	/* Animal, Cat, Dog */
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete meta;
	delete i;
	delete j;

	// /* WrongAnimal, WrongCat */
	// const WrongAnimal* wrong_meta = new WrongAnimal();
	// const Animal* j = new Dog();
	// const WrongAnimal* wrong_i = new WrongCat();
	// std::cout << j->getType() << " " << std::endl;
	// std::cout << wrong_i->getType() << " " << std::endl;
	// wrong_i->makeSound(); //will output the cat sound!
	// j->makeSound();
	// wrong_meta->makeSound();
	// delete wrong_meta;
	// delete wrong_i;
	// delete j;

	return 0;
}