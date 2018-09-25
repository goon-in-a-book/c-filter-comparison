#include <iostream>
#include <vector>
#include <chrono>

#include <stdlib.h>
#include <time.h>

int main() {
	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
	srand(time(NULL));
	int length = 4096;
	const size_t dataSize = length * length;
	std::vector<float> data(dataSize, 0.0);
	for (size_t i = 0; i < dataSize; i++)
	{
		data[i] = rand() % dataSize;
	}

	size_t numValues = 200;
	std::vector<float> filterValues(numValues, 0);
	for (size_t i = 0; i < numValues; i++)
	{
		filterValues[i] = rand() % dataSize;
	}

	std::vector<float> results(dataSize, 0.0);

	std::chrono::steady_clock::time_point done = std::chrono::steady_clock::now();
	std::cout << "Startup time (seconds) = " << std::chrono::duration_cast<std::chrono::milliseconds>(done - begin).count() << std::endl;
	begin = std::chrono::steady_clock::now();

	for (size_t i = 0; i < dataSize; i++)
	{
		for (size_t j = 0; j < numValues; j++) 
		{
			if (data[i] < filterValues[j]) {
				results[i] = 0;
				break;
			}
		}
		results[i] = data[i];
	}
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout << "Elapsed Time (milliseconds) = " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() / 1000000.0 << std::endl;
	std::cin.get();
}