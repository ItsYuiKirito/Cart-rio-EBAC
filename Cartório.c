#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string


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
	file = fopen(arquivo, "w"); //cria o arquivo e "w" é para criar um novo arquivo
	fprintf(file, "\nCPF: ");
	fprintf(file, cpf); //salvo o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); // "a" para atualizar informação 
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
    file = fopen(cpf, "r"); // "r" é pra ler o arquivo e buscar o que ta salvo
    
    if(file == NULL)
	{
		printf("Não foi possivel abrir o arquivo, não localizado!\n");
	}
	
	printf("\nEssas são as informações do usuário: ");
	
	while(fgets(conteudo, 200, file) != NULL) //fgets busca no arquivo, enquanto tiver no arquivo, vai rodar 200x até trazer tudo e para quando for nulo
	{
		printf("%s", conteudo);
	}
	
	fclose(file);
	system("pause");
			
}

int deletar()
{
    char cpf[40];
    
    printf("Digite o CPF do usuário a ser deletado: ");
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
		printf("\nO usuário não está cadastrado no sistema!\n\n");
		system("pause");
	}
	
	fclose(file);
	
}

int main()
{
    int opcao=0; //Definindo as variáveis
	int laco=1; //Definindo variável laço
	
	for(laco=1;laco=1;) //Repetição que faz o programa voltar aqui igual quando põe a senha errada no cell e aparece pra por de novo
	{
	
	    system("cls"); //Apagar o que estava escrito anteriormente após a escolha de alguma opção
	
    	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
    	printf("### Cartório da EBAC ###\n\n"); //Inicio do menú
    	printf("Escolha a opção desejada do menu:\n\n");
    	printf("\t1 - Registrar nomes\n");
    	printf("\t2 - Consultar nomes\n");
    	printf("\t3 - Deletar nomes\n");
    	printf("\t4 - Sair do sistema\n\n");
    	printf("Opção: "); //Fim do menú
	
    	scanf("%d", &opcao); //Armazenando a escolha dp usuário
         	
    	system("cls");
    	
    	switch(opcao) //Usar no lugar do IF para diminuir o código
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
    		printf("Essa opção não está disponivel!\n");
    		system("pause");
    		break;
    		
    	}
			  	
    }
	
}
