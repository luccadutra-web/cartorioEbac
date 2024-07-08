#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int registro(){
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];

    printf("Digite o CPF a ser cadastrado: ");
    scanf("%s", cpf);

    strcpy(arquivo, cpf); //respons�vel por copiar os valores das strings

    FILE *file;
    file = fopen(arquivo, "w");
    fprintf(file, cpf);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    printf("Digite o nome a ser cadastrado: ");
    scanf("%s", nome);

    file = fopen(arquivo, "a");
    fprintf(file, nome);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file, " ");
    fclose(file);

    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome);

    file = fopen(arquivo, "a");
    fprintf(file, sobrenome);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s", cargo);

    file = fopen(arquivo, "a");
    fprintf(file, cargo);
    fclose(file);

    system("pause");
    system("cls");
}

int consulta(){
    setlocale(LC_ALL, "Portuguese");

    char cpf[40];
    char conteudo[200];

    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf);

    FILE *file;
    file = fopen (cpf, "r");
    
    if(file == NULL){
        printf("O arquivo não foi localizado\n");
    }

    while(fgets(conteudo, 200, file) != NULL){
        printf("\nEssas são as informações do usuário: ");
        printf("%s", conteudo);
        printf("\n\n");
    }

    system("pause");
    system("cls");
}

int deletar(){
    char cpf[40];

    printf("Digite o CPF do usuário a ser deletado: ");
    scanf("%s", cpf);

    remove(cpf);

    FILE *file;
    file = fopen(cpf, "r");

    if(file == NULL){
        printf("O usuário não se encontra no sistema!\n");
        system("pause");
        system("cls");
    }

    system("cls");

}

int main(){

    int option=0;
    int laco=1;

    for(laco=1;laco=1;){
        system("cls");

        setlocale(LC_ALL, "Portuguese");

        //MENU DE ESCOLHA
        printf("### Cartório da EBAC ###\n\n");
        printf("Escolha a opção desejada do menu: \n\n");

        printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n");
        printf("\t4 - Sair do sistema\n\n");

        printf("Opção: ");

        //ESCOLHA DO USU�RIO
        scanf("%d", &option);

        //LIMPAR QUALQUER IMPRESS�O ANTERIOR
        system("cls");

        //SELE��O

        switch(option){

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
            printf("Obrigado por utilizar o sistema!\n");
            return 0;
            break;


            default:
            printf("Escolha uma opção disponível\n");
            system("pause");
            system("cls");
            break;
        }

    }

}