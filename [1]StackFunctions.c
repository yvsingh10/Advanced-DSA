#include <stdio.h>
    void push(int x);
    void pop();
    void peek();
    void traverse ();
    int top= -1;
    int st[4];
    
    
int main() {
    
    push(9);
    push(6);
    push(5);
    push(10);
    pop();
    push(1);
    peek();
    traverse ();
   
    return 0;
}

void push(int x){
    if (top==3){
        printf("Stack is full");
        
        
    }
    else{
        top=top+1;
        st[top]=x;
    }
        
    }
    
    
    void pop(){
        if(top==-1){
            printf("Stack is alrerady empty.");
            
        }
        else{
            int y;
            y= st[top];
            top=top-1;
            printf("Popped element is:%d\n",y);
        }
        }

void peek(){
    int y;
    y= st[top];
    printf("Value of top is:%d\n",y);
}

void traverse()
{
    if(top==-1){
        printf("Stack is empty");
    }
    else{
        printf("Stack elements:\n");
        for(int i=top;i>=0;i--){
            printf("%d\n",st[i]);
        }
        }
        printf("\n");
    }
    
    
