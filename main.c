#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int codigo;
    char nome[50];
    float valor;
    int quantidade;
    int quant_vend;
} Item;

void RealizarVenda();
void visualizarEstoque(Item tabela[], int tamanho);
void Cadastroitem(Item tabela[], int *contador);
void Visualizarprodutos(Item tabela[], int *contador);
void attproduto(Item tabela[], int contador);
void excluirproduto(Item tabela[], int *contador);
void Lerprodutos(Item tabela[], int *contador);
void Relatoriovendas();
void Venda();

int contador = 5;

int main()
{
    int opcao;

    Item tabela[100] = {
        {1, "pao de forma", 7.50, 0},
        {2, "pao de centeio", 8.69, 0},
        {3, "broa de milho", 5.00, 0},
        {4, "Sonho", 4.50, 0},
        {5, "Tubaina", 3.25, 0},
    };

    do
    {
        printf("Menu:\n");
        printf("1 - Produtos\n");
        printf("2 - Vendas\n");
        printf("3 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            system("cls");
            Visualizarprodutos(tabela, &contador);
            break;

        case 2:
            system("cls");
            // Venda();
            break;

        case 3:
            system("cls");
            printf("Fechando o programa!\n");
            break;

        default:
            system("cls");
            printf("Opção inválida. Tente novamente.\n");
            break;
        }
    } while (opcao != 3);
    return 0;
}

void Visualizarprodutos(Item tabela[], int *contador)
{
    int opcao;
    do
    {
        printf("1 - Exibir\n");
        printf("2 - Cadastrar\n");
        printf("3 - Atualizar\n");
        printf("4 - Excluir\n");
        printf("5 - Salvar\n");
        printf("6 - Ler\n");
        printf("7 - Voltar\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            system("cls");
            visualizarEstoque(tabela, *contador);
            break;
        case 2:
            system("cls");
            Cadastroitem(tabela, contador);
            break;
        case 3:
            system("cls");
            attproduto(tabela, *contador);
            break;
        case 4:
            system("cls");
            excluirproduto(tabela, contador);
            break;
        case 5:
            saveFile();
            break;
        case 6:
            system("cls");
            // Lerprodutos(tabela, contador);
            break;
        case 7:
            system("cls");
            return;
        default:
            system("cls");
            printf("Opção inválida!!\n");
            break;
        }
    } while (opcao != 7);
}

void visualizarEstoque(Item tabela[], int contador)
{
    printf("Código | Item           | Valor   | Quantidade | Produtos vendidos\n");
    for (int i = 0; i < contador; i++)
    {
        printf("%6d | %-15s | R$ %.2f | %d | %d \n", tabela[i].codigo, tabela[i].nome, tabela[i].valor, tabela[i].quantidade, tabela[i].quant_vend);
    }
}

void Cadastroitem(Item tabela[], int *contador)
{
    int quant_item, cod;
    int validar;

    printf("\nQuantos itens deseja cadastrar? ");
    scanf("%d", &quant_item);
    getchar();

    for (int i = 0; i < quant_item; i++)
    {
        if (quant_item > 0)
        {
            printf("\nEscreva o número do código: ");
            scanf("%d", &cod);
            validar = validador(cod, tabela, *contador);
            if (validar == 0)
            {
                tabela[*contador].codigo = cod;
                printf("\nNome do item: ");
                scanf("%s", tabela[*contador].nome);
                printf("\nValor do item: ");
                scanf("%f", &tabela[*contador].valor);
                printf("\nQuantidade do item: ");
                scanf("%d", &tabela[*contador].quantidade);
                (*contador)++;
            }
        }
    }

    printf("\nSaindo...\n");
}

int validador(int cod, Item tabela[], int contador)
{
    for (int i = 0; i < contador; i++)
    {
        if (cod == tabela[i].codigo)
        {
            printf("\nCódigo inválido\n");
            return 1;
        }
    }
    printf("\nCódigo válido\n");
    return 0;
}

void attproduto(Item tabela[], int contador)
{
    int codigo_editado;
    int encontrado = 0;

    system("cls");
    printf("Código | Item           | Valor   | Quantidade\n");
    for (int i = 0; i < contador; i++)
    {
        printf("%6d | %-15s | R$ %.2f | %d | %d \n", tabela[i].codigo, tabela[i].nome, tabela[i].valor, tabela[i].quantidade);

        printf("Digite o codigo do produto a ser editado: ");
        scanf("%d", codigo_editado);

        for (int i = 0; i < contador; i++)
        {
            if (tabela[i].codigo, codigo_editado)
            {
                encontrado = 1;
                printf("Produto encontrado:\n");
                printf("Codigo Produto: %d", tabela[i].codigo);
                printf("Nome Produto: %s\n", tabela[i].nome);
                printf("Valor Produto: %d\n", tabela[i].valor);
                printf("Quantidade Produto: %d\n", tabela[i].quantidade);

                char opcao[50];
                printf("O que você deseja editar (codigo, nome, valor, quantidade)? ");
                scanf("%s", opcao);

                if (strcmp(opcao, "nome") == 0)
                {
                    printf("Digite o novo nome: ");
                    scanf("%s", tabela[i].nome);
                }
                else if (strcmp(opcao, "codigo") == 0)
                {
                    printf("Digite o novo codigo: ");
                    scanf("%d", &tabela[i].codigo);
                }
                else if (strcmp(opcao, "valor") == 0)
                {
                    printf("Digite o novo valor: ");
                    scanf("%d", &tabela[i].valor);
                }
                else if (strcmp(opcao, "quantidade") == 0)
                {
                    printf("Digite a nova quantidade: ");
                    scanf("%d", &tabela[i].quantidade);
                }
                else
                {
                    printf("Opcao invalida.\n");
                }
            }
        }

        if (!encontrado)
        {
            printf("Produto nao encontrado.\n");
        }
    }
}
void excluirproduto(Item tabela[], int *contador)
{
    int codigo_editado;
    char nome_close[100];
    char excluir[10];
    system("cls");
    printf("Código | Item           | Valor   | Quantidade\n");
    for (int i = 0; i < contador; i++)
    {
        printf("%6d | %-15s | R$ %.2f | %d | %d \n", tabela[i].codigo, tabela[i].nome, tabela[i].valor, tabela[i].quantidade);

        printf("Digite o codigo do produto deseja excluir : ");
        scanf("%d", codigo_editado);
        int encontrar = 0;

        for (int i = 0; i < contador; i++)
        {
            if (tabela[i].codigo, codigo_editado)
            {
                printf("\nDeseja excluir %s? (excluir/cancelar):", tabela[i].nome);
                scanf("%s", excluir);
                if (strcmp(excluir, "excluir") == 0)
                {
                    free(tabela[i]); // Libera a memória do contato a ser excluído
                    for (int j = i; j < contador - 1; j++)
                    {
                        contador[j] = contador[j + 1]; // Move os contatos restantes
                    }
                    contador--;
                    printf("Contato excluído!\n");
                    encontrar = 1;
                    break;
                }
                else if (strcmp(excluir, "cancelar") == 0)
                {
                    printf("Cancelado.\n");
                    encontrar = 1;
                    break;
                }
                else
                {
                    printf("Resposta inválida. Digite 'excluir' ou 'cancelar'.\n");
                }
            }
        }
        if (!encontrar)
        {
            printf("Produto não encontrado.\n");
        }
    }
}

void saveFile(){
    File = *arq;

}
