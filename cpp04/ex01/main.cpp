/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 13:11:56 by gvigano           #+#    #+#             */
/*   Updated: 2025/07/26 13:11:57 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
	std::cout << "TEST 1: CHECK VIRTUAL DESTRUCTOR:" << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;
	delete i;

	std::cout << "TEST 2: DEMONSTRATING DEEP COPY OVER SHALLOW COPY!:" << std::endl;
	Dog	dogDefault;
	Dog	newDog(dogDefault);

	if (dogDefault.getBrain() != newDog.getBrain()) {
		std::cout << "Deep Copy successfully created! "
				  << "dogDefault brain: " << dogDefault.getBrain()
				  << " | newDog brain: " << newDog.getBrain() << std::endl;
	} else {
		std::cout << "Shallow Copy detected, look!!! : "
				  << "dogDefault brain: " << dogDefault.getBrain()
				  << " | newDog brain: " << newDog.getBrain() << std::endl;
	}

	std::cout << "TEST 3: TEST ASSIGNMENT OPERATOR:" << std::endl;
	Dog	dog1;
	Dog	dog2;
	Brain* defaultBrain = dog2.getBrain();

	dog2 = dog1;
	if ((dog2.getBrain() != dog1.getBrain()) && (dog2.getBrain() != defaultBrain))
		std::cout << "Deep Copy Assignment successful." << std::endl;

	std::cout << "TEST 4: TEST ARRAY ANIMALS: (MEMORY MANAGEMENT)" << std::endl;
	const int	size = 6;
	Animal* animals[size];
	for (int i = 0; i < size; i++) {
		if (i < size/2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	for (int i = 0; i < size; i++) {
		std::cout << animals[i]->getType() << " makes this sound :" << std::endl;
		animals[i]->makeSound();
	}
	for (int i = 0; i < size; i++) {
		delete animals[i];
	}
	return 0;
}