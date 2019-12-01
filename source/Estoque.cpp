#include "..//header//Estoque.h"
#include "..//func//OverLoad.h"

//Construtor - inicialização dos dados salvos anteriormente
Estoque::Estoque()
{
	long int data;
	size_t qProduto = 0, qPerecivel = 0;
	ifstream arquivo_info;
	arquivo_info.open("func//info//Info.txt");
	
	if(arquivo_info.is_open())
	{
		arquivo_info >> qProduto >> qPerecivel;
		arquivo_info.close();
		
		if(qProduto != 0)
		{
			ifstream arquivo_leitura;
			arquivo_leitura.open("func//info//Produto.txt");
			if(!arquivo_leitura.is_open())
				cerr << endl;
			else
				for(size_t contador = 0; contador < qProduto; contador++)
				{
					Produto produto;
					arquivo_leitura >> produto;
					adicionarProduto(produto);
				}
			arquivo_leitura.close();
		}
			
		if(qPerecivel != 0)
		{
			ifstream arquivo_leitura;
			arquivo_leitura.open("func//info//Perecivel.txt");
			if(!arquivo_leitura.is_open())
				cerr << "func//info//Perecivel.tx n�o pode ser aberto" << endl;
			else
				for(size_t contador = 0; contador < qPerecivel; contador++)
				{
					Perecivel perecivel;
					arquivo_leitura >> perecivel;
					adicionarProduto(perecivel);
				}
			arquivo_leitura.close();
		}
	}
}

//Destrutor - salva os dados ao fim do escopo
Estoque::~Estoque()
{
	if(salvarProdutos())
		cerr << "Salvo com sucesso - Entrada 1" << endl;
	else
		cerr << "N�o foi poss�vel salvar o arquivo - Entrada 1" << endl;
	if(salvarPereciveis())
		cerr << "Salvo com sucesso - Entrada 2" << endl;
	else
		cerr << "N�o foi poss�vel salvar o arquivo - Entrada 2" << endl;
		
	salvarInfo();
}

//AdicionarProduto com sobrecargas locais
bool Estoque::adicionarProduto(Produto novoItem)
{
	if(pesquisarProduto(novoItem.getItem().codigo) == produtos.size()+1 && pesquisarPerecivel(novoItem.getItem().codigo) == pereciveis.size()+1)
	{
		produtos.push_back(novoItem);
		return true;
	}
	return false;
}

bool Estoque::adicionarProduto(Perecivel novoItem)
{
	if(pesquisarProduto(novoItem.getItem().codigo) == produtos.size()+1 && pesquisarPerecivel(novoItem.getItem().codigo) == pereciveis.size()+1)
	{
		pereciveis.push_back(novoItem);
		return true;	
	}
	return false;
}

bool Estoque::adicionarProduto(long int codigo, long int quantidade)
{
	//H� componentes no vector produtos?
	if(produtos.begin() == produtos.end())
		return false;
	else	//Busca se existe algum produto existente
	if(size_t index = pesquisarProduto(codigo) != produtos.size()+1)
	{
		produtos[index].setQuantidade(produtos[index].getItem().quantidade + quantidade);
		return true;
	}
	//H� componentes no vector pereciveis?
	if(pereciveis.begin() == pereciveis.end())
		return false;
	else
	if (size_t index = pesquisarPerecivel(codigo) != pereciveis.size()+1)
	{
		pereciveis[index].setQuantidade(pereciveis[index].getItem().quantidade + quantidade);
		return true;	
	}
	
	return false;
}

bool Estoque::remover(long codigo)
{
	size_t index = pesquisarProduto(codigo);
	if(index < produtos.size())
	{
		produtos.erase(produtos.begin()+index,produtos.begin()+index+1);
		return true;
	}
	else
	{
		index = pesquisarPerecivel(codigo);
		if(index < pereciveis.size())
		{
			pereciveis.erase(pereciveis.begin()+index,pereciveis.begin()+index+1);
			return true;
		}
		else
			return false;
	}
}

