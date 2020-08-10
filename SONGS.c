#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#include "SONGS.h"

/* Main Function*/
int main(void)
{
    int Q,P,R,S,T;
    bool exit=false;
Begin:
    while(exit==false) //Infinite loop
    {
        int a = main_menu(); //Calling Main Menu Function
        switch(a) // Switch Statement 1
        {
        /*CASE 1*/

        case 1:
            Q = adding_song();
            if(Q==YES)
            {
                continue;
            }
            else
            {
                break;
            }

        /*CASE 2*/
        case 2:
            while(exit==false) //Infinite loop
            {
                int c = second_menu(); //Calling the Search Menu Function
                switch(c) // Switch Statement 2
                {
                /*CASE 2a*/
                case 1:
                    P = search_artist(P);
                    if(P==0)
                    {
                        printf("Not Found\n\n");
                        printf("YES to Go back to Main Menu and NO to Search again ");
                        if(check()==YES)
                        {
                            goto Begin;
                        }
                        else if (check()==NO)
                        {
                            printf("\nSearch again.");
                            break;
                        }
                        else
                            exit;
                    }
                    else
                        exit;
                /*CASE 2b*/
                case 2:
                    R = search_genre(R);
                    if(R==0)
                    {
                        printf("Not Found\n\n");
                        printf("YES to Go back to Main Menu and NO to Search again ");
                        if(check()==YES)
                        {
                            goto Begin;
                        }
                        else if (check()==NO)
                        {
                            printf("\nSearch again.");
                            break;
                        }
                        else
                            exit;
                    }
                    else
                        exit;
                /*CASE 2c*/
                case 3:
                    S = search_release(S);
                    if(S==0)
                    {
                        printf("Not Found\n\n");
                        printf("YES to Go back to Main Menu and NO to Search again ");
                        if(check()==YES)
                        {
                            goto Begin;
                        }
                        else if (check()==NO)
                        {
                            printf("\nSearch again.");
                            break;
                        }
                        else
                            exit;
                    }
                    else
                        exit;
                /*CASE 2d*/
                case 4:
                    T = search_album_name(T);
                    if(T==0)
                    {
                        printf("Not Found\n\n");
                        printf("YES to Go back to Main Menu and NO to Search again ");
                        if(check()==YES)
                        {
                            goto Begin;
                        }
                        else if (check()==NO)
                        {
                            printf("\nSearch again.");
                            break;
                        }
                        else
                            exit;
                    }
                    else
                        exit;

                /* CASE 2e*/
                case 5:
                    goto Begin;
                /* CASE 2f*/
                case 6:
                    exit=true;
                    break;
                /* DEFAULT*/
                default :
                    printf("You've entered an invalid number");
                    printf("\n\n\tPress 0 to go back or press any key to keep on Searching...");
                    int num;
                    scanf("%d",&num);
                    if(num == 0)
                    {
                        break;
                    }
                    else
                    continue;
                    	
                }
            }
        /*Case 3*/
        case 3:
            exit=true;
            break;

        /* DEFAULT*/
        default :
            printf("You've entered an invalid number");
            printf("\n\n\tPress 0 to Exit or any other number to go to MAIN MENU: ");
            int num;
            if(scanf("%d",&num) == 0)
            {
                exit= true;
                break;
            }
            else
            	continue;
        }
    }
    return 0;
}
