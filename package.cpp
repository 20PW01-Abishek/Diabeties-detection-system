
                                                /*DIABETES LEVEL DETECTION SYSTEM
                                                   OBJECT COMPUTING LAB PACKAGE
                                            Done by 20pw01-Abishek and 20pw30-SaiDinesh*/

//Including necessary header files
#include<iostream>
#include<conio.h>
#include<graphics.h>
#include<windows.h>
#include<stdlib.h>
#include<fstream>
#include<string>
#include<ctime>
#include<time.h>
using namespace std;

//To set console cursor position
COORD coord={0,0};
void gotoxy(int x,int y)
{
  	coord.X=x;
 	coord.Y=y;
 	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

//creating diabetes base class
class diabetes
{
    private:
        fstream fp;
        string id,name;
        float age;
        int wt;
        float ht;
        char sex, s[];
    public:
        void welcome_screen();
        void menu();
        void getvalue();
        void showvalue();
        void getlevel1_symptoms();
        void getlevel2_symptoms();
        void getlevel3_symptoms();
        void medicine_level();
        void medicine_level1();
        void medicine_level2();
        void medicine_level3();
        int analyse_symptoms(int);
        char display_message(int,int);
};

//welcome screen
void diabetes::welcome_screen()
{
    system("CLS");
    gotoxy(45,6);
    system("color 5F");
    _cputs("W E L C O M E");
    gotoxy(25,9);
    _cputs("D I A B E T E S   D I A G N O S I S   S O F T W A R E");
    gotoxy(25,13);-
    _cputs("D O N E  B Y  : ");
    gotoxy(35,15);
    _cputs("A B I S H E K    A N D    S A I D I N E S H");
    gotoxy(25,20);
    _cputs("* P R E S S   A N Y   K E Y   T O   C O N T I N U E *");
    _getch();
}

//menu page of the application
void diabetes::menu()
{
    char chars;
    string fnam;
    int a;
    L1:system("CLS");
    system("color 5F");
    gotoxy(45,12);
    _cputs("1. NEW PATIENT REGISTRATION");
    gotoxy(45,14);
    _cputs("2. VIEW PATIENT RECORD ");
    gotoxy(45,16);
    cout << "Enter your input here: ";
    cin >> a;
    switch(a)
    {
        case 1:
            getvalue();
            showvalue();
            break;
        case 2:
            system("CLS");
            system("color 5F");
            cout << "ENTER PATIENT ID: ";
            fflush(stdin);
            getline(cin,fnam);
            fflush(stdin);
            //exception handling
            try
            {
                //exception occurs here
                fp.open(fnam+".txt");
                if(!fp)
                {
                    throw fnam;
                }
                fp.get(chars);
                while(!fp.eof())
                {
                    cout << chars;
                    fp.get(chars);
                }
                fp.close();
            }
            catch(string fnam)
            {
                //rectifies the exception
                cout << "\n\tException: PATIENT FILE DOES NOT EXIST" << endl;
                _getch();
            }
            cout << "\n\t***E N T E R  (1)  T O   C O N T I N U E   A N Y   T O   E X I T***" << endl;
            int b;
            cin >> b;
            if(b==1)
            {
                goto L1;
            }
            else
            {
                exit(0);
            }
            break;
        default:
            system("CLS");
            gotoxy(45,13);
            cout << "*I N V A L I D   E N T R Y*\n\n\n\n\n\n\n\n\n\n" ;
            exit(0);
    }
}

//gets personal info and saving it in the patients file
void diabetes::getvalue()
{

    time_t tmNow;
    tmNow = time(0);
    struct tm t = *localtime(&tmNow);
    string time,date;
    time=to_string(t.tm_hour)+":"+to_string(t.tm_min)+":"+to_string(t.tm_sec);
    date=to_string(t.tm_mday)+"."+to_string(t.tm_mon+1)+"."+to_string(t.tm_year+1900);

    int a;
    system("CLS");
    system("color 5F");
    gotoxy(30,4);
    cout<<"P E R S O N A L   I N F O R M A T I O N";
    gotoxy(25,8);
    cout<<"P A T I E N T  I D    :";
    gotoxy(25,10);
    cout<<"N A M E               :";
    gotoxy(25,12);
    cout<<"A G E                 :";
    gotoxy(25,14);
    cout<<"W E I G H T           :";
    gotoxy(25,16);
    cout<<"H E I G H T           :";
    gotoxy(25,18);
    cout<<"S E X (M /F)          :";

    gotoxy(50,8);
    fflush(stdin);
    getline(cin,id);
    fflush(stdin);
    fp.open(id+".txt",ios::app);

    fp<<"TIME: "<<time<<endl;
    fp<<"DATE: "<<date<<endl;
    fp << "P A T I E N T  I D\t: " << id << endl;
    gotoxy(50,10);
    fflush(stdin);
    getline(cin,name);
    fflush(stdin);
    fp << "N A M E\t\t\t: " << name << endl;
    gotoxy(50,12);
    cin>>age;
    fp << "A G E\t\t\t: " << age << endl;
    gotoxy(50,14);
    cin>>wt;
    fp << "W E I G H T\t\t: " << wt << endl;
    gotoxy(50,16);
    cin>>ht;
    fp << "H E I G H T\t\t: " << ht << endl;
    gotoxy(50,18);
    cin>>sex;
    fp << "S E X\t\t\t: " << sex << endl << endl;
    fp.close();

}

//displays personal info
void diabetes::showvalue()
{
    system("CLS");
    system("color 5F");
    cout<< "\n\n\n\t\t\tP E R S O N A L   I N F O R M A T I O N\n\n" << endl;
    cout<< "\t\tP A T I E N T  I D :" << id   << endl;
    cout<< "\t\tN A M E            :" << name << endl;
    cout<< "\t\tA G E              :" << age  << endl;
    cout<< "\t\tH E I G H T        :" << ht   << endl;
    cout<< "\t\tW E I G H T        :" << wt   << endl;
    cout<< "\t\tS E X              :" << sex  << endl;
    cout<< "\n\t\tContents saved successfully...click any to continue!" << endl;
    _getch();
}

//Enters the diagnosis
void diagnosis()
{
     system("CLS");
     system("color 5F");
     gotoxy(0,5);
     _cputs("\t\t\t* D I A G N O S I S   W I N D O W *");
     cout<<"\n\n\n";
     _cputs("\t\t\tLet's have a look at  symptoms.........");
     std::cout<<"\n\n\n";
     _cputs("\t\t\tPlease enter the form in next page .");
     std::cout<<"\n\n\n";
     _cputs("\t\t\t** PRESS ANY KEY ** ");
     _getch();
}

//getting reports to check level 1 diabetes and saving it in the patients file
void diabetes::getlevel1_symptoms()
{
    system ("CLS");
    int i=0;
    gotoxy(23,3);
    _cputs( " * MEDICAL DIAGONOSIS FORM * ");
    fp.open(id+".txt",ios::app);

    gotoxy(3,6);
    _cputs("APPETITE (H(HIGH),/L(LOW),/N(NORMAL):") ;
    gotoxy(64,6);
    cin>>s[i];
    s[i]=toupper(s[i]);
    fp << "APPETITE\t\t\t:" << s[i] << endl;
    ++i;

    gotoxy(3,8);
    _cputs("FREQUENCY OF THIRST(H(HIGH),/L(LOW)/N(NORMAL):");
    gotoxy(64,8);
    cin>>s[i];
    s[i]=toupper(s[i]);
    fp << "FREQUENCY OF THIRST\t\t:" << s[i] << endl;
    ++i;

    gotoxy(3,10);
    _cputs("FREQUENCY OF URINATION(H(HIGH),/L(LOW),/N(NORMAL):");
    gotoxy(64,10);
    cin>>s[i];
    s[i]=toupper(s[i]);
    fp << "FREQUENCY OF URINATION\t\t:" << s[i] << endl;
    ++i;

    gotoxy(3,12);
    _cputs("VISION (I(IMPAIRMENT),/N(NORMAL):");
    gotoxy(64,12);
    cin>>s[i];
    s[i]=toupper(s[i]);
    fp << "VISION\t\t\t\t:" << s[i] << endl;
    ++i;

    gotoxy(3,14);
    _cputs("URINE SUGAR(P(PASSIVE)/A(ACTIVE):");
    gotoxy(64,14);
    cin>>s[i];
    s[i]=toupper(s[i]);
    fp << "URINE SUGAR\t\t\t:" << s[i] << endl;
    ++i;

    gotoxy(3,16);
    _cputs("KETONUREA(P(PASSIVE)/A(ACTIVE):");
    gotoxy(64,16);
    cin>>s[i];
    s[i]=toupper(s[i]);
    fp << "KETONUREA\t\t\t:" << s[i] << endl;
    ++i;

    gotoxy(3,18);
    _cputs("FASTING BLOOD SUGAR(H(HIGH)/L(LOW)/N(NOMAL):");
    gotoxy(64,18);
    cin>>s[i];
    s[i]=toupper(s[i]);
    fp << "FASTING BLOOD SUGAR\t\t:" << s[i] << endl;
    ++i;

    gotoxy(3,20);
    _cputs("R B S (H(HIGH)/L(LOW)/N(NORMAL):");
    gotoxy(64,20);
    cin>>s[i];
    s[i]=toupper(s[i]);
    fp << "R B S\t\t\t\t:" << s[i] << endl;
    ++i;

    gotoxy(3,22);
    _cputs("FAMILY HISTORY OF DIABETES(P(PASSIVE)/A(ACTIVE):");
    gotoxy(64,22);
    cin>>s[i];
    s[i]=toupper(s[i]);
    fp << "FAMILY HISTORY OF DIABETES\t:" << s[i] << endl;
    ++i;

    gotoxy(3,24);
    _cputs("OGTT(D/N):");
    gotoxy(64,24);
    cin>>s[i];
    s[i]=toupper(s[i]);
    fp << "OGTT\t\t\t\t:" << s[i] << endl << endl;
    ++i;

    fp.close();
    cout << "\nInfo saved..." << endl;
    _getch();
}


//getting reports to check level 2 diabetes and saving it in the patients file
void diabetes::getlevel2_symptoms()
{
    system("CLS");
    system("color 5F");
    int j=0;
    fp.open(id+".txt",ios::app);

    gotoxy(20,8);
    _cputs("PANCREATITIS(P/A)\t\t\t:");
    gotoxy(60,8);
    cin>>s[j];
    s[j]=toupper(s[j]);
    fp << "PANCREATITIS\t\t\t:" << s[j] << endl;
    j++;

    gotoxy(20,10);
    _cputs("CAROMA(P/A)\t\t\t\t:");
    gotoxy(60,10);
    cin>>s[j];
    s[j]=toupper(s[j]);
    fp << "CAROMA\t\t\t\t:" << s[j] << endl;
    ++j;

    gotoxy(20,12);
    _cputs("CIRHHOSIS(P/A)\t\t\t:");
    gotoxy(60,12);
    cin>>s[j];
    s[j]=toupper(s[j]);
    fp << "CIRHHOSIS\t\t\t:" << s[j] << endl;
    ++j;

    gotoxy(20,14);
    _cputs("HCTS (H/L/N)\t\t\t:");
    gotoxy(60,14);
    cin>>s[j];
    s[j]=toupper(s[j]);
    fp << "HCTS\t\t\t\t:" << s[j] << endl;
    ++j;

    gotoxy(20,16);
    _cputs("HEPATITIS(P/A)\t\t\t:");
    gotoxy(60,16);
    cin>>s[j];
    s[j]=toupper(s[j]);
    fp << "HEPATITIS\t\t\t:" << s[j] << endl;
    ++j;

    gotoxy(20,18);
    _cputs("HORMONAL DISORDER(P/A)\t\t:");
    gotoxy(60,18);
    cin>>s[j];
    s[j]=toupper(s[j]);
    fp << "HORMONAL DISORDER\t\t:" << s[j] << endl;
    ++j;

    gotoxy(20,20);
    _cputs("PANCREATECTOMY(P/A)\t\t\t:");
    gotoxy(60,20);
    std::cin>>s[j];
    s[j]=toupper(s[j]);
    fp << "PANCREATECTOMY\t\t\t:" << s[j] << endl << endl;
    ++j;

    fp.close();
    cout << "\nInfo saved..." << endl;
    _getch();
}

//getting reports to check level 3 diabetes and saving it in the patients file
void diabetes::getlevel3_symptoms()
{
    int k=0;
    system("CLS");
    fp.open(id+".txt",ios::app);
    system("color E2");

    gotoxy(10,8);
    _cputs("AGE [ Young (Y) / Middle aged (M) / Elderly (E) ]:");
    gotoxy(73,8);
    cin >> s[k];
    s[k]= toupper (s[k]);
    fp << "AGE\t\t\t\t\t:" << s[k] << endl;
    ++k;

    gotoxy(10,12);
    _cputs("BODY WEIGHT(normal(N)/Above normal(A)/Below normal(B)/obese):");
    gotoxy(73,12);
    cin >> s[k];
    s[k]= toupper(s[k]);
    fp << "BODY WEIGHT\t\t\t\t:" << s[k] << endl;
    ++k;

    gotoxy(10,16);
    _cputs("DURATION (weeks(W)/Months(M)/Years(Y))");
    gotoxy(73,16);
    cin >> s[k];
    s[k]= toupper(s[k]);
    fp << "DURATION\t\t\t\t:" << s[k] << endl;
    ++k;

    gotoxy(10,20);
    _cputs("KETONUREA(P/A)");
    gotoxy(73,20);
    cin >> s[k];
    s[k]= toupper(s[k]);
    fp << "KETONUREA\t\t\t\t:" << s[k] << endl;
    ++k;

    gotoxy(10,24);
    _cputs("AUTO ANTIBODIES(P/A)");
    gotoxy(73,24);
    cin >> s[k];
    s[k]= toupper(s[k]);
    fp << "AUTO ANTIBODIES\t\t\t:" << s[k] << endl;
    ++k;

    fp.close();
    cout << "\nInfo saved..." << endl;
    _getch();
}

//Basic medicine or diet
void diabetes::medicine_level()
{
    system("CLS");
    gotoxy(30,15);
    cout<<"NOTHING TO WORRY "<<endl;
    gotoxy(30,17);
    cout<<"MAINTAIN A PROPER DIET "<<endl;
    gotoxy(30,19);
    cout<<"LIMIT THE FOOD OF CARBOHYDRATES CONTENT "<<endl;
}

//Intakes for level 1 diabetes
void diabetes::medicine_level1()
{
    system("CLS");
    gotoxy(20,6);
    cout<<"Manage your carb intake "<<endl;
    gotoxy(20,7);
    cout<<"Increase your fiber intake "<<endl;
    gotoxy(20,8);
    cout<<"Drink water and stay hydrated "<<endl;
    gotoxy(20,9);
    cout<<"Implement portion control "<<endl;
    gotoxy(20,10);
    cout<<"Choose foods with a low glycemic index "<<endl;
    gotoxy(20,11);
    cout<<"Manage stress levels "<<endl;
    gotoxy(20,12);
    cout<<"Monitor your blood sugar levels "<<endl;
    gotoxy(20,13);
    cout<<"Excercise regularly "<<endl;
    gotoxy(20,14);
    cout<<"Get enough quality sleep "<<endl;
    gotoxy(20,15);
    cout<<"Eat fenugreek seeds "<<endl;

}

//medicines for level 2 diabetes
void diabetes::medicine_level2()
{
    system("cls");
    gotoxy(20,4);
    cout<<"PLEASE TAKE THE FOLLOWING MEDICATIONS "<<endl;
    gotoxy(20,6);
    cout<<"1.Humulin R and Novolin R ";
    gotoxy(20,7);
    cout<<"2.insulin glulisine and insulin lispro "<<endl;
    gotoxy(20,8);
    cout<<"3.Aspirin "<<endl;
    gotoxy(20,9);
    cout<<"4.Lipo protein drugs "<<endl;
}

//medicines for level 3 diabetes
void diabetes::medicine_level3()
{
    system("cls");
    gotoxy(20,4);
    cout<<"PLEASE TAKE THE FOLLOWING MEDICATIONS ";
    gotoxy(20,6);
    cout<<"1.METAFORMIN "<<endl;
    gotoxy(20,7);
    cout<<"2.Sulfonylureas "<<endl;
    gotoxy(20,8);
    cout<<"3.Glinides "<<endl;
    gotoxy(20,9);
    cout<<"Thiazolidinediones "<<endl;
    gotoxy(20,10);
    cout<<"4. sitagliptin "<<endl;
}

//ANALYSING THE SYMPTOMS FOR DIABETES
int diabetes::analyse_symptoms(int n)
{
    int i=0, count=0, result=0;
    switch(n)
    {
        case 1:
            if(s[9]=='D')
                result=-1;
            else
                if(s[5]=='P'&& s[6]=='P' && s[7]=='H')
                    result=-1;
                else
                {
                    for(i=0;i<10;i++)
                    {
                        if(s[i]=='H'||s[i]=='P'||s[i]=='D'||s[i]=='I')
                        count++;
                    }
                    if(count>5)
                        result=-1;
                }
            break;

        case 2:
            if((s[0]=='P')||(s[1]=='P')||(s[2]=='P')||(s[3]=='H')||(s[4]=='P')||(s[5]=='P')||(s[6]=='P'))
                result=-1;
		    else
                result=0;
            break;

        case 3:
            if((s[0]=='Y')&&(s[1]=='N')&&(s[2]=='W')&&(s[3]=='P')&&(s[4]=='P')||(s[0]=='Y')&&(s[1]=='B')&&(s[2]=='W')&&(s[3]=='P')&&(s[4]=='P')||(s[0]=='Y')&&(s[1]=='N')&&(s[2]=='M')&&(s[3]=='P')&&(s[4]=='P')||(s[0]=='Y')&&(s[1]=='N')&&(s[2]=='Y')&&(s[3]=='P')&&(s[4]=='P'))
                result=0;
		    else
                result=-1;
            break;

        default: break;
	}
    return(result);
}

//Displaying the result of diagnosis and save the result in a file
char diabetes::display_message(int n,int m)
{
    char ch;
    system("cls");
    switch(n)
    {
        case 1:
        switch(m);
        {
            case 0:
                system("color 5F");
                gotoxy(40,12);
                fp.open(id+".txt",ios::app);
			    _cputs("THE PERSON IS NOT DIABETIC");
			    _getch();
		        fp << "*THE PERSON IS NOT DIABETIC*" << endl << endl;
		        fp.close();
		        gotoxy(35,20);
		        _cputs("PRESS ANY KEY TO QUIT" );
			    exit(0);
            case -1:
                system("color 5F");
                gotoxy(40,15);
                fp.open(id+".txt",ios::app);
			    _cputs("## THE PERSON IS DIABETIC ##");
			    gotoxy(40,17);
			    _cputs("Enter any key to view medicines ");
			    _getch();
			    medicine_level();
			    _getch();
		        fp << "*THE PERSON IS DIABETIC*" << endl << endl;
		        fp.close();
		        system("cls");
		        gotoxy(40,25);
		        _cputs("PROCEED FURTHER (Y/N): ");
                cin >> ch;
			    break;
        }
        break;

        case 2:
        switch(m)
        {
            case 0:
                gotoxy(40,12);
                fp.open(id+".txt",ios::app);
				_cputs("IT IS PRIMARY DIABETES");
				gotoxy(40,14);
				_cputs("Enter any key to view medicines ");
				_getch();
				medicine_level1();
				_getch();
				fp << "*IT IS PRIMARY DIABETES*" << endl << endl;
				fp.close();
				system("cls");
			    gotoxy(40,20);
			    _cputs("Proceed further? (Y/N): ");
			    cin>>ch;
                break;

            case -1:
                gotoxy(40,12);
				fp.open(id+".txt",ios::app);
				_cputs("IT IS SECONDARY DIABETES");
				gotoxy(40,14);
				_cputs("Enter any key to view medicines ");
				_getch();
				medicine_level2();
				_getch();
				gotoxy(37,25);
				fp << "*IT IS SECONDARY DIABETES*" << endl << endl;
				fp.close();
				_cputs("\t*PRESS ANY KEY TO QUIT*");
				_getch();
				break;
        }
        break;

		case 3:switch(m)
        {
            case 0:
                gotoxy(30,12);
                fp.open(id+".txt",ios::app);
				_cputs("IT IS INSULIN DEPENDENT DIABETES");
				gotoxy(30,14);
				_cputs("Enter any key to view medicines ");
				_getch();
				medicine_level3();
				_getch();
				fp << "IT IS INSULIN DEPENDENT DIABETES" << endl << endl;
				fp.close();
				gotoxy(50,25);
				_cputs("PRESS ANY KEY TO QUIT");
				_getch();
				break;

            case -1:
                gotoxy(30,12);
                fp.open(id+".txt",ios::app);
                _cputs("IT IS NON INSULIN DEPENDENT DIABETES");
                fp << "IT IS NON INSULIN DEPENDENT DIABETES" << endl << endl;
			    fp.close();
			    gotoxy(50,25);
		        _cputs("PRESS ANY KEY TO QUIT");
		        _getch();
		        break;
        }
    }
    return (ch);
}

//main function
int main()
{
    time_t tmNow;
    tmNow = time(0);
    struct tm t = *localtime(&tmNow);
    string time,date;
    time=to_string(t.tm_hour)+":"+to_string(t.tm_min)+":"+to_string(t.tm_sec);
    date=to_string(t.tm_mday)+"."+to_string(t.tm_mon+1)+"."+to_string(t.tm_year+1900);

    diabetes dts;
    fstream file;
    string username="vernier",password="calipher123@",u,p;
    char ch,choice,cho;
    float m;
    int n=1,a,att=0;
    bool l;
    dts.welcome_screen();

    //GETTING LOGIN CREDENTIALS
    l1:system("cls");
    system("color 5F");
    for(int z=5;z<9;z++)
    {
        gotoxy(40,z);
        cout<<"*";
        gotoxy(57,z);
        cout<<"*";
    }
    gotoxy(40,5);
    cout<<"*****************"<<endl;
    gotoxy(43,7);
    cout<<"ADMIN LOGIN "<<endl;
    gotoxy(40,9);
    cout<<"******************"<<endl;
    gotoxy(35,14);
    fflush(stdin);
    cout<<"ENTER USERNAME: ";
    gotoxy(53,14);
    getline(cin,u);
    fflush(stdin);
    gotoxy(35,16);
    cout<<"ENTER PASSWORD: ";
    gotoxy(53,16);
    getline(cin,p);
    fflush(stdin);

    //CHECKING LOGIN CREDENTIALS
    if(u==username && p==password && att<5)
    {
        system("CLS");
        gotoxy(35,14);
        cout<<"LOGIN SUCCESS ........";
        gotoxy(35,16);
        cout<<"Press enter to continue";
        _getch();

        //ENTERING THE DIAGNOSIS
        dts.menu();
        diagnosis();
        dts.getlevel1_symptoms();
        m=dts.analyse_symptoms(n);
        choice=dts.display_message(m,n);
        choice=toupper(choice);
        if(choice=='Y')
        {
            ++n;
            dts.getlevel2_symptoms();
            m=dts.analyse_symptoms(n);
            choice=dts.display_message(n,m);
            choice=toupper(choice);
            if(choice=='Y')
            {
                ++n;
                dts.getlevel3_symptoms();
                m=dts.analyse_symptoms(n);
                cho=dts.display_message(n,m);
                cho=toupper(cho);
                if(cho=='Y')
                {
                    ++n;
                    dts.getlevel3_symptoms();
                    m=dts.analyse_symptoms(n);
                    choice=dts.display_message(m,n);
                }
            }
        }
    }
    //IF LOGIN CREDENTIALS ARE NOT SATISFIED
    else if((u!=username || p!=password) && att<5)
    {
        //LOGIN ATTEMPTS ARE STORED IN A LOGIN FILE WITH DATE AND TIME
        file.open("login.txt",ios::app);
        file<<"Username: "<<u<<endl;
        file<<"Password: "<<p<<endl;
        file<<"Login time: "<<time<<endl;
        file<<"Login date: "<<date<<endl<<endl;
        system("CLS");
        att++;

        //PROMPTS USER TO ENTER CORRECT CREDENTIALS FOR 5 TIMES
        gotoxy(47,12);
        cout<<"WRONG CREDENTIALS";
        gotoxy(45,14);
        cout<<"Remaining attempts ("<<5-att<<")";
        gotoxy(45,16);
        cout<<"Press any to try again";
        _getch();
        goto l1;
    }
    //IF EXCEEDS 5 ATTEMPTS
    else if(att==5)
    {
        system("CLS");
        gotoxy(47,14);
        cout<<"TOO MANY ATTEMPTS";
        gotoxy(45,16);
        cout<<"Open the application again...";
        gotoxy(10,25);
    }
    return 0;
}
