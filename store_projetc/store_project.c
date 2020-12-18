#include <stdlib.h>
#include <stdio.h>
#include "storage.h"
//Objetivos criar um cadastro de produtos, e fazer o controle de vendas e estoque

int global_ID = 0;

typedef struct produtc{

    int ID;
    float price;
    char *name;
    char *description;
    int qtt_stock;

}Product;

Product * create(float price, char *name, char *description, int qtt_stock){

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
        printf("Quantity in stock: %d\n", product->qtt_stock);
    }
    else{
        printf("\nPrint ERROR product doesnt exists\n");
    }

}

void menu(){

    int conf;

    do{
        system("cls || clear");

        printf("Product register \t- 1\n");
        printf("List of products \t- 2\n");
        printf("Exit \t\t\t- 0\n");
        scanf("%d", &conf);



        switch (conf){
        case 1:
            system("cls");

            break;

        case 2:

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

