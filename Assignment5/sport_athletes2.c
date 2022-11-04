//Benjamin Namo
//University of Western Ontario
//251182806
//CS2211B
//April 6th, 2022

#include "sport_athletes.h"

int athleteCode;
int athleteCodeArray[100];
int age;
char athleteName[50];
char athleteGender;
int j;
int countTwo=0;

void insert_athlete(athleteNode **sPtr){                            //inserting athlete function that takes in pointer to start of linked list
    
    athleteNode *newAthleteNode;                                    //creating new node
    newAthleteNode = malloc(sizeof(athleteNode));                   //dynamically allocating size of new node
    
    printf("Enter new athlete code: ");                             //requesting athlete code
    scanf("%d", &athleteCode);                                      //storing athlete code in temp variable
    
    
    if (countTwo == 100) {                                          //checking if athlete list is full
        printf("Database is full. Try editing an existing athlete.\n");
        fgetc(stdin);
        free(newAthleteNode);                                       //if full we free the space and return to start
        return;
    }
    
    if ((athleteCode<0)||(athleteCode>99)) {                        //checking if athlete code is outside the required range
        printf("Athlete code must be between 0 and 99.\n");
        fgetc(stdin);
        free(newAthleteNode);                                       //if invalid code, free the space and return to start
        return;
    }
    for(j=0; j<=countTwo;j++){                                      //checking to see if code already exists in our code array
        if (athleteCode == athleteCodeArray[j]){
            printf("Athlete code already exists.\n");
            fgetc(stdin);                                           //if it already exists, we free the space and return to start
            free(newAthleteNode);
            return;
        }
    }
    athleteCodeArray[countTwo] = athleteCode;                       //if athlete code was valid, it gets stored in our codes array at count index
        
    newAthleteNode->athleteCode = athleteCode;                      //placing athlete code in structure athlete code
    fgetc(stdin);
    
    printf("Enter athlete name: ");                                 //requesting athlete name
    fgets(newAthleteNode->athleteName,50,stdin);                    //storing athlete name
    
    for (j = 0; j<50; j++){                                         //iterating through name and clearing newline so that we can print it in the table

        if (newAthleteNode->athleteName[j] == '\n'){
        
            newAthleteNode->athleteName[j] = '\0';
        }
    }
    
    printf("Enter age of athlete: ");                              //requesting age
    scanf("%d", &age);                                             //storing age in temp variable
    
    if ((age<16)||(age>99)){                                                  //if age is invalid
        printf("Please enter an age between the values of 16 and 99.\n");     //print error message
        fgetc(stdin);                                              //clearing standard input
        free(newAthleteNode);                                      //freeing the space
        return;                                                    //restart
    }
    
    newAthleteNode->age = age;                                     //placing age in athlete structure
    fgetc(stdin);
    
    printf("Enter the gender M = Man,W = Woman,X = mixed: ");      //requesting gender
    scanf("%c", &athleteGender);                                   //storing input in gender variable
    
    if ((athleteGender == 'M')||(athleteGender == 'W')||(athleteGender == 'X')){      //checking if it is one of the valid options
        newAthleteNode->athleteGender = athleteGender;                                //storing gender variable in node if it is valid
    }
    
    
    else {                                                                                         //otherwise, if it is not valid
        fgetc(stdin);
        printf("Error: Please enter either 'M' for man, 'W' for woman, or 'X' for mixed.\n");      //print error message
        free(newAthleteNode);
        fgetc(stdin);
        return;
        
    }
    
    fgetc(stdin);
    
    newAthleteNode->nextAthletePtr = NULL;                         //new node inserted is the last node in the linked list
    
    athleteNode *currentPtr;                                       //creating current pointer that allows us to move from node to node
    currentPtr = *sPtr;                                            //without actually changing the pointer to the start of the linked list
    
    if(newAthleteNode != NULL){                                    //if we were able to create the node with sufficient memory
        
        if (currentPtr == NULL){                                   //if list is empty
            *sPtr = newAthleteNode;                                //add node to list in first position
        }
        else{                                                      //its not NULL, first item exists
            
            while (currentPtr->nextAthletePtr != NULL){            //while the current pointers next athlete pointer is not null
                currentPtr = currentPtr->nextAthletePtr;           //the current pointer is now pointing to the next node in the list, allowing us to traverse
            }
            
            if(currentPtr->nextAthletePtr == NULL){                //once we find the last item in the list, with its pointer being NULL
            currentPtr->nextAthletePtr = newAthleteNode;           //we make that pointer point to our new node,essentially adding it to the list
            }
            
        }
        
        countTwo+=1;                                               //increment count
    }
    
    else{
        printf("Memory error: Unable to add Node");                      //if we were unable to allocate memory, we print an error.
    }
    
}
           
