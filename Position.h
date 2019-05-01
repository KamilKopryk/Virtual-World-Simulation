#pragma once

#include <random>
#include <stdexcept>

enum Direction { top, right, down, left};

struct Position
{
	int x_;
	int y_;

	Position() = delete;
	Position(const int x, const int y);
	Position(const Position& position) = default;

	bool operator==(const Position& other) const
	{
		return (x_ == other.x_ && y_ == other.y_) ? true : false;
	}

	static Position GenerateRandomPosition()
	{
		//TODO	
	}

	static Position GenerateRandomNeighborPosition(const Position& position)
	{
		std::random_device rd;
		std::mt19937 rng(rd());

		const std::uniform_int_distribution<std::mt19937::result_type> dist(Direction::top, Direction::left);

		Position new_position = position;

		switch (dist(rng))
		{
		case top:	--new_position.y_;
			break;

		case right:	++new_position.x_;
			break;

		case down:	++new_position.y_;
			break;

		case left: --new_position.x_;
			break;
		default:
			throw std::runtime_error("Wrong case in GenerateRandomNeighborPosition!");
		}
		return new_position;
	}
};


inline Position::Position(const int x, const int y): x_(x), y_(y)
{}
