//Bibliotecas usadas no programa.
#include <stdio.h> //Entrada e saída padrão.
#include <stdlib.h> //Emula o prompt do SO correspondente.
#include <string.h> //Manipular strings

typedef struct {//Estrutura dos dados pessoais.

    char nome[40];
    char tel[15];
    char email[40];
    char status;
    int tipo;

} CADEIRAS;

typedef struct { //Estrutura dos dados da peça.

	CADEIRAS cadeira[22][30];
	char dataPeca[11];
	char nomePeca[60];
	char horarioPeca[6];
	float valorArrecadado;
	
} TEATRO;

void menu() { //Menu inicial do programa.

    printf("MENU PRINCIPAL \n\n");
    printf("1 - Visualizar mapa do teatro\n");
    printf("2 - Comprar cadeira\n");
    printf("3 - Reservar cadeira\n");
    printf("4 - Consultar uma determinada cadeira da sala\n");
    printf("5 - Total arrecadado\n");
    printf("6 - Cancelar todas as reservas\n");
    printf("7 - Desocupar cadeira especifica\n");
    printf("8 - Sair do aplicativo\n");
    printf("Digite o numero de uma das opcoes acima: ");
}

void letranumero(int numero) { // Transforma o numero em uma letra de fileira.
    
    switch (numero) { //Análise do número para a troca em letra.
	
    case 0:
        printf("A");
        break;
    case 1:
        printf("B");
        break;
    case 2:
        printf("C");
        break;
    case 3:
        printf("D");
        break;
    case 4:
        printf("E");
        break;
    case 5:
        printf("F");
        break;
    case 6:
        printf("G");
        break;
    case 7:
        printf("H");
        break;
    case 8:
        printf("I");
        break;
    case 9:
        printf("J");
        break;
    case 10:
        printf("K");
        break;
    case 11:
        printf("L");
        break;
    case 12:
        printf("M");
        break;
    case 13:
        printf("N");
        break;
    case 14:
        printf("O");
        break;
    case 15:
        printf("P");
        break;
    case 16:
        printf("Q");
        break;
    case 17:
        printf("R");
        break;
    case 18:
        printf("S");
        break;
    case 19:
        printf("T");
        break;
    case 20:
        printf("U");
        break;
    case 21:
        printf("V");
        break;
    case 22:
        printf("W");
        break;
    case 23:
        printf("X");
        break;
    case 24:
        printf("Y");
        break;
    case 25:
        printf("Z");
        break;
    }
}

void numeroletra(char letra, int *n) { // Transforma a letra de uma fileira digitada em um numero.
   
    switch (letra) { //Análise da letra para a troca em número.
    
    case 'A':
        *n = 0;
        break;
    case 'B':
        *n = 1;
        break;
    case 'C':
        *n = 2;
        break;
    case 'D':
        *n = 3;
        break;
    case 'E':
        *n = 4;
        break;
    case 'F':
        *n = 5;
        break;
    case 'G':
        *n = 6;
        break;
    case 'H':
        *n = 7;
        break;
    case 'I':
        *n = 8;
        break;
    case 'J':
        *n = 9;
        break;
    case 'K':
        *n = 10;
        break;
    case 'L':
        *n = 11;
        break;
    case 'M':
        *n = 12;
        break;
    case 'N':
        *n = 13;
        break;
    case 'O':
        *n = 14;
        break;
    case 'P':
        *n = 15;
        break;
    case 'Q':
        *n = 16;
        break;
    case 'R':
        *n = 17;
        break;
    case 'S':
        *n = 18;
        break;
    case 'T':
        *n = 19;
        break;
    case 'U':
        *n = 20;
        break;
    case 'V':
        *n = 21;
        break;
    case 'W':
        *n = 22;
        break;
    case 'X':
        *n = 23;
        break;
    case 'Y':
        *n = 24;
        break;
    case 'Z':
        *n = 25;
        break;
    }
}

void zerar(TEATRO *t) { //Função para desocupar todo o teatro.

    int i, j;
    for (i = 0; i < 22; i++) //Ciclo de varredura da matriz do teatro.
        for (j = 0; j < 30; j++)     
           t->cadeira[i][j].status ='L';
           
}

void imprimirDados(int i, int j, TEATRO t) { //Função para imprimir os dados do cliente e do tipo de entrada dele.

    printf("%s", t.cadeira[i][j].nome);
    printf("Telefone: %s", t.cadeira[i][j].tel);
    printf("Email: %s", t.cadeira[i][j].email);
    
    if (t.cadeira[i][j].tipo == 1) {
    	
        printf("Meia entrada\n");
    }
    else if (t.cadeira[i][j].tipo == 2) {
    
        printf("Entrada inteira\n");
    }
}

