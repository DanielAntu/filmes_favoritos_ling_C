#include <stdio.h>
#include <string.h>

#define MAX_FILMES 100
#define MAX_TITLE 50

typedef struct {
    char title[MAX_TITLE];
    int year;
    float imdb;
} Film;

void registerFilms(Film films[], int *amount);
void displayFilms(Film films[], int amount);
void searchTitle(Film films[], int amount, char title[]);
void menu();

int main() {
    Film films[MAX_FILMES];
    int amount = 0;
    int option;
    do {
        menu();
        printf("Escolha uma opcao: ");
        scanf("%d", &option);
        getchar();

        switch(option) {
            case 1:
                registerFilms(films, &amount);
                break;
            case 2:
                displayFilms(films, amount);
                break;
            case 3: {
                char searchName[MAX_TITLE];
                printf("\nDigite o titulo do filme a ser buscado: ");
                fgets(searchName, MAX_TITLE, stdin);
                searchName[strcspn(searchName, "\n")] = '\0';

                searchTitle(films, amount, searchName);
                break;
            }
            case 4:
                printf("\nFechando o programa...\n");
                break;
            default:
                printf("\nDigite uma opcao valida. Tente Novamente.\n\n");
                break;
        }

    } while (option != 4);

    printf("Ate Logo\n");

    return 0;
}

void menu() {
    printf("\nSistema de Cadastro de Filmes\n");
    printf("1. Cadastrar Filme\n");
    printf("2. Exibir Filmes\n");
    printf("3. Buscar Filme\n");
    printf("4. Sair\n");
}

void registerFilms(Film films[], int *amount) {
    if (*amount > MAX_FILMES) {
        printf("\nLimite maximo de filmes atingido.\n");
        return;
    }

    printf("Digite o titulo do filme: ");
    fgets(films[*amount].title, MAX_FILMES, stdin);
    films[*amount].title[strcspn(films[*amount].title, "\n")] = '\0';

    printf("Digite o ano de lancamento: ");
    scanf("%d", &films[*amount].year);
    getchar();

    printf("Digite a nota do IMDB do filme: ");
    scanf("%f", &films[*amount].imdb);
    getchar();

    (*amount)++;
    printf("Filme cadastrado com sucesso!\n\n");
}

void displayFilms(Film films[], int amount) {
    if (amount == 0) {
        printf("\nNenhum filme cadastrado.\n\n");
        return;
    }

    printf("\nLista de Filmes\n");
    for (int i = 0; i < amount; i++) {
        printf("%d. Titulo: %s, Ano de lancamento: %d, IMDB: %.1f\n\n", i + 1, films[i].title, films[i].year, films[i].imdb);
    }
}

void searchTitle(Film films[], int amount, char title[]) {
    for (int i = 0; i < amount; i++) {
        if (strcmp(films[i].title, title) == 0) {
            printf("\nFilme Encontrado:\n");
            printf("Titulo do Filme: %s\n", films[i].title);
            printf("Ano de Lancamento: %d\n", films[i].year);
            printf("IMDB: %.2f\n\n", films[i].imdb);
            return;
        }
    }

    printf("\nFilme com o titulo '%s' nao encontrado.\n\n", title);
}
