
typedef struct produtc Product;

Product * create(float price, char *name, char *description, int qtt_stock);

void product_print(Product *product);
