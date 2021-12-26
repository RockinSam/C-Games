// C GAMES

#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#define space "\t\t\t"

COORD coord={0,0};
 void gotoxy(int x,int y)
 {
   coord.X=x;
 coord.Y=y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
 }

// User information.
char username[100], password[100], accountsDB[10000], *tempstr;
char sound = '1', bgColor = '1';
int a[4][4]={0},l;// 2048 array.
// Declaring structure globally for checkers.
struct pieces
{
    char color; // color = s if piece is white else color = o.
    int posX;
    int posY;
};

/** Hangman **/
int diagram(int lastindex)
{

    if(lastindex==0)
      {
        printf("\n");
        printf(space"\t\t");
        printf("         %c%c%c%c%c%c%c\n", 220,220,220,220,220,220,220);
        printf(space"\t\t");
        printf("         %c     %c\n", 179,219);
        printf(space"\t\t");
        printf("         %c     %c\n", 179,219);
        printf(space"\t\t");
        printf(" \t       %c \n",219);
        printf(space"\t\t");
        printf("        ");
        printf("       %c\n", 219);
        printf(space"\t\t");
        printf("         ");
        printf("      %c\n", 219);
        printf(space"\t\t");
        printf("        ");
        printf("       %c \n", 219);
        printf(space"\t\t");
        printf("               %c\n", 219);
        printf(space"\t\t");
        printf("        %c%c%c%c%c%c%c%c%c%c", 223,223,223,223,223,223,223,223,223,223);
        printf("\n");

      }
    if(lastindex==1)
      {
       printf("\n");
       printf(space"\t\t");
       printf("         %c%c%c%c%c%c%c\n", 220,220,220,220,220,220,220);
       printf(space"\t\t");
       printf("         %c     %c\n", 179,219);
       printf(space"\t\t");
       printf("         %c     %c\n", 179,219);
       printf(space"\t\t");
       printf(" \t %c     %c \n", 179, 219);
       printf(space"\t\t");
       printf("        ");
       printf("       %c\n",219);
       printf(space"\t\t");
       printf("         ");
       printf("      %c\n", 219);
       printf(space"\t\t");
       printf("        ");
       printf("       %c \n", 219);
       printf(space"\t\t");
       printf("               %c\n", 219);
       printf(space"\t\t");
       printf("        %c%c%c%c%c%c%c%c%c%c", 223,223,223,223,223,223,223,223,223,223);
     }
   if(lastindex==2)
     {
     printf("\n");
     printf(space"\t\t");
     printf("         %c%c%c%c%c%c%c\n", 220,220,220,220,220,220,220);
     printf(space"\t\t");
     printf("         %c     %c\n", 179,219);
     printf(space"\t\t");
     printf("         %c     %c\n", 179,219);
     printf(space"\t\t");
     printf(" \t %c     %c \n", 179, 219);
     printf(space"\t\t");
     printf("         ");
     printf("%c ",234);
     printf("    %c\n",219);
     printf(space"\t\t");
     printf("         %c", 186);
     printf("     %c\n",219);
     printf(space"\t\t");
     printf("        ");
     printf("       %c \n", 219);
     printf(space"\t\t");
     printf("               %c\n", 219);
     printf(space"\t\t");
     printf("        %c%c%c%c%c%c%c%c%c%c", 223,223,223,223,223,223,223,223,223,223);
     }
    if(lastindex==3)
     {
      printf("\n");
      printf(space"\t\t");
      printf("         %c%c%c%c%c%c%c\n", 220,220,220,220,220,220,220);
      printf(space"\t\t");
      printf("         %c     %c\n", 179,219);
      printf(space"\t\t");
      printf("         %c     %c\n", 179,219);
      printf(space"\t\t");
      printf(" \t %c     %c \n", 179, 219);
      printf(space"\t\t");
      printf("        \\");
      printf("%c ",234);
      printf("    %c\n",219);
      printf(space"\t\t");
      printf("         %c", 186);
      printf("     %c\n",219);
      printf(space"\t\t");
      printf("        ");
      printf("       %c \n", 219);
      printf(space"\t\t");
      printf("               %c\n", 219);
      printf(space"\t\t");
      printf("        %c%c%c%c%c%c%c%c%c%c", 223,223,223,223,223,223,223,223,223,223);
     }
    if(lastindex==4)
     {
      printf("\n");
      printf(space"\t\t");
      printf("         %c%c%c%c%c%c%c\n", 220,220,220,220,220,220,220);
      printf(space"\t\t");
      printf("         %c     %c\n", 179,219);
      printf(space"\t\t");
      printf("         %c     %c\n", 179,219);
      printf(space"\t\t");
      printf(" \t %c     %c \n", 179, 219);
      printf(space"\t\t");
      printf("        \\");
      printf("%c",234);
      printf("/    %c\n", 219);
      printf(space"\t\t");
      printf("         %c", 186);
      printf("     %c\n", 219);
      printf(space"\t\t");
      printf("        ");
      printf("       %c \n", 219);
      printf(space"\t\t");
      printf("               %c\n", 219);
      printf(space"\t\t");
      printf("        %c%c%c%c%c%c%c%c%c%c", 223,223,223,223,223,223,223,223,223,223);
     }
   if(lastindex==5)
    {
    printf("\n");
    printf(space"\t\t");
    printf("         %c%c%c%c%c%c%c\n", 220,220,220,220,220,220,220);
    printf(space"\t\t");
    printf("         %c     %c\n", 179,219);
    printf(space"\t\t");
    printf("         %c     %c\n", 179,219);
    printf(space"\t\t");
    printf(" \t %c     %c \n", 179, 219);
    printf(space"\t\t");
    printf("        \\");
    printf("%c", 234);
    printf("/    %c\n", 219);
    printf(space"\t\t");
    printf("         ");
    printf("%c     %c\n", 186, 219);
    printf(space"\t\t");
    printf("        /");
    printf("      %c \n", 219);
    printf(space"\t\t");
    printf("               %c\n", 219);
    printf(space"\t\t");
    printf("        %c%c%c%c%c%c%c%c%c%c", 223,223,223,223,223,223,223,223,223,223);
    }
  if(lastindex==6)
   {
     printf("\n");
     printf(space "\t\t");
     printf("         %c%c%c%c%c%c%c\n", 220,220,220,220,220,220,220);
     printf(space "\t\t");
     printf("         %c     %c\n", 179,219);
     printf(space "\t\t");
     printf("         %c     %c\n", 179,219);
     printf(space "\t\t");
     printf(" \t %c     %c \n", 179, 219);
     printf(space "\t\t");
     printf("        \\");
     printf("%c",234);
     printf("/    %c\n", 219);
     printf(space "\t\t");
     printf("         ");
     printf("%c     %c\n", 186, 219);
     printf(space "\t\t");
     printf("        /");
     printf(" \\    %c \n", 219);
     printf(space "\t\t");
     printf("               %c\n", 219);
     printf(space "\t\t");
     printf("        %c%c%c%c%c%c%c%c%c%c", 223,223,223,223,223,223,223,223,223,223);
   }
}
int performInHangman(char *words[] , int size)
{
     char guess, choice;
    char miss[6];
    int i;
    system("cls");
    printf("\n\n\n");
    printf(space space"    HANGMAN\n");
    printf(space);
    for(i = 0; i < 72; i++)
    {
        printf("%c", 205);
    }
    int length , index  , lastindex = 0 , randomnumberofindex , check , count=0 , missing = 0 ;

    time_t t;
    srand((unsigned) time(&t));

     randomnumberofindex = rand()%size;   //picking random word in above given words

    length = strlen(words[randomnumberofindex]);

    char word[length];
    printf("\n\n\n\t\t"space);
    for(index = 0 ; index < length ; index++)
    {
        word[index] = '_';                 //declarinf _ when it matches the letter of random word it displays
        printf(" %c ",word[index]);

    }
    printf(" \n\n\n ");
    label:
         check = 0;
         fflush(stdin);

         printf("\n\n\n\t\t\t\t\t\tguess  ");            //enter the guess letter
         printf("\n\n\n\t\t\t");
           for(i = 0; i < 72; i++)
          {
           printf("%c", 205);
          }
          printf("\n\t\t\t\tPress Esc to exit   ");
          label5:
         guess = _getch();
         if(guess == 27)
         {
            return 0;
         }
         if(guess >= 65 && guess<= 90 || guess >= 97 && guess <= 122 || (guess>='0'&&guess<='9'))
         {
         }
         else{
                goto label5;
            }
        if((guess >= 'a' &&guess <= 'z')||(guess >= 'A' &&guess <= 'Z') || (guess>='0'&&guess<='9'))
        {
         system("cls");
         printf("\n\n\n");
         printf(space space"    HANGMAN\n");
          printf(space);
    for(i = 0; i < 72; i++)
    {
        printf("%c", 205);
    }
         printf("\n\n\n\t\t\t\t\t\t");

         for(index = 0 ; index < length ; index++)
         {
            if(words[randomnumberofindex][index]==guess)   //checking guess letter is present in random word or not
              {
                ++check;
                ++count;
                word[index] = guess;

              }
                printf(" %c ",word[index]);                //if present ,it prints the letter otherwise it prints _
         }

        if(check!=0)
        {
            missing=0;

          printf("\n\n\n\n\t\t\t\t\t\t misses are:");                  //it prints if the guess letter can't match with any randomword letter then guess letter stores in miss
          for(index = 0 ; index < lastindex ; index++)
            {
              printf(" %c ",miss[index]);
              ++missing;
              if(lastindex>0 && index<lastindex)
              printf(",");
            }
         }


         printf("\n");
         if(count==length)                    //if word matches with random word you win
         {
             printf("\n\n\n\t\t\t\t\tBRAVO!!!\n");
            printf("\n\n\n\n\n\n\n\n"space);
        for(i = 0; i < 72; i++)
        {
            printf("%c", 205);
        }
             condition:
            printf("\n\t\t\t\t\t\tPress any key to play again :\n\t\t\t\t\t\tPress Esc to exit :  ");
            fflush(stdin);
            label7 :
        choice = _getch();
        if(choice == 27)
        {
            return 0;
        }
        if(choice >= 65 && choice <= 90 || choice >= 97 && choice <= 122 || (guess>='0'&&guess<='9'))
         {
         }
        else{
                goto label7;
        }
        hangman();
         }

        if(check==0)
         {
            miss[lastindex] = guess;
            for(index = 0 ; index < lastindex ; index++)
             {
               if(miss[index]==guess)
                {
                    missing=0;
                    printf("\n\n\n\t\t\t\t\t\t misses are:");      //it prints if the guess letter can't match with any randomword letter then guess letter stores in miss
                    for(index = 0 ; index < lastindex ; index++)
                   {
                       ++missing;
                     printf(" %c ",miss[index]);
                     if(lastindex>0 && index<lastindex)
                     printf(",");
                   }
                   printf("\n");
                   diagram(index);    //it draws hangman diagram
                    goto label;
                }
             }
             printf("\t\t");
                 printf("\n\n\n\t\t\t\t\t\t misses are:");      //it prints if the guess letter can't match with any randomword letter then guess letter stores in miss
                 missing=0;
                for(index = 0 ; index <= lastindex ; index++)
                {
                  printf(" %c ",miss[index]);
                  ++missing;
                  if(lastindex>0 && index<lastindex)
                  printf(",");
                }

                ++lastindex;
                printf("\n");
          }

        draw:diagram(index);//it draws diagram of a hamgman

        if(missing < 6)
        goto label;
        printf("\n\t\t\t\t\t\tyou lost\n");
        printf("\n\t\t\t\t\t\tthe word is:");

        puts(words[randomnumberofindex]);
        condition1:
            printf("\n\t\t\t");
           for(i = 0; i < 72; i++)
          {
           printf("%c", 205);
          }
            printf("\n\t\t\t\t\t\tPress any key to play again :\n\t\t\t\t\t\tPress Esc to exit :  ");
            fflush(stdin);
            label6 :
        choice = _getch();
        if(choice == 27)
        {
            return 0;
        }
        if(choice >= 65 && choice <= 90 || choice >= 97 && choice <= 122 || (guess>='0'&&guess<='9'))
         {
         }
        else{
                goto label6;
        }
       hangman();
}
else
{
    goto label;

}
}
int fruits()
{
     int i;
    system("cls");
    printf("\n\n\n");
    printf(space space"    HANGMAN\n");
    printf(space);
    for(i = 0; i < 72; i++)
    {
        printf("%c", 205);
    }

    char *fruits[39] =   {"apple","strawberry","orange","banana","grape","pear","peach",
                        "pineapple","cherry","mango","watermelon","grapefruit","lemon",
                        "kiwifruit","avocado","cantaloupe","apricot","papaya","berry",
                        "blackberry","tangerine","pomegranate","coconut","cranberry",
                        "persimmon","lychee","carambola","gooseberry","kumquat",
                        "durian","pomelo","olive","quince","prune","jujube","loquat",
                        "tangelo","longan","guava"};


     int size;
    size = sizeof(fruits)/sizeof(fruits[0]);


    performInHangman(fruits,size);

        return 0;
}
int  movies ()
{
     int i;
    system("cls");
    printf("\n\n\n");
    printf(space space"    HANGMAN\n");
    printf(space);
    for(i = 0; i < 72; i++)
    {
        printf("%c", 205);
    }

    char *movie[30]={"logan","avatar","titanic","deadpool","inception","zootopia","jaws",
    "interstellar","gladiator","prisoners","whiplash","spotlight","memento","oldboy",
    "warrior","downfall","incendies","birdman","moonlight","arrival","fences",
    "gravity","selma","frozen","minions","skyfall","jurassicworld","theavemgers",
    "thedarkknight","spectre"};
    int size;
    size = sizeof(movie)/sizeof(movie[0]);


    performInHangman(movie,size);

return 0;
}



int  animalsandbirds()
{
     int i;
    system("cls");
    printf("\n\n\n");
    printf(space space"    HANGMAN\n");
    printf(space);
    for(i = 0; i < 72; i++)
    {
        printf("%c", 205);
    }

    char *animals[139]={"alligator","antelope","ape","armadillo","badger","bat","bear",
"beaver","bee","bird","cheetah","chicken","clam","bison","boar","buffalo","butterfly","camel","cat",
"cattle","codfish","coyote","crane","crow","deer","dinosaur","dog","dolphin","donkey","dove","duck",
"dagle","eel","elephant","elk","falcon","ferret",
"finch","fish","fly","fox","frog","gerbil","giraffe","gnat","gnu", "goat","goose","gorilla","grasshopper",
"guineapig","gull","hamster","hare","hawk","hedgehog","heron","hippopotamus","hog","hornet","horse",
"hound","human","hummingbird","hyena","jay","jellyfish","kangaroo","koala","lark","leopard","lion",
"llama","louse","magpie","mallard","marten","mole","monkey","moose","mosquito","mouse","mule",
"nightingale","opossum","ostrich","otter","owl","ox","panda","parrot","peafowl","penguin","pheasant",
"pig","pigeon","platypus","porpoise","prairie dog","pronghorn","quail","rabbit","raccoon", "rat","raven",
"rhinoceros", "sanddollar","seaurchin","seal","seastar","serval", "shark",  "sheep","skunk","snake","snipe",
  "sparrow","spider","squirrel", "swallow","swan","termite","tiger", "toad","trout","turkey","turtle", "wallaby",
"walrus","wasp","weasel",  "whale","wolf","wombat","woodpecker","wren","yak","yellowjacket","zebra"};

int size;
    size = sizeof(animals)/sizeof(animals[0]);


    performInHangman(animals,size);

    return 0;
}

int sports()
{
     int i;
    system("cls");
    printf("\n\n\n");
    printf(space space"    HANGMAN\n");
    printf(space);
    for(i = 0; i < 72; i++)
    {
        printf("%c", 205);
    }

    char *sports[47]={"americanfootball","archery","athletics","badminton"," baseball", "basketball",
                                   "bowls","boxing", "canoeing","cricket","curling", "cycling", "darts","disabilitysport",
                                   "diving","equestrian","fencing","football", "formula1", "gaelicgames", "golf", "gymnastics",
                                  "hockey", "horseracing", "icehockey", "judo", "modernpentathlon", "motorsport",
                                 "netball", "olympicsports", "rowing", "rugbyleague", "rugbyunion", "sailing",
                                 "shooting", "snooker", "squash", "swimming","tabletennis", "taekwondo",
                                 "tennis", "triathlon", "volleyball", "weightlifting", "wintersports", "wrestling","handball"};

    int size;
    size = sizeof(sports)/sizeof(sports[0]);


    performInHangman(sports,size);

    return 0;
}

// Hangman.
int hangman()
{
int i, pointer = 1;
char ch;
while(1)
    {

    system("cls");
    printf("\n\n\n");
    printf(space space"    HANGMAN\n");
    printf(space);
    for(i = 0; i < 72; i++)
    {
        printf("%c", 205);
    }
        printf("\n \n\t\t\t\t \tselect category:\n\n");             //word type or belongs to which category
            if(pointer == 1)
            {
                printf(space space"->Sports\n\n");
            }
            else
            {
                printf(space space"  Sports\n\n");
            }
            if(pointer == 2)
            {
                printf(space space"->Animals\n\n");
            }
            else
            {
                printf(space space"  Animals\n\n");
            }
            if(pointer == 3)
            {
                printf(space space"->Movies\n\n");
            }
            else
            {
                printf(space space"  Movies\n\n");
            }
            if(pointer == 4)
            {
                printf(space space"->Fruits\n\n");
            }
            else
            {
                printf(space space"  Fruits\n\n");
            }
            if(pointer == 5)
            {
                printf(space space"->How to play\n\n");
            }
            else
            {
                printf(space space"  How to play\n\n");
            }
            if(pointer == 6)
            {
                printf(space space"->Exit\n\n");
            }
            else
            {
                printf(space space"  Exit\n\n");
            }
        printf("\n\n\n\n\n\n");
        printf(space);
        for(i = 0; i < 72; i++)
        {
            printf("%c", 205);
        }
        fflush(stdin);
        ch = _getch();
        if(sound == '1')
        {
            Beep(1500, 100);
        }
        if(ch == 13)
        {
                if(pointer == 1)
                {
                    sports();
                }
                if(pointer == 2)
                {
                    animalsandbirds();
                }
                if(pointer == 3)
                {
                    movies();
                }
                if(pointer == 4)
                {
                    fruits();
                }
                if(pointer == 5)
                {
                    system("cls");
                    printf("\n\n\n");
                    printf(space space"    HOW TO PLAY\n");
                    printf(space);
                    for(i = 0; i < 72; i++)
                    {
                        printf("%c", 205);
                    }
                    printf("\n\n"space" 1. Press any alphabet, if it is correct then it will fill the space\n"
                           space"   or it will start the execution of man.\n\n"
                           space" 2. Once you are done with filling the gaps you win.\n"
                           space"   or you lose if man dies.\n\n"
                           space" 3. Press Esc if you want to exit the game.\n\n"
                           space" Press any key to return to main menu");
                    printf("\n\n\n\n\n\n\n\n\n\n\n\n"space);
                    for(i = 0; i < 72; i++)
                    {
                        printf("%c", 205);
                    }
                    _getch();
                }
                if(pointer == 6)
                {
                    return 0;
                }
        }
        if(ch == -32)
        {
            switch(_getch())
            {
                case 72 :
                    if(pointer == 1)
                    {
                        pointer = 6;
                    }
                    else
                    {
                        pointer--;
                    }
                break;

                case 80 :
                    if(pointer == 6)
                    {
                        pointer = 1;
                    }
                    else
                    {
                        pointer++;
                    }
                break;
            }
        }

    }
    return 0;
}

