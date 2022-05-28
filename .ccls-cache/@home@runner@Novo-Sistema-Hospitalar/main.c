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
 
typedef struct Paciente Paciente;

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

void Sucesso(){
	printf(VERDE"--------- Sucesso ! ---------- \n");
	printf(VERDE"✔ Conta criada com sucesso! \n");
	printf(VERDE"-------------------------------------- \n" RESET);
}

void inicia(Paciente *p, int *tam){
 p->prox = NULL;
 (*tam) = 0;
}// Inicia a fila

int vazia(Paciente *p){
 if(p->prox == NULL)
  return 1;
 else
  return 0;
} // Verifica se a fila esta vazia


Paciente * aloca(){
 Paciente *novo = (Paciente *) malloc(sizeof(Paciente));
 if(!novo){
  printf("Sem memoria disponivel!\n");
  exit(1);
 }else{
	//Cadastrar Paciente
  printf("--------- 📝Cadastro ---------- \n");
	 //cadastrar
  scanf("%s", novo->nome);
  return novo;
 }
}// aloca um novo nó na memória e incese as informações nesse nó.


void Cadastrar(Paciente *p){ // chama aloca e linka os ponteiros para o anterior e o proximo da fila
	int menucontrole = 0;
	char escolha = ' ';

	char nome[50] , sobrenome[50];
	printf("--------- 📝Cadastro ---------- \n");
	printf("Cadastrar novo Paciente :\n");
	printf("Qual o nome do Paciente ?\n");
	printf("Digite o nome e sobrenome: ");
	scanf(" %s%s", nome , sobrenome);
	printf("Qual a urgência do paciente ?\n");
	printf(VERDE"V - Verde");
	printf(RESET" | ");
	printf(AMARELO" A - Amarelo \n" RESET);
	printf("Digite a urgência: ");
	scanf(" %c", &escolha);

		Paciente *novo = aloca();

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
				Sucesso();
				prioridade = 'V';
				iniVerde++;
				tamfilaVerde = iniVerde;
				(p)->posicaoPrioridadeVerde = tamfilaVerde;
				(p)->posicaoGeral = tam;
				for(i=0 ; nome[i] != '\0'; i++){
						(p)->nome[i] = nome[i]; 
					}
				for(i=0 ; sobrenome[i] != '\0'; i++){
          (p)->sobrenome[i] = sobrenome[i];
        }
		    (p)->prioridade = 'v';

				break;
      
      case 'A':
      	case 'a':
        printf(AMARELO"--------- 🟡 Prioridade Amarela 🟡 ---------- \n" RESET);
				printf(AMARELO"Prioridade definida como Amarela! \n" RESET);
				printf(AMARELO"-------------------------------------- \n \n \n" RESET);
				Sucesso();
				iniAmarelo++;
				tamfilaAmarela = iniAmarelo;
				(p)->posicaoPrioridadeVerde = tamfilaAmarela;
				(p)->posicaoGeral = tam;
					for(i=0 ; nome[i] != '\0'; i++){
						(p)->nome[i] = nome[i]; 
					}
				for(i=0 ; sobrenome[i] != '\0'; i++){
          (p)->sobrenome[i] = sobrenome[i];
        }
  			
		    (p)->prioridade = 'a';
      break;
      default:
				Error();
		} 
  
	tam = tam +1; 
	i = i+1;
	fim++;
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

