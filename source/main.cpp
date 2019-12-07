#include "..//header//Estoque.h"
#include "..//header//Registro.h"
#include "..//func//wtime.h"    

#include <cstring>
#include <clocale>
#include <iomanip>

//Escopo de funções:
void menu();
int escolha();
Produto_t lerItem();
data_t lerData();
void removerEspaco(Produto_t*);
Data dataSistema();
void imprime(Produto);
void imprime(Perecivel);

//MAIN
int main()
{
  setlocale(LC_ALL,"portuguese");
  //system("func//cdata.bat");
  system("COLOR B");
  
  //Instâncias auxiliares
  Produto_t item;
  Perecivel perecivel;
  Produto produto;
  Registro registro;
  
  //Instância principal
  Estoque estoque;
  //Variáveis
  Data data_atual = dataSistema();
  long codigo;
  string nome, marca, pausar;
  size_t op1, op2, quantidade_produto, x = 0;

  

  do
  {
    menu();
    x = 0;
    while(x == 0)
    {
      try
      {
        op1 = escolha();
        if(op1 < 0 || op1 > 6)
          throw "Você não informou a opção corretamente!";
        else x = 1;
      }
      catch(const char* e)
      {
        cout << "Erro: " << e << endl;
        stopsec(0.5);
      } 
    }
    system("cls||clear");

    switch(op1)
    {
      case 0:
        cout << "Programa Encerrado!!" << endl;
        op1 = 0;
        break;        
      
      case 1:
      {
        cout << "-> Adicionar Produto: " << endl << endl;
        cout << "(1) - Adicionar novo produto" << endl;
        cout << "(2) - Adicionar produto perecivel" << endl;
        cout << "(3) - Adicionar produto existente" << endl;
        cout << "(4) - Voltar ao menu principal" << endl;
        cout << "(0) - Encerrar o programa" << endl;
        x = 0;
        while(x == 0)
        {
          try
          {
            op2 = escolha();
            if(op2 < 0 || op2 > 4)
              throw "Você não informou a opção corretamente!";
            else
              x = 1;
          }
          catch(const char* e)
          {
            cout << "Erro: " << e << endl;
          }
        }
        system("cls||clear");

        switch(op2)
        {
          case 0:
          {
            cout << "Programa Encerrado!!" << endl;
            op1 = 0;
            break;
          }
              
          case 1:
          {
            item = lerItem();
            produto.setItem(item);
            try
            {
              if(estoque.adicionarProduto(produto))
              {
                cout << "Produto adicionado ao estoque." << endl;
                registro.set_q_entrada();
                estoque.salvarProdutos();
                estoque.salvarInfo();
              }
              else
                throw "Não foi possível adicionar o produto. O código utilizado já foi registrado por outro produto.";
            }
            catch(const char* e)
            {
              cout << "Erro: " << e << endl;
            }              
            break;
          }

          case 2:
            {
              
              item = lerItem();
              cout << "Data de validade: (Dia Mês Ano)" << endl;
              data_t data_vencimento = lerData();
              perecivel.setData_validade(data_vencimento);
              perecivel.setItem(item);
              if(estoque.adicionarProduto(perecivel))
              {
                cout << "Produto adicionado ao estoque." << endl;
                estoque.salvarPereciveis();
              }
              else
                cout << "Não foi possível adicionar o produto. O código utilizado já foi registrado por outro produto." << endl;
            }
            break;

          case 3:
          {
            long int codigo;
            int quantidade_produto;
            cout << "Informe o código do produto que deseja adicionar." << endl;
            cin >> codigo; cin.ignore();
            cout << "Quantas unidades serão adicionadas? " << endl;
            cin >> quantidade_produto; cin.ignore();
            if(estoque.adicionarProduto(codigo, quantidade_produto))
            {
              cout << "O produto foi adicionado ao estoque." << endl;
              size_t index = estoque.pesquisarProduto(codigo);
            }
            else
              cout << "Não foi possível adicionar o produto, o código não confere com nenhum produto do estoque." << endl;
            }
            break;

          case 4:
            break;  
        }
        stopsec(0.35);
        estoque.salvarInfo();
        system("cls||clear");
        break;
      }

    case 2:
    {
      cout << "-> Imprimir Dados Ordenados: " << endl << endl;
      cout << "(1) - Ordenar por Nome" << endl;
      cout << "(2) - Ordenar por Categoria" << endl;
      cout << "(3) - Ordenar por Preço" << endl;
      cout << "(4) - Voltar ao menu principal" << endl;
      cout << "(0) - Encerrar o programa" << endl;
      x = 0;
      while(x == 0)
      {
        try
        {
          op2 = escolha();
          if(op2 < 0 || op2 > 4)
            throw "Você não informou a opção corretamente!";
          else
            x = 1;
        }
        catch(const char* e)
        {
          cout << "Erro: " << e << endl;
        }
      }
      system("cls||clear");
      switch(op2)
      {
        case 0:
        {
          cout << "Programa Encerrado!!" << endl;
          op1 = 0;
          break;
        }
          
        case 1:
        {
          estoque.opNome();
          cout << "Produtos ordenados por Nome: " << endl;
          estoque.imprimeProdutos();
          cout << "Produtos Perecíveis ordenados por Nome: " << endl;
          estoque.imprimePereciveis();
          break;
        }
          
        case 2:
        {
          estoque.opCategoria();
          cout << "Produtos ordenados por Categoria: " << endl;
          estoque.imprimeProdutos();
          cout << "Produtos Perecíveis ordenados por Categoria: " << endl;
          estoque.imprimePereciveis();
          break;
        }
        
        case 3:
        {
          estoque.opPreco();
          cout << "Produtos ordenados por Preco: " << endl;
          estoque.imprimeProdutos();
          cout << "Produtos Perecíveis ordenados por Preco: " << endl;
          estoque.imprimePereciveis();
          estoque.salvarInfo();
          break;
        }
        
        case 4:
          break;        
      }
      system("pause") || cin >> pausar;
      system("cls||clear");
      break;
    }
            
    case 3:
    {
      cout << "-> Remover Produto: " << endl << endl;
      cout << "(1) - Remover item usando o código do produto" << endl;
      cout << "(2) - Remover os produtos vencidos" << endl;
      cout << "(3) - Remover prudutos vendidos, a partir de seu código" << endl;
      cout << "(4) - Voltar ao menu principal" << endl;
      cout << "(0) - Encerrar o programa" << endl;
      x = 0;
      while(x == 0)
      {
        try
        {
          op2 = escolha();
          if(op2 < 0 || op2 > 4)
            throw "Você não informou a opção corretamente!";
          else
            x = 1;
        }
        catch(const char* e)
        {
          cout << "Erro: " << e << endl;
        }
      }
      system("cls||clear");
      switch(op2)
      {
        case 0:
        {
          cout << "Programa Encerrado!!" << endl;
          op1 = 0;
          break;
        } 

        case 1:
        {
          cout << "Informe o código do produto:" << endl;
          cin >> codigo;

          size_t index = estoque.pesquisarProduto(codigo);

          if(index < estoque.retornaTamanhoProduto())
          {
            size_t count = estoque.retornaProduto(estoque.pesquisarProduto(codigo)).getItem().quantidade;
            registro.set_q_saida(count);
            registro.calcularApurado(estoque.retornaProduto(estoque.pesquisarProduto(codigo)).getItem().preco_venda);
          }

          if(estoque.remover(codigo))
          {
            cout << "Removido com sucesso..." << endl;
            estoque.salvarProdutos();
            estoque.salvarInfo();
          }
          else
            cout << "Produto não encontrado no estoque" << endl;
          stopsec(0.5);
          break;
        }  

        case 2:
        {
          unsigned short int quantidade;
          cout << "Qual intervalo de dias que deseja efetuar a busca sobre os produtos com data de validade:";
          cin >> quantidade;
          vector<Perecivel> auxiliar = estoque.removerVencido(data_atual, quantidade);

          if(auxiliar.begin() != auxiliar.end())
          {
            cout << "Exibindo produtos vencidos: ( Intervalo de vencimento: " << quantidade << " dia(s) )"  << endl;
            cout << left << "|" <<setw(25) << "Categoria" << "|" << setw(25) << "Nome" << "|" << setw(25) <<"Marca" << "|" << setw(10) << "Data" << "|" << endl;
            cout << setfill('=') << setw(25+25+25+10+5) << " " << endl;
            cout << setfill('.');
          }
          else
            cout << "Não há produtos dentro do prazo de validade estabelicido" << endl;
          
          
          for(size_t index = 0; index < auxiliar.size(); index ++)
          {
            Produto_t item = auxiliar[index].getItem();
            cout << left << "|" << setw(25) << item.categoria << "|" << setw(25) << item.nome_produto << "|" << setw(25) << item.marca << "|" << setw(10) << " " << "|" << endl;
          }
          break;
        }
          
        case 3:
        {
          x = 0;
          while(x == 0)
          {
            try
            {
              cout << "Informe o código do produto - '0' caso deseje voltar ao Menu principal: " << endl;
              cin >> codigo; cin.ignore();
              cout << "Agora informe a quantidade de produtos que foram vendidos: " << endl;
              int quantidade_produto;
              cin >> quantidade_produto; cin.ignore();      
              if(quantidade_produto == 0) 
                x = 1;
              if(estoque.remover(codigo,quantidade_produto))
              {
                cout << "Produto(s) removido(s) com sucesso. " << endl;
                registro.calcularApurado(estoque.pesquisarProduto(codigo));
                x = 1;
              
              }
              else
                throw "Código ou quantidade não conferem.";
            }
            catch(const char* e)
            {
              cout << "Erro: " << e << endl;
            }
          }
          break;    
        }

        case 4:
          break;
      }
        cin >> pausar;
        system("pause");
        system("cls||clear");
        break;
      }

      case 4:
      { 
        cout << "-> Verificar estoque: " << endl << endl;
        cout << "(1) - Pesquisar produto a partir do codigo"<< endl;
        cout << "(2) - Pesquisar produtos perto do vencimento da data de validade e exibi-los" << endl;
        cout << "(3) - Voltar ao menu principal" << endl;
        cout << "(0) - Encerrar o programa" << endl;
        x = 0;
        while(x == 0)
        {
          try
          {
            op2 = escolha();
            if((op2 < 0) || (op2 > 3))
              throw "Você não informou a opção corretamente!";
            else
              x = 1;
          }
          catch(const char* e)
          {
            cout << "Erro: " << e << endl;
          }
        }
        system("cls||clear");
          
        switch(op2)
        {
          case 0:
            cout << "Programa Encerrado!!" << endl;
            op1 = 0;
            break;               

          case 1:
            size_t index, opcao;
            cout << "(1) - Para um não perecível" << endl;
            cout << "(2) - Para um perecível" << endl;
      
            x = 0;
            while(x == 0)
            {
              try
              {
                cin >> opcao; cin.ignore();
                if((opcao < 1) || (opcao > 2))
                  throw "Você não informou a opção corretamente!";
                else
                  x = 1;
              }
              catch(const char* e)
              {
                cout << "Erro: " << e << endl;
              }
            }
            system("cls");

            cout << "Informe o código do produto:" << endl;
            cin >> codigo;
            if (opcao==1)
            {
              index = estoque.pesquisarProduto(codigo);
              Produto auxiliar = estoque.retornaProduto(index);
              cout << "Produto com o respectivo código:" << endl;
              imprime(auxiliar);
              system("pause");
            }

            if (opcao==2)
            {
              index = estoque.pesquisarPerecivel(codigo);
              Perecivel auxiliar = estoque.retornaPerecivel(index);
              cout << "Produto perecível com o respectivo código:" << endl;
              imprime(auxiliar);
              cout << "Data de Vaidade: " << perecivel.dataFormatada() << endl;
              system("pause");
            }
            break;
                
          case 2: 
            vector<Perecivel> perecivel_aux = estoque.retornaPerecivel();
            index = estoque.retornaTamanhoPerecivel();
            cout << "Produtos próximos de se vencer" << endl;
            for(size_t i = 0;i < index;i++){
              if (perecivel_aux[i].tempoValidade(data_atual) < 7)
              {
                Perecivel aux = estoque.retornaPerecivel(i);
                imprime(aux);
                cout << endl;
              }
            } 
            break;             
        }
        
        cin >> pausar;
        system("pause");
        system("cls||clear");
        break;
      }
        
        case 5:
         {
            cout << "->Registro Geral:" << endl;
            cout << "(1) - Quantidade de produtos comprados" << endl;
            cout << "(2) - Quantidade de produtos vendidos" << endl;
            cout << "(3) - Valor gastos nas compras" << endl;
            cout << "(4) - Valor apurado nas vendas" << endl;
            cout << "(5) - Lucro obtido" << endl;
            cout << "(6) - Atualizar o saldo" << endl;
            cout << "(7) - Imprimir Registro" << endl;
            cout << "(8) - Voltar ao menu principal" << endl;
            cout << "(0) - Sair" << endl;
              
            x = 0;
            while(x == 0)
            {
              try
                {
                 op2 = escolha();
                 if((op2 < 0) || (op2 > 7))
                    throw "Você não informou a opção corretamente!";
                  else
                      x = 1;
                  }
                  catch(const char* e)
                  {
                    cout << "Erro: " << e << endl;
                  }
                }
                system("cls||clear");
            
            switch(op2)
            {
              case 0:
                cout << "Programa Encerrado!!";
                op1 = 0;
                break;
              
              case 1:
                registro.set_q_entrada();
                cout << "A quantidade de produtos comprados foram: " << registro.get_q_entrada() << endl;
                break;
              
              case 2:
                cout << "A quantidade de produtos vendidos foram:  " << registro.get_q_saida() << endl;
                break;
              
              case 3: 
                cout << "Valor gastos nas compras: " << registro.calcularDespezas() << " R$." << endl;
                break;
              
              case 4:
                cout << "Valor apurado nas vendas: " << registro.get_apurado() << " R$." << endl;
                break;

              case 5:
                cout << " Lucro obtido: " << registro.calcularLucro() << " R$." << endl;
                break;

              case 6:
                registro.atualizaSaldo();
                cout << "Saldo atualizado!!!" << endl;

              case 7:
                registro.set_q_entrada();
                registro.imprimirRegistro();
                registro.Registrar();
                break;

              case 8:
                break;
            }
          cin >> pausar;
          system("pause");
          system("cls");
          break;
            
        case 6:
        {
          if(estoque.salvarProdutos())
             cout << "Os produtos foram salvos com sucesso." << endl;
            else 
              cout << "Os produtos não foram salvos com êxito." << endl;
            if(estoque.salvarPereciveis())
              cout << "Os produtos perecíveis foram salvos." << endl;
            else
              cout << "Os produtos perecíveis não foram salvos com êxito." << endl;
            if(estoque.salvarInfo())
              cout << "As informações foram salvas com sucesso." << endl;
            else
              cout << "As informações não foram salvas com êxito." << endl;
            stopsec(1.5);
            system("pause");
            system("cls||clear");
            break; 
        }
      
      
      }
    }
  }
  while(op1 != 0);
  return 0;
}


