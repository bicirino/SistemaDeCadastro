//Projeto - Mini Sistema de cadastro - Código// 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

// usar F6 para executar o programa

enum TipoUsuario
{
    ADMIN,
    COMUM
};

// Estrutura para armazenar informações do usuário

typedef struct
{
    char nome[50];
    char email[50];
    char senha[20];
    enum TipoUsuario tipo;
} Usuario;

Usuario usuarios[100];

// inicialização de variáveis globais
int qntdUsuarios = 0;   // quantidade de usuários cadastrados
int usuarioLogado = -1; // -1 significa que nenhum usuário está logado, se for >=0 significa o índice do usuário logado no array de usuários

void listarUsuarios()
{ // função para listar usuários cadastrados
    if (qntdUsuarios == 0)
    {
        printf("Nenhum usuário cadastrado!\n");
        return;
    }
    for (int i = 0; i < qntdUsuarios; i++)
    {
        const char *nivel = usuarios[i].tipo == ADMIN ? "ADMIN" : "COMUM"; // operador ternário - define o nível do usuário - substitui o if/else
        printf("| %-4d | %-20s | %-25s | %-8s |\n", i, usuarios[i].nome, usuarios[i].email, nivel);
    }
    printf("-------------------------------------------------------------------\n");
}

int main(){
    setlocale(LC_ALL,"pt_BR.UTF-8");
    

    // Escolha de opções fornecidas

    int escolhaUser;

    // Variáveis para login
    char emailLogin[50];
    char senhaLogin[20];

    do {  

    printf("Sistema de Cadastro de Usuários\n");

    printf("\n\t1 - Cadastrar Usuário");
    printf("\n\t2 - Fazer Login");
    printf("\n\t3 - Listar usuários (apenas administradores)");
    printf("\n\t4 - Sair\n");
    printf("\n\t-> ");
    scanf("%i", &escolhaUser);
    getchar(); // sempre limpar o buffer quando vou usar fgets depois do scanf

    switch (escolhaUser)
    {

    case 1:
    {
        // Código para cadastrar usuário
        if (qntdUsuarios < 100)
        {
            printf("Cadastro de Usuário\n");

            printf("\tNome: ");
            fgets(usuarios[qntdUsuarios].nome, 50, stdin);
            usuarios[qntdUsuarios].nome[strcspn(usuarios[qntdUsuarios].nome, "\n")] = '\0';

            printf("\tEmail: ");
            fgets(usuarios[qntdUsuarios].email, 50, stdin);
            usuarios[qntdUsuarios].email[strcspn(usuarios[qntdUsuarios].email, "\n")] = '\0';

            printf("\tSenha: ");
            fgets(usuarios[qntdUsuarios].senha, 20, stdin);
            usuarios[qntdUsuarios].senha[strcspn(usuarios[qntdUsuarios].senha, "\n")] = '\0';

            usuarios[qntdUsuarios].tipo = COMUM; 
            qntdUsuarios++;
            printf("\tUsuário cadastrado!\n");
        }
        else
        {
            printf("Limite de usuários atingido!\n");
        }

        break;
    }

    case 2:
    {
        // Código para Login do usuário
        if (usuarioLogado != -1)
        {
            printf("Já existe um usuário logado! Deslogando usuário ... \n"); // LogOut
            usuarioLogado = -1;
        }
        else
        {
            printf("Login de Usuário\n");

            printf("\n\tEmail: ");
            fgets(emailLogin, 50, stdin);
            emailLogin[strcspn(emailLogin, "\n")] = '\0';

            printf("\n\tSenha: ");
            fgets(senhaLogin, 20, stdin);
            senhaLogin[strcspn(senhaLogin, "\n")] = '\0';

            int encontrado = 0;

            for (int i = 0; i < qntdUsuarios; i++)
            {
                // verifica se o email e senha correspondem
                if (strcmp(usuarios[i].email, emailLogin) == 0 && strcmp(usuarios[i].senha, senhaLogin) == 0)
                {

                    usuarioLogado = i; // variável para armazenar o índice/posição do usuário sem depender do "int i";
                    encontrado = 1;
                    break; // sair do loop
                }
            }
            if (encontrado == 1)
            {
                printf("Login bem-sucedido! Bem-vindo, %s\n", usuarios[usuarioLogado].nome);
            }
            else
            {
                printf("Email ou senha incorretos!\n");
            }
        }

        break;
    }

    case 3:
    {
        // Código para listar usuário
        printf("\n--- Listagem de Usuários ---\n");

        if (usuarioLogado == -1)
        {
            printf("🔒 Você precisa estar logado para listar usuários! ");
            break;
        }
        if (usuarios[usuarioLogado].tipo == ADMIN)
        {
            // Se for administrador, chama a função de listar usuários
            listarUsuarios();
        }
        else
        {
            printf("🔒 Acesso negado! Apenas administradores podem listar usuários.\n");
        }

        break;
    }

    case 4:
    {
        printf("Saindo do sistema...\n");
        exit(0);

        break;
    }
    }
    
    } while (escolhaUser != 4); 
    
    return 0;
}