/** Word Puzzle **/
int answer(char word[][6],int length)
{
    int row , column ,i ,decision;
    printf("\n");
    printf(space"Answers : ");
    for(row = 0 ; row < length ; row++)
      {
          printf("\t");
       for(column = 0 ; column < strlen(word[row]) ; column++)
         {
         printf("%c",word[row][column]);
         }
      }
    Sleep(1000);
    return 0;
}


int perform(char word[][6],int length)
{
int j, level;
static int k = 0;
for(j = 0; word[0][j] != '\0'; j++);
level = j;
int row = 0 , column = 0 , check = 0 , count = 0 , lencheck = 0 , decision = 0 ,choice ,i ;
char select[5] = {0};
char words[6][6] = {0};
    system("cls");
    printf("\n\n\n");
    printf(space space"WORD PUZZLE\n");
    printf(space);
    for(i = 0; i < 72; i++)
    {
        printf("%c", 205);
    }
    printf("\n");
for(row = 0 ; row < length ; row++)
  {
      printf("\n"space"\t\t");
  for(column = 0 ; column < strlen(word[row]) ; column++)
    {
     words[row][column] = '_';                         //declaring as - to fill words
     printf(" %c  ",words[row][column]);
    }
    printf("\n");
  }
label:check=0;
     printf("\n\n"space"\tWord's letters :\t");

    for(column = strlen(word[0])-1 ; column >= 0 ; column--)
    {

     printf(" %c ",word[0][column]);                  //all letters that form all words in a string array
     if(column>0)
     printf(" , ");
    }
    printf("\n\n\n");
    printf(space);
    for(i = 0; i < 72; i++)
    {
        printf("%c", 205);
    }
    if(k == 0)
    {
        printf("\n\t\t\t\tType 'exit' to exit\t\tGuess the word : ");
        fflush(stdin);
        gets(select);                               //entering the word having given letters
        if(strcmp(select, "exit") == 0)
        {
            return 0;
        }
        else if(strcmp(select, "@143sam") == 0)
        {
            answer(word, length);
        }
        printf("\n");
    }
        system("cls");
if(strlen(select) <= strlen(word[0]))                  //word length is less than or equal to the highest wordlength in array
{
for(row = 0 ; row < length ; row++)
 {
     check=0;                                            //check is use to check if the letter is present
    for(column = 0 ; column < strlen(word[row]) ; column++)
    {
        if((select[column] == word[row][column]))
        {
            ++check;
        }

        if(check == strlen(select) && (check == strlen(word[row])) )
        {
            break;
        }

    }

    if(check == strlen(select)  && (check == strlen(word[row])))
        {
            break;
        }
 }
  printf("\n\n");
if(check == strlen(select) && check == strlen(word[row]) )   //if check is string length then word is present
  {
  for(column = 0 ; column < strlen(select) ; column++)
    {
     words[row][column] = word[row][column];
    }
  }
  count = 0;
  lencheck = 0;    system("cls");
    printf("\n\n\n");
    printf(space space"    WORDPUZZLE\n");
    printf(space);
    for(i = 0; i < 72; i++)
    {
        printf("%c", 205);
    }
      system("cls");
    printf("\n\n\n");
    printf(space space"    WORDPUZZLE\n");
    printf(space);
    for(i = 0; i < 72; i++)
    {
        printf("%c", 205);
    }
    printf("\n");
  for(row = 0 ; row < length ; row++)
    {
    printf("\n"space"\t\t");
    for(column = 0 ; column < strlen(word[row]) ; column++)
      {
      printf("");
      printf(" %c  ",words[row][column]);               //printing after entry of the word
      if(words[row][column] != '_')
      count++;
      }
    lencheck = lencheck + strlen(word[row]);
    printf("\n");
    }
    if(count == lencheck)
    {
     fflush(stdin);
     printf("\n"space"\tBRAVO!!!\n\n");
         printf(space);
        for(i = 0; i < 72; i++)
    {
        printf("%c", 205);
    }
     printf("\n\t\t\t\tPress any key to play again\n"space"\tPress Esc to exit : \n");

    decision = _getch();
    if(decision == 27)
    {
        return 0;
    }
    else
    {
        if(level == 3)
        {
            easy();
        }
        if(level == 4)
        {
            medium();
        }
        if(level == 5)
        {
            hard();
        }
    }

    }
    goto label;
}
else
    {
    printf("\n\n\n");
    printf(space space"WORD PUZZLE\n");
    printf(space);
    for(i = 0; i < 72; i++)
    {
        printf("%c", 205);
    }
    for(row = 0 ; row < length ; row++)
    {
    printf("\n\n"space"\t\t");
    for(column = 0 ; column < strlen(word[row]) ; column++)
      {
      printf(" %c  ",words[row][column]);
      }
    }
    printf("\n");
    goto label;
    }
}

//initializing the words in the word puzzle
//finding number of strings present in given array
//performing puzzle on given letters
int word1()
{
    char word[][6] = {"gym","my"};
    int length;
    length = sizeof word / sizeof word[0];
    perform(word,length); return 0;
}
int word2()
{
    char word[][6] = {"cup","up"};
    int length;
    length = sizeof word / sizeof word[0];
    perform(word,length); return 0;
}
int word3()
{
     char word[][6] = {"bat","at","tab"};
     int length;
     length = sizeof word / sizeof word[0];
     perform(word,length); return 0;
}
int word4()
{
    char word[][6] = {"fog","go","of"};
    int length;
    length = sizeof word / sizeof word[0];
    perform(word,length); return 0;
}
int word5()
{
    char word[][6] = {"son","no","on","so"};
    int length;
    length = sizeof word / sizeof word[0];
    perform(word,length); return 0;
}
int word6()
{
     char word[][6] = {"god","dog","go","do"};
     int length;
     length = sizeof word / sizeof word[0];
     perform(word,length); return 0;
}
int word7()
{
    char word[][6] = {"fox","of","ox"};
    int length;
    length = sizeof word / sizeof word[0];
    perform(word,length); return 0;
}
int word8()
{
     char word[][6] = {"won","now","no","own","on"};
     int length;
     length = sizeof word / sizeof word[0];
     perform(word,length); return 0;
}
int word9()
{
    char word[][6] = {"may","yam","my","am"};
    int length;
    length = sizeof word/sizeof word[0];
    perform(word,length); return 0;
}
int word10()
{
    char word[][6] = {"pat","at","tap","apt"};
    int length;
    length = sizeof word/sizeof word[0];
    perform(word,length); return 0;
}
int word11()
{
     char word[][6] = {"food","of","do"};
     int length;
     length = sizeof word / sizeof word[0];
     perform(word,length); return 0;
}
int word12()
{
    char word[][6] = {"face","ace","cafe"};
    int length;
    length = sizeof word / sizeof word[0];
    perform(word,length); return 0;
}
int word13()
{
    char word[][6] = {"oven","eon","no","one","on"};
    int length;
    length = sizeof word / sizeof word[0];
    perform(word,length); return 0;
}
int word14()
{
    char word[][6] = {"word","row","rod","or","do"};
    int length;
    length = sizeof word / sizeof word[0];
    perform(word,length); return 0;
}
int word15()
{
     char word[][6] = {"wise","is","sew","we"};
     int length;
     length = sizeof word / sizeof word[0];
     perform(word,length); return 0;
}
int word16()
{
    char word[][6] = {"trip","it","pit","tip","rip"};
    int length;
    length = sizeof word / sizeof word[0];
    perform(word,length); return 0;
}
int word17()
{
    char word[][6] = {"fact","act","fat","cat","at","aft"};
    int length;
    length = sizeof word / sizeof word[0];
    perform(word,length); return 0;
}
int word18()
{
    char word[][6] = {"save","vase","as","sea"};
    int length;
    length = sizeof word / sizeof word[0];
    perform(word,length); return 0;
}
int word19()
{
     char word[][6] = {"busy","bus","buy","us","sub","by"};
     int length;
     length = sizeof word / sizeof word[0];
     perform(word,length); return 0;
}
int word20()
{
    char word[][6] = {"soul","so","us"};
    int length;
    length = sizeof word / sizeof word[0];
    perform(word,length); return 0;
}
int word21()
{
    char word[][6] = {"juice","ice","cue"};
    int length;
    length = sizeof word / sizeof word[0];
    perform(word,length); return 0;
}
int word22()
{
    char word[][6] = {"bless","less"};
    int length;
    length = sizeof word / sizeof word[0];
    perform(word,length); return 0;
}
int word23()
{
    char word[][6] = {"sorry","rosy","soy","ors"};
    int length;
    length = sizeof word / sizeof word[0];
    perform(word,length); return 0;
}
int word24()
{
    char word[][6] = {"local","all","call","coal","cola"};
    int length;
    length = sizeof word / sizeof word[0];
    perform(word,length); return 0;
}
int word25()
{
    char word[][6] = {"staff","aft","fast","fat","fats","sat"};
    int length;
    length = sizeof word / sizeof word[0];
    perform(word,length); return 0;
}
int word26()
{
    char word[][6] = {"youth","hot","hut","out","thou","thy","toy"};
    int length;
    length = sizeof word / sizeof word[0];
    perform(word,length); return 0;
}
int word27()
{
    char word[][6] = {"whisk","his","ski","wish"};
    int length;
    length = sizeof word / sizeof word[0];
    perform(word,length); return 0;
}
int word28()
{
    char word[][6] = {"india","aid","and","din"};
    int length;
    length = sizeof word / sizeof word[0];
    perform(word,length); return 0;
}
int word29()
{
    char word[][6] = {"cabin","ban","bin","cab","can","nab","nib"};
    int length;
    length = sizeof word / sizeof word[0];
    perform(word,length); return 0;
}
int word30()
{
    char word[][6] = {"black","alb","back","balk","cab","lab","lack"};
    int length;
    length = sizeof word / sizeof word[0];
    perform(word,length); return 0;
}
int easy()    //easy puzzle words
{
int choice;
    time_t t;
    srand((unsigned) time(&t));
    choice = rand()%10; //picking random word in above given words

switch(choice)
{
case 1:
    word1();
    break;
case 2:
    word2();
    break;
case 3:
    word3();
    break;
case 4:
    word4();
    break;
case 5:
    word5();
    break;
case 6:
   word6();
    break;
case 7:
    word7();
    break;
case 8:
   word8();
    break;
case 9:
    word9();
    break;
case 10:
    word10();
    break;
}
return 0;
}
int medium()    //medium puzzle words
{
    int choice;
    time_t t;
    srand((unsigned) time(&t));
    choice = rand()%10; //picking random word in above given words

switch(choice)
{

case 1:
   word11();
    break;
case 2:
    word12();
    break;
case 3:
    word13();
    break;
case 4:
    word14();
    break;
case 5:
    word15();
    break;
case 6:
   word16();
    break;
case 7:
    word17();
    break;
case 8:
    word18();
    break;
case 9:
    word19();
    break;
case 10:
    word20();
    break;
}
return 0;
}
int hard()      //hard wordpuzzle words
{
     int choice;
    time_t t;
    srand((unsigned) time(&t));
    choice = rand()%10; //picking random word in above given words

switch(choice)
{

case 1:
   word21();
    break;
case 2:
    word22();
    break;
case 3:
    word23();
    break;
case 4:
    word24();
    break;
case 5:
    word25();
    break;
case 6:
   word26();
    break;
case 7:
    word27();
    break;
case 8:
    word28();
    break;
case 9:
    word29();
    break;
case 10:
    word30();
    break;
}
return 0;
}

int startInWP(int level)
{
      system("cls");
    switch(level)       //levels of word puzzle
    {
        case 1:
            easy();
            break;
        case 2:
            medium();
            break;
        case 3:
            hard();
            break;
    }
return 0;
}

// Word puzzle.
int wordPuzzle()
{
    int level, r, i;
    label1 :
    level = 0;
    r = gameMenu("WORD PUZZLE", &level);
    if(r == 1)
    {
        return 0;
    }
    else if(r == 2)
    {
        system("cls");
        printf("\n\n\n");
        printf(space space"    HOW TO PLAY\n");
        printf(space);
        for(i = 0; i < 72; i++)
        {
            printf("%c", 205);
        }
        printf("\n\n"space" 1. Press any alphabet from the given alphabets to fill the space\n\n"
                space" 2. Once you are done with filling all the gaps of all words you win.\n\n"
                space" 3. Type 'exit' if you want to exit the game.\n\n"
                space" Press any key to return to main menu");
        printf("\n\n\n\n\n\n\n\n\n\n\n\n"space);
        for(i = 0; i < 72; i++)
        {
            printf("%c", 205);
        }
        _getch();
    }
    level -= 2;
    startInWP(level);           //starting of the word puzzle
    goto label1;
    return 0;
}

/** Tic Tac Toe **/
// Draw game condition.
int drawTicTacToe(char Board[3][3])
{
    int k=0,i,j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(Board[i][j]=='o'||Board[i][j]=='x')
            {
                k++;
            }return 0;
        }
    }
    if(k==9)
    {
        printf("\n"space"\tGame draw\n");
        _getch();
        return 1;
        }
}

int gamer2(char board[3][3], char Board[3][3])           //player 2 playing function.
{
int p,q;
int i,j,y,z,k=1;
char b='x',c;
char position;
y=position;
system("cls");

label:

fflush(stdin);
c='1';
position = getCurPos(Board, 2);
if(position == 0)
{
    return 1;
}
printf("\n");

for(i=0;i<3;i++)
{
    for(j=0;j<3;j++)
    {

        if(position==c&&((board[i][j]=='o')||(board[i][j]=='x')))   //checking whether the place is occupied or not
        {
            goto label;
        }
        c++;

    }
}

system("cls");
if(position>='1'&&position<='9')              //if positions are between initialize positions
{
    system("cls");
    printf("\n\n\n");
        printf(space space"    TIC TAC TOE\n");
        printf(space);
        for(i = 0; i < 72; i++)
        {
            printf("%c", 205);
        }
        printf("\n\n\n\n\n\n\n\n");
for(i=0;i<3;i++)                           //print tic tac toe after player 2 place the position
   {
       printf(space space"    ");
       for(j=0;j<3;j++)
       {
           if(board[i][j]==position)
           {
               Board[i][j]=board[i][j]=b;
              printf(" %c ",Board[i][j]);
           }
           else
           {
               printf(" %c ",Board[i][j]);
           }
           if(j < 2)
           {
                printf("%c", 179);
           }
       }
        if(i < 2)
        {
            printf("\n"space space"    %c%c%c%c%c%c%c%c%c%c%c\n", 196, 196, 196, 197, 196, 196, 196, 197, 196, 196, 196);
        }
   }
        printf("\n\n\n\n\n\n\n\n");
        printf(space);
        for(i = 0; i < 72; i++)
        {
            printf("%c", 205);
        }

   for(i=0;i<3;i++)      //checking horizontal and vertical
{
    if(board[i][0]=='x'&&board[i][1]=='x'&&board[i][2]=='x')
    {
        system("color a0");
        printf("\n"space space);
        printf("player 2 won the game\n");
        _getch();
        return 1;
        break;
    }
    if(board[0][i]=='x'&&board[1][i]=='x'&&board[2][i]=='x')
    {
        system("color a0");
        printf("\n"space space);
        printf("player 2 won the game\n");
        _getch();
        return 1;
        break;
    }


}
if(board[0][0]=='x'&&board[1][1]=='x'&&board[2][2]=='x')      //checking diagonals
{
    system("color a0");
    printf("\n"space space);
        printf("player 2 won the game\n");
    return 1;
    _getch();
}
if(board[0][2]=='x'&&board[1][1]=='x'&&board[2][0]=='x')
{
    system("color a0");
    printf("\n"space space);
        printf("player 2 won the game\n");
    _getch();
    return 1;
}
}
else                            //if position is not in between positions
{
    goto label;
}

    gamer1(board, Board);
}

int gamer1(char board[3][3], char Board[3][3])           //player 1 playing function.
{
int i,j,k=1;
char    b='o',c;
char position=1;
system("cls");
label:
fflush(stdin);
c='1';
position = getCurPos(Board, 1);
if(position == 0)
{
    return 0;
}
system("cls");
for(i=0;i<3;i++)
{
    for(j=0;j<3;j++)
    {
        if(position==c&&((board[i][j]=='o')||(board[i][j]=='x')))     //checking position if it is already occupied
        {
            goto label;
        }
        c++;
    }
}

if(position>='1'&&position<='9')                                   //if position is between declared positions
{
    system("cls");
        printf("\n\n\n");
        printf(space space"    TIC TAC TOE\n");
        printf(space);
        for(i = 0; i < 72; i++)
        {
            printf("%c", 205);
        }
        printf("\n\n\n\n\n\n\n\n");
for(i=0;i<3;i++)                           //print tic tac toe after player 1 place the position
   {
       printf(space space"    ");
       for(j=0;j<3;j++)
       {
           if(board[i][j]==position)
           {
               Board[i][j]=board[i][j]=b;
              printf(" %c ",Board[i][j]);
           }
           else
           {
               printf(" %c ",Board[i][j]);
           }
           if(j < 2)
           {
                printf("%c", 179);
           }
       }
        if(i < 2)
        {
            printf("\n"space space"    %c%c%c%c%c%c%c%c%c%c%c\n", 196, 196, 196, 197, 196, 196, 196, 197, 196, 196, 196);
        }
   }
   printf("\n\n\n\n\n\n\n\n");
        printf(space);
        for(i = 0; i < 72; i++)
        {
            printf("%c", 205);
        }
for(i=0;i<3;i++)                                      //checking horizontal and vertical columns are same or not
{
    if(board[i][0]=='o'&&board[i][1]=='o'&&board[i][2]=='o')
    {
        system("color a0");
        printf("\n"space space);
        printf("player 1 won the game\n");
        _getch();
        return 0;
        break;
    }
    if(board[0][i]=='o'&&board[1][i]=='o'&&board[2][i]=='o')
    {
        system("color a0");
        printf("\n"space space);
        printf("player 1 won the game\n");
        _getch();
        return 0;
        break;
    }
}
if(board[0][0]=='o'&&board[1][1]=='o'&&board[2][2]=='o')            //checking diagonal positions having same
{
    system("color a0");
    printf("\n"space space);
        printf("player 1 won the game\n");
    _getch();
    return 0;
}
if(board[0][2]=='o'&&board[1][1]=='o'&&board[2][0]=='o')
{
    system("color a0");
    printf("\n"space space);
        printf("player 1 won the game\n");
    _getch();
    return 0;
}
}
else                                                 //if position is not in between given positions
{
    goto label;
}
if(gamer2(board, Board))
{
    return 0;
}
}

