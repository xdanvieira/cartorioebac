#include <stdio.h> //biblioteca de comunicaÃ§Ã£o com o usuÃ¡rio
#include <stdlib.h> //biblioteca de alocaÃ§Ã£o de espaÃ§o em memÃ³ria
#include <locale.h> //biblioteca de alocaÃ§Ãµes de texto por regiÃ£o
#include <string.h> //biblioteca responsÃ¡vel por cuidar das string
		
int registro()      // Funçaõ responsavel por cadasttrar os usuários
{

// Inicio para criação das variáveis/string

	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
// final para criação das variáveis/string



	printf("Digite o CPF a ser cadastrado: ");         // coletando informações do usuario
	scanf("%s", cpf);         //%s se refere a string  
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" escreve
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);	
	
    system("pause");

}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	char cpf[40];
	char conteudo[100];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
  	
	FILE *file;
	file = fopen(cpf,"r");
  	
	  if(file == NULL)
	  {
	  	printf("Não foi possivel abrir o arquivo, nãoo localizado!.\n");
	  }
	  
	  
	  while(fgets(conteudo, 100, file) != NULL)
	  {
	  	printf("\nEssas são as informações do usuário: ");
		  printf("%s", conteudo);
		  printf("\n\n");
	  }
	  
	  system ("pause");
}


int deletar()
{
	char cpf[40];
	
	printf("Digite o cpf a ser deletado");
	scanf("%s",cpf);

	remove(cpf);
	
	FILE*file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!.\n");
		system("pause");
	}
	
}




int main()
    {
	int opcao=0; //definindo as variavéis
	int laco=1;
	
	
	for(laco=1;laco=1;)
	{
		system("cls");
	
	
    	setlocale(LC_ALL, "Portuguese"); //defindo a linguagem
	
	    printf("### Cartório EBAC ###\n\n"); //inicio do menu
	    printf("Escolha a opção desejada do menu\n\n");
    	printf("\t1 - registrar nomes\n");
	    printf("\t2 - consultar nomes\n");
	    printf("\t3 - deletar nomes\n\n"); 
	    printf("\t4 - Sair  do sistema\n\n");
	    

    	scanf("%d", &opcao); //inicio da seleção
	
    	system("cls");         // responsavel por limpar a tela
    	
    	
    	switch(opcao)            //  inicio da seleção do menu
		{
			case 1: 
			registro();        // chamada de funções
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
	        deletar();
	        break;
	        
	        case 4: 
	        printf("obrigado por utilizar o sistema\n");
	        return 0;
			break;  
	        
	        
	        
	        default:
	        printf("Essa opção não está disponivel");
			system("pause");
			break;
	        	
		} 	
   }
}
