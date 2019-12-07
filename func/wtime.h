/*
	Autor: William Henrique A. Martins
		   DEE UFCG
	A fun�o abaixo suprime a necessidade de um time, use como desejar	
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

void stopsec(double second)
{
  double fixed_t = clock() / (double)CLOCKS_PER_SEC , current_t =0;
  while(second >= current_t)
    current_t = (double(clock() - fixed_t)) / CLOCKS_PER_SEC;
}

