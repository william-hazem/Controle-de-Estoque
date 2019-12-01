#include "..//header//Estoque.h"
#include "..//func//wtime.h"    //Minha função by will <3

#include <cstring>

#include <clocale>

#include <iomanip>
 //Escopo de funções
void menu();
14
	+ int escolha();
15
	+ Produto_t lerItem();
16
	+ void removerEspaco(Produto_t*);
17
	+ long int dataSistema();
18
	+ void imprime(Produto);
19
	+ void imprime(Perecivel);
20
	+
21
	+ //MAIN
22
	+ int main()
23
	+ {
24
	+     setlocale(LC_ALL,"portuguese");
25
	+     system("func\\cdata.bat");
26
	+   system("COLOR B");
27
	+     
28
	+   //Instâncias auxiliares
29
	+     Produto_t item;
30
	+     Perecivel perecivel;
31
	+     Produto produto;
32
	+
33
	+     //Instância principal
34
	+     Estoque estoque;
35
	+
36
	+     //Variáveis
37
	+     long data_atual = dataSistema();
38
	+     long int codigo;
39
	+   size_t op1, op2, quantidade_produto;
40
	+     size_t sentinela, x = 0;
41
	+
42
	+     do
43
	+     {
44
	+         menu();
45
	+         while(x == 0){
46
	+             op1 = escolha();
47
	+             try{
48
	+                 if((op1 < 0) || (op1 > 7)){
49
	+                     throw "Você não informou a opção corretamente!";}
50
	+                 else{x = 1;}
51
	+             }
52
	+             catch(const char* e){
53
	+                 cout << "Erro: " << e << endl;
54
	+               }
55
	+           }
56
	+     system("cls");
57
	+         
58
	+     switch(op1)
59
	+         {

             case 1:
	+                 cout << "->QUAL O TIPO DE ENTRADA: " << endl;
62
	+                 cout << "(1) - Adicionar novo produto" << endl;
63
	+                 cout << "(2) - Adicionar produto perecivel" << endl;
64
	+                 cout << "(3) - Adicionar produto existente" << endl;
65
	+                 cout << "(4) - Voltar ao menu principal" << endl;
66
	+                 cout << "(0) - Encerrar o programa" << endl;
67
	+
68
	+         x = 0;
69
	+         while(x == 0){
70
	+             try{
71
	+               op2 = escolha();
72
	+               if((op2 < 0) || (op2 > 4)){
73
	+               throw "Você não informou a opção corretamente!";}
74
	+               else{x = 1;}
75
	+               }
76
	+               catch(const char* e){
77
	+               cout << "Erro: " << e << endl;
78
	+             }
79
	+           }
80
	+                 system("cls");
81
	+         
82
	+         switch(op2)
83
	+               {
84
	+                     case 1:
85
	+                         item = lerItem();
86
	+                         produto.setItem(item);
87
	+                         if(estoque.adicionarProduto(produto))
88
	+                             cout << "Produto adicionado ao estoque." << endl;
89
	+                         else
90
	+                             cout << "Não foi possível adicionar o produto. O código utilizado já foi registrado por outro produto." << endl;
91
	+                         estoque.salvarProdutos();
92
	+                         stopf(1000);
93
	+                         break;
94
	+
95
	+                     case 2:
96
	+                         long int data_vencimento;
97
	+                         item = lerItem();
98
	+                         cout << "Data de validade:" << endl;
99
	+                         cin >> data_vencimento; cin.ignore();
100
	+                         perecivel.setData_validade(data_vencimento);
101
	+                         perecivel.setItem(item);
102
	+                         if(estoque.adicionarProduto(perecivel))
103
	+                             cout << "Produto adicionado ao estoque." << endl;
104
	+                         else
105
	+                             cout << "Não foi possível adicionar o produto. O código utilizado já foi registrado por outro produto." << endl;
106
	+                         estoque.salvarPereciveis();
107
	+                         stopf(1000);
108
	+                         break;
109
	+
110
	+                     case 3:
111
	+                         cout << "Informe o código do produto que deseja adicionar" << endl;
112
	+                         cin >> codigo; cin.ignore();
113
	+                         cout << "Quantas unidades serão adicionadas? " << endl;
114
	+                         cin >> quantidade_produto; cin.ignore();
115
	+
116
	+                         if(estoque.adicionarProduto(codigo, quantidade_produto))
117
	+                             cout << "O produto foi adicionado." << endl;
118
	+                         else
119
	+                             cout << "Não foi possível adicionar o produto; o código não confere." << endl;
120
	+                         stopf(1000);
121
	+                         break;
122
	+           
123
	+           case 4:
124
	+             break;
125
	+                     
126
	+           case 5:
127
	+             op1 = 0;
128
	+                   }
129
	+             estoque.salvarInfo();
130
	+             system("pause");
131
	+       system("cls");
132
	+
133
	+             case 2:
134
	+             cout << "(1) - Ordenar por Nome" << endl;
135
	+             cout << "(2) - Ordenar por Categoria" << endl;
136
	+             cout << "(3) - Ordenar por Preço" << endl;
137
	+                 cout << "(4) - Voltar ao menu principal" << endl;
138
	+                 cout << "(0) - Encerrar o programa" << endl;
139
	+         
140
	+         x = 0;
141
	+         while(x == 0){
142
	+             try{
143
	+               op2 = escolha();
144
	+               if((op2 < 0) || (op2 > 4)){
145
	+               throw "Você não informou a opção corretamente!";}
146
	+               else{x = 1;}
147
	+               }
148
	+               catch(const char* e){
149
	+               cout << "Erro: " << e << endl;
150
	+                 }
151
	+           }
152
	+         system("cls");
153
	+                 
154
	+         switch(op2)
155
	+         {
156
	+                     case 1:
157
	+                         estoque.opNome();
158
	+                         cout << "Produtos ordenados por Nome: " << endl;
159
	+                         estoque.imprimeProdutos();
160
	+                         cout << "Produtos Perecíveis ordenados por Nome: " << endl;
161
	+                         estoque.imprimePereciveis();
162
	+                         break;
163
	+
164
	+                     case 2:
165
	+                         estoque.opCategoria();
166
	+                         cout << "Produtos ordenados por Categoria: " << endl;
167
	+                         estoque.imprimeProdutos();
168
	+                         cout << "Produtos Perecíveis ordenados por Categoria: " << endl;
169
	+                         estoque.imprimePereciveis();
170
	+                         break;
171
	+
172
	+                     case 3:
173
	+                         estoque.opPreco();
174
	+                         cout << "Produtos ordenados por Preco: " << endl;
175
	+                         estoque.imprimeProdutos();
176
	+                         cout << "Produtos Perecíveis ordenados por Preco: " << endl;
177
	+                         estoque.imprimePereciveis();
178
	+                         break;
179
	+
180
	+                     case 4:
181
	+                         break;
182
	+                     
183
	+           case 0:
184
	+                         op1 = 0;
185
	+                 }
186
	+           system("pause");
187
	+           system("cls");
188
	+
189
	+             case 3:
190
	+                 cout << "(1) - Remover item usando o código do produto" << endl;
191
	+                 cout << "(2) - Remover os produtos vencidos" << endl;
192
	+                 cout << "(3) - Remove uma quantidade de produtos, a partir de seu código" << endl;
193
	+                 cout << "(4) - Voltar ao menu principal" << endl;
194
	+                 cout << "(0) - Encerrar o programa" << endl;
195
	+                 
196
	+         x = 0;
197
	+         while(x == 0){
198
	+             try{
199
	+               op2 = escolha();
200
	+               if((op2 < 0) || (op2 > 4)){
201
	+               throw "Você não informou a opção corretamente!";}
202
	+               else{x = 1;}
203
	+               }
204
	+               catch(const char* e){
205
	+               cout << "Erro: " << e << endl;
206
	+                 }
207
	+           }
208
	+         system("cls");
209
	+                 
210
	+         switch(op2)
211
	+                 {
212
	+                     case 1:
213
	+                         cout << "Informe o código do produto:" << endl;
214
	+                         cin >> codigo;
215
	+                         if(estoque.remover(codigo))
216
	+                             cout << "Produto removido com sucesso." << endl;
217
	+                         else
218
	+                             cout << "O código digitado não pertence a nenhum produto" << endl;
219
	+                         break;
220
	+
221
	+                     case 2:
222
	+                         cout << "Exibindo produtos vencidos: ( Intervalo de vencimento: 0 dia(s) )"  << endl;
223
	+                         cout << left << "|" <<setw(25) << "Categoria" << "|" << setw(25) << "Nome" << "|" << setw(25) <<"Marca" << "|" << setw(10) << "Data" << "|" << endl;
224
	+                         cout << setfill('=') << setw(25+25+25+10+5) << " " << endl;
225
	+                         cout << setfill('.');
226
	+                         vector<Perecivel> auxiliar = estoque.removerVencido(data_atual);
227
	+                         for(size_t index = 0; index < auxiliar.size(); index ++)
228
	+                         {
229
	+                             Produto_t item = auxiliar[index].getItem();
230
	+                             cout << left << "|" << setw(25) << item.categoria << "|" << setw(25) << item.nome_produto << "|" << setw(25) << item.marca << "|" << setw(10) << auxiliar[index].getData_validade() << "|" << endl;
231
	+                         }
232
	+                         break;
233
	+
234
	+                     case 3:
235
	+            cout << "Informe o código do produto: " << endl;
236
	+            cin >> codigo; cin.ignore();
237
	+            cout << "Agora informe a quantidade de produtos que serão removidos: " << endl;
238
	+                      cin >> quantidade_produto; cin.ignore();
239
	+
240
	+                         if(estoque.remover(codigo,quantidade_produto))
241
	+                             cout << "Produto(s) removido(s) com sucesso. " << endl;
242
	+                         else
243
	+                             cout << "Código ou quantidade não conferem." << endl;
244
	+           
245
	+           case 4:
246
	+             break;
247
	+
248
	+           case 0:
249
	+             op1 = 0;
250
	+                   }
251
	+       system("pause");
252
	+             system("cls");
253
	+               
254
	+       case 4:
255
	+                 cout << "(1) - Pesquisar produto a partir do codigo"<< endl;
256
	+                 cout << "(2) - Pesquisar produtos perto do vencimento da data de validade e exibi-los" << endl;
257
	+                 cout << "(3) - Voltar ao menu principal" << endl;
258
	+                 cout << "(0) - Encerrar o programa" << endl;
259
	+                 
260
	+                 x = 0;
261
	+         while(x == 0){
262
	+             try{
263
	+               op2 = escolha();
264
	+               if((op2 < 0) || (op2 > 3)){
265
	+               throw "Você não informou a opção corretamente!";}
266
	+               else{x = 1;}
267
	+               }
268
	+               catch(const char* e){
269
	+               cout << "Erro: " << e << endl;
270
	+                 }
271
	+           }
272
	+       system("cls");
273
	+         
274
	+         switch(op2)
275
	+                 {
276
	+                     case 1:
277
	+                         size_t index, opcao;
278
	+                         cout << "(1) - Para um não perecível" << endl;
279
	+                         cout << "(2) - Para um perecível" << endl;
280
	+                         
281
	+             x = 0;
282
	+             while(x == 0){
283
	+               try{
284
	+                 cin >> opcao; cin.ignore();
285
	+                 if((opcao < 1) || (opcao > 2)){
286
	+                 throw "Você não informou a opção corretamente!";}
287
	+                 else{x = 1;}
288
	+               }
289
	+               catch(const char* e){
290
	+               cout << "Erro: " << e << endl;
291
	+                 }
292
	+               }
293
	+             system("cls");
294
	+             
295
	+             cout << "Informe o código do produto:" << endl;
296
	+                         cin >> codigo;
297
	+                         if (opcao==1){
298
	+                            index = estoque.pesquisarProduto(codigo);
299
	+                            Produto auxiliar = estoque.retornaProduto(index);
300
	+                            cout << "Produto com o respectivo código:" << endl;
301
	+                            imprime(auxiliar);
302
	+                         }
303
	+                         if (opcao==2){
304
	+                             index = estoque.pesquisarPerecivel(codigo);
305
	+                             Perecivel auxiliar = estoque.retornaPerecivel(index);
306
	+                             cout << "Produto perecível com o respectivo código:" << endl;
307
	+                             imprime(auxiliar);
308
	+                             cout << "Data de Vaidade: " << perecivel.getData_validade() << endl;
309
	+             }
310
	+              break;
311
	+                     case 2: 
312
	+             long data;
313
	+                         cout << "Informe a data atual: " << endl;
314
	+                         cin >> data; cin.ignore();
315
	+                         vector<Perecivel> perecivel_aux = estoque.retornaPerecivel();
316
	+                         index = estoque.retornaTamanhoPerecivel();
317
	+                         cout << "Produtos próximos de se vencer" << endl;
318
	+                         for(size_t i = 0;i < index;i++){
319
	+                             if (perecivel_aux[i].tempoValidade(data) < 3){
320
	+                                     Perecivel aux = estoque.retornaPerecivel(i);
321
	+                                     imprime(aux);
322
	+                                     cout << endl;
323
	+                             }
324
	+                         }
325
	+                       break;
326
	+         
327
	+                   case 3:
328
	+             break;
329
	+           case 0:
330
	+             op1 = 0;
331
	+         }
332
	+             case 5://registro geral
333
	+         break;
334
	+             case 6:// configurações
335
	+
336
	+               break;
337
	+         
338
	+             default: 
339
	+               break;
340
	+         }
341
	+     }while(op1);
342
	+
343
	+     return 0;
344
	+ }
