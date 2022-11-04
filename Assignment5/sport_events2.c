//Benjamin Namo
//University of Western Ontario
//251182806
//CS2211B
//April 6th, 2022

#include "sport_events.h"
#include <stdio.h>
#include <stdlib.h>

int eventCode;
int eventCodeArray[100];
int competitors;
char eventName[50];
char gender;
int i;
int count=0;

void insert_event(eventNode **sPtr){                            //inserting event function that takes in pointer to start of linked list
    
    eventNode *newEventNode;                                    //creating new node
    newEventNode = malloc(sizeof(eventNode));                   //dynamically allocating size of new node
    
    printf("Enter new event code: ");                           //requesting event code
    scanf("%d", &eventCode);                                    //storing event code in temp variable
    
    
    if (count == 100) {                                         //checking if events list is full
        printf("Database is full. Try editing an existing event.\n");
        fgetc(stdin);
        free(newEventNode);                                     //if full we free the space and return to start
        return;
    }
    
    if ((eventCode<0)||(eventCode>99)) {                        //checking if event code is outside the required range
        printf("Event code must be between 0 and 99.\n");
        fgetc(stdin);
        free(newEventNode);                                     //if invalid code, free the space and return to start
        return;
    }
    for(i=0; i<=count;i++){                                     //checking to see if code already exists in our code array
        if (eventCode == eventCodeArray[i]){
            printf("Event code already exists.\n");
            fgetc(stdin);                                       //if it already exists, we free the space and return to start
            free(newEventNode);
            return;
        }
    }
    eventCodeArray[count] = eventCode;                           //if event code was valid, it gets stored in our codes array at count index
        
    newEventNode->eventCode = eventCode;                         //placing event code in structure event code
    fgetc(stdin);
    
    printf("Enter event name: ");                                //requesting event name
    fgets(newEventNode->eventName,50,stdin);                     //storing event name
    
    for (i = 0; i<50; i++){                                      //iterating through name and clearing newline so that we can print it in the table

        if (newEventNode->eventName[i] == '\n'){
        
            newEventNode->eventName[i] = '\0';
        }
    }
    
    printf("Enter number of competitors: ");                     //requesting competitors
    scanf("%d", &competitors);                                   //storing competitors in temp variable
    
    if ((competitors<10)||(competitors>99)){                                                  //if # of competitors is invalid
        printf("Please enter an amount of competitors between the values of 10 and 99.\n");   //print error message
        fgetc(stdin);                                                                         //clearing standard input
        free(newEventNode);                                                                   //freeing the space
        return;                                                                               //restart
    }
    
    newEventNode->competitors = competitors;                     //placing competitors in structure event code
    fgetc(stdin);
    
    printf("Enter the gender M = Mens,W = Womens,X = mixed: ");  //requesting gender
    scanf("%c", &gender);                                        //storing input in gender variable
    
    if ((gender == 'M')||(gender == 'W')||(gender == 'X')){      //checking if it is one of the valid options
        newEventNode->gender = gender;                           //storing gender variable in node if it is valid
    }
    
    else {                                                                                           //otherwise, if it is not valid
        fgetc(stdin);
        printf("Error: Please enter either 'M' for mens, 'W' for womens, or 'X' for mixed.\n");      //print error message
        free(newEventNode);
        fgetc(stdin);
        return;
        
    }
    
    fgetc(stdin);
    
    newEventNode->nextEventPtr = NULL;                           //new node inserted is the last node in the linked list
    
    eventNode *currentPtr;                                       //creating current pointer that allows us to move from node to node
    currentPtr = *sPtr;                                          //without actually changing the pointer to the start of the linked list
    
    if(newEventNode != NULL){                                    //if we were able to create the node with sufficient memory
        
        if (currentPtr == NULL){                                 //if list is empty
            *sPtr = newEventNode;                                //add node to list in first position
        }
        else{                                                    //its not NULL, first item exists
            
            while (currentPtr->nextEventPtr != NULL){           //while the current pointers nextEvent is not null
                currentPtr = currentPtr->nextEventPtr;          //the current pointer is now pointing to the next node in the list, allowing us to traverse
            }
            
            if(currentPtr->nextEventPtr == NULL){               //once we find the last item in the list, with its pointer being NULL
            currentPtr->nextEventPtr = newEventNode;            //we make that pointer point to our new node,essentially adding it to the list
            }
            
        }
        
        count+=1;                                               //increment count
    }
    
    else{
        printf("Memory error: Unable to add Node");                           //if we were unable to allocate memory, we print an error.
    }
    
}
           
