//
//  Name this file: penny.c
//  PennyLab
//
//  Student Name: Melanie Summers;
//  Student id: 012090935;
//  Name of the assignment: Penny Lab;
//  Date: 10/03/18;
//  Name and version of the C Compiler: Xcode v. 9.4.1;
//  Name of Operating System: Mac OS High Sierra v. 10.13.6;
//

#include <stdio.h>
FILE *fp;

void header(void);
int table(double);

int main(void) {
    double moneyGoal = 0;
    //should i add the numDays var here? do all var declarations need to be at the top of the document?
    // after var declarations include the fopen thing
    fp = fopen("csis.txt", "w");
    
    printf(     "What is your money savings goal? \n");
    fprintf(fp, "What is your money savings goal? \n");
    scanf("%lf", &moneyGoal);
    
    header();
    
    int numDays = table(moneyGoal);
    
    printf(     "It took %d days to accumulate at least $%.2lf \n", numDays, moneyGoal);
    fprintf(fp, "It took %d days to accumulate at least $%.2lf \n", numDays, moneyGoal);
    
    //fclose comes before return 0
    fclose(fp);
    return 0;
    
}

void header(){
    printf(     "%10s %14s %14s \n", "DAY", "DEPOSIT", "BALANCE");
    fprintf(fp, "%10s %14s %14s \n", "DAY", "DEPOSIT", "BALANCE");
    
    printf(     "%10s %14s %14s \n", "---", "-------", "-------");
    fprintf(fp, "%10s %14s %14s \n", "---", "-------", "-------");
}

int table(double goal){
    int days = 0;
    double deposit = .01;
    double balance = 0;
    
    while(balance <= goal){
        balance += deposit;
        days++;
        
        printf(     "%10d %14.2lf %14.2lf\n", days, deposit, balance);
        fprintf(fp, "%10d %14.2lf %14.2lf\n", days, deposit, balance);
        
        deposit *=2;
    }
    return days;
}
