/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 12:30:22 by gvigano           #+#    #+#             */
/*   Updated: 2025/07/26 12:30:22 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "=== SUBJECT REQUIRED TEST ===" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	
	std::cout << "\nTEST WRONG CLASSES:" << std::endl;
	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();
	
	std::cout << wrongCat->getType() << " " << std::endl;
	wrongCat->makeSound();
	wrongMeta->makeSound();
	
	std::cout << "\n=== ADDITIONAL COMPREHENSIVE TESTS ===" << std::endl;
	
	std::cout << "\nTEST COPY CONSTRUCTOR & ASSIGNMENT:" << std::endl;
	
	std::cout << "\nTesting Animal copy constructor & assignment:" << std::endl;
	Animal originalAnimal;
	Animal copiedAnimal(originalAnimal);
	Animal assignedAnimal;
	assignedAnimal = originalAnimal;
	
	std::cout << "\nTesting Dog copy constructor & assignment:" << std::endl;
	Dog originalDog;
	Dog copiedDog(originalDog);
	Dog assignedDog;
	assignedDog = originalDog;
	
	std::cout << "\nTesting Cat copy constructor & assignment:" << std::endl;
	Cat originalCat;
	Cat copiedCat(originalCat);
	Cat assignedCat;
	assignedCat = originalCat;
	
	std::cout << "\nTesting WrongAnimal copy constructor & assignment:" << std::endl;
	WrongAnimal originalWrongAnimal;
	WrongAnimal copiedWrongAnimal(originalWrongAnimal);
	WrongAnimal assignedWrongAnimal;
	assignedWrongAnimal = originalWrongAnimal;
	
	std::cout << "\nTesting WrongCat copy constructor & assignment:" << std::endl;
	WrongCat originalWrongCat;
	WrongCat copiedWrongCat(originalWrongCat);
	WrongCat assignedWrongCat;
	assignedWrongCat = originalWrongCat;

	std::cout << "\nTEST GETTYPE & MAKESOUND FOR ANIMAL/DOG/CAT:" << std::endl;
	Animal	animal;
	Dog		dog;
	Cat		cat;

	std::cout << "Animal type: " << animal.getType() << " | Sound: ";
    animal.makeSound();
    std::cout << "Dog type: " << dog.getType() << " | Sound: ";
    dog.makeSound();
    std::cout << "Cat type: " << cat.getType() << " | Sound: ";
    cat.makeSound();

	std::cout << "\nTEST ARRAY CORRECT POLYMORPHISM:" << std::endl;
	std::cout << "Zoo simulation with Animal array:" << std::endl;
	Animal* zoo[4] = {
		new Dog(),
		new Cat(),
		new Dog(),
		new Cat()
	};
	
	for (int i = 0; i < 4; i++) {
		std::cout << "Zoo[" << i << "] (" << zoo[i]->getType() << "): ";
		zoo[i]->makeSound();
	}
	
	std::cout << "\nCleaning up zoo:" << std::endl;
	for (int i = 0; i < 4; i++) {
		delete zoo[i];
	}
	
	std::cout << "\nPROOF: SAME OBJECT, DIFFERENT BEHAVIOR!" << std::endl;
	WrongCat sameCat;
	WrongAnimal* catPtr = &sameCat;
	
	std::cout << "sameCat.makeSound() = ";
	sameCat.makeSound();
	
	std::cout << "catPtr->makeSound() = ";
	catPtr->makeSound();
	
	std::cout << "\nCONCLUSION: WITHOUT 'VIRTUAL', NO POLYMORPHISM!" << std::endl;
	
	std::cout << "\nTEST VIRTUAL DESTRUCTOR:" << std::endl;
	std::cout << "Creating and deleting via Animal* pointer:" << std::endl;
	Animal* testAnimal = new Dog();
	delete testAnimal;
	
	std::cout << "\nCreating and deleting via WrongAnimal* pointer:" << std::endl;
	WrongAnimal* testWrong = new WrongCat();
	delete testWrong;
		
	std::cout << "\nTEST CONST MEMBER FUNCTION CORRECTNESS:" << std::endl;
	const Dog constDog;
	const Cat constCat;
	std::cout << "Const Dog type: " << constDog.getType() << " | sound: ";
	constDog.makeSound();
	std::cout << "Const Cat type: " << constCat.getType() << " | sound: ";
	constCat.makeSound();
	
	delete meta;
	delete j;
	delete i;
	delete wrongMeta;
	delete wrongCat;
	
	return 0;
}