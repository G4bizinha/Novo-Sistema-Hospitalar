#include <stdio.h>
#include <stdlib.h>
#include <locale.h> 
#include <string.h>
#include <unistd.h>

int menucontrole = 1 , ini, fim , tamfilaAmarela=0, tamfilaVerde = 0 , achou , i=0 , prioridade, iniAmarelo, fimAmarela , iniVerde, fimVerde;

// sistema de cores
#define VERDE "\x1b[32m"  
#define AMARELO "\x1b[93m"
#define VERMELHO "\x1b[31m"
#define AZUL "\x1b[34m"
#define RESET "\x1b[0m"

void Error(){ //mensagem de erro se a opção estiver errada
	printf(VERMELHO" \n ---------- Erro ❗ ---------- \n ❌ Opção inválida! 😐 \nTente novamente! \n ---------------------------- \n"RESET);
}

void FilaVazia(){ // mensagem de erro - Fila Vazia
	printf(VERMELHO"--------- Erro ❗ ---------- \n Fila Vazia! , nenhum paciente foi encontrado 😢 \n -------------------------------------\n" RESET);
}

void Sucesso(int i){ // Mensagem de sucesso - quando o usuario é criado com sucesso e a aocção foi feita
	switch(i){
		case 1: //mensagem de sucesso padrão
				printf(VERDE"\n--------- Sucesso ! ---------- \n ✔ Conta criada com sucesso! \n -------------------------------------- \n" RESET);
			break;
		case 2: // mensagem de suceso ao definir a prioridade Amarela
				printf(AMARELO"\n---------  Prioridade Amarela  ---------- \n Prioridade definida como Amarela! \n -------------------------------------- \n" RESET);
			break;
		case 3: // mensagem de suceso ao definir a prioridade Verde
				printf(VERDE"\n---------  Prioridade Verde  ---------- \n Prioridade definida como Verde! \n -------------------------------------- \n" RESET);
			break;
		}
}

struct Paciente{
  char nome[50];//salva o nome do paciente na fila
	char sobrenome[50];//salvar o sobrenome 
  char prioridade;//salva a prioridade do paciente   V ou A
  int posicaoGeral;//salva a posição do paciente da fila por ordem de chegada.
	int posicaoPrioridadeVerde;//salva a posição do paciente pela prioridade Verde
	int posicaoPrioridadeAmarela;//salva a posição do paciente pela prioridade Amarela
	struct Paciente *prox; //pegar o proximo paciente
};
typedef struct Paciente Paciente;

void inicia(Paciente *p, int *tam){ // inicia a fila
 	p->prox = NULL;
 (*tam) = 0;
}

int vazia(Paciente *p){ //verifica se a fila está vazia
 if(p->prox == NULL){
	 return 1;
	 FilaVazia();
 }else{
	 return 0;
 }
} // Verifica se a fila esta vazia

void Realoca(Paciente *p){ // realoca quem tem prioridade para frente da fila
	if (prioridade == 'a' || prioridade == 'A') {
    //p->prioridade=ini;
		// verifica a prioridade e se entre as prioridades leva e m cinsideração a ordem de chegada pela prioridade
		/* pegar o if epasar pra void aloca e chamr o realoca na propria void. aí ddentro da void realocar vai ter as funçoes dele

*/
  }
}

Paciente *aloca(){ // aloca um novo nó para salvar um novo paciente
 Paciente *novo = (Paciente *) malloc(sizeof(Paciente));
	char prioridade = ' ';
 if(!novo){
  printf("❗ Erro -> Sem memoria disponivel!\n");
  exit(1);
 }else{
	 	printf("--------- 📝Cadastro ---------- \n");
		printf("Cadastrar novo Paciente :\n");
		printf("Digite o nome e sobrenome: ");
		scanf("%s", novo->nome);
		scanf("%s", novo->sobrenome);
	 	//novo->posicaoGeral = tam;

	 printf("Qual a prioridade do paciente?");
	 scanf("%c", &prioridade);
    switch (prioridade){
			case 'V':
      case 'v':
				//prioridade verde
				Sucesso(1);
				Sucesso(3);
				iniVerde++;
				tamfilaVerde = iniVerde;
				novo->posicaoPrioridadeVerde = tamfilaVerde;
				novo->prioridade = 'v';
				break;
			case 'A':
      case 'a':
				//prioridade amarela
				Sucesso(1);
				Sucesso(2);
				iniAmarelo++;
				tamfilaAmarela = iniAmarelo;
				novo->posicaoPrioridadeAmarela = tamfilaAmarela;
				novo->prioridade = 'a';
				break;
     }
   }return novo;
}//ALOCA