void search_athlete(athleteNode **sPtr){                                  //function to search through linked list of athletes
    
    int searchAthlete;                                                    //variable to hold the athlete code we would like to find
    
    printf("Enter the athlete code you would like to search: ");
    scanf("%d", &searchAthlete);                                          //prompting and storing athlete code to find
    
    athleteNode *currentPtr;                                              //creating pointer to start of linked list
    currentPtr = *sPtr;
    
    if (currentPtr == NULL){                                              //if the head pointer is null, the list is empty
        printf("List is empty.");
        return;
    }
    
    else{
        
        printf("Athlete Code    Athlete Name                  Athlete Age                  Gender\n");   //print table header
        
        while (currentPtr->nextAthletePtr != NULL){                                                      //while the current pointer is not the last node in the list
            
            if(currentPtr->athleteCode == searchAthlete){                                                //if current node matches the one we want
                
                printf("      %-8d%-34s%-27d%c\n",currentPtr->athleteCode,currentPtr->athleteName,currentPtr->age,currentPtr->athleteGender);      //we print the values
                return;
            }
            
            currentPtr = currentPtr->nextAthletePtr;                                                     //then we increment the current pointer to point to the next item in the list
        }
        
        if ((currentPtr->nextAthletePtr == NULL) && (currentPtr->athleteCode == searchAthlete)){         //if the current pointer is the last and has the code we want
                
            printf("      %-8d%-34s%-27d%c\n",currentPtr->athleteCode,currentPtr->athleteName,currentPtr->age,currentPtr->athleteGender);          //we print the values
            return;
            
        }
        
        printf("Event code does not exist.");                                                           //if we cannot find the code, print error message.
    }
    
    
}

