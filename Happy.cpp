// A happy number is defined by the following process: 
// Starting with any positive integer, replace the number by the sum of the squares of its digits in base-ten, 
// and repeat the process until the number either equals 1 (where it will stay), or it loops endlessly in a 
// cycle that does not include 1. Those numbers for which this process ends in 1 are happy numbers, while those 
// that do not end in 1 are unhappy numbers (or sad numbers).


#include <iostream>
#include <fstream>
#include <unordered_set>
#include <chrono>

using namespace std;

int happy_reduce(int x) 
{
	int z, y = 0;
	z = x;

	while (z > 0)
	{
		y = y + (z % 10)*(z % 10);
		z = z/10;
	}

	return y;
}

bool happy_check(int a)
{

	std::unordered_set<int> Happy = {};
	auto search = Happy.find(a);

	while (a != 1)
	{

		Happy.insert(a);
		a = happy_reduce(a);
		search = Happy.find(a);

		if (search != Happy.end()) {
			return false;
		}

	}

		return true;


}

int main()
{

	ofstream myfile;
	auto start = std::chrono::high_resolution_clock::now();

	const int range = 10;
	int candidate = 1;
	int size = 0;
	std::vector<int> happys;

	while (size < range) // runs until number of found happy numbers is equal to range
	{

		if (happy_check(candidate)==true)
		{
			happys.push_back(candidate);
			size = size + 1;
		}
		
		candidate = candidate + 1;
	}

	auto finish = std::chrono::high_resolution_clock::now();

	myfile.open("List_of_Happy_numbers.txt");

	for (int i = 0; i < range; i++)
	{
		myfile << happys[i] << "\n";
	}

	myfile.close();

	std::chrono::duration<double> elapsed = finish - start;

	std::cout << "Elapsed time: " << elapsed.count() << " s\n";
	cout << "Happy" << endl;

	system("pause");
	return 0;

}