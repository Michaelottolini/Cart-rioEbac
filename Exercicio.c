#include <stdio.h>  // biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de alocações de espaço em memória
#include <locale.h> // biblioteca de alocações de texto por região 
#include <string.h> // biblioteca responsável por cuidar das strings

int registro() // Função responsável por cadastrar os usuários no sistema
{
	// incio criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo [40];
	// final da criação de variáveis/string
	
	printf("Você escoheu o Registro de Nomes!\n\n\n");//apresentação da função
	
	printf("Digite o CPF a ser Cadastrado: \n");//Responsável por copiar os valores das string
	scanf("%s", cpf); //referece a armazenamento de string 
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores de string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // abrindo e criando o arquivo
	fprintf(file,cpf); //salvo o valor da variável
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
	
	printf("Você escolheu Consultar Nomes!\n");

	
	char cpf[40];
	char conteudo[200];
	
	printf("\nDigite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf ("Não foi possível abrir o arquivo, CPF não localizado! /n");
	}
	
	while(fgets(conteudo, 200, file) != NULL);
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	system("pause");
	
}
int deletar()
{
	char cpf[40];
		
	printf("Você escolheu Deletar Nomes!\n");
	printf("\nDigite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if (file == NULL)
	{
		printf("Usuário Inexistente!\n");
		system ("pause");
	}

}

int main()
	{
		int opcao=0; // Definindo variáveis
		int laco=1;
		
		for(laco=1;laco=1;)
		{
			setlocale(LC_ALL, "portuguese"); //Definindo a linguagem
			
			system("cls");
			
 			printf("\t\t\t\t\t####Cartório da EBAC####\n\n"); //inicio do menu
    		printf("Escolha a opção desejada do menu:\n\n");
    		printf("\t 1 - Registrar nomes\n");
    		printf("\t 2 - Consultar nomes\n");
    		printf("\t 3 - Deletar nomes\n\n");
    		printf("Opção: "); //fim do menu
    		
    		scanf("%d", &opcao); //armazenando a escolha do usuário
    		
    		system("cls"); // responsável por limpar a tela
    		
    		switch(opcao)
    		{
			
    		case 1:
    			registro();	//chamada de funções
    			break;
    		
			case 2:
				consulta();
				break;
				
			case 3:
				deletar();
				break;
				
			default:
				printf("Essa opção não está disponivel!\n");
				system("pause");
				break;			
    		}
			
		}

	}