345
	+
346
	+ void menu()
347
	+ {
348
	+     /*
349
	+         A função têm como objetivo escrever a saída de texto abaixo e minimizar a quantidade de codigos dentro do escopo da main
350
	+     */
351
	+     long int data_atual = dataSistema();
352
	+     cout << "                          " << right << data_atual/1000000 << "/" << data_atual/10000%100 << "/" << data_atual%10000 << endl;
353
	+
354
	+     cout << "====================================" << endl;
355
	+     cout << " __   __  _______  __    _  __   __ " << endl;
356
	+     cout << "|  |_|  ||       ||  |  | ||  | |  |" << endl;
357
	+     cout << "|       ||    ___||   |_| ||  | |  |" << endl;
358
	+     cout << "|       ||   |___ |       ||  |_|  |" << endl;
359
	+     cout << "|       ||    ___||  _    ||       |" << endl;
360
	+     cout << "| ||_|| ||   |___ | | |   ||       |" << endl;
361
	+     cout << "|_|   |_||_______||_|  |__||_______|" << endl;
362
	+     cout << endl;
363
	+     cout << "====================================" << endl;
364
	+     cout << "\tMenu de opções: " << endl << endl;
365
	+     cout << "(1) - Adicionar Produto" << endl;    //Criar opção para adicionar produto existente apartir do código deste
366
	+
367
	+     cout << "(2) - Imprimir Dados Ordenados" << endl;    //Fazer submenu com opões para (1 - com subopções para cada ordenação,
368
	+     //depois disso ele deve retornar para o submenu)ordenar e (2)imprimir - verificar a classe estoque.h
369
	+
370
	+     cout << "(3) - Remover Produto" << endl;    //NESTE SUBMENU, deve haver 3 cases. (1) remover um produto do estoque através de seu codigo. (2) retirar uma certa quantidade de produtos do estoque através de seu codigo. (3) remover os produtos vencidos do estoque.
371
	+
372
	+     cout << "(4) - Verificar estoque" << endl;    //Fazer submenu, (1)criar opções para pesquisar algum produto a partir do codigo deste, (2)para dizer se há produtos perto da data de validade e exibi-los
373
	+     cout << "(5) - Registro Geral" << endl;        //Fazer submenu, precisa ver com francinildo esta aparte
374
	+     cout << "(6) - Configurações" << endl;
375
	+     cout << "(7) - Salvar" << endl;            //Chamar os métodos salvarProduto, salvarPereciveis, salvarInfo.. exibir de acordo com o retorno se foi possivel ou não salvar o arquivo
376
	+     cout << "(0) - Encerrar o programa" << endl;
377
	+     //Adicionar um item para voltar para o menu principal para todos os item itens acima
378
	+     //Criar uma sáida paradrão notificando que a entrada é invalida para todos os casos acima
379
	+ }
