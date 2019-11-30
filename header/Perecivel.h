#ifndef PERECIVEL_H
#define PERECIVEL_H

#include "Produto.h"

class Perecivel : public Produto
{
	
private:
	long data_validade;
	
public:
	Perecivel(Produto_t = {0," ", " ", " ", 0, 0}, long = 0);
	void setData_validade(long);
	long getData_validade() const;
	//retorna em quantos dias o produto irá se vencer
	int tempoValidade(long) const;		
	
};

#endif
