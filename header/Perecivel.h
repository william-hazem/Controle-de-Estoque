#ifndef PERECIVEL_H
#define PERECIVEL_H

#include "Produto.h"
#include "Data.h"

typedef Data data_t;

class Perecivel : public Produto
{
	
private:
  data_t data_validade;
	//long data_validade;
	
public:
	Perecivel(Produto_t = {0, 0, " ", " ", " ", 0, 0}, data_t = {0,0,0});

	void setData_validade(data_t);
  
	data_t getData_validade() const;
  
  
	//retorna em quantos dias o produto ir� se vencer
	unsigned int tempoValidade(data_t) const;	

  void imprimirData() const;
  string dataFormatada() const;
	
};

#endif
