#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>
using namespace std;

int main()
{
	ofstream myfile;
	auto start = std::chrono::high_resolution_clock::now();


	const int range=1000000;
	int num = 0;
	int candidate = 2;
	int size = 1;

	std::vector<int> Primes;
	Primes.push_back(2);



	while (size < range) // runs until number of primes is equal to range
	{
		candidate = candidate+1;

		for (int i = 0; i < size; i++) // runs through all known primes at this instance
		{

			if (candidate%Primes[i]==0)
			{
				break;
			}
			else if (sqrt(candidate)<Primes[i])
			{
				Primes.push_back(candidate);
				size = size + 1;
				break;
			}
		}
	}


	auto finish = std::chrono::high_resolution_clock::now();


	myfile.open("List_of_primes.txt");
	
	for (int i = 0; i < range; i++)
	{
		//cout << i+1 << ". " << Primes[i] << endl;
		myfile << Primes[i] <<"\n";
	}

	myfile.close();

	std::chrono::duration<double> elapsed = finish - start;

	std::cout << "Elapsed time: " << elapsed.count() << " s\n";

	cout << "Bok" << endl;

	system ("pause");
	return 0;
}