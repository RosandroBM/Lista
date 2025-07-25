#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct {
    int ele[MAX];
    int tam;} Lista;
Lista criar_lista() {
    Lista l;
    l.tam = 0;
    return l;}

int esta_vazia(Lista *l) {
    return l->tam == 0;}
int esta_cheia(Lista *l) {
    return l->tam == MAX;}
int tamanho_lista(Lista *l) {
    return l->tam;}
int obter_valor(Lista *l, int pos) {
    if (pos < 1 || pos > l->tam) {
        printf("Erro: posição inválida.\n");
        return -1;
        }
    return l->ele[pos - 1];}
void modificar_valor(Lista *l, int pos, int novo) {
    if (pos < 1 || pos > l->tam) {
        printf("Erro: posição inválida.\n");
        return;
    }
    l->ele[pos - 1] = novo;
}
void inserir(Lista *l, int pos, int valor) {
    if (esta_cheia(l)) {
        printf("Erro: lista cheia.\n");
        return;
    }
    if (pos < 1 || pos > l->tam + 1) {
        printf("Erro: posição inválida.\n");
        return;
    }
    for (int i = l->tam; i >= pos; i--)
        l->ele[i] = l->ele[i - 1];
    l->ele[pos - 1] = valor;
    l->tam++;
}
void remover(Lista *l, int pos) {
    if (pos < 1 || pos > l->tam) {
        printf("Erro: posição inválida.\n");
        return;
    }
    for (int i = pos; i < l->tam; i++)
        l->ele[i - 1] = l->ele[i];
    l->tam--;
}

void exibir(Lista *l) {
    printf("Lista: ");
    for (int i = 0; i < l->tam; i++)
        printf("%d ", l->ele[i]);
    printf("\n");
}
void salvar_lista(Lista *l) {
    FILE *f = fopen("dados.bin", "wb");
    if (f) {
        fwrite(l, sizeof(Lista), 1, f);
        fclose(f);
    }
}

void carregar_lista(Lista *l) {
    FILE *f = fopen("dados.bin", "rb");
    if (f) {
        fread(l, sizeof(Lista), 1, f);
        fclose(f);
    } else {
        *l = criar_lista(); 
    }
}

int main(int argc, char *argv[]) {
    Lista lista;
    carregar_lista(&lista);
    if (argc < 2) {
        printf("Uso: ./lista <comando> [args]\n");
        printf("Comandos disponíveis:\n");
        printf(" inserir <pos> <valor>\n");
        printf(" remover <pos>\n");
        printf(" modificar <pos> <novo>\n");
        printf(" obter <pos>\n");
        printf(" tamanho\n");
        printf(" vazio\n");
        printf(" cheio\n");
        printf(" exibir\n");
        return 1;
    }
    char *cmd = argv[1];
    if (strcmp(cmd, "inserir") == 0 && argc == 4) {
        int pos = atoi(argv[2]);
        int val = atoi(argv[3]);
        inserir(&lista, pos, val);
    } else if (strcmp(cmd, "remover") == 0 && argc == 3) {
        int pos = atoi(argv[2]);
        remover(&lista, pos);
    } else if (strcmp(cmd, "modificar") == 0 && argc == 4) {
        int pos = atoi(argv[2]);
        int novo = atoi(argv[3]);
        modificar_valor(&lista, pos, novo);
    } else if (strcmp(cmd, "obter") == 0 && argc == 3) {
        int pos = atoi(argv[2]);
        int valor = obter_valor(&lista, pos);
        if (valor != -1)
            printf("Valor na posição %d: %d\n", pos, valor);
    } else if (strcmp(cmd, "tamanho") == 0) {
        printf("Tamanho atual da lista: %d\n", tamanho_lista(&lista));
    } else if (strcmp(cmd, "vazio") == 0) {
        printf("Lista %s\n", esta_vazia(&lista) ? "está vazia." : "não está vazia.");
    } else if (strcmp(cmd, "cheio") == 0) {
        printf("Lista %s\n", esta_cheia(&lista) ? "está cheia." : "ainda tem espaço.");
    } else if (strcmp(cmd, "exibir") == 0) {
        exibir(&lista);
    } else {
        printf("Comando inválido ou argumentos incorretos.\n");
    }
    salvar_lista(&lista);
    return 0;
}
