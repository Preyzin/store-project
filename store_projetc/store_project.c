#include <stdlib.h>
#include <stdio.h>
#include "storage.h"
//Objetivos criar um cadastro de produtos, e fazer o controle de vendas e estoque

static int global_ID = 0;

typedef struct produtc{

    int ID;
    float price;
    char *name;
    char *description;
    int qtt_stock;

}Product;

typedef struct cell{

    Product *product;
    struct Cell *next;

}Cell;

Cell *cell_create(Product *product){

    Cell *cell = malloc(sizeof(Cell));

    cell->product = product;

    cell->next = NULL;

    return cell;

}


typedef struct linked_list{

    Cell *head;

}LinkedList;

LinkedList *linked_list_create(){

    LinkedList *linked_list = malloc(sizeof(LinkedList));

    linked_list->head = NULL;

    return linked_list;
}

static int verify_empty_linked_list(LinkedList *linked_list){

    return (linked_list == NULL) || (linked_list->head == NULL);

}

void linked_list_insert_first(Product *product, LinkedList *linked_list){

    Cell *aux;

    if (linked_list == NULL)
        linked_list = linked_list_create();

    aux = cell_create(product);

    aux->next = linked_list->head;

    linked_list->head = aux;
}

void linked_list_insert_last(Product *product, LinkedList *linked_list){
    Cell *aux, *new_cell;

    if (linked_list == NULL)
        linked_list = linked_list_create();

    if (verify_empty_linked_list(linked_list))
        linked_list_insert_first(product, linked_list);
    else{
        aux = linked_list->head;

        while(aux->next != NULL)
            aux = aux->next;

        new_cell = cell_create(product);

        aux->next = new_cell;
    }
}

void linked_list_insert(Product *product, LinkedList *linked_list){

    Cell *aux;

    if(linked_list == NULL)
        linked_list = linked_list_create();

    if(verify_empty_linked_list(linked_list))
        linked_list_insert_first(product, linked_list);
    else
        linked_list_insert_last(product, linked_list);

}

void print_linked_list(LinkedList *linked_list){

    system("cls || clear");

    Cell *aux;

    if(!verify_empty_linked_list(linked_list)){
        aux = linked_list->head;

        while(aux != NULL){
            product_print(aux->product);
            aux = aux->next;
        }

    }

    system("pause");

}

Product * product_create(float price, char *name, char *description, int qtt_stock){

    Product *product = (Product*) malloc(sizeof(Product));

    if(product != NULL){
        product->ID = global_ID;
        global_ID++;

        product->price = price;

        product->name = malloc(sizeof(char)* strlen(name));
        strcpy(product->name, name);

        product->description = malloc(sizeof(char)* strlen(description));
        strcpy(product->description, description);

        product->qtt_stock = qtt_stock;
        return product;
    }
    else{
        printf("\nInitializating ERROR!\n");
    }

}

void product_print(Product *product){

    if(product != NULL){

        printf("\nID: %d\n", product->ID);
        printf("Name: %s\n", product->name);
        printf("Description: %s\n", product->description);
        printf("Price: $ %.2f\n", product->price);
        printf("Quantity in stock: %d (un)\n", product->qtt_stock);
    }
    else{
        printf("\nPrint ERROR product doesnt exists\n");
    }

}

void product_register_menu(LinkedList *product_linked_list){

    char product_name[120], product_description[250];
    float product_price;
    int product_qtt_stock;

    system("cls || clear");

    printf("Product register menu\n\n");


    fflush(stdin);
    printf("Product Name: ");
    gets(product_name);

    fflush(stdin);
    printf("\nProduct Description: ");
    gets(product_description);

    printf("\nProduct Price: $ ");
    scanf("%f", &product_price);

    printf("\nQuantity in Stock (un): ");
    scanf("%d", &product_qtt_stock);

    linked_list_insert(product_create(product_price, product_name, product_description, product_qtt_stock), product_linked_list);

}


void menu(){

    int conf;

    LinkedList *product_linked_list = linked_list_create();

    do{
        system("cls || clear");

        printf("Product register \t- 1\n");
        printf("List of products \t- 2\n");
        printf("Exit \t\t\t- 0\n");
        scanf("%d", &conf);



        switch (conf){
        case 1:

            product_register_menu(product_linked_list);

            break;

        case 2:

            print_linked_list(product_linked_list);

            break;

        case 0:
            system("cls || clear");
            printf("System shutdown");
            break;

        default:
            printf("\nInvalid option\n");
            system("pause");
        }

    }while(conf != 0);

}

