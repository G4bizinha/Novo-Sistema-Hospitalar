#include <stdio.h>
#include <stdlib.h>
#include <locale.h> 
#include <string.h>
#include <unistd.h>

int menucontrole = 1;
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
  int posicaoGeral;//salva a posição do paciente da fila por ordem de chegada.
	int posicaoPrioridadeVerde;//salva a posição do paciente pela prioridade Verde
	int posicaoPrioridadeAmarela;//salva a posição do paciente pela prioridade Amarela
	struct Paciente *ant; //pegar o paciente anterior
	struct Paciente *prox; //pegar o proximo paciente
};
 
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
	p->ant = NULL;
 (*tam) = 0;
}

int vazia(Paciente *p){
 if(p->prox == NULL){
	 return 1;
	 FilaVazia();
 }else{
	 return 0;
 }
} // Verifica se a fila esta vazia

void InserirPacienteAmarelo(Paciente *novo , int tam){
  
 		printf("--------- 📝Cadastro ---------- \n");
		printf("Cadastrar novo Paciente :\n");
		printf("Digite o nome e sobrenome: ");
		scanf("%s", novo->nome);
		scanf("%s", novo->sobrenome);
		novo->posicaoGeral = tam;
    printf(AMARELO"--------- 🟡 Prioridade Amarela 🟡 ---------- \n" RESET);
		printf(AMARELO"Prioridade definida como Amarela! \n" RESET);
		printf(AMARELO"-------------------------------------- \n \n \n" RESET);
		Sucesso();
		iniAmarelo++;
		tamfilaAmarela = iniAmarelo;
		novo->posicaoPrioridadeAmarela = tamfilaAmarela;
		novo->prioridade = 'a';
}

void InserirPacienteVerde(Paciente *novo, int tam){
    printf("--------- 📝Cadastro ---------- \n");
		printf("Cadastrar novo Paciente :\n");
		printf("Digite o nome e sobrenome: ");
		scanf("%s", novo->nome);
		scanf("%s", novo->sobrenome);
		novo->posicaoGeral = tam;
		printf(VERDE"--------- 🟢 Prioridade Verde 🟢 ---------- \n"RESET);
		printf(VERDE"Prioridade definida como Verde! \n"RESET);
		printf(VERDE"-------------------------------------- \n \n \n" RESET);
		Sucesso();
		iniVerde++;
		tamfilaVerde = iniVerde;
		novo->posicaoPrioridadeVerde = tamfilaVerde;
		novo->prioridade = 'v';
}
  Paciente *aloca()
{
 Paciente *novo = (Paciente *) malloc(sizeof(Paciente));
 if(!novo){
  printf("Sem memoria disponivel!\n");
  exit(1);
 }else{
  printf("Novo elemento: ");
	
  scanf("%s", novo->nome);//salvando só o nome
  return novo;
 }
}

void inserirFim(Paciente *p , int *tam){
	//chama o aloca e passa ele como um novo nó
	Paciente *novo = aloca();
	novo->prox = NULL;

	if(vazia(p)){
		p->prox=novo;
	}else{
		Paciente *tmp = p->prox;

		while(tmp->prox !=NULL)
			tmp = tmp->prox;

			tmp->prox = novo;
      }
    (*tam)++;
}



void CadastrarPaciente(){
 char escolha = ' ';
	printf("Qual a urgência do paciente ?\n");
	printf(VERDE"V - Verde");
	printf(RESET" | ");
	printf(AMARELO" A - Amarelo \n" RESET);
	printf("Digite a urgência: ");
	scanf(" %c", &escolha);

		switch(escolha){

		case 'v': 
		case 'V':
   // InserirPacienteVerde();
		break;

    case 'a':
    case 'A':
  //  InserirPacienteAmarelo(); 
		break;
	}
}

/*
void Cadastrar(Paciente *p , int tam){ // chama aloca e linka os ponteiros para o anterior e o proximo da fila
	int menucontrole = 0;
	
	Paciente *novo = aloca(tam);
 	novo->prox = NULL;

	tam = tam +1; 
	i = i+1;
	fim++;
}//VOID CADASTRAR

*/

void Remover(){
  printf("--------- 🚶Remover Paciente da Fila ---------- \n");

    //codigo para remover paciente
		
	printf(VERDE"--------- ✔ Paciente removido com sucesso ! 😁👍---------- \n");
	menucontrole =1;
	//Reorganizar();
}


//Pesquisar (Posições Ocupadadas , Posições Livres , Tamanho da fila) 
void Pesquisar(Paciente *p, int tam){
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
void VfilaCompleta(Paciente *p , int tam){
	if(vazia(p)){
		printf(AZUL"A Fila está vazia! 🥲" RESET);
	}else{
	Paciente *tmp;
	tmp = p->prox;
	printf(AZUL"--------- 📋Visualizar Fila Completa ---------- \n" RESET);
	while(tmp != NULL){
		printf("Nome:");
		printf("%s", tmp ->nome);
		tmp = tmp->prox;
		}
		printf("\n");
	}
}
// Ver Fila por tipo de urgencia|Prioridade 
//(corre toda a fila e mostra apenas os pacientes de acordo com a prioridade escolhida no sistema)
void VfilaTipoUrgencia(Paciente *p , int tam){
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
void ConsultarFila(int tam){
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

// Menu da Aplicação (Faz o rotiamento da aplicação , o menu que gerencia as rotas e chama as demais funções da aplicação) 
void Menu(){
  int i , tam;
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
      case 1:inserirFim(p, &tam);break;
      case 2:Remover(); break;
      case 3:Pesquisar(p,tam);break;
      case 4:VfilaCompleta(p, tam);break;
      case 5:VfilaTipoUrgencia(p, tam);break;
      case 6:ConsultarFila(tam); break;
      default:Error();
				}
		}while(menucontrole ==1); 
}
		
//  Main (classe principal da nossa aplicação, ela que sera chamada quando o código rodar)
int main(){ 
	int tam; //guarda total de elementos
	Paciente *p = (Paciente *) malloc(sizeof(Paciente)); 
	inicia(p,&tam);
	setlocale (LC_ALL,"portuguese"); // define o idioma do projeto como portugês brasil
	Menu(); // chama o menu
	
}