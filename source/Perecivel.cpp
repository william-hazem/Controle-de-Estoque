#include "..//header//Perecivel.h"

Perecivel::Perecivel(Produto_t novoItem, data_t data_validade) : Produto(novoItem)
{
	this->data_validade = data_validade;
}

data_t Perecivel::getData_validade() const
{
	return this->data_validade;
}

void Perecivel::setData_validade(data_t data_validade)
{
	this->data_validade = data_validade;
}

unsigned int Perecivel::tempoValidade(data_t data_atual) const
{
	return this->data_validade.dataDif(data_atual);
}

void Perecivel::imprimirData() const
{
  data_validade.imprimirData();
}

string Perecivel::dataFormatada() const
{
  string sdata = to_string(data_validade.getDia()) + "/" + to_string(data_validade.getMes()) + "/" + to_string(data_validade.getAno());

  return sdata; 
}