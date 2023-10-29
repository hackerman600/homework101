#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 30
#define COLS 3

double ** return_data(){
    //,Years,Experience,Salary
    double ** skills = malloc(sizeof(double*)*ROWS);
    char mystr[300];
    FILE* mypointer;
    int row_ind,col_ind = 0;

    mypointer = fopen("/home/kali/Downloads/Salary_dataset.csv","r");
    while(fgets(mystr,sizeof(mystr),mypointer)){
        printf("%s%s", mystr,"\n");
        char *tok = strtok(mystr,",");
        double *row = malloc(sizeof(double)*COLS);
        skills[row_ind] = row;
        col_ind = 0;
        while (tok != NULL){
            skills[row_ind][col_ind] = strtod(tok,NULL);
            col_ind += 1;
            tok = strtok(NULL,",");
        }
        row_ind += 1;
    }

    return skills;
} 

void print_struct(double** mydata){
    for (int i = 0; i < ROWS; i ++){
        for (int l = 0; l < COLS; l++){
            printf("%f%s",mydata[i][l],", ");
        }
        printf("\n");
    }
}

enum myenum{
    HOURS_WORKED_PW = 40,
    START_TIME = 9,
    END_TIME = 5,
    BREAK_LENGTH = 40,
    NO_BREAKS = 1
}__attribute__((packed));


struct mystruct{
    double myval;
    double mygal;
};

int main(){

    //,Years,Experience,Salary
    double **mydata = return_data();
    print_struct(mydata);
    printf("%d",HOURS_WORKED_PW); 

    struct mystruct structme;
    structme.mygal = 5;
    printf("%f",structme.mygal); 


    return 0;
}