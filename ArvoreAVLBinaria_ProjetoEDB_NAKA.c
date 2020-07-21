#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

enum Balance {E,C,D};

struct arvore
{
    int chave;
    enum Balance bal;
    struct arvore *esq, *dir;

};

typedef struct arvore no;

int menu_display(int, no **);
void insere( no **, int, int *);
int mydel(no **);
void remover(no **, int);
void ordem(no *);
void preOrdem(no *);
void posOrdem(no *);
int mediaTotal(no *);
int umFilho(no *);
int doisFilhos(no *);
int totalNos(no*);
int totalFolhas(no *);
void largura (no *);
int altura(no *);
int consultaMaior(no *);
int consultaMenor(no *);
int arvoreIguais(no *, no *);
int arvoresSimilares(no *,no *);
int arvoreSimetricas(no *, no *);
int consultaArvores(no *, no *, int);

int main()
{
    setlocale(LC_ALL, "portuguese");

    int valor;
    int total, totalContagem, totalMedia, totalAlt;
    int opcaoMenu , opcaoPercurso, opcaoContagem, opcaoRaiz = 1;
    int num, i;
    int quant1 = 0, quant2 = 0;
    int flagRaiz;
    int flag;
    int verificaRaiz;
    float media;
    no *raiz1 = NULL;
    no *raiz2 = NULL;


        do
        {
            opcaoMenu = 1;
            printf("Escolha entre a raiz 1 e 2\n");
            printf("0. Sair\n");
            printf("->: ");
            scanf("%d", &opcaoRaiz);
            switch(opcaoRaiz)
            {
            case 1:
                flagRaiz = 1;
                break;
            case 2:
                flagRaiz = 2;
                break;
            case 0:
                exit(1);
            default:
                return 0;

        }

        while(opcaoMenu != 0)
        {
            system("cls");
            printf("1.Inserir\n");
            printf("2.Excluir\n");
            printf("3.Media dos valores\n");
            printf("4.Percurso da arvore\n");
            printf("5.Contagem de nós\n");
            printf("6.Largura da árvore\n");
            printf("7.Altura da árvore\n");
            printf("8.Consultar o maior numero\n");
            printf("9.Consultar o menor numero\n");
            printf("10.Consultar se as árvores são iguais\n");
            printf("11.Consultar se as árvores são similares\n");
            printf("12.Consultar se as árvores são simetricas\n");
            printf("13.Consultar se o valor se encontra em alguma ou nas duas arvores\n");
            printf("0.Sair\n");
            scanf("%d", &opcaoMenu);
            system("cls");

            switch(opcaoMenu)
            {
                case 1:
                    if(flagRaiz == 1)
                    {
                        printf("quantos valores quer colocar?: \n");
                        scanf("%d",&num);
                         for(i = 0; i < num; i++)
                        {
                            printf("->: \n");
                            scanf("%d", &valor);
                            insere(&raiz1, valor, &flag);
                        }
                        quant1 = quant1 + num;
                    }
                    else if(flagRaiz == 2)
                    {
                        printf("quantos valores quer colocar?: \n");
                        scanf("%d",&num);
                        for(i = 0; i < num; i++)
                        {
                            printf("->: \n");
                            scanf("%d", &valor);
                            insere(&raiz2, valor, &flag);
                        }

                        quant2 = quant2 + num;
                    }
                    system("pause");
                    system("cls");
                    break;
                case 2:
                    if(flagRaiz == 1)
                    {
                        printf("qual valor deseja remover?: \n");
                        scanf("%d", &valor);
                        remover(&raiz1, valor);
                        quant1--;
                    }
                    else if(flagRaiz == 2)
                    {
                        printf("qual valor deseja remover?: \n");
                        scanf("%d", &valor);
                        remover(&raiz2, valor);
                        quant2--;
                    }
                    system("pause");
                    system("cls");
                    break;
                case 3:
                    if(flagRaiz == 1)
                    {
                        totalMedia = mediaTotal(raiz1);
                        media = totalMedia/quant1;
                        printf("%.2f é total aproximado da média\n", media);
                    }
                    else if(flagRaiz == 2)
                    {
                        totalMedia = mediaTotal(raiz2);
                        media = totalMedia/quant2;
                        printf("%.2f é total aproximado da média\n", media);
                    }
                    system("pause");
                    system("cls");
                    break;
                case 4:
                    printf("1. Percurso em ordem\n");
                    printf("2. Percurso em pré ordem\n");
                    printf("3. Percurso em pós ordem\n");
                    printf("Qual percusro deseja fazer?: \n");
                    scanf("%d", &opcaoPercurso);
                    switch(opcaoPercurso)
                    {
                    case 1:
                        if(flagRaiz == 1)
                        {
                            ordem(raiz1);
                        }
                        else if(flagRaiz == 2)
                        {
                            ordem(raiz2);
                        }
                        system("pause");
                        break;
                    case 2:
                        if(flagRaiz == 1)
                        {
                            preOrdem(raiz1);
                        }
                        else if(flagRaiz == 2)
                        {
                            preOrdem(raiz2);
                        }
                        system("pause");
                        break;
                    case 3:
                        if(flagRaiz == 1)
                        {
                            posOrdem(raiz1);
                        }
                        else if(flagRaiz == 2)
                        {
                            posOrdem(raiz2);
                        }
                        system("pause");
                        break;
                    }
                    system("cls");
                    break;
                case 5:
                    printf("1.Total de nós com um filho\n");
                    printf("2.Total de nós com dois filhos\n");
                    printf("3.Total de nós\n");
                    printf("4.Total de nós folhas\n");
                    scanf("%d", &opcaoContagem);
                    system("cls");
                    switch(opcaoContagem)
                    {
                    case 1:
                        if(flagRaiz == 1)
                        {
                            totalContagem = umFilho(raiz1);
                            printf("%d é o total de nós com um filho\n", totalContagem);
                        }
                        else if(flagRaiz == 2)
                        {
                            totalContagem = umFilho(raiz2);
                            printf("%d é o total de nós com um filho\n", totalContagem);
                        }
                        system("pause");
                        break;
                    case 2:
                        if(flagRaiz == 1)
                        {
                            totalContagem = doisFilhos(raiz1);
                            printf("%d é o total de nós com dois filhos\n", totalContagem);
                        }
                        else if(flagRaiz == 2)
                        {
                            totalContagem = doisFilhos(raiz2);
                            printf("%%d é o total de nós com dois filhos\n", totalContagem);
                        }
                        system("pause");
                        break;
                    case 3:
                        if(flagRaiz == 1)
                        {
                            if(raiz1 == NULL)
                            {
                                printf("Raiz Vazia\n");
                                break;
                            }
                            totalContagem = totalNos(raiz1);
                            printf("%d é o total de nós\n", totalContagem);
                        }
                        else if(flagRaiz == 2)
                        {
                            if(raiz2 == NULL)
                            {
                                printf("Raiz Vazia\n");
                                break;
                            }
                            totalContagem = totalNos(raiz2);
                            printf("%d é o total de nós\n", totalContagem);
                        }
                        system("pause");
                        break;
                    case 4:
                        if(flagRaiz == 1)
                        {
                            totalContagem = totalFolhas(raiz1);
                            printf("%d é o total de folhas\n", totalContagem);
                        }
                        else if(flagRaiz == 2)
                        {
                            totalContagem = totalFolhas(raiz2);
                            printf("%d é o total de folhas\n", totalContagem);;
                        }
                        system("pause");
                        break;
                    }
                    system("cls");
                    break;
                case 6:
                    if(flagRaiz == 1)
                    {
                        largura(raiz1);
                    }
                    else if(flagRaiz == 2)
                    {
                        largura(raiz2);
                    }
                    system("pause");
                    system("cls");
                    break;
                case 7:
                    if(flagRaiz == 1)
                    {
                        totalAlt = altura(raiz1);
                        printf("A altura total é %d\n", totalAlt);
                    }
                    else if(flagRaiz == 2)
                    {
                        totalAlt = altura(raiz2);
                        printf("A altura total é %d\n", totalAlt);
                    }
                    system("pause");
                    system("cls");
                    break;
                    break;
                case 8:
                    if(flagRaiz == 1)
                    {
                        total = consultaMaior(raiz1);
                    }
                    else if(flagRaiz == 2)
                    {
                        total = consultaMaior(raiz2);
                    }
                    if(total == 0)
                        printf("A árvore está vazia\n");
                    else printf("%d é o maior numero \n", total);
                    system("pause");
                    system("cls");
                    break;
                case 9:
                    if(flagRaiz == 1)
                    {
                        total = consultaMenor(raiz1);
                    }
                    else if(flagRaiz == 2)
                    {
                        total = consultaMenor(raiz2);
                    }
                    if(total == 0)
                        printf("A árvore está vazia\n");
                    else printf("%d é o menor numero \n", total);
                    system("pause");
                    system("cls");
                    break;
                case 10:
                    verificaRaiz = arvoreIguais(raiz1, raiz2);
                    if(verificaRaiz == 0)
                    {
                        printf("As raizes não são iguais\n");
                        system("pause");
                    }
                    else if (verificaRaiz == 1)
                    {
                        printf("As raizes são iguais\n");
                        system("pause");
                    }
                    system("cls");
                    break;
                case 11:
                    verificaRaiz = arvoresSimilares(raiz1, raiz2);
                    if(verificaRaiz == 0)
                    {
                        printf("As raizes não são similares\n");
                        system("pause");
                    }
                    else if (verificaRaiz == 1)
                    {
                        printf("As raizes são similares\n");
                        system("pause");
                    }
                    system("cls");
                    break;
                case 12:
                    verificaRaiz = arvoreSimetricas(raiz1, raiz2);
                    if(verificaRaiz == 0)
                    {
                        printf("As raizes não são simetricas\n");
                        system("pause");
                    }
                    else if (verificaRaiz == 1)
                    {
                        printf("As raizes são simetricas\n");
                        system("pause");
                    }
                    system("cls");
                    break;
                case 13:
                    if(!raiz1)
                    {
                        printf("Arvore 1 está vazia\n");
                        system("pause");
                        break;
                    }
                    if(!raiz2)
                    {
                        printf("Arvore 2 está vazia\n");
                        system("pause");
                        break;
                    }
                    printf("qual valor deseja consultar?: \n");
                    scanf("%d", &valor);
                    verificaRaiz = consultaArvores(raiz1, raiz2, valor);
                    if(verificaRaiz == 0)
                    {
                        printf("O valor não se encontra nas arvores\n");
                        system("pause");
                    }
                    else if(verificaRaiz == 1)
                    {
                        printf("O valor se encontra nas duas arvores\n");
                        system("pause");
                    }
                    else if(verificaRaiz == 2)
                    {
                        printf("O valor se encontra na arvore 1\n");
                        system("pause");
                    }
                    else if(verificaRaiz == 3)
                    {
                        printf("O valor se encontra na arvore 2\n");
                        system("pause");
                    }
                    system("cls");
                    break;
                default:
                    printf("Numero Inválido");
                case 0:
                    break;
            }
        }
        }while(opcaoRaiz != 0);
    return (0);
}

