#pragma once

#include "Position.h"

class Organism
{

protected:

	int age_;
	int strange_;
	int priority_;
	bool is_dead_;
	Position position_;

public:
	Organism() = delete;
	Organism(Organism& organism) = delete;
	Organism(Organism&& organism) = delete;
	virtual ~Organism() = 0;
	Organism& operator =(Organism& r_organism) = delete;
	Organism& operator =(Organism&& r_organism) = delete;

	Organism(const Position& position, const int age, const int strange, const int priority, const bool is_dead );


	virtual void Action() = 0;
	virtual void Colision(Organism* other) = 0;
	virtual void Print() = 0;

	Position GetPosition() const;

	void UpdatePosition(const Position& position);
};



inline Organism::~Organism() = default;

inline Organism::Organism(const Position& position, const int age, const int strange, const int priority, const bool is_dead = false):
	age_(age), strange_(strange), priority_(priority), is_dead_(is_dead), position_(position)
{

}

inline Position Organism::GetPosition() const
{
	return position_;
}

inline void Organism::UpdatePosition(const Position& position)
{
	position_ = position;
}
