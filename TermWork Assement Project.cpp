#include "iostream"
#include "fstream"
using namespace std;

ofstream fout ("Termwork.txt");

class Student
{
private:
    int rno,total;
    string name;
    float overllAtte,attend;
    int mockPractMarks,dsa,mis,iot,se,stat;
    int dsaAtt,iotAtt,seAtt,misAtt,statAtt;
    char certification,grade;

    int dsaTerm,iotTerm,seTerm,misTerm,statTerm,overallTerm;

public:
    void getdata()
    {
        cout<<"\nEnter Roll no: ";
        cin>>rno;
        cout<<"Enter Name: ";
        cin>>name;
        cout<<"Enter DSA Marks outff 30         : ";
        cin>>dsa;
        cout<<"Enter IOT Marks outff 30         : ";
        cin>>iot;
        cout<<"Enter SE Marks outff 30          : ";
        cin>>se;
        cout<<"Enter MIS Marks outff 30         : ";
        cin>>mis;
        cout<<"Enter STAT Marks outff 30        : ";
        cin>>stat;
        cout<<"Enter DSA Attendance outff 40    : ";
        cin>>dsaAtt;
        cout<<"Enter IOT Attendance outff 40    : ";
        cin>>iotAtt;
        cout<<"Enter SE Attendance outff 40     : ";
        cin>>seAtt;
        cout<<"Enter MIS Attendance outff 40    : ";
        cin>>misAtt;
        cout<<"Enter STAT Attendance outff 40   : ";
        cin>>statAtt;
        cout<<"Enter Mock Practicals Marks      : ";
        cin>>mockPractMarks;
        cout<<"Do you have any Certification?  Y or N: ";
        cin>>certification;
    }

    // total=dsa+iot+se+mis+stat;
    // overllAtte=((dsaAtt+iotAtt+seAtt+misAtt+statAtt)/200)*100;

    void putdata()
    {
        cout<<"\n"<<rno<<"\t\t"<<name<<"\t\t\t"<<mockPractMarks<<"\n";
    }

    int Marks(int mark, int att)
    {
        if((mark>=25 && mark<=30) && (att>=35 && att<=40))
        {
            return 50;
        }
        else
        if((mark>=20 && mark<25) && (att>=35 && att<=40))
        {
            return 45;
        }
        else
        if((mark>=10 && mark<20) && (att>=35 && att<=40))
        {
            return 35;
        }
        else
        if((mark>=5 && mark<10) && (att>=35 && att<=40))
        {
            return 25;
        }
        else
        if((mark<5) && (att>=35 && att<=40))
        {
            return 15;
        }
        else
        if((mark>=25 && mark<=30) && (att>=25 && att<35))
        {
            return 45;
        }
        else
        if((mark>=20 && mark<25) && (att>=25 && att<=35))
        {
            return 43;
        }
        else
        if((mark>=10 && mark<20) && (att>=25 && att<=35))
        {
            return 32;
        }
        else
        if((mark>=5 && mark<10) && (att>=25 && att<=35))
        {
            return 20;
        }
        else
        if((mark<5) && (att>=25 && att<=35))
        {
            return 14;
        }
        else
        if((mark>=25 && mark<=30) && (att>=15 && att<25))
        {
            return 42;
        }
        else
        if((mark>=20 && mark<25) && (att>=15 && att<=25))
        {
            return 39;
        }
        else
        if((mark>=10 && mark<20) && (att>=15 && att<=25))
        {
            return 28;
        }
        else
        if((mark>=5 && mark<10) && (att>=15 && att<=25))
        {
           return 15;
        }
        else
        if((mark<5) && (att>=15 && att<=25))
        {
            return 12;
        }
        else
        if((mark>=25 && mark<=30) && (att>=0 && att<15))
        {
            return 39;
        }
        else
        if((mark>=20 && mark<25) && (att>=0 && att<15))
        {
            return 32;
        }
        else
        if((mark>=10 && mark<20) && (att>=0 && att<15))
        {
            return 25;
        }
        else
        if((mark>=5 && mark<10) && (att>=0 && att<15))
        {
            return 14;
        }
        else
        if((mark<5) && (att>=0 && att<15))
        {
            return 12;
        }
        else
        {
            return 0;
        }
    }

