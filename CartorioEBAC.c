#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocaçoes de texto por região
#include <string.h> //biblioteca responsavel por cuidar das strings

int registrar() //função responsavel por cadastrar 
{
        //inicio criação de variaveis/string
	    char arquivo[40];
		char cpf[40];
	    char nome[40];
	    char sobrenome[40];
	    char cargo[40];
	    //final criação variavel
		
		printf("Digite o CPF a ser cadastrado: "); // coletando informação
		scanf("%s", cpf);//%s refere-se a string
		
		strcpy(arquivo, cpf); //responsavel por copiar o valor das strings
		
		FILE *file; //cria o arquivo
		file = fopen(arquivo, "w"); //abre o arquivo e o "w" significa escrever
		fprintf(file, cpf);//salvo o valor da variavel
		fclose(file);//fechar o arquivo
		
		file = fopen(arquivo, "a"); //abre o arquivo e o "a" acessa o arquivo
		fprintf(file,",");
		fclose(file);
		
		printf("Digite o nome a ser cadastrado: "); //Nome
		scanf("%s", nome);
        file = fopen(arquivo, "a");
		fprintf(file,nome);
		fclose(file);
    		file = fopen(arquivo, "a"); //virgula
    		fprintf(file,",");
    		fclose(file);
		
		printf("Digite o sobrenome a ser cadastrado: "); // Sobrenome
		scanf("%s", sobrenome);
		file = fopen(arquivo, "a");
		fprintf(file,sobrenome);
		fclose(file);
			file = fopen(arquivo, "a");//virgula
	    	fprintf(file,",");
	    	fclose(file);
		
		printf("Digite o cargo a ser cadastrado: ");// Cargo
		scanf("%s", cargo);
		file = fopen(arquivo, "a");
		fprintf(file,cargo);
		fclose(file);

		
		system("pause");
		
}

int consultar()
{
	setlocale(LC_ALL, "Portuguese"); // Idioma usado
   
    char cpf[40];
    char conteudo[200];
    
    printf("Digite o CPF a ser consultado: "); // Consulta CPF.
    scanf("%s",cpf);
    
    FILE *file;
    file = fopen(cpf,"r");// "r" le o arquivo
    
    if(file == NULL)// compara o arquivo
{
    printf("Não foi possivel abrir o arquivo, não localizado!\n"); //CPF Não localizado.
}
    
    while (fgets(conteudo, 200, file) != NULL)
{
    	printf("\nEssas são as informações do usuário: "); //Informações para o usuário.
    	printf("%s", conteudo);
    	printf("\n\n");
		
}
	system("pause");
	fclose(file);
}

int deletar()
{
	char cpf[40];
    
	printf("Digite o CPF que o usuário deseja deletar: ");
    scanf("%s",cpf);
    
	remove(cpf);
	
	FILE *file; // Abrindo o arquivo referente ao cpf e dando o comando "r" para leitura
	file = fopen(cpf,"r");
	
	if(file == NULL) // Caso o cpf digitado não esteja no banco de dados
	  {
	  	printf(" CPF não encontrado no sistema!. \n"); //Mensagem de erro para o usuario
	  	system ("pause"); // Comandoo que pausa a tela atual	
	  }
	  
	  if(file != NULL) 
	  {
	  	printf("\n CPF deletado com sucesso \n");
	  	system("pause");
	  	fclose(file);
	  }
	 
    
    
}


int main(){
	int opcao=0; // Definindo variáveis
	
	int loop=1;
	
	for(loop=1;loop=1;)
	{
		system("cls");
		setlocale(LC_ALL, "Portuguese"); // Idioma usado
	
    	printf("### Cartório da EBAC ###\n\n"); //Inicio do Menu
    	
    	printf("Escolha a opção desejada no menu:\n\n"); 
	
    	printf("\t1 - Registrar nomes.\n");
	
      	printf("\t2 - Consultar nomes.\n");
   	
    	printf("\t3 - Deletar nomes.\n\n");	
	
    	printf("Escolha uma das opções acima: "); //fim do menu
    
    scanf("%d", &opcao); //armazenando escolha do usuario
 	
    system("cls");
    
    switch(opcao)
	{
	    	case 1:
		    registrar();
	        break;
	        
	        case 2:
	        consultar();
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
