#pragma once

#include <iostream>

#include "Organism.h"
#include "Position.h"


class Animal :
	public Organism
{

protected:
	void Reproduction();

public:
	Animal() = delete;

	Animal(Animal& animal) = delete;
	Animal(Animal&& animal) = delete;
	Animal& operator=(Animal& r_animal) = delete;
	Animal& operator=(Animal&& r_animal) = delete;
	virtual ~Animal() = 0;

	Animal(const Position& position, const int age, const int strange, const int priority);

	virtual void Action() override;
	virtual void Colision(Organism *other) override;
	virtual void Print() override;
	void UpdatePosition(const Position& new_position);
};

inline Animal::~Animal() = default;

inline Animal::Animal(const Position& position, const int age, const int strange, const int priority) : Organism(position,age, strange,priority)
{
}


inline void Animal::Reproduction()
{
	//TODO
}

inline void Animal::Action()
{
	const Position new_position = Position::GenerateRandomNeighborPosition(position_);

	UpdatePosition(new_position);

}

inline void Animal::Colision(Organism* other)
{
	//TODO
}

inline void Animal::Print()
{
	//TODO
	// wip
	std::cout << "x";
}

inline void Animal::UpdatePosition(const Position& new_position)
{
	position_ = new_position;
}
