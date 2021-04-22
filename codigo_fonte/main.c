#include <stdio.h>
#include <stdlib.h>
#include "pokedex_ascii.h"


char user[50];
char nome[152][100];
char tipo[152][100];
char poder[152][100];
char aptidao[152][10];
int ncadastro;
int cadastro, fim;
int menu, continuar;
int cadn[152], cadt[152], cadp[152], cada[152];
int ok;


void fmenu();
void cadastrar();
void oqc();
void editar();
void oqe();
void logo();

int main() {

	logo();
	printf("\n");
	printf("Ola, digite seu nome: ");
	scanf("%[^\n]", user);
	printf("\n");
	printf("\n");
	printf("\n");
	printf("    Bem Vindo, %s!\n", user);
	printf("\n");
	fmenu();

	return 0;
}
//
void fmenu() {


	printf("\n");
	printf("\n");
	printf("\n");
	printf("Voce esta no Pokemenu! Escolha uma das opcoes abaixo:\n");
	printf("\n");
	printf("\n");
	printf("(1) Cadastrar\n");
	printf("(2) Consultar\n");
	printf("(3) Editar\n");
	printf("(4) Excluir\n");
	printf("\n");
	printf("(0) Sair\n");

	printf("\n");
	printf("\n");
	printf("Digite a opcao desejada: ");
	scanf("%d", &menu);
	////////linux = system("clear");
	system("cls");

	switch (menu) {
	case 1:
        logo();
		cadastrar();

		break;

	case 2:
	    logo();
		break;
	case 3:
        logo();
	    editar();

		break;
	case 4:
	    logo();
		break;
	case 0:
	    logo();
	    system("pause");
		exit(0);
		break;

	default:
	    logo();
	    printf("\n");
	    printf("\n");
		printf("Opcao invalida, digite novamente");
		printf("\n");
		printf("\n");
		fmenu();
		break;
	}
}

void logo(){

    printf("   ___________________________________________  \n");
	printf("  |  _-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_  |  \n");
	printf("  | |                                       | |  \n");
	printf("  | |                   /                   | |  \n");
	printf("  | |  |--: [--] | _/ |--- |--| |--- -X /-  | |  \n");
	printf("  | |  |__: |  | |<_  |--- |  ] |---   X    | |  \n");
	printf("  | |  |    {__} |  | |___ |__/ |___ _/ x_  | |  \n");
	printf("  | |                                       | |  \n");
	printf("  | |_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_| |  \n");
    printf("  |___________________________________________|  \n");
	printf("\n");
	printf("\n");



}

void cadastrar() {
	printf("\n");
	printf("\n");
	printf("CADASTAR POKEMON\n");
	printf("\n");
	printf("\n");
	do {
		printf("Digite o numero do Pokemon que voce deseja cadastrar [De 1 a 151]:  ");
		scanf("%d", &ncadastro);

		system("cls");


		printf("\n");
		printf("\n");

	} while (ncadastro < 1 || ncadastro > 151);

    do{
    printf("\n");
    printf("\n");
    print_pokemon(ncadastro);
    printf("\n");
    printf("\n");
    printf("Pokemon (%d), deseja continuar?  \n", ncadastro);
    printf("\n");

    printf("\n");
    printf("(1) Sim\n");
    printf("(2) Nao\n");
    printf("\n");
    printf("\n");
    printf("Digite sua escolha:  ");
    scanf("%d", &continuar);
    system("cls");
    }while(continuar!=1&&continuar!=2);
    system("cls");
    printf("\n");
    printf("\n");
    if(continuar==2){
      cadastrar();
    } else if(continuar==1){




  oqc();


      printf("\n");
      printf("\n");
      printf("(0) Menu\n");
      printf("(1) Sair");
      printf("\n");
      printf("\n");


      printf("Digite a opcao desejada: ");
      scanf("%d", &fim);
      switch (fim) {
      case 0:
        system("cls");
        fmenu();
        break;

      case 1:
          system("pause");
        exit(0);
        break;
      }
    }

}