int getCurPos(char Board[3][3], int r)
{
 int boxPos = 5;
int i, j, ib, jb;
char ch;
while(1)
{
    if(boxPos >= 1 && boxPos <= 3)
    {
        ib = 0;
        jb = boxPos - 1;
    }
    else if(boxPos >= 4 && boxPos <= 6)
    {
        ib = 1;
        jb = boxPos - 4;
    }
    else if(boxPos >= 7 && boxPos <= 9)
    {
        ib = 2;
        jb = boxPos - 7;
    }
        system("cls");
        printf("\n\n\n");
        printf(space space"    TIC TAC TOE\n");
        printf(space);
        for(i = 0; i < 72; i++)
        {
            printf("%c", 205);
        }
        printf("\n\n\n\n\n\n\n\n");
    for(i=0;i<3;i++)
    {
    printf(space space"    ");
    for(j=0;j<3;j++)
    {
        if(i == ib && j == jb)
        {
            printf("[%c]",Board[i][j]);
        }
        else
        {
            printf(" %c ",Board[i][j]);
        }
        if(j < 2)
        {
            printf("%c", 179);
        }
    }
    if(i < 2)
    {
        printf("\n"space space"    %c%c%c%c%c%c%c%c%c%c%c\n", 196, 196, 196, 197, 196, 196, 196, 197, 196, 196, 196);
    }
    }
    printf("\n\n\n\n\n\n\n\n");
        printf(space);
        for(i = 0; i < 72; i++)
        {
            printf("%c", 205);
        }
          printf(space space"Press Esc to exit \t Player %d's chance", r);
    fflush(stdin);
    ch = _getch();
    if(sound == '1')
    {
        Beep(1500, 100);
    }
    if(ch == 27)
    {
        return 0;
    }
    if(ch == 13)
    {
        boxPos += 48;
        return boxPos;
    }
    if(ch == -32)
    {
        switch(_getch())
        {
            // Moving box up.
            case 72 :
                if(boxPos >=1 && boxPos <= 3)
                {
                }
                else
                {
                    boxPos -= 3;
                }
            break;

            // Moving box left.
            case 75 :
                if(((boxPos - 1) % 3) == 0)
                {
                }
                else
                {
                    boxPos -= 1;
                }
            break;

            // Moving box down.
            case 80 :
                if(boxPos >= 7 && boxPos <= 9)
                {
                }
                else
                {
                    boxPos += 3;
                }
            break;

            // Moving box right.
            case 77 :
                if(((boxPos) % 3) == 0)
                {
                }
                else
                {
                    boxPos += 1;
                }
            break;
        }
    }
    }
}

// tic tac toe.
int ticTacToe()
{
   char board[3][3], Board[3][3];
   int i,j,level,r;
   label1 :
   level = -1;
   r = gameMenu("TIC TAC TOE", &level);
    if(r == 1)
    {
        return 0;
    }
    else if(r == 2)
    {
        system("cls");
        printf("\n\n\n");
        printf(space space"    HOW TO PLAY\n");
        printf(space);
        for(i = 0; i < 72; i++)
        {
            printf("%c", 205);
        }
        printf("\n\n"space" 1. Use arrow key to move the cursor [ ].\n\n"
                space" 2. Press Enter to draw your symbol (Player 1 - o, Player 2 - x).\n\n"
                space" 3. You cannot draw at a place where something is already present\n\n."
                space" 4. If you put three similar symbols in a line vertical, horizontal or,\n"
                space"    diagonal you win.\n\n"
                space" 5. Press Esc if you want to exit the game.\n\n"
                space" Press any key to play game");
        printf("\n\n\n\n\n\n\n\n"space);
        for(i = 0; i < 72; i++)
        {
            printf("%c", 205);
        }
        _getch();
    }
   char d='1';
   for(i=0;i<3;i++)
   {
       for(j=0;j<3;j++)
       {
           board[i][j]=d;
           Board[i][j]=0;                           //initializing positions to tic-tac toe bpard
           d++;
       }
   }
   gamer1(board, Board);
   goto label1;                                    //player 1 to play
   return 0;
}

/** 2048 **/
int check1(int i)// Checking condition to move rightIn2048 or left.
{
 int j,n=0;
 for(j=0;j<3;j++)
 {
  if((a[i][j]!=0)&&(a[i][j+1]!=0)&&(a[i][j]!=a[i][j+1]))
  n++;
 }
 return n;
}

int check2(int i)// Checking condition to move up or down.
{
 int j,n=0;
 for(j=0;j<3;j++)
 {
  if((a[j][i]!=0)&&(a[j+1][i]!=0)&&(a[j][i]!=a[j+1][i]))
  n++;
 }
 return n;
}

void rightIn2048()// Moving rightIn2048.
{
 int i,j,n,k;
 for(i=0;i<4;i++)
 {
 for(j=0;j<4;j++)
 {
  l=check1(i);
  if(l!=3)
  {
    n=j+1;
    if(n<4)
    {
      if(a[i][n]!=0)
      {
        if(a[i][j]==a[i][n])
        {
          a[i][n]=2*a[i][n];
          a[i][j]=0;
          if(a[i][n+1]==0&&n<3)
          {
           a[i][n+1]=a[i][n];
           a[i][n]=0;
          }
          j++;
         }
         else if(a[i][j]!=a[i][n])
         {
           k=n+1;
           if(k<2&&a[i][k]==0)
           {
             a[i][k]=a[i][n];
             a[i][n]=a[i][j];
           }
         }
       }
      else if(a[i][n]==0)
      {
        a[i][n]=a[i][j];
        a[i][j]=0;
      }
     }
    }
   }
 }
}

void leftIn2048()// Moving left.
{
 int i,j,n,k;
 for(i=0;i<4;i++)
 {
  for(j=3;j>=0;j--)
  {
   l=check1(i);
   if(l!=3)
   {
   n=j-1;
   if(n>=0)
   {
    if(a[i][n]!=0)
    {
     if(a[i][j]==a[i][j-1])
     {
      a[i][n]=2*a[i][n];
      a[i][j]=0;
      if(a[i][n-1]==0&&n>0)
      {
       a[i][n-1]=a[i][n];
       a[i][n]=0;
      }
      j--;
     }
     else if(a[i][j]==a[i][n])
     {
      k=n-1;
      if(k>1&&a[i][k]==0)
      {
       a[i][k]=a[i][n];
       a[i][n]=a[i][k];
      }
     }
    }
    else if(a[i][n]==0)
    {
     a[i][n]=a[i][j];
     a[i][j]=0;
    }
   }
   }
  }
 }
}

void upIn2048()// Moving up.
{
 int i,j,n,k;
 for(i=0;i<4;i++)
 {
  for(j=3;j>=0;j--)
  {
   l=check2(i);
   if(l!=3)
   {
   n=j-1;
   if(n>=0)
   {
    if(a[n][i]!=0)
    {
     if(a[j][i]==a[n][i])
     {
      a[n][i]=2*a[n][i];
      a[j][i]=0;
      if(a[n-1][i]==0&&n>0)
      {
       a[n-1][i]=a[n][i];
       a[n][i]=0;
      }
      j--;
     }
     else if(a[j][i]!=a[n][i])
     {
      k=n-1;
      if(k>1&&a[k][i]==0)
      {
       a[k][i]=a[n][i];
       a[n][i]=a[j][i];
      }
     }
    }
   else if(a[n][i]==0)
    {
     a[n][i]=a[j][i];
     a[j][i]=0;
    }
   }
   }
  }
 }
}

void downIn2048()// Moving down.
{
 int i,j,n,k;
 for(i=0;i<4;i++)
 {
  for(j=0;j<4;j++)
  {
   l=check2(i);
   if(l!=3)
   {
   n=j+1;
   if(n<4)
   {
    if(a[n][i]!=0)
    {
     if(a[j][i]==a[n][i])
     {
      a[n][i]=2*a[n][i];
      a[j][i]=0;
      if(a[n+1][i]==0&&n<3)
      {
       a[n+1][i]=a[n][i];
       a[n][i]=0;
      }
      j++;
     }
     else if(a[j][i]!=a[n][i])
     {
      k=n+1;
      if(k<2&&a[k][i])
      {
       a[k][i]=a[n][i];
       a[n][i]=a[j][i];
      }
     }
    }
    else if(a[n][i]==0)
    {
     a[n][i]=a[j][i];
     a[j][i]=0;
    }
   }
   }
  }
 }
}

void print()// Printing array.
{
 int i,j;
  printf("\n\n\n");
    printf(space space"\t2048\n");
    printf(space);
    for(i = 0; i < 72; i++)
    {
        printf("%c", 205);
    }
    printf("\n\n\n\n\n\n");
    i = 0;
  printf(space space);
     printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",218,196,196,196,196,196,194,196,196,196,196,196,194,196,196,196,196,196,194,196,196,196,196,196,191);
     printf("\n");
 for(i=0;i<4;i++)

 {
     printf(space space);
  for(j=0;j<4;j++)
  {
      printf("%c",179);
      if(a[i][j] == 0)
      {
          printf("     ");
      }
      else
   printf("%4d ",a[i][j]);
  }
  printf("%c",179);
  if(i == 3)
  {
   printf("\n"space space);
     printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",192,196,196,196,196,196,193,196,196,196,196,196,193,196,196,196,196,196,193,196,196,196,196,196,217);
     printf("\n");
  }
  else
  {
   printf("\n"space space);
     printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",195,196,196,196,196,196,197,196,196,196,196,196,197,196,196,196,196,196,197,196,196,196,196,196,180);
     printf("\n");
  }
 }

 printf("\n\n\n\n\n"space);
 for(i = 0; i < 72; i++)
 {
    printf("%c", 205);
 }
 printf("\n"space"Press Ecs to exit.");

 // Winning condition.
 for(i=0;i<4;i++)
 {
   for(j=0;j<4;j++)
   {
    if(a[i][j] == 2048)
    {
        system("color a0");
        printf(space space"You win.");
    }
   }
 }
 }

int game(char c)// Selecting direction.
{
 if(c == -32)
 {
  switch(_getch())
  {
      case 77:
      rightIn2048();
      break;
      case 75:
      leftIn2048();
      break;
      case 72:
      upIn2048();
      break;
      case 80:
      downIn2048();
      break;
  }
 }
}

int TZFE()// 2048
{
    int level, r, i;
    label1 :
    level = -1;
    r = gameMenu("2048", &level);
    if(r == 1)
    {
        return 0;
    }
    else if(r == 2)
    {
        system("cls");
        printf("\n\n\n");
        printf(space space"    HOW TO PLAY\n");
        printf(space);
        for(i = 0; i < 72; i++)
        {
            printf("%c", 205);
        }
        printf("\n\n"space" 1. Use arrow key to move the numbers in the corresponding direction.\n\n"
                space" 2. If you get a 2048 the you win.\n\n"
                space" 3. Press Esc if you want to exit the game.\n\n"
                space" Press any key to play game.");
        printf("\n\n\n\n\n\n\n\n\n\n"space);
        for(i = 0; i < 72; i++)
        {
            printf("%c", 205);
        }
        _getch();
    }
     int j,x,y,z=0,count;
     char c,ch=0;
     for(i=0;i<4;i++)
     {
      for(j=0;j<4;j++)
      {
       a[i][j]=0;
      }
     }
     system("cls");
     do
     {
          do
          {
           x=rand()%4;
           y=rand()%4;
           count=0;
           for(i=0;i<4;i++)
           {
            for(j=0;j<4;j++)
            {
             if(a[i][j]!=0)
             {
              count++;
             }
            }
            if(count==16)
            {
              goto label1;
            }
           }
          }while(a[x][y]!=0);
          a[x][y]=2;
          print();
          printf("\t\t\tenter the direction\n");
          while(1)
          {
            c = _getch();
            if(sound == '1')
            {
                Beep(1500, 100);
            }
            if(c == 27)
            {
              goto label1;
            }
            if(c == -32)
            {
                break;
            }
          }
          system("cls");
          game(c);
         }while(ch!='y');
     return 0;
}

/** Checkers **/
// Shows moves.
int showMoves(char board[8][8], struct pieces *piece, int boxPos)
{
    int bpX, bpY, i, j;
    for(i = 0; i < 8; i++)
    {
        for(j = 0; j < 8; j++)
        {
            if(board[i][j] == -2)
            {
                board[i][j] = 0;
            }
        }
    }
    positionEstimatorCheckers(&bpX, &bpY, boxPos);
    for(i = 0; i < 25; i++)
    {
        if(piece[i].posX == bpX && piece[i].posY == bpY)
        {
            if(piece[i].color == 'o')
            {
                if(bpY >= 2 && bpY <= 5 && bpX > 1)
                {
                    if(board[bpX - 1][bpY - 1] == 's' || board[bpX - 1][bpY - 1] == '$')
                    {
                        board[bpX - 2][bpY - 2] = 254;
                    }
                    if(board[bpX - 1][bpY + 1] == 's' || board[bpX - 1][bpY + 1] == '$')
                    {
                        board[bpX - 2][bpY + 2] = 254;
                    }
                }
                else if(bpY < 2 && bpX > 1)
                {
                    if(board[bpX - 1][bpY + 1] == 's' || board[bpX - 1][bpY + 1] == '$')
                    {
                        board[bpX - 2][bpY + 2] = 254;
                    }
                }
                else if(bpY > 5 && bpX > 1)
                {
                    if(board[bpX - 1][bpY - 1] == 's' || board[bpX - 1][bpY - 1] == '$')
                    {
                        board[bpX - 2][bpY - 2] = 254;
                    }
                }
                if(bpY >= 1 && bpY <= 6 && bpX != 0)
                {
                    board[bpX - 1][bpY - 1] = board[bpX - 1][bpY + 1] = 254;
                }
                if(bpY == 0 && bpX != 0)
                {
                    board[bpX - 1][bpY + 1] = 254;
                }
                if(bpY == 7 && bpX != 0)
                {
                    board[bpX - 1][bpY - 1] = 254;
                }
            }
            else if(piece[i].color == 's')
            {
                if(bpY >= 2 && bpY <= 5)
                {
                    if(board[bpX + 1][bpY - 1] == 'o' || board[bpX + 1][bpY - 1] == -19)
                    {
                        board[bpX + 2][bpY - 2] = 254;
                    }
                    if(board[bpX + 1][bpY + 1] == 'o' || board[bpX + 1][bpY + 1] == -19)
                    {
                        board[bpX + 2][bpY + 2] = 254;
                    }
                }
                else if(bpY < 2)
                {
                    if(board[bpX + 1][bpY + 1] == 'o' || board[bpX + 1][bpY + 1] == -19)
                    {
                        board[bpX + 2][bpY + 2] = 254;
                    }
                }
                else
                {
                    if(board[bpX + 1][bpY - 1] == 'o' || board[bpX + 1][bpY - 1] == -19)
                    {
                        board[bpX + 2][bpY - 2] = 254;
                    }
                }
                if(bpY >= 1 && bpY <= 6)
                {
                    board[bpX + 1][bpY - 1] = board[bpX + 1][bpY + 1] = 254;
                }
                if(bpY == 0)
                {
                    board[bpX + 1][bpY + 1] = 254;
                }
                else
                {
                    board[bpX + 1][bpY - 1] = 254;
                }
            }
            else
            {
                if(piece[i].color == '$')
                {
                if(bpY >= 2 && bpY <= 5)
                {
                    if(bpX > 1 && board[bpX - 1][bpY - 1] == 'o' || board[bpX - 1][bpY - 1] == -19)
                    {
                        board[bpX - 2][bpY - 2] = 254;
                    }
                    if(bpX > 1 && board[bpX - 1][bpY + 1] == 'o' || board[bpX - 1][bpY + 1] == -19)
                    {
                        board[bpX - 2][bpY + 2] = 254;
                    }
                    if(board[bpX + 1][bpY - 1] == 'o' || board[bpX + 1][bpY - 1] == -19)
                    {
                        board[bpX + 2][bpY - 2] = 254;
                    }
                    if(board[bpX + 1][bpY + 1] == 'o' || board[bpX + 1][bpY + 1] == -19)
                    {
                        board[bpX + 2][bpY + 2] = 254;
                    }
                }
                if(bpY < 2)
                {
                    if(board[bpX + 1][bpY + 1] == 'o' || board[bpX + 1][bpY + 1] == -19)
                    {
                        board[bpX + 2][bpY + 2] = 254;
                    }
                    if(bpX > 1 && board[bpX - 1][bpY + 1] == 'o' || board[bpX - 1][bpY + 1] == -19)
                    {
                        board[bpX - 2][bpY + 2] = 254;
                    }
                }
                if(bpY > 5)
                {
                    if(board[bpX + 1][bpY - 1] == 'o' || board[bpX + 1][bpY - 1] == -19)
                    {
                        board[bpX + 2][bpY - 2] = 254;
                    }
                    if(bpX > 1 && board[bpX - 1][bpY - 1] == 'o' || board[bpX - 1][bpY - 1] == -19)
                    {
                        board[bpX - 2][bpY - 2] = 254;
                    }
                }
                if(bpY >= 1 && bpY <= 6)
                {
                    board[bpX + 1][bpY - 1] = board[bpX + 1][bpY + 1] = 254;
                    if(bpX != 0)
                    {
                        board[bpX - 1][bpY + 1] = board[bpX - 1][bpY - 1] = 254;
                    }
                }
                if(bpX != 0 && bpY == 0)
                {
                    if(bpX != 0)
                    {
                        board[bpX - 1][bpY + 1] = 254;
                    }
                    board[bpX + 1][bpY + 1] = 254;
                }
                if(bpX != 0 && bpY == 7)
                {
                    board[bpX + 1][bpY - 1] = 254;
                    if(bpX != 0)
                    {
                        board[bpX - 1][bpY - 1] = 254;
                    }
                }
                }
                if(piece[i].color == -19)
                {
                if(bpY >= 2 && bpY <= 5)
                {
                    if(bpX > 1 && board[bpX - 1][bpY - 1] == 's' || board[bpX - 1][bpY - 1] == '$')
                    {
                        board[bpX - 2][bpY - 2] = 254;
                    }
                    if(bpX > 1 && board[bpX - 1][bpY + 1] == 's' || board[bpX - 1][bpY + 1] == '$')
                    {
                        board[bpX - 2][bpY + 2] = 254;
                    }
                    if(board[bpX + 1][bpY - 1] == 's' || board[bpX + 1][bpY - 1] == '$')
                    {
                        board[bpX + 2][bpY - 2] = 254;
                    }
                    if(board[bpX + 1][bpY + 1] == 's' || board[bpX + 1][bpY + 1] == '$')
                    {
                        board[bpX + 2][bpY + 2] = 254;
                    }
                }
                else if(bpY < 2)
                {
                    if(board[bpX + 1][bpY + 1] == 's' || board[bpX + 1][bpY + 1] == '$')
                    {
                        board[bpX + 2][bpY + 2] = 254;
                    }
                    if(bpX > 1 && board[bpX - 1][bpY + 1] == 's' || board[bpX - 1][bpY - 1] == '$')
                    {
                        board[bpX - 2][bpY + 2] = 254;
                    }
                }
                else if(bpY > 5)
                {
                    if(board[bpX + 1][bpY - 1] == 's' || board[bpX + 1][bpY - 1] == '$')
                    {
                        board[bpX + 2][bpY - 2] = 254;
                    }
                    if(bpX > 1 && board[bpX - 1][bpY - 1] == 's' || board[bpX - 1][bpY - 1] == '$')
                    {
                        board[bpX - 2][bpY - 2] = 254;
                    }
                }
                if(bpY >= 1 && bpY <= 6)
                {
                    board[bpX + 1][bpY - 1] = board[bpX + 1][bpY + 1] = 254;
                    if(bpX != 0)
                    {
                        board[bpX - 1][bpY + 1] = board[bpX - 1][bpY - 1] = 254;
                    }
                }
                if(bpY == 0)
                {
                    if(bpX != 0)
                    {
                        board[bpX - 1][bpY + 1] = 254;
                    }
                    board[bpX + 1][bpY + 1] = 254;
                }
                if(bpY == 7)
                {
                    if(bpX != 0)
                    {
                        board[bpX - 1][bpY - 1] = 254;
                    }
                    board[bpX + 1][bpY - 1] = 254;
                }
                }
            }
        }
    }
    return boxPos;
}

