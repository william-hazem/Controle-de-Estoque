/*
	Autor: William Henrique A. Martins
		   DEE UFCG
	A função abaixo suprime a necessidade de um time, use como desejar	
*/

#include <ctime>
void stopf(int time)
{
	clock_t fixed_t = time, current_t = 0, relative_t = clock();
	while(fixed_t >= current_t)
	{
		current_t = clock() - relative_t;
	}
}