void criar_arq (TEATRO t) { // Função para criar o aquivo do programa - sem a struct.

   FILE *fp;  
 
   fp = fopen ("Teatro.dat", "wb"); //Arquivo para escrita binaria.
   if (fp == NULL) {  
        printf ("Erro ao abrir o arquivo.\n");
              
      return;  
   }   
   else {  
        printf ("Arquivo Binario criado com sucesso.\n");  
          fwrite(&t, sizeof(TEATRO), 1, fp); 
    }         
     fclose (fp);
       
}//Função reponsavel por exibir o conteudo do arquivo Binario.dat

void Carregar_Arq(TEATRO *t) { //Função reponsavel por exibir o conteudo do arquivo Binario.dat

    FILE *fp;
    
    fp = fopen ("Teatro.dat", "rb"); 
        if (fp == NULL) {  
        
		  zerar(&(*t));
          printf("Digite o nome do espetaculo: ");
          fgets(t->nomePeca, 60, stdin);
          printf("Digite a data do espetaculo: ");
          fgets(t->dataPeca, 11, stdin);
          printf("Digite o horario do espetaculo: ");
          fgets(t->horarioPeca, 6, stdin);
          printf("\n");

		return;
    }  
        else {
        	
          fread(&(*t),sizeof(TEATRO),1,fp);
          fclose(fp);
    }  
}

void Imprimir_infosPeca (TEATRO *t) { //Função para imprimir as informações inseridas sobre a peça.
	
	printf("\n");
	printf("O espetaculo sera: %s", t->nomePeca);
	printf("Data do evento: %s", t->dataPeca);
	printf("Horario do evento: %s\n", t->horarioPeca);
	printf("\n");
	
	return;
}

