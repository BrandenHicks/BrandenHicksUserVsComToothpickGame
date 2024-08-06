
#define ROUNDS 3
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

void greeting(); //display welcome message to user
int playRound(int round); //play one round
int humanPick(); //retrieve the user's guess
int computerPick(int choice, int leftover); //computer makes its pick
int leftOnTable(int toothpicks, int taken); //calculate number of toothpicks left
void winnerAnnouncment(int user); //overall winner of round announcement

int main()
{
    greeting(); //calls function to greet the user
    for(int x = 0; x < ROUNDS; ++x)
{
    int result = playRound(x + 1); //call playRound and assign result the value function returns
    winnerAnnouncment(result); //determines the winner depending on the return value of playRound
}
    printf("********************************************************\n");
    printf("Thank you for playing!\n");
    return 0; //end of the game
}

void greeting() 
{   
    //this is the code that greets the user and contains the instruction for how the game works
    printf("********************************************************\n"); 
    printf("Welcome to Toothpick Game!\n"); 
    printf("Here are the rules.\n"); 
    printf("There are currently 31 toothpicks on the table.\n"); 
    printf("You and I will each get a turn to pick either 1, 2, or 3 toothpicks off the table.\n"); 
    printf("The player that gets to pick the last toothpicks loses the game!\n"); 
    printf("Sounds easy right? Well lets see if you can beat me!\n"); 
    printf("Ready to play?...Here we go!\n");
    printf("********************************************************\n"); 
     
}

int playRound(int round)
{   
    printf("Welcome to round %d!\n", round);
    printf("You may go first!\n");
    printf("********************************************************\n"); 
    int toothpicks = 31; //number of toothpicks to start with 
    /*loop that keeps track of toothpicks until respective no more toothpicks 
    left. we will learn about conditional loops soon :)*/
    while(toothpicks != 0)
    { 
    printf("There are %d toothpick(s) left on the table.\n", toothpicks); 
    int human = humanPick(); //calls humanPicks(); 
        if (human > 3 || human < 1 || toothpicks <= 2 && human >= 2) /*ensures that the user can't take more than 3 toothpicks or less than 1 toothpick. This also ensures that the user can't take more toothpicks that are available when they're limited under 3.*/  
        {
            printf("Oh no no, you can't do that in this game! Try again.\n"); 
            printf("********************************************************\n");
            continue; //returns to the beginning of the loop
        }
        else 
        {
            printf("Ok... you took %d off the table.\n", human); 
            toothpicks = leftOnTable(toothpicks, human); //updates remaining toothpicks 
        } 
        
        if (toothpicks <= 0)//insert code here that simulate the round properly based on assignment directions
        {
            return 0; //returns a value for winnerAnnouncment(); 
            break; //this is so we don't go into the negatives for toothpicks left on the table
        }
        else
        {
            printf("I'm making my decision now.\n"); 
            int computer = computerPick(human, toothpicks); //calls computerPicks(); 
            toothpicks = leftOnTable(toothpicks, computer); //updates remaining toothpicks 
            printf("I am taking %d toothpick(s) off the table.\n", computer); 
            printf("********************************************************\n"); 
            printf("********************************************************\n"); 
        }
      
    }
    return 1;   
}

int humanPick() 
{ 
    int numTaken; //decalred variable to be used an input 
    printf("How many toothpicks are you going to take off the table? "); /*asks user for toothpicks they want to take*/ 
    scanf("%d", &numTaken); //takes input from the user 
    return numTaken; //returns the values 

}

int computerPick(int choice, int leftover) 
{
    if(leftover > 4) /*take the value of whatever the user chose, subtracts that from 4, then uses that value for the computers pick */
    {
        int took1 = 4 - choice; 
        return took1; 
    }
    else if (leftover == 4) /*if there are 4 toothpicks left, the computer will take 3 to leave 1 remaining toothpick for the player(resulting in the player loosing the round)*/
    {
        int took2 = leftover - 1; 
        return took2; 
    }
    else if (leftover == 3) /*if there are 3 toothpicks left, the computer will take 2 to leave 1 remaining toothpick for the player(resulting in the player loosing the round)*/
    {
        int took3 = leftover - 1; 
        return took3; 
    }
    else if (leftover == 2) /*if there are 2 toothpicks left, the computer will take 1 to leave 1 remaining toothpick for the player(resulting in the player loosing the round)*/
    {
        int took4 = leftover - 1; 
        return took4; 
    }
    else if (leftover == 1) //the computer takes the last toothpick 
    {
        int took5 = leftover; 
        return took5; 
    }
 return 0; //this is so there wont be an error in the terminal 
}


int leftOnTable(int toothpicks, int taken) //function to update the toothpicks that remain after the user and computer take toothpicks 
{
    int remaining = toothpicks - taken; 
    return remaining; 
}

void winnerAnnouncment(int user) //announces winner. return values help determine which statement is called 
{
    if(user == 1) //user wins 
    {
        printf("You won! I'll let you have this one.\n");
    }
    else if (user == 0) //computer wins 
    {
        printf("I won! Haha better luck next time!\n");
    }
    
}
