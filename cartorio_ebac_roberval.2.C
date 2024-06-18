#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de espaço em memória
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
    scanf("%s",cpf);
    
    strcpy(arquivo, cpf); // Responsável por copiar os valores das string
    
    FILE *file; //cria o arquivo
    file = fopen(arquivo, "w");
    fprintf(file,cpf); //savo o valor da variavel
    fclose(file);// fecha o arquivo
    
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
    setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
   
    char cpf[40];
    char conteudo[200];
    
    printf("Digite o CPF a ser consultado: ");
    scanf("%s",cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
    
    if (file == NULL)
    { 
       printf("Não foi possivel abrir o arquivo, não localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) !=NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
        system("pause");
        fclose(file);
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado:");
	scanf("%s", cpf);
	
	
	FILE *file;
	file = fopen(cpf, "r");

    if(file==NULL)
	{
		printf("O usuário não se encontra no sistema!\n ");
		system("pause");
		return 0;
	}   
	fclose(file);
	
	if (remove(cpf) == 0) {
		printf("CPF deletado com sucesso!\n");
	} else {
		printf("Erro ao deletar o CPF.\n");
	}

      system("pause");
	  return 0;

}
int main()
{  
    int opcao=0; //Definindo variáveis
    int laco=1;
    
    for(laco=1;laco=1;)
    {
       system("cls");
       
	   setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	 
	   printf("###Cartório da EBAC###\n\n"); //Inicio do menu
	   printf("Escolha a opção desejeda no menu:\n\n");
	   printf("\t1 - Registrar nomes\n");
	   printf("\t2 - Consultar nomes\n");
	   printf("\t3 - Deletar nomes\n\n");
	   printf("Opção: "); //Fim do menu
    
       scanf("%d", &opcao); //armazenando a escolha do usuário
    
       system("cls");
       
       switch(opcao)
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
		
		default:
		printf("Essa opção não está disponivel!\n");
	    system("pause");
		break;	
     	}
     
    }
}   
