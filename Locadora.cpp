/*
VINICIUS BUENO GERMINIANI
RA 262515342
*/

//-------------------------------------------------------------------------------BIBLIOTECAS

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <conio2.h>
#include <windows.h>

//-----------------------------------------------------------------------------------GLOBAIS

#define TF 100

//-----------------------------------------------------------------------------------STRUCTS
struct TpClientes{
	char nome[30],cpf[16],telefone[14];
	int QtdLocacoes;
}TabClientes[TF];

struct TpCarros{
	int codCar;
	char modelo[15], categ[15];
	float precoDiaria;
}TabCarros[TF];

struct TpLocacoes{
	char cpf[16];
	int codCar,QtdeDias;
	float ValorLocacao;
}TabLocacoes[TF];


//--------------------------------------------------------------------------------PROTOTIPOS
//Menus
void menuPrincipal();
void menuClientes(TpClientes TabClientes[TF], int &TL);
void menuCarros(TpCarros TabCarros[TF],int &TL,int TLloc);
void menuLocacoes(TpLocacoes TabLocacoes[TF],TpCarros TabCarros[TF],TpClientes TabClientes[TF],int TLcarro, int TLcliente, int &TLloc);
void menuRelatorios(TpLocacoes TabLocacoes[TF],TpCarros TabCarros[TF],TpClientes TabClientes[TF],int TLcarro, int TLcliente, int TLloc);
void Moldura(int CI, int LI, int CF, int LF, int CorT, int CorF);
void MolduraMenor(int CI, int LI, int CF, int LF, int CorT);


//Cadastros
void inserirDados(TpClientes TabClientes[TF],TpCarros TabCarros[TF],TpLocacoes TabLocacoes[TF],int &TLclientes,int &TLcarros,int &TLloc);
void CadastroCliente(TpClientes TabClientes[TF],int &TL);
void CadastroCarro(TpCarros TabCarros[TF],int &TL);
void InsertionSortCliente(TpClientes TabClientes[TF], int &TL);
void InsertionSortCarro(TpCarros TabCarros[TF],int TL);
void CadastrarLocacao(TpLocacoes TabLocacoes[TF],int TLcarro,int TLcliente,int &TLloc);
void SelectionSortCarroPorCod(TpCarros TabCarros[TF], int TL);

//Exclusões
void ExcluirCliente(TpClientes TabClientes[TF],int &TL);
void ExcluirCarro(TpCarros TabCarros[TF],int &TL,int TLloc);
void ExcluirLocacao(TpLocacoes TabLocacoes[TF],int &TL);

//Editar
void EditarCliente(TpClientes TabClientes[TF],int &TL);
void EditarCarro(TpCarros TabCarros[TF],int &TL);
void EditarLocacao(TpLocacoes TabLocacoes[TF],TpCarros TabCarros[TF],int &TL,int TLcliente,int TLcarro);

//Relatorios
void Relatorio1_Listar3Maiores(int TLcliente,int TLloc);
void Relatorio2_CarrosPorCategoria(TpCarros TabCarros[TF], int TLcarro);
void Relatorio3_LocacoesPorValor(TpLocacoes TabLocacoes[TF], int TLloc);
void Relatorio4_RelatorioCompleto(TpLocacoes TabLocacoes[TF], TpCarros TabCarros[TF], TpClientes TabClientes[TF], int TLcarro, int TLcliente, int TLloc);

//Listagem
void ListarClientes(TpClientes TabClientes[TF],int TL);
void ListarCarro(TpCarros TabCarros[TF],int TL);
void ListarLocacao(TpLocacoes TabLocacoes[TF],int TL);
//---------------------------------------------------------main
int main(void){
	menuPrincipal();
	return 0;
}
//---------------------------------------------------------aplicacoes
//utilizaveis
void inserirDados(TpClientes TabClientes[TF],TpCarros TabCarros[TF],TpLocacoes TabLocacoes[TF],int &TLclientes,int &TLcarros,int &TLloc){
	strcpy(TabClientes[0].cpf, "463.033.618-46");
	strcpy(TabClientes[0].nome, "Antonio");
	strcpy(TabClientes[0].telefone, "(18)23565-3232");
	TabClientes[0].QtdLocacoes=5;
	
	strcpy(TabClientes[1].cpf, "321.312.121-11");
	strcpy(TabClientes[1].nome, "Bruno");
	strcpy(TabClientes[1].telefone, "(18)584928-9685");
	TabClientes[1].QtdLocacoes=5;
    
    strcpy(TabClientes[2].cpf, "111.222.333-44");
    strcpy(TabClientes[2].nome, "Camila");
    strcpy(TabClientes[2].telefone, "(18)98765-4321");
    TabClientes[2].QtdLocacoes=1;

    strcpy(TabClientes[3].cpf, "555.666.777-88");
    strcpy(TabClientes[3].nome, "Davi");
    strcpy(TabClientes[3].telefone, "(18)24680-1357");
    TabClientes[3].QtdLocacoes=2;

    strcpy(TabClientes[4].cpf, "999.000.111-22");
    strcpy(TabClientes[4].nome, "Eduarda");
    strcpy(TabClientes[4].telefone, "(18)36925-8147");
    TabClientes[4].QtdLocacoes=3;

    strcpy(TabClientes[5].cpf, "333.444.555-66");
    strcpy(TabClientes[5].nome, "Felipe");
    strcpy(TabClientes[5].telefone, "(18)11223-3445");
    TabClientes[5].QtdLocacoes=6;

    strcpy(TabClientes[6].cpf, "777.888.999-00");
    strcpy(TabClientes[6].nome, "Gabriela");
    strcpy(TabClientes[6].telefone, "(18)55667-7889");
    TabClientes[6].QtdLocacoes=1;

    strcpy(TabClientes[7].cpf, "222.111.000-99");
    strcpy(TabClientes[7].nome, "Hugo");
    strcpy(TabClientes[7].telefone, "(18)99001-1223");
    TabClientes[7].QtdLocacoes=3;
    
    strcpy(TabClientes[8].cpf, "666.555.444-33");
    strcpy(TabClientes[8].nome, "Isabella");
    strcpy(TabClientes[8].telefone, "(18)33445-5667");
    TabClientes[8].QtdLocacoes=5;

    strcpy(TabClientes[9].cpf, "101.202.303-40");
    strcpy(TabClientes[9].nome, "João");
    strcpy(TabClientes[9].telefone, "(18)77889-9001");
    TabClientes[9].QtdLocacoes=1;

    strcpy(TabClientes[10].cpf, "505.404.303-20");
    strcpy(TabClientes[10].nome, "Laura");
    strcpy(TabClientes[10].telefone, "(18)10203-0405");
    TabClientes[10].QtdLocacoes=2;

    TLclientes = 11;

    strcpy(TabCarros[0].categ, "Hatch");
    TabCarros[0].codCar = 1001;
    strcpy(TabCarros[0].modelo, "Onix");
    TabCarros[0].precoDiaria = 120.50; 

   
    strcpy(TabCarros[1].categ, "Sedan");
    TabCarros[1].codCar = 2002;
    strcpy(TabCarros[1].modelo, "Corolla");
    TabCarros[1].precoDiaria = 250.00; 

  
    strcpy(TabCarros[2].categ, "SUV");
    TabCarros[2].codCar = 3003;
    strcpy(TabCarros[2].modelo, "Tracker");
    TabCarros[2].precoDiaria = 180.99; 

    
    strcpy(TabCarros[3].categ, "Picape");
    TabCarros[3].codCar = 4004;
    strcpy(TabCarros[3].modelo, "Strada");
    TabCarros[3].precoDiaria = 150.00; 

    strcpy(TabCarros[4].categ, "Hatch");
    TabCarros[4].codCar = 5005;
    strcpy(TabCarros[4].modelo, "HB20");
    TabCarros[4].precoDiaria = 110.75; 

    strcpy(TabCarros[5].categ, "Sedan");
    TabCarros[5].codCar = 6006;
    strcpy(TabCarros[5].modelo, "Versa");
    TabCarros[5].precoDiaria = 205.50; 

    strcpy(TabCarros[6].categ, "SUV");
    TabCarros[6].codCar = 7007;
    strcpy(TabCarros[6].modelo, "Compass");
    TabCarros[6].precoDiaria = 285.00; 

    strcpy(TabCarros[7].categ, "Van");
    TabCarros[7].codCar = 8008;
    strcpy(TabCarros[7].modelo, "Spin");
    TabCarros[7].precoDiaria = 175.25; 

    strcpy(TabCarros[8].categ, "Esportivo");
    TabCarros[8].codCar = 9009;
    strcpy(TabCarros[8].modelo, "Mustang");
    TabCarros[8].precoDiaria = 299.99; 

    
    strcpy(TabCarros[9].categ, "Hatch");
    TabCarros[9].codCar = 1010;
    strcpy(TabCarros[9].modelo, "Polo");
    TabCarros[9].precoDiaria = 135.00; 
    
   

    TLcarros = 10;
	
	gotoxy(40,25);textcolor(10);printf("Dados inseridos!");
	textcolor(15);
	Sleep(1000);
	return;
	
	

}	

