#include "..\\header\\Estoque.h"

#include "..\\func\\wtime.h"	//Minha função by will <3

#include <cstring>

#include <clocale>

#include <iomanip>

#include <utility>

//Escopo de funções
void menu();
int escolha();
Produto_t lerItem();
void removerEspaco(Produto_t*);
long dataSistema();

//MAIN
int main() 
{	
	setlocale(LC_ALL,"portuguese");
	system("func\\cdata.bat");
	
	//Instâncias auxiliares
	Produto_t item;
	Perecivel perecivel;
	Produto produto;
	
	//Instância principal
	Estoque estoque;
	
	//Variáveis
	long data_atual = dataSistema();
	size_t op1, op2;
	size_t sentinela;
	
	system("COLOR B");

	do
	{ 
		menu();
		op1 = escolha();
		sentinela = op1;
		switch(op1)
		{
			case 1:
				
				cout << "->QUAL O TIPO DE ENTRADA: " << endl;
				cout << "(1) - Adicionar novo produto" << endl;
				cout << "(2) - Adicionar produto perecivel" << endl;
				cout << "(3) - Adicionar produto existente" << endl;
				cout << "(4) - Voltar ao menu principal" << endl;
				cout << "(0) - Encerrar o programa" << endl;
				op1 = escolha();
				sentinela = op1;
				switch(op1)
				{
					case 1:
						item = lerItem();
						produto.setItem(item);	
						if(estoque.adicionarProduto(produto))
							cout << "Produto adicionado ao estoque." << endl;
						else
							cout << "Não foi possível adicionar o produto. O código utilizado já foi registrado por outro produto." << endl;	
						estoque.salvarProdutos();
						stopf(1000);
						break;
						
					case 2:
						long int data_vencimento;
						item = lerItem();
						cout << "Data de validade" << endl;
						cin >> data_vencimento; cin.ignore();
						perecivel.setData_validade(data_vencimento);
						perecivel.setItem(item);
						if(estoque.adicionarProduto(perecivel))
							cout << "Produto adicionado ao estoque." << endl;
						else
							cout << "Não foi possível adicionar o produto. O código utilizado já foi registrado por outro produto." << endl;
						estoque.salvarPereciveis();
						stopf(1000);
						break;
						
					case 3:
						long int codigo;
						int quantidade_produto;
						
						cout << "Informe o código do produto que deseja adicionar" << endl;
						cin >> codigo; cin.ignore();
						cout << "Quantas unidades serão adicionadas? " << endl;
						cin >> quantidade_produto; cin.ignore();
						  
						if(estoque.adicionarProduto(codigo, quantidade_produto))
							cout << "O produto foi adicionado." << endl;
						else
							cout << "Não foi possível adicionar o produto; o código não confere." << endl;
						stopf(1000);
						break;
					

					default:
						
				    	break;
				}
				estoque.salvarInfo();
				system("cls");
			break;	
			
			case 2:
    			cout << "(1) Ordenar por Nome" << endl;
    			cout << "(2) Ordenar por Categoria" << endl;
    			cout << "(3) Ordenar por Preço" << endl;
				cout << "(4) - Voltar ao menu principal" << endl;
				cout << "(0) - Encerrar o programa" << endl;
				op1 = escolha();
				sentinela = op1;
				
				switch(op1){
					
					case 1:
						
						estoque.opNome();
						cout << "Produtos ordenados por Nome: " << endl;
						estoque.imprimeProdutos();
						cout << "Produtos Perecíveis ordenados por Nome: " << endl;
						estoque.imprimePereciveis();
						break;
					case 2:
						
						estoque.opCategoria();
						cout << "Produtos ordenados por Categoria: " << endl;
						estoque.imprimeProdutos();
						cout << "Produtos Perecíveis ordenados por Categoria: " << endl;
						estoque.imprimePereciveis();
						break;
					case 3:
						
						estoque.opPreco();
						cout << "Produtos ordenados por Preco: " << endl;
						estoque.imprimeProdutos();
						cout << "Produtos Perecíveis ordenados por Preco: " << endl;
						estoque.imprimePereciveis();
						break;
					
					case 4:
						break;
					default:
						cout << "Opção inválida." << endl;
						break;
				}
				system("pause");
				system("cls");
				break;
				
			case 3:
				cout << "(1) - Remover item usando o código do produto" << endl;
				cout << "(2) - Remover os produtos vencidos" << endl;
				cout << "(3) - Voltar ao menu principal" << endl;
				cout << "(0) - Encerrar o programa" << endl;
				op1 = escolha();
				sentinela = op1;
				switch(op1)
				{
					case 1:
						int codigo;
						cout << "Informe o código do produto:" << endl;
						cin >> codigo;
						if(estoque.remover(codigo))
							cout << "Removido com sucesso" << endl;
						else
							cout << "O código digitado não pertence a nenhum produto" << endl;
						break;
					
					case 2:	// Analisar as condicionais dos métodos e estabelecer uma comunicação com o usuario
						cout << "Exibindo produtos vencidos: ( Intervalo de vencimento: 0 dia(s) )"  << endl;
						cout << left << "|" <<setw(25) << "Categoria" << "|" << setw(25) << "Nome" << "|" << setw(25) <<"Marca" << "|" << setw(10) << "Data" << "|" << endl;
						cout << setfill('=') << setw(25+25+25+10+5) << " " << endl;
						cout << setfill('.');
						vector<Perecivel> auxiliar = estoque.removerVencido(data_atual);
						for(size_t index = 0; index < auxiliar.size(); index ++)
						{
							Produto_t item = auxiliar[index].getItem();
							cout << left << "|" << setw(25) << item.categoria << "|" << setw(25) << item.nome_produto << "|" << setw(25) << item.marca << "|" << setw(10) << auxiliar[index].getData_validade() << "|" << endl;
						}
						system("pause");
						break;
				}
			
			case 4:
				cout << "(1) - Pesquisar produto a partir do codigo"<< endl; 
				cout << "(2) - Pesquisar produtos perto do vencimento da data de validade e exibi-los" << endl;
				cout << "(3) - Voltar ao menu principal" << endl;
				cout << "(0) - Encerrar o programa" << endl;
				op1 = escolha();
				sentinela = op1;
				switch(op1)
				{
					case 1:
						int codigo;
						cout << "Informe o código do produto:" << endl;
						cin >> codigo;
						/*
						if (estoque.pesquisar(codigo))//fazer método que pesquise o produto pelo seu código
							cout << estoque.retornaProduto(codigo) << endl;//fazer um método para retornar o produto pelo seu código
					   	else
					   		cout << "Produto não encontrado."<< endl;
						break;
						*/
					break;
					case 2://este caso será terminado durante o decorrer da semana
					
						//cout    - Não deixar de qualquer jeito os códigos espalhados pelo programa - PS: WILLIAM
						short limite_dias = 3;
						for(short int i = 0; i < estoque.retornaTamanhoPerecivel(); i++){//verificar a forma correta de realizar esse for
							Perecivel auxiliar = estoque.retornaPerecivel(i);
							if(perecivel.tempoValidade(data_atual) < limite_dias)//é necessário percorrer o vector 'pereciveis' e procurar os produtos 
																//com o tempoValidade < limite_dias que pode ser informado pelo usuário
							cout << "Produtos próximos de passarem da data de validade:" << endl;
						}
					break;

				}
				break;
				
			case 5://registro geral
				
				
			case 6:// configurações	
				
							
			break;
			default:
			break;		
		}
	}while(sentinela);

	return 0;
}

