#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>
using namespace std;

int main()
{

	 ofstream myfile;
	 auto start = std::chrono::high_resolution_clock::now();


	const int count = 90; // large numbers apear very quickly
	std:vector<long long int> Fibonacci;
	Fibonacci.push_back(2);
	Fibonacci.push_back(3);


	for (int i = 0; i < count; i++)
	{
		Fibonacci.push_back(Fibonacci[i] + Fibonacci[i+1]);
	}

	auto finish = std::chrono::high_resolution_clock::now();


	myfile.open("List_of_Fibonacci_numbers.txt");

	for (int i = 0; i < count; i++)
	{
		myfile << Fibonacci[i] << "\n";
	}

	myfile.close();


	std::chrono::duration<double> elapsed = finish - start;

	std::cout << "Elapsed time: " << elapsed.count() << " s\n";

system("pause");
return 0;

}