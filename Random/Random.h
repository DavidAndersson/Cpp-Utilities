#pragma once
#include <random>
#include "Vec2.h"

// How to initialize the class:
// #include <random>
// std::mt19937& rng = std::mt19937(std::random_device{}());


class Random
{
public:
	Random(std::mt19937& rng)
		:
		rng(rng)
	{};
	
	// 1D
	float random(float min, float max);
	float random(float max);


	// 2D

	// Specify a range between where you want the random number to go between
	Vec2 Random_2D(Vec2 x_range, Vec2 y_range);

	// Specify the upper limits to the random generator, assuming the lower is 0
	Vec2 Random_2D(float x_max = 1, float y_max = 1);

	// Specify the upper limits to the random generator, assuming the lower is the same but negative
	Vec2 Random_2D_sym(float x_max = 1, float y_max = 1);

	// The same as Random_2d_sym, but the random value is normalized
	Vec2 Random_2D_Normalized();

private:
	std::mt19937& rng;
};