void oqc() {
    printf("\n");
    printf("\n");
  printf("O que voce deseja cadastrar?\n");
  printf("\n");
  printf("\n");
  printf("(1) Nome\n");
  printf("(2) Tipo\n");
  printf("(3) Poder\n");
  printf("(4) Aptidao para batalha\n");
  printf("\n");
  printf("(0) Voltar ao Pokemenu\n");
  printf("\n");
  printf("\n");
  printf("Digite a opcao desejada: ");
  scanf("%d", &cadastro);

  system("cls");
  printf("\n");

  switch (cadastro) {
  case 1:
  printf("\n");
  printf("\n");
  print_pokemon(ncadastro);
  printf("\n");
  printf("\n");
  printf("\n");
  printf("Digite o nome do Pokemon: ");
  scanf("%s", nome[ncadastro]);
  printf("\n");
  printf("\n");
  cadn[ncadastro]=1;
  printf("\n");
  printf("O nome do Pokemon (%d): %s\n", ncadastro, nome[ncadastro]);

  break;

  case 2:
  printf("\n");
  printf("\n");
  print_pokemon(ncadastro);
  printf("\n");
  printf("\n");
  printf("\n");
  printf("Digite o tipo do Pokemon: ");
  scanf("%s", tipo[ncadastro]);
  printf("\n");
  printf("\n");
  cadt[ncadastro]=1;
  printf("\n");
  printf("O Pokémon (%d) e do tipo: %s\n", ncadastro, tipo[ncadastro]);
  break;

  case 3:
  printf("\n");
  printf("\n");
  print_pokemon(ncadastro);
  printf("\n");
  printf("\n");
  printf("\n");
  printf("Digite o poder do Pokemon: ");
  scanf("%s", poder[ncadastro]);
  printf("\n");
  printf("\n");
  cadp[ncadastro]=1;
  printf("\n");
  printf("O Pokemon (%d) tem o seguinte poder: %s\n", ncadastro,
  poder[ncadastro]);
  break;

  case 4:
  printf("\n");
  printf("\n");
  print_pokemon(ncadastro);
  printf("\n");
  printf("\n");
  printf("\n");
  printf("O Pokemon esta apto a lutar? ");
  scanf("%s", aptidao[ncadastro]);
  printf("\n");
  printf("\n");
  cada[ncadastro]=1;
  printf("\n");
  printf("Aptidao do Pokemon (%d) a lutar: [Sim ou Nao]  %s\n", ncadastro, aptidao[ncadastro]);
  break;

  case 0:
  fmenu();
  break;

  default:
      printf("\n");
      printf("\n");
  printf("Opcao invalida, tente novamente!\n");
  printf("\n");
  printf("\n");
  oqc();
}
}




void editar(){
printf("\n");
	printf("\n");
	printf("EDITAR DADOS DO POKEMON\n");
	printf("\n");
	printf("\n");
	do {
		printf("Digite o numero do Pokemon que voce deseja editar [De 1 a 151]:  ");
		scanf("%d", &ncadastro);

		system("cls");


		printf("\n");
		printf("\n");

	} while (ncadastro < 1 || ncadastro > 151);

    do{
    printf("\n");
    printf("\n");
    print_pokemon(ncadastro);
    printf("\n");
    printf("\n");
    printf("Pokemon (%d), deseja continuar?  \n", ncadastro);
    printf("\n");

    printf("\n");
    printf("(1) Sim\n");
    printf("(2) Nao\n");
    printf("\n");
    printf("\n");
    printf("Digite sua escolha:  ");
    scanf("%d", &continuar);
    system("cls");
    }while(continuar!=1&&continuar!=2);
    system("cls");
    printf("\n");
    printf("\n");
    if(continuar==2){
      editar();
    } else if(continuar==1){




  oqe();


      printf("\n");
      printf("\n");
      printf("(0) Menu\n");
      printf("(1) Sair");
      printf("(2) Editar novamente\n");
      printf("\n");
      printf("\n");


      printf("Digite a opcao desejada: ");
      scanf("%d", &fim);
      switch (fim) {
      case 0:
        system("cls");
        fmenu();
        break;

      case 1:
          system("pause");
        exit(0);
        break;

      case 2:
          system("cls");
        editar();
        break;

      default:
        printf("\n");
        printf("\n");
        printf("Opcao invalida, tente novamente!\n");
        printf("\n");
        printf("\n");
        system("cls");

      }
    }

}


