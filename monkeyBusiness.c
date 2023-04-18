#include <stdio.h>
#include <stdlib.h>

// -1 will indicate heading back to the root, aka the entrance of the park
#define ENTRANCE -1

int trackMonkeys(int [], int);

// Primary function that will sum up the monkeys in the stack and return the answer
int trackMonkeys(int stackArray[], int numMonkeys) 
{
    // Answer value that will hold the sum of the monkeys in the stack
    int sumMonkeys = 0;

    // Add each monkey in the stack array to the sum of the total monkeys seen
    for (int i = 0; i <= numMonkeys; i++) 
    {
        sumMonkeys = sumMonkeys + stackArray[i];
    }

    return sumMonkeys;
}

int main()
{
    // Declarations here
    int numExhibits, numMonkeys, exhibitID;
    int cur = 0;
    
    // Input the number of exhibits in the park
    scanf("%d", &numExhibits);

    // Stack array to pass into the stack function
    int curMonkeys[numExhibits];

    // answer array to store values retrieved from the stack function
    int ans[numExhibits];

    // Main loop that will traverse through the stack 2n - 1 times
    for (int i = 0; i < ((2 * numExhibits) - 1); i++) 
    {
        // take in ID of the exhibit to create an array structure
        scanf("%d", &exhibitID);

        // If the input is not -1 aka going back to the entrance
        if (exhibitID != ENTRANCE) 
        {
            // Take in the number of monkeys in the entrance and store in the temporary array
            scanf("%d", &numMonkeys);
            curMonkeys[cur] = numMonkeys;

            // Create answer array by calling stack function after passing in the current stack
            ans[exhibitID - 1] = trackMonkeys(curMonkeys, cur);

            // Increment the current position to keep track of where we are on the stack
            cur++;

        }

        // If the input is -1 aka the entrance then go back one position
        else if (exhibitID == ENTRANCE) 
        {
            cur--;
        }
    }

    // Input exhibits to visit after the park array is setup
    // AKA "visitors" entering the park after employees "set it up"
    scanf("%d", &numExhibits);

    // Input which exhibits the visitors will go to
    for (int i = 0; i < numExhibits; i++)
    {
        scanf("%d", &curMonkeys[i]);      
    }

    // Print the monkeys that the visitors saw at those exhibits based on what was recorded from the stack
    // at that point
    for (int i = 0; i < numExhibits; i++)
    {
        printf("%d\n", ans[curMonkeys[i] - 1]);
    }

}