bool Estoque::remover(long codigo, size_t quantidade)
{
	size_t index = pesquisarProduto(codigo);
	if(index < produtos.size()) 
		if(produtos[index].getItem().quantidade > quantidade)
			produtos[index].setQuantidade(produtos[index].getItem().quantidade - quantidade);
		else
			produtos.erase(produtos.begin()+index);
	else
	{
		index = pesquisarPerecivel(codigo);
		if(index < pereciveis.size())
			if (pereciveis[index].getItem().quantidade > quantidade)
				pereciveis[index].setQuantidade(pereciveis[index].getItem().quantidade - quantidade);
			else
				pereciveis.erase(pereciveis.begin()+index);
		else
			return false;
	}
	
	return true;
}

size_t Estoque::pesquisarProduto(long codigo) const
{	
	for(size_t index = 0; index < produtos.size(); index++)
		if(produtos[index].getItem().codigo == codigo)
			return index;
			
	return produtos.size()+1;
}

size_t Estoque::pesquisarPerecivel(long codigo) const
{
	for(size_t index = 0; index < pereciveis.size(); index++)
		if(pereciveis[index].getItem().codigo == codigo)
			return index;
			
	return pereciveis.size()+1;
}

bool Estoque::checarVencimento(size_t index, long data_atual, short limite) const
{
	if(pereciveis[index].tempoValidade(data_atual) <= limite)
		return true;
	return false;
}
vector<Perecivel> Estoque::retornaVencido(long data_atual, short limite) const
{
  vector<Perecivel> auxiliar;
  for(size_t index = 0; index < pereciveis.size(); index++)
    if(checarVencimento(index,data_atual,limite))
      auxiliar.push_back(pereciveis[index]);

  return auxiliar;
}

vector<Perecivel> Estoque::removerVencido(long data_global, short limite)
{
	vector<Perecivel> auxiliar;
	if(pereciveis.begin() != pereciveis.end())
	{
		vector<Perecivel>::const_iterator it = pereciveis.begin();
		for(size_t index = 0; index < pereciveis.size(); index++)
		{
			if(checarVencimento(index, data_global, limite))
			{
				auxiliar.push_back(pereciveis[index]);
				pereciveis.erase(it+index,it+index+1);
			}
		}
		return auxiliar;
	}
	return auxiliar = {};
}

//Retorno de um objeto
Produto Estoque::retornaProduto(size_t index) const
{
	return this->produtos[index];
}

Perecivel Estoque::retornaPerecivel(size_t index) const
{
	return this->pereciveis[index];
}

//Retorno de uma lista de objetos
vector<Produto> Estoque::retornaProduto() const
{
	return this->produtos;
}

vector<Perecivel> Estoque::retornaPerecivel() const
{
	return pereciveis;
}

size_t Estoque::retornaTamanhoProduto() const
{
	if(produtos.begin() != produtos.end())
		return produtos.size();
	return 0;
}

size_t Estoque::retornaTamanhoPerecivel() const
{
	if(pereciveis.begin() != pereciveis.end())
		return pereciveis.size();
	return 0;
}

bool Estoque::salvarProdutos()
{
	if(produtos.begin() == produtos.end()) 
		cerr << endl;
		
	ofstream arquivo;
	arquivo.open("func//info//Produto.txt");
	if(!arquivo.is_open())
		return false;
	
	arquivo <<produtos[0];
	for(size_t index = 1; index < retornaTamanhoProduto(); index++)
	{
		arquivo << endl;
		arquivo << produtos[index];
	}
	arquivo.close();
	
	return true;
}

bool Estoque::salvarPereciveis()
{
	if(pereciveis.begin() == pereciveis.end())
		return false;
	
	ofstream arquivo;
	arquivo.open("func//info//Perecivel.txt");
	if(!arquivo.is_open())
		return false;

	arquivo << pereciveis[0];
	for(size_t index = 1; index < retornaTamanhoPerecivel(); index++)
	{
		arquivo << endl;
		arquivo << pereciveis[index];
	}
	arquivo.close();
	
	return true;
}

bool Estoque::salvarInfo()
{
	ofstream arquivo;
	arquivo.open("func//info//Info.txt");
	
	if(!arquivo.is_open())
		return false;
	
	arquivo << retornaTamanhoProduto() << '\t' << retornaTamanhoPerecivel();
	arquivo.close();
	return true;
}

