#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

  int registro() 
 {
	setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem

	//inicio criação de variáveis/string
	char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //final da criação de variáveis/string
    
    printf("Digite o CPF a ser cadastrado: ");//coletando informção do usuário
    scanf("%s",cpf); // %s refere-se a string
    
    strcpy(arquivo, cpf); // Responsável por copiar os valores das string
    
    FILE *file; //cria o arquivo
    file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
    fprintf(file,cpf); //savo o valor da variavel
    fclose(file);// fecha o arquivo
    
    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);
    
    printf("Digite o nome a ser cadastrado: "); // Cadastrando nome
    scanf("%s",nome);
    
    file = fopen(arquivo, "a");
    fprintf(file,nome);
    fclose(file);
     
	file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);
    
    printf("Digite o sobrenome a ser cadastrado: "); // Cadastrando sobrenome
    scanf("%s",sobrenome);
    
    file = fopen(arquivo, "a");
    fprintf(file,sobrenome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);
    
    printf("Digite o cargo a ser cadastrado: "); // Cadastrando cargo
    scanf("%s",cargo);
    
	file = fopen(arquivo, "a");
    fprintf(file,cargo);
    fclose(file);
    
    system("pause");
    system("cls");
 }
 
  int consulta()
 {
    setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
   
    char cpf[40];
    char conteudo[200];
    
    printf("Digite o CPF a ser consultado: "); // Definindo usuário a ser consultado
    scanf("%s",cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
    
    if (file == NULL)
    { 
       printf("Não foi possivel abrir o arquivo, não localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) !=NULL)
	  {
		printf("\nEssas são as informações do usuário:\n ");
		printf("%s", conteudo);
		printf("\n\n");
	  }   
     fclose(file);
     system("pause");
     system("cls");
       
 }

  int deletar()
 {
	setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
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
	} 
	 else 
	  {
		printf("Erro ao deletar o CPF.\n");
	  }

      system("pause");
      system("cls");
	  return 0;

 }
   int main()
 {  
    int opcao=0; //Definindo variáveis
    int laco=1;
    char senhadigitada[10]="a";
    int comparacao;
    
	 setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
    
	printf("###Cartório da EBAC###\n\n"); //Inicio do menu
	printf("Login de administrador!\n\nDigite a sua senha:");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
     if(comparacao == 0)
   { 
       system("cls");
       for(laco=1;laco=1;)
      {  
	     setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem       
	  
	     printf("###Cartório da EBAC###\n\n"); //Inicio do menu
	     printf("Escolha a opção desejeda no menu:\n\n");
	     printf("\t1 - Registrar nomes\n");
	     printf("\t2 - Consultar nomes\n");
	     printf("\t3 - Deletar nomes\n\n");
	     printf("\t4 - Sair do sistema.\n\n");
	     printf("Opção: "); //Fim do menu
    
       scanf("%d", &opcao); //armazenando a escolha do usuário
    
       system("cls");//responsável por limpar a tela
       
       switch(opcao)
         {
    	   case 1:
	    registro(); //chamada de funções
            break;
	    
           case 2:
	     consulta();
	     break;
	   
	   case 3:
	     deletar();
	     break;
		
           case 4:
	     printf("Obrigado por utilizar o sistema!\n"); //encerramento do Sistema
	     return 0;
	     break;
		
           default:
	     printf("Essa opção não está disponivel!\n");
	     system("pause");
	      break;	
     	 } //fim da seleção
       }
    }
   else
       printf("Senha incorreta!");//encerramento do Sistema
 }   
   
