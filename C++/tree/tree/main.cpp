#include "tree.h"
#include <string>
#include <iostream>
#include <cstdio>
int main()
{
	tree <string, float>a;
	a["mama"] = 32.0f;
	a["papa"] = 33.0f;
	a["sasa"] = 34.0f;
	a["zaza"] = 35.0f;
	a["kaka"] = 36.0f;
	a.showshow();

	std::cout << a["mama"] << a["papa"] << a["sasa"] << a["zaza"] << a["kaka"] << std::endl;
	std::getc(stdin);
	return 0;
}