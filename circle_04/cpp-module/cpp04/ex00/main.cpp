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
	std::cout << "delete Animal" << std::endl;
	delete meta;
	std::cout << "delete Dog" << std::endl;
	delete j;
	std::cout << "delete Cat" << std::endl;
	delete i;

	///* WrongAnimal, WrongCat */
	//const WrongAnimal* wrong_meta = new WrongAnimal();
	//const Animal* j = new Dog();
	//const WrongAnimal* wrong_i = new WrongCat();
	//std::cout << j->getType() << " " << std::endl;
	//std::cout << wrong_i->getType() << " " << std::endl;
	//wrong_i->makeSound(); //will output the cat sound!
	//j->makeSound();
	//wrong_meta->makeSound();
	//std::cout << "delete WrongAnimal" << std::endl;
	//delete wrong_meta;
	//std::cout << "delete Dog" << std::endl;
	//delete j;
	//std::cout << "delete WrongCat" << std::endl;
	//delete wrong_i;

	return 0;
}