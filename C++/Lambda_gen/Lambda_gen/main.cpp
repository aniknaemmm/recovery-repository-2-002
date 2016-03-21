#include <iostream>
typedef int serial(int);
serial lambda_gen()
{
	static int range = 0;
	range += 1000000;
	return [range](int x)
	{
		return x + range;
	};
}
int main()
{
	
	
	auto s1 = lambd_gen();
	auto s2 = lambd_gen();
	std::cout << s1(2) << s1(3) << s2(2);
	return 0;
}
