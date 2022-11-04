//Benjamin Namo//
//CS2211B 2022//
//Assignment 04//
//251182806//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    
    printf("*************************\n");
    printf("* 2211 Winter Olympics! *\n");
    printf("*************************\n");
    
    char opCode = ' ';            //operation code variable
    int count = 0;                //variable to keep track of where we store the events in the event array, start at index 0
    int tempEventCode;            //variable to temporarily hold event code, in order to check if valid
    int tempCompetitors;          //variable to temporarily hold amount of competitors, in order to check if valid
    char tempGender;              //variable to temporarily hold gender, in order to check if it is valid
    int i,j;                      //iteration variables
    
    struct event {                //declaring struct for event
        int eventCode;            //declaring int variable for eventCode, each event code must be unique
        char eventName[50];       //declaring char arrray for type of sport, with a size limit of 50 including null character
        int competitors;          //declaring int variable for number of competitors in the event
        char gender;              //declaring char variable for gender competiting, options are 'M'(male) 'F'(female) 'X'(mixed)
    };
    
    struct event allEvents[100];  //declaring an array of structs to hold all the events
    
LOOP:
    
    while(opCode != 'q') {

        printf("\nEnter operation code: ");                                     //requesting operation code
        scanf("\n%c",&opCode);                                                  //storing input ('i'= new event, 's'= search database of events,
                                                                                // 'u' = update event, 'p'= print list of events 'q'= quit
        if (opCode == 'i') {                                                    //if operation code is i, then we are creating a new event
            
            printf("Enter event code: ");
            scanf("\n%d",&tempEventCode);                                       //storing event code in a temporary variable
            
            for (i = 0; i<=count; i++) {                                        //iterating through the events array (up to count so we avoid empty indexes)
                
                if ((allEvents[i].eventCode == tempEventCode)&&(allEvents[i].eventCode != 0)) {  
										//if the event code is already found to exist at index and if the event code isnt 0 (to deal with a small glitch when 0)
                    printf("Event already exists.\n");                          //print error message
                
                    fgetc(stdin);                                               //clear standard input
                    goto LOOP;                                                  //restart loop
                }
            }
            
            if (count == 100) {                                                 //checking if events array is full
                printf("Database is full. Try editing an existing event.\n");
                fgetc(stdin);
                goto LOOP;
            }
            
            if ((tempEventCode<0)||(tempEventCode>99)) {                        //checking if event code is outside the required range
                printf("Event code must be between 0 and 99.\n");
                fgetc(stdin);
                goto LOOP;
            }
            
            
            allEvents[count].eventCode = tempEventCode;                         //finally, if all tests pass, assign temporary eventcode to the actual eventcode variable in the struct
            fgetc(stdin);                                                       //clear standard input

            printf("Enter event name: ");
            fgets(allEvents[count].eventName, 50, stdin);                       //using fgets to take in event name, this doesnt need to be tested since events can have the same name
        
            for (i = 0; i<50; i++) {                                            //here, since fgets also takes in the '\n\ after an input, we are swapping it with '\0' or end of word.
                if (allEvents[count].eventName[i] == '\n'){
                    allEvents[count].eventName[i] = '\0';
                }
            }
        
            printf("Enter number of competitors: ");
            scanf("\n%d", &tempCompetitors);                                                          //storing number of competitors in a temp variable to check if valid
            
            if ((tempCompetitors<10)||(tempCompetitors>99)){                                          //if # of competitors is invalid
                printf("Please enter an amount of competitors between the values of 10 and 99.\n");   //print error message
                allEvents[count].eventCode=1000;                                                      //setting event code to a high number, or "clearing" it, not sure why this works
                fgetc(stdin);                                                                         //clearing standard input
                goto LOOP;                                                                            //restart
            }
            allEvents[count].competitors = tempCompetitors;                                           //otherwise, if temp competitor count is valid, store it in the event
            fgetc(stdin);
        
            
            printf("Enter gender ('M' for mens, 'W' for womens 'X' for mixed: ");
            scanf("%c",&tempGender);                                                                  //storing gender char in a temp variable
            
            if ((tempGender == 'M')||(tempGender == 'W')||(tempGender == 'X')){                       //checking if it is one of the valid options
                allEvents[count].gender = tempGender;                                                 //if it is, then set the events gender to it
            }
            
            else {                                                                                    //otherwise, if it is not valid
                fgetc(stdin);
                printf("Please enter either 'M' for mens, 'W' for womens, or 'X' for mixed.\n");      //print error message
                allEvents[count].eventCode=1000;                                                      //get rid of events code
                goto LOOP;                                                                            //restart
                
            }
                                           
            fgetc(stdin);                                                                             //clearing stdin
            count += 1;                                                                               //incrementing count to move on to the next index in the events array
        
        }
        
        if (opCode == 's'){                                                                           //if operation code is for searching
            
            printf("Enter event code: ");
            scanf("%d",&tempEventCode);                                                               //storing event code in temp variable
                
            for (i = 0; i<=count; i++){                                                               //iterating through eventArray (until count) to find if it exists
                
                if (allEvents[i].eventCode == tempEventCode){                                         //if it exists, print the event similar to 'p' operation
                    
                    printf("Event Code    Event Name                  Competitors                  Gender\n");
                    printf("      %-8d%-34s%-27d%c\n",allEvents[i].eventCode,allEvents[i].eventName,allEvents[i].competitors,allEvents[i].gender);
                    
                    fgetc(stdin);                                                                     //clear standard input
                    goto LOOP;                                                                        //restart loop
                    
                }
                
            }
            
            printf("Event code not found. Please enter a valid event code.\n");                       //otherwise, if event code is not found, print error message
            goto LOOP;                                                                                //then restart
            
        }
        
        if (opCode == 'u'){                                                                           //if 'u', or update event
            
            printf("Enter event code: ");
            scanf("\n%d",&tempEventCode);                                                             //store entered event code in a variable
            
            for (i = 0; i<=count; i++) {                                                              //iterating through events to search for eventcode
                
                if (allEvents[i].eventCode == tempEventCode) {                                        //if we do find the event exists, go through same steps as operation code 'i'
                                                                                                      //see operation code i (line 33)
                    fgetc(stdin);
                    printf("Enter event name: ");
                    fgets(allEvents[i].eventName, 50, stdin);                                         //minor difference, in all of 'u', we are using i as the index and not count
                
                    for (j = 0; j<50; j++){
            
                        if (allEvents[i].eventName[j] == '\n'){
                        
                            allEvents[i].eventName[j] = '\0';
                        }
                    }
                
                    printf("Enter number of competitors: ");                                           //inputing number of competitors, same as i, except now using i as index
                    scanf("\n%d", &tempCompetitors);
                    
                    if ((tempCompetitors<10)||(tempCompetitors>99)){                                   //same error as i
                        printf("Please enter an amount of competitors between the values of 10 and 99.\n");
                        fgetc(stdin);
                        goto LOOP;
                    }
                    allEvents[i].competitors = tempCompetitors;
                    fgetc(stdin);
                
                    
                    printf("Enter gender ('M' for mens, 'W' for womens, 'X' for mixed: ");             //inputing gender, same as i, except now using i as index
                    scanf("%c",&tempGender);
                    
                    if ((tempGender == 'M')||(tempGender == 'W')||(tempGender == 'X')){
                        allEvents[i].gender = tempGender;
                    }
                    else{                                                                              //same error as i
                        
                        fgetc(stdin);
                        printf("Please enter either 'M' for mens, 'W' for womens, or 'X' for mixed.\n");
                        goto LOOP;
                        
                    }
                    fgetc(stdin);
                
                    goto LOOP;                                                                         //after updating, restart
                    
                }
            }
            
                printf("This event does not exist. Try creating it yourself.\n");                      //if event doesnt exist, give error
                fgetc(stdin);                                                                          //clear stdin
                goto LOOP;                                                                             //restart loop
            }
        
            
        
    
        
        
        if (opCode == 'p') {                          						       //if op code is p or print
            
            printf("Event Code    Event Name                  Competitors                  Gender\n"); //print table header
            
            for (i = 0; i<=count-1; i++){                      				               //iterate through eventarray indexes and print events, sufficiently spaced.
                
                printf("      %-8d%-34s%-27d%c\n",allEvents[i].eventCode,allEvents[i].eventName,allEvents[i].competitors,allEvents[i].gender);
                
            }
            
        }
        
        if (opCode == 'q'){                            						       //if op code is q or quit
            break;                                      					       //quit
        }
    }
}