void oqe(){

    printf("\n");
    printf("\n");
  printf("O que voce deseja editar?\n");
  printf("\n");
  printf("\n");
  printf("(1) Nome\n");
  printf("(2) Tipo\n");
  printf("(3) Poder\n");
  printf("(4) Aptidao para batalha\n");
  printf("\n");
  printf("(0) Voltar ao Pokemenu\n");
  printf("\n");
  printf("\n");
  printf("Digite a opcao desejada: ");
  scanf("%d", &cadastro);

  system("cls");
  printf("\n");

  switch (cadastro){
  case 1:

  if(cadn[ncadastro]==1){

    do{
    printf("\n");
    printf("\n");
    printf("Nome do Pokemon (%d): %s\n", ncadastro, nome[ncadastro]);
    printf("\n");
    printf("\n");
    printf("Deseja realmente alterar?\n");
    printf("\n");
    printf("\n");
    printf("(1) Sim\n");
    printf("(2) Nao\n");
    printf("\n");
    printf("\n");
    printf("Digite sua escolha:  ");
    scanf("%d", &continuar);
    system("cls");
    }while(continuar!=1&&continuar!=2);
    system("cls");
    printf("\n");
    printf("\n");
    if(continuar==2){
      system("pause");
      system("cls");
      editar();
    } else if(continuar==1){


      printf("\n");
      printf("\n");
      print_pokemon(ncadastro);
      printf("\n");
      printf("\n");
      printf("\n");
      printf("Digite o novo nome do Pokemon: ");
      scanf("%s", nome[ncadastro]);
      printf("\n");
      printf("\n");
      printf("\n");
      printf("O nome do Pokemon (%d): %s\n", ncadastro, nome[ncadastro]);



  }
  }  else{

  printf("\n");
  printf("\n");
  printf("Pokemon nao cadastrado, voce precisa primeiro cadastra-lo!\n");
  printf("\n");
  printf("\n");
  printf("(1) Cadastrar\n");
  printf("(2) Menu\n");
  printf("\n");
  printf("(0) Sair\n");
  printf("\n");
  printf("\n");
  printf("Digite a opcao desejada: ");
  scanf("%d", &ok);
  system("cls");


  switch(ok){
  case 1:

      cadastrar();


      break;

  case 2:

    fmenu();

    break;

  case 0:
system("pause");
    exit(0);

    break;

  default:

    printf("\n");
    printf("\n");
    printf("Opcao invalida, tente novamente!\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    editar();
    break;

  }
  }

  break;



  case 2:
  printf("\n");
  printf("\n");
  print_pokemon(ncadastro);
  printf("\n");
  printf("\n");
  printf("\n");
  printf("Digite o novo tipo do Pokemon: ");
  scanf("%s", tipo[ncadastro]);
  printf("\n");
  printf("\n");
  printf("\n");
  printf("O Pokémon (%d) e do tipo: %s\n", ncadastro, tipo[ncadastro]);
  break;

  case 3:
  printf("\n");
  printf("\n");
  print_pokemon(ncadastro);
  printf("\n");
  printf("\n");
  printf("\n");
  printf("Digite o novo poder do Pokemon: ");
  scanf("%s", poder[ncadastro]);
  printf("\n");
  printf("\n");
  printf("\n");
  printf("O Pokemon (%d) tem o seguinte poder: %s\n", ncadastro,
  poder[ncadastro]);
  break;

  case 4:
  printf("\n");
  printf("\n");
  print_pokemon(ncadastro);
  printf("\n");
  printf("\n");
  printf("\n");
  printf("O Pokemon esta apto a lutar? [Sim ou Nao]  ");
  scanf("%s", aptidao[ncadastro]);
  printf("\n");
  printf("\n");
  printf("\n");
  printf("Aptidao do Pokemon (%d) a lutar: %s\n", ncadastro, aptidao[ncadastro]);
  break;

  case 0:
  fmenu();
  break;

  default:
      printf("\n");
      printf("\n");
  printf("Opcao invalida, tente novamente!\n");
  printf("\n");
  printf("\n");
  oqe();

    }



}
