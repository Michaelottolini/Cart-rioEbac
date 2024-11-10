#include <stdio.h>  // biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // biblioteca de aloca��es de espa�o em mem�ria
#include <locale.h> // biblioteca de aloca��es de texto por regi�o 
#include <string.h> // biblioteca respons�vel por cuidar das strings

int registro() // Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	// incio cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo [40];
	// final da cria��o de vari�veis/string
	
	printf("Voc� escoheu o Registro de Nomes!\n\n\n");//apresenta��o da fun��o
	
	printf("Digite o CPF a ser Cadastrado: \n");//Respons�vel por copiar os valores das string
	scanf("%s", cpf); //referece a armazenamento de string 
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores de string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // abrindo e criando o arquivo
	fprintf(file,cpf); //salvo o valor da vari�vel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: \n");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadadastrado: \n ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: \n");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
}
int consulta()
{
	setlocale(LC_ALL, "portuguese"); //Definindo a linguagem
	
	printf("Voc� escolheu Consultar Nomes!\n");

	
	char cpf[40];
	char conteudo[200];
	
	printf("\nDigite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf ("N�o foi poss�vel abrir o arquivo, CPF n�o localizado! /n");
	}
	
	while(fgets(conteudo, 200, file) != NULL);
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	system("pause");
	
}
int deletar()
{
	char cpf[40];
		
	printf("Voc� escolheu Deletar Nomes!\n");
	printf("\nDigite o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if (file == NULL)
	{
		printf("Usu�rio Inexistente!\n");
		system ("pause");
	}

}

int main()
	{
		int opcao=0; // Definindo vari�veis
		int laco=1;
		
		for(laco=1;laco=1;)
		{
			setlocale(LC_ALL, "portuguese"); //Definindo a linguagem
			
			system("cls");
			
 			printf("\t\t\t\t\t####Cart�rio da EBAC####\n\n"); //inicio do menu
    		printf("Escolha a op��o desejada do menu:\n\n");
    		printf("\t 1 - Registrar nomes\n");
    		printf("\t 2 - Consultar nomes\n");
    		printf("\t 3 - Deletar nomes\n\n");
    		printf("Op��o: "); //fim do menu
    		
    		scanf("%d", &opcao); //armazenando a escolha do usu�rio
    		
    		system("cls"); // respons�vel por limpar a tela
    		
    		switch(opcao)
    		{
			
    		case 1:
    			registro();	//chamada de fun��es
    			break;
    		
			case 2:
				consulta();
				break;
				
			case 3:
				deletar();
				break;
				
			default:
				printf("Essa op��o n�o est� disponivel!\n");
				system("pause");
				break;			
    		}
			
		}

	}


