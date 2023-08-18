#include<bits/stdc++.h>
using namespace std;

class account
{
	int acc_no;
	char name[50];
	int deposit;
	long long ph_no;
	char acc_type;
    string new_pass, conf_pass;
public:
	void create_account();
	void show_account() const;
	void modify();
	void dep(int);
	void draw(int);
	void report() const;
	int retacno() const;
	int retdeposit() const;
	char rettype() const;
    string retpass() const; 
};   

void account::create_account()
{
	cout<<"\nEnter The account No. :";
	cin>>acc_no;
	cout<<"\n\nEnter The Name of The account Holder : ";
	// cin.ignore();//clear the input buffer upto one char only
	cin.ignore(numeric_limits<streamsize>::max(), '\n');  //clear maximum no. of char
	cin.getline(name,50);
	cout<<"\nEnter Type of The account (C/S) : ";
	cin>>acc_type;
	acc_type=toupper(acc_type);//change in uppercase
	cout<<"\nEnter your Ph.No. : ";
	cin>>ph_no;
	cout<<"\nEnter The Initial amount(>=500 for Saving and >=1000 for current ) : ";
	cin>>deposit;
    do{
    cout<<"\nEnter your password(min 6 digit): ";
    cin>>new_pass;
    if (new_pass.length()<6)
    {
        cout<<"\nYour password is too short...";
        continue;
    }
    cout<<"\nConfirm your password: ";
    cin>>conf_pass;
    if(new_pass!=conf_pass){
        cout<<"\nPassword not matched...";
        continue;
    }
    else
        break;
    }while(true);
	cout<<"\n\n\nAccount Created..";
}

void account::show_account() const
{
	cout<<"\nAccount No. : "<<acc_no;
	cout<<"\nAccount Holder Name : ";
	cout<<name;
	cout<<"\nType of Account : "<<acc_type;
	cout<<"\nBalance amount : "<<deposit;
	cout<<"\nPhone No.: "<<ph_no;
}


void account::modify()
{
	cout<<"\nAccount No. : "<<acc_no;
	int choose;
	cout<<"\n\n1. Modify Account Holder Name : ";
	cout<<"\n\n2. Modify Type of Account : ";
	cout<<"\n\n3. Modify Ph.No. : ";
	cout<<"\n\nSelect your option (1-3): ";
	cin>>choose;
	switch (choose)
	{
	case 1:
		cout<<"\nEnter Your New Name : ";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin.getline(name,50);
		break;
	case 2:
		cout<<"\nEnter Type of Account(s/c) : ";
		cin>>acc_type;
		acc_type=toupper(acc_type);
		break;
	case 3:
		cout<<"\nEnter New M.No. : ";
		cin>>ph_no;
		break;
	default:
		cout<<"\n\nInvalid Input!";
		break;
	}
}

	
void account::dep(int x)
{
	deposit+=x;
}
	
void account::draw(int x)
{
	deposit-=x;
}
	
void account::report() const
{
	cout<<acc_no<<"\t"<<name<<"\t"<<acc_type<<"\t"<<deposit<<"\t"<<ph_no<<endl;
}

	
int account::retacno() const
{
	return acc_no;
}

int account::retdeposit() const
{
	return deposit;
}

char account::rettype() const
{
	return acc_type;
}
string account::retpass() const{
    return conf_pass;
}

void write_account();
void display_sp(int);
void modify_account(int);
void delete_account(int);
void display_all();	
void deposit_withdraw(int, int); 
void intro();



int main()
{
	char ch;
	int num;
    string pass;
	intro();
	do
	{
		system("clear");//use cls for window
		cout<<"\n\n\n\tMAIN MENU";
		cout<<"\n\n\t01. NEW ACCOUNT";
		cout<<"\n\n\t02. DEPOSIT AMOUNT";
		cout<<"\n\n\t03. WITHDRAW AMOUNT";
		cout<<"\n\n\t04. BALANCE ENQUIRY";
		cout<<"\n\n\t05. ALL ACCOUNT HOLDER LIST";
		cout<<"\n\n\t06. CLOSE AN ACCOUNT";
		cout<<"\n\n\t07. MODIFY AN ACCOUNT";
		cout<<"\n\n\t08. EXIT";
		cout<<"\n\n\tSelect Your Option (1-8) ";
		cin>>ch;
		system("clear");
		switch(ch)
		{
		case '1':
			write_account();
			break;
		case '2':
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
			deposit_withdraw(num, 1);
			break;
		case '3':
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
			deposit_withdraw(num, 2);
			break;
		case '4': 
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
			display_sp(num);
			break;
		case '5':
			display_all();
			break;
		case '6':
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
			delete_account(num);
			break;
		 case '7':
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
			modify_account(num);
			break;
		 case '8':
			cout<<"\n\n\tThanks for using bank managemnt system";
			break;
		 default :cout<<"\n\nEnter a valid input\npress ENTER...";
		}
		cin.ignore();
		cin.get();//It's often used to pause the program and wait for the user to press a key before continuing
	}while(ch!='8');
	return 0;
}


