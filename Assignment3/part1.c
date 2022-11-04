//CS2211B 2022
//Assignment #3
//Benjamin Namo
//251182806
//bnamo
//Feb 28th, 2022

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    
    char str[1000]; //creating string array to hold input
    int tempIntArray[1000]; //creating a temporary integer array of large size to accept (mostly) arbitrary amount of values
    
    printf("Please enter your integers seperated by spaces: ");
    scanf ("%[^\n]%*c", str); //taking in all inputs

    int i;
    int j;
    char tmp[100];  //creating an array to temporarily hold seperate strings of digits from the input
    int count = 0;  //count value for char array
    int arrayCount=0;   //count value for int array
    
    for (i=0; i<(strlen(str)+1); i++){  //iterating through string input
        
        if ((str[i] != ' ') & (str[i]=='0'||str[i]=='1'||str[i]=='2'||str[i]=='3'||str[i]=='4'||str[i]=='5'||str[i]=='6'||str[i]=='7'||str[i]=='8'||str[i]=='9')){  //checking if input is a number or not
            
            tmp[count]=str[i];  //if it is a number then we add it to the temporary string array
            count ++;   //incrementing count
            }
        
        if (((str[i] == ' ' )|(str[i] == '\0')) & (str[i-1] != ' ') & (str[i-1]=='0'||str[i-1]=='1'||str[i-1]=='2'||str[i-1]=='3'||str[i-1]=='4'||str[i-1]=='5'||str[i-1]=='6'||str[i-1]=='7'||str[i-1]=='8'||str[i-1]=='9')){ //if we have reached a space or the end of the input
                                                                                            //also checking if the char before was a space or not, so we dont store that space
            tempIntArray[arrayCount] = atoi(tmp);   //if we have reached the end of the number (found a space), we turn the temporary array into an integer and store in the temp int array. Further, we store this value at arrayCount index (0 at first).
            arrayCount +=1; //incrementing arrayCount to next index
            
            for (j=0; j<=count; j++){ //clearing the temp char array, so that we can store the next run of digits from the input
                tmp[j] = '\0'; //setting to \0 is the equivalent of clearing a space in a char array
            }
            count = 0;  //resetting count to 0, so that we store the next digit in the first index of the temp char array
            
        }
    
    }
        
    int intArray[arrayCount];   //initializing the final array from the input, using previously incremented arrayCount as the size of the array.
    
    for (i=0; i<arrayCount;i++){    //copying values from temp int array to final int array
            
        intArray[i] = tempIntArray[i];
        
        }
    
    printf("\nPart 1:\n");
    printf("    Your array is: ");
    
    for (i=0; i<arrayCount; i++){   //printing array
        
        printf("%d ", intArray[i]);
        
    }
    
    printf("\n    Your array has %d elements", arrayCount);
    printf("\n    The size of the array is %d bytes\n", sizeof(intArray));
    
    printf("\nPart 2:\n");
    printf("    Your array in reverse is: ");
    
    for (i=arrayCount-1; i>-1; i--){    //printing array backwardsby starting at final integer and decrementing
        
        printf("%d ", intArray[i]);
        
    }

    printf("\n\nPart 3: \n");
    
    printf("    The smallest value in your array is: ");
    
    int smallestVal = intArray[0];  //initializing the smallest value as the first value in the array
    
    for (i=1; i<arrayCount; i++){   //iterating through array
        
        if (intArray[i] < smallestVal){ //if the value found is smaller than the smallest value, it is the new smallest. After going through all indexes, were left with true smallest.
            
            smallestVal = intArray[i];
            
        }
        
    }
    
    printf("%d", smallestVal);
    
    printf("\n\nPart 4: \n");
    
    printf("    The sum of all values in your array is: ");
    
    int sum = 0;    //initializing sum to 0
    
    for (i=0; i<arrayCount; i++){   //incrementing through array and adding all values to sum
        
        sum += intArray[i];
        
    }
    
    printf("%d", sum);
    
    printf("\n\nPart 5: \n");
    
    printf("     Your array with the first and last element switched is: ");
    
    printf("%d ",intArray[arrayCount-1]);   //printing last element of array
    
    for (i=1; i<arrayCount-1; i++){ //printing elements of array starting from 2nd element and ending at 2nd last element
        
        printf("%d ",intArray[i]);
        
    }
    
    printf("%d ",intArray[0]);  //printing first element
    
    
    printf("\n\nPart 6: \n");
    
    printf("     Your array in sorted order is: ");
    
    int tempVal = 0;    //a variable to hold a value temporarily
    int sortedArray[arrayCount];    //creating a new array, so that we can sort original array without actually changing it
    
    for (i=0;i<arrayCount;i++){                 //copying elements to sorted array (still unsorted at this point)
        
        sortedArray[i] = intArray[i];
        
    }
    
    for (i=0; i<arrayCount; i++){       //incrementing through array
        
        for (j=i+1; j<arrayCount; j++){ //incrementing through next index of array
            
            if (sortedArray[j] < sortedArray[i]){   //if the next index is less than the current index, we swap them
                
                tempVal = sortedArray[i];   //we store the current index in tempVal
                sortedArray[i] = sortedArray[j];    //we then make the current index equivelent to the value of the next index
                sortedArray[j] = tempVal;   //and then make the next index equivalent to the initial index
                
                //i could not explain it very well, but we are essentially going through the array and through swapping values, pushing all the lower values to the left.
                //this will eventually sort the array from lowest to highest.
                
            }
            
        }
        
    }
        
    for (i=0; i<arrayCount; i++){   //printing the sorted array
        printf("%d ", sortedArray[i]);
    }
    
    printf("\n\n");
    
}
        