int main() { //Função principal.

    TEATRO t;
    int i, j, cont = 0, contr = 0;
    int op;
    char aux;

    Carregar_Arq(&t); //Chamando da função para carregar o arquivo.
       
    printf("  ******* T E A T R O ******* \n");
    
    Imprimir_infosPeca (&t); //Chamada da função que insere as informações sobre o evento.

    do //Ciclo responsável pela operação do menu.
    {
        menu();
        scanf("%d", &op);
        printf("\n");

        switch (op) { //Análise do dígito de operação do menu.
        
        //System("clear") funciona no Linux, no Windows usa-se "CLS". 
		//System("clear") usado apenas nas opções as quais não dependem do mapa do teatro para a experiência completa do programa.
        
        case 1: //Primeira opção: Exibir planta do teatro.
            system("clear");
            
            for (i = 0; i < 22; i++)
            {
                for (j = 0; j < 15; j++)
                {
                    letranumero(i);
                    printf("%d-", j + 1);
                    printf("%c ", t.cadeira[i][j].status);
                }

                printf("       ");

                for (j = 15; j < 30; j++)
                {
                    letranumero(i);
                    printf("%d-", j + 1);
                    printf("%c ", t.cadeira[i][j].status);
                }
                printf("\n");
            }
            break;

        case 2: //Segunda opção, comprar cadeira.
        
            printf("Digite fileira da cadeira que deseja comprar: ");
            scanf(" %c", &aux);
            numeroletra(aux, &i);
            printf("Digite coluna da cadeira que deseja comprar: ");
            scanf("%d", &j);
            getchar();
            j--;
            
            if (t.cadeira[i][j].status == 'L') {
            
                printf("Digite o nome do cliente: ");
                fgets(t.cadeira[i][j].nome, 40, stdin);
                printf("Digite o telefone do cliente: ");
                fgets(t.cadeira[i][j].tel, 15, stdin);
                printf("Digite o email do cliente: ");
                fgets(t.cadeira[i][j].email, 40, stdin);
                printf("Digite 1 pra Meia e 2 para Inteira: ");
                scanf("%d", &t.cadeira[i][j].tipo);

                if (t.cadeira[i][j].tipo == 1) { //Contador de entrada completa e meia entrada.
				
                    cont++;
                }
                else {

                    cont+=2;
                }

                if (t.cadeira[i][j].tipo != 1 && t.cadeira[i][j].tipo != 2) {
                	
                    do {
					
                        printf("Tipo invalido, digite 1 pra Meia e 2 para Inteira: ");
                        scanf("%d", &t.cadeira[i][j].tipo);
                    } 
					while (t.cadeira[i][j].tipo != 1 && t.cadeira[i][j].tipo != 2);
                }

                t.cadeira[i][j].status = 'O';
                printf("\nCadeira comprada com sucesso!\n");
            }
            else
            {
                printf("\nCadeira ja esta ocupada!\n");
            }
            break;

        case 3: //Terceira opção, reservar cadeira.
        
            printf("Digite fileira da cadeira que deseja reservar: ");
            scanf(" %c", &aux);
            numeroletra(aux, &i);
            printf("Digite coluna da cadeira que deseja reservar: ");
            scanf("%d", &j);
            getchar();
            j--;
            
            if (t.cadeira[i][j].status == 'L') {
			
                printf("Digite o nome do cliente: ");
                fgets(t.cadeira[i][j].nome, 40, stdin);
                printf("Digite o telefone do cliente: ");
                fgets(t.cadeira[i][j].tel, 15, stdin);
                printf("Digite o email do cliente: ");
                fgets(t.cadeira[i][j].email, 40, stdin);
                printf("Digite 1 pra Meia e 2 para Inteira: ");
                scanf("%d", &t.cadeira[i][j].tipo);

                if (t.cadeira[i][j].tipo == 1) { //Contador de entrada completa e meia entrada.
			
                    contr++;
                }
                else {
				
                    contr+=2;
                }

                if (t.cadeira[i][j].tipo != 1 && t.cadeira[i][j].tipo != 2) {
                	
                    do {
                        printf("Tipo invalido, digite 1 pra Meia e 2 para Inteira: ");
                        scanf("%d", &t.cadeira[i][j].tipo);
                    } 
					while (t.cadeira[i][j].tipo != 1 && t.cadeira[i][j].tipo != 2);
                }

                t.cadeira[i][j].status = 'R';
                printf("\nCadeira reservada com sucesso!\n");
            }
            else {
                printf("\nCadeira ja esta ocupada!\n");
            }
            break;

        case 4: //Quarta opção, consultar disponibilidade de uma cadeira específica.

            printf("Digite fileira da cadeira que deseja consultar: ");
            scanf(" %c", &aux);
            numeroletra(aux, &i);
            printf("Digite coluna da cadeira que deseja consultar:  ");
            scanf("%d", &j);
            getchar();
            j--;

            if (t.cadeira[i][j].status == 'L') {
            	
                printf("A cadeira esta livre\n");
            }
            else if (t.cadeira[i][j].status == 'O') {
            	
                printf("\nA cadeira esta ocupada por: ");
                imprimirDados(i, j, t);
            }
            else if (t.cadeira[i][j].status == 'R') {
            	
                printf("A cadeira esta reservada por: ");
                imprimirDados(i, j, t);
            }
            break;

        case 5: //Quinta opção, arrecadação e valores de reservas.
        
            system("clear");
            printf("Total reservado: R$ %d,00 \n", (contr * 15));
            printf("Total arrecadado: R$ %d,00 \n", (cont * 15));            
            break;

        case 6: //Sexta opção, cancelamento de todas as reservas.
        
            system("clear");
            for (i = 0; i < 22; i++)
            for (j = 0; j < 30; j++)
            if(t.cadeira[i][j].status=='R') {
                t.cadeira[i][j].status ='L';
            }
            printf("\nTODAS AS RESERVAS FORAM CANCELADAS\n");
            break;

        case 7: //Sétima opção, cancelamento de uma cadeira específica.
        
            printf("Digite fileira da cadeira que deseja desocupar: ");
            scanf(" %c", &aux);
            numeroletra(aux, &i);
            printf("Digite coluna da cadeira que deseja desocupar:  ");
            scanf("%d", &j);
            getchar();
            j--;
            t.cadeira[i][j].status ='L';
            printf("\nCadeira desocupada com sucesso!\n");
            break;

        case 8: //Oitava opção, finalização do sistema.
        
            system("clear");
            printf("OBRIGADO POR UTILIZAR O NOSSO SISTEMA!\n");
            criar_arq(t);
            break;

        default: //Controle de opções caso o usuário digite valores diferentes do intervado de [1-8]
            printf("Digite uma opcao valida:\n");
            break;

        }

        printf("\n");
    } 
	while (op != 8); //Ciclo para repetir o menu até a finalização dele com a operação (8).

    return 0;
}