void insere(no **raiz, int valor, int *flag)//função que insere valores na arvore
{
    no *aux1, *aux2;

    if((*raiz) == NULL)
    {
        (*raiz) = (no*)malloc(sizeof(no));
        if(*raiz == NULL) return;

        *flag = 1;
        (*raiz)->chave = valor;
        (*raiz)->esq = (*raiz)->dir = NULL;
        (*raiz)->bal = C;

    }
    else
        if(valor < (*raiz)->chave)
        {
            insere(&(*raiz)->esq, valor, flag);
                if(*flag)
                {
                    switch((*raiz)->bal)
                    {
                      case D:
                        (*raiz)->bal = C;
                        *flag = 0;
                        break;
                    case C:
                        (*raiz)->bal = E;
                        break;
                    case E:
                        aux1 = (*raiz)->esq;
                        if(aux1->bal == E)
                        {
                            (*raiz)->esq = aux1->dir;
                            aux1->dir = (*raiz);
                            (*raiz)->bal = C;
                            (*raiz) = aux1;
                        }
                        else
                        {
                            aux2 = aux1->dir;
                            aux1->dir = aux2->esq;
                            aux2->esq = aux1;
                            (*raiz)->esq = aux2->dir;
                            aux2->dir = (*raiz);
                            if(aux2->bal == E) (*raiz)->bal = D;
                                else (*raiz)->bal = C;
                            if(aux2->bal == D) (*raiz)->bal = E;
                                else aux1->bal = C;
                            (*raiz) = aux2;
                        }
                        (*raiz)->bal = C;
                        *flag = 0;
                        break;
                    }

                }
        }
        else
            if(valor > (*raiz)->chave)
            {
                insere(&(*raiz)->dir, valor, flag);
                    if(*flag)
                    {
                        switch((*raiz)->bal)
                        {
                           case E:
                            (*raiz)->bal = C;
                            *flag = 0;
                            break;
                        case C:
                            (*raiz)->bal = D;
                            break;
                        case D:
                            aux1 = (*raiz)->dir;
                            if(aux1->bal == D)
                            {
                                (*raiz)->dir = aux1->esq;
                                aux1->esq = (*raiz);
                                (*raiz)->bal = C;
                                (*raiz) = aux1;
                            }
                            else
                            {
                                aux2 = aux1->esq;
                                aux1->esq = aux2->dir;
                                aux2->dir = aux1;
                                (*raiz)->dir = aux2->esq;
                                aux2->esq = (*raiz);
                                if(aux2->bal == D) (*raiz)->bal = E;
                                    else (*raiz)->bal = C;
                                if(aux2->bal == E) (*raiz)->bal = D;
                                    else aux1->bal = C;
                                (*raiz) = aux2;
                            }
                            (*raiz)->bal = C;
                            *flag = 0;
                            break;
                        }
                    }
                }
}