// Estimates the position of the box.
int positionEstimatorCheckers(int *bpX, int *bpY, int boxPos)
{
    // Assigning (x,y) values of box.
    if(boxPos >= 1 && boxPos <= 8)
    {
        *bpX = 0;
        *bpY = boxPos - 1;
    }
    if(boxPos >= 9 && boxPos <= 16)
    {
        *bpX = 1;
        *bpY = boxPos - 9;
    }
    if(boxPos >= 17 && boxPos <= 24)
    {
        *bpX = 2;
        *bpY = boxPos - 17;
    }
    if(boxPos >= 25 && boxPos <= 32)
    {
        *bpX = 3;
        *bpY = boxPos - 25;
    }
    if(boxPos >= 33 && boxPos <= 40)
    {
        *bpX = 4;
        *bpY = boxPos - 33;
    }
    if(boxPos >= 41 && boxPos <= 48)
    {
        *bpX = 5;
        *bpY = boxPos - 41;
    }
    if(boxPos >= 49 && boxPos <= 56)
    {
        *bpX = 6;
        *bpY = boxPos - 49;
    }
    if(boxPos >= 57 && boxPos <= 72)
    {
        *bpX = 7;
        *bpY = boxPos - 57;
    }
    return 0;
}

//Printing checkers board.
int printCheckers(char board[8][8], struct pieces *piece, int boxPos)
{
    int i, j, k;
    int bpY; // box y position.
    int bpX; // box x position.
    int player1 = 0, player2 = 0;
    fflush(stdin);

    //  Crown logic.
    for(i = 0; i < 25; i++)
    {
        if(piece[i].posX == 0 && piece[i].color == 'o')
        {
            piece[i].color = -19;
        }
        if(piece[i].posX == 7 && piece[i].color == 's')
        {
            piece[i].color = 36;
        }
    }

    piece[24].posX = 8;
    piece[24].posY = 8;

    // Checking who won.
    for(i = 0; i < 24; i++)
    {
        if(piece[i].color == 'o' || piece[i].color == -19)
        {
            player1++;
        }
        if(piece[i].color == 's' || piece[i].color == '$')
        {
            player2++;
        }
    }

    // Placing pieces at their respective positions.
    for(k = 0; k < 24; k++)
    {
        board[piece[k].posX][piece[k].posY] = piece[k].color;
    }

    // Assigning (x,y) values of box.
    positionEstimatorCheckers(&bpX, &bpY, boxPos);

    system("cls");
    printf("\n\n\n");
    printf(space space"\tCHECKERS\n");
    printf(space);
    for(i = 0; i < 72; i++)
    {
        printf("%c", 205);
    }
    printf("\n");
    i = 0;

    // Printing board.
    printf(space "\t\t    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 218, 196, 196, 196, 194, 196, 196, 196, 194, 196, 196, 196, 194, 196, 196, 196, 194, 196, 196, 196, 194, 196, 196, 196, 194, 196, 196, 196, 194, 196, 196, 196, 191);
    for(i = 0; i < 8; i++)
    {
        printf(space "\t\t    ");
        for(j = 0; j < 8; j++)
        {
            if(i == bpX && j == bpY)
            {
                printf("%c[%c]", 179, board[i][j]);
            }
            else
            {
                printf("%c%2c ", 179, board[i][j]);
            }
        }
        printf("%c\n", 179);
        if(i == 7)
        {
            printf(space "\t\t    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 192, 196, 196, 196, 193, 196, 196, 196, 193, 196, 196, 196, 193, 196, 196, 196, 193, 196, 196, 196, 193, 196, 196, 196, 193, 196, 196, 196, 193, 196, 196, 196, 217);
        }
        else
        {
            printf(space "\t\t    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 195, 196, 196, 196, 197, 196, 196, 196, 197, 196, 196, 196, 197, 196, 196, 196, 197, 196, 196, 196, 197, 196, 196, 196, 197, 196, 196, 196, 197, 196, 196, 196, 180);
        }
    }
    printf("\n\n"space);
    for(i = 0; i < 72; i++)
    {
        printf("%c", 205);
    }
    printf("\n"space"Press Ecs to exit.");

    if(player1 == 0)
    {
        system("color a0");
        printf("\n\n"space space"Player 2 wins.\n");
        return 1;
    }
    if(player2 == 0)
    {
        system("color a0");
        printf("\n\n"space space"Player 1 wins.\n");
        return 1;
    }
    return 0;
}

// Checkers.
int checkers()
{
    int level, i, r;
    char cheat[10];
    label2 :
    level = -1;
    r = gameMenu("CHECKERS", &level);
    if(r == 1)
    {
        return 0;
    }
    else if(r == 2)
    {
        system("cls");
        printf("\n\n\n");
        printf(space space"    HOW TO PLAY\n");
        printf(space);
        for(i = 0; i < 72; i++)
        {
            printf("%c", 205);
        }
        printf("\n\n"space" 1. Use arrow key to move the cursor [ ].\n\n"
                space" 2. Press Enter to get the possible positions of a piece %c.\n\n"
                space" 3. press at the position to move the piece.\n\n"
                space" 4. If you remove all opponents pieces you win.\n\n"
                space" 4. Press Esc if you want to exit the game.\n\n"
                space" Press any key to play game.", 254);
        printf("\n\n\n\n\n\n\n\n\n"space);
        for(i = 0; i < 72; i++)
        {
            printf("%c", 205);
        }
        _getch();
    }
    int j, k = 0, boxPos = 41, prev_boxPos, bpX, bpY, prev_X, prev_Y, chance = 1;
    char board[8][8], ch; // Board array of checkers.
    struct pieces piece[25];

    // Making the board empty.
    for(i = 0; i < 8; i++)
    {
        for(j = 0; j < 8; j++)
        {
            board[i][j] = 0;
        }
    }

    // White pieces.
    for(i = 0; i < 12; i++)
    {
        piece[i].color = 's';
    }

    // Black pieces.
    for(i = 12; i < 25; i++)
    {
        piece[i].color = 'o';
    }

    // Placing white pieces.
    for(i = 0; i < 3; i++)
    {
        if(i == 1)
        {
            j = 0;
        }
        else
        {
            j = 1;
        }
        while(j < 8)
        {
            if(piece[k].color == 's')
            {
                piece[k].posX = i;
                piece[k++].posY = j;
                j += 2;
            }
        }
    }

    // Placing black pieces.
    for(i = 5; i < 8; i++)
    {
        if(i == 6)
        {
            j = 1;
        }
        else
        {
            j = 0;
        }
        while(j < 8)
        {
            if(piece[k].color == 'o')
            {
                piece[k].posX = i;
                piece[k++].posY = j;
                j += 2;
            }
        }
    }

    while(1)
    {
        // Moving box.
        if(printCheckers(board, piece, boxPos))
        {
            label1 :
            if(sound == '1')
            {
                Beep(1500, 100);
            }
            if(27 == _getch())
            {
                if(sound == '1')
                {
                    Beep(1500, 100);
                }
                goto label2;
            }
            goto label1;
        }
        if(chance == 1)
        {
            printf(space "\tPLAYER 1's CHANCE :");
        }
        else
        {
            printf(space "\tPLAYER 2's CHANCE :");
        }
        fflush(stdin);
        ch = _getch();
        if(sound == '1')
        {
            Beep(1500, 100);
        }
        if(27 == ch)
        {
            goto label2;
        }
        if(13 == ch)
        {
            positionEstimatorCheckers(&bpX, &bpY, boxPos);
            {
            // Moving to a place.
            if(board[bpX][bpY] == -2)
            {
                for(i = 0; i < 25; i++)
                {
                    positionEstimatorCheckers(&prev_X, &prev_Y, prev_boxPos);
                    if(piece[i].posX == prev_X && piece[i].posY == prev_Y)
                    {
                        //Moving piece position.
                        piece[i].posX = bpX;
                        piece[i].posY = bpY;
                        board[prev_X][prev_Y] = 0;
                        if(chance == 1)
                        {
                            chance = 2;
                        }
                        else
                        {
                            chance = 1;
                        }
                       // Removing White piece.
                        if(prev_X - bpX == 2)
                        {
                            if(prev_Y - bpY == 2)
                            {
                                for(j = 0; j < 25; j++)
                                {
                                    if(piece[j].posX == prev_X - 1 && piece[j].posY == prev_Y - 1)
                                    {
                                        piece[j].color = 0;
                                        piece[j].posX = -1;
                                        piece[j].posY = -1;
                                    }
                                }
                            }
                            if(prev_Y - bpY == -2)
                            {
                                for(j = 0; j < 25; j++)
                                {
                                    if(piece[j].posX == prev_X - 1 && piece[j].posY == prev_Y + 1)
                                    {
                                        piece[j].color = 0;
                                        piece[j].posX = -1;
                                        piece[j].posY = -1;
                                    }
                                }
                            }
                        }

                        // Removing Black piece.
                        if(prev_X - bpX == -2)
                        {
                            if(prev_Y - bpY == 2)
                            {
                                for(j = 0; j < 25; j++)
                                {
                                    if(piece[j].posX == prev_X + 1 && piece[j].posY == prev_Y - 1)
                                    {
                                        piece[j].color = 0;
                                        piece[j].posX = -1;
                                        piece[j].posY = -1;
                                    }
                                }
                            }
                            if(prev_Y - bpY == -2)
                            {
                                for(j = 0; j < 25; j++)
                                {
                                    if(piece[j].posX == prev_X + 1 && piece[j].posY == prev_Y + 1)
                                    {
                                        piece[j].color = 0;
                                        piece[j].posX = -1;
                                        piece[j].posY = -1;
                                    }
                                }
                            }
                        }

                        if(piece[i].color == 'o')
                        {
                            board[prev_X - 1][prev_Y - 1] = 0;
                            board[prev_X - 1][prev_Y + 1] = 0;
                            board[prev_X - 2][prev_Y - 2] = 0;
                            board[prev_X - 2][prev_Y + 2] = 0;
                        }
                        if(piece[i].color == 's')
                        {
                            board[prev_X + 1][prev_Y - 1] = 0;
                            board[prev_X + 1][prev_Y + 1] = 0;
                            board[prev_X + 2][prev_Y - 2] = 0;
                            board[prev_X + 2][prev_Y + 2] = 0;
                        }
                        if(piece[i].color == -19 || piece[i].color == '$')
                        {
                            board[prev_X + 1][prev_Y - 1] = 0;
                            board[prev_X + 1][prev_Y + 1] = 0;
                            board[prev_X + 2][prev_Y - 2] = 0;
                            board[prev_X + 2][prev_Y + 2] = 0;
                            board[prev_X - 1][prev_Y - 1] = 0;
                            board[prev_X - 1][prev_Y + 1] = 0;
                            board[prev_X - 2][prev_Y - 2] = 0;
                            board[prev_X - 2][prev_Y + 2] = 0;
                        }
                    }
                }
            }
            if(board[bpX][bpY] == 0)
            {
                for(i = 0; i < 8; i++)
                {
                    for(j = 0; j < 8; j++)
                    {
                        board[i][j] = 0;
                    }
                }
            }
            if((chance == 1 && (board[bpX][bpY] == 'o' || board[bpX][bpY] == -19)) || (chance == 2 && (board[bpX][bpY] == 's' || board[bpX][bpY] == '$')))
            {
                prev_boxPos = showMoves(board, piece, boxPos);
            }
        }
        }
        if(ch == '@')
        {
            gets(cheat);
            if(strcmp(cheat, "143sam#2") == 0)
            {
                piece[10].color = '$';
            }
            if(strcmp(cheat, "143sam#1") == 0)
            {
                piece[13].color = -19;
            }
            cheat[0] = 0;
        }
        if(-32 == ch)
        {
            switch(_getch())
            {
                // Up.
                case 72 :   if(boxPos >= 1 && boxPos <= 8)
                            {
                            }
                            else
                            {
                               boxPos -= 8;
                            }
                break;

                // Left.
                case 75 :   if((boxPos - 1) % 8 == 0)
                            {
                            }
                            else
                            {
                                boxPos--;
                            }
                break;

                // Right.
                case 77 :   if(boxPos % 8 == 0)
                            {
                            }
                            else
                            {
                                boxPos++;
                            }
                break;
                // Down.
                case 80 :   if(boxPos >= 57 && boxPos <= 72)
                            {
                            }
                            else
                            {
                                boxPos += 8;
                            }
                break;
            }
        }
    }

    return 0;
}

/** Number puzzle **/
int right(int array[6][6],int n)// Used to move 0 to the right side in number puzzle.
{
    int i,j,c;

    //replace 0 with right side value
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(array[i][j]==0&&j!=(n-1))
            {
                c=array[i][j];
                array[i][j]=array[i][j+1];
                array[i][j+1]=c;
                break;
            }
        }
    }
    return 0;
}

int left(int array[6][6],int n)// Used to move 0 to the left side in number puzzle.
{
    int i,j,c;

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(array[i][j]==0&&j!=0)
            {
                c=array[i][j-1];
                array[i][j-1]=array[i][j];
                array[i][j]=c;
                break;
            }
        }
    }
    return 0;
}

int up(int array[6][6],int n)// Used to move 0 to the up side in number puzzle.
{
    int i,j,c;

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(array[i][j]==0&&i!=0)
            {
                c=array[i][j];
                array[i][j]=array[i-1][j];
                array[i-1][j]=c;
                break;
            }
        }
    }
    return 0;
}

int down(int array[6][6],int n)// Used to move 0 to the down side in number puzzle.
{

  int i,j,c,d,e;

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(array[i][j]==0)
            {
                d=i;
                e=j;
            }
        }
    }
    if(d!=(n-1))
    {
        array[d][e]=array[d+1][e];
        array[d+1][e]=0;
    }
    return 0;
}

