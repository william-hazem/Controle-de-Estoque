#ifndef REGISTRO_H
#define REGISTRO_H

#include "Estoque.h"

class Registro
{
	float saldo_loja;
	list<string> Registro;
	
	public:
		Registro();
		void salvaRegistro();			//ofstream
		void imprimeRegistro() const;	
		float calcularLucro() const;
		float calcularDespesas() const;
};

#endif