int mydel(no **x)
{
    if ((*x)->dir != NULL) return(mydel(&(*x)->dir));
    else
    {
         int n = (*x)->chave;
         (*x) = (*x)->esq;
         return(n);
     }
}

void remover(no **raiz, int valor)//função onde remove valores da arvore
{
    //no *aux;

    if (*raiz != NULL)
    {
        if ((*raiz)->chave == valor)
        {
             if ((*raiz)->esq == NULL)
                (*raiz) = (*raiz)->dir;
             else if ((*raiz)->dir == NULL)
                (*raiz) = (*raiz)->esq;
             else
                (*raiz)->chave = mydel(&(*raiz)->esq);
         }
          else if (valor > (*raiz)->chave)
            remover(&(*raiz)->dir, valor);
          else if (valor < (*raiz)->chave)
            remover(&(*raiz)->esq, valor);
    }
    else
    {
        printf("Árvore vazia\n");
    }
}

void ordem(no *raiz) //função para fazer a percussão em ordem
{
    if(raiz != NULL)
    {
        ordem(raiz->esq);
        printf("%d\n", raiz->chave);
        ordem(raiz->dir);
    }
}

void preOrdem(no *raiz)//função para fazer a percussão em pré ordem
{
    if(raiz != NULL)
    {
        printf("%d\n", raiz->chave);
        preOrdem(raiz->esq);
        preOrdem(raiz->dir);
    }
}