    void termWork()
    {
        dsaTerm = Marks(dsa,dsaAtt);
        iotTerm = Marks(iot,iotAtt);
        seTerm = Marks(se,seAtt);
        misTerm = Marks(mis,misAtt);
        statTerm = Marks(stat,statAtt);
        total=dsaTerm+iotTerm+seTerm+misTerm+statTerm;
        attend=(dsaAtt+iotAtt+seAtt+misAtt+statAtt)/200;
        overllAtte=attend*100;

        if(certification=='Y')
        {
            overallTerm=total+50;
        }
        else
        {
            overallTerm=total;
        }

       if(overallTerm>=250 && overallTerm<=300)
       {
           grade='A';
       }
       else
       if(overallTerm>=190 && overallTerm<250)
       {
           grade='B';
       }
       else
       if(overallTerm>=100 && overallTerm<190)
       {
           grade='C';
       }
       else
       {
           grade='D';
       }
    }

    void Display_Termwork()
    {
        cout<<"\n"<<rno<<"\t"<<name<<"\t\t"<<dsaTerm<<"\t\t"<<iotTerm<<"\t\t"<<seTerm<<"\t\t"<<misTerm<<"\t\t"<<statTerm<<"\t\t"<<overllAtte<<"\t\t"<<overallTerm<<"\t\t"<<grade<<"\n";
    }

    void Save_Termwork_In_File()
    {
        fout<<"\n"<<rno<<"\t"<<name<<"\t\t"<<dsaTerm<<"\t\t"<<iotTerm<<"\t\t"<<seTerm<<"\t\t"<<misTerm<<"\t\t"<<statTerm<<"\t\t"<<overllAtte<<"\t\t"<<overallTerm<<"\t\t"<<grade<<"\n";
    }
};

int main()
{
    int rollno;
    cout<<"\n**************WELCOME TO TERMWORK ASSESSMENT*********************\n";

    int noOfStudents;
    cout<<"\nEnter Number of Students in class: ";
    cin>>noOfStudents;

    Student obj[noOfStudents];
    for(int i=0;i<noOfStudents;i++)
    {
        obj[i].getdata();
    }

    fout<<"\n#################################################### TERMWORK #########################################################################\n";
    fout<<"\nROLL\tNAME\tDSA TERMWORK\tIOT TERMWORK\tSE TERMWORK\tMIS TERMWORK\tSTAT TERMWORK\tATTENDANCE %  \tTERMWORK  \tGRADE\n";

    cout<<"\n#################################################### TERMWORK #########################################################################\n";
    cout<<"\nROLL\tNAME\tDSA TERMWORK\tIOT TERMWORK\tSE TERMWORK\tMIS TERMWORK\tSTAT TERMWORK\tATTENDANCE %  \tTERMWORK  \tGRADE\n";
    for(int i=0;i<noOfStudents;i++)
    {
        obj[i].termWork();
        obj[i].Display_Termwork();
        obj[i].Save_Termwork_In_File();
    }
    cout<<"\n#######################################################################################################################################\n";
    fout.close();

    cout<<"\n\n";
    cout<<"         *********************************************************************************************\n";
    cout<<"         *  NOTE:                                                                                    *\n";
    cout<<"         *  1:DSA Termwork, IOT Termwork, SE Termwork, MIS Termwork and STAT Termwork is outoff 50   *\n";
    cout<<"         *  2.If overall Attendance is 100% carry extra 25 Marks in Overall Termwork                 *\n";
    cout<<"         *  3.If certification is available carry extra 25 Marks in Overall Termwork                 *\n";
    cout<<"         *  4.Overall Termwork is outoff 300 Marks.                                                  *\n";
    cout<<"         *********************************************************************************************\n";


}