void menu()
{
	/*
		A função têm como objetivo escrever a saída de texto abaixo e minimizar a quantidade de codigos dentro do escopo da main
	*/
	long int data_atual = dataSistema();
	cout << "                          " << right << data_atual/1000000 << "/" << data_atual/10000%100 << "/" << data_atual%10000 << endl;
	
	cout << "====================================" << endl;
	cout << " __   __  _______  __    _  __   __ " << endl;
	cout << "|  |_|  ||       ||  |  | ||  | |  |" << endl;
	cout << "|       ||    ___||   |_| ||  | |  |" << endl;
	cout << "|       ||   |___ |       ||  |_|  |" << endl;
	cout << "|       ||    ___||  _    ||       |" << endl;
	cout << "| ||_|| ||   |___ | | |   ||       |" << endl;
	cout << "|_|   |_||_______||_|  |__||_______|" << endl;
	cout << endl;
	cout << "====================================" << endl;
	cout << "\tMenu de opções: " << endl << endl;
	cout << "(1) - Adicionar Produto" << endl;	//Criar opção para adicionar produto existente apartir do código deste
	
	cout << "(2) - Imprimir Dados Ordenados" << endl;	//Fazer submenu com opões para (1 - com subopções para cada ordenação, 
    //depois disso ele deve retornar para o submenu)ordenar e (2)imprimir - verificar a classe estoque.h
	
	cout << "(3) - Remover Produto" << endl;	//NESTE SUBMENU, deve haver 3 cases. (1) remover um produto do estoque através de seu codigo. (2) retirar uma certa quantidade de produtos do estoque através de seu codigo. (3) remover os produtos vencidos do estoque.
	
	cout << "(4) - Verificar estoque" << endl;	//Fazer submenu, (1)criar opções para pesquisar algum produto a partir do codigo deste, (2)para dizer se há produtos perto da data de validade e exibi-los
	cout << "(5) - Registro Geral" << endl;		//Fazer submenu, precisa ver com francinildo esta aparte
	cout << "(6) - Configurações" << endl;
	cout << "(7) - Salvar" << endl;			//Chamar os métodos salvarProduto, salvarPereciveis, salvarInfo.. exibir de acordo com o retorno se foi possivel ou não salvar o arquivo
	cout << "(0) - Encerrar o programa" << endl;
	//Adicionar um item para voltar para o menu principal para todos os item itens acima
	//Criar uma sáida paradrão notificando que a entrada é invalida para todos os casos acima
}

int escolha()
{
	int opcao;
	cout << "->DIGITE A OPÇÂO DESEJADA: ";
	cin >> opcao; cin.ignore();
	system("cls");
	return opcao;
}

Produto_t lerItem()
{
	Produto_t item;
	cout << "Categoria: ";
	getline(cin,item.categoria);
	cout << "Codigo: ";
	cin >> item.codigo; cin.ignore();
	cout << "Preco de venda: ";
	cin >> item.preco_venda; cin.ignore();
	cout << "Marca: ";
	getline(cin,item.marca);
	cout << "Nome do produto: ";
	getline(cin,item.nome_produto);
	cout << "Quantidade: ";
	cin >> item.quantidade;
	
	return item;
}

long dataSistema()
{
	int dia, mes, ano;	
	ifstream arquivo("func\\info\\data.txt");
	arquivo >> dia >> mes >> ano;
	arquivo.close();
	return (dia*1000000 + mes*10000 + ano);
}
