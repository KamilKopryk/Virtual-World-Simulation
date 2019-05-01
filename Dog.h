#pragma once

#include "Animal.h"
#include "Position.h"

class Dog :
	public Animal
{
public:
	Dog() = delete;
	~Dog();

	Dog(const Position& position, const int age, const int strange, const int priority);
	
	
};

Dog::~Dog()
{
}


inline Dog::Dog(const Position& position, const int age, const int strange, const int priority) : Animal(position, age, strange, priority)
{
}