void search_event(eventNode **sPtr){                                          //function to search through linked list of events
    
    int searchEvent;                                                          //variable to hold the event code we would like to find
    
    printf("Enter the event code you would like to search: ");
    scanf("%d", &searchEvent);                                                //prompting and storing event code to find
    
    eventNode *currentPtr;                                                    //creating pointer to start of linked list
    currentPtr = *sPtr;
    
    if (currentPtr == NULL){                                                  //if the head pointer is null, the list is empty
        printf("List is empty.");
        return;
    }
    
    else{
        
        printf("Event Code    Event Name                  Competitors                  Gender\n");  //print table header
        
        while (currentPtr->nextEventPtr != NULL){                                                   //while the current pointer is not the last node in the list
            
            if(currentPtr->eventCode == searchEvent){                                               //if current node matches the one we want
                
                printf("      %-8d%-34s%-27d%c\n",currentPtr->eventCode,currentPtr->eventName,currentPtr->competitors,currentPtr->gender);      //we print the values
                return;
            }
            
            currentPtr = currentPtr->nextEventPtr;                                                  //then we increment the current pointer to point to the next item in the list
        }
        
        if ((currentPtr->nextEventPtr == NULL) && (currentPtr->eventCode == searchEvent)){          //if the current pointer is the last and has the code we want
                
            printf("      %-8d%-34s%-27d%c\n",currentPtr->eventCode,currentPtr->eventName,currentPtr->competitors,currentPtr->gender);  //print it
            return;
            
        }
        
        printf("Event code does not exist.");                                                       //if we cannot find the code, print error message.
    }
    
    
}

void update_event(eventNode **sPtr){
    
    int updateEvent;                                                         //variable to hold code for event we want to update
    
    printf("Enter the event code you would like to update: ");               //prompting for then storing the code we want
    scanf("%d", &updateEvent);
    fgetc(stdin);
    
    eventNode *currentPtr;                                                   //creating pointer to head of linked list
    currentPtr = *sPtr;
    
    if (currentPtr == NULL){                                                 //if list is empty, we print an error message and return.
        printf("List is empty.");
        return;
    }
    
    else{
        
        while (currentPtr->nextEventPtr != NULL){                            //if list has more than one node, traversing through it
            
            if(currentPtr->eventCode == updateEvent){                        //if code matches, we go through same steps as insert_event function, except with currentPtr instead of newEventNode
                
                printf("Enter event name: ");                                //requesting event name
                fgets(currentPtr->eventName,50,stdin);                       //storing event name
                
                for (i = 0; i<50; i++){                                      //iterating through name and clearing newline so that we can print it in the table

                    if (currentPtr->eventName[i] == '\n'){
                    
                        currentPtr->eventName[i] = '\0';
                    }
                }
                
                printf("Enter number of competitors: ");                     //requesting competitors
                scanf("%d", &competitors);                                   //storing competitors in temp variable
                
                if ((competitors<10)||(competitors>99)){                                                  //if # of competitors is invalid
                    printf("Please enter an amount of competitors between the values of 10 and 99.\n");   //print error message
                    fgetc(stdin);                                                                         //clearing standard input
                    return;                                                                               //restart
                }
                
                currentPtr->competitors = competitors;                       //place competitors in currentPtr
                fgetc(stdin);
                
                printf("Enter the gender M = Mens,W = Womens,X = mixed: ");  //requesting gender
                scanf("%c", &gender);                                        //storing input in gender variable
                
                if ((gender == 'M')||(gender == 'W')||(gender == 'X')){      //checking if it is one of the valid options
                    currentPtr->gender = gender;                             //storing gender variable in node if it is valid
                }
                
                else {                                                                                           //otherwise, if it is not valid
                    fgetc(stdin);
                    printf("Error: Please enter either 'M' for mens, 'W' for womens, or 'X' for mixed.\n");      //print error message
                    fgetc(stdin);
                    return;
                    
                }
                
                fgetc(stdin);
                
                return;
            }
            
            currentPtr = currentPtr->nextEventPtr;                           //increment currentPtr to next item in the list
        }
        
        if ((currentPtr->nextEventPtr == NULL) && (currentPtr->eventCode == updateEvent)){  //if current pointer is the last pointer and holds our desired event code
            
            printf("Enter event name: ");                                    //requesting event name
            fgets(currentPtr->eventName,50,stdin);                           //storing event name
            
            for (i = 0; i<50; i++){                                          //iterating through name and clearing newline so that we can print it in the table

                if (currentPtr->eventName[i] == '\n'){
                
                    currentPtr->eventName[i] = '\0';
                }
            }
            
            printf("Enter number of competitors: ");                         //requesting competitors
            scanf("%d", &competitors);                                       //storing competitors in temp variable
            
            if ((competitors<10)||(competitors>99)){                                                  //if # of competitors is invalid
                printf("Please enter an amount of competitors between the values of 10 and 99.\n");   //print error message
                fgetc(stdin);                                                                         //clearing standard input
                return;                                                                               //restart
            }
            
            currentPtr->competitors = competitors;                           //placing competitors in structure event code
            fgetc(stdin);
            
            printf("Enter the gender M = Mens,W = Womens,X = mixed: ");      //requesting gender
            scanf("%c", &gender);                                            //storing input in gender variable
            
            if ((gender == 'M')||(gender == 'W')||(gender == 'X')){          //checking if it is one of the valid options
                currentPtr->gender = gender;                                 //storing gender variable in node if it is valid
            }
            
            else {                                                           //otherwise, if it is not valid
                fgetc(stdin);
                printf("Error: Please enter either 'M' for mens, 'W' for womens, or 'X' for mixed.\n");      //print error message
                fgetc(stdin);
                return;
                
            }
            
            fgetc(stdin);
            
            return;
            
        }
        
        printf("Event code does not exist.");                                //if event code does not exist, print an error message.
    }
    
}
           
