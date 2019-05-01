#pragma once

#include <unordered_map>
#include <vector>

#include "Position.h"
#include "Organism.h"
#include "Dog.h"

#ifdef _WIN32
#define WINDOWS
#include <Windows.h>
#endif

struct Position;
class Organism;


class Game
{
private:
	
	int x_map_;
	int y_map_;

	std::vector<Organism*> organisms_map_;
	std::vector<Organism*> organisms_vector_;

	void InitBasicOrganisms();
	void MakeRound();
	void PrintWorld();
	void SaveWorld();
	void LoadWorld();
	int GetIndexFromPosition(const Position& position) const;

	bool IsValidNewPosition(const Position& position) const;

	Organism* ColisionEngine(Position old_position);
	Position CalculatePosition(const int i) const;
protected:


public:
	Game() = delete;
	Game(int x_max, int y_max);
	~Game();

	void StartGame();
};


inline void Game::MakeRound()
{


	for (const auto& organism : organisms_vector_)
	{
		const auto old_position = organism->GetPosition();

		organism->Action();

		const auto new_position = organism->GetPosition();


		if(!IsValidNewPosition(new_position))
		{
			organism->UpdatePosition(old_position);
		}
		else
		{
			Organism* other = ColisionEngine(old_position);

			if (other != nullptr)
				organism->Colision(other);

			organisms_map_[GetIndexFromPosition(old_position)] = nullptr;
			organisms_map_[GetIndexFromPosition(organism->GetPosition())] = organism;
		}
	}
}

inline void Game::PrintWorld()
{
	
	for(int i=0; i< y_map_; ++i)
	{
		for(int j=0; j<x_map_; ++j)
		{
			const auto position = GetIndexFromPosition(Position(i, j));

			if( organisms_map_[position] != nullptr)
				std::cout << "x";
			else
				std::cout << " ";
		}

		std::cout << std::endl;
	}
}

inline int Game::GetIndexFromPosition(const Position& position) const
{
	return position.x_ + position.y_ * y_map_;
}

inline bool Game::IsValidNewPosition(const Position& position) const
{
	return (position.x_ >= 0) && (position.x_ < x_map_) && (position.y_ >= 0) && (position.y_ < y_map_) ? true : false;
}

inline Organism* Game::ColisionEngine(Position old_position)
{
	//todo
	return nullptr;
}

inline Position Game::CalculatePosition(const int i) const
{
	int x = i % x_map_;
	int y = i / x_map_;
	return Position(x, y);
}

inline Game::Game(const int x_max = 50, const int y_max = 50):
	x_map_(x_max), y_map_(y_max), organisms_map_(x_max* y_max, nullptr)
{
	const auto max_number_of_organisms = x_map_ * y_map_;
	organisms_vector_.reserve(max_number_of_organisms);
}

Game::~Game()
{
	for(const auto& organism: organisms_vector_)
	{
		delete organism;
	}
}

inline void Game::InitBasicOrganisms()
{
	Organism* dog = new Dog(Position(10,10),10,10,5);
	organisms_vector_.emplace_back(dog);
	organisms_map_[GetIndexFromPosition(dog->GetPosition())] = dog;
}

inline void Game::StartGame()
{
	InitBasicOrganisms();

	while(true)
	{
		MakeRound();
		PrintWorld();

#ifdef WINDOWS
		system("cls");
#endif
	}
}