#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <math.h>
#include<process.h>
#include <time.h>
#define NUMLETTERS 100
#define MAXLEN1000 1000
#define MAXLEN100 100
// Variables
int LineChoose_t;
char Str[1024];
char *array[10];
int IDEnter; // ID Entered by the person
char DataStoreLine[MAXLEN1000];

char Gender[MAXLEN100];
char CustName[MAXLEN100];
char PlaceChosen[MAXLEN1000];
int PricePerDayChosen;
int TotalPrice;
int NoOfPpl; 
int NoOfDays;
int Rooms; 
int ID;
int tracer=1;
int Age;
int hours, minutes, seconds, day, month, year;
int Day,Month,Year, MaxDay,t;


void MangerPortal()  // Function to Open a file for the Admin or manager. 
{
    char str[1000];
    FILE *fp1 = fopen("DataStore.csv","a+"); // Open the file DataStore.csv and ManagerFile.txt
    FILE *fp2 = fopen("ManagerFile.txt" , "w");
    while( fgets(str,10000,fp1) != NULL)
    {
        fprintf(fp2, "%s",str);
    }
    fclose(fp1); // Close the respective files 
    fclose(fp2);
    system("start ManagerFile.txt"); // open ManagerFile.txt
}
int DeleteEntry(char *FileName , int delete_line )  // Delete a Entry/Ticket from our Data File
{
    FILE *fileptr1, *fileptr2; // File Pointers
    
    char ch;
    char line1[10000];
    int temp = 1;

    // printf("Enter file name: ");
    // scanf("%s", FileName);
    //open file in read mode
    fileptr1 = fopen(FileName, "r");
    // ch = getc(fileptr1);
    //  while (ch != EOF)
    // {
    //    printf("%c", ch);
    //   ch = getc(fileptr1);
    // }
    //rewind
    rewind(fileptr1); // Go to the begining of the file pointer
    //printf(" \n Enter line number of the line to be deleted:");
    //scanf("%d", &delete_line);
    //open new file in write mode
    fileptr2 = fopen("replica.c", "w");
    ch = 'A';
    while (fgets(line1,100000,fileptr1) != NULL) // get each line
    {
    
        //except the line to be deleted
        if (temp != delete_line)
        {
            //copy all lines in file replica.c execpt the line to be deleted
            // printf("%s", line1);
            fprintf(fileptr2 ,"%s", line1);
        }
        temp++;
    }
    fclose(fileptr1); // Close the file ptrs
    fclose(fileptr2);
    remove(FileName); // Remove orignal file
    //rename the file replica.c to original name
    rename("replica.c", FileName); // Rename the file
    //fileptr1 = fopen(filename, "r");
    //ch = getc(fileptr1);
    //while (ch != EOF)
    // {
    // printf("%c", ch);
    // ch = getc(fileptr1);
    //}
    //fclose(fileptr1);
    return 0;
}
int CheckOS() // Function to check the OS on which the program is running on.
{  

  
 
// Checking for windows OS with
// _WIN32 macro
#ifdef _WIN32
           return 1;
  
// Checking for mac OS with
// __APPLE__ macro
#elif __APPLE__ 
           return 2;
  
// Checking for linux OS with
// __linux__ macro
#elif __linux__    
         return 3;
          
// Checking for iOS embedded OS with
// TARGET_OS_EMBEDDED macro
#elif TARGET_OS_EMBEDDED
    
  
// Checking for iOS simulator OS with
// TARGET_IPHONE_SIMULATOR macro
#elif TARGET_IPHONE_SIMULATOR
  
  
// Checking for iPhone OS with
// TARGET_OS_IPHONE macro
#elif TARGET_OS_IPHONE
    
// Checking for MAC OS with
// TARGET_OS_MAC macro
#elif TARGET_OS_MAC
    
// Checking for Android OS with
// __ANDROID__ macro
#elif__ANDROID__
   
  
// Checking for unix OS with
// __unix__ macro
#elif __unix__
  
  
// Checking for POSIX based OS with
// _POSIX_VERSION macro
#elif _POSIX_VERSION
    
  
// Checking for Solaris OS with
// __sun macro
#elif __sun
   
  
// Checking for HP UX OS with
// __hpux macro
#elif __hpux
    
  
// Checking for BSD OS with
// BSD macro
#elif BSD
   
  
// Checking for DragonFly BSD OS with
// __DragonFly__ macro
#elif __DragonFly__
   
// Checking for FreeBSD OS with
// __FreeBSD__ macro
#elif __FreeBSD__
    
  
// Checking for Net BSD OS with
// __NetBSD__ macro
#elif __NetBSD__
   
  
// Checking for Open BSD OS with
// __OpenBSD__ macro
#elif __OpenBSD__

// If neither of them is present
// then this is printed...
#else
    printf("Sorry, the system are"
           "not listed above.\n");
#endif
    return 0;

}
void OpenAndReadFile(char* Filename) // Function to Open and read the contents of file.
{
    FILE *fp = NULL;
	char *line,*record;
	char buffer[1024];
	if ((fp = fopen( Filename, "at+")) != NULL)
	{
		char delims[] = ","; // deleimiter "," to read csv
		char *result = NULL;
		int j = 0; // Count vars
        int i = 0 ; 
		while ((line = fgets(buffer, sizeof(buffer), fp))!=NULL)//The loop continues when the end of the file is not read
		{
            
			record = strtok(line, ",");
			 while (record != NULL)//Read the data of each row
			{
				if (strcmp(record, "Ps:") == 0)//When reading the Ps line, do not continue reading
				return 0;
				printf("%s ", record);//Print out every data read
				if (j == 30) //Just read the first 30 columns as our csv has only 30 lines mostly 
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
int DataPrint() // Function to Print the Contents in a file 
{
    
   FILE* fp = fopen("DataStore.csv", "a+");
    if (fp == NULL) // Checking if the file exists.
    { 
        // Error in file opening
        printf("Can't open file\n");
        return 1;
    }
    // Saving data in file
    fprintf(fp, "Unique ID : %d, Name : %s, Age : %d , Gender : %s, Place Chosen : %s, Price Per Day: %d, Number Of People : %d, Number Of Days Stay: %d, Rooms Booked : %d, Grand Total : %d Rs\n", ID,CustName,Age,Gender,PlaceChosen,PricePerDayChosen,NoOfPpl,NoOfDays,Rooms,TotalPrice);
    printf("Ticket Booking Confirmed ! \n");
  
    fclose(fp);
    return 0;    

} // Siddharth
int GenrateRandomUniqueID()
{
    
    FILE *fp = fopen("ids.txt","a+");
    int arr[7];
    int lower = 1000, upper = 9999, count = 10;

    srand(time(0));

   // printf("The random numbers are: ");
    for (int i = 0; i < count; i++) 
    {
        int num = (rand() % (upper - lower + 1)) + lower;
        arr[i] = num;
        
    }
    for(int i = 0 ; i < 5;i++)
    {
      //  printf("%d",arr[i]);
    }

    int lower1 = 0, upper1 = 4, count1 = 1;

    srand(time(0));

  //  printf("The random numbers are: ");
    for (int i = 0; i < count1; i++) {
        int x = (rand() % (upper1 - lower1 + 1)) + lower1;
        //printf("%d ", x);
        //printf("%d",arr[x]);s
        ID = arr[x];
        fprintf(fp,"%d\n",arr[x]);
        printf("Your Unique ID is %d, Please remember it for future reference\n",ID);
    }
    return 0;
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
    int a  = 8377;
    printf("Enter the Number Of People : ");
    scanf("%d",&NoOfPpl);
    printf("Enter the number of Days : ");
    scanf("%d",&NoOfDays);
    Rooms = ceil((float)NoOfPpl/4);
   // printf("%d",PricePerDayChosen);
    TotalPrice = ((TravelCost*NoOfPpl) + (NoOfDays*PricePerDayChosen)*Rooms);
    printf("Your Total Booking amount is  : %ld Rs.\n",TotalPrice);
    GenrateRandomUniqueID();
    
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
    int choose ; 

    int NA = 90000; //Round Cost
    int AS = 50000;
    int EU = 60000;
    int AU = 90000;
    printf("Choose the Continent you would like to travel to.\n");
    printf("1. North America\n"); 
    printf("2. Asia\n");
    printf("3. Europe\n");
    printf("4. Australia\n");
    printf("Enter your choice : ");

    
    scanf("%d",&choose);

    switch (choose)
    {
    case 1:
        printf("Do you want to open the options in a Excel Document? \n");
        printf("1. Yes\n");
        printf("2. No\n");
        printf("Enter your choice : ");
        scanf("%d",&yesno);
        if(yesno==1)//|| strcmp("y",yesno))
        {
           if(CheckOS ==1)
           {
                system("start d1na.xlsx");
           }
           else if(CheckOS == 2)
           {
                system("libreoffice --calc d1na.xlsx"); // come here later
           }
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
        printf("\nEnter the Place you want to travel to : ");
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
        printf("Enter your choice : ");
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
        printf("\nEnter the Place you want to travel to : ");
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
        printf("Enter your choice : ");
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
        
        
        printf("\nEnter the Place you want to travel to :  ");
        
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
        printf("Enter your choice : ");
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
        printf("\nEnter the Place you want to travel to :  ");
        scanf("%d",&lineChoose);
        LineChoose_t = lineChoose;
        ConvertLineToString("d1aus.csv",LineChoose_t);
        StoringString();
        PriceCompute(AU);
        
    break;
    
    default:
    {
        printf("Please Enter a Valid Option\n");
        DestinationChoose();
        
    }
        
    
    }
} //Shreyas S
void LinePrint(char *FileName ,  int l)
{
	int count = 1;
	FILE *fp1 = fopen(FileName, "r");
	//fgets(line , 1000 , fp1);
	
	while(fgets(DataStoreLine , 1000 , fp1) != NULL)
	{
		
		if(count == l)
		{
			printf("%s \n",DataStoreLine); /// Printing the Person's Data out 
			count =1;
			break;
		}
		else
		{
			count = count +1;
		}
	}
    fclose(fp1);

}
void IDCheck()
{
     FILE *fp = NULL;
	char *line,*record;
	char buffer[1024];
	if ((fp = fopen( "ids.txt", "r")) != NULL)
	{
		
       
        char temp[100];
        char t[100];
		
        
        //char search[100] = "Sid";
		 while ((line = fgets(buffer, sizeof(buffer), fp))!=NULL)//The loop continues when the end of the file is not read
		{
            
            strcpy(temp,strtok(buffer ," "));
            //printf("%s",temp);
            int a  = atoi(temp);
           // printf("%d",a);
            if(a == IDEnter)
            {
               // printf("reached here");
               // printf("%d",count);
               // printf("%d",tracer);
               printf("We found A record using your Unique ID : \n");
               LinePrint("DataStore.csv",tracer);
               break;
            }
            else
            {
                tracer++;
               // printf("Not");
                
            }

		} 
	    fclose(fp);
		fp = NULL;
        
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
    int yn;
    char Gen;
    
    printf("\t \tHi, Welcome to the Booking System\n");
    printf("1. Book Custom Tickets\n");
    printf("2. Book Package\n");
    printf("3. View Tickets\n");
    printf("4. Cancel Tickets\n");
    printf("5. Exit Program\n");
    printf("6. Manager Portal\n");
    printf("Enter your choice : ");
    scanf("%d",&choice);

    switch (choice)
    {
     case 1:
      {  
        // Asking user input for the
        // new record to be added
        printf("Enter Your Name : ");
        scanf("%s", &CustName);
        //printf("\nEnter Available Amount\n");
        //scanf("%s", &Gender);
        printf("Enter Your Age : ");
        scanf("%d", &Age);
        printf("Enter Your Gender (M/F/O) : ");
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
        printf("\nEnter Your Name : \n");
        scanf("%s", &CustName);
        //printf("\nEnter Available Amount\n");
        //scanf("%s", &Gender);
        printf("\nEnter Your Age :\n");
        scanf("%d", &Age);
        printf("\nEnter Your Gender (M/F/O) : \n");
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
        printf("1. Yes\n");
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
        printf("\n  Enter the Place you want to travel to : ");
        scanf("%d",&lineChoose);
        LineChoose_t = lineChoose;
        ConvertLineToString("Package.csv",LineChoose_t);
        StoringString();
        PriceCompute(24000);
        
        DataPrint();

        break;
      }
      
      case 3:
      {
          
          printf("--------------Welcome to Tourism Specialist--------------- \n");
          printf("Enter your Unique ID at the time of booking your Tickets : ");
          scanf("%d",&IDEnter);
          IDCheck();
          // check if id is in the file of DataStore and print the Details of the 
          break;
      }

      case 4:
      {
          printf("--------------Welcome to Tourism Specialist--------------- \n");
          printf("Enter your Unique ID given at the time of booking your Tickets : ");
          scanf("%d",&IDEnter);
          //printf("%d\n",IDEnter);
          IDCheck();
          
         // DeleteEntry("DataStore.csv",tracer);
         // printf("%d",tracer);
          printf("Are You sure you want to delete the Booking 1.Yes 2.No \n");
          scanf("%d",&yn);
          if(yn == 1)
          {
          DeleteEntry("DataStore.csv",tracer);
          DeleteEntry("ids.txt",tracer);
          }
         // printf("deleted");
          break;
        }

        case 5:
        {
            exit(0);
            break;
        }

        case 6:
        {
            MangerPortal();
            break;
        }
      default :
      {
          printf("Enter a Valid Option\n");
          menu();
          break;
      }
    }

    
   
    
    
   
}//Shreyansh
int main()
    {   
    menu();
    return 0;
    }

// Instructions
// What ever comments u make dont delete existing coments unless they bs 
// try fixing the indentation if not proper
// See if u can find a fix for the warnings
// Make package csv we neeed atleat 30 entries so 10 each , try making your oen with reasonable prices
// we need a discount funct its easy pls make im too bored to make :/
// to make a discount func make generate a random number between 1 to 3 ,1 being 10% and 3 30% , just meke a func with price as the arg to do discount on ;
// ill give 5 rs to the person who makes the function XD
// format for the package csv is mostly the same as the other csv made earlier refer them  , its the package name (all place included keep them max 4)(Delhi->NYC->EUROPE->Africa), price - 