void menu()
{
    /*
    A função têm como objetivo escrever a saída de texto abaixo e minimizar a quantidade de codigos dentro do escopo da main
    */
    Data data_atual = dataSistema();
    cout << "                           ";
    data_atual.imprimirData();
    cout << "====================================" << endl;
    cout << " __   __  _______  __    _  __   __ " << endl;
    cout << "|  |_|  ||       ||  |  | ||  | |  |" << endl;
    cout << "|       ||    ___||   |_| ||  | |  |" << endl;
    cout << "|       ||   |___ |       ||  |_|  |" << endl;
    cout << "|       ||    ___||  _    ||       |" << endl;
    cout << "| ||_|| ||   |___ | | |   ||       |" << endl;
    cout << "|_|   |_||_______||_|  |__||_______|" << endl << endl;
    cout << "====================================" << endl;
    cout << endl << "Menu de opções: " << endl << endl;
    cout << "(1) - Adicionar Produto" << endl;	//Criar opção para adicionar produto existente apartir do código deste

    cout << "(2) - Imprimir Dados Ordenados" << endl;	//Fazer submenu com opões para (1 - com subopções para cada ordenação,
      //depois disso ele deve retornar para o submenu)ordenar e (2)imprimir - verificar a classe estoque.h

    cout << "(3) - Remover Produto" << endl;	//NESTE SUBMENU, deve haver 3 cases. (1) remover um produto do estoque através de seu codigo. (2) retirar uma certa quantidade de produtos do estoque através de seu codigo. (3) remover os produtos vencidos do estoque.

    cout << "(4) - Verificar estoque" << endl;	//Fazer submenu, (1)criar opções para pesquisar algum produto a partir do codigo deste, (2)para dizer se há produtos perto da data de validade e exibi-los
    cout << "(5) - Registro Geral" << endl;		//Fazer submenu, precisa ver com francinildo esta aparte
    cout << "(6) - Salvar" << endl;			//Chamar os métodos salvarProduto, salvarPereciveis, salvarInfo.. exibir de acordo com o retorno se foi possivel ou não salvar o arquivo
    cout << "(0) - Encerrar o programa" << endl;
    //Adicionar um item para voltar para o menu principal para todos os item itens acima
    //Criar uma sáida paradrão notificando que a entrada é invalida para todos os casos acima
}

