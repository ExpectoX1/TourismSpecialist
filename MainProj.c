#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define NUMLETTERS 100
// Variables
char name[100];
int age[100];
int codes[100];
char destin[100];
long price[100];
int no_days[];
int no_ppl[];
long tot_pp[];
int t_p[];
int a = 0;
main();

typedef struct 
{
    int SrNo;
    char Destination[200];
    int PricePerDay;
    char Discription[100000];
} record_t;

int DataInput()
{
    
   FILE* fp = fopen("DataStore.csv", "a+");
    char CustName[100];
    int Age; 
    char Gender;
  
  
  
    if (fp == NULL)
    { 
        // Error in file opening
        printf("Can't open file\n");
        return 1;
    }
  
    // Asking user input for the
    // new record to be added
    printf("\nEnter Your Name\n");
    scanf("%s", &CustName);
    //printf("\nEnter Available Amount\n");
    //scanf("%s", &Gender);
    printf("\nEnter Your Age\n");
    scanf("%d", &Age);
    
  
    // Saving data in file
    fprintf(fp, "%s, %d\n", CustName,Age);
  
    printf("\nNew Account added to record \n");
  
    fclose(fp);
    return 0;    

}
int printRandoms(int lower, int upper,  int count)
{
    int i;
    for (i = 0; i < count; i++) {
        int num = (rand() %
           (upper - lower + 1)) + lower;
        return num;
    }
}      
int DestinationChoose()
{
     
FILE *fp = NULL;
	char *line,*record;
	char buffer[512];
	if ((fp = fopen("DataPlace.csv", "at+")) != NULL)
	{
		char delims[] = ",";
		char *result = NULL;
		int j = 0;
		 while ((line = fgets(buffer, sizeof(buffer), fp))!=NULL)//The loop continues when the end of the file is not read
		{
			record = strtok(line, ",");
			 while (record != NULL)//Read the data of each row
			{
				 if (strcmp(record, "Ps:") == 0)//When reading the Ps line, do not continue reading
					return 0;
				 printf("%s ", record);//Print out every data read
				 if (j == 14) //Just read the first 13 columns
					break;
				record = strtok(NULL, ",");
				j++;
			}
			printf("\n"); 
			j = 0;
 
		}
		fclose(fp);
		fp = NULL;
	}

    


   /* int NA = 75000;
    int AS = 30000;
    int EU = 55000;
    int AU = 85000;
    printf("Choose the Continent you would like to travel to.\n");
    printf("1. North America\n"); 
    printf("2. Asia\n");
    printf("3. Europe\n");
    printf("4. Australia\n");

    int choose  = 0 ; 
    scanf("%d",&choose);

    switch (choose)
    {
    case 1:
        
    break;
    case 2:
        ;
    break; 
    case 3:
      
    break;
    case 4: 
        
    break;
    default:
        printf("Please Enter a Valid Option\n");
        DestinationChoose();
    break;
    }*/
    
}
void BookCT()
{ 
    char per_name[20];int per_age;
    age[a]=per_age;
        
        
        
    
    for(int i=0;i<50;i++)// change i for new no. of destinations
    {
        printf("%d, %s , %ld\n",i+1, destin[i], price[i]);
    }
    int place;
    printf("Enter the place Sr No where you want to go to.\n");
    scanf("%d",&place);
    place-=1;
    t_p[a] = place;
    int ndays; 
    printf("Enter Number of Days.\n");
    scanf("%d",&ndays);
    no_days[a]=ndays;
    int nppl;
    printf("Enter Number of People.\n");
    scanf("%d",&nppl);
    no_ppl[a]=nppl;

    //price calc
    long t_price= price[a]*no_ppl[a]*no_days[a];
    tot_pp[a]=t_price;
    printf("Your total billed amt is:%ld\n",t_price);
    int code = printRandoms(1000,9999,1000);//x
    printf("Your code is - %d\n",code);
    printf("Don't Forget it\n");
    codes[a] = code ; 
    //printf("y or n\n");
    //char opt; scanf("%c",&opt);
    //if(opt=="y")
    //{   name[a]=per_name;
    //    age[a]=per_age;
    //    no_days[a]=ndays;
    //    no_ppl[a]=nppl;
    //    tot_pp[a]=t_price;

    //    printf("Your booking has been confirmed\n");
    //}
    //else
    //{
    //    printf("Your booking has been cancelled\n");
    //}
    

    
    //book
    //call menu()
    a++;
    t_price=0;
    

}
void View ()
{
    a=0;
    int t = 0 ;
    printf("Enter the Code\n");
    scanf("%d",&t );
    for(int i =0 ; i<100 ; i++)
    {
    if(t == codes[i])
    {
        printf("Name:%s\n", name[a]);
        printf("Age:%d\n", age[a]);
        printf("Destination:%s\n",destin[t_p[a]]);
        printf("Number of ppl: %d\n",tot_pp[a]);
        printf("Number of Days:%d\n",no_days[a]);

    }
    else
    {
        printf("Enter a Valid Code");
    }
    }
    






}
void Exit()
{
    exit(0);
}
void menu()
{   

    int choice;
    printf("\t \tHi, Welcome to the Booking System\n");
    printf("1. Book Custom Tickets\n");
    printf("2. Book Package\n");
    printf("3. View Tickets(Under Constructon)\n");
    printf("4. Cancel Tickeit(Under Construction)\n");
    printf("5. Exit Program\n");
    printf("6. Manager Portal ");
    scanf("%d",&choice);

    switch (choice)
    {
    case 1:
    {
        DataInput();  
        DestinationChoose();
        break;
    }
    
   
    }
    
   
}
int main()
    {   
    menu();

    return 0;
    }

