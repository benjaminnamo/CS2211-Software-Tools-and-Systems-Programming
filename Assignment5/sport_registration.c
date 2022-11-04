//Benjamin Namo
//University of Western Ontario
//251182806
//CS2211B
//April 6th, 2022

#include "sport_registration.h"
#include <stdio.h>
#include <stdlib.h>

int registrationCode;
int registrationCodeArray[100];
int registrationEventCode;
int registrationAthleteCode;
int k;
int countThree=0;

void insert_registration(registrationNode **sPtr,int eventCode[100]){
    
    registrationNode *newRegistrationNode;
    newRegistrationNode = malloc(sizeof(registrationNode));
    
    printf("Enter registration code: ");
    scanf("%d", &registrationCode);
    
    
    if (countThree == 100) {
        printf("Database is full. Try editing an existing athlete.\n");
        fgetc(stdin);
        free(newRegistrationNode);
        return;
    }
    
    if ((registrationCode<0)||(registrationCode>99)) {
        printf("Registraion code must be between 0 and 99.\n");
        fgetc(stdin);
        free(newRegistrationNode);
        return;
    }
    for(k=0; k<=countThree;k++){
        if (registrationCode == registrationCodeArray[k]){
            printf("Registration code already exists.\n");
            fgetc(stdin);
            free(newRegistrationNode);
            return;
        }
    }
    registrationCodeArray[countThree] = registrationCode;
        
    newRegistrationNode->registrationCode = registrationCode;
    fgetc(stdin);
    
    
    printf("Enter event code: ");
    scanf("%d", &registrationEventCode);
    
    for (k=0;k<=100;k++){
        if(eventCode[k] == registrationEventCode){
            newRegistrationNode->registrationEventCode = registrationEventCode;
        }
        if((k=100)&&eventCode[k]!=registrationCode){
            printf("Event does not exist.");
            return;
        }
    }
    
    fgetc(stdin);
    
    printf("Enter athlete code: ");
    scanf("%d", &registrationAthleteCode);
    
    newRegistrationNode->registrationAthleteCode = registrationAthleteCode;
    fgetc(stdin);
    
    newRegistrationNode->nextRegistrationPtr = NULL;
    
    registrationNode *currentPtr;
    currentPtr = *sPtr;
    
    if(newRegistrationNode != NULL){
        
        if (currentPtr == NULL){
            *sPtr = newRegistrationNode;
        }
        else{
            
            while (currentPtr->nextRegistrationPtr != NULL){
                currentPtr = currentPtr->nextRegistrationPtr;
            }
            
            if(currentPtr->nextRegistrationPtr == NULL){
            currentPtr->nextRegistrationPtr = newRegistrationNode;
            }
            
        }
        
        countThree+=1;
    }
    
    else{
        printf("Memory error: Unable to add Node");
    }
    
}
           
void search_registration(registrationNode **sPtr){
    
    int searchRegistration;
    printf("Enter the Registration code you would like to search: ");
    scanf("%d", &searchRegistration);
    
    registrationNode *currentPtr;
    currentPtr = *sPtr;
    
    if (currentPtr == NULL){
        printf("List is empty.");
        return;
    }
    
    else{
        
        printf("Registration Code    Event Number                  Athlete Code\n");
        
        while (currentPtr->nextRegistrationPtr != NULL){                                                      //while the current pointer is not the last node in the list
            
            if(currentPtr->registrationCode == searchRegistration){                                                //if current node matches the one we want
                
                printf("       %-20d%-29d%-24d\n",currentPtr->registrationCode,currentPtr->registrationEventCode,currentPtr->registrationAthleteCode);      //we print the values
                return;
            }
            
            currentPtr = currentPtr->nextRegistrationPtr;                                                     //then we increment the current pointer to point to the next item in the list
        }
        
        if ((currentPtr->nextRegistrationPtr == NULL) && (currentPtr->registrationCode == searchRegistration)){         //if the current pointer is the last and has the code we want
                
            printf("       %-20d%-29d%-24d\n",currentPtr->registrationCode,currentPtr->registrationEventCode,currentPtr->registrationAthleteCode);      //we print the values
            return;
        }
        
        printf("Event code does not exist.");                                                           //if we cannot find the code, print error message.
    }
    
    
}

void update_registration(registrationNode **sPtr, int eventCode[100] ){
    
    int updateRegistraion;
    
    printf("Enter the registration code you would like to update: ");
    scanf("%d", &updateRegistraion);
    fgetc(stdin);
    
    registrationNode *currentPtr;
    currentPtr = *sPtr;
    
    if (currentPtr == NULL){
        printf("List is empty.");
        return;
    }
    
    else{
        
        while (currentPtr->nextRegistrationPtr != NULL){
            
            if(currentPtr->registrationCode == updateRegistraion){
                
               
                //do the same thing as insert function
                
                
                fgetc(stdin);
                return;
            }
            
            currentPtr = currentPtr->nextRegistrationPtr;
        }
        
        if ((currentPtr->nextRegistrationPtr == NULL) && (currentPtr->registrationCode == updateRegistraion)){
            
            //do the same thing
            
            fgetc(stdin);
            
            return;
            
        }
        
        printf("Registration code does not exist.");
    }
    
}
           
void print_registration(registrationNode **sPtr){
    
    registrationNode *currentPtr;
    currentPtr = *sPtr;
    
    if (currentPtr == NULL){
        printf("List is empty.");
    }
    
    else{
        
        printf("Registration Code    Event Number                  Athlete Code\n");
        
        while (currentPtr->nextRegistrationPtr != NULL){
            
            printf("       %-20d%-29d%-24d\n",currentPtr->registrationCode,currentPtr->registrationEventCode,currentPtr->registrationAthleteCode);
            currentPtr = currentPtr->nextRegistrationPtr;
        }
        printf("       %-20d%-29d%-24d\n",currentPtr->registrationCode,currentPtr->registrationEventCode,currentPtr->registrationAthleteCode);                
    }
    
    
}
            
void erase_registration(registrationNode **sPtr){                                             //function to erase a node in our linked list
    
    int registrationToDelete;                                                            //variable to hold the event code we wish to delete
    
    printf("Enter the code of the registration you would like to delete: ");             //prompt for code
    scanf("%d",&registrationToDelete);                                                   //store code in code variable
    
    registrationNode *currentPtr;                                                        //create node pointer
    currentPtr = *sPtr;                                                             //make node pointer point to first node (our input)
    registrationNode *previousPtr;                                                       //create a previous node pointer as well
    
    if (currentPtr != NULL && currentPtr->registrationCode == registrationToDelete){          //if current pointer, the starting pointer isnt null and has the code
        
        *sPtr = currentPtr->nextRegistrationPtr;                                         //change the next item to the starting item
        free(currentPtr);                                                           //free memory of old item
            
    }
    
    while (currentPtr != NULL && currentPtr->registrationCode != registrationToDelete){       //if starting pointer does not hold the code, iterate through until the event BEFORE the event we want
        previousPtr = currentPtr;                                                   //once we find that event, we set the previous pointer to it
        currentPtr = currentPtr->nextRegistrationPtr;                                    //then the currentPtr becomes the actual event we wish to delete
    }
    
    if (currentPtr == NULL){                                                        //if code wasnt found, we print an error message and return to start
        printf("Registration code not found.");
        return;
    }
    
    previousPtr->nextRegistrationPtr = currentPtr->nextRegistrationPtr;                       //otherwise, the previous pointer is now linked to the event AFTER the event we wish to delete
    free(currentPtr);                                                               //and we free the memory of the one we wish to delete, essentially erasing it from the chain
        
    
}
           
