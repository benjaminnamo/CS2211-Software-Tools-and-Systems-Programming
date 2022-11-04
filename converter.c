//Converter.c
//This program converts an input with a chosen unit of measurement to a different unit of measurement.
//Benjamin Namo
//251182806
//Feb 9 2022

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main(void){
    
    bool chosen = false; //bool for checking if they have picked an input number
    int num = 0;    //variable for input number
    char letter;    //varaible for input character
    float value = 0.0;  //variable for value input
    
    do {    //do loop so that we can return to the main menu after getting a conversion
        
        while (!chosen) {   //while they have not picked a valid number, or chosen is false
        
            printf("Please enter a number.\n1 for conversion between Kilometre and Mile\n2 for conversion between Litres and Gallons\n3 for conversion between Hectares and Acres\n4 for conversion between Kilograms and Pounds\n5 for quit\n");
    
            scanf("%d", &num);  //storing input at address of number variable
        
            if (num<=5){    //if number is valid
                chosen = true;  //chosen becomes true, so that it wont run again
            }
        }
    
                            //these are be the same throughout all options of num 1-5, so i will only do comments for the first
        if (num==1){
            chosen = false; //setting chosen to false again, so that we can choose a new number once the loop restarts
        
            printf("You chose conversion between Kilometre and Mile.\nFor Kilometers to Miles, enter K.\nFor Miles to Kilometers, enter M.\n");
            scanf("\n%c",&letter); //storing chosen letter at address of letter
        
            if(letter=='K'){
        
                printf("Enter your value in Kilometers: ");
                scanf("%f",&value); //storing chosen value at address of value
            
                printf("%s%.2f%s\n", "Your conversion is: ", (value*0.621371)," Miles\n"); //converting and printing value to other unit

        }
        
            if(letter=='M'){
            
                printf("Enter your value in Miles: ");
                scanf("%f",&value);
            
                printf("%s%.2f%s\n", "Your conversion is: ", (value/0.621371)," Miles\n");
            }
            
        }
    
        if(num==2){
            chosen = false;
        
            printf("You chose conversion between Litre and Gallon.\nFor Litres to Gallons, enter L.\nFor Gallons to Litres, enter G.\n");
            scanf("\n%c",&letter);
        
            if(letter=='L'){
        
                printf("Enter your value in Litres: ");
                scanf("%f",&value);
            
                printf("%s%.2f%s\n", "Your conversion is: ", (value*0.264172)," Gallons\n");
            
            }
        
            if(letter=='G'){
            
                printf("Enter your value in Gallons: ");
                scanf("%f",&value);
            
                printf("%s%.2f%s\n", "Your conversion is: ", (value/0.264172)," Litres\n");
            }
        }
    
        if(num==3){
            chosen = false;
        
            printf("You chose conversion between Hectares and Acres.\nFor Hectars to Acres, enter H.\nFor Aces to Hectares, enter A.\n");
            scanf("\n%c",&letter);
        
            if(letter=='H'){
        
                printf("Enter your value in Hectares: ");
                scanf("%f",&value);
            
                printf("%s%.2f%s\n", "Your conversion is: ", (value*2.47105)," Acres\n");
            
            }
        
            if(letter=='A'){
            
                printf("Enter your value in Acres: ");
                scanf("%f",&value);
            
                printf("%s%.2f%s\n", "Your conversion is: ", (value/2.47105)," Hectars\n");
            }
        }
    
        if (num==4){
            chosen = false;
        
            printf("You chose conversion between Kilograms and Pounds.\nFor Kilograms to Pounds, enter K.\nFor Pounds to Kilograms, enter P.\n");
            scanf("\n%c",&letter);
        
            if(letter=='K'){
        
                printf("Enter your value in Kilograms: ");
                scanf("%f",&value);
            
                printf("%s%.2f%s\n", "Your conversion is: ", (value*2.20462)," Pounds\n");
            
            }
        
            if(letter=='P'){
            
                printf("Enter your value in Pounds: ");
                scanf("%f",&value);
            
                printf("%s%.2f%s\n", "Your conversion is: ", (value/2.20462)," Kilograms\n");
            }
        }
    
        if (num==5){ //if number is five, then quit.
            chosen = false;
    
            exit(0);
            
        }
    }
    while(true);
}


