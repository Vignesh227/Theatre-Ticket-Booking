#include<iostream>
#include<iomanip>
#include<ctime>

using namespace std;
class theatre
{
    private:
        int a[102], b[52], seats, tot[4], i, j, x,totalamt;
        int rem1=20, rem2=80, rem3=50, m=0, n=20, p=0, showchoice,sh=0;
        time_t now = time(0);
        tm *clock = localtime(&now);
    public:
        theatre()   //Constructor
        {
            cout<<"\n\t``````VVV THEATRE TICKET BOOKING";
            MovieInfo();
            cout<<"\n\t SEATS AVAILABILITY";
            cout<<"\n Ground Floor Seats(1st and 2nd row)  availability - 20 ";
            cout<<"\n Ground Floor Seats(remaining 8 rows) availability - 80 ";
            cout<<"\n First Floor seats availability - 50";
            cout<<"\n\n 1-> Book Ground Floor Seats(First two rows)";
            cout<<"\n 2-> Book Ground Floor Seats ";
            cout<<"\n 3-> Book Tickets on First Floor";
            cout<<"\n 4-> Checkout";
            tot[1]=tot[2]=tot[3]=0;
        }
        void MovieInfo()
        {
            cout<<"\n MOVIE NAME : SHANG-CHI And The Legend Of The Ten Rings";
            cout<<"\n SHOW DATE : "<<1+clock->tm_mday<<"/"<<1+clock->tm_mon<<"/"<<1900+clock->tm_year;
            cout<<"\n SHOW TIMINGS : \n 1-> 09:00AM to 12:00PM\n 2-> 01:00PM to 04:00PM\n 3-> 06:00PM to 09:00PM";
            do{
                if(sh==1)
                {
                    cout<<"\n ** Please Enter A Valid Input For Show Choices **";
                }
                cout<<"\n Enter Your Choice(for Show Timing) : ";
                cin>>showchoice;
                sh=1;
            }while((showchoice!=1)&&(showchoice!=2)&&(showchoice!=3));
        }
        void GroundFloor1()
        {
            cout<<"\n Enter the number of seats to be booked : ";
            cin>>seats;
            if(seats<=0)
            {
                cout<<"\n ** Please Enter A Valid Choice **";
            }
            else if(seats>rem1)
            {
                cout<<"\n There are only "<<rem1<<" seats available ";
                cout<<"in the first two rows\n";
            }
            else
            {
                rem1 -= seats;
                cout<<"\n Your seat numbers(1st and 2nd row) are : ";
                for(i=m+1,j=1;j<=seats;j++,i++)
                {
                    a[i]=1;
                    cout<<" G"<<i;
                    if(j!=seats)
                    {
                        cout<<", ";
                    }
                    m=i;
                }
                cout<<"\n";
                tot[1] = seats * 20;
            }
        }
        void GroundFloor()
        {
            cout<<"\n Enter the number of seats to be booked : ";
            cin>>seats;
            if(seats<=0)
            {
                cout<<"\n ** Please Enter A Valid Choice **";
            }
            else if(seats>rem2)
            {
                cout<<"\n There are only "<<rem2<<" seats available ";
                cout<<"in the ground floor\n";
            }
            else
            {
                rem2 -= seats;
                cout<<"\n Your seat numbers(GroundFloor) are : ";
                for(j=n+1,i=1;i<=seats;j++,i++)
                {
                    a[j]=1;
                    cout<<" G"<<j;
                    if(i!=seats)
                    {
                        cout<<", ";
                    }
                    n=j;
                }
                cout<<"\n";
                tot[2] = seats * 200;
            }
        }
        void FirstFloor()
        {
            cout<<"\n Enter the number of seats to be booked : ";
            cin>>seats;
            if(seats<=0)
            {
                cout<<"\n ** Please Enter A Valid Choice **\n ";
            }
            else if(seats>rem3)
            {
                cout<<"\n There are only "<<rem3<<" seats available ";
                cout<<"in the First Floor\n";
            }
            else
            {
                rem3 -= seats;
                cout<<"\n Your seat numbers(FirstFloor) are : ";
                for(i=p+1,j=1;j<=seats;j++,i++)
                {
                    b[i]=1;
                    cout<<" F"<<i;
                    if(j!=seats)
                    {
                        cout<<",";
                    }
                    p=i;
                }
                cout<<"\n";
                tot[3] = seats * 300;
            }
        }
        void CheckOut(int *flag)
        {
            if((rem1==20)&&(rem2==80)&&(rem3==50))
            {
                cout<<"\n\t There is no ticket has been booked from your end !!\n ";
            }
            else
            {
                cout<<"\n**********************************************************************";
                cout<<"\n --------------------------------------------------------------------";
                cout<<"\n |                               BILL                               |";
                cout<<"\n --------------------------------------------------------------------";
                cout<<"\n |"<<setw(56)<<" BOOKING DATE : "<<clock->tm_mday<<"/"<<1+clock->tm_mon<<"/"<<1900+clock->tm_year<<" |";
                cout<<"\n |"<<setw(56)<<" BOOKING TIME : "<<clock->tm_hour<<":"<<clock->tm_min<<":"<<clock->tm_sec<<setw(3)<<
                " |";
                cout<<"\n --------------------------------------------------------------------";
                cout<<"\n |\t FLOOR\t\t\t|   NUMBER OF   |\tAMOUNT\t    |\n |\t\t\t\t|    SEATS\t|\t\t    |";
                cout<<"\n --------------------------------------------------------------------";
                seats=0;
                if(rem1!=20)
                {
                    seats += 20-rem1;
                    cout<<"\n | GroundFloor(1st and 2nd row) |\t"<<20-rem1;
                    cout<<"       |\t "<<tot[1]<<"\t    | ";
                    cout<<"\n --------------------------------------------------------------------";
                }
                if(rem2!=80)
                {
                    seats += 80-rem2;
                    cout<<"\n |       Ground Floor           |\t"<<80-rem2;
                    cout<<"       |\t "<<tot[2]<<"\t    | ";
                    cout<<"\n --------------------------------------------------------------------";
                }
                if(rem3!=50)
                {
                    seats += 50-rem3;
                    cout<<"\n |      First Floor             |\t"<<50-rem3;
                    cout<<"       |\t "<<tot[3]<<"\t    | ";
                    cout<<"\n --------------------------------------------------------------------";
                }
                totalamt = tot[1]+tot[2]+tot[3];
                cout<<"\n | \t  TOTAL \t\t|\t"<<seats<<"      |\t "<<totalamt<<" Rs    |";
                cout<<"\n --------------------------------------------------------------------";

                cout<<"\n\n\n --------------------------------------------------------------------";
                cout<<"\n |                              TICKET                              |";
                cout<<"\n --------------------------------------------------------------------";
                cout<<"\n  MOVIE NAME : SHANG-CHI And The Legend Of The Ten Rings";
                cout<<"\n  TICKET ID : "<<now;   //random number
                cout<<"\n  SHOW DATE : "<<1+clock->tm_mday<<"/"<<1+clock->tm_mon<<"/"<<1900+clock->tm_year;
                if(showchoice==1)
                {
                    cout<<"\n  SHOW TIMING : 09:00 AM to 12:00 PM";
                }
                if(showchoice==2)
                {
                    cout<<"\n  SHOW TIMING : 01:00 PM to 04:00 PM";
                }
                if(showchoice==3)
                {
                    cout<<"\n  SHOW TIMING : 06:00 PM to 09:00 PM";
                }
                cout<<"\n  You have Booked the Seats : ";
                if(rem1!=20)
                {
                    for(i=1,j=0;i<=20;i++)
                    {
                        if(a[i]==1)
                        {
                            if(j==0)
                            {
                                cout<<" G"<<i;
                            }
                            j=1;
                            j=i;
                        }
                    }
                    x=1;
                    if(j!=1)
                    {
                        cout<<" to G"<<j;
                    }
                }
                if(rem2!=80)
                {
                    for(i=21,j=0;i<=101;i++)
                    {
                        if(a[i]==1)
                        {
                            if(j==0)
                            {
                                if(x==1)
                                {
                                    cout<<",";
                                }
                                cout<<" G"<<i;
                            }
                            j=1;
                            j=i;
                        }
                    }
                    x=2;
                    if(j!=21)
                    {
                        cout<<" to G"<<j;
                    }
                }
                if(rem3!=50)
                {
                    for(i=1,j=0;i<=50;i++)
                    {
                        if(b[i]==1)
                        {
                            if(j==0)
                            {
                                if(x==1||x==2)
                                {
                                    cout<<" and";
                                }
                                cout<<" F"<<i;
                            }
                            j=1;
                            j=i;
                        }
                    }
                    if(j!=1){
                        cout<<" to F"<<j;
                    }
                    cout<<"\n --------------------------------------------------------------------";
                }
                *flag=1;
            }
        }
        ~theatre()      //Destructor
        {
            cout<<"\n\t\t\t     THANK YOU\n\t\t        HAVE A NICE DAY :)\n";
            cout<<"\n**********************************************************************\n";
        }
};
int main()
{
    int choice, flag = 0;
    theatre obj;
    do
    {
        cout<<"\n Enter your choice : ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                obj.GroundFloor1();
                break;
            case 2:
                obj.GroundFloor();
                break;
            case 3:
                obj.FirstFloor();
                break;
            case 4:
                obj.CheckOut(&flag);
                break;
            default:
                cout<<"\n\t ** Please enter a valid choice **";
        }
    }while(flag==0);
    return 0;
}

