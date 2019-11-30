#include "..\\header\\Estoque.h"

/*
	ESTE ARQUIVO SER� USADO PARA IMPLEMENTAR TODAS AS SOBRECARGAS GLOBAIS DO PROJETO
*/

ofstream& operator << (ofstream& c, Produto_t& produto_type)
{
	//String
	c << produto_type.categoria << endl;
	c << produto_type.marca << endl;
	c << produto_type.nome_produto << endl;
	//int
	c << produto_type.codigo << endl;
	c << produto_type.quantidade << endl;
	//float
	c << produto_type.preco_venda;
	
	return c;
}

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
	c << p.getItem().preco_venda;
	
	return c;
}

ofstream& operator << (ofstream& c, Perecivel& p)
{
	//String
	c << p.getItem().categoria << endl;
	c << p.getItem().marca << endl;
	c << p.getItem().nome_produto << endl;
	//int
	c << p.getItem().codigo << endl;
	c << p.getItem().quantidade << endl;
	c << p.getData_validade() << endl;
	//float
	c << p.getItem().preco_venda;
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
	p.setItem(item);
	return c;
}

ifstream& operator >> (ifstream& c, Perecivel& p)
{
	long data_validade;
	Produto_t item;
	getline(c, item.categoria);
	getline(c, item.marca);
	getline(c, item.nome_produto);
	c >> item.codigo; c.ignore();
	c >> item.quantidade; c.ignore();
	c >> data_validade; c.ignore();
	c >> item.preco_venda; c.ignore();
	p.setItem(item);
	p.setData_validade(data_validade);
	return c;
}
