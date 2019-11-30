#ifndef PRODUTO_H
#define PRODUTO_H

#include <iostream>
using namespace std;

struct Produto_t
{
	float preco_venda;
	string nome_produto;
	string marca;
	string categoria;
	int quantidade;
	int codigo;
};

class Produto {

private:
	Produto_t item;

public:
	
	Produto(Produto_t = {0," ", " ", " ", 0, 0} );

	void setItem(Produto_t);
	void setPreco_venda(float);
	void setNome_produto(string);
	void seMarca(string);
	void setCategoria(string);
	void setQuantidade(int);
	void setcodigo(int);

	Produto_t getItem() const;
};

#endif