void posOrdem(no *raiz)//função para fazer a percussão em pós ordem
{
    if(raiz != NULL)
    {
        posOrdem(raiz->esq);
        posOrdem(raiz->dir);
        printf("%d\n", raiz->chave);
    }
}

   struct no_fila {
        no *registro;
        struct no_fila *prox;
         };

typedef struct no_fila no_fila;

void enqueue(no *raiz, no_fila **fila)
{
    if (*fila==NULL)
    {
        *fila=(no_fila *) malloc(sizeof(no_fila));
        (*fila)->registro = raiz;
        (*fila)->prox = NULL;
    } else
    {
        no_fila *aux;
        aux = *fila;
        while ((aux)->prox != NULL)
                 (aux) = (aux)->prox;
        aux->prox = (no_fila *) malloc(sizeof(no_fila));
        aux = aux->prox;
        aux->registro = raiz;
        aux->prox = NULL;
    }
}

no_fila *dequeue(no_fila **fila)
{
   if (*fila!=NULL) {
         no_fila *aux;
         aux = *fila;
         if (aux->prox==NULL)
            {
              *fila=NULL;
              return(aux);
              }
              else {
                   aux=*fila;
                   *fila=(*fila)->prox;
                   return(aux);
                   }
         }
}

void largura (no *raiz) //função que verifica a largura da arvore
{
     no_fila *fila = NULL;
     no_fila * aux;

     enqueue (raiz, &fila);
     while (fila) {
           aux = dequeue(&fila);
           printf("%d ( %d )  ", aux->registro->chave, aux->registro->bal);
           if (aux->registro->esq) enqueue (aux->registro->esq, &fila);
           if (aux->registro->dir) enqueue (aux->registro->dir, &fila);
           }
     printf("\n");
}

int altura(no *raiz)//função uqe verifica a altura da raiz
{
    if(raiz == NULL)
        return -1;
    else
    {
        int AltEsq = altura(raiz->esq);
        int AltDir = altura(raiz->dir);
        if(AltEsq < AltDir)
            return(AltDir + 1);
        else
            return(AltEsq +1);
    }
}

int mediaTotal(no *raiz) //função para verificar a média da raiz
{
    if(raiz == NULL) return (0);
    return(raiz->chave + mediaTotal(raiz->esq) + mediaTotal(raiz->dir));
}