void write_account()
{
	account ac;
	ofstream outFile;
	outFile.open("account.dat",ios::binary|ios::app);
	ac.create_account();
	outFile.write(reinterpret_cast<char *> (&ac), sizeof(account));
	outFile.close();
}

//functions to read record from files
void display_sp(int n)
{
	account ac;
	bool flag=false;
	ifstream inFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
    	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
	{

		if(ac.retacno()==n)
		{
    		string pass;
			flag=true;
            cout<<"\nENTER YOUR PASSWORD: ";
            cin>>pass;
            if(pass==ac.retpass()){
	        cout<<"\nBALANCE DETAILS\n";
			ac.show_account();
            }
            else
                cout<<"\n\nPASSWORD DOES  NOT MATCH";
		}
	}
	inFile.close();
	if(flag==false)
		cout<<"\n\nAccount number does not exist";
}

//function to modify record of file

void modify_account(int n)
{
	bool found=false;
	account ac;
	fstream File;
	File.open("account.dat",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(account));
		if(ac.retacno()==n)
		{
			found=true;
    		string pass;
			cout<<"\nENTER YOUR PASSWORD: ";
            cin>>pass;
            if(pass==ac.retpass()){
			ac.show_account();
			cout<<"\n\nEnter The New Details of account"<<endl;
			ac.modify();
            }
            else{
                cout<<"\n\nPASSWORD DOES  NOT MATCH";
				break;
			}
			int pos=(-1)*static_cast<int>(sizeof(account));
			File.seekp(pos,ios::cur);
			File.write(reinterpret_cast<char *> (&ac), sizeof(account));
			cout<<"\n\n\t Record Updated";
		  }
	}
	File.close();
	if(found==false)
		cout<<"\n\n Record Not Found ";
}


void delete_account(int n)
{
	account ac;
	ifstream inFile;
	ofstream outFile;
	bool recordDeleted=false;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	outFile.open("Temp.dat",ios::binary);
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
	{
		if(ac.retacno()!=n)
		{
			outFile.write(reinterpret_cast<char *> (&ac), sizeof(account));
		}
		else
    	{
        	recordDeleted = true;
    	}
	}
	inFile.close();
	outFile.close();
	if (!recordDeleted)
	{
    	cout << "\n\n\tNo record found for deletion.";
	}
	else
	{
		remove("account.dat");
		rename("Temp.dat","account.dat");
		cout<<"\n\n\tRecord Deleted ..";
	}
}


void display_all()
{
	account ac;
	ifstream inFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	cout<<"\n\n\t\t**ACCOUNT HOLDER LIST**\n\n";
	cout<<"**********************************************************\n";
	cout<<"A/c no.      NAME      Type     Balance      Ph.No.\n";
	cout<<"**********************************************************\n";
	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
	{
		ac.report();
		cout<<endl;
	}
	inFile.close();
}


void deposit_withdraw(int n, int option)
{
	int amt;
    string pass;
	bool found=false;
	account ac;
	fstream File;
	File.open("account.dat", ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(account));
		if(ac.retacno()==n)
		{
			ac.show_account();
			if(option==1)
			{
				cout<<"\n\n\tTO DEPOSITE AMOUNT ";
				cout<<"\n\nEnter The amount to be deposited";
				cin>>amt;
				ac.dep(amt);
			    found=true;
			}
			if(option==2)
			{
			    found=true;
				cout<<"\n\n\tTO WITHDRAW AMOUNT ";
				cout<<"\n\nEnter The amount to be withdraw: ";
				cin>>amt;
                cout<<"\n\nEnter your password: ";
                cin>>pass;
                if(pass==ac.retpass()){
				int bal=ac.retdeposit()-amt;
				if((bal<500 && ac.rettype()=='S') || (bal<1000 && ac.rettype()=='C'))
					cout<<"Insufficience balance";
				else
					ac.draw(amt);
                }
                else{
                    cout<<"INCORRECT PASSWORD: ";
                    break;
                }
			}
			int pos=(-1)*static_cast<int>(sizeof(ac));
			File.seekp(pos,ios::cur);
			File.write(reinterpret_cast<char *> (&ac), sizeof(account));
			cout<<"\n\n\t Record Updated";
	    }
    }
	File.close();
	if(found==false)
		cout<<"\n\n Record Not Found ";
}

void intro()
{
	cout<<"\n\n\n\t WELCOME";
	cout<<"\n\n\t   TO";
	cout<<"\n\n\t  BANK";
	cout<<"\n\n\tMANAGEMENT";
	cout<<"\n\n\t  SYSTEM";
	cout<<"\n\n\n\nMADE BY : NIKHILESH SIROHI";
	cout<<"\n\nCOLLEGE : MADAN MOHAN MALAVIYA UNIVERSITY OF TECHNOLOGY, GORAKHPUR";
	cin.get();
}
	   