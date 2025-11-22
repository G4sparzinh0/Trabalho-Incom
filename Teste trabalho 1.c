#include <stdio.h>
#include <string.h>
typedef struct{
    char nome[101],editora[51];
    int quantidade;
}livro;
void cadastro(livro *a){
    printf("Digite o nome do Livro: ");
    fgets(a->nome,100,stdin);
    printf("Digite o nome da Editora: ");
    fgets(a->editora,50,stdin);
    printf("Digite a quantidade de livros em estoque: ");
    while(1){
        scanf("%d",&a->quantidade);
        if(a->quantidade>=0){
            break;
        }else{
            printf("Quantidade nao aceita, digite novamente: ");
        }
    }
    getchar();
}
void visualizar(livro a){
    printf("Livro: %s",a.nome);
    printf("Editora: %s",a.editora);
    printf("Quantidade: %d\n\n",a.quantidade);
}
void atualizar(livro a[],int ii){
    int opi,q;
    printf("--Selecione o Livro que quer atualizar--\n");
    scanf("%d",&opi);
    if (opi>=0 && opi<ii){
        printf("Digite a nova quantidade: ");
        while(1){
            scanf("%d",&q);
            if(q>=0){
                a[opi].quantidade=q;
                break;
            }else{
                printf("Quantidade nao aceita, digite novamente: ");
            }
        }
        printf("Quantidade atualizada para %d\n\n",a[opi].quantidade);
    }else{
        printf("--Indice Invalido--\n\n");
    }
}
int main(){
    int op,ii=0,opi,q;
    livro a[10];
    while (1){
        printf("---Selecione---\n\n--(1) Cadastrar Livro--\n--(2) Visualizar Livro--\n--(3) Atualizar Quantidade--\n--(4) Finalizar Programa--\n");
        scanf("%d",&op);
        getchar();
        if(op==1){
            printf("\n--Cadastro selecionado--\n\n");
            if(ii<10){
                cadastro(&a[ii]);
                printf("\n");
                ii++;
            }else{
                printf("--LIMITE DE CADASTRO ALCANCADO (10)--\n");
            }
        }
        if(op==2){
            printf("--Visualizacao selecionada--\n");
            printf("--Digite o livro que quer visualizar--\n\n");
            scanf("%d",&opi);
            if(opi>=0 && opi<ii){
                visualizar(a[opi]);
                if(a[opi].quantidade<5){
                    printf("--LIVRO EM BAIXA QUANTIDADE NO ESTOQUE--\n\n");
                }
            }
            else{
                printf("--Indice indisponivel--\n\n");
            }
        }
        if(op==3){
            printf("--Atualizacao selecionada--\n");
            atualizar(a,ii);
        }
        if(op==4){
            printf("--Finalizando Programa...--\n");
            break;
        }
        if(op<1||op>4){
            printf("\n--Opcao selecionada invalida--\n\n");
        }
    }
    return 0;
}
