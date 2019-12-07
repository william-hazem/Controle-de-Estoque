#include "..//header//Data.h"
#include <iostream>
using std::cout;

Data::Data(ushort dia, ushort mes, ushort ano)
{
  setData(dia,mes,ano);
}

bool Data::setData(ushort dia, ushort mes, ushort ano)
{
  if(dia < 1 || dia > 31 || mes < 1 || mes > 12 || ano == 0)
    return 0;
    
  this->dia = dia;
  this->mes = mes;
  this->ano = ano;
  return 1;
}

void Data::imprimirData() const
{
  cout << dia << "/" << mes << "/" << ano << '\n';
}

ushort Data::getDia() const
{
  return this->dia;
}

ushort Data::getMes() const
{
  return this->mes;
}

ushort Data::getAno() const
{
  return this->ano;
}

unsigned int Data::dataDif(Data data) const
{
  unsigned int diferenca = 0;
  ushort aux = data.getDia();

  if(this->dia > aux)
    diferenca += this->dia - aux;
  else
    diferenca += aux - this->dia;

  aux = data.getMes();
  if(this->mes > aux)
    diferenca += (this->mes - aux)*30;
  else
    diferenca += (aux - this->mes)*30;
  
  aux = data.getAno();
  if(this->ano > aux)
    diferenca += (this->ano - aux)*365;
  else
    diferenca += (aux - this->ano)*365;

  return diferenca;
}
