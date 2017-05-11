#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DIM_CODA 10
#define DIM_STACK 10

//Estructura de un nodo.Contiene un dato y un puntero a un struct
typedef struct node
{
    int data;
    struct node* link;
    
}Node;

//Con esto definiremos una cola.Los elementos se van almacenando "debajo".Los
//primeros en salir son los de abajo(los que se han inserido los ultimos)
typedef struct
{
    Node* front;    //Elemento siguiente
    Node* back;     //Elemento anterior
    int cont;       //Numero elementos de la cola
}Queue;

//                      Stack
//                 _______________
//                 |___cont______|
//                 |__siguiente__|
//                 
//Estructura stack.En un stack los elementos se van metiendo encima.Los primeros
//en salir siguen siendo los ultimos inseridos
typedef struct
{
    Node* top;
    int cont;
}Stack;

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//                          FUNCIONES PARA COLA



//******************************************************************************
//                      FUNCION isEmptyQueue
//Nos indica si la cola está vacia o no
//******************************************************************************
bool isEmptyQueue(Queue apuntador){
    if(apuntador.cont==0){
        return true;
        
    }else{
        return false;
    }
}

//******************************************************************************
//                      FUNCION isFullQueue
//Nos indica si la cola está llena 

bool isFullQueue(Queue apuntador){
    if(apuntador.cont==10){
        return true;
    }else{
        return false;
    }
}

//******************************************************************************
//                      FUNCION pushQueue
//Su funcion es ingresar un dato en la cola
//******************************************************************************

void pushQueue(Queue *apuntador,int val){
    //Si la cola está llena,imprimir por pantalla error
    if(isFullQueue(*apuntador)){
        printf("Error underflow");
    }else{
        //Alocamos en memoria un nuevo nodo
        Node *new_node = (Node*)malloc(sizeof(Node));
        //Asignamos valor al nodo
        new_node->data=val;
        new_node->link=NULL;
        
        //Si la lista apuntada está vacia(No hay ningun elemento)
        if(isEmptyQueue(*apuntador)){
            apuntador->back=new_node;
            apuntador->front=new_node;
            
        }else{
            //Se inserta al principio de la cola pero será el ultimo en salir
            apuntador->back->link=new_node;
            apuntador->back=new_node;
        }
        apuntador->cont++;
    }
}
//******************************************************************************
//                      FUNCION popQueue
//Su funcion es eliminar un valor de la cola.En la cola,
//******************************************************************************

int popQueue(Queue *apuntador){
    
    int val;
    if(isEmptyQueue(*apuntador)){
        printf("Error underflow");
        val=-1;
    }else{
        Node *temp=apuntador->front;
        
        //Si solo hay un elemento
        if(apuntador->cont==1){
            apuntador->back=NULL;
            apuntador->front=NULL;
            apuntador->cont--;
            free(temp);
            
            //Si hay por lo menos dos
        }else{
            
            apuntador->front=apuntador->front->link;
            free(temp);
            apuntador->cont--;
        }
    
    }
    
    return val;
}

//******************************************************************************
//                      FUNCION printCoda
//Su funcion es imprimir por pantalla una cola
//******************************************************************************

void printCoda(Queue *cola){
    if(cola->cont==0){
        printf("La cola esta vacia.\n");
    }else{
    
    Node *temp=cola->front;
    int i=0;
    for(i;i<cola->cont;i++){
        printf("%d\n",temp->data);
        temp=temp->link;
    }
    printf("\n");
    }
}

