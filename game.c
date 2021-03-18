#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

FILE *fptr;

//the player struct
struct Player
{
    char *name;
    int value;
} player1, player2;

//a function to find a word in a french dictioanry
int FindWord(char *word, char *file)
{
    char line[1024];
    FILE *fp = fopen(file, "r");
    while (fgets(line, sizeof(line), fp) != NULL)
    {

        if (line == word)
        {

            return 1;
        }
    }
}

int generate_random_number(int lower, int upper, int count)
{ //this will generate random number in range l and r
    int i;
    for (i = 0; i < count; i++)
    {
        int num = (rand() %
                   (upper - lower + 1)) +
                  lower;
        return num;
    }
}

// the part of letter game
void lettersGame()
{
    // variables

    char answer1[100];
    char answer2[100];

    char array[1024] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char letters[11];
    int i = 0;
    time_t t;
    //current time as seed of random number generator
    srand((unsigned)time(&t));

    // while loop to get random letters from the alphabet array
    while (i <= 9)
    {

        letters[i] = array[rand() % 10];
        i++;
    }

    // printing the random letters to the players and getting their answers

    printf("%s\n", letters);
    printf("answer of the first player   :      ");
    scanf("%s", answer1);
    char *c = answer1;
    char *j = answer2;
    printf("answer of the second player  :      ");
    scanf("%s", answer2);
    //looking for the two answers in the dictionary
    int boolean = FindWord(answer1, "/Users/macbookcrea/desktop/projet/liste_francais.txt");
    int boolean2 = FindWord(answer2, "/Users/macbookcrea/desktop/projet/liste_francais.txt");
    // checking if the two word exist
    if (!(boolean == 1))
    {
        printf("the word does not exist \n");
        exit(1);
    }
    if (!(boolean2 == 1))
    {
        printf("the word does not exist \n");
    }

    //checking if the  answer only contains letters  from the random alphabets generated
    if (!strchr(letters, (*c)))
    {
        printf("player 1 has cheated \n");
    }
    //checking if the  answer only contains letters  from the random alphabets generated

    if (!strchr(letters, (*j)))
    {
        printf("player 2 has cheated \n");
    }

    //checking the longest word among the answers
    if (boolean == 1)
    {
        if (strlen(answer1) > strlen(answer2))
        {
            printf("player 1 is the winner \n");
            player1.value++;
        }
    }else{
        printf("player 2 is the winner");
        player2.value++;
    }

    if (boolean2 == 1)
    {
        if (strlen(answer2) > strlen(answer1))
        {
            printf("player 2 is the winner \n");
            player2.value++;
        }
        
    }else{
        print("player 1 is the winner");
        player1.value ++;
    }
}

void numbersGame()
{

    int lower = 1, upper = 10, count = 1;
    int answer1;
    int answer2;
    //current time as seed of random number generator
    srand(time(0));
    /// generating random numbers
    int x = generate_random_number(lower, upper, count);
    int y = generate_random_number(lower, upper, count);
    int z = generate_random_number(lower, upper, count);
    int v = generate_random_number(lower, upper, count);
    // printing the users and getting their answers
    printf(("(%d + %d) X %d  \n"), x, y, z);
    int val = (x + y) * z;
    printf("first player answer \n");
    scanf("%d", &answer1);
    printf("second player answer \n");
    scanf("%d", &answer2);
    // checking for the correct answers
    if (answer1 == val)
    {

        player1.value++;
        printf("player 1 answer is correct \n");
    }
    if (answer2 == val)
    {

        player2.value++;
        printf("player 2 answer is correct \n");
    }
}

int main()
{
    int mode_number;
    // getting the names of the players
    char name1[100];
    char name2[100];
    printf("------------------------------------ \n");
    printf("name of the first player      :   ");
    scanf("%s", name1);

    printf("------------------------------------ \n");

    //setting the name of the players
    player1.name = name1;

    printf("name of the second player      :  ");
    scanf("%s", name2);

    printf("------------------------------------ \n");

    player2.name = name2;
    printf("Select the game mode \n \n");

    printf("1 Simple 10 round \n \n ");

    printf("2 Medium 20 round \n \n");

    printf("3 Hard 40 round \n \n ");

    printf("Enter the number of the mode you want to play     :  ");
    printf("\u263A\n");
    scanf("%d", &mode_number);

    if (mode_number == 1)
    {
        printf("game started in simple mode \n");
        int i = 0;
        while (i < 15)
        {
            lettersGame();
            numbersGame();
            i++;
        }

        if (player1.value > player2.value)
        {
            printf("player 1 is the winner");
        }
    }

    return 0;
}
