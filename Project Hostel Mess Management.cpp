//jai shree Ganeshji.
#include<iostream>
#include<conio.h>
#include<fstream>

using namespace std;

//***************************************************************
//    	function declaration
//****************************************************************
void WriteCustomerData();		//Function to write customer data
void Hosteller();			    //function to searching details of Hosteller
void TodaysFood(int);			//Function to store food details
void  ListofAll();				//Fucntion to print list of all customer
void HostelList();				//Function to print list of all hostelller
void  Thali(int);				//Function to store details of amount
void intro();					//Introduction
//***************************************************************
//    	class for new hostel student
//****************************************************************
typedef struct Student
{	char name[50];
	int age;
	char gender;
	int room;
	char branch[20];
	int hostelid;
		
}Hostelstud;

//***************************************************************
//    	class for customer
//****************************************************************
class customer
{
	private:
		char name[30];
		char gender;
		char phno[30];
	public:
		void CreateCustomerInfo();
		void DisplayCustomer(customer s);
};

//customer create
void customer::CreateCustomerInfo()
{	
	cout<<"Name: ";
	cin.ignore();
	cin.getline(name,30);
	cout<<"Gender: "; cin>>gender;
	cin.ignore();
	cout<<"Phone no.: "; cin.getline(phno,30);


 } 
 
 //customer display
 void customer::DisplayCustomer(customer s1)
 {
 	cout<<s1.name<<"\t\t|   "<<s1.gender<<"\t|"<<s1.phno;
 	cout<<"\n";
 	
 }



//***************************************************************
//    	function to enter data of hosteller
//****************************************************************
void CreateStudData()
{Hostelstud h;
char ch1='y';
	ofstream hostwrite("HostelStud.txt",ios::binary|ios::out|ios::app);
		while(ch1=='y'||ch1=='Y')
		{ 
			cout<<"\t\t\t\tName: "; 
			cin.ignore();
			cin.getline(h.name,50);
			cout<<"\t\t\t\tGender: ";
			cin>>h.gender;
			cout<<"\t\t\t\tBranch: ";
				cin.ignore();
			cin.getline(h.branch,20);
		
			cout<<"\t\t\t\tRoom No:"; cin>>h.room;
			cout<<"\t\t\t\tage: ";cin>>h.age;
			srand(h.room);
			h.hostelid=rand();
			cout<<"\n\t\t\t\t"<<h.name<<" Your Hostel ID is : "<<h.hostelid;
		 hostwrite.write((char *)&h,sizeof(h));
					
		cout<<"\n\n\t\t\t\tDo you want to enter more record:(Y/N): ";
		cin>>ch1;
		

							
			}
	hostwrite.close();
		
			
}

//***************************************************************
//    	Main Function
//****************************************************************
int main(){
	
	intro();
	system("cls");//clear screen
	
	int choice,count=0;
	char menu;
	char ch1='y';
	customer s;
	
	
	
	do{
		cout<<"\n\n\t\t\t\t\t\t\t\t*****Welcome TO SGSITS Hostel Mess*****\n\n";
		cout<<"\n\t\t\t\t\t\t\t\t\t***MAIN MENU***\n";
		cout<<"\t\t\t\t\t\t\t\t\t________________\n\n";
		cout<<"\t\t\t1. New Customer:\t\t";
		cout<<"\t\t2. Hosteller:";
		cout<<"\t\t\t\t3. Todays food:\n\n";
		cout<<"\t\t\t4. List of all customer:\t";
		cout<<"\t\t5. List of Hostel Students:\t";
		cout<<"\t6. Exit:\n\n\t\t\t";
		cout<<"-------------------------------------------------------------------------------------------------------\n\t\t\t\t\t";
		cin>>choice;
		
		
		
		switch(choice)
		{
			case 1: system("cls");
					WriteCustomerData();
					break;
																											
			case 2: char ans,choice;
					cout<<"\n\t\t\t\tAre you newly joined (Yes/No) ? :  ";
					cin>>ans;
					if(ans=='y'||ans=='Y')	
					{	
					CreateStudData();
					cout<<"\t\t\t\tData of New Student has been inserted.\n";
					}
					else
					{
						Hosteller();
					}
					
					break;
					
			case 3 :system("cls");
					TodaysFood(count);
					break;
					
			case 4 :system("cls");
					cin.ignore();
					cout<<"list is:\n";
					cout<<"Name\t\t\t|Gender\t|Phone\n";
					cout<<"------------------------|-------|---------\n";
					ListofAll();
					break;
					
			case 5: HostelList();
					break;
					
			case 6: cout<<"\n\n\t\t\t\t\t\t\t\t__________";
					cout<<"\n\t\t\t\t\t\t\t\tThank you.\n";
					cout<<"\t\t\t\t\t\t\t\t__________";
					exit(0);
					break;
					
		    defult: cout<<"You Entered Wrong Key!!\n"; 
		}
	cout<<"\n\n\t\t\tDo you want to See MENU:(Y/N): ";
	cin>>menu;
	system("cls");
	}while(menu=='y'||menu=='Y');

return 0;
}

