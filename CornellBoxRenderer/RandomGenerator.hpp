#pragma once
#include <random>
#include <memory>

namespace CBR{

class RandomGenerator{
public:
	RandomGenerator();

	// 0.0~1.0の範囲で乱数を返す
	double operator()() const;

private:
	std::unique_ptr<std::mt19937> engine;
	std::unique_ptr<std::uniform_real_distribution<>> distRnd;
};

}