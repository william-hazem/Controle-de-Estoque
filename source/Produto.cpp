#include "..\\header\\Produto.h"

Produto::Produto(Produto_t novoItem)
{
    item = novoItem;
}

//Métdos SETS
void Produto::setItem(Produto_t novoItem)
{
	item = novoItem;
}

void Produto::setPreco_venda(float preco_venda)
{
    this->item.preco_venda = preco_venda;
}

void Produto::setNome_produto(string nome_produto)
{
    this->item.nome_produto = nome_produto;
}

void Produto::seMarca(string marca)
{
    this->item.marca = marca;
}

void Produto::setCategoria(string categoria)
{
    this->item.categoria = categoria;
}

void Produto::setQuantidade(int quantidade)
{
    this->item.quantidade = quantidade;
}

void Produto::setcodigo(int codigo)
{
    this->item.codigo = codigo;
}
//Métodos GETS
Produto_t Produto::getItem() const
{
	return item;
}