//***************************************************************
//    	function to display Menu of perticular day
//****************************************************************
void TodaysFood(int count)
{
	int day;
	system("cls");
	cout<<"\t\t*****************************************************";
	cout<<"\n\t\tEnter the Day (1 for MONDAY and so on.):";
	cout<<"\n\t\t";
	cin>>day;
	cout<<"\t\t*****************************************************";
	int c;	
	cout<<endl;
	if(day>=1 && day<=7){
	switch(day){
	
		case 1: cout<<"\t\t\t\t\t*Its Monday*\n\n";
				cout<<"\t\t\t\t\tAalu ki Sabji\n\t\t\t\t\tRoti\n\t\t\t\t\tDal Chawal\n\t\t\t\t\tAachar\n\t\t\t\t\tSalad\n";
            break;
        case 2: cout<<"\t\t\t\t\t*Its Tuesday*\n\n";
				cout<<"\t\t\t\t\tKofte ki Sabji\n\t\t\t\t\tRoti\n\t\t\t\t\tDal Chawal\n\t\t\t\t\tAachar\n\t\t\t\t\tSalad\n";
            break;
        case 3: cout<<"\t\t\t\t*Its Wednesday*\n\n";
				cout<<"\t\t\t\t\tSeaonal Sabji\n\t\t\t\t\tRoti\n\t\t\t\t\tDal Chawal\n\t\t\t\t\tAachar\n\t\t\t\t\tSalad\n";
            break;
        case 4: cout<<"\t\t\t\t*Its Thursday*\n\n";
				cout<<"\t\t\t\t\tSev ki Sabji\n\t\t\t\t\tRoti\n\t\t\t\t\tDal Chawal\n\t\t\t\t\tAachar\n\t\t\t\t\tSalad\n";
            break;
        case 5: cout<<"\t\t\t\t*Its Friday*\n\n";
				cout<<"\t\t\t\t\tKadi chawal\n\t\t\t\t\tAachar\n\t\t\t\t\tSalad\n";
            break;
        case 6: cout<<"\t\t\t\t*Its Saturday*\n\n";
				cout<<"\t\t\t\t\tSeasonal Sabji\n\t\t\t\t\tRoti\n\t\t\t\t\tDal Chawal\n\t\t\t\t\tAachar\n\t\t\t\t\tSalad\n";
            break;
        case 7: cout<<"\t\t\t*Its Sunday Special*\n\n";
        		cout<<"\t\t\t\t\tDaal Bati\n\t\t\t\t\tKheer\n\t\t\t\t\tGulab Jamun";
        		cout<<"\n\n\t\t\t\t**WHOOOO Bhaiyya Me Bhaiyya ||YADAV BHAIYYA||\n\n";
            break;
        default: cout<<"Invalid input! Please enter week no. between 1-7.";
    }
	char ans,perform;
	int rupee,sum=0;
	cout<<"\t\t\tDo you want to eat our THAALI(Y/N): ";
	cin>>ans;
	if(ans=='y'|| ans=='Y'){
	 	Thali(count);}
	 	
	 else{
		cout<<"\t\t\tThank you for the visit\n";
		}
	}
	else
		cout<<"\t\t\tEnter valid Input.";
		getch();

}

//***************************************************************
//    	function to enter information of customers
//****************************************************************
void WriteCustomerData()
{	customer s;
	ofstream fout;
	char ch='y';
	int count=0;
	fout.open("mess.txt",ios::out|ios::app);
	cout<<"Enter customer information:\n";
	while(ch=='y'||ch=='Y')
	{ count++;
	s.CreateCustomerInfo();
	cout<<endl;
	fout.write((char *)&s,sizeof(s));
	cout<<"\t\t\t\tDo you want to enter more record:(Y/N): ";
	cin>>ch;
	
	}
	if(ch!='y'||ch!='Y')
		TodaysFood(count);
fout.close();
						
cout<<"\nData of New customer has been created.\n";
system("cls");
}

//***************************************************************
//    	function to display all customers
//****************************************************************
void ListofAll()
{
	customer s1;
	ifstream fin;
	fin.open("mess.txt",ios::in);
	fin.seekg(0);
	while(fin.read((char *)&s1,sizeof(s1)))
	{
		s1.DisplayCustomer(s1);
	}	
	fin.close(); 
	cout<<endl;
}

