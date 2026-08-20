#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
//#include "populate.h"

void listContacts(AddressBook *addressBook) 
{
    // Sort contacts based on the chosen criteria
    
    //int shortCriteria;
    Contact temp;
    for(int i=0;i<addressBook->contactCount-1;i++){
        for(int j=i+1;j<addressBook->contactCount;j++){
            if(strcasecmp(addressBook->contacts[i].name,addressBook->contacts[j].name)>0){
                temp=addressBook->contacts[i];
                addressBook->contacts[i]=addressBook->contacts[j];
                addressBook->contacts[j]= temp;
            }
        }
    }
    for(int i=0;i<addressBook->contactCount;i++){
       printf("Name: %s\t\tphone :%s\t\temail :%s\t\t\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
        
    }
}

void initialize(AddressBook *addressBook) {
    addressBook->contactCount = 0;
    
    // Load contacts from file during initialization (After files)
    //loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}


void createContact(AddressBook *addressBook)
{
	/* Define the logic to create a Contacts */
    //validating name
    char name[50];
    int valid=1;
    do{
        printf("Enter Name:");
        scanf(" %[^\n]",name);
   
        for(int i=0;name[i]!='\0';i++){
            if(name[i]>='A' && name[i]<='Z' || name[i]>='a' && name[i]<='z' || name[i]>='0' && name[i]<='9' || name[i]==' '){
                valid=1;
            }
            else{
                valid=0;
                break;
            }
        }
        if(valid==0){
            printf("Re-enter Name.\n");
        }
    }while(valid==0);
        {
	        int i;
            for( i=0;name[i]!=0;i++){
                addressBook->contacts[addressBook->contactCount].name[i]=name[i];
            }
            addressBook->contacts[addressBook->contactCount].name[i]='\0';
        }


    
    
    //validating phone
    char phone[11];
    
    do{
    printf("Enter phone:");
    scanf(" %[^\n]",phone);
    valid=1; 
    if(phone[0]<'5'){
	    valid=0;
    }
    else{
        for(int i=0;phone[i]!='\0';i++){
        
            if(phone[i]>='0' && phone[i]<='9'){
            
                valid=1;
            }
        
            else{
                valid=0;
                break;
            }
        }
    } 
        if(valid==0){
            printf("Re-enter Phone\n.");
        }
    
   
    }while(valid==0);
    {
    int i;
    	for( i=0;phone[i]!=0;i++){
                addressBook->contacts[addressBook->contactCount].phone[i]=phone[i];
    	}
                addressBook->contacts[addressBook->contactCount].phone[i]='\0';
    }


    //valid email
     char email[40];
     int i;
     do{
	     int length=0;
	     printf("Enter email:");
	     scanf(" %[^\n]",email);
	     if(email[0]>='a' && email[0]<='z')
	        {
		        valid=1;
	         }
	        else{
		        valid=0;
	        }
	        if(email[0] == '@')
            {
                valid = 0;
                
            }

	        for( i=0;email[i]!=0;i++){
		        length++;
                if(email[i]>='A' && email[i]<='Z'){
			        valid=0;
                }
	        }
	        for( i=0;email[i]!=0;i++){
                if(email[i]=='@'){
                    break;;
                }
            }
            if(email[i]=='\0'){
                valid=0;
            }
	        if(length>=4){
		        if(email[length-4]!='.' && email[length-3]!='c' && email[length-2]!='o' && email[length-1]!='m'){
			        valid=0;
		        }
                
            }
	        else{
                valid=0;
            }
	        if(valid==0){
		        printf("Re-enter Phone\n.");
	        }
        }while(valid==0);
        {
		     
		     for( i=0;email[i]!=0;i++){
		     		addressBook->contacts[addressBook->contactCount].email[i]=email[i];
	     	     }
	     			addressBook->contacts[addressBook->contactCount].email[i]='\0';
       	}
     addressBook->contactCount++;
}

   
    

    

    


void searchContact(AddressBook *addressBook) 
{
    /* Define the logic for search */
    char name[50];
    int valid=0;
    printf("Enter a name to search:");
    scanf(" %[^\n]",name);
    for(int i=0;i<addressBook->contactCount;i++){
        if(strstr(addressBook->contacts[i].name,name)!=NULL){
	    printf("Name  : %s\n", addressBook->contacts[i].name);
            printf("Phone : %s\n", addressBook->contacts[i].phone);
            printf("Email : %s\n", addressBook->contacts[i].email);
            
	}
    }
            
}

void editContact(AddressBook *addressBook)
{
	/* Define the logic for Editcontact */
    
}

void deleteContact(AddressBook *addressBook)
{
	/* Define the logic for deletecontact */
    char name[50];
    int valid=0;
    printf("Enter a name to delete:");
    scanf(" %[^\n]",name);
    for(int i=0;i<addressBook->contactCount;i++){
        if(strstr(addressBook->contacts[i].name,name)!=NULL){
	    printf("Name  : %s\n", addressBook->contacts[i].name);
            printf("Phone : %s\n", addressBook->contacts[i].phone);
            printf("Email : %s\n", addressBook->contacts[i].email);
            
	}
    }
   
}
