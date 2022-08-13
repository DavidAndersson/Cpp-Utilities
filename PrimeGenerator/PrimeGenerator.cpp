#include "PrimeGenerator.h"

const std::vector<int> PrimeGenerator::GetNFirst(int nPrimes)
{
	int searchLimit = nPrimes * 5;
	int primesFound = 0;

	std::vector<int> primes;
	std::vector<bool> potentialPrimes(searchLimit, true);


	// Start at the first prime - 2 and increment. If the potential prime number is true it ís a prime and subsequently
	// we set every multiple of this number to false, this ensures that every future non-prime is tagged as false
	for (int i = 2; i < searchLimit; i++) {

		if (potentialPrimes[i] == true) {

			for (int j = i * 2; j < searchLimit; j += i)
				potentialPrimes[j] = false;

			primes.push_back(i);
			primesFound++;
		}

		// If the current number we are at is equal to the maximum restricted value -> break
		if (primesFound == nPrimes)
			break;
	}

	return primes;

}

const std::vector<int> PrimeGenerator::GetPrimesUpTo(int searchLimit)
{
	if (searchLimit > maxSearchSize) {
		std::cout << "Cannot create primes up to that high" << std::endl;
		return std::vector<int>{};
	}


	int primesFound = 0;

	std::vector<int> primes;
	std::vector<bool> potentialPrimes(searchLimit, true);


	// Start at the first prime - 2 and increment. If the potential prime number is true it ís a prime and subsequently
	// we set every multiple of this number to false, this ensures that every future non-prime is tagged as false
	for (int i = 2; i < searchLimit; i++) {

		if (potentialPrimes[i] == true) {

			for (int j = i * 2; j < searchLimit; j += i)
				potentialPrimes[j] = false;

			primes.push_back(i);
			primesFound++;
		}

		// If the current number we are at is equal to the maximum restricted value -> break
		if (i == searchLimit)
			break;
	}


	std::cout << primesFound << " primes found while searching " << searchLimit << " numbers" << std::endl;
	return primes;

}
