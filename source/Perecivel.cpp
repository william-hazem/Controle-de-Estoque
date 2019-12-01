#include "..//header//Perecivel.h"

Perecivel::Perecivel(Produto_t novoItem, long data_validade) : Produto(novoItem)
{
	this->data_validade = data_validade;
}

long Perecivel::getData_validade() const
{
	return data_validade;
}

void Perecivel::setData_validade(long data_validade)
{
	this->data_validade = data_validade;
}

int Perecivel::tempoValidade(long data_atual) const
{
	long auxiliar = data_validade - data_atual;
	int dias;
	
	if(auxiliar <= 0) return 0;
	dias = (auxiliar%10000)*365;
	auxiliar = auxiliar/10000;
	dias += (auxiliar%100)*30;
	auxiliar = auxiliar/100;
	dias += auxiliar;
	return dias;	//Dias restante at� o vencimento
}
