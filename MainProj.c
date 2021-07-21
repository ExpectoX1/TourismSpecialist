#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <math.h>
#include<process.h>
#include <time.h>
#define NUMLETTERS 100
// Variables
int LineChoose_t;
char Str[1024];
char *array[10];

char Gender[100];
char CustName[100];
char PlaceChosen[1000];
int PricePerDayChosen;
int TotalPrice;
int NoOfPpl;
int NoOfDays;
int Rooms; 


int Age;

int hours, minutes, seconds, day, month, year;
int Day,Month,Year, MaxDay,t;


void OpenAndReadFile(char* Filename)
{
    FILE *fp = NULL;
	char *line,*record;
	char buffer[1024];
	if ((fp = fopen( Filename, "at+")) != NULL)
	{
		char delims[] = ",";
		char *result = NULL;
		int j = 0;
        int i = 0 ; 
		 while ((line = fgets(buffer, sizeof(buffer), fp))!=NULL)//The loop continues when the end of the file is not read
		{
            

			record = strtok(line, ",");
			 while (record != NULL)//Read the data of each row
			{
				 if (strcmp(record, "Ps:") == 0)//When reading the Ps line, do not continue reading
					return 0;
				 printf("%s ", record);//Print out every data read
				 if (j == 25) //Just read the first 25 columns
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
}
int DataPrint()
{
    
   FILE* fp = fopen("DataStore.csv", "a+");
    if (fp == NULL)
    { 
        // Error in file opening
        printf("Can't open file\n");
        return 1;
    }
    // Saving data in file
    fprintf(fp, "Name : %s, Age : %d , Gender : %s, Place Chosen : %s, Price Per Day: %d, Number Of People : %d, Number Of Days Stay: %d, Rooms Booked : %d, Grand Total : %d Rs\n", CustName,Age,Gender,PlaceChosen,PricePerDayChosen,NoOfPpl,NoOfDays,Rooms,TotalPrice);
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
void GetElementsFromString()
{ 
    int i=0;

    array[i] = strtok(Str,",");

    while(array[i]!=NULL)
{
   array[++i] = strtok(NULL,",");
}
    strcpy(PlaceChosen,array[1]);
    //printf("%s",array[1]);
    //printf("%s",PlaceChosen);
    PricePerDayChosen = atoi(array[2]);
    //printf("%d", PricePerDayChosen);
}  
void PriceCompute(int TravelCost)
{
    printf("Enter the Number Of People :");
    scanf("%d",&NoOfPpl);
    printf("Enter the number of Days :");
    scanf("%d",&NoOfDays);
    Rooms = ceil((float)NoOfPpl/4);
   // printf("%d",PricePerDayChosen);
    TotalPrice = ((TravelCost*NoOfPpl) + (NoOfDays*PricePerDayChosen)*Rooms);
    
}
void StoringString()
{
    
   // printf("%s",Str);
    GetElementsFromString();

}   
int DestinationChoose()
{
    int lineChoose ;
    int yesno;


    int NA = 90000; //Round Cost
    int AS = 50000;
    int EU = 60000;
    int AU = 90000;
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
        printf("Do you want to open the options in a Excel Document? \n");
        printf("1. Yes");
        printf("2. No");
        scanf("%d",&yesno);
        if(yesno==1)//|| strcmp("y",yesno))
        {
            system("start d1na.xlsx");
        }
        else if(yesno==2)//|| strcmp("n",yesno))
        {
            OpenAndReadFile("d1na.csv");
            
        }
        else
        {
            printf("Enter a Valid Option: \n");
            break;
        }
        printf("\n  Enter the Place you want to travel to ");
        scanf("%d",&lineChoose);
        LineChoose_t = lineChoose;
        ConvertLineToString("d1na.csv",LineChoose_t);
        StoringString();
        PriceCompute(NA);
        //printf("%d ", TotalPrice);
    break;
    case 2:
        printf("Do you want to open the options in a Excel Document? \n");
        printf("1. Yes\n");
        printf("2. No\n");
        scanf("%d",&yesno);
        if(yesno==1)
        {
            system("start d1asia.xlsx");
        }
        else if(yesno==2)
        {
            OpenAndReadFile("d1asia.csv");
        }
        else
        {
            printf("Enter a Valid Option: \n");
            break;
        }
        printf("\n Enter the Place you want to travel to ");
        scanf("%d",&lineChoose);
        LineChoose_t = lineChoose;
        ConvertLineToString("d1asia.csv",LineChoose_t);
        StoringString();
        PriceCompute(AS);
    break; 
    case 3:
        
        //OpenAndReadFile("d1euro.csv");
        printf("Do you want to open the options in a Excel Document? \n");
        printf("1. Yes\n");
        printf("2. No\n");
        scanf("%d",&yesno);
        
        if(yesno==1)
        {
            system("start d1euro.xlsx");
        }
        else if(yesno==2)
        {
            OpenAndReadFile("d1euro.csv");
        }
        else
        {
            printf("Enter a Valid Option: \n");
            break;
        }
        
        
        printf("\n  Enter the Place you want to travel to ");
        
        scanf("%d",&lineChoose);
        LineChoose_t = lineChoose;
        ConvertLineToString("d1euro.csv",LineChoose_t);
        StoringString();
        PriceCompute(EU);
      
    break;
    case 4: 
        printf("Do you want to open the options in a Excel Document? \n");
        printf("1. Yes\n");
        printf("2. No\n");
        scanf("%d",&yesno);
        if(yesno==1)
        {
            system("start d1aus.xlsx");
        }
        else if(yesno==2)
        {
            OpenAndReadFile("d1aus.csv");
        }
        else
        {
            printf("Enter a Valid Option: \n");
            break;
        }
        printf("\n  Enter the Place you want to travel to ");
        scanf("%d",&lineChoose);
        LineChoose_t = lineChoose;
        ConvertLineToString("d1aus.csv",LineChoose_t);
        StoringString();
        PriceCompute(AU);
        
    break;
    default:
        printf("Please Enter a Valid Option\n");
        DestinationChoose();
    break;
    }
}
void ConvertLineToString(char *FLEN ,int lne)
{
    char str[1024];
    int end, loop, line= lne;
    FILE *fd = fopen( FLEN, "r");
    //if (fd == NULL) 
    //{
        //printf("Failed to open file\n");
        //return -1;
    //}
    for(end = loop = 0;loop<line+1;++loop){ 
        if(0==fgets(str, sizeof(str), fd)){//include '\n'
            end = 1;//can't input (EOF)
            break;
        }
    }
    if(!end)
    {
        strcpy(Str,str);
    }
    fclose(fd);
}
void Exit()
{
    exit(0);
}
void menu()
{   
    int lineChoose ;
    int yesno;
    int choice;
    char Gen;
    printf("\t \tHi, Welcome to the Booking System\n");
    printf("1. Book Custom Tickets\n");
    printf("2. Book Package\n");
    printf("3. View Tickets(Under Constructon)\n");
    printf("4. Cancel Tickeit(Under Construction)\n");
    printf("5. Exit Program\n");
    printf("6. Manager Portal\n ");
    scanf("%d",&choice);

    switch (choice)
    {
     case 1:
      {  
        // Asking user input for the
        // new record to be added
        printf("\nEnter Your Name\n");
        scanf("%s", &CustName);
        //printf("\nEnter Available Amount\n");
        //scanf("%s", &Gender);
        printf("\nEnter Your Age\n");
        scanf("%d", &Age);
        printf("\nEnter Your Gender (M/F/O)\n");
        scanf("%s",&Gen);
        switch (Gen)
        {
        case 'M' :
            strcpy(Gender,"Male");
            break;
        case 'F' :
            strcpy(Gender,"Female");
            break;
        case 'O' :
            strcpy(Gender,"Others");
            break;
        case 'm' :
            strcpy(Gender,"Male");
            break;
        case 'f' :
            strcpy(Gender,"Female");
            break;
        case 'o' :
            strcpy(Gender,"Others");
            break;
        default:
            printf("Invalid Option");
            strcpy(Gender,"N/A");
            break;
        }
        
        DestinationChoose();
        
        DataPrint();

        break;
     }
   
        
    
      case 2:
      {  
        // Asking user input for the
        // new record to be added
        printf("\nEnter Your Name\n");
        scanf("%s", &CustName);
        //printf("\nEnter Available Amount\n");
        //scanf("%s", &Gender);
        printf("\nEnter Your Age\n");
        scanf("%d", &Age);
        printf("\nEnter Your Gender (M/F/O)\n");
        scanf("%s",&Gen);
        switch (Gen)
        {
        case 'M' :
            strcpy(Gender,"Male");
            break;
        case 'F' :
            strcpy(Gender,"Female");
            break;
        case 'O' :
            strcpy(Gender,"Others");
            break;
        case 'm' :
            strcpy(Gender,"Male");
            break;
        case 'f' :
            strcpy(Gender,"Female");
            break;
        case 'o' :
            strcpy(Gender,"Others");
            break;
        default:
            printf("Invalid Option");
            strcpy(Gender,"N/A");
            break;
        }
        
        printf("Do you want to open the options in a Excel Document? \n");
        printf("1. Yes");
        printf("2. No\n");
        scanf("%d",&yesno);
        if(yesno==1)//|| strcmp("y",yesno))
        {
            system("start Package.xlsx");
        }
        else if(yesno==2)//|| strcmp("n",yesno))
        {
            OpenAndReadFile("Package.csv");
            
        }
        else
        {
            printf("Enter a Valid Option: \n");
            break;
        }
        printf("\n  Enter the Place you want to travel to ");
        scanf("%d",&lineChoose);
        LineChoose_t = lineChoose;
        ConvertLineToString("Package.csv",LineChoose_t);
        StoringString();
        PriceCompute(24000);
        
        DataPrint();

        break;
      }
    }
    
   
    
    
   
}
int main()
    {   
    menu();
    return 0;
    }

