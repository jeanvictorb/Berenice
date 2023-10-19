#include <stdio.h>
#include <stdlib.h>

void RealizarVenda();
void visualizarEstoque();
void Cadastroitem();
void Visualizarprodutos();
void attproduto();
void excluirproduto();
void Lerprodutos();
void Relatoriovendas();
void venda();

typedef struct Item
{
    int codigo;
    char nome[50];
    float valor;
    int quantidade;
} Item;

int main()
{
    int opcao;
    Item tabela[5] = {
        {18745, "pao de forma", 7.50, 0},
        {45462, "pao de centeio", 8.69, 0},
        {34654, "broa de milho", 5.00, 0},
        {40, "Sonho", 4.50, 0},
        {5000, "Tubaina", 3.25, 0}};

    do
    {
        printf("Menu:\n");
        printf("1 - Produtos\n");
        printf("2 - Vendas\n");
        printf("3 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            system("cls");
            Visualizarprodutos();
            break;

        case 2:
            system("cls");
            RealizarVenda();
            break;

        case 3:
            system("cls");
            printf("Fechando programa!\n");
            break;

        default:
            system("cls");
            printf("Opcao invalida. Tente novamente.\n");
            break;
        }
    } while (opcao != 3);
    return 0;
}

void Visualizarprodutos()
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
            visualizarEstoque();
            break;
        case 2:
            system("cls");
            Cadastroitem();
            break;
        case 3:
            system("cls");
            attproduto();
            break;
        case 4:
            system("cls");
            excluirproduto();
            break;
        case 5:
            /// salvar
            break;
        case 6:
            system("cls");
            Lerprodutos();
            break;
        case 7:
            system("cls");
            int main();
        default:
            system("cls");
            printf("opcao invalida!!\n");
            break;
        }
    } while (opcao != 7);
}

void Venda()
{
    int opcao;
    system("cls");
    printf("1 - Realizar Vendas\n");
    printf("2 - Relatorio de Vendas\n");
    printf("3 - Voltar\n");
    scanf("%d", &opcao);

    do
    {
        switch (opcao)
        {
        case 1:
            system("cls");
            RealizarVenda();
            break;
        case 2:
            system("cls");
            Relatoriovendas();
            break;
        case 3:
            system("cls");
            int main();
        default:
            printf("opcao invalida!!\n");
            break;
        }
    } while (opcao != 3);
}

void visualizarEstoque(Item tabela[], int tamanho)

{
    printf("codigo | item           | valor   | quantidade\n");
    for (int i = 0; i < tamanho; i++)
    {
        printf("%6d | %-15s | R$ %.2f | %d\n", tabela[i].codigo, tabela[i].nome, tabela[i].valor, tabela[i].quantidade);
    }
}
void Cadastroitem()
{
    do
    {
        printf("Digite o Id do item\n")
    } while (/* condition */);
    

}