380
	+
381
	+ int escolha()
382
	+ {
383
	+     int opcao;
384
	+     cout << "->DIGITE A OPÇÂO DESEJADA: ";
385
	+     cin >> opcao; cin.ignore();
386
	+     system("cls");
387
	+     return opcao;
388
	+ }
389
	+
390
	+ Produto_t lerItem()
391
	+ {
392
	+     Produto_t item;
393
	+     cout << "Categoria: ";
394
	+     getline(cin,item.categoria); cin.ignore();
395
	+     cout << "Codigo: ";
396
	+     cin >> item.codigo; cin.ignore();
397
	+     cout << "Preco de venda: ";
398
	+     cin >> item.preco_venda; cin.ignore();
399
	+     cout << "Marca: ";
400
	+     getline(cin,item.marca);cin.ignore();
401
	+     cout << "Nome do produto: ";
402
	+     getline(cin,item.nome_produto); cin.ignore();
403
	+     cout << "Quantidade: ";
404
	+     cin >> item.quantidade;cin.ignore();
405
	+
406
	+     return item;
407
	+ }
408
	+
409
	+ long int dataSistema()
410
	+ {
411
	+     int dia, mes, ano;
412
	+     ifstream arquivo("func\\info\\data.txt");
413
	+     arquivo >> dia >> mes >> ano;
414
	+     arquivo.close();
415
	+     return (dia*1000000 + mes*10000 + ano);
416
	+ }
