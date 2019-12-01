#include "..//header//Registro.h"

Registro::Registro()
{
	saldo = 0;
	apurado = 0;
	q_entrada = 0;
	q_saida = 0;
}

void Registro::Registrar(Produto produto)
{
	ofstream arquivo("Reg_01.txt",ios::app);
	
  arquivo << produto.getItem().nome_produto << endl;
	arquivo << produto.getItem().categoria << endl;
	arquivo << produto.getItem().marca << endl;
	arquivo << produto.getItem().codigo << endl;
	arquivo << produto.getItem().quantidade << endl;
	arquivo << produto.getItem().preco_venda;
  cout << "Produto registrado!!!" << endl;
}

void Registro::set_saldo(float saldo)
{
	this ->saldo = saldo;
}

void Registro::set_q_entrada()
{
	vector<Produto> auxilar = retornaProduto();

	for(size_t index = 0; index < auxilar.size(); index++)
		q_entrada += auxilar[index].getItem().quantidade;

	vector<Perecivel> aux  = retornaPerecivel();
	
	for(size_t index = 0; index < aux.size(); index++)
		q_entrada += aux[index].getItem().quantidade;
		
}

void Registro::set_q_saida(int count)
{
	q_saida += count;
}

float Registro::get_saldo()const
{
	return saldo;
}

int Registro::get_q_entrada()const
{
	return q_entrada;
}

int Registro::get_q_saida()const
{
	return q_saida;
}

float Registro::get_apurado()const
{
	return apurado;
}

void Registro::imprimirRegistro()const
{
	cout << "Quantidade de produtos que entraram  no estoque: " << q_entrada << endl;
	cout << "Quantidade de produtos que sairam do estoque: " << q_saida << endl;
	cout << "Saldo total do caixa: "  << saldo << " R$" << endl;
}

float Registro::calcularDespezas()const
{
	float despeza1, despeza2;
	
	vector<Produto>aux = retornaProduto();
	
	for(size_t index = 0; index < aux.size(); index++)
		despeza1 += aux[index].getItem().preco_venda;
	
	vector<Perecivel>auxiliar = retornaPerecivel();
	
	for(size_t index = 0; index < auxiliar.size(); index++)
		despeza2 += auxiliar[index].getItem().preco_venda;
	
	
	return despeza1 + despeza2;
}

void Registro::calcularApurado(size_t index)
{
	vector<Produto>produtos = retornaProduto();
	vector<Perecivel>pereciveis = retornaPerecivel();
	
			apurado = apurado + produtos[index].getItem().preco_venda;
	
}

float Registro::calcularLucro()const
{
	return apurado - calcularDespezas();
}

void Registro::atualizaSaldo()
{
	Registro::set_saldo(saldo + calcularLucro());
}