int escolha()
{
	int opcao;
	cout << endl << "->DIGITE A OPÇÂO DESEJADA: ";
	cin >> opcao; cin.ignore();
	return opcao;
}

Produto_t lerItem()
{
	Produto_t item;
  cout << "Nome do produto: ";
	getline(cin,item.nome_produto);
	cout << "Categoria: ";
	getline(cin,item.categoria);
	cout << "Codigo: ";
	cin >> item.codigo; cin.ignore();
  cout << "Preço de compra: ";
  cin >> item.preco_compra; cin.ignore();
	cout << "Preco de venda: ";
	cin >> item.preco_venda; cin.ignore();
	cout << "Marca: ";
	getline(cin,item.marca);
	cout << "Quantidade: ";
	cin >> item.quantidade;

	return item;
}

data_t lerData()
{
  data_t data;
  while(true)
  {
    ushort dia, mes, ano;
    cout << "Dia | Mês | Ano" << endl;
    cin >> dia >> mes >> ano;
    
    try
    {
      if(!data.setData(dia,mes,ano))
        throw "Erro";
    }
    catch(const char* erro)
    {
      cout << erro << endl;
    }
    break;
  }
  return data;
}

Data dataSistema()
{
  ushort dia, mes, ano;
  time_t timer;
  struct tm *horarioLocal;

  time(&timer);
  horarioLocal = localtime(&timer);

  dia = horarioLocal->tm_mday;
  mes = horarioLocal->tm_mon + 1;
  ano = horarioLocal->tm_year + 1900;

  Data data_atual(dia,mes,ano);
  return data_atual;
}

