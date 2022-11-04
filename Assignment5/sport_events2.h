//Benjamin Namo
//University of Western Ontario
//251182806
//CS2211B
//April 6th, 2022

#include <stdio.h>


struct eventNode{             //declaring struct for event
    
    int eventCode;            //declaring int variable for eventCode, each event code must be unique
    char eventName[50];       //declaring char arrray for type of sport, with a size limit of 50 including null character
    int competitors;          //declaring int variable for number of competitors in the event
    char gender;              //declaring char variable for gender competiting, options are 'M'(male) 'F'(female) 'X'(mixed)
    struct eventNode *nextEventPtr; //declaring pointer to next event in linked list
};
typedef struct eventNode eventNode;


extern void insert_event(eventNode **sPtr);
          
extern void search_event(eventNode **sPtr);
     
extern void update_event(eventNode **sPtr);
      
extern void print_event(eventNode **sPtr);
           
extern void erase_event(eventNode **sPtr);

extern void fetch_eventcodes(int array[100]);
