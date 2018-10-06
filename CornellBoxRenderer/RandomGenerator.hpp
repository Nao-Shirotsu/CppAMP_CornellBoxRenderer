#pragma once
#include <random>
#include <memory>

class RandomGenerator{
public:
	RandomGenerator();

	// 0.0~1.0�͈̔͂ŗ�����Ԃ�
	double operator()() const;

private:
	std::unique_ptr<std::mt19937> engine;
	std::unique_ptr<std::uniform_real_distribution<>> distRnd;
};