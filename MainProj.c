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
int found = 0 ;
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
int DiscountedPrice;
int discountpercentage;
int hours, minutes, seconds, day, month, year;
int Day,Month,Year, MaxDay,t;
// Discount Function for the final Discount on total price.
void DiscountFunc(int totalp)
{
    if(Rooms >=3)
    {
        DiscountedPrice = totalp-(totalp*0.3);
        discountpercentage = 30;
    }
    else if(Rooms ==2)
    {
        DiscountedPrice = totalp-(totalp*0.2);
        discountpercentage = 20;
    }
    else
    {
        DiscountedPrice = totalp-(totalp*0.1);
        discountpercentage = 10;
    }
    
}
// Function to Open a file for the Admin or manager. 
void MangerPortal()  
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
// Delete a Entry/Ticket from our Data File
int DeleteEntry(char *FileName , int delete_line )  
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
// Function to check the OS on which the program is running on.
int CheckOS() 
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
// Function to Open and read the contents of file.
void OpenAndReadFile(char* Filename)
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
				if (j == 35) //Just read the first 35 columns as our csv has only 30 lines mostly 
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
// Function to Print the Contents in a file 
int DataPrint() //3
{
    
   FILE* fp = fopen("DataStore.csv", "a+");
    if (fp == NULL) // Checking if the file exists.
    { 
        // Error in file opening
        printf("Can't open file\n");
        return 1;
    }
    // Saving data in file
    fprintf(fp, "Unique ID : %d, Name : %s, Age : %d , Gender : %s, Place Chosen : %s, Price Per Day: %d, Number Of People : %d, Number Of Days Stay: %d, Rooms Booked : %d, Grand Total : %d Rs , Discounted Grand Price : %d Rs\n", ID,CustName,Age,Gender,PlaceChosen,PricePerDayChosen,NoOfPpl,NoOfDays,Rooms,TotalPrice,DiscountedPrice);
    printf("Ticket Booking Confirmed ! \n");
  
    fclose(fp);
    return 0;    

}
// code block to generate a random 4 digit number to be used as a password
int GenrateRandomUniqueID()
{
    
    FILE *fp = fopen("ids.txt","a+"); // a new text file is created and the numbers generated are stored in that
    int arr[7];
    int lower = 1000, upper = 9999, count = 10;// setting the limits for that no. generated

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

    srand(time(0)); // waits for some system clicks so that the random no generated varies

  //  printf("The random numbers are: ");
    for (int i = 0; i < count1; i++) {
        int x = (rand() % (upper1 - lower1 + 1)) + lower1;
        //printf("%d ", x);
        //printf("%d",arr[x]);s
        ID = arr[x];
        fprintf(fp,"%d\n",arr[x]);// prints the random valuein the file created
        printf("Your Unique ID is %d, Please remember it for future reference\n",ID);
    }
    return 0;
}
// to get a particular element from the csv file
void GetElementsFromString()
{ 
    int i=0;

    array[i] = strtok(Str,","); // sets the delimiter as ',' since the file is in csv format

    while(array[i]!=NULL)
 {
   array[++i] = strtok(NULL,",");  //the next element will be the value/ string required
 }
    strcpy(PlaceChosen,array[1]);
    //printf("%s",array[1]);
    //printf("%s",PlaceChosen);
    PricePerDayChosen = atoi(array[2]); // atoi converts a string to an int type 
    //printf("%d", PricePerDayChosen);
}  
// a sum function to get the total cost taking the price from the file and adding the additional costs based on the formula
void PriceCompute(int TravelCost)
{ // takes the input and computes the cost
    // int a  = 8377;
    printf("Enter the Number Of People : ");
    scanf("%d",&NoOfPpl);
    printf("Enter the number of Days : ");
    scanf("%d",&NoOfDays);
    Rooms = ceil((float)NoOfPpl/4); // casting because ceil converts it to the integer greater than the given number. Comes under math.h
    // printf("%d",PricePerDayChosen);
    TotalPrice = ((TravelCost*NoOfPpl) + (NoOfDays*PricePerDayChosen)*Rooms);
    DiscountFunc(TotalPrice);
    printf("Your Total Booking amount is  : %ld Rs.\n",TotalPrice);
    printf("Congratulations!! You got a Discount of  : %ld %c \n",discountpercentage,'%');
    printf("Your Discounted Total Booking amount is  : %ld Rs.\n",DiscountedPrice);
    GenrateRandomUniqueID(); // calls the random number generator 
    
}
// a sum function to get the total cost taking the price from the file and adding the additional costs based on the formula
void PriceComputePackage()
{ // takes the input and computes the cost
    int a  = 8377;
    printf("Enter the Number Of People : ");
    scanf("%d",&NoOfPpl);
    printf("Enter the number of Days : ");
    scanf("%d",&NoOfDays);
    Rooms = ceil((float)NoOfPpl/4); // casting because ceil converts it to the integer greater than the given number. Comes under math.h
   // printf("%d",PricePerDayChosen);
    TotalPrice = ((PricePerDayChosen*NoOfPpl) + (NoOfDays*PricePerDayChosen)*Rooms);
    DiscountFunc(TotalPrice);
    printf("Your Total Booking amount is  : %ld Rs.\n",TotalPrice);
    printf("Congratulations!! You got a Discount of  : %ld %c \n",discountpercentage,'%');
    printf("Your Discounted Total Booking amount is  : %ld Rs.\n",DiscountedPrice);
    GenrateRandomUniqueID(); // calls the random number generator 
    
}
// link between two functions
void StoringString()
{
    
   // printf("%s",Str);
    GetElementsFromString();

}   
// code block to take input from the user about the destination
int DestinationChoose()//2
{
    int lineChoose ;
    int yesno;
    int choose ; 

    int NA = 90000; //Round trip Cost
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
	// switch case 
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
        printf("\nEnter the Place you want to travel to : ");
        scanf("%d",&lineChoose);
        LineChoose_t = lineChoose; // linechoose is the particular line from the file
        ConvertLineToString("d1na.csv",LineChoose_t);// opens the csv file 
        StoringString();// stores the csv file ie the string from it into the required output
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
            system("start d1asia.xlsx"); // similiar to the previous case opens the excel file
        }
        else if(yesno==2)
        {
            OpenAndReadFile("d1asia.csv"); // displays it in the command prompt
        }
        else
        {
            printf("Enter a Valid Option: \n");
            break;
        }
        printf("\nEnter the Place you want to travel to : ");
        scanf("%d",&lineChoose); // this corresponds to the  line in the file where the info regarding the place is stored
        LineChoose_t = lineChoose;
        ConvertLineToString("d1asia.csv",LineChoose_t);
        StoringString();
        PriceCompute(AS); // computes the price
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
}
// Printing User info out on the the terminal and storing it in DataStoreLine
void LinePrint(char *FileName ,  int l)
{
	int count = 1; // Counter Var for line number
	FILE *fp1 = fopen(FileName, "r");
	//fgets(line , 1000 , fp1);
	
	while(fgets(DataStoreLine , 1000 , fp1) != NULL)
	{
		
		if(count == l) // Checking line Number 
		{
			printf("%s \n",DataStoreLine); /// Printing the Person's Data out 
			count =1;
			break;
		}
		else
		{
			count = count +1; // Incrementing Count
		}
	}
    fclose(fp1);

}
// Checking the ID entered by the user  
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
            
            strcpy(temp,strtok(buffer ," ")); // Getting ID out of the Data 
            //printf("%s",temp);
            int a  = atoi(temp); // converting to integer 
            // printf("%d",a);
            if(a == IDEnter)
            {
               // printf("reached here");
               // printf("%d",count);
               // printf("%d",tracer);
               printf("We found A record using your Unique ID : \n");
               LinePrint("DataStore.csv",tracer);
               found = 0;
               break;
            }
            else
            {
                tracer++;
               // printf("No Data was found for the entered id")
            }
            found = 1;

		} 
        if(found == 1)
        {
            printf("We could not find your Ticket");
        }
	    fclose(fp);
		fp = NULL;
        
	}
}
//Converting the PerLine to Strings 
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
    for(end = loop = 0;loop<line+1;++loop)
    { 
        if(0==fgets(str, sizeof(str), fd))
        {//include '\n'
            end = 1;//can't input (EOF)
            break;
        }
    }
    if(!end)
    {
        strcpy(Str,str);// copying the data
    }
    fclose(fd);
}
//Exit Function 
void Exit()
{
    exit(0);
}
// Menu Function 
void menu() //1 
{   
    int lineChoose ; // line chosen by user 
    int yesno; // Yes No var
    int choice;//choice entered 
    int yn; //Yn Var
    char Gen;//Gender Var
    
    printf("\t \tHi, Welcome to the TOURISM SPECIALIST.\n");
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
        switch (Gen) // Checking Gender 
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
        
        DestinationChoose(); // Calling Functions
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
            system("start Package.xlsx"); // Open Excel Doc
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
        printf("\nEnter the Place you want to travel to : ");
        scanf("%d",&lineChoose);
        LineChoose_t = lineChoose;
        ConvertLineToString("Package.csv",LineChoose_t);
        StoringString();
        PriceComputePackage();
        
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
          if(found ==0)
          {
          printf("Are You sure you want to delete the Booking 1.Yes 2.No \n");
          scanf("%d",&yn);
          if(yn == 1)
          {
          DeleteEntry("DataStore.csv",tracer);
          DeleteEntry("ids.txt",tracer);
          }
          }
          printf("deleted");
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

    
   
    
    
   
}
// Main Function
int main()
    {   
    menu();
    return 0;
    }

