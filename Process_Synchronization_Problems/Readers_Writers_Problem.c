#include<stdio.h>
#include<stdlib.h>
int rc=0,mutex=1,db=1;


int down(){
 if(db==0){
    printf("\nCan't perform any operation\n");
    return db;
    }
else
    return db--;
}

void up(){
 return ++db;
}


void completeRead(){
            mutex--;
            rc=rc-1;
            if(rc==0) up();
            mutex++;    
}

void Reader(){
    int x;
    
        mutex--;
        rc=rc+1;
        if(rc==1) down();
        printf("\nvalue of db is %d \n",db);
        mutex++;        
        r:
        printf("\nREADING database....by reader %d\n",rc);
        w:  
        printf("what you want to do now ?\t");
        printf("\n1)New Reader\n2)Writing\n3)Continue Reading\n");
        
        scanf("%d",&x);
        switch(x){
        
        case 1: Reader();
            break;
        
        case 2: writer(); 
            goto w;
            break;
        
        case 3: completeRead();
            if(rc!=0)
                goto r;
            break; 

        default: printf("please enter correct choice\n");
        }   
    
}

void writer(){
    int check;

    check=down();
        
    if(check){ printf("\nWRITING in database....\n");   
    
        up(); }
    
}

void main(){

    int n;
    while(1){
    printf("Enter the choice\t");   
    printf("\n1)Read\n2)write\n3)exit\n");  
    scanf("%d",&n);
    switch(n){
    
    case 1: Reader();
        break;
    
    case 2: writer();
        break;
    
    case 3: exit(0);
    
    default: printf("\nplease enter correct choiceeeeee\n");
    }

    }
}   

