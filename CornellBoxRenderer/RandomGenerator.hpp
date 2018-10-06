#pragma once
#include <random>
#include <memory>

class RandomGenerator{
public:
	RandomGenerator();

	// 0.0~1.0‚Ì”ÍˆÍ‚Å—”‚ğ•Ô‚·
	double operator()() const;

private:
	std::unique_ptr<std::mt19937> engine;
	std::unique_ptr<std::uniform_real_distribution<>> distRnd;
};