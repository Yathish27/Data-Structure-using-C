#include<stdio.h>
#include<stdlib.h>

// Node of the linked list
typedef struct Node {
	int data;
	struct Node *link;
} Node;

// Handle of the list. Its head points to the first node in the list.
typedef struct List {
	Node *head;
	int number_of_nodes;
} List;

// Initializes a linked list
List* list_initialize();

// Creates a node and stores the data
Node* create_node(int);

// Deletes the node at the given position
// Does not delete anything if position is out of range
void del_at_pos(int, List*);

// Displays the contents of the linked list in space seperated manner.
void display(List*);

// Inserts an element into an ordered linked list.
void insert_in_order(int, List*);

// Returns the index of the key in the linked list.
// Returns -1 if key not found
int find_key(int, List*);

// Destroy the list by freeing all the nodes.
void destroy_list(List*);

int main()
{
    int choice,element,position,index;

    // Initialize an empty list.
    List* sll = list_initialize();
    do
    {   
        scanf("%d", &choice);
        switch(choice)
        {
            // Delete at given position
            case 1:
            {        
                scanf("%d", &position);
                del_at_pos(position, sll);
            }
            break;
        
            // Insert element into the ordered list.
            case 2: 
            { 
                scanf("%d", &element);
                insert_in_order(element, sll);
            }
            break;
            
            // Display the list.
            case 3:
            {
                display(sll);
            }
            break;
            
            // Find the given key.
            case 4:
            {        
                scanf("%d", &element);
                index = find_key(element, sll);
                printf("%d\n",index);
            }
            break;
            default:
                break;
        }
    }
    while(choice != 0);

    destroy_list(sll);

    return 0;
}

List* list_initialize()
{
    List*list=(List*)malloc(sizeof(List));
    list->head=NULL;
    list->number_of_nodes=0;
    return list;
}

Node* create_node(int data)
{
    Node*new_node=(Node*)malloc(sizeof(Node));
    new_node->data=data;
    new_node->link=NULL;
    return new_node;
}

void display(List* sll)
{
    Node*temp=sll->head;
    if(temp==NULL)
    
    {
        printf("\n");
    }
    else
    {
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->link;
    }
    printf("\n");
    }
    
}

void del_at_pos(int position, List* sll)
{
    if(position<0 || position>sll->number_of_nodes)
    {
        return;
    }
    else
    {
        Node *temp=sll->head;
        Node *prev=NULL;
        for(int i=0;i<position;++i)
        {
            prev=temp;
            temp=temp->link;
        }
        if (prev==NULL)
        {
            sll->head=temp->link;
            free(temp);
            temp=NULL;
        }
        else
        {
            prev->link=temp->link;
            free(temp);
            temp=NULL;
            
        }
        --sll->number_of_nodes;
    }
}

void insert_in_order(int element, List* sll)
{
    Node*newnode=create_node(element);
    if(sll->head=NULL)
    {
        sll->head=newnode;
    }
    else
    {
    Node* prev=NULL;
    Node*curr=sll->head;
    while((curr!=NULL)&& (curr->data >newnode->data))
    {
        prev=curr;
        curr=curr->link;
    }
    if(prev==NULL)
    {
        newnode->link=sll->head;
        sll->head=newnode;
    }
    else
    {
        prev->link=newnode;
        newnode->link=curr ;
    }
    ++sll->number_of_nodes;
    }
    
} 

int find_key(int key, List* sll)
{
    
        Node *temp=sll->head;
        int a=0;
        if(sll->number_of_nodes==0)
        {
            return -1;
        }
        else
        {
            for(int i=0;i<sll->number_of_nodes;++i)
            {
                if(temp->data==key)
                {
                    return i;
                    
                }
                    
            temp=temp->link;
            }
            return -1;        
        }    Node* prev=NULL;
    Node*curr=sll->head;
      
    
}

void destroy_list(List* sll)
{  
    Node*temp;
    for(temp=sll->head;temp!=NULL;temp=temp->link)
    {
        free(sll);
    }
    
}