void inserirFim(Paciente *p , int *tam){ // insere um novo paciente no final da fila
	Paciente *novo = aloca(); //chama o aloca e passa ele como um novo nó
	novo->prox = NULL; // define o proximo desse novo no como null , pois ele é o umtimo da fila, só sera mudado quando um novo nó fod adicionado
	if(vazia(p)){ 
		p->prox=novo; 
		}else{
		Paciente *tmp = p->prox;
		while(tmp->prox !=NULL){
			tmp = tmp->prox;
		}
			tmp->prox = novo;
  } 
	  (*tam)++;

	
  if (prioridade == 'a' || prioridade == 'A') {
    p->prioridade=ini;
		// verifica a prioridade e se entre as prioridades leva e m cinsideração a ordem de chegada pela prioridade
		 //pegar o if epasar pra void aloca e chamr o realoca na propria void. aí ddentro da void realocar vai ter as funçoes dele
    }

}//InserirFim

void Remover(Paciente *p, int tam){ //remove um paciente da fila
  printf("--------- 🚶Remover Paciente da Fila ---------- \n");

  /*Paciente *novo = aloca(); //chama o aloca e passa ele como um novo nó
	novo->prox = NULL; // define o proximo desse novo no como null , pois ele é o umtimo da fila, só sera mudado quando um novo nó fod adicionado
	if(vazia(p)){ 
		p->prox=novo; 
		}else{
		Paciente *tmp = p->prox;
		while(tmp->prox !=NULL){
			tmp = tmp->prox;
		}
			tmp->prox = NULL;
  } 
	  (*tam)--;
  */
	
	printf(VERDE"--------- ✔ Paciente removido com sucesso ! 😁👍---------- \n");
	menucontrole=1 ;
}//Remover

void Pesquisar(Paciente *p, int tam){ //Pesquisar (Posições Ocupadadas , Posições Livres , Tamanho da fila) 
  menucontrole = 0;
	printf(AZUL"<------------ 🔍Pesquisar pacientes -------> \n" RESET);
	char escolha = ' ';
	char Nome[50]; // vetor para salvar o nome do paciente que sera lido abaixo e pesquisar o mesmo no vetor cadastro
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
	 	switch(escolha){
			case 'V':
      case 'v':
				for(int v=0; v < tam; v++){
				if(p->prioridade == 'v' || p->prioridade == 'V'){
					if( ! strcmp (p->nome, Nome)){
						if( ! strcmp (p->sobrenome, Sobrenome)){
							printf(VERDE"------------------ Informações do paciente📝🧑🏻 -------------------- \n" RESET);
							printf("Esse usuario esta como: \n");
							printf(" Nome: %s", p->nome );
							printf(" \n Sobrenome: %s", p->sobrenome );
							printf(" \n Prioridade: %c",p->prioridade );
							printf(" \n Posição Geral: %d", p->posicaoGeral+1 );
							printf(" \n Posição por prioridade: %d", p->posicaoPrioridadeVerde+1 );
							printf(VERDE" \n -------------------------------------- \n" RESET);
							achou++;
						}//3º if
					}//2º if
				}//1º if
			}//for
				if(p->posicaoGeral == 0){ FilaVazia(); }
				break;
      case 'A':
      case 'a':
        for(int i = 0; i < tam; i++){
				if(p->prioridade == 'a' || p->prioridade == 'A'){
				printf(AMARELO"------------------ Informações do paciente📝🧑🏻 -------------------- \n" RESET);
					printf("Esse usuario esta como: \n");
					printf(" Nome: %s", p->nome );
					printf(" \n Sobrenome: %s", p->sobrenome );
					printf(" \n Prioridade: %c",p->prioridade );
					printf(" \n Posição Geral: %d", p->posicaoGeral+1 );
					printf(" \n Posição por prioridade: %d", p->posicaoPrioridadeVerde+1 );
				printf(AMARELO"-------------------------------------- \n" RESET);
					achou++;
					}//IF
			}//FOR
				if(p->posicaoGeral == 0){ FilaVazia(); }
					break;	
      default:Error();}//SWITCH
		menucontrole =1;
}//VOID PESQUISAR