//Pesquisar (Posições Ocupadadas , Posições Livres , Tamanho da fila) 
void Pesquisar(Paciente *p){
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
				if(p->prioridade == 'v' || p->prioridade == 'V'){
					if( ! strcmp (p->nome, Nome)){
						if( ! strcmp (p->sobrenome, Sobrenome)){
					printf(VERDE"------------------ Informações do paciente📝🧑🏻 -------------------- \n" RESET);
							printf("Esse usuario esta como: \n");
							printf(" Nome: ");
					    printf("%s", p->nome);
							printf(" \n ");
							printf("Sobrenome: ");
					    printf("%s", p->sobrenome);
							printf(" \n ");
							printf("Prioridade: ");
							printf("%c", p->prioridade);
							printf(" \n ");
							printf("Posição Geral: ");
							printf("%d", p->posicaoGeral+1); 
							printf(" \n ");
							printf("Posição por prioridade: ");
							printf("%d", p->posicaoPrioridadeVerde+1);
							printf(" \n ");
							printf(VERDE"-------------------------------------- \n" RESET);
							achou++;
						}//3º if
					}//2º if
				}//1º if
			}//for
				if(p->posicaoGeral == 0){ 
					FilaVazia();
					}
				break;

      case 'A':
      	case 'a':
        for(int i = 0; i < tam; i++){
				if(p->prioridade == 'a' || p->prioridade == 'A'){
				printf(AMARELO"------------------ Informações do paciente📝🧑🏻 -------------------- \n" RESET);
				printf("Esse usuario esta como: \n");
				printf(" Nome: ");
				printf("%s", p->nome);
				printf(" \n ");
				printf("Sobrenome: ");
				printf("%s", p->sobrenome);
				printf(" \n ");
				printf("Prioridade: ");
				printf("%c", p->prioridade);
				printf(" \n ");
				printf("Posição Geral: ");
				printf("%d", p->posicaoGeral +1); 
				printf(" \n ");
				printf("Posição por prioridade: ");
				printf("%d", p->posicaoPrioridadeAmarela+1); 
				printf(" \n ");
				printf(AMARELO"-------------------------------------- \n" RESET);
					achou++;
					}//IF
			}//FOR
				if(p->posicaoGeral == 0){
 					FilaVazia(); 
					}
					break;	
      default:Error();}//SWITCH
		menucontrole =1;
}//VOID PESQUISAR

//  Ver Fila Completa (Corre toda a fila e mostra todos os pacientes, nome , sobrenome , e a sua prioridade dentro da fila geral)
void VfilaCompleta(Paciente *p){
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
					printf("%s" , p->nome);
					printf(" ");
          printf("%s" , p->sobrenome);
          printf(" | ");
  				printf("Prioridade: ");
          printf("%c" , p->prioridade);
  				printf(" | ");
          printf(" \n");
					i++; 
					indice++;
				}while(i<50);
		} menucontrole =1;
  }

// Ver Fila por tipo de urgencia|Prioridade (corre toda a fila e mostra apenas os pacientes de acordo com a prioridade escolhida no sistema)
void VfilaTipoUrgencia(Paciente *p){
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
					if(p->prioridade == 'v' || p->prioridade == 'V'){
						printf("%d" , indice+1); 
            printf(" - ");
						printf("%s" , p->nome);
            printf(" - ");
						printf("%s" , p->sobrenome);
            printf("\n");
						indice++;
					}//if
				}//for
			}//else
			break;
			case 'A':
      case 'a':
        printf(AMARELO"--------- 🟡Prioridade Amarela🟡 ---------- \n" RESET);
				if(tamfilaAmarela == 0){
					FilaVazia(); 
					}else{
					for(int t=0; t < tamfilaAmarela+2; t++){
						if(p->prioridade == 'a' || p->prioridade == 'A'){
						printf("%d" , indice+1);
						printf(" - ");
            printf("%s" , p->nome);
					  printf(" - ");
						printf("%s" , p->sobrenome);
						printf("\n");
						indice++;
						}
					}
				}
				break;
      	default:
				Error();
  } menucontrole =1;
}

// Consultar Fila (Posições Ocupadadas , Posições Livres , Tamanho da fila) 
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

// Menu da Aplicação (Faz o rotiamento da aplicação , o menu que gerencia as rotas e chama as demais funções da aplçicação) 
void Menu(){
  int i;

	Paciente *p = (Paciente *) malloc(sizeof(Paciente));
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
      case 1:Cadastrar(p);break;
      case 2:Remover(); break;
      case 3:Pesquisar(p);break;
      case 4:VfilaCompleta(p);break;
      case 5:VfilaTipoUrgencia(p);break;
      case 6:ConsultarFila(); break;
      default: Error();}
	}while(menucontrole ==1); 
}

//  Main (classe principal da nossa aplicação, ela que sera chamada quando o código rodar)
int main(){ 
	setlocale (LC_ALL,"portuguese"); // define o idioma do projeto como portugês brasil
	Menu(); // chama o menu
}