void MolduraMenor(int CI, int LI, int CF, int LF, int CorT){
	int i;
	textcolor(CorT);
	gotoxy(CI,LI);
	printf("%c",218);
	gotoxy(CF,LI);
	printf("%c",191);
	gotoxy(CI,LF);
	printf("%c",192);
	gotoxy(CF,LF);
	printf("%c",217);
	for(i=CI+1; i<CF; i++)
	{
		gotoxy(i,LI);
		printf("%c",196);
		
		gotoxy(i,LF);
		printf("%c",196);
	}
	
	for(i=LI+1; i<LF; i++)
	{
		gotoxy(CI,i);
		printf("%c",179);
		
		
		gotoxy(CF,i);
		printf("%c",179);
	}
	textcolor(7);
}
void Moldura(int CI, int LI, int CF, int LF, int CorT, int CorF){
	int i;
	textcolor(CorT);
	textbackground(CorF);
	gotoxy(CI,LI);
	printf("%c",201);
	gotoxy(CF,LI);
	printf("%c",187);
	gotoxy(CI,LF);
	printf("%c",200);
	gotoxy(CF,LF);
	printf("%c",188);
	for(i=CI+1; i<CF; i++)
	{
		gotoxy(i,LI);
		printf("%c",205);
		
		gotoxy(i,LF);
		printf("%c",205);
	}
	
	for(i=LI+1; i<LF; i++)
	{
		gotoxy(CI,i);
		printf("%c",186);
		
		
		gotoxy(CF,i);
		printf("%c",186);
	}
	textcolor(7);
	textbackground(0);
}
int msgSair(){
	char op;
	textcolor(12);
	printf("Pressione ESC para sair...\n");
	do{
		fflush(stdin);
		op=getch();
	}while(op!=27);
	textcolor(15);
	clrscr();
	return 1;
}
//menus
void menuPrincipal(){
	textcolor(15);
	int TLclientes=0,TLcarros=0,TLloc=0;
	char op;
	do{
		
		system("cls");
		Moldura(32,8,68,10,2,0);
		textcolor(3);gotoxy(43,9);printf("MENU PRINCIPAL");
		textcolor(3);
		Moldura(1,1,100,30,15,9);
		MolduraMenor(32,11,68,23,8);
		gotoxy(39,12);textcolor(10);printf("[A]");textcolor(15);printf(" Clientes");
		gotoxy(39,14);textcolor(10);printf("[B]");textcolor(15);printf(" Carros");
		gotoxy(39,16);textcolor(10);printf("[C]");textcolor(15);printf(" Locacoes");
		gotoxy(39,18);textcolor(10);printf("[D]");textcolor(15);printf(" Inserir dados");
		gotoxy(39,20);textcolor(10);printf("[E]");textcolor(15);printf(" Relatorios/Consultas");
		gotoxy(39,22);textcolor(12);printf("[S]");textcolor(12);printf(" Sair");
		op=toupper(getch());
		fflush(stdin);
		switch(op){
			
			case 'A':
			gotoxy(39,12);textcolor(9);printf("[A]");textcolor(9);printf(" Clientes");
			Sleep(200);
			menuClientes(TabClientes,TLclientes);
			break;
			case 'B':gotoxy(39,14);textcolor(9);printf("[B]");textcolor(9);printf(" Carros");	Sleep(200);menuCarros(TabCarros,TLcarros,TLloc);break;
			case 'C':gotoxy(39,16);textcolor(9);printf("[C]");textcolor(9);printf(" Locacoes");	Sleep(200);menuLocacoes(TabLocacoes,TabCarros,TabClientes,TLcarros,TLclientes,TLloc);break;
			case 'D':gotoxy(39,18);textcolor(9);printf("[D]");textcolor(9);printf(" Inserir dados");	Sleep(200);inserirDados(TabClientes,TabCarros,TabLocacoes,TLclientes,TLcarros,TLloc);break;
			case 'E':gotoxy(39,20);textcolor(9);printf("[E]");textcolor(9);printf(" Relatorios/Consultas");	Sleep(200);menuRelatorios(TabLocacoes,TabCarros,TabClientes,TLcarros,TLclientes,TLloc);break;
			
		}
		
	}while(op!='S');
};
void menuClientes(TpClientes TabClientes[TF], int &TL){
	char op;
	do{
		
		system("cls");
		MolduraMenor(35,8,62,10,10);
		gotoxy(39,9);
		textcolor(14);
		printf(" CENTRAL DE CLIENTES ");
		Moldura(1,1,100,30,15,9);
		MolduraMenor(35,11,62,21,8);
		gotoxy(39,12);textcolor(10);printf("[A]");textcolor(15);printf(" Cadastrar Cliente");
		gotoxy(39,14);textcolor(10);printf("[B]");textcolor(15);printf(" Excluir Cliente");
		gotoxy(39,16);textcolor(10);printf("[C]");textcolor(15);printf(" Editar Cliente");
		gotoxy(39,18);textcolor(10);printf("[D]");textcolor(15);printf(" Listar Cliente");
		gotoxy(39,20);textcolor(12);printf("[S]");textcolor(12);printf(" Sair");
		op=toupper(getch());
		fflush(stdin);
		switch(op){
			
			case 'A':gotoxy(39,12);textcolor(9);printf("[A]");textcolor(9);printf(" Cadastrar Cliente");Sleep(150);CadastroCliente(TabClientes, TL);break;
			case 'B':gotoxy(39,14);textcolor(9);printf("[B]");textcolor(9);printf(" Excluir Cliente");Sleep(150);ExcluirCliente(TabClientes,TL);break;
			case 'C':gotoxy(39,16);textcolor(9);printf("[C]");textcolor(9);printf(" Editar Cliente");Sleep(150);EditarCliente(TabClientes,TL);break;
			case 'D':gotoxy(39,18);textcolor(9);printf("[D]");textcolor(9);printf(" Listar Cliente");Sleep(150);ListarClientes(TabClientes,TL);break;
			
		}
		
	}while(op!='S');
};
void menuCarros(TpCarros TabCarros[TF],int &TL,int TLloc){
	
	char op;
	do{
		
		system("cls");
		MolduraMenor(35,8,60,10,10);
		gotoxy(39,9);
		textcolor(14);
		printf(" CENTRAL DE CARROS ");
		Moldura(1,1,100,30,15,9);
		MolduraMenor(35,11,60,21,8);
		gotoxy(39,12);textcolor(10);printf("[A]");
		textcolor(15);printf(" Cadastrar Carro");
		gotoxy(39,14);textcolor(10);printf("[B]");
		textcolor(15);printf(" Excluir Carro");
		gotoxy(39,16);textcolor(10);printf("[C]");
		textcolor(15);printf(" Editar Carro");
		gotoxy(39,18);textcolor(10);printf("[D]");
		textcolor(15);printf(" Listar Carros");
		gotoxy(39,20);textcolor(4);printf("[S] Sair");
		fflush(stdin);
		op=toupper(getch());
		textcolor(15);
		switch(op){
			
			case 'A':CadastroCarro(TabCarros,TL);break;
			case 'B':ExcluirCarro(TabCarros,TL,TLloc);break;
			case 'C':EditarCarro(TabCarros,TL);break;
			case 'D':ListarCarro(TabCarros,TL);break;
			
		}
		
	}while(op!='S');
};
void menuLocacoes(TpLocacoes TabLocacoes[TF],TpCarros TabCarros[TF],TpClientes TabClientes[TF],int TLcarro, int TLcliente, int &TLloc){
	char op;
	do{
		
		system("cls");
		MolduraMenor(35,8,60,10,10);
		gotoxy(38,9);
		textcolor(14);
		printf(" CENTRAL DE LOCACOES ");
		Moldura(1,1,100,30,15,9);
		MolduraMenor(35,11,60,21,8);
		gotoxy(39,12);textcolor(10);printf("[A]");
		textcolor(15);printf(" Nova Locacao");
		gotoxy(39,14);textcolor(10);printf("[B]");
		textcolor(15);printf(" Excluir Locacao");
		gotoxy(39,16);textcolor(10);printf("[C]");
		textcolor(15);printf(" Editar Locacao");
		gotoxy(39,18);textcolor(10);printf("[D]");
		textcolor(15);printf(" Listar Locacoes");
		gotoxy(39,20);textcolor(4);printf("[S] Sair");
		fflush(stdin);
		op=toupper(getch());
		textcolor(15);
		switch(op){
			
			case 'A':CadastrarLocacao(TabLocacoes,TLcarro,TLcliente,TLloc);break;
			case 'B':ExcluirLocacao(TabLocacoes,TLloc);break;
			case 'C':EditarLocacao(TabLocacoes,TabCarros,TLloc,TLcliente,TLcarro);break;
			case 'D':ListarLocacao(TabLocacoes,TLloc);break;
			
		}
		
	}while(op!='S');
};
void menuRelatorios(TpLocacoes TabLocacoes[TF],TpCarros TabCarros[TF],TpClientes TabClientes[TF],int TLcarro, int TLcliente, int TLloc){
	char op;
	do{
		
		system("cls");
		MolduraMenor(23,8,80,10,10); 
		gotoxy(33,9); textcolor(14);
		printf("CENTRAL DE RELATORIOS / CONSULTAS");
		Moldura(1,1,100,30,15,9);
		MolduraMenor(23,11,80,24,8); 
	
		gotoxy(25,12);textcolor(10);printf("[A]");textcolor(15);printf(" Listar clientes que fizeram 3 ou mais locacoes");
		
		gotoxy(25,14);textcolor(10);printf("[B]");textcolor(15);printf(" Listar carros por categoria");
		
		gotoxy(25,16);textcolor(10);printf("[C]");textcolor(15);printf(" Locacoes acima de um valor limite");
		
		gotoxy(25,18);textcolor(10);printf("[D]");textcolor(15);printf(" Relatorio completo (Locacoes por cliente)");
		
		gotoxy(25,20);textcolor(4);printf("[S] Sair");
		
		fflush(stdin);
		op=toupper(getch());
		textcolor(15);
		switch(op){
			
			case 'A':Relatorio1_Listar3Maiores(TLcliente,TLloc);break;
			case 'B':Relatorio2_CarrosPorCategoria(TabCarros,TLcarro);break;
			case 'C':Relatorio3_LocacoesPorValor(TabLocacoes,TLloc);break;
			case 'D':Relatorio4_RelatorioCompleto(TabLocacoes,TabCarros,TabClientes,TLcarro,TLcliente,TLloc);break;
			
		}
		
	}while(op!='S');
}
void Relatorio1_Listar3Maiores(int TLcliente,int TLloc){
	
	int i;
	system("cls");
	textcolor(14);printf("=============== Clientes que realizaram 3 ou mais locacoes ===============\n");
	printf("\n---------------------------------------------------------------------------\n");
	textcolor(15);
	for(i=0;i<TLcliente;i++){
		if(TabClientes[i].QtdLocacoes>=3){
			printf("\nNome: %s | Cpf: %s | telefone: %s",TabClientes[i].nome,TabClientes[i].cpf,TabClientes[i].telefone);
			printf("\nQuantidade de locacoes registradas: %d\n",TabClientes[i].QtdLocacoes);
			printf("\n-----------------------------------------------------------------------------\n");
		}	
	}
	
	if(msgSair()){
		
		clrscr();
		return;
		
	}
}
void Relatorio2_CarrosPorCategoria(TpCarros TabCarros[TF], int TLcarro){
    
    char auxCateg[15];
    int i, count = 0;
    system("cls");
    
    textcolor(14);printf("=============== Listar Carros por Categoria ===============\n");
    printf("\n---------------------------------------------------------------------------\n");
    
    textcolor(15);
    printf("Digite a categoria (ex: Hatch, SUV, Sedan): ");
    fflush(stdin);
    gets(auxCateg);
    
    system("cls");
    textcolor(14);printf("=============== Carros da Categoria: %s ===============",auxCateg);
    printf("\n_______________________________________________________________\n");
    textcolor(3);printf("\n    Codigo |               Modelo  |   Categ. | Preco Diaria\n");
    printf("---------------------------------------------------------------\n");
    textcolor(15);
    
    for(i=0; i<TLcarro; i++){
        if(strcmp(TabCarros[i].categ, auxCateg) == 0){ 
            printf("\n%10d | %21s | %9s | R$:%.2f\n", TabCarros[i].codCar,TabCarros[i].modelo,TabCarros[i].categ,TabCarros[i].precoDiaria);
            printf("______________________________________________________________|\n");
            count++;
        }
    }
    
    if(count == 0){
        textcolor(14);printf("\nNenhum carro encontrado na categoria\n");
    }
    
    if(msgSair()){
        clrscr();
        return;
    }
}
void Relatorio3_LocacoesPorValor(TpLocacoes TabLocacoes[TF], int TLloc){
    
    int i, count = 0;
    float limite;
    system("cls");
    
    textcolor(14);printf("=============== Locacoes por Valor Minimo ===============\n");
    printf("\n---------------------------------------------------------------------------\n");
    
    textcolor(15);
    printf("Digite o valor minimo (limite) da locacao: R$ ");
    scanf("%f", &limite);
    
    system("cls");
    textcolor(14);printf("=============== Locacoes com Valor Acima de R$ %.2f ===============", limite);
    printf("\n_______________________________________________________________\n");
    textcolor(3);printf("\n        CPF | Cod. Carro | Dias | Valor Total\n");
    printf("---------------------------------------------------------------\n");
    textcolor(15);
    
    for(i=0; i<TLloc; i++){
        if(TabLocacoes[i].ValorLocacao > limite){
            printf("\n%12s | %10d | %4d | R$:%.2f\n", TabLocacoes[i].cpf, TabLocacoes[i].codCar, TabLocacoes[i].QtdeDias, TabLocacoes[i].ValorLocacao);
            printf("_______________________________________________________________\n");
            count++;
        }
    }
    
    if(count == 0){
        textcolor(12);printf("\nNenhuma locacao encontrada acima do limite de R$ %.2f.\n", limite);
    }
    
    if(msgSair()){
        clrscr();
        return;
    }
}
int BuscarPosCarroCod(TpCarros TabCarros[TF], int TL, int cod){ 
	int pos=0;
	TabCarros[TL].codCar=cod; 
	while(TabCarros[pos].codCar!=cod){
		pos++;
	}
	if(pos==TL){
		return -1;
	}
	else{
		return pos;
	}
}
void Relatorio4_RelatorioCompleto(TpLocacoes TabLocacoes[TF], TpCarros TabCarros[TF], TpClientes TabClientes[TF], int TLcarro, int TLcliente, int TLloc){
    
    int i, j, posCarro;
    int clientesComLocacao = 0;
    system("cls");
    
    textcolor(14);printf("=============== Relatorio Completo de Locacoes por Cliente ===============\n");
    printf("\n---------------------------------------------------------------------------\n");
    textcolor(15);
    
    for(i=0; i<TLcliente; i++){
        int locacoesCliente = 0;
        
  
        for(j=0; j<TLloc; j++){
            if(strcmp(TabClientes[i].cpf, TabLocacoes[j].cpf) == 0){
                if(locacoesCliente == 0){
                    textcolor(10);
                    printf("\nCLIENTE: %s | CPF: %s\n", TabClientes[i].nome, TabClientes[i].cpf);
                    printf("========================================================================\n");
                    textcolor(3);
                    printf("  Cod. Carro | Modelo             | Dias | Preco Diaria | Valor Locacao\n");
                    printf("------------------------------------------------------------------------\n");
                    textcolor(15);
                }
                
              
                posCarro = BuscarPosCarroCod(TabCarros, TLcarro, TabLocacoes[j].codCar);
                
                if(posCarro != -1){
                    printf("%12d | %18s | %4d | R$:%.2f | R$:%.2f\n",
                           TabLocacoes[j].codCar,
                           TabCarros[posCarro].modelo,
                           TabLocacoes[j].QtdeDias,
                           TabCarros[posCarro].precoDiaria,
                           TabLocacoes[j].ValorLocacao);
                } else {
                    printf("%12d | Carro N/E            | %4d | R$:N/A   | R$:%.2f\n",
                           TabLocacoes[j].codCar,
                           TabLocacoes[j].QtdeDias,
                           TabLocacoes[j].ValorLocacao);
                }
                
                locacoesCliente++;
                clientesComLocacao = 1; 
            }
        }
        
        if(locacoesCliente > 0){
            printf("------------------------------------------------------------------------\n");
        }
    }
    
    if(clientesComLocacao == 0){
        textcolor(12);printf("\nNenhuma locacao cadastrada no sistema.\n");
    }
    
    if(msgSair()){
        clrscr();
        return;
    }
}
void InsertionSortCliente(TpClientes TabClientes[TF], int &TL){
	int j,i, auxQtdLoc;
	char auxCpf[16], auxTel[14];
	char auxNome[30];
	
	for(i=1;i<TL;i++){
		strcpy(auxNome,TabClientes[i].nome);
		strcpy(auxCpf,TabClientes[i].cpf);
		strcpy(auxTel,TabClientes[i].telefone);
		auxQtdLoc=TabClientes[i].QtdLocacoes;
		
		j=i-1;
		
		while(j>=0 && strcmp(TabClientes[j].cpf,auxCpf)>0){
			TabClientes[j+1] = TabClientes[j];
			j=j-1;
		}
		strcpy(TabClientes[j+1].nome, auxNome);
		strcpy(TabClientes[j+1].cpf, auxCpf);
		strcpy(TabClientes[j+1].telefone, auxTel);
		TabClientes[j+1].QtdLocacoes = auxQtdLoc;
	}
}
int verificaCpf(TpClientes TabClientes[TF],int TL,char cpf[16]){
	int i=0;
	if(TL==0) 
		return 1;
		
	strcpy(TabClientes[TL].cpf,cpf);//sent
	while(!strcmp(TabClientes[i].cpf,cpf)==0){
		i++;
	}
	
	if(TL==i)
		return 1;  // 1 - esta disponivel
	else{
	
		textcolor(12);
		printf("CPF em uso");
		textcolor(15);
		return 0;
		 // 0 - esta em uso
	}
}                                         
void CadastroCliente(TpClientes TabClientes[TF],int &TL){

	char auxCpf[16];
	char auxNome[30];
	char auxTel[14];
	char op;
	
	do{
		system("cls");
		MolduraMenor(30,4,78,6,14);
		gotoxy(32,8);textcolor(9);printf("Nome:");textcolor(15);
		gotoxy(32,10);textcolor(9);printf("CPF:");textcolor(15);
		gotoxy(32,12);textcolor(9);printf("Telefone:");textcolor(15);
		
		MolduraMenor(30,6,78,16,14);
		gotoxy(45,5);textcolor(2);printf("Cadastro de cliente");
		textcolor(15);
		
		gotoxy(32,8);textcolor(9);printf("Nome:");textcolor(15);
		fflush(stdin);
		gets(auxNome);
		
		
		gotoxy(32,10);textcolor(9);printf("CPF:");textcolor(15);
		do{
			fflush(stdin);
			gets(auxCpf);
		}while(!verificaCpf(TabClientes,TL,auxCpf));
		
		gotoxy(32,12);textcolor(9);printf("Telefone:");textcolor(15);
		fflush(stdin);
		gets(auxTel);
		
		gotoxy(40,18);printf("Confirmar o cadastro?");
		gotoxy(42,20);textcolor(10);printf("[S] sim");
		gotoxy(52,20);textcolor(12);printf("[N] nao");
		do{
				fflush(stdin);
				op=toupper(getch());
			}while(op!='N' && op!='S');
		if(op=='S'){
			strcpy(TabClientes[TL].nome,auxNome);
			strcpy(TabClientes[TL].cpf,auxCpf);
			strcpy(TabClientes[TL].telefone,auxTel);
			TabClientes[TL].QtdLocacoes=0;
			
			TL++;
			InsertionSortCliente(TabClientes,TL);
			Sleep(200);
			gotoxy(42,2);textcolor(10);printf("Cadastrado com sucesso!");
			textcolor(15);
			Sleep(1000);
			gotoxy(40,2);textcolor(10);printf("                         ");
			gotoxy(40,18);printf("                                      ");
			gotoxy(40,18);textcolor(9);printf("Deseja cadastrar outro cliente?");
			gotoxy(42,20);textcolor(10);printf("[S] sim");
			gotoxy(52,20);textcolor(12);printf("[N] nao");
			do{
				fflush(stdin);
				op=toupper(getch());
			}while(op!='N' && op!='S');
		}
		else{
			system("cls");
			gotoxy(35,10);textcolor(15);printf("Deseja cadastrar outro cliente?");
			gotoxy(33,12);textcolor(10);printf("[S] sim");
			gotoxy(42,12);textcolor(12);printf("[N] nao");
			textcolor(15);
			do{
				fflush(stdin);
				op=toupper(getch());
			}while(op!='N' && op!='S');
		}
	}while(op!='N');
	
}
int BuscaClienteCpf(TpClientes TabClientes[TF],int TL){
	
	int pos=0;
	char auxCpf[16];
	gotoxy(34,8);textcolor(14);printf("Digite o cpf do cliente a ser excluido");
	gotoxy(34,10);textcolor(9);printf("CPF:");textcolor(15);
	fflush(stdin);
	gets(auxCpf);
	while(strcmp(auxCpf,TabClientes[pos].cpf)==1 && !strcmp(TabClientes[pos].cpf,auxCpf)==0){
		pos++;
	}
	if(pos<TL && strcmp(TabClientes[pos].cpf,auxCpf)==0)
		return pos; 
	else
		return -1;
}
void ExcluirCliente(TpClientes TabClientes[TF],int &TL){
	system("cls");
	fflush(stdin);
	char op,auxCpf[16];
	int pos;
	
		
	do{
		system("cls");
		MolduraMenor(30,4,78,6,14);
		gotoxy(45,5);textcolor(2);printf("Excluir Cliente");
		textcolor(15);
		MolduraMenor(30,6,78,13,14);
		pos=BuscaClienteCpf(TabClientes,TL);
		
	
		
		if(pos>=0){
			gotoxy(34,8);printf("                                        ");
			gotoxy(34,8);textcolor(14);printf("Deseja excluir o cliente abaixo?");textcolor(15);
		
			gotoxy(34,10);printf("Nome: %s | CPF: %s",TabClientes[pos].nome,TabClientes[pos].cpf);
		
			gotoxy(43,12);textcolor(10);printf("[S] Sim");
			gotoxy(53,12);textcolor(12);printf("[N] Nao");
			textcolor(15);
			do{
				fflush(stdin);
				op=toupper(getch());
			}while(op!='N' && op!='S');
			if(op=='S'){
			
			for(int i=pos;i<TL-1;i++){
				
				strcpy(TabClientes[i].nome,TabClientes[i+1].nome);									
				strcpy(TabClientes[i].cpf,TabClientes[i+1].cpf);
				strcpy(TabClientes[i].telefone,TabClientes[i+1].telefone);
					
				}
				
				TL--;
				gotoxy(40,2);textcolor(10);printf("Excluido com sucesso!");
				Sleep(700);
				gotoxy(40,2);printf("                        ");
			}
			
		}else if(pos==-1){
		
			gotoxy(40,2);textcolor(12);printf("Usuario nao encontrado no sistema!");
			Sleep(900);
			gotoxy(40,2);printf("                                     ");
			textcolor(15);
		}
		textcolor(14);
		gotoxy(40,18);printf("Digitar outro cpf?");
		gotoxy(40,19);textcolor(10);printf("[S] Sim");
		gotoxy(50,19);textcolor(12);printf("[N] Nao");
		textcolor(15);
		do{
			fflush(stdin);
			op=toupper(getch());
		}while(op!='N' && op!='S');
			
	}while(op!='N');
	
	}