//***************************************************************
//    	function to display hostel students
//****************************************************************
void HostelList()
{
	Hostelstud h;
	ifstream fin;
	fin.open("HostelStud.txt",ios::in);
	fin.seekg(0);
	cout<<"name\t\tHostelID\t\tBranch\t\tgender\t\troom no\t\tage\n";
	cout<<"---------------------------------------------------------------------------------------------\n";
	while(fin.read((char *)&h,sizeof(h)))
	{
		cout<<h.name<<"\t\t"<<h.hostelid<<"\t\t"<<h.branch<<"\t\t"<<h.gender<<"\t\t"<<h.room<<"\t\t"<<h.age;
		cout<<endl;
	}	
	fin.close(); 
}


//***************************************************************
//    	function to store details of amount
//****************************************************************
void Thali(int count)
{
	char perform;
	int amount;
	int rupee;
	int sum=0;
		amount=count*50;
		
	cout<<"\t\t\tDid you perform entry (Y/N): ";
	cin>>perform;
	int flag=0;
	if(perform=='y'|| perform=='Y')
	{	
		if(amount==0)
		{
			cout<<"\n\t\t\tYou Are Telling Lie\n";
		}
		

		else {
		cout<<"\n\t\t\tNow You Can Have Your Food  *ENJOY*\n";
		getch();
			
		
				cout<<"\n\t\t\tKindly pay Just "<<amount<<" rs.   ";
				cin>>rupee;
			
				if(rupee!=amount){
					cout<<"\t\t\tYou dont pay full amount!!!!\n";
					getch();
				}
				else{
					cout<<"\n\t\t\t$$$ YOU HAVE DONE YOUR PAYMENT $$$\n";
					
				}
					
				
			}}
	
	else{
		WriteCustomerData();
		}

}

//***************************************************************
//    	function to searching details of Hosteller 
//****************************************************************
void Hosteller()
{	int hostid,found=0;
char food;
	Hostelstud host;
	ifstream fin;
	fin.open("HostelStud.txt",ios::in);
	fin.seekg(0);
	cout<<"\n\t\t\t\t-----------------------------------";
	cout<<"\n\t\t\t\tEnter your mess id no :  ";
	cin>>hostid;

	//Searching for the hostellers data
	while(fin.read((char *)&host,sizeof(host)))
	{
		if(host.hostelid==hostid)
		{		cout<<"\n\t\t\t\t-----------------------------------------------------------------------------------------";
			cout<<"\n\t\t\t\tname"<<"\t\tHostelID\tBranch\t\tgender\t\troom no\t\tage\n";
			cout<<"\t\t\t\t---------------------------------------------------------------------------------------------\n";
			cout<<"\t\t\t\t"<<host.name<<"\t"<<host.hostelid<<"\t\t"<<host.branch<<"\t\t"<<host.gender<<"\t\t"<<host.room<<"\t\t"<<host.age;
			cout<<endl;
			found=1;
			
			cout<<"\n\t\t\t\tdo you want to eat food ? (y/n) :";
			cin>>food;
			
			if(food=='y' || food=='Y')
			{	cout<<"\n\n\t\t\t\t\t\t----------------------------------";
				cout<<"\n\t\t\t\t\t\t|*|*|You can have your food|*|*| \n";
			}
			else
			{	
				cout<<"\n\t\t\t\t|Ok Then!|:)\n";
			}
		}
		
	}	
	fin.close(); 
	if(found==0)
	{
		cout<<"\t\t\t\tData Not Found!!!\n";
	}
}

//***************************************************************
//    	INTRODUCTION FUNCTION
//****************************************************************


void intro()
{
	cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t***********************************************************\n";
	cout<<"\t\t\t\t\t\t_________________________________";
	cout<<"\n\t\t\t\t\t\t||Hostel Mess Management System|| ";
	cout<<"\t\t\t\t\t\t\t\t_________________________________";
	cout<<"\n\n\t\t\t\t\t\t___________";
	cout<<"\n\t\t\t\t\t\t(using C++)";
	cout<<"\t\t\t\t\t\t\t\t\t\t\t___________";
	cout<<"\n\n\n\t\t\t\t\t\t_____________________________";
	cout<<"\n\t\t\t\t\t\t|| MADE BY : SHUBHAM NIKUM ||";
	cout<<"\t\t\t\t\t\t\t\t\t_____________________________\n";
	cout<<"\n\t\t\t******************************************************";
	cin.get();
}



