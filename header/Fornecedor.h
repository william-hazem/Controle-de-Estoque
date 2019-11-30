#ifndef Fornecedor_H
#define Fornecedor_H
#include <iostream>

using namespace std;

class Fornecedor{
   
    private:
        float preco_bruto;
        string distribuidor;
        string CNPJ;
        int data_entrega;
       
    public:
        Fornecedor(float=0, string = " ", string = " ", int = 0);
        float get_preco_bruto()const;
        string get_distribuidor()const;
        string get_CNPJ()const;
        int get_data_entrega()const;
       
};

#endif