417
	+
418
	+ void imprime(Produto auxiliar)
419
	+ {
420
	+     cout <<"Nome: " << auxiliar.getItem().preco_venda << endl;
421
	+     cout <<"Código: " << auxiliar.getItem().preco_venda << endl;
422
	+     cout <<"Marca: " << auxiliar.getItem().marca << endl;
423
	+     cout <<"Categoria: " << auxiliar.getItem().categoria << endl;
424
	+     cout <<"Preço de venda: " << auxiliar.getItem().preco_venda << endl;
425
	+     cout <<"Quantidade: " << auxiliar.getItem().quantidade << endl;;
426
	+
427
	+ }
428
	+
429
	+ void imprime(Perecivel auxiliar)
430
	+ {
431
	+     cout <<"Nome: " << auxiliar.getItem().preco_venda << endl;
432
	+     cout <<"Código: " << auxiliar.getItem().preco_venda << endl;
433
	+     cout <<"Marca: " << auxiliar.getItem().marca << endl;
434
	+     cout <<"Categoria: " << auxiliar.getItem().categoria << endl;
435
	+     cout <<"Preço de venda: " << auxiliar.getItem().preco_venda << endl;
436
	+     cout <<"Quantidade: " << auxiliar.getItem().quantidade << endl;;
437
	+     cout <<"Data de validade" << auxiliar.getData_validade()<<endl;
 } 