void imprime(Produto auxiliar)
{
  cout <<"Nome: " << auxiliar.getItem().nome_produto << endl;
  cout <<"Código: " << auxiliar.getItem().codigo << endl;
  cout <<"Marca: " << auxiliar.getItem().marca << endl;
  cout <<"Categoria: " << auxiliar.getItem().categoria << endl;
  cout << "Preço de compra: " << auxiliar.getItem().preco_compra << endl;
  cout <<"Preço de venda: " << auxiliar.getItem().preco_venda << endl;
  cout <<"Quantidade: " << auxiliar.getItem().quantidade << endl;
  stopsec(3);
}

void imprime(Perecivel auxiliar)
{
    cout <<"Nome: " << auxiliar.getItem().nome_produto << endl;
    cout <<"Código: " << auxiliar.getItem().codigo << endl;
    cout <<"Marca: " << auxiliar.getItem().marca << endl;
    cout <<"Categoria: " << auxiliar.getItem().categoria << endl;
    cout << "Preço de compra: " << auxiliar.getItem().preco_compra << endl;
    cout <<"Preço de venda: " << auxiliar.getItem().preco_venda << endl;
    cout <<"Quantidade: " << auxiliar.getItem().quantidade << endl;
    cout <<"Data de validade" << auxiliar.dataFormatada()<<endl;
    stopsec(3);
 } 
