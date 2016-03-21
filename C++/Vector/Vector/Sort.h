#pragma once
#include <cstdlib>
#include <cstring>

using namespace std;
template <class A>
void sort(A begin, A end)
{
	A i, j , q;
	for (i = begin; i != end; ++i)
	{
		j = begin;
		while(1)
		{
			q = j;
			++j;

			if (j == end) 
             	break;

			if (*q > *j) 
			{
				auto helper = *j;
				*j = *q;
				*q = helper;
			}
		}
	}
}