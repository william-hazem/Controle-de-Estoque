#ifndef ESTOQUE_H
#define ESTOQUE_H

#include "Produto.h"
#include "Perecivel.h"

#include <vector>

#include <fstream>

#include <utility>

using std::ofstream;
using std::ifstream;
using std::ios;

class Estoque
{
	
private:
	vector <Produto> produtos;			//Produtos n�o pereciveis
	vector <Perecivel> pereciveis;	
	
public:
	Estoque();
	~Estoque();
	
	bool adicionarProduto(Produto);
	bool adicionarProduto(Perecivel);
	bool adicionarProduto(long int, long int);
	
	bool remover(long int);
	bool remover(long int, size_t);
	
	size_t pesquisarProduto(long) const;
	size_t pesquisarPerecivel(long) const;
	
	bool checarVencimento(size_t, long, short = 0) const;
  vector<Perecivel> retornaVencido(long, short = 0) const;
	vector<Perecivel> removerVencido(long, short = 0);
	
	Produto retornaProduto(size_t) const;
	Perecivel retornaPerecivel(size_t) const;
	vector<Produto> retornaProduto() const;
	vector<Perecivel> retornaPerecivel() const;
	
	size_t retornaTamanhoProduto() const;
	size_t retornaTamanhoPerecivel() const;
	
	bool salvarProdutos();
	bool salvarPereciveis();
	bool salvarInfo();

	//Ordena�o
	void opNome();
	void opPreco();
	void opCategoria();	

	//Impress�o dos dados armazenados nos conteiners
	void imprimeProdutos() const;
	void imprimePereciveis() const;
	
	//Implementar os dois m�todos abaixo - FRANCINILDO
	void modificarProduto(size_t);
	void modificarPerecivel(size_t);
};

#endif
