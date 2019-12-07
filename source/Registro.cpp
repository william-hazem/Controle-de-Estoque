#include "..//header//Registro.h"

Registro::Registro()
{
	saldo = 0;
	apurado = 0;
	q_entrada = 0;
	q_saida = 0;
}

void Registro::Registrar()
{
	ofstream arquivo("Reg_01.txt",ios::app);
	
  arquivo << q_entrada << endl;
	arquivo << q_saida << endl;
	arquivo << calcularDespezas() << endl;
	arquivo << apurado << endl;
	arquivo << calcularLucro() << endl;
  cout << "Registro finalizado!!!" << endl;
}

void Registro::set_saldo(float saldo)
{
	this ->saldo = saldo;
}

void Registro::set_q_entrada()
{
  int q_entrada1 = 0, q_entrada2 = 0; 

	vector<Produto> auxilar = retornaProduto();

	for(size_t index = 0; index < auxilar.size(); index++)
		q_entrada1 += auxilar[index].getItem().quantidade;

	vector<Perecivel> aux  = retornaPerecivel();
	
	for(size_t index = 0; index < aux.size(); index++)
		q_entrada2 += aux[index].getItem().quantidade;

  q_entrada = q_entrada1 + q_entrada2;
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
	cout << "Apurado total com vendas: " << apurado << " R$" << endl;
	cout << "Despeza total com compras: " << calcularDespezas() << " R$" << endl;
	cout << "Lucro de compra e venda: " << calcularLucro() << " R$" << endl;
	cout << "Saldo total do caixa: "  << saldo << " R$" << endl;
}

float Registro::calcularDespezas()const
{
	float despeza1 = 0, despeza2 = 0;
	
	vector<Produto>aux = retornaProduto();
	
	for(size_t index = 0; index < aux.size(); index++)
		despeza1 += (aux[index].getItem().preco_compra * aux[index].getItem().quantidade);
	
	vector<Perecivel>auxiliar = retornaPerecivel();
	
	for(size_t index = 0; index < auxiliar.size(); index++)
		despeza2 +=  (auxiliar[index].getItem().preco_compra * auxiliar[index].getItem().quantidade);
	
	
	return despeza1 + despeza2;
}

void Registro::calcularApurado(float precoVenda)
{ 
  apurado += (precoVenda * q_saida);
}

float Registro::calcularLucro()const
{
	return apurado - calcularDespezas();
}

void Registro::atualizaSaldo()
{
	Registro::set_saldo(saldo + calcularLucro());
}