//  Ver Fila Completa (Corre toda a fila e mostra todos os pacientes, nome , sobrenome , e a sua prioridade dentro da fila geral)
void VfilaCompleta(Paciente *p){ // visualizar fila completa 
	if(vazia(p)){ FilaVazia(); }else{
	Paciente *tmp;
	tmp = p->prox;
	printf(AZUL"--------- 📋Visualizar Fila Completa ---------- \n" RESET);
	while(tmp != NULL){
		printf("Nome: %s", tmp ->nome);
		tmp = tmp->prox;
		}
		printf("\n");
	}
}
// Ver Fila por tipo de urgencia|Prioridade 
//(corre toda a fila e mostra apenas os pacientes de acordo com a prioridade escolhida no sistema)
void VfilaTipoUrgencia(Paciente *p , int tam){
	int indice=0;
	char escolha = ' ' , nome = ' ';
	printf(AZUL"--------- 📋Visualizar Tipo de Urgência ---------- \n" RESET);
	printf("Qual a urgência do paciente ?\n");
	printf(VERDE"V - Verde");
  printf(RESET" | ");
  printf(AMARELO"A - Amarelo \n" RESET);
	printf("Digite a urgência: ");
  scanf(" %c", &escolha);
	 	switch(escolha){
      case 'V':
      case 'v':
        printf(VERDE" \n \n --------- Prioridade Verde ---------- \n" RESET);
        if(tamfilaVerde == 0){ 
					FilaVazia();
					}else{
					for(int f=0; f < tamfilaVerde+2; f++){
					if(p->prioridade == 'v' || p->prioridade == 'V'){
							printf("%d" , indice+1); 
							printf(" - %s" , p->nome);
							printf(" - %s" , p->sobrenome);
						indice++;
					}//if
				}//for
			}//else
			break;
			case 'A':
      case 'a':
        printf(AMARELO" \n \n --------- Prioridade Amarela ---------- \n" RESET);
				if(tamfilaAmarela == 0){
					FilaVazia(); 
					}else{
					for(int t=0; t < tamfilaAmarela+2; t++){
						if(p->prioridade == 'a' || p->prioridade == 'A'){
							printf("%d" , indice+1); 
							printf(" - %s" , p->nome);
							printf(" - %s" , p->sobrenome);
						indice++;
						}
					}
				}
				break;
      	default:
				Error();
  } menucontrole =1;
}

void ConsultarFila(int tam){ // Consultar Fila (Posições Ocupadadas , Posições Livres , Tamanho da fila) 
	printf(AZUL"--------- 📋Consultar Fila ---------- \n" RESET);
	printf(" \n Tamanho da fila: %d" , tam);
	printf(" \n Posições ocupadas: %d" , tam);
	printf(" \n Posições livres: %d" , tam);
	menucontrole =1;
}

void Menu(){ // Menu da Aplicação (Faz o rotiamento da aplicação , o menu que gerencia as rotas e chama as demais funções da aplicação) 
  int i , tam;
	Paciente *p = (Paciente *) malloc(sizeof(Paciente)); 
	do{
		printf(AZUL" \n \n ------------------ Menu ---------------- \n" RESET);
		printf(" 1 - 📝Cadastrar Paciente \n 2 - 🚶Remover Paciente \n 3 - 🔍Pesquisar Paciente por nível de urgência \n");
		printf(" 4 - 📋Visualizar fila completa \n 5 - 📋Visualizar fila por tipo de urgência \n 6 - 📋Consultar situação da fila \n");
		printf("Digite uma Opção: ");
		scanf("%d", &i);
		printf(AZUL"---------------------------------------- \n \n " RESET);
			switch(i){ 
      case 1:inserirFim(p, &tam);break; //
      case 2:Remover(p, tam); break; // tbm precisa passar o tam como referencia / tambem deve passar o p
      case 3:Pesquisar(p,tam);break; // é passada como cópia poris pesquisar não faz alteração no tamanho da fila
      case 4:VfilaCompleta(p);break; // 
      case 5:VfilaTipoUrgencia(p, tam);break;
      case 6:ConsultarFila(tam); break; //
      default:Error(); }
		}while(menucontrole ==1); }
		
int main(){  
	int tam; 
	Paciente *p = (Paciente *) malloc(sizeof(Paciente));// inicio esta na paciente p. 
	inicia(p,&tam);
	setlocale (LC_ALL,"portuguese"); // define o idioma do projeto como portugês brasil
	Menu(); 
}