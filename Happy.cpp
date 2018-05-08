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
	int z,y = 0;
	z = x;

	while (z > 0)
	{
		y = y + (z % 10)*(z % 10);
		z = z/10;
	}

		return y;
}


int main()
{

	int candidate, a, flag = 0;
	cout << "Insert candidate happy number" << endl;
	cin >> candidate;
	a = candidate;


	std::unordered_set<int> Happy ={};
	auto search = Happy.find(a);

	while (a != 1)
	{

		if (search != Happy.end()) {
			std::cout << "We have a looper: " << (*search) << '\n';
			flag = 1;
			break;
		}
		else {
			std::cout << "Nope .. " << a << "  Go fish\n";
		}
		Happy.insert(a);
		a = happy_reduce(a);
		search = Happy.find(a);
	}
	
	if (flag != 1)
	{
		std::cout << candidate << " is a Happy number!" << endl;
	}



	system("pause");
	return 0;

}