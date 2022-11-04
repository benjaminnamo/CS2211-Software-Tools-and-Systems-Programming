//Benjamin Namo
//University of Western Ontario
//251182806
//CS2211B
//April 6th, 2022

#include <stdio.h>

struct registrationNode{
    int registrationCode;
    int registrationEventCode;
    int registrationAthleteCode;
    struct registrationNode *nextRegistrationPtr;
};

typedef struct registrationNode registrationNode;


extern void insert_registration(registrationNode **sPtr, int eventCode[100]);
          
extern void search_registration(registrationNode **sPtr);
     
extern void update_registration(registrationNode **sPtr, int eventCode[100]);
      
extern void print_registration(registrationNode **sPtr);
           
extern void erase_registration(registrationNode **sPtr);
            
