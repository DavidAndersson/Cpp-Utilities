#include "Random.h"

float Random::random(float min, float max)
{
	auto dist = std::uniform_real_distribution<float>(min, max);
	return dist(rng);
}

float Random::random(float max)
{
	return random(0, max);
}

Vec2 Random::Random_2D(Vec2 x_range, Vec2 y_range)
{
	auto x_dist = std::uniform_real_distribution<float>(x_range.x, x_range.y);
	auto y_dist = std::uniform_real_distribution<float>(y_range.x, y_range.y);
	return Vec2(x_dist(rng), y_dist(rng));
}

Vec2 Random::Random_2D(float x_max, float y_max)
{
	return Random_2D(Vec2(0, x_max), Vec2(0, y_max));

}

Vec2 Random::Random_2D_sym(float x_max, float y_max)
{	
	return Random_2D(Vec2(-x_max, x_max), Vec2(-x_max, y_max));
}

Vec2 Random::Random_2D_Normalized()
{
	return Random_2D_sym(1, 1).GetNormalized();
}
