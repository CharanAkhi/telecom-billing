#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<ctype.h>
#include<windows.h>
#include<stdlib.h>


struct subscriber
{
char phonenumber[20];
char name[50];
float amount;
}s;


char get;


main()
{
	 int n,q;
    system("COLOR 2");
   	
    printf("\n\n\n\t\t #############################################");
	printf("\n\n\n\t\t AKHIL'S TELECOM BILLING MANAGEMENT SYSTEM");
	printf("\n\n\n\t\t #############################################");
      
    getche();
    printf("\n\n\n\t\tPress 1: For Logging into the Portal\n");
    printf("\n\t\tPress 2: For Exiting\n\t\t");
    scanf("%d",&n);
   
   switch(n)
   {
   	 case 1:
   	 	{
   	 	   char name[20],pass[20];
   	 	   char U[20]="ADMIN";
   	 	   char input;
   	 	   
            system("cls");
           system("COLOR 2");
		  
		    printf("\t\t\t\t\t\t\t------------------------------------------------");
		   printf("\n\t\t\t\t\t\t\t| USE THE BELOW INFORMATION FOR LOGIN          |");
		   printf("\n\t\t\t\t\t\t\t| USER NAME: ADMIN");
		   printf("\t PASSWORD:  ADMIN      |");  
		   printf("\n\t\t\t\t\t\t\t------------------------------------------------");
		   
		  
		    
		    printf("\n\tEnter Your USER NAME:");
		   printf("\n\t---------------------\n\t");
		   scanf("%s",&name);
		   printf("\n\tEnter Your PASSWORD:");
		   printf("\n\t--------------------\n\t");
		   scanf("%s",&pass);
		   
		  
		   
		   if((strcmp(name,U)==0)&&(strcmp(pass,U)==0))
		   {
		   	system("cls");
		   	
		   	
		   	printf("\n\tLOGIN SUCCESFUL\n");
		   	
		   	time_t t = time(NULL);
	        struct tm tm = *localtime(&t);
	        system("COLOR F1");
		
		    printf("\n\tDate: %d-%d-%d\t\t\tTime: %d:%d:%d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
	        printf("\t-----\t\t\t\t\t----\n");
		   	
		   	printf("\n\tEnter the Input according to Required Operation");
		    printf("\n\t-----------------------------------------------");
		    printf("\n\n\t 1 : For Adding new Customer details");
		    printf("\n\t 2 : For Viewing all Customer's details");
		    printf("\n\t 3 : For Modifying Customer's details");
		    printf("\n\t 4 : For Payment");
		    printf("\n\t 5 : For Searching Customer's details");
		    printf("\n\t 6 : For Deleting Customer's details");
		    printf("\n\t 7 : For Exit\n\t");
		    
		    input=getche();
		
		   switch(input)
		 {
			
			case '1':
				
				//Add customer details
                {
	              FILE *f;
	              char test;
	              f=fopen("file.txt","a+");
	              if(f==0)
	             {   f=fopen("file.txt","w+");
		          system("cls");
		         printf("please wait while we configure your computer\n");
		         printf("/npress any key to continue");
		         getch();
	             }
	            while(1)
	            {
		        system("cls");
				system("COLOR F5");
				 printf("\n\tDate: %d-%d-%d\t\t\tTime: %d:%d:%d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
	             printf("\t-----\t\t\t\t\t----\n");
				printf("\n\tFill in the Details to Add a new customer:\n");
				printf("\t==========================================\n");
				printf("\n\t Please Enter Customer phone number to add:\t");
				scanf("%s",&s.phonenumber);
				printf("\t------------------------------------------\n");
				printf("\n\t Please Enter Customer Name:\t");
        		fflush(stdin);
				scanf("%s",&s.name);
				printf("\t---------------------------\n");
				printf("\n\t Enter amount:\t");
				scanf("%f",&s.amount);
				printf("\t-------------\n");
				fwrite(&s,sizeof(s),1,f);
				fflush(stdin);
				system("cls");
				printf("\n***\t New Customer  successfully added \t***\n");
				printf("\n\n\t Press esc key to Exit");
				printf("\n\t Any other key to add other record:");
				test=getche();
				if(test==27)
				break;
			    }
			    fclose(f);
			    break;
			}
				
				
			case '2':
				{
					
						FILE *f;
						int i;
						if((f=fopen("file.txt","r"))==NULL)
						exit(0);
						system("cls");
						 printf("\n\tDate: %d-%d-%d\t\t\tTime: %d:%d:%d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
	                     printf("\t-----\t\t\t\t\t----\n");
						system("COLOR F0");
						printf("\n\tDETAILS OF ALL THE CUSTOMERS ARE DISPLAYED BELOW:\n");
						printf("\n\n\tPHONE NUMBER\t\tCUSTOMER NAME\t\t\tAMOUNT\n");
						printf("\t=================================================================================");
	
						while(fread(&s,sizeof(s),1,f)==1)
						{  
						printf("\n\t%-10s\t\t%-20s\t\tRs. %.2f /-",s.phonenumber,s.name,s.amount);
						}
						system("COLOR F0");
						printf("\n\t=================================================================================");
						fclose(f);
						getch();
						break;
				}
				
			    
			case '3':
				
				{
					
							FILE *f;
							char phonenumber[20];
							long int size=sizeof(s);
							if((f=fopen("file.txt","r+"))==NULL)
							exit(0);
							system("cls");
							system("COLOR F2");
							 printf("\n\tDate: %d-%d-%d\t\t\tTime: %d:%d:%d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
	                         printf("\t-----\t\t\t\t\t----\n");
							printf("\n\n\tEnter phone number of the Customer to modify:\n");
							printf("\t===============================================\n\t");
							scanf("%s",phonenumber);
							fflush(stdin);
							while(fread(&s,sizeof(s),1,f)==1)
							{
							if(strcmp(s.phonenumber,phonenumber)==0)
							{
							system("cls");
							printf("\n\n\tEnter the data to be modified\n");
							printf("\t------------------------------\n");
							printf("\n\n\t Enter phone number:");
							scanf("%s",&s.phonenumber);
							printf("\n\t Enter name: ");
							fflush(stdin);
							scanf("%s",&s.name);
							printf("\n\t Enter amount: ");
							scanf("%f",&s.amount);
							printf("\n\n\t***\tCustomer Details Modified Successfully\t***\n");
		    
							fwrite(&s,sizeof(s),1,f);
							break;
							}
							}
							fclose(f);
					}
				
			case '4':
				{
						FILE *f;
						char phonenumber[20];
						long int size=sizeof(s);
						float amt;
						int i;
						if((f=fopen("D:/file.txt","r+"))==NULL)
						exit(0);
						system("cls");
						system("COLOR F1");
						printf("\n\tDate: %d-%d-%d\t\t\tTime: %d:%d:%d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
	                    printf("\t-----\t\t\t\t\t----\n");
						printf("\n\n\tEnter phone number of the Customer for payment\n");
						printf("\t-----------------------------------------------\n\t");
						scanf("%s",phonenumber);
						fflush(stdin);
						while(fread(&s,sizeof(s),1,f)==1)
						{
						if(strcmp(s.phonenumber,phonenumber)==0)
							{
							system("cls");
							printf("\n\n\tPhone No.: %s",s.phonenumber);
							printf("\n\t---------");
							printf("\n\tName: %s",s.name);
							printf("\n\t----");
							printf("\n\tCurrent amount: %f",s.amount);
							printf("\n\t-------------");
			
		    
		 				   printf("\n****************************************************************\n");
							printf("\n\n\tEnter amount of payment:");
							printf("\n\t-------------------------\n\t");
							fflush(stdin);
							scanf(" %f",&amt);
							s.amount=s.amount-amt;
						
						fwrite(&s,sizeof(s),1,f);
						break;
						}
						}
						system("cls");
						printf("\n\t\t ***PAYMENT SUCCESSFUL***\n");
						printf("\n\t ***THANK YOU %s FOR CHOSING OUR SERVICE***",s.name);
						getch();
						fclose(f);
						break;
				}
			
			case '5':
				
				{
					
					FILE *f;
					char phonenumber[20];
					int flag=1;
					f=fopen("file.txt","r+");
					if(f==0)
					exit(0);
					fflush(stdin);
					system("cls");
					system("COLOR F3");
					printf("\n\tDate: %d-%d-%d\t\t\tTime: %d:%d:%d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
	                printf("\t-----\t\t\t\t\t----\n");
					printf("\n\n\tEnter Customer Phone Number to search in our database\n");
					printf("\t-----------------------------------------------------\n\t");
					scanf("%s", phonenumber);
					while(fread(&s,sizeof(s),1,f)==1)
					{
					if(strcmp(s.phonenumber,phonenumber)==0)
					{	system("cls");
					printf("\n\tDate: %d-%d-%d\t\t\tTime: %d:%d:%d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
	                printf("\t-----\t\t\t\t\t----\n");
					printf("\n\n\tCustomer details Found\n ");
					printf("\t========================\n");
					printf("\n\n\tPhone Number: %s\n",s.phonenumber);
					printf("\t-------------\n");
					printf("\tName: %s\n",s.name);
					printf("\t-----\n");
					printf("\tAmount: Rs.%.2f\n",s.amount);
					printf("\t-------\n");
					flag=0;
					break;
					}
					else if(flag==1)
					{	system("cls");
					printf("\n\tDate: %d-%d-%d\t\t\tTime: %d:%d:%d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
	                printf("\t-----\t\t\t\t\t----\n");
					printf("\n\n\n\tRequested Customer details Not found in our database");
					printf("\n\t----------------------------------------------------");
					}
					}
					getch();
					fclose(f);
					break;
				}
			
			case '6':
				
			{
				FILE *f,*t;
				int i=1;
				char phonenumber[20];
				if((t=fopen("temp.txt","w+"))==NULL)
				exit(0);
				if((f=fopen("file.txt","r"))==NULL)
				exit(0);
				system("cls");
				system("COLOR F4");
				printf("\n\tDate: %d-%d-%d\t\t\tTime: %d:%d:%d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
	            printf("\t-----\t\t\t\t\t----\n");
				printf("\n\n\tEnter the phone number to be deleted from the Database:\n");
				printf("\t-------------------------------------------------------\n\t");
				fflush(stdin);
				scanf("%s",phonenumber);
	
				while(fread(&s,sizeof(s),1,f)==1)
				{
					if(strcmp(s.phonenumber,phonenumber)==0)
					{       i=0;
					continue;

				}
				else
				fwrite(&s,sizeof(s),1,t);
				}
				if(i==1)
				{       system("cls");
				
				printf("\n\tDate: %d-%d-%d\t\t\tTime: %d:%d:%d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
	            printf("\t-----\t\t\t\t\t----\n");
				printf("\n\n\tPhone number \"%s\" not found",phonenumber);
				printf("\n\t----------------------------------");
				remove("file.txt");
				rename("temp.txt","file.txt");
				getch();
				fclose(f);
				fclose(t);
				main();
				}
				remove("file.txt");
				rename("temp.txt","file.txt");
				system("cls");
				
				printf("\n\n***\t The Number %s Successfully Deleted\t ***",phonenumber);
				fclose(f);
				fclose(t);
				getch();
				break;
			}
				
			case '7':
				system("cls");
				system("COLOR F2");
				printf("\n\n\t #################################");
				printf("\n\n\t  THANK YOU FOR USING OUR SERVICE");
				printf("\n\t\t HAVE A GREAT DAY! ");
				printf("\n\n\t #################################");
				
				
				exit(0);
				break;
			default:
				system("cls");
				system("COLOR F1");
				printf("Incorrect Input");
				printf("\nAny key to continue");
				getch();
		 }
	      
	                 

		   	
		   	
		   	}
		   	
		   	else{
			      printf("\tRetry Login\n");
			    
				}
		   	break;
		}
		
	 case 2:
	 	{
	 		exit(0);
	 		break;
		 }
   	   
   }
   }	
