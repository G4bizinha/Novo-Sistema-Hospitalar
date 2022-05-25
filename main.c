#include <stdio.h>
#include <stdlib.h>
#include <locale.h> 
#include <string.h>
#include <unistd.h>

int menucontrole = 1;
int tam;
int ini,fim;
int tamfilaAmarela = 0;
int tamfilaVerde = 0;
int achou;
int i=0;
int prioridade;
int iniAmarelo, fimAmarelo;
int iniVerde, fimVerde;

struct Paciente{
  char nome[50];//salva o nome do paciente na fila
	char sobrenome[50];//salvar o sobrenome 
  char prioridade;//salva a prioridade do paciente   V ou A
  int posicaoGeral; // salva a posição do paciente da fila por ordem de chegada.
	int posicaoPrioridadeVerde;// salva a posição do paciente pela prioridade Verde
	int posicaoPrioridadeAmarela;// salva a posição do paciente pela prioridade Amarela
	struct Paciente *ant; // pegar o paciente anterior
	struct Paciente *prox; // pegar o proximo paciente
} ;

typedef struct Paciente paciente;







// sistema de cores
#define VERDE "\x1b[32m"
#define AMARELO "\x1b[93m"
#define VERMELHO "\x1b[31m"
#define AZUL "\x1b[34m"
#define RESET "\x1b[0m"

void Error(){ //mensagem de erro se a opção estiver errada
	printf(VERMELHO"---------- Erro ❗ ---------- \n");
  printf("❌ Opção inválida! 😐 \nTente novamente! \n");
	printf("---------------------------- \n" RESET);
}
void FilaVazia(){
	printf(VERMELHO"--------- Erro ❗ ---------- \n" RESET);
	printf(" Fila Vazia! , nenhum paciente foi encontrado 😢 \n");
	printf("-------------------------------------\n");
}





void Reorganizar(){

	for(int i=0 ; i<49; i++){
			for(int j=i+1; j<fim; j++){


					if(prioridade<=3){
					if(cadastro[i].prioridade=='V' || cadastro[i].prioridade=='v'){
							aux = cadastro[i];
							cadastro[i] = cadastro[j];
							cadastro[j] = aux;
	
							prioridade++;
					}
				}
			}
	}

	if(prioridade >=7){
		prioridade=0;
	}
}

void Cadastrar(paciente **p){
	int menucontrole = 0;
	char escolha = ' ';

	char nome , sobrenome;
	printf("--------- 📝Cadastro ---------- \n");
	printf("Cadastrar novo Paciente :\n");
	printf("Qual o nome do Paciente ?\n");
	printf("Digite o nome e sobrenome: ");
	scanf(" %s%s", &nome , &sobrenome);
	printf("Qual a urgência do paciente ?\n");
	printf(VERDE"V - Verde");
	printf(RESET" | ");
	printf(AMARELO" A - Amarelo \n" RESET);
	printf("Digite a urgência: ");
	scanf(" %c", &escolha);

		paciente *atual, *novo, *anterior;
		novo = (paciente *) malloc(sizeof(paciente));

		atual = *p;
		anterior = NULL;

	char verde = 'v';
	char amarelo = 'a';
	char prioridade;
  
	  switch(escolha)
		{
			case 'V':
      	case 'v':
				printf(VERDE"--------- 🟢 Prioridade Verde 🟢 ---------- \n"RESET);
				printf(VERDE"Prioridade definida como Verde! \n"RESET);
				printf(VERDE"-------------------------------------- \n \n \n" RESET);
				printf(VERDE"--------- Sucesso ! ---------- \n");
				printf(VERDE"✔ Conta criada com sucesso! \n");
				printf(VERDE"-------------------------------------- \n" RESET);
				prioridade = 'V';
				iniVerde++;
				tamfilaVerde = iniVerde;
				novo->posicaoPrioridadeVerde = tamfilaVerde;
				novo->posicaoGeral = tam;

				novo->nome = nome;
				novo->posicaoGeral 
				// "nó" -> "campo da estutura" = "referencia";
				
				break;
      
      case 'A':
      	case 'a':
        printf(AMARELO"--------- 🟡 Prioridade Amarela 🟡 ---------- \n" RESET);
				printf(AMARELO"Prioridade definida como Amarela! \n" RESET);
				printf(AMARELO"-------------------------------------- \n \n \n" RESET);
				printf(VERDE"--------- Sucesso ! ---------- \n");
				printf(VERDE"✔ Conta criada com sucesso! \n");
				printf(VERDE"-------------------------------------- \n" RESET);
				cadastro[i].prioridade = 'A';
				iniAmarelo++;
				tamfilaAmarela = iniAmarelo;
				cadastro[i].posicaoPrioridadeAmarela = tamfilaAmarela;
        cadastro[i].posicaoGeral = tam;
					
      break;
      default:
				Error();
		} 
  
    
	tam = tam +1; 
	i = i+1;
	fim++;
	Reorganizar();
}//VOID CADASTRAR

