# pragma once
#include <vector>
#include <iostream>


class PrimeGenerator {

public:
	static const std::vector<int> GetNFirst(int nPrimes);
	static const std::vector<int> GetPrimesUpTo(int searchLimit);

private:

	static constexpr int maxSearchSize = 1000'000; 


};


