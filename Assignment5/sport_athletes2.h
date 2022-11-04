//Benjamin Namo
//University of Western Ontario
//251182806
//CS2211B
//April 6th, 2022

#include <stdio.h>
#include <stdlib.h>

struct athleteNode{             //declaring struct for event
    
    int athleteCode;            //declaring int variable for eventCode, each event code must be unique
    char athleteName[50];       //declaring char arrray for type of sport, with a size limit of 50 including null character
    int age;                    //declaring int variable for number of competitors in the event
    char athleteGender;                //declaring char variable for gender competiting, options are 'M'(male) 'F'(female) 'X'(mixed)
    struct athleteNode *nextAthletePtr; //declaring pointer to next event in linked list
};
typedef struct athleteNode athleteNode;


extern void insert_athlete(athleteNode **sPtr);
          
extern void search_athlete(athleteNode **sPtr);
     
extern void update_athlete(athleteNode **sPtr);
      
extern void print_athlete(athleteNode **sPtr);
           
extern void erase_athlete(athleteNode **sPtr);
            