void Remover(){
  printf("--------- 🚶Remover Paciente da Fila ---------- \n");

	
    if(ini == fim){
		 FilaVazia();
		}else{
			ini++;

			if(tamfilaAmarela != 0){ 
		if(prioridade < 3){
				tamfilaAmarela--; 
				prioridade++;
		}	
	}else if (tamfilaVerde != 0){
		tamfilaVerde--;
		if(prioridade >=7){
			prioridade=0;
		} 
	}
		
	printf(VERDE"--------- ✔ Paciente removido com sucesso ! 😁👍---------- \n");
	menucontrole =1;
	//Reorganizar();
	}
}

// -------------------- Pesquisar (Posições Ocupadadas , Posições Livres , Tamanho da fila) -----------------
void Pesquisar(){
  menucontrole = 0;
	printf(AZUL"<------------ 🔍Pesquisar pacientes -------> \n" RESET);
	char escolha = ' ';
	char Nome[50]; // vetor para salvar o nome do paciente que sera lido abaixo e quesquisar o mesmo no vetor cadastro
	char Sobrenome[50]; //vetor para salvar o sobrenome do paciente já existente que sera lido abaixo e irá pesquisar o mesmo no vetor cadastro
	printf("Qual o nome do Paciente ?\n");
	printf("Digite o nome: ");
	scanf(" %s%s", Nome , Sobrenome);
	printf("Qual a urgência do paciente ?\n");
	printf("Digite a urgência: ");
	printf(VERDE"V - Verde");
	printf(RESET" | ");
	printf(AMARELO"A - Amarelo \n" RESET);
 	scanf(" %c", &escolha);

	 	switch(escolha)
		{
			case 'V':
      case 'v':

				for(int v=0; v < tam; v++){
				if(cadastro[v].prioridade == 'v' || cadastro[v].prioridade == 'V'){
					if( ! strcmp (cadastro[v].nome, Nome)){
						if( ! strcmp (cadastro[v].sobrenome, Sobrenome)){
					printf(VERDE"------------------ Informações do paciente📝🧑🏻 -------------------- \n" RESET);
							printf("Esse usuario esta como: \n");
							printf(" Nome: ");
					    printf("%s", cadastro[v].nome);
							printf(" \n ");
							printf("Sobrenome: ");
					    printf("%s", cadastro[v].sobrenome);
							printf(" \n ");
							printf("Prioridade: ");
							printf("%c", cadastro[v].prioridade);
							printf(" \n ");
							printf("Posição Geral: ");
							printf("%d", cadastro[v].posicaoGeral+1); 
							printf(" \n ");
							printf("Posição por prioridade: ");
							printf("%d", cadastro[ini].posicaoPrioridadeVerde+1);
							printf(" \n ");
							printf(VERDE"-------------------------------------- \n" RESET);
							achou++;
						}
					}
				}
			}//for
				if(achou <= 0){ 
					FilaVazia();
					}
				break;

      case 'A':
      	case 'a':
        for(int i = 0; i < tam; i++){
				if(cadastro[i].prioridade == 'a' || cadastro[i].prioridade == 'A'){
				printf(AMARELO"------------------ Informações do paciente📝🧑🏻 -------------------- \n" RESET);
				printf("Esse usuario esta como: \n");
				printf(" Nome: ");
				printf("%s", cadastro[i].nome);
				printf(" \n ");
				printf("Sobrenome: ");
				printf("%s", cadastro[i].sobrenome);
				printf(" \n ");
				printf("Prioridade: ");
				printf("%c", cadastro[i].prioridade);
				printf(" \n ");
				printf("Posição Geral: ");
				printf("%d", cadastro[ini].posicaoGeral +1); 
				printf(" \n ");
				printf("Posição por prioridade: ");
				printf("%d", cadastro[ini].posicaoPrioridadeAmarela+1); 
				printf(" \n ");
				printf(AMARELO"-------------------------------------- \n" RESET);
					achou++;
					}//IF
			}//FOR
				if(achou <= 0){
 				FilaVazia(); 
					}
					break;	
      default:Error();}//SWITCH
		menucontrole =1;
}//VOID PESQUISAR
// -------------------------- Ver Fila Completa (Corre toda a fila e mostra todos os pacientes, nome , sobrenome , e a sua prioridade dentro da fila geral) -----------------
void VfilaCompleta(){

  int i = ini;
	int indice=0;
  menucontrole = 0;
	printf(AZUL"--------- 📋Visualizar Fila Completa ---------- \n" RESET);
	if(ini == fim){ 
    FilaVazia(); 
    }else{
			do{ 
				if(indice <9){
					printf(" 0%d" , indice+1); 
				}else if( indice >=9){
				printf(" %d" , indice+1); 
				}
					printf(" - ");
					printf("Nome: "); 
					printf("%s" , cadastro[i].nome);
					printf(" ");
					printf("%s" , cadastro[i].sobrenome);
          printf(" | ");
					printf("Prioridade: ");
          printf("%c" , cadastro[i].prioridade);
					printf(" | ");
          printf(" \n");
					i++; 
					indice++;
				}while(i<50);
   
		} menucontrole =1;
  }

