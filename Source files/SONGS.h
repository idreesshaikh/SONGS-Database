#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>

////*Structure declared*////
typedef struct song
{
    char SongTitle[30];
    char NameOfArtist[30];
    char Genre[20];
    char AlbumName[30];
    char YearOfRelease[5];
    char Duration[6];
} song ;



////* MAIN MENU *////

int main_menu(void) // Main menu Function
{
    system("cls"); //Clear Screen
    printf("                SONGS\n");
    printf("--------------------------------------\n\n");
    printf("\t    MAIN MENU\n\n");

    printf("    Select by Categories:\n\n");
    printf("    1. Add a new Song.\n");
    printf("    2. Search any Song.\n");
    printf("    3. Exit the Program.\n\n");

    printf("    Enter any of the above numbers to choose: ");
    int select1;
    scanf("%d",&select1);
    if(select1>3 && select1<1)
    {
        return 0;
    }
    return select1;
}


////*Search Menu*////
int second_menu(void)
{
    system("cls"); //Clear Screen
    printf("\t      SONGS\n\n");
    printf("\t    SEARCH MENU\n\n");

    printf("     Search by Categories:\n\n");
    printf("     1. Artist(s).\n");
    printf("     2. Genre.\n");
    //printf("     3. Year of Release.\n");
    printf("     4. Album Name.\n");
    printf("     5. Go back to the Main Menu.\n");
    printf("     6. Exit the Program.\n");

    printf("Enter any of the above numbers to choose: ");
    int select2;
    scanf("%d",&select2);
    if(select2>6 && select2<1)
    {
        return 0;
    }
    return select2;
}


////*File Open Write function*////
FILE* open_write()
{
    FILE *file = fopen("song.txt", "a+");
    return file;
}


////*File Open Read function*////
FILE* open_read()
{
    FILE *file = fopen("song.txt", "r");
    return file;
}


////*Null Check Function*////
void null_check(FILE* file)
{
    if (file == NULL)
    {
        printf(" Error the file does not exist \n");
        //return NULL;
    }
}


///////////ENUMERATION DECLARATION AND DEFINITION///////////


typedef enum permission {NO,YES,CONFUSED} permission; // Enumeration Declaration

//Enumerated Function with YES , NO , and CONFUSED.
permission check(void)
{
    printf("Continue (Y/N)\n");
    char slt = getch();
    if (slt == 'N'|| slt == 'n')
    {
        return NO;
    }
    else if (slt=='Y'||slt=='y')
    {
        printf("\nContinue for a new song.\n");
        return YES;
    }
    else
    {
        printf("\nInvalid Input\n");
        return CONFUSED;
    }
}

////ADDING A SONG Function/////

permission adding_song(void)
{
    song s1;
    FILE *file; //File Pointer
    file = open_write(); // Calling Open file function to Write
    null_check(file);
    printf("\n    Song Title: ");
    fprintf(file,"%s", "Song Title: ");
    scanf("%s",&s1.SongTitle);
    fputs(s1.SongTitle,file);
    //putc('  ',file);
    printf("\n    Artist(s): ");
    fprintf(file,"%s", "  Artist(s): ");
    scanf("%s",&s1.NameOfArtist);
    fputs(s1.NameOfArtist,file);
    //putc('  ',file);
    printf("\n    Name of the Album: ");
    fprintf(file,"%s", "  Name of the Album: ");
    scanf("%s",&s1.AlbumName);
    fputs(s1.AlbumName,file);
    //putc('  ', file);
    printf("\n    Year of Release: ");
    fprintf(file,"%s", "  Year of Release: ");
    scanf("%s",&s1.YearOfRelease);
    fputs(s1.YearOfRelease,file);
    //putc('  ', file);
    printf("\n    Genre: ");
    fprintf(file,"%s", "  Genre: ");
    scanf("%s",&s1.Genre);
    fputs(s1.Genre, file);
    //putc('  ', file);
    printf("\n    Time Duration(mm:ss): ");
    fprintf(file,"%s", "  Time Duration(mm:ss): ");
    scanf("%s",&s1.Duration);
    fputs(s1.Duration,file);
    //putc('  ', file);
    fclose(file); // Closing the file
    if(check()==YES)  //Calling Check function for YES or NO
    {
        return YES;
    }
    else
    {
        return NO;
    }
}

//// Main Search Function////
int search_engine(int Q,char art[]){
    fflush(stdin); //Flush the file
    FILE *file; //File Pointer
    file = open_read(); // Calling Open file function to Read
    null_check(file); // Null check of file pointer
    int Ai = 0,Vi = 0; //Lengths of A and V
    char *V  = NULL;  //Pointer B is also Null
    char *A_array = NULL; // Pointer array of A which is NULL
    char A; // Character Variable A
    char P; //Character Variable P
    V = (char*)malloc(Vi*sizeof(char)); //Allocating memory to pointer V
    A_array = (char*)malloc(Ai*sizeof(char));// Same allocating memory to pointer of A
    Q = 0; // For confirming
        {
        fflush(stdin);
        printf("\nEnter the %s ",art);
        while((scanf("%c",&A) == 1) && (A != '\n'))
        {
            A_array = (char*)realloc(A_array,((Ai+1)*sizeof(char)));
            A_array[Ai] = A;
            Ai++;
        }
        A_array = (char*)realloc(A_array,(Ai+1)*sizeof(char));
        A_array[Ai] = '\0';
        while((fscanf(file,"%c", &P)) != EOF)
        {
            if(P != '\n')
            {
                V = (char*)realloc(V,(Vi+1)*sizeof(char));
                V[Vi] = P;
                Vi++;
            }
            else if(P == '\n')
            {
                V = (char*)realloc(V,(Vi+1)*sizeof(char));
                V[Vi] = '\0';
                if(strcmp(A_array,V))
                {
                    printf("\n %s \n", V);
                    Q = 1;
                }
                free(V);
                Vi = 0;
                V = (char*)malloc(Vi*sizeof(char));
            }
        }
        free(V); //Freeing V pointer
        free(A_array); //Freeing A_array pointer
    }
    fclose(file);
    return Q;
}

     ////Search Artist(s)////
int search_artist(int Q)
{
    char art[]= {"  Artist(s): "};
    int Z = search_engine(Q , art);
    return Z;
}
     ////Search Name of Album////
int search_album_name(int Q)
{
    char art[]= {"  Name of the Album: "};
    int Z = search_engine(Q , art);
    return Z;
}
     ////Search Genre////
int search_genre(int Q)
{
    char art[]= {"  Genre: "};
    int Z = search_engine(Q , art);
    return Z;
}
     ////Search Year Of Release////
int search_release(int Q)
{
    char art[]= {"  Year of Release: "};
    int Z = search_engine(Q , art);
    return Z;
}
