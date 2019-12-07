#ifndef REGISTRO_H
#define REGISTRO_H

#include "Estoque.h"

using namespace std;

class Registro : public Estoque
{
	int q_entrada; // Quantidade de produtos que entraram no estoque
	int q_saida; // Quantidade de produtos que sairam do estoque
	float apurado;
	float saldo;
	
	public:
		Registro();
		void Registrar();
		void set_saldo(float);
		void set_q_saida(int);
    void set_q_entrada();
		float get_saldo()const;
		float get_apurado()const;
		int get_q_entrada()const;
		int get_q_saida()const;
		void imprimirRegistro()const;
		float calcularDespezas()const;
		void calcularApurado(float);
		float calcularLucro()const;
		void atualizaSaldo();
};

#endif
