
typedef struct produtc Product;

typedef struct cell Cell;

typedef struct linked_list LinkedList;

LinkedList *linked_list_create();

static int verify_empty_linked_list(LinkedList *linked_list);

void linked_list_insert_first(Product *product, LinkedList *linked_list);

void linked_list_insert_last(Product *product, LinkedList *linked_list);

void linked_list_insert(Product *product, LinkedList *linked_list);

void print_linked_list(LinkedList *linked_list);

Product * product_create(float price, char *name, char *description, int qtt_stock);

void product_print(Product *product);

void product_register_menu(LinkedList *product_linked_list);

void menu();