//M�todos ordenadores
void Estoque::opNome()
{
	for(size_t index = 0; index < produtos.size(); index++)
		for(size_t index = 0; index < produtos.size(); index++)
			if(index+1 < produtos.size() && produtos[index].getItem().nome_produto.compare(produtos[index+1].getItem().nome_produto) > 0) 
			{
				Produto aux = produtos[index];
				produtos[index] = produtos[index+1];
				produtos[index+1] = aux;
			}
			
	for(size_t index = 0; index < pereciveis.size(); index++)
		for(size_t index = 0; index < pereciveis.size(); index++)
			if(index+1 < pereciveis.size() && pereciveis[index].getItem().nome_produto.compare(pereciveis[index+1].getItem().nome_produto) > 0) 
			{
				Perecivel aux = pereciveis[index];
				pereciveis[index] = pereciveis[index+1];
				pereciveis[index+1] = aux;
			}
}

void Estoque::opPreco()
{	
	for(size_t i = 0; i < produtos.size() ; i++)
		for(size_t i = 0; i < produtos.size() ; i++)
			if(i+1 < produtos.size() && produtos[i].getItem().preco_venda > produtos[i+1].getItem().preco_venda)
			{
				Produto aux = produtos[i];
				produtos[i] = produtos[i + 1];
				produtos[i + 1] = aux;
			}
			
    for(size_t i = 0; i < pereciveis.size() ; i++)
		for(size_t i = 0; i < pereciveis.size() ; i++)
			if(i+1 < pereciveis.size() && pereciveis[i].getItem().preco_venda > pereciveis[i + 1].getItem().preco_venda)
			{
				Perecivel aux = pereciveis[i];
				pereciveis[i] = pereciveis[i + 1];
				pereciveis[i + 1] = aux;
			}	
}

void Estoque::opCategoria()
{
	for(size_t i = 0; i < produtos.size() ; i++)
		for(size_t i = 0; i < produtos.size() ; i++)
			if(i+1 < produtos.size() && produtos[i].getItem().codigo > produtos[i + 1].getItem().codigo)
			{
				Produto aux = produtos[i];
				produtos[i] = produtos[i + 1];
				produtos[i + 1] = aux;
			}

    for(size_t i = 0; i < pereciveis.size() ; i++)
		for(size_t i = 0; i < pereciveis.size() ; i++)
			if(i+1 < pereciveis.size() && pereciveis[i].getItem().codigo > pereciveis[i + 1].getItem().codigo)
			{
				Perecivel aux = pereciveis[i];
				pereciveis[i] = pereciveis[i + 1];
				pereciveis[i + 1] = aux;
			}		
}

//M�todos de impress�o
void Estoque::imprimeProdutos() const
{
	cout << "Produtos n�o pereciveis: " << endl << endl;
	
	for(int i = 0 ; i < produtos.size() ; i++)
	{
		cout << "Produto " << i + 1 << endl << endl;
		cout << "Nome: " << produtos[i].getItem().nome_produto << endl;
		cout << "Categoria: " << produtos[i].getItem().categoria << endl;
		cout << "Marca: " << produtos[i].getItem().marca << endl;
		cout << "Preco: " << produtos[i].getItem().preco_venda << endl;
		cout << "Quantidade: " << produtos[i].getItem().quantidade << endl;
		cout << "Codigo: " << produtos[i].getItem().codigo << endl << endl;
	}
}

void Estoque::imprimePereciveis() const
{
	cout << "Produtos pereciveis: " << endl << endl;
	
	for(int i = 0 ; i < pereciveis.size() ; i++)
	{
		cout << "Produto " << i + 1 << endl << endl;
		cout << "Nome: " << pereciveis[i].getItem().nome_produto << endl;
		cout << "Categoria: " << pereciveis[i].getItem().categoria << endl;
		cout << "Marca: " << pereciveis[i].getItem().marca << endl;
		cout << "Preco: " << pereciveis[i].getItem().preco_venda << endl;
		cout << "Quantidade: " << pereciveis[i].getItem().quantidade << endl;
		cout << "Codigo: " << pereciveis[i].getItem().codigo << endl;
		cout << "Validade: " << pereciveis[i].getData_validade() << endl << endl;
	}
}