int umFilho(no *raiz) //função para verificar o total de nós com um filho
{
    if(!raiz) return(0);
    if((raiz->esq == NULL) && (raiz->dir == NULL)) return (0);
    if((raiz->esq == NULL) || (raiz->dir == NULL)) return (1);
    return(umFilho(raiz->esq) + umFilho(raiz->dir));
}

int doisFilhos(no *raiz) //função para verificar o total de nós com dois filhos
{
    int quant = 0;
    no *aux;
    aux = raiz;
    if (aux==NULL) return (0);
       {
        while(aux->esq != NULL)
        {
            if((aux->esq != NULL) && (aux->dir != NULL)) quant++;
            aux = aux->esq;
        }
    aux = raiz->dir;
        while(aux->dir != NULL)
        {
            if((aux->esq != NULL) && (aux->dir != NULL)) quant++;
            aux = aux->dir;
        }
     }
    return(quant);
}

int totalNos(no *raiz)//verificar total de nós na arvores
{
    if(!raiz) return(0);
    while((raiz->esq == NULL) && (raiz->dir == NULL))
    {
        return (1);
    }
    return(1 + totalNos(raiz->esq) + totalNos(raiz->dir));
}

int totalFolhas(no *raiz)//total de folhas em arvores
{
    if(!raiz) return(0);
    while((raiz->esq == NULL) && (raiz->dir == NULL))
    {
        if((raiz->esq == NULL) && (raiz->dir == NULL)) return (1);
    }
    return(totalFolhas(raiz->esq) + totalFolhas(raiz->dir));
}

int consultaMaior(no *raiz)//a função que consulta o maior numero na arvore
{
    no *aux;
    aux = raiz;
    if (aux==NULL) return (0);
     else
     {
        while(aux->dir != NULL)
        {
          aux = aux->dir;
        }
        return (aux->chave);
     }
}

int consultaMenor(no *raiz)//função que consulta o menor numero na arvore
{
    no *aux;
    aux = raiz;
    if (aux==NULL) return (0);
     else
     {
        while(aux->esq != NULL)
        {
          aux = aux->esq;
        }
        return (aux->chave);
     }
}

int arvoreIguais(no *raiz1, no *raiz2) // função que consulta se as arvores são iguais
{
    if(raiz1 == NULL && raiz2==NULL) return 1;
    if(raiz1 == NULL || raiz2==NULL) return 0;
    if(raiz1->chave != raiz2->chave) return 0;
    if(arvoreIguais(raiz1->esq, raiz2->esq) == 0)
        return 0;
    if(arvoreIguais(raiz1->dir, raiz2->dir) == 0)
        return 0;
    return 1;
}

int arvoresSimilares(no *raiz1, no *raiz2) // função que consulta se as arvores são similares
{
    int quantR1 = 1;
    int quantR2 = 1;
    int alt1 = altura(raiz1);
    int alt2 = altura(raiz2);

    if(!raiz1 && !raiz2) return(0);
    if(alt1 == alt2)
    {
        quantR1 = totalNos(raiz1);
        quantR2 = totalNos(raiz2);
        if(quantR1 == quantR2)
        {
            return 1;
        }
        else return 0;
    }
    else return 0;
}

int arvoreSimetricas(no *raiz1, no *raiz2)// função que consulta se as arvores são simétricas
{
    if(raiz1 == NULL && raiz2==NULL) return 1;
    if(raiz1 == NULL || raiz2==NULL) return 0;
    if(raiz1->chave != raiz2->chave) return 0;
    if(arvoreSimetricas(raiz1->esq, raiz2->dir) == 0)
        return 0;
    if(arvoreSimetricas(raiz1->dir, raiz2->esq) == 0)
        return 0;
    return 1;
}

int consulta(no* raiz, int valor)// faz a consulta se o numero está na arvores
{
    if (raiz == NULL) return (0);
    else if (raiz->chave == valor) return (1);
    else if (valor < raiz->chave) return(consulta (raiz->esq, valor));
    else return(consulta (raiz->dir, valor));
}

int consultaArvores(no *raiz1, no *raiz2, int valor) // função que retorna se o valor está em uma ou nas duas arvores
{
    int consR1 = consulta(raiz1, valor);
    int consR2 = consulta(raiz2, valor);
    if(consR1 == 1 && consR2 == 1) return 1;
    if(consR1 == 1 && consR2 != 1) return 2;
    if(consR1 != 1 && consR2 == 1) return 3;
    else return 0;
}