void update_athlete(athleteNode **sPtr){
    
    int updateAthlete;                                                         //variable to hold code for athlete we want to update
    
    printf("Enter the athlete code you would like to update: ");               //prompting for then storing the code we want
    scanf("%d", &updateAthlete);
    fgetc(stdin);
    
    athleteNode *currentPtr;                                                   //creating pointer to head of linked list
    currentPtr = *sPtr;
    
    if (currentPtr == NULL){                                                   //if list is empty, we print an error message and return.
        printf("List is empty.");
        return;
    }
    
    else{
        
        while (currentPtr->nextAthletePtr != NULL){                            //if list has more than one node, traversing through it
            
            if(currentPtr->athleteCode == updateAthlete){                      //if code matches, we go through same steps as insert_event function, except with currentPtr instead of newAthleteNode
                
                printf("Enter athlete name: ");                                //requesting athlete name
                fgets(currentPtr->athleteName,50,stdin);                       //storing athlete name
                
                for (j = 0; j<50; j++){                                        //iterating through name and clearing newline so that we can print it in the table

                    if (currentPtr->athleteName[j] == '\n'){
                    
                        currentPtr->athleteName[j] = '\0';
                    }
                }
                
                printf("Enter age of athlete: ");                              //requesting age
                scanf("%d", &age);                                             //storing age in temp variable
                
                if ((age<16)||(age>99)){                                                      //if age is invalid
                    printf("Please enter an age between the values of 16 and 99.\n");         //print error message
                    fgetc(stdin);                                                             //clearing standard input
                    return;                                                                   //restart
                }
                
                currentPtr->age = age;                                                        //place age in currentPtr
                fgetc(stdin);
                
                printf("Enter the gender M = Man, W = Woman, X = mixed: ");                   //requesting gender
                scanf("%c", &athleteGender);                                                  //storing input in gender variable
                
                if ((athleteGender == 'M')||(athleteGender == 'W')||(athleteGender == 'X')){  //checking if it is one of the valid options
                    currentPtr->athleteGender = athleteGender;                                //storing gender variable in node if it is valid
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
            
            currentPtr = currentPtr->nextAthletePtr;                                              //increment currentPtr to next item in the list
        }
        
        if ((currentPtr->nextAthletePtr == NULL) && (currentPtr->athleteCode == updateAthlete)){  //if current pointer is the last pointer and holds our desired event code
            
            printf("Enter athlete name: ");                                                       //requesting event name
            fgets(currentPtr->athleteName,50,stdin);                                              //storing event name
            
            for (j = 0; j<50; j++){                                                               //iterating through name and clearing newline so that we can print it in the table

                if (currentPtr->athleteName[j] == '\n'){
                
                    currentPtr->athleteName[j] = '\0';
                }
            }
            
            printf("Enter age of athlete: ");                                                     //requesting competitors
            scanf("%d", &age);                                                                    //storing competitors in temp variable
            
            if ((age<16)||(age>99)){                                                              //if # of competitors is invalid
                printf("Please enter an age between 16 and 99.\n");                               //print error message
                fgetc(stdin);                                                                     //clearing standard input
                return;                                                                           //restart
            }
            
            currentPtr->age = age;                                                                //placing competitors in structure event code
            fgetc(stdin);
            
            printf("Enter the gender M = Man ,W = Woman ,X = mixed: ");                           //requesting gender
            scanf("%c", &athleteGender);                                                          //storing input in gender variable
            
            if ((athleteGender == 'M')||(athleteGender == 'W')||(athleteGender == 'X')){          //checking if it is one of the valid options
                currentPtr->athleteGender = athleteGender;                                        //storing gender variable in node if it is valid
            }
            
            else {                                                                                 //otherwise, if it is not valid
                fgetc(stdin);
                printf("Error: Please enter either 'M' for man, 'W' for woman, or 'X' for mixed.\n");      //print error message
                fgetc(stdin);
                return;
                
            }
            
            fgetc(stdin);
            
            return;
            
        }
        
        printf("Athlete code does not exist.");                                //if event code does not exist, print an error message.
    }
    
}
           
void print_athlete(athleteNode **sPtr){                                        //function to print an event
    
    athleteNode *currentPtr;                                                   //create pointer to head of linked list
    currentPtr = *sPtr;
    
    if (currentPtr == NULL){                                                   //if list is empty, print an error message.
        printf("List is empty.");
    }
    
    else{
        
        printf("Athlete Code    Athlete Name                  Athlete Age                  Gender\n");  //print table header
        
        while (currentPtr->nextAthletePtr != NULL){                                                                                             //if there is a next item in the list
            
            printf("      %-12d%-33s%-27d%c\n",currentPtr->athleteCode,currentPtr->athleteName,currentPtr->age,currentPtr->athleteGender);      //print the current item
            currentPtr = currentPtr->nextAthletePtr;                                                                                            //then the next item becomes the current item
        }
        printf("      %-12d%-33s%-27d%c\n",currentPtr->athleteCode,currentPtr->athleteName,currentPtr->age,currentPtr->athleteGender);          //if we are at the end of the list, print that item too (since it has no next)
    }
    
    
}
            
void erase_athlete(athleteNode **sPtr){                                             //function to erase a node in our linked list
    
    int athleteToDelete;                                                            //variable to hold the event code we wish to delete
    
    printf("Enter the code of the athlete you would like to delete: ");             //prompt for code
    scanf("%d",&athleteToDelete);                                                   //store code in code variable
    
    athleteNode *currentPtr;                                                        //create node pointer
    currentPtr = *sPtr;                                                             //make node pointer point to first node (our input)
    athleteNode *previousPtr;                                                       //create a previous node pointer as well
    
    if (currentPtr != NULL && currentPtr->athleteCode == athleteToDelete){          //if current pointer, the starting pointer isnt null and has the code
        
        *sPtr = currentPtr->nextAthletePtr;                                         //change the next item to the starting item
        free(currentPtr);                                                           //free memory of old item
            
    }
    
    while (currentPtr != NULL && currentPtr->athleteCode != athleteToDelete){       //if starting pointer does not hold the code, iterate through until the event BEFORE the event we want
        previousPtr = currentPtr;                                                   //once we find that event, we set the previous pointer to it
        currentPtr = currentPtr->nextAthletePtr;                                    //then the currentPtr becomes the actual event we wish to delete
    }
    
    if (currentPtr == NULL){                                                        //if code wasnt found, we print an error message and return to start
        printf("Athlete code not found.");
        return;
    }
    
    previousPtr->nextAthletePtr = currentPtr->nextAthletePtr;                       //otherwise, the previous pointer is now linked to the event AFTER the event we wish to delete
    free(currentPtr);                                                               //and we free the memory of the one we wish to delete, essentially erasing it from the chain
        
    
}
           
