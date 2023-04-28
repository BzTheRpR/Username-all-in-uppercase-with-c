#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {

    char unm[1000];
    int i;
    

    printf("Give us your user name(All letter of your user must be in upper case and you can not use any digits): ");
    scanf("%s", unm);
  
    while (1)
    {
        int flag = 0;
        int low = 0;
        int dig = 0;
        int sp = 0;

        for (i = 0; unm[i] != '\0'; i++)
        {
            if (islower(unm[i]) != 0)
            {
                low++;
            }
            else if (isdigit(unm[i]) != 0)
            {
                dig++;
            }
            else if (isalnum(unm[i]) == 0)
            {
                sp++;
            }
        }
        if (low == 0 && dig == 0 && sp==0)
        {
            printf("!!!SUCCESSFULLY accepted your user name");
            break;
        }
        else if(low!=0 && dig==0 && sp==0)
        {
            printf("Umm looks like you have gave %d lower case(s)\nNot a problem if you want we can convert it into upper cases\nPress y and the hit enter if you want it.Otherwise press n and hit enter\ny/n: ", low);
            char yn;
            scanf(" %c", &yn);
            while (yn != 'y' && yn != 'n')
            {
                printf("Please enter y or n: ");
                scanf(" %c", &yn);
            }
            if (yn == 'y')
            {
                for (i = 0; unm[i] != '\0'; i++)
                {
                    if (islower(unm[i]) != 0) unm[i] = (char)((int)unm[i] - 32);

                }
                printf("We have succesfully converted them into upper cases :)\n");
                printf("Your username stored as: %s", unm);
                puts(unm);
                flag = 1;
            }
            else if (yn == 'n')
            {
                printf("Give us your user name(All letter of your user must be in upper case and you can not use any digt): ");
                
            }
        }
        else if (dig != 0 || sp!=0)
        {
            printf("Sorry, you have enterd %d digit(s) %d none alphanumeric(without digit) character(s) and %d lower case(s)....\nPlease enter an username with capital letter only: ", dig, sp, low);
        }
        if (flag == 1)break;
        else 
        {
            scanf(" %s", unm);
        }
    }

    return 0;
}