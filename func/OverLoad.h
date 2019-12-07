#include "..//header//Estoque.h"

/*
	ESTE ARQUIVO SER� USADO PARA IMPLEMENTAR TODAS AS SOBRECARGAS GLOBAIS DO PROJETO
*/

ofstream& operator << (ofstream& c, Produto& p)
{
	//String
	c << p.getItem().categoria << endl;
	c << p.getItem().marca << endl;
	c << p.getItem().nome_produto << endl;
	//int
	c << p.getItem().codigo << endl;
	c << p.getItem().quantidade << endl;
	//float
	c << p.getItem().preco_venda << endl;
  c << p.getItem().preco_compra;
	
	return c;
}

ofstream& operator << (ofstream& c, Perecivel& p)
{
  data_t data = p.getData_validade();
	//String
	c << p.getItem().categoria << endl;
	c << p.getItem().marca << endl;
	c << p.getItem().nome_produto << endl;
	//int
	c << p.getItem().codigo << endl;
	c << p.getItem().quantidade << endl;
  //data_t
  c << data.getDia() << "\t" << data.getMes() << "\t" <<data.getAno() << endl;
	//float
	c << p.getItem().preco_venda << endl;
  c << p.getItem().preco_compra;
	return c;
}

ifstream& operator >> (ifstream& c, Produto& p)
{
	Produto_t item;
	getline(c, item.categoria);
	getline(c, item.marca);
	getline(c, item.nome_produto);
	c >> item.codigo; c.ignore();
	c >> item.quantidade; c.ignore();
	c >> item.preco_venda; c.ignore();
  c >> item.preco_compra; c.ignore();
	p.setItem(item);
	return c;
}

ifstream& operator >> (ifstream& c, Perecivel& p)
{
	ushort dia, mes, ano;
	Produto_t item;
	getline(c, item.categoria);
	getline(c, item.marca);
	getline(c, item.nome_produto);
	c >> item.codigo; c.ignore();
	c >> item.quantidade; c.ignore();
	c >> dia >> mes >> ano; c.ignore();
  data_t data_validade(dia,mes,ano);
	c >> item.preco_venda; c.ignore();
  c >> item.preco_compra; c.ignore();
	p.setItem(item);
	p.setData_validade(data_validade);
	return c;
}