void print_event(eventNode **sPtr){                                          //function to print an event
    
    eventNode *currentPtr;                                                   //create pointer to head of linked list
    currentPtr = *sPtr;
    
    if (currentPtr == NULL){                                                 //if list is empty, print an error message.
        printf("List is empty.");
    }
    
    else{
        
        printf("Event Code    Event Name                  Competitors                  Gender\n");  //print table header
        
        while (currentPtr->nextEventPtr != NULL){                                                                                           //if there is a next item in the list
            
            printf("      %-8d%-34s%-27d%c\n",currentPtr->eventCode,currentPtr->eventName,currentPtr->competitors,currentPtr->gender);      //print the current item
            currentPtr = currentPtr->nextEventPtr;                                                                                          //then the next item becomes the current item
        }
        printf("      %-8d%-34s%-27d%c\n",currentPtr->eventCode,currentPtr->eventName,currentPtr->competitors,currentPtr->gender);          //if we are at the end of the list, print that item too (since it has no next)
    }
    
    
}
            
void erase_event(eventNode **sPtr){                                             //function to erase a node in our linked list
    
    int eventToDelete;                                                          //variable to hold the event code we wish to delete
    
    printf("Enter the code of the event you would like to delete: ");           //prompt for code
    scanf("%d",&eventToDelete);                                                 //store code in code variable
    
    eventNode *currentPtr;                                                      //create node pointer
    currentPtr = *sPtr;                                                         //make node pointer point to first node (our input)
    eventNode *previousPtr;                                                     //create a previous node pointer as well
    
    if (currentPtr != NULL && currentPtr->eventCode == eventToDelete){          //if current pointer, the starting pointer isnt null and has the code
        
        *sPtr = currentPtr->nextEventPtr;                                       //change the next item to the starting item
        free(currentPtr);                                                       //free memory of old item
            
    }
    
    while (currentPtr != NULL && currentPtr->eventCode != eventToDelete){       //if starting pointer does not hold the code, iterate through until the event BEFORE the event we want
        previousPtr = currentPtr;                                               //once we find that event, we set the previous pointer to it
        currentPtr = currentPtr->nextEventPtr;                                  //then the currentPtr becomes the actual event we wish to delete
    }
    
    if (currentPtr == NULL){                                                    //if code wasnt found, we print an error message and return to start
        printf("Event code not found.");
        return;
    }
    
    previousPtr->nextEventPtr = currentPtr->nextEventPtr;                       //otherwise, the previous pointer is now linked to the event AFTER the event we wish to delete
    free(currentPtr);                                                           //and we free the memory of the one we wish to delete, essentially erasing it from the chain
        
    
}

void fetch_eventcodes(int array[100]){
    
    for (i=0;i<=count;i++){
        array[i] = eventCodeArray[i];
    }
    
}
           