// -------------- Ver Fila por tipo de urgencia|Prioridade (corre toda a fila e mostra apenas os pacientes de acordo com a prioridade escolhida no sistema) -----------------
void VfilaTipoUrgencia(){
	int indice=0;
	printf(AZUL"--------- 📋Visualizar Tipo de Urgência ---------- \n" RESET);
	char escolha = ' ';
	char nome = ' ';
	printf("Qual a urgência do paciente ?\n");
	printf(VERDE"V - Verde");
  printf(RESET" | ");
  printf(AMARELO"A - Amarelo \n" RESET);
	printf("Digite a urgência: ");
  scanf(" %c", &escolha);
	 	switch(escolha){
			
      case 'V':
      case 'v':
        printf(VERDE"--------- 🟢Prioridade Verde🟢 ---------- \n" RESET);
        if(tamfilaVerde == 0){ 
					FilaVazia();
					}else{
					for(int f=0; f < tamfilaVerde+2; f++){
					if(cadastro[f].prioridade == 'v' || cadastro[f].prioridade == 'V'){
						printf("%d" , indice+1); 
            printf(" - ");
						printf("%s" , cadastro[f].nome); 
            printf(" - ");
						printf("%s" , cadastro[f].sobrenome);
            printf("\n");
						indice++;
					}
				}
			break;

			case 'A':
      case 'a':
        printf(AMARELO"--------- 🟡Prioridade Amarela🟡 ---------- \n" RESET);
				if(tamfilaAmarela == 0){
					FilaVazia(); 
					}
				else
        {
					for(int t=0; t < tamfilaAmarela+2; t++){
						if(cadastro[t].prioridade == 'a' || cadastro[t].prioridade == 'A'){
						printf("%d" , indice+1);
						printf(" - ");
						printf("%s" , cadastro[t].nome); 
						printf(" - ");
						printf("%s" , cadastro[t].sobrenome);
						printf("\n");
						indice++;
						}
					}
				}
				break;
      	default:
				Error();
		}
  } menucontrole =1;
}
// --------------------- Consultar Fila (Posições Ocupadadas , Posições Livres , Tamanho da fila) -----------------
void ConsultarFila(){
  int menucontrole = 0;
	printf(AZUL"--------- 📋Consultar Fila ---------- \n" RESET);
	printf("Tamanho da fila: ");
	printf("%d" , tam);
	printf(" \n");
	printf("Posições ocupadas: ");
	printf("%d" , tam); 
	printf(" \n");
	printf("Posições livres: ");
	printf("%d" , 50 - tam); 
	printf(" \n");
	menucontrole =1;
}//Void ConsultarFila
// ------------------------- Menu da Aplicação (Faz o rotiamento da aplicação , o menu que gerencia as rotas e chama as demais funções da aplçicação) -----------------
void Menu(){
  int i;
	do{
		printf(AZUL"------------------ Menu ---------------- \n" RESET);
		printf("1 - 📝Cadastrar Paciente \n");
		printf("2 - 🚶Remover Paciente \n");
		printf("3 - 🔍Pesquisar Paciente por nível de urgência \n");
		printf("4 - 📋Visualizar fila completa \n");
 	 	printf("5 - 📋Visualizar fila por tipo de urgência \n");
  	printf("6 - 📋Consultar situação da fila \n");
		printf("Digite uma Opção: ");
		scanf("%d", &i);
		printf(AZUL"---------------------------------------- \n" RESET);
			switch(i){
      case 1:Cadastrar();break;
      case 2:Remover(); break;
      case 3:Pesquisar();break;
      case 4:VfilaCompleta();break;
      case 5:VfilaTipoUrgencia();break;
      case 6:ConsultarFila(); break;
      default: Error();}
	}while(menucontrole ==1); 
}
// ----------------- Main (classe principal da nossa aplicação, ela que sera chamada quando o código rodar) -----------------
int main(){ 
	setlocale (LC_ALL,"portuguese"); // define o idioma do projeto como portugês brasil
	Menu(); // chama o menu
}