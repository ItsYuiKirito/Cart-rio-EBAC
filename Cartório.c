#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string


int registro()
{
	char arquivo[40];
    char cpf[40];
    char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e "w" � para criar um novo arquivo
	fprintf(file, "\nCPF: ");
	fprintf(file, cpf); //salvo o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); // "a" para atualizar informa��o 
	fprintf(file, ",\nNOME: ");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a"); 
	fprintf(file, ",\nSOBRENOME: ");
	fclose(file);
	
	printf("Digite o seu sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a"); 
	fprintf(file, ",\nCARGO: ");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fprintf(file, ".\n\n");
	fclose(file);
	
	system("pause");
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
    char cpf[40];
    char conteudo[200];
    
    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf);
    
    FILE *file;
    file = fopen(cpf, "r"); // "r" � pra ler o arquivo e buscar o que ta salvo
    
    if(file == NULL)
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!\n");
	}
	
	printf("\nEssas s�o as informa��es do usu�rio: ");
	
	while(fgets(conteudo, 200, file) != NULL) //fgets busca no arquivo, enquanto tiver no arquivo, vai rodar 200x at� trazer tudo e para quando for nulo
	{
		printf("%s", conteudo);
	}
	
	fclose(file);
	system("pause");
			
}

int deletar()
{
    char cpf[40];
    
    printf("Digite o CPF do usu�rio a ser deletado: ");
    scanf("%s", cpf);
    
    FILE *file;
    file = fopen(cpf, "r");
    
    if(file)
	{
		fclose(file);
		remove(cpf);
		printf("\n\tCPF deletado com sucesso!\n\n");
		system("pause");
 	}
	else
	{
		printf("\nO usu�rio n�o est� cadastrado no sistema!\n\n");
		system("pause");
	}
	
	fclose(file);
	
}

int main()
{
    int opcao=0; //Definindo as vari�veis
	int laco=1; //Definindo vari�vel la�o
	
	for(laco=1;laco=1;) //Repeti��o que faz o programa voltar aqui igual quando p�e a senha errada no cell e aparece pra por de novo
	{
	
	    system("cls"); //Apagar o que estava escrito anteriormente ap�s a escolha de alguma op��o
	
    	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
    	printf("### Cart�rio da EBAC ###\n\n"); //Inicio do men�
    	printf("Escolha a op��o desejada do menu:\n\n");
    	printf("\t1 - Registrar nomes\n");
    	printf("\t2 - Consultar nomes\n");
    	printf("\t3 - Deletar nomes\n");
    	printf("\t4 - Sair do sistema\n\n");
    	printf("Op��o: "); //Fim do men�
	
    	scanf("%d", &opcao); //Armazenando a escolha dp usu�rio
         	
    	system("cls");
    	
    	switch(opcao) //Usar no lugar do IF para diminuir o c�digo
		{
			case 1:
			registro();
	    	break;
	    	
	    	case 2:
	    	consulta();
	    	break;
	    	
	    	case 3:
	    	deletar();
    		break;
    		
    		case 4:
    		printf("Obrigado por utilizar o sistema!");
    		return 0;
    		break;
    		
    		default:
    		printf("Essa op��o n�o est� disponivel!\n");
    		system("pause");
    		break;
    		
    	}
			  	
    }
	
}