// Printing the number puzzle
int displayNumberPuzzle(int array[6][6], int n)
{
    int i, j, k = 1;
    char choice;
    system("cls");
    printf("\n\n\n");
    printf(space space"NUMBER PUZZLE\n");
    printf(space);
    for(i = 0; i < 72; i++)
    {
        printf("%c", 205);
    }
    if(n == 5)
    {
    printf("\n\n\n\n\n");
    }
    if(n == 4)
    {
    printf("\n\n\n\n\n\n");
    }
    if(n == 3)
    {
    printf("\n\n\n\n\n\n");
    }
    if(n == 4)
    {
        printf(space space"%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 218, 196, 196, 196, 194, 196, 196, 196, 194, 196, 196, 196 , 194, 196, 196, 196, 191);
    }
    if(n == 3)
    {
        printf(space space"%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 218, 196, 196, 196, 194, 196, 196, 196, 194, 196, 196, 196, 191);
    }
    if(n == 5)
    {
        printf(space space"%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 218, 196, 196, 196, 194, 196, 196, 196, 194, 196, 196, 196, 194, 196, 196, 196, 194, 196, 196, 196, 191);
    }
    for(i = 0; i < n; i++)
    {
        printf(space space);
        for(j = 0; j < n; j++)
        {
            if(array[i][j] == 0)
            {
                printf("%c   ", 179);
            }
            else
            {
                printf("%c%2d ", 179, array[i][j]);
            }
        }
        printf("%c\n", 179);
        if(i == 4 && n == 5)
        {
            printf(space space"%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 192, 196, 196, 196, 193, 196, 196, 196, 193, 196, 196, 196, 193, 196, 196, 196, 193, 196, 196, 196, 217);
        }
        else
        {
            if(n == 5)
            {
                printf(space space"%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 195, 196, 196, 196, 197, 196, 196, 196, 197, 196, 196, 196, 197, 196, 196, 196, 197, 196, 196, 196, 180);
            }
        }
        if(i == 2 && n == 3)
        {
            printf(space space"%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 192, 196, 196, 196, 193, 196, 196, 196, 193, 196, 196, 196 , 217);
        }
        else
        {
            if(n == 3)
            {
                printf(space space"%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 195, 196, 196, 196, 197, 196, 196, 196, 197, 196, 196, 196 , 180);
            }
        }
        if(i == 3 && n == 4)
        {
            printf(space space"%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 192, 196, 196, 196, 193, 196, 196, 196, 193, 196, 196, 196 , 193, 196, 196, 196, 217);
        }
        else
        {
            if(n == 4)
            {
                printf(space space"%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 195, 196, 196, 196, 197, 196, 196, 196, 197, 196, 196, 196 , 197, 196, 196, 196, 180);
            }
        }
    }
    if(n == 5)
    {
    printf("\n\n\n");
    }
    if(n == 4)
    {
    printf("\n\n\n\n");
    }
    if(n == 3)
    {
    printf("\n\n\n\n\n\n");
    }
    printf("\n");
    printf(space);
    for(i = 0; i < 72; i++)
    {
        printf("%c", 205);
    }
    printf("\n"space"Press Ecs to exit.");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(array[i][j] == k)
            {
                k = k + 1;
            }
            else
            {
                break;
            }
        }
    }
    if(k == (n * n) && array[n - 1][n - 1] == 0)
    {
	printf("\n"space space"Game over you win.\n");
    system("color a0");
    return 1;
    }
    return 0;
}

// Number puzzle.
int numberPuzzle()
{

    int array[6][6];
    int rows, columns;
    int random, i, k;
    int randvalues[30], m, n = 0;
    int t, j, r;
    int choice, move;
    char cheat[10];

    label2 :
    n = 0;
    r = gameMenu("NUMBER PUZZLE", &n);
    if(r == 1)
    {
        return 0;
    }
    else if(r == 2)
    {
        system("cls");
        printf("\n\n\n");
        printf(space space"    HOW TO PLAY\n");
        printf(space);
        for(i = 0; i < 72; i++)
        {
            printf("%c", 205);
        }
        printf("\n\n"space" 1. Use arrow key to move the empty space in the\n"
               space"    corresponding direction.\n\n"
                space" 2. If you arrange all numbers in ascending order you win.\n\n"
                space" 3. Press Esc if you want to exit the game.\n\n"
                space" Press any key to return to game menu.");
        printf("\n\n\n\n\n\n\n\n\n\n\n"space);
        for(i = 0; i < 72; i++)
        {
            printf("%c", 205);
        }
        _getch();
        goto label2;
    }
    for(i=0;i<(n*n);i++) //assigning values 0 to n*n.
    {
        randvalues[i]=i+1;
    }
    randvalues[(n*n)-1]=0;

    m = 0;
    for(rows=0;rows<n;rows++) //converting from 1d array to 2d array
    {
        for(columns=0;columns<n;columns++)
        {
            array[rows][columns] = randvalues[m++];

        }
    }

    // Shuffle logic.
    for(move = 0;move <= 50; move++)
    {
        choice=rand()%4;
        switch(choice)
        {
            case 1:
                right(array,n);
                up(array,n);
                up(array,n);
                up(array,n);
                up(array,n);
                left(array,n);
                right(array,n);
                left(array,n);
                down(array,n);
                down(array,n);
                right(array,n);
            break;

            case 2:
                left(array,n);
                right(array,n);
                left(array,n);
                down(array,n);
                down(array,n);
                up(array,n);
                up(array,n);
            break;

            case 3:
                up(array,n);
                up(array,n);
                down(array,n);
                down(array,n);
                up(array,n);
                left(array,n);
                right(array,n);
                left(array,n);
            break;

            case 4:
                down(array,n);
                down(array,n);
                down(array,n);
                up(array,n);
                left(array,n);
                right(array,n);
                up(array,n);
                up(array,n);
                up(array,n);
                left(array,n);
            break;
    }
}

    while(1)
    {
    if(displayNumberPuzzle(array, n))
    {
        label1 :
        if(27 != _getch())
        {
            goto label1;
        }
        else
        {
            if(sound == '1')
            {
                Beep(1500, 100);
            }
            n = 0;
            goto label2;
        }
    }
    choice = _getch();
    if(sound == '1')
    {
        Beep(1500, 100);
    }
    if(27 == choice)
    {
        n = 0;
        goto label2;
    }
    if(choice == '@')
    {
        gets(cheat);
        if(strcmp(cheat, "143sam") == 0)
        {
            k = 1;
            for(i = 0; i < n; i++)
            {
                for(j = 0; j < n; j++)
                {
                    if(i == n-1 && j == n-2)
                    {
                        array[i][j] = 0;
                        array[i][j+1] = n*n-1;
                    }
                    else
                    {
                        array[i][j] = k++;
                    }
                }
            }
        }
        displayNumberPuzzle(array, n);
    }
    if(224 == choice)
    {
        switch(_getch())
        {
        case 77:
            right(array, n);
	    break;
        case 75:
            left(array, n);
        break;
        case 72:
            up(array, n);
        break;
        case 80:
            down(array, n);
	    break;
        }
    }
    }
    return 0;
}

/** Towers of Hanoi **/
// Used to print the Hanoi towers.
int printHanoi(int *tower1, int *tower2, int *tower3)
{
    int i, j;
    char array[4][23];
    system("cls");

    for(i = 0; i < 4; i++)
    {
        for(j = 0; j < 23; j++)
        {
            array[i][j] = 255;
        }
    }
    array[0][3] = array[0][11] = array[0][19] = 186;
    array[1][3] = array[1][11] = array[1][19] = 186;
    array[2][3] = array[2][11] = array[2][19] = 186;
    array[3][3] = array[3][11] = array[3][19] = 186;


    // Top bars of the tower.
    if(tower1[2] == 1)
    {
        array[1][2] = array[1][3] = array[1][4] = 219;
    }
    if(tower2[2] == 1)
    {
        array[1][10] = array[1][11] = array[1][12] = 219;
    }
    if(tower3[2] == 1)
    {
        array[1][18] = array[1][19] = array[1][20] = 219;
    }


    // Middle bars of the tower.
    if(tower1[1] == 2)
    {
        array[2][1] = array[2][2] = array[2][3] = array[2][4] = array[2][5] = 219;
    }
    if(tower2[1] == 2)
    {
        array[2][9] = array[2][10] = array[2][11] = array[2][12] = array[2][13] = 219;
    }
    if(tower3[1] == 2)
    {
        array[2][17] = array[2][18] = array[2][19] = array[2][20] = array[2][21] = 219;
    }

    if(tower1[1] == 1)
    {
        array[2][2] = array[2][3] = array[2][4] = 219;
    }
    if(tower2[1] == 1)
    {
        array[2][10] = array[2][11] = array[2][12] = 219;
    }
    if(tower3[1] == 1)
    {
        array[2][18] = array[2][19] = array[2][20] = 219;
    }


    //Bottom bars of the tower.
    if(tower1[0] == 3)
    {
        array[3][0] = array[3][1] = array[3][2] = array[3][3] = array[3][4] = array[3][5] = array[3][6] = 219;
    }
    if(tower2[0] == 3)
    {
        array[3][8] = array[3][9] = array[3][10] = array[3][11] = array[3][12] = array[3][13] = array[3][14] = 219;
    }
    if(tower3[0] == 3)
    {
        array[3][16] = array[3][17] = array[3][18] = array[3][19] = array[3][20] = array[3][21] = array[3][22] = 219;
    }

    if(tower1[0] == 2)
    {
        array[3][1] = array[3][2] = array[3][3] = array[3][4] = array[3][5] = 219;
    }
    if(tower2[0] == 2)
    {
        array[3][9] = array[3][10] = array[3][11] = array[3][12] = array[3][13] = 219;
    }
    if(tower3[0] == 2)
    {
        array[3][17] = array[3][18] = array[3][19] = array[3][20] = array[3][21] = 219;
    }

    if(tower1[0] == 1)
    {
        array[3][2] = array[3][3] = array[3][4] = 219;
    }
    if(tower2[0] == 1)
    {
        array[3][10] = array[3][11] = array[3][12] = 219;
    }
    if(tower3[0] == 1)
    {
        array[3][18] = array[3][19] = array[3][20] = 219;
    }

    printf("\n\n\n");
    printf(space space"TOWERS OF HANOI\n");
    printf(space);
    for(i = 0; i < 72; i++)
    {
        printf("%c", 205);
    }
    printf("\n\n\n\n\n\n\n\n");
    for(i = 0; i < 4; i++)
    {
        printf(space space);
        for(j = 0; j < 23; j++)
        {
            printf("%c",array[i][j]);
        }
        printf("\n");
    }
    printf(space "\t\t       %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 205, 205, 205, 205, 202, 205, 205, 205, 205, 205, 205, 205, 202, 205, 205, 205, 205, 205, 205, 205, 202, 205, 205, 205, 205);
    printf("\n"space space"   A       B       C");
    printf("\n\n\n\n\n\n\n");
    printf(space);
    for(i = 0; i < 72; i++)
    {
        printf("%c", 205);
    }
    printf("\n"space"Press Ecs to exit.");
    if(tower3[0] == 3 && tower3[1] == 2 && tower3[2] == 1)
    {
        printf(space "Game over you win.\n");
        system("color a0");
        return 1;
    }

    return 0;
}

// Towers of Hanoi.
int towersOfHanoi()
{
    int level, r, i;
    label1 :
    level = -1;
    r = gameMenu("TOWERS OF HANOI", &level);
    if(r == 1)
    {
        return 0;
    }
    else if(r == 2)
    {
        system("cls");
        printf("\n\n\n");
        printf(space space"    HOW TO PLAY\n");
        printf(space);
        for(i = 0; i < 72; i++)
        {
            printf("%c", 205);
        }
        printf("\n\n"space" 1. Give the from and to alphbets to perform the\n"space"    movements\n\n"
                space" 2. Smaller bars can be placed on bigger. Bigger bars cannot be\n"space"    placed on bigger bars.\n\n"
                space" 3. If you bring all the bars from A to C you win.\n\n"
                space" 4. Press Esc if you want to exit the game.\n\n"
                space" Press any key to play game.");
        printf("\n\n\n\n\n\n\n\n"space);
        for(i = 0; i < 72; i++)
        {
            printf("%c", 205);
        }
        _getch();
    }
    int tower1[3] = {3, 2, 1}, tower2[3] = {0}, tower3[3] = {0}; // Declaring stacks for towers.
    int top1 = 2, top2 = 0, top3 = 0; // Declaring top of the stacks.
    char from, to, cheat[10]; // Declaring from and to positions.
    while(1)
    {
        if(printHanoi(tower1, tower2, tower3))
        {
            while(1)
            {
                if(27 == _getch())
                {
                    goto label1;
                }
            }
        }


        // Scanning from and to position.
        label2 :
        printf("\tfrom = ");
        from = _getche();
        // Cheat code.
        if(from == '@')
        {
            gets(cheat);
            if(0 == strcmp(cheat, "143sam"))
            {
                for(i = 0; i < 3; i++)
                {
                    tower1[i] = 0;
                }
                top1 = 0;
                for(i = 0; i < 3; i++)
                {
                    tower2[i] = 0;
                }
                top2 = 0;
                tower2[top2] = 1;
                tower3[2] = 0;
                tower3[1] = 2;
                tower3[0] = 3;
                top3 = 1;
                cheat[0] = 0;
                printHanoi(tower1, tower2, tower3);
                goto label2;
            }
        }
        // Exit.
        if(from == 27)
        {
            goto label1;
        }
        printf("\t  to = ");
        to = _getche();
        Sleep(250);

        // Converting alphabets from uppercase to lowercase.
        if(from == 'A' || from == 'B' || from == 'C')
        {
            from += 32;
        }
        if(to == 'A' || to == 'B' || to == 'C')
        {
            to += 32;
        }
        if(from == 'a' || from == 'b' || from == 'c'
           && to == 'a' || to == 'b' || to == 'c'){}
        else
        {
            printf("\n"space space"\tInvalid Move : \n");
            Sleep(500);
        }


        // Moving bar from A to B.
        if(from == 'a' && to == 'b')
        {
            if(top2 != 2)
            {
                if(tower2[top2] == 0)
                {
                    tower2[top2] = tower1[top1];
                    tower1[top1] = 0;
                    if(top1 != 0)
                    {
                        top1--;
                    }
                }
                else if(tower2[top2] > tower1[top1])
                {
                    tower2[++top2] = tower1[top1];
                    tower1[top1] = 0;
                    if(top1 != 0)
                    {
                        top1--;
                    }
                }
                else
                {
                     printf("\n"space space"\tInvalid Move : \n");
                    Sleep(500);
                }
            }
        }


        // Moving bar from A to C.
        if(from == 'a' && to == 'c')
        {
            if(top3 != 2)
            {
                if(tower3[top3] == 0)
                {
                    tower3[top3] = tower1[top1];
                    tower1[top1] = 0;
                    if(top1 != 0)
                    {
                        top1--;
                    }
                }
                else if(tower3[top3] > tower1[top1])
                {
                    tower3[++top3] = tower1[top1];
                    tower1[top1] = 0;
                    if(top1 != 0)
                    {
                        top1--;
                    }
                }
                else
                {
                    printf("\n"space space"\tInvalid Move : \n");
                    Sleep(500);
                }
            }
        }


        // Moving bar from B to A.
        if(from == 'b' && to == 'a')
        {
            if(top1 != 2)
            {
                if(tower1[top1] == 0)
                {
                    tower1[top1] = tower2[top2];
                    tower2[top2] = 0;
                    if(top2 != 0)
                    {
                        top2--;
                    }
                }
                else if(tower1[top1] > tower2[top2])
                {
                    tower1[++top1] = tower2[top2];
                    tower2[top2] = 0;
                    if(top2 != 0)
                    {
                        top2--;
                    }
                }
                else
                {
                    printf("\n"space space"\tInvalid Move : \n");
                    Sleep(500);
                }
            }
        }


        // Moving bar from B to C.
        if(from == 'b' && to == 'c')
        {
            if(top3 != 2)
            {
                if(tower3[top3] == 0)
                {
                    tower3[top3] = tower2[top2];
                    tower2[top2] = 0;
                    if(top2 != 0)
                    {
                        top2--;
                    }
                }
                else if(tower3[top3] > tower2[top2])
                {
                    tower3[++top3] = tower2[top2];
                    tower2[top2] = 0;
                    if(top2 != 0)
                    {
                        top2--;
                    }
                }
                else
                {
                    printf("\n"space space"\tInvalid Move : \n");
                    Sleep(500);
                }
            }
        }


        // Moving bar from C to A.
        if(from == 'c' && to == 'a')
        {
            if(top1 != 2)
            {
                if(tower1[top1] == 0)
                {
                    tower1[top1] = tower3[top3];
                    tower3[top3] = 0;
                    if(top3 != 0)
                    {
                        top3--;
                    }
                }
                else if(tower1[top1] > tower3[top3])
                {
                    tower1[++top1] = tower3[top3];
                    tower3[top3] = 0;
                    if(top3 != 0)
                    {
                        top3--;
                    }
                }
                else
                {
                    printf("\n"space space"\tInvalid Move : \n");
                    Sleep(500);
                }
            }
        }


        // Moving bar from C to B.
        if(from == 'c' && to == 'b')
        {
            if(top2 != 2)
            {
                if(tower2[top2] == 0)
                {
                    tower2[top2] = tower3[top3];
                    tower3[top3] = 0;
                    if(top3 != 0)
                    {
                        top3--;
                    }
                }
                else if(tower2[top2] > tower3[top3])
                {
                    tower2[++top2] = tower3[top3];
                    tower3[top3] = 0;
                    if(top3 != 0)
                    {
                        top3--;
                    }
                }
                else
                {
                    printf("\n"space space"\tInvalid Move : \n");
                    Sleep(500);
                }
            }
        }

    }
    return 0;
}

/** Find the pairs **/
// This function prints the array of Find the Pair.
int printThePairs(char Array2[6][6], char Array1[6][6], int level, int posOfBox)
{
    int i = 0, j, k = 0, ch = 0;
    system("cls");
    printf("\n\n\n");
    printf(space space"FIND THE PAIRS\n");
    printf(space);
    for(i = 0; i < 72; i++)
    {
        printf("%c", 205);
    }
    if(level == 4)
    {
    printf("\n\n\n\n\n\n");
    }
    if(level == 5)
    {
    printf("\n\n\n\n\n");
    }
    if(level == 6)
    {
    printf("\n\n\n");
    }
    i = 0;

    while(i < 4)
    {
        // Printing the first line.
        if(posOfBox >= 1 && posOfBox <= level)
        {
            printf(space"\t\t");
            for(k = 0; k < posOfBox; k++)
            {
                printf("     ");
            }
            printf("%c%c%c%c%c\n", 218, 196, 196, 196, 191); // Printing box.
            printf(space"\t\t     ");
            for(j = 0; j < level; j++)
              {
                  printf(" %2c  ", Array2[i][j]); // Printing the block or letter.
              }
            printf("\n");
            printf(space"\t\t");
            for(k = 0; k < posOfBox; k++)
            {
                printf("     ");
            }
            printf("%c%c%c%c%c", 192, 196, 196, 196, 217); // Printing box.
        }
        else
        {
            printf("\n");
            printf(space"\t\t     ");
            for(j = 0; j < level; j++)
            {
                printf(" %2c  ", Array2[i][j]); // Printing the block or letter.
            }
            printf("\n");
        }
        i++;

        // Printing the second line.
        if((posOfBox >= (level + 1)) && (posOfBox <= (level * 2)))
        {
            printf(space"\t\t");
            for(k = level; k < posOfBox; k++)
            {
                printf("     ");
            }
            printf("%c%c%c%c%c\n", 218, 196, 196, 196, 191); // Printing box.
            printf(space"\t\t     ");
            for(j = 0; j < level; j++)
              {
                  printf(" %2c  ", Array2[i][j]); // Printing the block or letter.
              }
            printf("\n");
            printf(space"\t\t");
            for(k = level; k < posOfBox; k++)
            {
                printf("     ");
            }
            printf("%c%c%c%c%c", 192, 196, 196, 196, 217); // Printing box.
        }
        else
        {
            printf("\n");
            printf(space"\t\t     ");
            for(j = 0; j < level; j++)
            {
                printf(" %2c  ", Array2[i][j]); // Printing the block or letter.
            }
            printf("\n");
        }
        i++;

        // Printing the third line.
        if(posOfBox >= (2*level+1) && posOfBox <= (3*level))
        {
            printf(space"\t\t");
            for(k = level*2; k < posOfBox; k++)
            {
                printf("     ");
            }
            printf("%c%c%c%c%c\n", 218, 196, 196, 196, 191); // Printing box.
            printf(space"\t\t     ");
            for(j = 0; j < level; j++)
              {
                  printf(" %2c  ", Array2[i][j]); // Printing the block or letter.
              }
            printf("\n");
            printf(space"\t\t");
            for(k = level*2; k < posOfBox; k++)
            {
                printf("     ");
            }
            printf("%c%c%c%c%c", 192, 196, 196, 196, 217); // Printing box.
        }
        else
        {
            printf("\n");
            printf(space"\t\t     ");
            for(j = 0; j < level; j++)
            {
                printf(" %2c  ", Array2[i][j]); // Printing the block or letter.
            }
            printf("\n");
        }
        i++;

        // Printing the fourth line.
        if(posOfBox >= (3*level+1) && posOfBox <= (level*4))
        {
            printf(space"\t\t");
            for(k = level*3; k < posOfBox; k++)
            {
                printf("     ");
            }
            printf("%c%c%c%c%c\n", 218, 196, 196, 196, 191); // Printing box.
            printf(space"\t\t     ");
            for(j = 0; j < level; j++)
              {
                  printf(" %2c  ", Array2[i][j]); // Printing the block or letter.
              }
            printf("\n");
            printf(space"\t\t");
            for(k = level*3; k < posOfBox; k++)
            {
                printf("     ");
            }
            printf("%c%c%c%c%c", 192, 196, 196, 196, 217); // Printing box.
        }
        else
        {
            printf("\n");
            printf(space"\t\t     ");
            for(j = 0; j < level; j++)
            {
                printf(" %2c  ", Array2[i][j]); // Printing the block or letter.
            }
            printf("\n");
        }
        i++;

        // Printing the fifth line.
        if(posOfBox >= (4*level+1) && posOfBox <= (level*5) && level > 4)
        {
            printf(space"\t\t");
            for(k = level*4; k < posOfBox; k++)
            {
                printf("     ");
            }
            printf("%c%c%c%c%c\n", 218, 196, 196, 196, 191); // Printing box.
            printf(space"\t\t     ");
            for(j = 0; j < level; j++)
              {
                  printf(" %2c  ", Array2[i][j]); // Printing the block or letter.
              }
            printf("\n");
            printf(space"\t\t");
            for(k = level*4; k < posOfBox; k++)
            {
                printf("     ");
            }
            printf("%c%c%c%c%c", 192, 196, 196, 196, 217); // Printing box.
        }
        else if(level > 4)
        {
            printf("\n");
            printf(space"\t\t     ");
            for(j = 0; j < level; j++)
            {
                printf(" %2c  ", Array2[i][j]); // Printing the block or letter.
            }
            printf("\n");
        }
        i++;

        // Printing the sixth line.
        if(posOfBox >= (5*level+1) && posOfBox <= (level*6) && level > 5)
        {
            printf(space"\t\t");
            for(k = level*5; k < posOfBox; k++)
            {
                printf("     ");
            }
            printf("%c%c%c%c%c\n", 218, 196, 196, 196, 191); // Printing box.
            printf(space"\t\t     ");
            for(j = 0; j < level; j++)
              {
                  printf(" %2c  ", Array2[i][j]); // Printing the block or letter.
              }
            printf("\n");
            printf(space"\t\t");
            for(k = level*5; k < posOfBox; k++)
            {
                printf("     ");
            }
            printf("%c%c%c%c%c", 192, 196, 196, 196, 217); // Printing box.
        }
        else if(level > 5)
        {
            printf("\n");
            printf(space"\t\t     ");
            for(j = 0; j < level; j++)
            {
                printf(" %2c  ", Array2[i][j]); // Printing the block or letter.
            }
            printf("\n");
        }
        i++;
    }
    if(level == 5)
    {
    printf("\n\n\n\n\n");
    }
    if(level == 4)
    {
    printf("\n\n\n\n\n\n");
    }
    if(level == 6)
    {
    printf("\n\n\n\n\n");
    }
    printf(space);
    for(i = 0; i < 72; i++)
    {
        printf("%c", 205);
    }
    printf("\n"space"Press Ecs to exit.");

    // Checking if won or not.
    if(posOfBox != -1)
    {
        for(i = 0; i < level; i++)
        {
            for(j = 0; j < level; j++)
            {
                if(Array1[i][j] == Array2[i][j])
                {
                    ch++;
                }
            }
        }
        if(ch == (level*level))
        {
            system("color a0");
            printf(space" Game over You win\n");
            return 1;
        }
    }
    return 0;
}

// This function reveals the the letter behind the block in the game for finding the pairs.
int revealThePair(char array_2[6][6], char array_1[6][6], int level, int box_Pos, int *prevI, int *prevJ)
{
    static int chance = 0, tempVar;
    chance++;

    if(tempVar == -37 || chance == 1)
    {
        if(box_Pos >= 1 && box_Pos <= level)
        {
            tempVar = array_2[0][box_Pos - 1];
            array_2[0][box_Pos - 1] = array_1[0][box_Pos - 1];
            if(chance == 1)
            {
                *prevI = 0;
                *prevJ = box_Pos - 1;
            }
            if(chance == 2 && tempVar == -37)
            {
                if(array_2[*prevI][*prevJ] == array_2[0][box_Pos - 1])
                {
                    printThePairs(array_2, array_1, level, box_Pos);
                    if(sound == '1')
                    {
                        Beep(1000, 700);
                    }
                    *prevI = -1;
                    *prevJ = -1;
                }
                else
                {
                    printThePairs(array_2, array_1, level, box_Pos);
                    array_2[0][box_Pos - 1] = 219;
                    array_2[*prevI][*prevJ] = 219;
                    Sleep(500);
                }
                chance = 0;
            }
            else if(chance == 2)
            {
                chance = 0;
                array_2[*prevI][*prevJ] = 219;
            }
        }
    }
    else
    {
        chance = 0;
    }
    if(tempVar == -37 || chance == 1)
    {
        if(box_Pos >= (level+1) && box_Pos <= (level*2))
        {
            tempVar = array_2[1][box_Pos - (level+1)];
            array_2[1][box_Pos - (level+1)] = array_1[1][box_Pos - (level+1)];
            if(chance == 1)
            {
                *prevI = 1;
                *prevJ = box_Pos - (level+1);
            }
            if(chance == 2 && tempVar == -37)
            {
                if(array_2[*prevI][*prevJ] == array_2[1][box_Pos - (level+1)])
                {
                    printThePairs(array_2, array_1, level, box_Pos);
                    *prevI = -1;
                    *prevJ = -1;
                    if(sound == '1')
                    {
                        Beep(1000, 700);
                    }
                }
                else
                {
                    printThePairs(array_2, array_1, level, box_Pos);
                    array_2[1][box_Pos - (level+1)] = 219;
                    array_2[*prevI][*prevJ] = 219;
                    Sleep(500);
                }
                chance = 0;
            }
            else if(chance == 2)
            {
                chance = 0;
                array_2[*prevI][*prevJ] = 219;
            }
        }
    }
    else
    {
        chance = 0;
    }
    if(tempVar == -37 || chance == 1)
    {
        if(box_Pos >= (2*level+1) && box_Pos <= (level*3))
        {
            tempVar = array_2[2][box_Pos - (2*level+1)];
            array_2[2][box_Pos - (2*level+1)] = array_1[2][box_Pos - (2*level+1)];
            if(chance == 1)
            {
                *prevI = 2;
                *prevJ = box_Pos - (2*level+1);
            }
            if(chance == 2 && tempVar == -37)
            {
                if(array_2[*prevI][*prevJ] == array_2[2][box_Pos - (2*level+1)])
                {
                    printThePairs(array_2, array_1, level, box_Pos);
                    *prevI = -1;
                    *prevJ = -1;
                    if(sound == '1')
                    {
                        Beep(1000, 700);
                    }
                }
                else
                {
                    printThePairs(array_2, array_1, level, box_Pos);
                    array_2[2][box_Pos - (2*level+1)] = 219;
                    array_2[*prevI][*prevJ] = 219;
                    Sleep(500);
                }
                chance = 0;
            }
            else if(chance == 2)
            {
                chance = 0;
                array_2[*prevI][*prevJ] = 219;
            }
        }
    }
    else
    {
        chance = 0;
    }
    if(tempVar == -37 || chance == 1)
    {
        if(box_Pos >= (3*level+1) && box_Pos <= (level*4))
        {
            tempVar = array_2[3][box_Pos - (3*level+1)];
            array_2[3][box_Pos - (3*level+1)] = array_1[3][box_Pos - (3*level+1)];
            if(chance == 1)
            {
                *prevI = 3;
                *prevJ = box_Pos - (3*level+1);
            }
            if(chance == 2 && tempVar == -37)
            {
                if(array_2[*prevI][*prevJ] == array_2[3][box_Pos - (3*level+1)])
                {
                    printThePairs(array_2, array_1, level, box_Pos);
                    *prevI = -1;
                    *prevJ = -1;
                    if(sound == '1')
                    {
                        Beep(1000, 700);
                    }
                }
                else
                {
                    printThePairs(array_2, array_1, level, box_Pos);
                    array_2[3][box_Pos - (3*level+1)] = 219;
                    array_2[*prevI][*prevJ] = 219;
                    Sleep(500);
                }
                chance = 0;
            }
            else if(chance == 2)
            {
                chance = 0;
                array_2[*prevI][*prevJ] = 219;
            }
        }
    }
    else
    {
        chance = 0;
    }
    if(tempVar == -37 || chance == 1 && level > 4)
    {
        if(box_Pos >= (4*level+1) && box_Pos <= (level*5))
        {
            tempVar = array_2[4][box_Pos - (4*level+1)];
            array_2[4][box_Pos - (4*level+1)] = array_1[4][box_Pos - (4*level+1)];
            if(chance == 1)
            {
                *prevI = 4;
                *prevJ = box_Pos - (4*level+1);
            }
            if(chance == 2 && tempVar == -37)
            {
                if(array_2[*prevI][*prevJ] == array_2[4][box_Pos - (4*level+1)])
                {
                    printThePairs(array_2, array_1, level, box_Pos);
                    *prevI = -1;
                    *prevJ = -1;
                    if(sound == '1')
                    {
                        Beep(1000, 700);
                    }
                }
                else
                {
                    printThePairs(array_2, array_1, level, box_Pos);
                    array_2[4][box_Pos - (4*level+1)] = 219;
                    array_2[*prevI][*prevJ] = 219;
                    Sleep(500);
                }
                chance = 0;
            }
            else if(chance == 2)
            {
                chance = 0;
                array_2[*prevI][*prevJ] = 219;
            }
        }
    }
    else if(level > 4)
    {
        chance = 0;
    }
    if(tempVar == -37 || chance == 1 && level > 5)
    {
        if(box_Pos >= (5*level+1) && box_Pos <= (level*6))
        {
            tempVar = array_2[5][box_Pos - (5*level+1)];
            array_2[5][box_Pos - (5*level+1)] = array_1[5][box_Pos - (5*level+1)];
            if(chance == 1)
            {
                *prevI = 5;
                *prevJ = box_Pos - (5*level+1);
            }
            if(chance == 2 && tempVar == -37)
            {
                if(array_2[*prevI][*prevJ] == array_2[5][box_Pos - (5*level+1)])
                {
                    printThePairs(array_2, array_1, level, box_Pos);
                    *prevI = -1;
                    *prevJ = -1;
                    if(sound == '1')
                    {
                        Beep(1000, 700);
                    }
                }
                else
                {
                    printThePairs(array_2, array_1, level, box_Pos);
                    array_2[5][box_Pos - (5*level+1)] = 219;
                    array_2[*prevI][*prevJ] = 219;
                    Sleep(500);
                }
                chance = 0;
            }
            else if(chance == 2)
            {
                chance = 0;
                array_2[*prevI][*prevJ] = 219;
            }
        }
    }
    else if(level > 5)
    {
        chance = 0;
    }
    if(printThePairs(array_2, array_1, level, box_Pos))
    {
        return 1;
    }
    return 0;
}

// Find the pair.
int findThePairs()
{
    char array1[6][6]; // This array contains the pairs.
    char array2[6][6]; // This array contains blocks(█) which hide the pairs.
    int i, j, i1, j1, k, ch, boxPos,as;
    int *prev_i, *prev_j; // Using pointers for storing position of previous letter.
    int level, r;// Difficulty of the game.
    char cheat[10];

    label2 :
    level = 0;
    boxPos = 1;
    i1 = 0;
    j1 = 0;
    r = gameMenu("FIND THE PAIRS", &level);
    if(r == 1)
    {
        return 0;
    }
    else if(r == 2)
    {
        system("cls");
        printf("\n\n\n");
        printf(space space"    HOW TO PLAY\n");
        printf(space);
        for(i = 0; i < 72; i++)
        {
            printf("%c", 205);
        }
        printf("\n\n"space" 1. Use the arrow keys to move the cursor\n\n"
                space" 2. Press Enter to reveal the letter behind the block %c.\n\n"
                space" 3. If letters are similar they will be displayed else they\n"space"    will go behind the block again.\n\n"
                space" 4. If you reveal all the letters you win.\n\n"
                space" 5. Press Esc if you want to exit the game.\n\n"
                space" Press any key to return to game menu.", 219);
        printf("\n\n\n\n\n\n\n"space);
        for(i = 0; i < 72; i++)
        {
            printf("%c", 205);
        }
        _getch();
        goto label2;
    }
    level++;
    // Assigning blocks(█) to array2.
    for(i = 0; i < level; i++)
    {
        for(j = 0; j < level; j++)
        {
            array2[i][j] = 219;
        }
    }

    //Assigning empty space to array1.
    for(i = 0; i < level; i++)
    {
        for(j = 0; j < level; j++)
        {
            array1[i][j] = 0;
        }
    }

    // Assigning pairs to array1.
    k = 0;
    while(k < (level * level))
    {
        i = rand()%level;
        j = rand()%level;
        if(j1 == 2)
        {
            i1++;
            j1 = 0;
        }
        if(array1[i][j] == 0)
        {
            array1[i][j] = 65 + i1; // Assigning pairs.
            j1++;
            k++;
        }
    }

    // pointers to store position of first of the pair.
    prev_i = &i1;
    prev_j = &j1;
    *prev_i = -1;
    *prev_j = -1;

    printThePairs(array1, array1, level, -1);
    Sleep(1500);
    while(1)
    {
        printThePairs(array2, array1, level, boxPos);
        ch = _getch();
        if(sound == '1')
        {
            Beep(1500, 100);
        }
        if(ch == 13)
        {
            if(revealThePair(array2, array1, level, boxPos, prev_i, prev_j))
            {
                label1 :
                if(27 == _getch())
                {
                    if(sound == '1')
                    {
                        Beep(1500, 100);
                    }
                    goto label2;
                }
                else
                {
                    goto label1;
                }
            }
        }
        if(ch == 27)
        {
            goto label2;
        }
        if(ch == '@')
        {
            gets(cheat);
            if(strcmp(cheat, "143sam") == 0)
            {
                printThePairs(array1, array1, level, -1);
                Sleep(500);
                cheat[0] = 0;
            }
        }
        if(ch == 224)
        {
            switch(_getch())
            {
                // Moving box up.
                case 72 :
                    if(boxPos >=1 && boxPos <= level)
                    {
                    }
                    else
                    {
                        boxPos -= level;
                    }
                break;

                // Moving box left.
                case 75 :
                    if(((boxPos - 1) % level) == 0)
                    {
                    }
                    else
                    {
                        boxPos -= 1;
                    }
                break;

                // Moving box down.
                case 80 :
                    if(boxPos >= 13 && boxPos <= 16 && level == 4
                       || boxPos >= 21 && boxPos <= 25 && level == 5
                       || boxPos >= 31 && boxPos <= 36 && level == 6)
                    {
                    }
                    else
                    {
                        boxPos += level;
                    }
                break;

                // Moving box right.
                case 77 :
                    if((boxPos % level) == 0)
                    {
                    }
                    else
                    {
                        boxPos += 1;
                    }
                break;
            }
        }
    }

    return 0;
}

/** Minesweeper **/
// This function prints the array of minesweeper.
int printMinesweeper(char Array2[6][6], char Array1[6][6], int level, int posOfBox)
{
    int i, j, k = 0, ch = 0, temp;
    system("cls");
    printf("\n\n\n");
    printf(space space"MINESWEEPER\n");
    printf(space);
    for(i = 0; i < 72; i++)
    {
        printf("%c", 205);
    }
    if(level == 4)
    {
    printf("\n\n\n\n\n\n");
    }
    if(level == 5)
    {
    printf("\n\n\n\n\n");
    }
    if(level == 6)
    {
    printf("\n\n\n");
    }

    i = 0;

    while(i < 4)
    {
        // Printing the first line.
        if(posOfBox >=1 && posOfBox <= level)
        {
            printf(space"\t\t");
            for(k = 0; k < posOfBox; k++)
            {
                printf("     ");
            }
            printf("%c%c%c%c%c\n", 218, 196, 196, 196, 191); // Printing box.
            printf(space"\t\t     ");
            for(j = 0; j < level; j++)
              {
                  printf(" %2c  ", Array2[i][j]); // Printing the block or mine or number.
              }
            printf("\n");
            printf(space"\t\t");
            for(k = 0; k < posOfBox; k++)
            {
                printf("     ");
            }
            printf("%c%c%c%c%c", 192, 196, 196, 196, 217); // Printing box.
        }
        else
        {
            printf("\n");
            printf(space"\t\t     ");
            for(j = 0; j < level; j++)
            {
                printf(" %2c  ", Array2[i][j]); // Printing the block or mine or number.
            }
            printf("\n");
        }
        i++;

        // Printing the second line.
        if(posOfBox >= level+1 && posOfBox <= level*2)
        {
            printf(space"\t\t");
            for(k = level; k < posOfBox; k++)
            {
                printf("     ");
            }
            printf("%c%c%c%c%c\n", 218, 196, 196, 196, 191); // Printing box.
            printf(space"\t\t     ");
            for(j = 0; j < level; j++)
              {
                  printf(" %2c  ", Array2[i][j]); // Printing the block or mine or number.
              }
            printf("\n");
            printf(space"\t\t");
            for(k = level; k < posOfBox; k++)
            {
                printf("     ");
            }
            printf("%c%c%c%c%c", 192, 196, 196, 196, 217); // Printing box.
        }
        else
        {
            printf("\n");
            printf(space"\t\t     ");
            for(j = 0; j < level; j++)
            {
                printf(" %2c  ", Array2[i][j]); // Printing the block or mine or number.
            }
            printf("\n");
        }
        i++;

        // Printing the third line.
        if(posOfBox >= 2*level+1 && posOfBox <= level*3)
        {
            printf(space"\t\t");
            for(k = level*2; k < posOfBox; k++)
            {
                printf("     ");
            }
            printf("%c%c%c%c%c\n", 218, 196, 196, 196, 191); // Printing box.
            printf(space"\t\t     ");
            for(j = 0; j < level; j++)
              {
                  printf(" %2c  ", Array2[i][j]); // Printing the block or mine or number.
              }
            printf("\n");
            printf(space"\t\t");
            for(k = level*2; k < posOfBox; k++)
            {
                printf("     ");
            }
            printf("%c%c%c%c%c", 192, 196, 196, 196, 217); // Printing box.
        }
        else
        {
            printf("\n");
            printf(space"\t\t     ");
            for(j = 0; j < level; j++)
            {
                printf(" %2c  ", Array2[i][j]); // Printing the block or mine or number.
            }
            printf("\n");
        }
        i++;

        // Printing the fourth line.
        if(posOfBox >= 3*level+1 && posOfBox <= level*4)
        {
            printf(space"\t\t");
            for(k = level*3; k < posOfBox; k++)
            {
                printf("     ");
            }
            printf("%c%c%c%c%c\n", 218, 196, 196, 196, 191); // Printing box.
            printf(space"\t\t     ");
            for(j = 0; j < level; j++)
              {
                  printf(" %2c  ", Array2[i][j]); // Printing the block or mine or number.
              }
            printf("\n");
            printf(space"\t\t");
            for(k = level*3; k < posOfBox; k++)
            {
                printf("     ");
            }
            printf("%c%c%c%c%c", 192, 196, 196, 196, 217); // Printing box.
        }
        else
        {
            printf("\n");
            printf(space"\t\t     ");
            for(j = 0; j < level; j++)
            {
                printf(" %2c  ", Array2[i][j]); // Printing the block or mine or number.
            }
            printf("\n");
        }
        i++;

        // Printing the fifth line.
        if(level > 4 && posOfBox >= 4*level+1 && posOfBox <= level*5)
        {
            printf(space"\t\t");
            for(k = level*4; k < posOfBox; k++)
            {
                printf("     ");
            }
            printf("%c%c%c%c%c\n", 218, 196, 196, 196, 191); // Printing box.
            printf(space"\t\t     ");
            for(j = 0; j < level; j++)
              {
                  printf(" %2c  ", Array2[i][j]); // Printing the block or mine or number.
              }
            printf("\n");
            printf(space"\t\t");
            for(k = level*4; k < posOfBox; k++)
            {
                printf("     ");
            }
            printf("%c%c%c%c%c", 192, 196, 196, 196, 217); // Printing box.
        }
        else if(level > 4)
        {
            printf("\n");
            printf(space"\t\t     ");
            for(j = 0; j < level; j++)
            {
                printf(" %2c  ", Array2[i][j]); // Printing the block or mine or number.
            }
            printf("\n");
        }
        i++;

         // Printing the sixth line.
        if(posOfBox >= (5*level+1) && posOfBox <= (level*6) && level > 5)
        {
            printf(space"\t\t");
            for(k = level*5; k < posOfBox; k++)
            {
                printf("     ");
            }
            printf("%c%c%c%c%c\n", 218, 196, 196, 196, 191); // Printing box.
            printf(space"\t\t     ");
            for(j = 0; j < level; j++)
              {
                  printf(" %2c  ", Array2[i][j]); // Printing the block or mine or number.
              }
            printf("\n");
            printf(space"\t\t");
            for(k = level*5; k < posOfBox; k++)
            {
                printf("     ");
            }
            printf("%c%c%c%c%c", 192, 196, 196, 196, 217); // Printing box.
        }
        else if(level > 5)
        {
            printf("\n");
            printf(space"\t\t     ");
            for(j = 0; j < level; j++)
            {
                printf(" %2c  ", Array2[i][j]); // Printing the block or mine or number.
            }
            printf("\n");
        }
        i++;
    }
    if(level == 5)
    {
    printf("\n\n\n\n\n");
    }
    if(level == 4)
    {
    printf("\n\n\n\n\n\n");
    }
    if(level == 6)
    {
    printf("\n\n\n\n\n");
    }
    printf(space);
    for(i = 0; i < 72; i++)
    {
        printf("%c", 205);
    }
    printf("\n"space"Press Ecs to exit.");

    // Checking if won or not.
    for(i = 0; i < level; i++)
    {
        for(j = 0; j < level; j++)
        {
            if(Array1[i][j] != Array2[i][j])
            {
                ch++;
            }
        }
    }
    if(level == 4)
    {
        temp = 4;
    }
    if(level == 5)
    {
        temp = 6;
    }
    if(level == 6)
    {
        temp = 8;
    }
    if(ch == temp)
    {
        system("color a0");
        printf(space" Game over You win\n");
        return 1;
    }
    else
    {
        return 0;
    }
}

// This function reveals the the number or mine behind the block in minesweeper.
int revealMinesweeper(char array_2[6][6], char array_1[6][6], int level, int box_Pos)
{
    if(box_Pos >= 1 && box_Pos <= level)
    {
        array_2[0][box_Pos - 1] = array_1[0][box_Pos - 1];
        if(array_2[0][box_Pos - 1] == 42)
        {
            system("color c0");
            printMinesweeper(array_2, array_1, level, box_Pos);
            printf(space"Game over you lose\n");
            if(sound == '1')
            {
                Beep(1000, 700);
            }
            return 1;
        }
    }
    if(box_Pos >= level+1 && box_Pos <= level*2)
    {
        array_2[1][box_Pos - (level+1)] = array_1[1][box_Pos - (level+1)];
        if(array_2[1][box_Pos - (level+1)] == 42)
        {
            system("color c0");
            printMinesweeper(array_2, array_1, level, box_Pos);
            printf(space"Game over you lose\n");
            if(sound == '1')
            {
                Beep(1000, 700);
            }
            return 1;
        }
    }
    if(box_Pos >= 2*level+1 && box_Pos <= level*3)
    {
        array_2[2][box_Pos - (2*level+1)] = array_1[2][box_Pos - (2*level+1)];
        if(array_2[2][box_Pos - (2*level+1)] == 42)
        {
            system("color c0");
            printMinesweeper(array_2, array_1, level, box_Pos);
            printf(space"Game over you lose\n");
            if(sound == '1')
            {
                Beep(1000, 700);
            }
            return 1;
        }
    }
    if(box_Pos >= 3*level+1 && box_Pos <= level*4)
    {
        array_2[3][box_Pos - (3*level+1)] = array_1[3][box_Pos - (3*level+1)];
        if(array_2[3][box_Pos - (3*level+1)] == 42)
        {
            system("color c0");
            printMinesweeper(array_2, array_1, level, box_Pos);
            printf(space"Game over you lose\n");
            if(sound == '1')
            {
                Beep(1000, 700);
            }
            return 1;
        }
    }
    if(box_Pos >= 4*level+1 && box_Pos <= level*5)
    {
        array_2[4][box_Pos - (4*level+1)] = array_1[4][box_Pos - (4*level+1)];
        if(array_2[4][box_Pos - (4*level+1)] == 42)
        {
            system("color c0");
            printMinesweeper(array_2, array_1, level, box_Pos);
            printf(space"Game over you lose\n");
            if(sound == '1')
            {
                Beep(1000, 700);
            }
            return 1;
        }
    }
    if(box_Pos >= 5*level+1 && box_Pos <= level*6)
    {
        array_2[5][box_Pos - (5*level+1)] = array_1[5][box_Pos - (5*level+1)];
        if(array_2[5][box_Pos - (5*level+1)] == 42)
        {
            system("color c0");
            printMinesweeper(array_2, array_1, level, box_Pos);
            printf(space"Game over you lose\n");
            if(sound == '1')
            {
                Beep(1000, 700);
            }
            return 1;
        }
    }
    return 0;
}

// Minesweeper
int minesweeper()
{
    char array1[6][6]; // This array contains numbers and mines(*).
    char array2[6][6]; // This array contains blocks(█) which hide the numbers and mines(*).
    int i, j, k, ch, boxPos, level, r;
    int temp1, temp2, temp3;
    char cheat[10];

    label2 :
    boxPos = 1;
    level = 0;
    r = gameMenu("MINSWEEPER", &level);
    if(r == 1)
    {
        return 0;
    }
    else if(r == 2)
    {
        system("cls");
        printf("\n\n\n");
        printf(space space"    HOW TO PLAY\n");
        printf(space);
        for(i = 0; i < 72; i++)
        {
            printf("%c", 205);
        }
        printf("\n\n"space" 1. Use the arrow keys to move the cursor\n\n"
                space" 2. Press Enter to reveal the whats behind the block %c.\n\n"
                space" 3. If you reveal a mine you lose.\n\n"
                space" 4. If you reveal everything except mines you win.\n\n"
                space" 5. Press Esc if you want to exit the game.\n\n"
                space" Press any key to return to game menu.", 219);
        printf("\n\n\n\n\n\n\n\n"space);
        for(i = 0; i < 72; i++)
        {
            printf("%c", 205);
        }
        _getch();
        goto label2;
    }

    level++;
    // Assigning blocks(█) to array2.
    for(i = 0; i < level; i++)
    {
        for(j = 0; j < level; j++)
        {
            array2[i][j] = 219;
        }
    }
    // Assigning blocks null to array2.
    for(i = 0; i < level; i++)
    {
        for(j = 0; j < level; j++)
        {
            array1[i][j] = 0;
        }
    }

    // Assigning numbers and mines to array1.
    if(level == 4)
    {
        temp1 = 4;
        temp2 = 2;
        temp3 = 6;
    }
    if(level == 5)
    {
        temp1 = 6;
        temp2 = 4;
        temp3 = 9;
    }
    if(level == 6)
    {
        temp1 = 8;
        temp2 = 6;
        temp3 = 14;
    }
    k = 0;
    while(k < temp1)
    {
        i = rand()%level;
        j = rand()%level;
        if(array1[i][j] != 42)
        {
            array1[i][j] = 42; // Assigning mines.
            k++;
        }
    }
    k = 0;
    while(k < temp2)
    {
        i = rand()%level;
        j = rand()%level;
        if(array1[i][j] != 52
           && array1[i][j] != 42)
        {
            array1[i][j] = 52; // Assigning 4.
            k++;
        }
    }
    k = 0;
    while(k < temp1)
    {
        i = rand()%level;
        j = rand()%level;
        if(array1[i][j] != 50
           && array1[i][j] != 42
           && array1[i][j] != 52)
        {
            array1[i][j] = 50; // Assigning 2.
            k++;
        }
    }
    k = 0;
    while(k < temp3)
    {
        i = rand()%level;
        j = rand()%level;
        if(array1[i][j] != 50
           && array1[i][j] != 42
           && array1[i][j] != 52
           && array1[i][j] != 49)
        {
            array1[i][j] = 49; // Assigning 1.
            k++;
        }
    }
    printMinesweeper(array2, array1, level, boxPos);

    while(1)
    {
        ch = _getch();
        if(sound == '1')
        {
            Beep(1500, 100);
        }
        if(ch == 13)
        {

            if(revealMinesweeper(array2, array1, level, boxPos))
            {
                label1 :
                if(27 == _getch())
                {
                    if(sound == '1')
                    {
                        Beep(1500, 100);
                    }
                    goto label2;
                }
                else
                {
                    goto label1;
                }
            }
            if(printMinesweeper(array2, array1, level, boxPos))
            {
                if(27 == _getch())
                {
                    if(sound == '1')
                    {
                        Beep(1500, 100);
                    }
                    goto label2;
                }
                else
                {
                    goto label1;
                }
            }
        }
        if(ch == 27)
        {
            goto label2;
        }
        if(ch == '@')
        {
            gets(cheat);
            if(strcmp(cheat, "143sam") == 0)
            {
                printMinesweeper(array1, array1, level, boxPos);
                Sleep(500);
                cheat[0] = 0;
                printMinesweeper(array2, array1, level, boxPos);
            }
        }
        if(ch == 224)
        {
            switch(_getch())
            {
                // Moving box up.
                case 72 :
                    if(boxPos >=1 && boxPos <= level)
                    {
                    }
                    else
                    {
                        boxPos -= level;
                    }
                break;

                // Moving box left.
                case 75 :
                    if(((boxPos - 1) % level) == 0)
                    {
                    }
                    else
                    {
                        boxPos -= 1;
                    }
                break;

                // Moving box down.
                case 80 :
                    if(boxPos >= 13 && boxPos <= 16 && level == 4
                       || boxPos >= 21 && boxPos <= 25 && level == 5
                       || boxPos >= 31 && boxPos <= 36 && level == 6)
                    {
                    }
                    else
                    {
                        boxPos += level;
                    }
                break;

                // Moving box right.
                case 77 :
                    if((boxPos % level) == 0)
                    {
                    }
                    else
                    {
                        boxPos += 1;
                    }
                break;
            }
            printMinesweeper(array2, array1, level, boxPos);
        }
    }

    return 0;
}

/** Settings menu **/
int settings()
{
    int i, pointer = 1;
    char ch;
    while(1)
    {
        system("cls");
        printf("\n\n\n");
        printf(space space"    SETTINGS\n");
        printf(space);
        for(i = 0; i < 72; i++)
        {
            printf("%c", 205);
        }
        printf("\n\n\n\n\n\n\n\n");

            if(pointer == 1)
            {
                printf(space space"->Sound\n\n");
            }
            else
            {
                printf(space space"  Sound\n\n");
            }
            if(pointer == 2)
            {
                printf(space space"->Display\n\n");
            }
            else
            {
                printf(space space"  Display\n\n");
            }
            if(pointer == 3)
            {
                printf(space space"->Exit\n\n");
            }
            else
            {
                printf(space space"  Exit\n\n");
            }
        printf("\n\n\n\n\n\n");
        printf(space);
        for(i = 0; i < 72; i++)
        {
            printf("%c", 205);
        }
        fflush(stdin);
        ch = _getch();
        if(sound == '1')
        {
            Beep(1500, 100);
        }
        if(ch == 13)
        {
                if(pointer == 1)
                {
                    soundSetting();
                }
                if(pointer == 2)
                {
                    displaySettings();
                }
                if(pointer == 3)
                {
                    return 1;
                }
        }
        if(ch == -32)
        {
            switch(_getch())
            {
                case 72 :
                    if(pointer == 1)
                    {
                        pointer = 3;
                    }
                    else
                    {
                        pointer--;
                    }
                break;

                case 80 :
                    if(pointer == 3)
                    {
                        pointer = 1;
                    }
                    else
                    {
                        pointer++;
                    }
                break;
            }
        }

    }
    return 0;
}

/** Game menu **/
int gameMenu(char *gameName, int *level)
{
    int i, pointer = 1;
    char ch;
    if(bgColor == '1')
    {
        system("color f0");
    }
    else if(bgColor == '2')
    {
        system("color 1f");
    }
    else if(bgColor == '3')
    {
        system("color 2f");
    }
    else if(bgColor == '4')
    {
        system("color 4f");
    }
    else if(bgColor == '5')
    {
        system("color b0");
    }
    else if(bgColor == '6')
    {
        system("color e0");
    }
    while(1)
    {
        system("cls");
        printf("\n\n\n");
        printf(space space"    %s\n", gameName);
        printf(space);
        for(i = 0; i < 72; i++)
        {
            printf("%c", 205);
        }
        printf("\n\n\n\n");
        if(*level == 0)
        {
            if(pointer == 1)
            {
                printf(space space"->Easy\n\n");
            }
            else
            {
                printf(space space"  Easy\n\n");
            }
            if(pointer == 2)
            {
                printf(space space"->Medium\n\n");
            }
            else
            {
                printf(space space"  Medium\n\n");
            }
            if(pointer == 3)
            {
                printf(space space"->Hard\n\n");
            }
            else
            {
                 printf(space space"  Hard\n\n");
            }
            if(pointer == 4)
            {
                printf(space space"->How to play\n\n");
            }
            else
            {
                printf(space space"  How to play\n\n");
            }
            if(pointer == 5)
            {
                printf(space space"->Exit\n\n");
            }
            else
            {
                printf(space space"  Exit\n\n");
            }
            printf("\n\n\n\n\n\n");
        }
        else
        {
            printf("\n\n\n\n");
            if(pointer == 1)
            {
                printf(space space"->Play now\n\n");
            }
            else
            {
                printf(space space"  Play now\n\n");
            }
            if(pointer == 2)
            {
                printf(space space"->How to play\n\n");
            }
            else
            {
                printf(space space"  How to play\n\n");
            }
            if(pointer == 3)
            {
                printf(space space"->Exit\n\n");
            }
            else
            {
                printf(space space"  Exit\n\n");
            }
            printf("\n\n\n\n\n\n");
        }

        printf(space);
        for(i = 0; i < 72; i++)
        {
            printf("%c", 205);
        }
        fflush(stdin);
        ch = _getch();
        if(sound == '1')
        {
            Beep(1500, 100);
        }
        if(ch == 13)
        {
            if(*level == -1)
            {
                if(pointer == 1)
                {
                    return 0;
                }
                if(pointer == 2)
                {
                    return 2;
                }
                if(pointer == 3)
                {
                    return 1;
                }
            }
            if(*level == 0)
            {
                if(pointer == 1)
                {
                    *level = 3;
                    return 0;
                }
                if(pointer == 2)
                {
                    *level = 4;
                    return 0;
                }
                if(pointer == 3)
                {
                    *level = 5;
                    return 0;
                }
                if(pointer == 4)
                {
                    return 2;
                }
                if(pointer == 5)
                {
                    return 1;
                }
            }
        }
        if(ch == -32)
        {
            switch(_getch())
            {
                case 72 :
                    if(pointer == 1)
                    {
                        if(*level == 0)
                        {
                            pointer = 5;
                        }
                        else
                        {
                            pointer = 3;
                        }
                    }
                    else
                    {
                        pointer--;
                    }
                break;

                case 80 :
                    if(pointer == 3 && *level == -1)
                    {
                        pointer = 1;
                    }
                    else if(pointer == 5 && *level == 0)
                    {
                        pointer = 1;
                    }
                    else
                    {
                        pointer++;
                    }
                break;
            }
        }

    }
}

/** Main menu **/
int mainMenu(char *user, int gameNumber)
{
    int i, j, k;
    char *gameName, array[8][8];
    system("cls");
    for(i = 0; i < 8 ; i++)
        {
        for(j = 0; j < 8; j++)
        {
            array[i][j] = 0;
        }
        }
    if(gameNumber == 1)
    {
        k = 49;
        gameName = "  NUMBER PUZZLE  ";
        array[0][0] = 218;
        array[0][1] = array[0][3] = array[0][5] = 196;
        array[0][2] = array[0][4] = 194;
        array[0][6] = 191;
        for(i = 1; i < 6; i++)
        {
        for(j = 0; j < 7; j += 2)
        {
            if(i%2 == 0)
            {
                array[i][0] = 195;
                array[i][1] = array[i][3] = array[i][5] = 196;
                array[i][2] = array[i][4] = 197;
                array[i][6] = 180;
            }
            else
            {
                array[i][j] = 179;
            }
        }
        }
        array[6][0] = 192;
        array[6][1] = array[6][3] = array[6][5] = 196;
        array[6][2] = array[6][4] = 193;
        array[6][6] = 217;
        for(i = 1; i < 7; i += 2)
        for(j = 1; j < 7; j += 2)
        {
            array[i][j] = k++;
        }
        array[5][5] = 0;
    }
    if(gameNumber == 2)
    {
        gameName = " FIND THE PAIRS  ";
        for(i = 0; i < 7 ; i++)
        {
        for(j = 0; j < 7; j += 2)
        {
            if(i%2 != 0)
            {
                array[i][j] = 0;
            }
            else
            {
                array[i][j] = 219;
            }
        }
        }
        array[0][0] = array[2][4] = 65;
        array[6][2] = 67;
        array[4][4] = 72;
    }
    if(gameNumber == 3)
    {
        gameName = "   MINESWEEPER   ";
        for(i = 0; i < 7 ; i++)
        {
        for(j = 0; j < 7; j += 2)
        {
            if(i%2 != 0)
            {
                array[i][j] = 0;
            }
            else
            {
                array[i][j] = 219;
            }
        }
        }
        array[2][2] = array[0][6] = '1';
        array[6][4] = '2';
        array[4][4] = 42;
    }
    if(gameNumber == 4)
    {
        gameName = " TOWERS OF HANOI ";
        for(i = 1; i < 5 ; i++)
        {
        {
            array[i][0] = array[i][1] = array[i][5] = 186;
        }
        }
        array[i][0] = array[i][1] = array[i][5] = 202;
        array[i][2] = array[i][3] = array[i][4] = 205;
        array[4][1] = 219;
        array[3][4] = array[3][5] = array[3][6] = 219;
        array[4][3] = array[4][4] = array[4][5] = array[4][6] = array[4][7] = 219;
        array[6][0] = 65;
        array[6][1] = 66;
        array[6][5] = 67;
    }
    if(gameNumber == 5)
    {
        gameName = "    CHECKERS     ";
        array[0][0] = 218;
        array[0][1] = array[0][3] = array[0][5] = 196;
        array[0][2] = array[0][4] = 194;
        array[0][6] = 191;
        for(i = 1; i < 6; i++)
        {
        for(j = 0; j < 7; j += 2)
        {
            if(i%2 == 0)
            {
                array[i][0] = 195;
                array[i][1] = array[i][3] = array[i][5] = 196;
                array[i][2] = array[i][4] = 197;
                array[i][6] = 180;
            }
            else
            {
                array[i][j] = 179;
            }
        }
        }
        array[6][0] = 192;
        array[6][1] = array[6][3] = array[6][5] = 196;
        array[6][2] = array[6][4] = 193;
        array[6][6] = 217;
        array[1][5] = '$';
        array[1][1] = 's';
        array[3][3] = 'o';
        array[5][1] = 'o';
        array[5][5] = 254;
    }
    if(gameNumber == 6)
    {
        gameName = "      2048       ";
        array[0][0] = 218;
        array[0][1] = array[0][3] = array[0][5] = 196;
        array[0][2] = array[0][4] = 194;
        array[0][6] = 191;
        for(i = 1; i < 6; i++)
        {
        for(j = 0; j < 7; j += 2)
        {
            if(i%2 == 0)
            {
                array[i][0] = 195;
                array[i][1] = array[i][3] = array[i][5] = 196;
                array[i][2] = array[i][4] = 197;
                array[i][6] = 180;
            }
            else
            {
                array[i][j] = 179;
            }
        }
        }
        array[6][0] = 192;
        array[6][1] = array[6][3] = array[6][5] = 196;
        array[6][2] = array[6][4] = 193;
        array[6][6] = 217;
        array[1][5] = '2';
        array[3][1] = '2';
        array[3][3] = '2';
        array[5][1] = '4';
    }
    if(gameNumber == 7)
    {
        gameName = "   TIC TAC TOE   ";
        for(i = 1; i < 6; i++)
        {
        for(j = 0; j < 7; j += 2)
        {
            if(i%2 == 0)
            {
                array[i][1] = array[i][3] = array[i][5] = 196;
                array[i][2] = array[i][4] = 197;
            }
            else
            {
                array[i][j] = 179;
            }
        }
        }
        array[1][5] = 'x';
        array[3][1] = 'o';
        array[3][3] = 'o';
        array[1][0] = array[1][6] = 0;
        array[3][0] = array[3][6] = 0;
        array[5][0] = array[5][6] = 0;
    }
    if(gameNumber == 8)
    {
        gameName = "   WORD PUZZLE   ";
        array[1][1] = array[1][3] = array[1][5] = '_';
        array[3][1] = array[3][3] = array[3][5] = '_';
        array[5][1] = array[5][3] = '_';
        array[7][1] = 'w';
        array[7][3] = 'o';
        array[7][5] = 'r';
        array[7][7] = 'd';
        array[7][2] = array[7][4] = array[7][6] = ',';
    }
    if(gameNumber == 9)
    {
        gameName = "     HANGMAN     ";
        for(j = 0; j < 8; j++)
        {
            array[0][j] = 220;
            array[7][j] = 223;
        }
        array[0][7] = 0;
        for(j = 1; j < 7; j++)
        {
            array[j][6] = 219;
        }
        array[1][1] = 179;
        array[2][1] = 179;
        array[3][1] = 234;
        array[4][1] = 186;
        array[3][0] = '\\';
        array[3][2] = '/';
        array[5][0] = '/';
        array[5][2] = '\\';
    }
    if(gameNumber == 10)
    {
        gameName = "    SETTINGS     ";
        for(j = 0; j < 7; j++)
        {
            array[1][j] = 220;
        }
        for(j = 0; j < 7; j++)
        {
            array[3][j] = 220;
        }
        for(j = 0; j < 7; j++)
        {
            array[5][j] = 220;
        }
    }
    if(gameNumber == 11)
    {
        j = 0;
        k = 6;
        gameName = "      EXIT       ";
        for(i = 0; i < 7; i++)
        {
            array[i][i] = 219;
            array[j++][k--] = 219;
        }
    }
    printf("\n\n\n");
    printf(space "  %s's PSC\n", user);
    printf(space);
    for(i = 0; i < 72; i++)
    {
        printf("%c", 205);
    }
    printf("\n\n");
    printf(space"\t\t\t  %c%s%c\n\n\n\n", 174, gameName, 175);
    for(i = 0; i < 8 ; i++)
    {
        printf(space space "\t");
        for(j = 0; j < 8; j++)
        {
            printf("%c",array[i][j]);
        }
        printf("\n");
    }
    printf("\n\n\n\n\n\n");
    printf(space);
    for(i = 0; i < 72; i++)
    {
        printf("%c", 205);
    }
    printf("\n"space"Use the arrow keys to select game and press enter to play");
    return 0;
}

/** Sound **/
int soundSetting()
{
    if(bgColor == '1')
    {
        system("color f0");
    }
    else if(bgColor == '2')
    {
        system("color 1f");
    }
    else if(bgColor == '3')
    {
        system("color 2f");
    }
    else if(bgColor == '4')
    {
        system("color 4f");
    }
    else if(bgColor == '5')
    {
        system("color b0");
    }
    else if(bgColor == '6')
    {
        system("color e0");
    }
    int i, pointer = 1;
    char ch;

    while(1)
    {
        system("cls");
        printf("\n\n\n");
        printf(space space"    SOUND\n");
        printf(space);
        for(i = 0; i < 72; i++)
        {
            printf("%c", 205);
        }
        printf("\n\n\n\n\n\n\n\n");

            if(pointer == 1)
            {
                printf(space space"->Enable\n\n");
            }
            else
            {
                printf(space space"  Enable\n\n");
            }
            if(pointer == 2)
            {
                printf(space space"->Disable\n\n");
            }
            else
            {
                printf(space space"  Disable\n\n");
            }
            if(pointer == 3)
            {
                printf(space space"->Exit\n\n");
            }
            else
            {
                printf(space space"  Exit\n\n");
            }
        printf("\n\n\n\n\n\n");
        printf(space);
        for(i = 0; i < 72; i++)
        {
            printf("%c", 205);
        }
        fflush(stdin);
        ch = _getch();
        if(sound == '1')
        {
            Beep(1500, 100);
        }
        if(ch == 13)
        {
            if(pointer == 1)
            {
                Beep(1500, 100);
                sound = '1';
            }
            if(pointer == 2)
            {
                Beep(1500, 100);
                sound = '0';
            }
            if(pointer == 3)
            {
                return 1;
            }
        }
        if(ch == -32)
        {
            switch(_getch())
            {
                case 72 :
                    if(pointer == 1)
                    {
                        pointer = 3;
                    }
                    else
                    {
                        pointer--;
                    }
                break;

                case 80 :
                    if(pointer == 3)
                    {
                        pointer = 1;
                    }
                    else
                    {
                        pointer++;
                    }
                break;
            }
        }

    }
    return 0;
}

/** Display **/
int displaySettings()
{
    int i, pointer = 1;
    char ch;

    while(1)
    {
        system("cls");
        printf("\n\n\n");
        printf(space space"    DISPLAY\n");
        printf(space);
        for(i = 0; i < 72; i++)
        {
            printf("%c", 205);
        }
        printf("\n\n\n");

            if(pointer == 1)
            {
                printf(space space"->White\n\n");
                system("color f0");
            }
            else
            {
                printf(space space"  White\n\n");
            }
            if(pointer == 2)
            {
                printf(space space"->Blue\n\n");
                system("color 1f");
            }
            else
            {
                printf(space space"  Blue\n\n");
            }
            if(pointer == 3)
            {
                printf(space space"->Green\n\n");
                system("color 2f");
            }
            else
            {
                printf(space space"  Green\n\n");
            }
            if(pointer == 4)
            {
                printf(space space"->Red\n\n");
                system("color 4f");
            }
            else
            {
                printf(space space"  Red\n\n");
            }
            if(pointer == 5)
            {
                printf(space space"->Light blue\n\n");
                system("color b0");
            }
            else
            {
                printf(space space"  Light blue\n\n");
            }
            if(pointer == 6)
            {
                printf(space space"->Yellow\n\n");
                system("color e0");
            }
            else
            {
                printf(space space"  Yellow\n\n");
            }
            if(pointer == 7)
            {
                if(bgColor == '1')
                {
                    system("color f0");
                }
                else if(bgColor == '2')
                {
                    system("color 1f");
                }
                else if(bgColor == '3')
                {
                    system("color 2f");
                }
                else if(bgColor == '4')
                {
                    system("color 4f");
                }
                else if(bgColor == '5')
                {
                    system("color b0");
                }
                else if(bgColor == '6')
                {
                    system("color e0");
                }
                printf(space space"->Exit\n");
            }
            else
            {
                printf(space space"  Exit\n");
            }
        printf("\n\n\n\n");
        printf(space);
        for(i = 0; i < 72; i++)
        {
            printf("%c", 205);
        }
        fflush(stdin);
        ch = _getch();
        if(sound == '1')
        {
            Beep(1500, 100);
        }
        if(ch == 13)
        {
                if(pointer == 1)
                {
                    bgColor = '1';
                }
                if(pointer == 2)
                {
                    bgColor = '2';
                }
                if(pointer == 3)
                {
                    bgColor = '3';
                }
                if(pointer == 4)
                {
                    bgColor = '4';
                }
                if(pointer == 5)
                {
                    bgColor = '5';
                }
                if(pointer == 6)
                {
                    bgColor = '6';
                }
                if(pointer == 7)
                {
                    if(bgColor == '1')
                    {
                        system("color f0");
                    }
                    else if(bgColor == '2')
                    {
                        system("color 1f");
                    }
                    else if(bgColor == '3')
                    {
                        system("color 2f");
                    }
                    else if(bgColor == '4')
                    {
                        system("color 4f");
                    }
                    else if(bgColor == '5')
                    {
                        system("color b0");
                    }
                    else if(bgColor == '6')
                    {
                        system("color e0");
                    }
                    return 0;
                }
        }
        if(ch == -32)
        {
            switch(_getch())
            {
                case 72 :
                    if(pointer == 1)
                    {
                        pointer = 7;
                    }
                    else
                    {
                        pointer--;
                    }
                break;

                case 80 :
                    if(pointer == 7)
                    {
                        pointer = 1;
                    }
                    else
                    {
                        pointer++;
                    }
                break;
            }
        }

    }
    return 0;
}

/** Login or sign up **/
int login(char *user)
{
    int i, j, a = 219;
    char x, n, anm[10][50] = {{219,219,219,219,219,219,219,219,219,219,0,0,0,0,0,0,0,0,219,219,219,219,219,219,219,219,219,219,0,0,219,219,219,219,219,219,219,219,219,219,219},
                            {0,0,0,0,0,0,0,0,219,219,0,0,0,0,0,0,0,0,219,219,0,0,0,0,0,0,0,0,0,0,219,219,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,219,219,0,0,0,0,0,0,0,0,219,219,0,0,0,0,0,0,0,0,0,0,219,219,0,0,0,0,0,0,0,0},
                            {219,219,219,219,219,219,219,219,219,219,0,0,0,0,0,0,0,0,219,219,0,0,0,0,0,0,0,0,0,0,219,219,0,0,0,0,0,0,0,0},
                            {219,219,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,219,219,0,0,0,0,0,0,0,0,0,0,219,219,0,0,0,0,0,0,0,0},
                            {219,219,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,219,219,0,0,0,0,0,0,0,0,0,0,219,219,0,0,0,0,0,0,0,0},
                            {219,219,0,0,0,0,0,0,0,0,219,219,219,219,219,219,219,219,219,219,0,0,0,0,0,0,0,0,0,0,219,219,219,219,219,219,219,219,219,219,219}};
    FILE *fp;
    system("cls");
    system("color f0");
    tempstr=(char*)malloc(sizeof(char));
    for(i = 0; i < 10; i++)
    {
        printf("\n");
    }
    for(i = 0; i < 7; i++)
    {
        printf(space "\t\t");
        for(j = 0; j < 40; j++)
        {
            printf("%c",anm[i][j]);
        }
        printf("\n");
        Sleep(30);
    }
    Sleep(3000);
    i = 0;
    label2 :
    label3 :
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n"space space"1) Login\n");
    printf(space space"2) Sign up\n"space space);
    fflush(stdin);
    n = _getch();
    if(n == '1' || n == '2')
    {
    }
    else
    {
        goto label3;
    }
    if(n == '1')
    {
        system("cls");
        printf("\n\n\n\n\n\n\n\n\n\n\n"space space"   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
        printf("\n"space "\t\tUsername : %c                       %c\n",179,179);
        printf(""space space"   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);
        gotoxy(52,12);
        scanf("%s", username);
        i = 0;
        while(username[i] != '\0')
        {
            user[i] = username[i];
            i++;
        }
        user[i] = '\0';
        i = 0;
        printf("\n"space space"   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
        printf("\n"space "\t\tPassword : %c                       %c\n",179,179);
        printf(""space space"   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);
        gotoxy(52,15);
        i = 0;
        while((x = _getch()) != '\r')
        {
            printf("*");
            password[i++] = x;
        }
        password[i] = '\0';
        i = 0;
        strcat(username, password);
        fp = fopen("PROJECT_GCOS_FILE.txt","r");
        while((x = fgetc(fp)) != EOF)
        {
            accountsDB[i++] = x;
        }
        accountsDB[i] = '\0';
        fclose(fp);
        if(NULL == strstr(accountsDB, username))
        {
            printf("\n\n"space space"*Username or password is wrong");
            _getch();
            goto label2;
        }
        else
        {
            tempstr = strstr(accountsDB, username);
        }
        i = 0;
        while(tempstr[i] != '$')
        {
            i++;
        }
        sound = tempstr[++i];
        i = 0;
        while(tempstr[i] != '#')
        {
            i++;
        }
        bgColor = tempstr[++i];
        i -= 3;
        if(i == strlen(username))
        {
            //loadAllFiles();
            return 0;
        }
        else
        {
            printf("\n\n"space space"*Username or password is wrong");
            _getch();
            goto label2;
        }
    }
    if(n == '2')
    {
        label1 :
        system("cls");
        printf("\n\n\n\n\n\n\n\n\n\n\n"space space"   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
        printf("\n"space "\t\tUsername : %c                       %c\n",179,179);
        printf(""space space"   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);
        gotoxy(52,12);
        scanf("%s", username);
        i = 0;
        while((x = username[i]) != '\0')
        {
            if(x == '|' || x == '#' || x == '$')
            {
                printf("\n"space space "*Username must not contain special characters like |, #, $ etc.");
                _getch();
                goto label1;
            }
            i++;
        }
        fp = fopen("PROJECT_GCOS_FILE.txt","r");
        i = 0;
        while((x = fgetc(fp)) != EOF)
        {
            accountsDB[i++] = x;
        }
        fclose(fp);
        if(NULL == strstr(accountsDB, username))
        {
            printf("\n"space space"   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
            printf("\n"space "\t\tPassword : %c                       %c\n",179,179);
            printf(""space space"   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);
            gotoxy(52,15);
            i = 0;
            while((x = _getch()) != '\r')
            {
                if(x == '|' || x == '#' || x == '$')
                {
                    printf("\n"space space"*Password must not contain special characters like |, #, $ etc.");
                    _getch();
                    goto label1;
                }
                printf("*");
                password[i++] = x;
            }
            password[i] = '\0';
            printf("\n\n"space space"   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
            printf("\n"space "    Enter password again : %c                       %c\n",179,179);
            printf(""space space"   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);
            gotoxy(52,18);
            i = 0;
            while((x = _getch()) != '\r')
            {
                printf("*");
                tempstr[i++] = x;
            }
            tempstr[i] = '\0';
            if(strcmp(password, tempstr) == 0)
            {
                i = 0;
                fp = fopen("PROJECT_GCOS_FILE.txt","a");
                fputc('|',fp);
                while((x = username[i]) != '\0')
                {
                    fputc(x,fp);
                    i++;
                }
                i = 0;
                while((x = password[i]) != '\0')
                {
                    fputc(x,fp);
                    i++;
                }
                fputc('$', fp);
                fputc('1', fp);
                fputc('#', fp);
                fputc('1', fp);
                fclose(fp);
                printf("\n\n"space space"Sign up successful");
                _getch();
                goto label2;
            }
            else
            {
                printf("\n\n"space space"*Passwords do not match, try again");
                _getch();
                goto label1;
            }
        }
        else
        {
            printf("\n"space space"     *Username is already taken");
            _getch();
            goto label1;
        }
     }
    return 0;
}

/** Exit menu**/
int Exit()
{
    int i, j, k = 0, a = 219, pointer = 1;
    char ch = 0;
    system("cls");
    printf("\n\n\n");
    printf(space space"    EXIT\n");
    printf(space);
    for(i = 0; i < 72; i++)
    {
        printf("%c", 205);
    }
    printf("\n\n\n\n\n\n");
    printf(space space"Are you sure you want to exit?\n\n");
    printf(space space"  *Press [Enter] to exit\n");
    printf(space space"  *Press [Esc] to go back\n");
    printf("\n\n\n\n\n\n"space);
    for(i = 0; i < 72; i++)
    {
        printf("%c", 205);
    }
    while(1)
    {
        fflush(stdin);
        ch = _getch();
        if(sound == '1')
        {
            Beep(1500, 100);
        }
        if(13 == ch)
        {
            saveProgress();
            while(k < 5)
            {
            system("cls");
            system("color f0");
            for(i = 0; i < 10; i++)
            {
                printf("\n");
            }
            for(i = 0; i < 7; i++)
            {
                char anm[10][50] = {{a,a,a,a,a,a,a,a,a,a,0,0,0,0,0,0,0,0,a,a,a,a,a,a,a,a,a,a,0,0,a,a,a,a,a,a,a,a,a,a},
                                    {0,0,0,0,0,0,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,0,0,0,0,0,0,0,0,0,a,a,0,0,0,0,0,0,0,0},
                                    {0,0,0,0,0,0,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,0,0,0,0,0,0,0,0,0,a,a,0,0,0,0,0,0,0,0},
                                    {a,a,a,a,a,a,a,a,a,a,0,0,0,0,0,0,0,0,a,a,0,0,0,0,0,0,0,0,0,0,a,a,0,0,0,0,0,0,0,0},
                                    {a,a,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,a,a,0,0,0,0,0,0,0,0,0,0,a,a,0,0,0,0,0,0,0,0},
                                    {a,a,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,a,a,0,0,0,0,0,0,0,0,0,0,a,a,0,0,0,0,0,0,0,0},
                                    {a,a,0,0,0,0,0,0,0,0,a,a,a,a,a,a,a,a,a,a,0,0,0,0,0,0,0,0,0,0,a,a,a,a,a,a,a,a,a,a}};
                printf(space "\t\t");
                for(j = 0; j < 40; j++)
                {
                    printf("%c",anm[i][j]);
                }
                printf("\n");
            }
            if(k == 0)
            {
                Sleep(2000);
                a = 179;
            }
            if(k == 3)
            {
                a = 1;
            }
            Sleep(30);
            a--;
            k++;
            }
            Sleep(1000);
            system("cls");
            system("color 0f");
            exit(0);
        }
        if(ch == 27)
        {
            return 0;
        }
    }
}

int saveProgress()
{
    int i, j;
    char x, tempar1[100], *tempar2;
    FILE *fp;
    printf("\n");
    i = 0;
    while(tempstr[i] != '$')
    {
        i++;
    }
    tempstr[++i] = sound;
    i = 0;
    while(tempstr[i] != '#')
    {
        i++;
    }
    tempstr[++i] = bgColor;
    i = 0;
    while(tempstr[i] != '\0')
    {
        tempar1[i] = tempstr[i];
        i++;
    }
    tempar1[i] = '\0';
    tempar2 = strrev(strstr(strrev(accountsDB), strrev(username)));
    i = strlen(username);
    j = strlen(tempar2);
    i = j - i;
    while(j >= i)
    {
        tempar2[j--] = '\0';
    }
    strcat(tempar2, tempar1);
    i = 0;
    fp = fopen("PROJECT_GCOS_FILE.txt","w");
    while((x = tempar2[i]) != '\0')
    {
        fputc(x, fp);
        i++;
    }
    fclose(fp);
    return 0;
}

/** Main function **/
int main()
{
    int gameNumber = 1;
    char ch, user[100];

    login(user);
    while(1)
    {
        mainMenu(user, gameNumber);
        ch = _getch();
        if(sound == '1')
        {
            Beep(1500, 100);
        }
        if(13 == ch)
        {
            if(gameNumber == 1)
            {
                numberPuzzle();
            }
            if(gameNumber == 2)
            {
                findThePairs();
            }
            if(gameNumber == 3)
            {
                minesweeper();
            }
            if(gameNumber == 4)
            {
                towersOfHanoi();
            }
            if(gameNumber == 5)
            {
                checkers();
            }
            if(gameNumber == 6)
            {
                TZFE();
            }
            if(gameNumber == 7)
            {
                ticTacToe();
            }
            if(gameNumber == 8)
            {
                wordPuzzle();
            }
            if(gameNumber == 9)
            {
                hangman();
            }
            if(gameNumber == 10)
            {
                settings();
            }
            if(gameNumber == 11)
            {
                Exit();
            }
        }
        if(-32 == ch)
        {
            switch(_getch())
            {
                case 75 :
                    if(gameNumber == 1)
                    {
                        gameNumber = 11;
                    }
                    else
                    {
                        gameNumber--;
                    }
                break;

                case 77 :
                    if(gameNumber == 11)
                    {
                        gameNumber = 1;
                    }
                    else
                    {
                        gameNumber++;
                    }
                break;
            }
        }
    }
    return 0;
}
