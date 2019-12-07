#ifndef DATA_H
#define DATA_H

typedef unsigned short int ushort;

class Data
{
private:
  ushort dia;
  ushort mes;
  ushort ano;

public:
  Data(ushort = 1, ushort = 1, ushort = 1);

  bool setData(ushort,ushort,ushort);

  void imprimirData() const;

  ushort getDia() const;
  ushort getMes() const;
  ushort getAno() const;
  unsigned int dataDif(Data) const;
};

#endif // DATA_H