void AlterarCadastroChaveCpf(TpClientes TabClientes[TF],int &TL,char auxCpf[16]){
	int pos=0;
	while(pos<=TL && !strcmp(TabClientes[pos].cpf,auxCpf)==0){
		pos++;
	}
	if(pos>TL){
		gotoxy(40,2);textcolor(12);printf("Usuario nao encontrado!");textcolor(15);
		getch();
		msgSair();
		return;
	}
	system("cls");
	MolduraMenor(25,4,85,10,15);
	gotoxy(27,6);textcolor(14);printf("Usuario a ser editado:");textcolor(8);
	gotoxy(27,8);printf("Nome: %s | CPF: %s | Telefone: %s",TabClientes[pos].nome,TabClientes[pos].cpf,TabClientes[pos].telefone);
	MolduraMenor(25,11,85,20,15);
	
	gotoxy(27,14);textcolor(14);printf("Nome: ");textcolor(15);
	gotoxy(27,16);textcolor(14);printf("CPF: ");textcolor(15);
	gotoxy(27,18);textcolor(14);printf("Telefone: ");textcolor(15);
	
	gotoxy(27,12);textcolor(10);printf("Alterar cadastro");
	gotoxy(27,14);textcolor(14);printf("Nome: ");textcolor(15);
	fflush(stdin);
	gets(TabClientes[pos].nome);
	
	gotoxy(27,16);textcolor(14);printf("CPF: ");textcolor(15);
	fflush(stdin);
	gets(TabClientes[pos].cpf);
	
	gotoxy(27,18);textcolor(14);printf("Telefone: ");textcolor(15);
	fflush(stdin);
	gets(TabClientes[pos].telefone);
	
	InsertionSortCliente(TabClientes,TL);
	Sleep(200);
	gotoxy(40,2);printf("                                ");
	gotoxy(40,2);textcolor(10);printf("Cadastro alterado com sucesso!");
	textcolor(15);
	Sleep(900);
}
void EditarCliente(TpClientes TabClientes[TF],int &TL){
	system("cls");
	MolduraMenor(30,4,78,6,14);
	gotoxy(45,5);textcolor(2);printf("Editar Cliente");
	textcolor(15);
	MolduraMenor(30,6,78,13,14);
	char auxCpf[16];
	gotoxy(32,8);textcolor(14);printf("Digite o cpf do cliente que voce quer editar");
	gotoxy(32,10);textcolor(9);printf("Cpf:");
	textcolor(15);
	fflush(stdin);
	
	gets(auxCpf);
	AlterarCadastroChaveCpf(TabClientes,TL,auxCpf);
}
void ListarClientes(TpClientes TabClientes[TF],int TL){
	int i;
	system("cls");
	printf("============================= Cadastros de clientes =============================\n\n");textcolor(15);
	for(i=0;i<TL;i++){
			textcolor(15);printf("\nNome: %s | CPF: %s | Telefone: %s\n",TabClientes[i].nome,TabClientes[i].cpf,TabClientes[i].telefone);
			textcolor(8);printf("-----------------------------------------------------------------\n");
			
			
	}
	
	getch();
}
void SelectionSortCarroPorCod(TpCarros TabCarros[TF], int TL){
	
	int i,j,posMenor;
	int auxCod;
	char auxModelo[15], auxCateg[15];
	float auxDiaria;
	for(i= 0;i<TL-1;i++){
		posMenor =i;
		for(j=i+1;j<TL;j++){
			if(TabCarros[j].codCar<TabCarros[posMenor].codCar){
				posMenor = j;
			}
		}	
		if(posMenor != i){
			auxCod=TabCarros[i].codCar;
			strcpy(auxModelo,TabCarros[i].modelo);
			strcpy(auxCateg,TabCarros[i].categ);
			auxDiaria=TabCarros[i].precoDiaria;
			
			TabCarros[i].codCar=TabCarros[posMenor].codCar;
			strcpy(TabCarros[i].modelo,TabCarros[posMenor].modelo);
			strcpy(TabCarros[i].categ,TabCarros[posMenor].categ);
			TabCarros[i].precoDiaria=TabCarros[posMenor].precoDiaria;
			
			TabCarros[posMenor].codCar=auxCod;
			strcpy(TabCarros[posMenor].modelo,auxModelo);
			strcpy(TabCarros[posMenor].categ,auxCateg);
			TabCarros[posMenor].precoDiaria=auxDiaria;
		}
	}
}
void BubbleSortCarroPorModelo(TpCarros TabCarros[TF], int TL){
	int i, j;
	TpCarros aux; 
	for(i=0;i<TL-1;i++){
		for(j=0;j<TL-1-i;j++){
			if(strcmp(TabCarros[j].modelo, TabCarros[j+1].modelo) > 0){
				aux=TabCarros[j];
				TabCarros[j]=TabCarros[j+1];
				TabCarros[j+1]=aux;
			}
		}
	}
}
void CadastroCarro(TpCarros TabCarros[TF],int &TL){
	system("cls");
	char auxModelo[15];
	char op;
	do{	
		textcolor(2);printf("===================Cadastro de carro==================");
		textcolor(15);printf("\nDigite o codigo do carro: ");
		scanf("%d",&TabCarros[TL].codCar);
		printf("VC ESTA NA PARTE DE MOSTRAR O TL, É A POSICAO ONDE VAI SER SALVO O CARRO\nTL= %d",TL);
		getch();
		printf("\nDigite o modelo do carro: ");
		fflush(stdin);
		gets(TabCarros[TL].modelo);
		
		printf("\nDigite a categoria do carro: ");
		fflush(stdin);
		gets(TabCarros[TL].categ);
		
		printf("Digite o valor de aluguel diario: ");
		scanf("%f",&TabCarros[TL].precoDiaria);
		
		TL++;
		
		SelectionSortCarroPorCod(TabCarros,TL);
		
		printf("\nCadastrado com sucesso!");
		printf("\nDeseja cadastrar outro carro?\n[S] sim\n[N] nao");
		op=toupper(getch());
		fflush(stdin);
		clrscr();
		
	}while(op!='N');
	
}
void ListarCarro(TpCarros TabCarros[TF],int TL){
	system("cls");
	int i;
	BubbleSortCarroPorModelo(TabCarros, TL);//leandrao aq to ordenando por modelo apenas para listar
	
	 
	textcolor(10);printf("|==================== LISTAGEM DOS CARROS ====================|");
	            printf("\n_______________________________________________________________\n");
	
	textcolor(3);printf("\n    Codigo |              Modelo   |    Categ. | Preco Diaria\n");
	             printf("---------------------------------------------------------------\n");
	textcolor(15);
	for(i=0;i<TL;i++){
		printf("\n%10d | %21s | %9s | R$:%.2f\n",TabCarros[i].codCar,TabCarros[i].modelo,TabCarros[i].categ,TabCarros[i].precoDiaria);
		printf("______________________________________________________________|\n");
	}
	
	if(msgSair())

		return;
}
void AlterarCarroChaveCod(TpCarros TabCarros[TF],int &TL,int auxCod){
	int pos=0;
	char auxModel[15],auxCateg[15];
	float auxPreco;
	TabCarros[TL].codCar=auxCod; //sentinela
	while(TabCarros[pos].codCar!=auxCod){
		pos++;
	}
	if(pos==TL){
		textcolor(12);
		printf("\nCarro nao encontrado!");
		Sleep(1500);
		textcolor(15);
		printf("\nRetornando ao menu principal...");
		Sleep(1000);
		return;
	}
	else{
		system("cls");
		textcolor(10);
		printf("Cadastro anterior\n");
		textcolor(3);printf("\n    Codigo |              Modelo   |    Categ. | Preco Diaria\n");
	    printf("---------------------------------------------------------------\n");
		textcolor(15);printf("%10d | %21s | %9s | R$:%.2f\n",TabCarros[pos].codCar,TabCarros[pos].modelo,TabCarros[pos].categ,TabCarros[pos].precoDiaria);
		printf("\n------------------------------------------------------------------------------------\n");
		textcolor(10);printf("\nNovo cadastro:\n");
		textcolor(3);printf("\nModelo: ");textcolor(15);fflush(stdin);gets(auxModel);
		textcolor(3);printf("\nCategoria: ");textcolor(15);fflush(stdin);gets(auxCateg);
		textcolor(3);printf("\nPreco diaria: ");textcolor(15);scanf("%f",&auxPreco);
		system("cls");
		textcolor(3);printf("\n    Codigo |              Modelo   |    Categ. | Preco Diaria\n");
		textcolor(15);printf("---------------------------------------------------------------\n");
		printf("\n%10d | %21s | %9s | R$:%.2f\n",TabCarros[pos].codCar,auxModel,auxCateg,auxPreco);
		textcolor(15);printf("---------------------------------------------------------------\n");
		textcolor(10);printf("\nDeseja confirmar as alterações? [S/N]\n");
		textcolor(15);
		char op;
		do{
		fflush(stdin);
		op=toupper(getch());
		}while(!op=='S' || !op=='N');
		switch(op){
		case 'N':textcolor(12);
				printf("\nAlteracao cancelada!");
				Sleep(1500);
				textcolor(15);printf("\nRetornando...");
				Sleep(1500);
				return;break;
		case 'S':strcpy(TabCarros[pos].modelo,auxModel);
				strcpy(TabCarros[pos].categ,auxCateg);
				TabCarros[pos].precoDiaria=auxPreco;
				Sleep(500);
				textcolor(10);printf("\nAlteracao concluida!");textcolor(15);
				Sleep(1000);
				msgSair();
				return;
				break;
		}
		
	}
};
void EditarCarro(TpCarros TabCarros[TF],int &TL){
	system("cls");
	printf("====================== Editar Carro ===========================\n");
	int auxCod;
	printf("\nDigite o codigo do carro que voce quer editar:");
	scanf("%d",&auxCod);
	AlterarCarroChaveCod(TabCarros,TL,auxCod);
	msgSair();
	
}
int BuscaBinariaCarro(TpCarros TabCarros[TF],int TL,int auxCod){
	SelectionSortCarroPorCod(TabCarros,TL);
	int low,mid,high;
	high=TL-1;
	low=0;
	do{
		
		mid = (high+low)/2;
		if(TabCarros[mid].codCar==auxCod)
			return mid;
		else if(TabCarros[mid].codCar>auxCod)
			high=mid-1;
		else if(TabCarros[mid].codCar<auxCod)
			low=mid+1;
		
	}while(low<=high && TabCarros[mid].codCar!=auxCod);
		return -1;

}
int VerificarNaTabLocacao(int pos,int TL){
	int flag=0;
	for(int i=0;i<TL;i++){
		if(TabLocacoes[i].codCar==TabCarros[pos].codCar)
			return 0; //locacao coisada
	}
	return 1; //pode apagar
}
void ExcluirCarro(TpCarros TabCarros[TF],int &TL,int TLloc){
	system("cls");
	char op;
	int pos,auxCod,estado;
	printf("\n=================Excluir carro===================\n");
	SelectionSortCarroPorCod(TabCarros,TL);
	do{
		printf("\nDigite o codigo do carro a ser excluido: ");
		scanf("%d",&auxCod);
		pos=BuscaBinariaCarro(TabCarros,TL,auxCod);
		estado=VerificarNaTabLocacao(pos,TLloc);
		if(!estado){
			system("cls");
			gotoxy(30,10);textcolor(12);printf("Locacao cadastrada com este veiculo, impossivel excluir");
			Sleep(1500);
			textcolor(15);
			gotoxy(30,12);printf("Retornando...");
			Sleep(1000);
			return;
		}
		if(pos>=0){
			
			for(int i=pos;i<TL-1;i++){   
				
				strcpy(TabCarros[i].categ,TabCarros[i+1].categ);									
				strcpy(TabCarros[i].modelo,TabCarros[i+1].modelo);
				TabCarros[i].codCar=TabCarros[i+1].codCar;
				TabCarros[i].precoDiaria=TabCarros[i+1].precoDiaria;
				
			}
			
			TL--;
			printf("\nExcluido com sucesso!");
			printf("TL: %d",TL);
			getch();
			
		}else if(pos==-1)
		
			printf("\nCarro nao encontrado no sistema!");
			
		printf("\n[A] Digitar outro codigo\n[B] Sair\n");
		fflush(stdin);
		op=toupper(getch());
		if(op=='B')
		
			return;
			
	}while(op=='A');
	
}
float CalcularPreco(int cod,int TL,int dias){
	int pos;
	float precoFinal;
	pos=BuscaBinariaCarro(TabCarros,TL,cod);
	precoFinal=TabCarros[pos].precoDiaria*dias;
	return precoFinal;
}
int verificaCpfLocacao(TpClientes TabClientes[TF],char auxCpf[16],int TL){
	int pos=0;
	strcpy(TabClientes[TL].cpf,auxCpf);  //sen
	while(!strcmp(TabClientes[pos].cpf,auxCpf)==0){
		pos++;
	}
	if(pos==TL)
		return -1;
	else{
		return pos;
	}

}
int verificarCarroLoc(int pos,int TL){
	int aux=0;
	printf("cod carrro na tabela carros: %d",TabCarros[pos].codCar);
	getch();
	while(TabLocacoes[aux].codCar!=TabCarros[pos].codCar && aux<TL){
		
		aux++;
		if(TabLocacoes[aux].codCar==TabCarros[pos].codCar)
			return 1; //carro ja alugado
	}
	return 0; //disponivel
	
}
void ListarLocacao(TpLocacoes TabLocacoes[TF],int TL){
	int i;
	system("cls");
	printf("======================= Locacoes cadastradas =======================\n");
	for(i=0;i<TL;i++){
		
		printf("\nCpf: %s",TabLocacoes[i].cpf);
		printf("\nCodigo do carro: %d",TabLocacoes[i].codCar);
		printf("\nQtd de dias: %d",TabLocacoes[i].QtdeDias);
		printf("\nValor: %f\n",TabLocacoes[i].ValorLocacao);
		printf("\n----------------------------------------------------------\n");
		
	}
	
	if(msgSair()){
		
		clrscr();
		return;
		
	}
}
void CadastrarLocacao(TpLocacoes TabLocacoes[TF],int TLcarro,int TLcliente,int &TLloc){
	system("cls");
	char auxCpf[15];
	int auxCod,auxQtdDia,posCliente,posCarro,estado;
	float precoLoc;
	
	textcolor(2);printf("===================Nova Locacao==================");
	textcolor(15);printf("\nDigite o cpf do cliente: ");
	fflush(stdin);
	gets(auxCpf);
	posCliente=verificaCpfLocacao(TabClientes,auxCpf,TLcliente);  
	if(posCliente==-1){
		
		printf("\nCpf invalido");
		Sleep(700);
		msgSair();
		return;
	}
	printf("\nDigite o codigo do carro: ");
	scanf("%d",&auxCod);
	posCarro=BuscaBinariaCarro(TabCarros,TLcarro,auxCod);
	if(posCarro==-1){
		textcolor(14);printf("Carro não encontrado no sistema!");
		Sleep(1000);
		textcolor(15);
		return;
	}
	if(verificarCarroLoc(posCarro,TLloc)){
		textcolor(14);printf("Carro ja alugado!");
		Sleep(1000);
		textcolor(15);
		return;
	}
	
	
	printf("\nQuantidade de dias: ");
	scanf("%d",&auxQtdDia);
	
	precoLoc=CalcularPreco(auxCod,TLcarro,auxQtdDia);
	system("cls");
	textcolor(10);printf("================CONFIRMAR LOCACAO================\n");
	textcolor(14);printf("\nDeseja confirmar a seguinte locacao?\n");
	textcolor(15);printf("NOME: %s\nCPF: %s\n%s - %d dias\nValor total: %2.f\n",TabClientes[posCliente].nome,auxCpf,TabCarros[posCarro].modelo,auxQtdDia,precoLoc);
	textcolor(14);printf("\n[S/N]");
	textcolor(15);
	char op;
	do{
		fflush(stdin);
		op=toupper(getch());
	}while(!op=='S' ||!op=='N');
	if(op=='S'){
		TabClientes[posCliente].QtdLocacoes++; 
		
		strcpy(TabLocacoes[TLloc].cpf,auxCpf);
		TabLocacoes[TLloc].codCar=auxCod;
		TabLocacoes[TLloc].QtdeDias=auxQtdDia;
		TabLocacoes[TLloc].ValorLocacao=precoLoc;
		TLloc++;
		textcolor(10);
		printf("\nLocacao cadastrada no sistema!");
		textcolor(15);
		Sleep(1000);
		msgSair();
		return;
	}else{
		textcolor(12);printf("\nOperacao Cancelada");
		textcolor(15);
		Sleep(1000);
		msgSair();
		return;
	}   
	
	
}
void ExcluirLocacao(TpLocacoes TabLocacoes[TF],int &TL){
	system("cls");
	fflush(stdin);
	char op,auxCpf[16];
	int pos=0;
	textcolor(10);printf("\n=================Excluir Locacao===================\n");
	textcolor(15);
	do{
		printf("\nDigite o cpf para excluir:");
		fflush(stdin);
		gets(auxCpf);
		//busca
		while(!strcmp(TabLocacoes[pos].cpf,auxCpf)==0 && pos<TL){
			pos++;
		}
		printf("pos: %d",pos);
		getch();
		
		if(pos<TL){
			
			for(int i=pos;i<TL-1;i++){
				
				strcpy(TabLocacoes[i].cpf,TabLocacoes[i+1].cpf);									
				TabLocacoes[i].codCar=TabLocacoes[i+1].codCar;
				TabLocacoes[i].QtdeDias=TabLocacoes[i+1].QtdeDias;
				TabLocacoes[i].ValorLocacao=TabLocacoes[i+1].ValorLocacao;
				
			}
			
			TL--;
			printf("\nExcluido com sucesso!");
			getch();
			
		}else if(pos>TL)
		
			textcolor(14);printf("\nLocacao nao encontrada no sistema!");
			textcolor(15);
			printf("\n[A] Digitar outro cpf\n[B] Sair\n");
			fflush(stdin);
			op=toupper(getch());
			if(op=='B')
				return;
			
	}while(op=='A');
	
}
void AlterarLocacaoChaveCpf(TpLocacoes TabLocacoes[TF],TpCarros TabCarros[TF],int &TL,int TLcliente,int TLcarro,char auxCpf[16]){
	int pos=0,posCarro,auxQtdDia,posCliente,auxCod;
	float precoLoc;
	while(pos<=TL && !strcmp(TabLocacoes[pos].cpf,auxCpf)==0){
		pos++;
	}
	if(pos>TL){
		textcolor(14);printf("Locacao nao encontrada!");textcolor(15);
		getch();
		msgSair();
		return;
	}
	printf("\nLocacao a ser editada:\n");
	printf("\nCPF: %s | Cod Carro: %d | %d dias | %f \n",TabLocacoes[pos].cpf,TabLocacoes[pos].codCar,TabLocacoes[pos].QtdeDias);
		textcolor(15);printf("\nDigite o cpf do cliente: ");
	fflush(stdin);
	gets(auxCpf);
	posCliente=verificaCpfLocacao(TabClientes,auxCpf,TLcliente);  
	if(posCliente==-1){
	
		printf("\nCpf invalido");
		Sleep(700);
		msgSair();
		return;
	}
	
	printf("\nDigite o codigo do carro: ");
	scanf("%d",&auxCod);
	posCarro=BuscaBinariaCarro(TabCarros,TL,auxCod);
	if(posCarro==-1){
		printf("Carro não encontrado no sistema!");
		Sleep(1000);
		return;
	}
	if(verificarCarroLoc(posCarro,TL)){
		printf("Carro ja alugado!");
		Sleep(1000);
		return;
	}
	
	
	printf("\nQuantidade de dias: ");
	scanf("%d",&auxQtdDia);
	
	precoLoc=CalcularPreco(auxCod,TLcarro,auxQtdDia);
	system("cls");
	textcolor(10);printf("================CONFIRMAR LOCACAO================\n");
	textcolor(14);printf("\nDeseja confirmar a seguinte locacao?\n");
	textcolor(15);printf("NOME: %s\nCPF: %s\n%s - %d dias\nValor total: %2.f\n",TabClientes[posCliente].nome,auxCpf,TabCarros[posCarro].modelo,auxQtdDia,precoLoc);
	textcolor(14);printf("\n[S/N]");
	textcolor(15);
	char op;
	do{
		fflush(stdin);
		op=toupper(getch());
	}while(!op=='S' ||!op=='N');
	if(op=='S'){
		strcpy(TabLocacoes[pos].cpf,auxCpf);
		TabLocacoes[pos].codCar=auxCod;
		TabLocacoes[pos].QtdeDias=auxQtdDia;
		TabLocacoes[pos].ValorLocacao=precoLoc;
		printf("\nLocacao cadastrada no sistema!");
		Sleep(1000);
		msgSair();
		return;
	}else{
		textcolor(12);printf("\nOperacao Cancelada");
		Sleep(1000);
		msgSair();
		return;
	}   
}
void EditarLocacao(TpLocacoes TabLocacoes[TF],TpCarros TabCarros[TF],int &TL,int TLcliente,int TLcarro){
	system("cls");
	printf("====================== Editar Locacao ===========================\n");
	char auxCpf[16];
	printf("\nDigite o cpf:");
	fflush(stdin);
	gets(auxCpf);
	AlterarLocacaoChaveCpf(TabLocacoes,TabCarros,TL,TLcliente,TLcarro,auxCpf);
}
																		 
																 
	