void printExtremosCola(Queue *cola){
    
    
    printf("El primero es ahora %d",cola->front->data);
    printf("El ultimo es %d",cola->back->data);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//                          FUNCIONES PARA PILA




//******************************************************************************
//                      FUNCION isEmptyStack
//Si el contador es igual a 0 quiere decir que la pila está vacía
//******************************************************************************

bool isEmptyStack(Stack *apuntador){
    if(apuntador->cont==0){
        return true;
    }else{
        return false;
    }
}

//******************************************************************************
//                      FUNCION isFullStack
//Si el contador es igual a 10 queire decir que la lista está llena
//******************************************************************************

bool isFullStack(Stack *apuntador){
    if(apuntador->cont==10){
        return true;
    }else{
        return false;
    }
}

//******************************************************************************
//                      FUNCION pushStack
//Su funcion es inserir un elemento en lo alto de la pila.(Una montaña de platos)
//******************************************************************************

void pushStack(Stack *apuntador,int val){
    
    //Si la lista está llena,no se puede añadir nada
    if(isFullStack(apuntador)){
        printf("error overflow");
    }else{
        //Alocamos el nodo en memoria
        Node *new_node = (Node*)malloc(sizeof(Node));
        //Le damos el valor val
        new_node->data=val;
        new_node->link=NULL;
        
        //Si la pila está vacia(No hay ningun elemento) será el primero.
        if(isEmptyStack(apuntador)){
            apuntador->top=new_node;
            apuntador->cont++;
            
            //Si hay por lo menos un elemento
        }else{
            //El primer nodo apunta al nodo que era antes el primero
            new_node->link=apuntador->top;
            //La cabeza de la pila ahora es este nuevo nodo
            apuntador->top=new_node;
            apuntador->cont++;
        }
        
    }
}
//******************************************************************************
//                      FUNCION popStack
//Su funcion es eliminar un elemento de la pila.Elimina el elemento que se ha 
//inserido el ultimo.El que está más arriba.
//******************************************************************************

void popStack(Stack *stack){
    
    if(isEmptyStack(stack)){
        printf("error.No hay datos");
    }else{
        //Creamos un puntero temporal para borrar el ultimo nodo(el primero empe-
        //zando por arriba
        Node *a_borrar=stack->top;
        //SI solo hay un elemento
        if(stack->cont==1){
            stack->top==NULL;
            free(a_borrar);
            
            //Si hay por lo menos dos
        }else{
            stack->top=stack->top->link;
            free(a_borrar);
        }
        stack->cont--;
    }
}

void printStack(Stack *mi_pila){
    if(mi_pila->cont==0){
        printf("La pila esta vacia\n");
    }else{
        int i=0;
        Node *temp=mi_pila->top;
        for(i;i<mi_pila->cont;i++){
            printf("%d\n",temp->data);
            temp=temp->link;
        }
    }
}

int main()
{
    Queue queue;
    queue.front = NULL;
    queue.back = NULL;
    queue.cont = 0;
    
    //                  COMPROBACIONES DEL CORRECTO FUNCIONAMIENTO
    
    //                  COLAS
    int a=1;
    int b=2;
    int c=3;
    int d=4;
    int e=5;
    
    //Añadimos elementos a la cola
    printf("Añadimos los numeros 1,2,3,4,5 a la cola. \n\n");
    pushQueue(&queue,a);
    pushQueue(&queue,b);
    pushQueue(&queue,c);
    pushQueue(&queue,d);
    pushQueue(&queue,e);
    printf("La cola queda como: \n");
    printCoda(&queue);
    printf("Borramos un elemento.Hacemos pop.\n");
    popQueue(&queue);
    printf("La cola queda como: \n\n");
    printCoda(&queue);
    printf("Aniadimos un elemento a la cola.Hacemos push.");
    pushQueue(&queue,d);
    printf("La cola queda como: \n\n");
    printCoda(&queue);
    printf("Eliminamos los elementos.La cola queda como: \n");
    popQueue(&queue);
    popQueue(&queue);
    popQueue(&queue);
    popQueue(&queue);
    popQueue(&queue);
    printCoda(&queue);
    
    
    //                  STACK(PILAS)
    
    printf("*************************************************\n");
    Stack stack;
    stack.top = NULL;
    stack.cont = 0;
    
    printf("Aniadimos los elementos 1,2,3,4,5 a nuestra stack. \n");
    pushStack(&stack,a);
    pushStack(&stack,b);
    pushStack(&stack,c);
    pushStack(&stack,d);
    pushStack(&stack,e);
    printStack(&stack);
    printf("Sacamos un elemento.Hacemos pop.\n");
    popStack(&stack);
    printf("La pila queda como: \n");
    printStack(&stack);
    printf("Volvemos a aniadir un elemento.\n");
    pushStack(&stack,b);
    printf("La pila queda como: \n");
    printStack(&stack);
    printf("Eliminamos los elementos.La pila queda como: \n");
    popStack(&stack);
    popStack(&stack);
    popStack(&stack);
    popStack(&stack);
    popStack(&stack);
    printStack(&stack);
    
    
//                  FINALIZACION DE COMPROBACION DE COLA 
    
    return 0;
}