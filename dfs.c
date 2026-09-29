#include <stdio.h>
#include<stdlib.h>

struct node{
    int data ;
    struct node *next;
    
};
struct node *adj[10];
void add_edge(int u,int v){
    struct node*newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=v;
    newnode->next=adj[u];
    adj[u]=newnode;
    
}
void display(int vertices){
    struct node *temp;
    for(int i=0;i<vertices;i++){
        temp=adj[i];
        printf("%d->",i);
        while(temp!=NULL){
            printf("%d->",temp->data);
            temp=temp->next;
        }
            printf("NULL\n");
    }
    
}
void DFS(int vertex) {
    struct node *temp;
    int visited[100];

    visited[vertex] = 1;
    printf("%d ", vertex);

    temp = adj[vertex];

    while (temp != NULL) {
        if (visited[temp->data] == 0) {
            DFS(temp->data);
        }

        temp = temp->next;
    }
}

int main() {
    int vertices,edges,u,v;

    printf("Number of vertices:");
    scanf("%d",&vertices);

    printf("Number of edges:");
    scanf("%d",&edges);

    for(int i=0;i<vertices;i++){
        adj[i]=NULL;
    }

for(int i=0;i<edges;i++){
        scanf("%d %d",&u,&v);
    

   add_edge(u,v);
   add_edge(v,u); 
}
   display(vertices); 
   DFS(0);
    return 0;
}
