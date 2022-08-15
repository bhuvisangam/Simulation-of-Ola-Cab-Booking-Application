#include <iostream>
#include<cstring>
#include<fstream>
#include<exception>
#include <limits.h>
#include<cstring>
#include<stdio.h>


#define V 8
using std::ofstream;
using namespace std;

class DisplayError
{
    public:string msg;
           DisplayError(string m)
           {
               msg=m;
           }
           void show()
           {
               cout<<msg;
           }
};

class Login
{
public:
       int choice;
       void load()
       {
          cout<<"Enter 1 to login\n"<<endl;
          cout<<"No account?..";
          cout<<"Press 2 to create\n"<<endl;

          cin>>choice;

          if(choice==1)
          {
            int p;
            p=login();

            while(p==2)
               p=login();

            return;
           }

          else if(choice==2)
          {
            int p;
            p=signup();

            while(p==1)
              p=signup();

            if(p==2)
            {
              int m;

              m=login();

              while(m==2)
                m=login();
            }
            return;
           }

        }

    int login()
{

       string user,password;
       string name,pass;
       int flag=0;


       cout<<"\nEnter\n user name: "<<endl;
       cin>>user;
       cout<<"\npassword: "<<endl;
       cin>>password;


       ifstream in("username.txt");

       if(!in)
       {
        cout<<"Cant open a file";
        return -1;
       }

     while(!in.eof())
        {
            in>>name;
            in>>pass;

            if(user==name)
             {
                if(password==pass)
                {
                   flag=1;
                   cout<<"You have successfully logged in\n";
                   in.close();

                   return 1;
                }
              }
        }
         if(flag==0)
            {
                cout<<"Invalid username or password. Enter valid name\n";
                in.close();
                return 2;
            }

}


int signup()
{

    int flag=0;
    string user,password;
    string name,pass;


    printf("Enter your name: ");
    cin>>user;


    cout<<"Hint: password should not be more than 5 characters\n";
    cout<<"\nEnter your password: ";
    cin>>password;


    if(password.size()>5)
    {
        cout<<"!!!Password has more than 5 characters!!!\nPlease check once\n";
        return(1);
    }


    fstream out("username.txt");


    if(!out)
      {
         cout<<"File not found\n";
         return -1;
      }

    while(!out.eof())
      {

        out>>name>>pass;
        if(name==user||pass==password)
        {

            flag=1;

            if(name==user)
            {
                cout<<"Username already exists. Enter new name\n";
                out.close();
                return 1;
            }

            else if(pass==password)
            {
                cout<<"Password already exists.enter new password\n";
                out.close();
                return 1;
            }


            else
                {
                    cout<<"Both username and password already exist. Enter new value\n";
                    out.close();;
                    return 1;
                 }
           }

        }
        out.close();
        ofstream outdata;

        outdata.open("username.txt",std::ios_base::app);

        if(!outdata)
        {
            cout<<"File not found\n";
            return -1;
        }

        if(flag==0)
        {
            cout<<"You have successfully signed in with us.\n";
            outdata<<"\n"<<user<<" "<<password;
            outdata.close();
            return 2;
        }

}

};

class Vehicle
{
    public: string vehicleNumber;
            string vehicleChassis;


            Vehicle()
            {
                vehicleNumber="";
                vehicleChassis="";

            }

            Vehicle(string n,string chassis)
            {
                vehicleNumber=n;
                vehicleChassis=chassis;

            }

            virtual void printVehicle()=0;


};

class RentalVehicle:public Vehicle
{
    public: float rentalAmount;
            string location;
            string availability;

            RentalVehicle():Vehicle()
            {
                rentalAmount=0;
                location="";
                availability="";
            }

            RentalVehicle(string n,string chassis,string loc,string a):Vehicle(n,chassis)
            {
                rentalAmount=100;
                location=loc;
                availability=a;
            }



            void printVehicle()
            {

                cout<<"Vehicle Number:"<<Vehicle::vehicleNumber<<"\nChassis Number:"<<Vehicle::vehicleChassis<<"\nLocation:"<<location<<"\n";
            }

};

class MiniRentalVehicle:public RentalVehicle
{
    public: float minPrice;

            MiniRentalVehicle():RentalVehicle()
            {
                minPrice=0;
            }

            MiniRentalVehicle(string n,string chassis,string loc,string a):RentalVehicle(n,chassis,loc,a)
            {
                minPrice=25;
                minPrice=minPrice+RentalVehicle::rentalAmount;
            }


            void printVehicle()
            {
                RentalVehicle::printVehicle();
                cout<<"Fixed Charges for  mini rental vehicle is Rs."<<minPrice;

            }
};

class SedanRentalVehicle:public RentalVehicle
{
    public: float minPrice;

            SedanRentalVehicle():RentalVehicle()
            {
                minPrice=0;
            }

            SedanRentalVehicle(string n,string chassis,string loc,string a):RentalVehicle(n,chassis,loc,a)
            {
                minPrice=75;
                minPrice=minPrice+RentalVehicle::rentalAmount;
            }

            void printVehicle()
            {
                RentalVehicle::printVehicle();
                cout<<"Fixed Charges for sedan rental vehicle is Rs."<<minPrice;

            }
};
class MacroRentalVehicle:public RentalVehicle
{
    public: float minPrice;

            MacroRentalVehicle():RentalVehicle()
            {
                minPrice=0;
            }

            MacroRentalVehicle(string n,string chassis,string loc,string a):RentalVehicle(n,chassis,loc,a)
            {
                minPrice=50;
                minPrice=minPrice+RentalVehicle::rentalAmount;
            }


            void printVehicle()
            {
                RentalVehicle::printVehicle();
                cout<<"Fixed Charges for macro rental vehicle is Rs."<<minPrice;

            }
};


class NormalVehicle:public Vehicle
{
    public: float baseAmount;

            NormalVehicle():Vehicle()
            {
                baseAmount=0;
            }

            NormalVehicle(string n,string chassis):Vehicle(n,chassis)
            {
                baseAmount=120;
            }

            void printVehicle()
            {

                cout<<"Vehicle Number:"<<Vehicle::vehicleNumber<<"\nChassis Number:"<<Vehicle::vehicleChassis<<"\n";

            }

};

class MiniNormalVehicle:public NormalVehicle
{
    public: float minPrice;

            MiniNormalVehicle():NormalVehicle()
            {
                minPrice=0;
            }

            MiniNormalVehicle(string n,string chassis):NormalVehicle(n,chassis)
            {
                minPrice=30;
                minPrice=minPrice+NormalVehicle::baseAmount;
            }


            void printVehicle()
            {
                NormalVehicle::printVehicle();
                cout<<"Fixed Charges for  mini normal vehicle is Rs."<<minPrice;

            }
};

class MacroNormalVehicle:public NormalVehicle
{
    public: float minPrice;

            MacroNormalVehicle():NormalVehicle()
            {
                minPrice=0;
            }

            MacroNormalVehicle(string n,string chassis):NormalVehicle(n,chassis)
            {
                minPrice=60;
                minPrice=minPrice+NormalVehicle::baseAmount;
            }


            void printVehicle()
            {
                NormalVehicle::printVehicle();
                cout<<"Fixed Charges for  macro normal vehicle is Rs."<<minPrice;

            }
};

class SedanNormalVehicle:public NormalVehicle
{
    public: float minPrice;

            SedanNormalVehicle():NormalVehicle()
            {
                minPrice=0;
            }

            SedanNormalVehicle(string n,string chassis):NormalVehicle(n,chassis)
            {
                minPrice=90;
                minPrice=minPrice+NormalVehicle::baseAmount;
            }


            void printVehicle()
            {
                NormalVehicle::printVehicle();
                cout<<"Fixed Charges for  sedan normal vehicle is Rs."<<minPrice;

            }
};

class Driver
{
private:
     int check;
public:
    string driverName;
    int driverAge;
    string location;
    string availability;
    MiniNormalVehicle* mnv;
    MacroNormalVehicle* mcnv;
    SedanNormalVehicle* snv;
    string dtype;


Driver()
{
     driverName="";
     driverAge=0;
     location="";
     availability="";
}

Driver(string n,int ag,string loc,string av,MiniNormalVehicle *m)
{
    driverName=n;
    driverAge=ag;
    location=loc;
    availability=av;
    mnv=m;
    check=1;
    dtype="mini";
}

Driver(string n,int ag,string loc,string av,MacroNormalVehicle* mc)
{
     driverName=n;
     driverAge=ag;
     location=loc;
     availability=av;
     mcnv=mc;
     check=2;
     dtype="macro";
}

Driver(string n,int ag,string loc,string av,SedanNormalVehicle* sd)
{
     driverName=n;
     driverAge=ag;
     location=loc;
     availability=av;
     snv=sd;
     check=3;
     dtype="sedan";
}

void printDriver()
{
    cout<<"\n\nThe details of the driver and his vehicle are: "<<endl;
    cout<<"Name : "<<driverName<<endl;
    cout<<"Age  : "<<driverAge<<endl;
    if(check==1)
    {
        mnv->printVehicle();
    }
    else if(check==2)
    {
        mcnv->printVehicle();
    }
    else
    {
        snv->printVehicle();
    }

}

};


class BankAccount
{
public:
    string bankName;
    string branch;
    int accNo;
    float balance;

BankAccount()
{
    bankName="";
    branch="";
    accNo=0;
    balance=0;
}

BankAccount(string a,string b,int c,float d)
{
    bankName=a;
    branch=b;
    accNo=c;
    balance=d;
}

void printAccount()
{
    cout<<"The details of the account are:"<<endl;
    cout<<"BANK NAME : "<<bankName<<endl;
    cout<<"BRANCH OF THE BANK : "<<branch<<endl;
    cout<<"ACCOUNT NUMBER : "<<accNo<<endl;
    cout<<"BALANCE IN THE ACCOUNT : "<<balance<<endl;
}

};

class Customer
{
public:
    string customerName;
    int custAge;
    string source;
    string destination;
    string vehicleType;
    string travelType;
    BankAccount *bank;
    float price;
    string status;

Customer()
{
     customerName="";
     custAge=0;
     source="";
     destination="";
     vehicleType="";
     travelType="";

}

Customer(string ab,int g,string s,string d,string v,string t,BankAccount* b)
{
    customerName=ab;
     custAge=g;
     source=s;
     destination=d;
     vehicleType=v;
     travelType=t;
     bank=b;
}

Customer(string ab,int g,string s,string v,string t,BankAccount* b)
{
     customerName=ab;
     custAge=g;
     source=s;
     vehicleType=v;
     travelType=t;
     bank=b;
}

void printCustomer()
{
    cout<<"CUSTOMER NAME : "<<customerName<<endl;
    cout<<"CUSTOMER AGE  : "<<custAge<<endl;
}

};


class OlaCabService
{
public:
       Driver *d;
       Driver* d0;
       Driver d1;
       Customer* customer;
       int dcount;
       int counter=0;
       float distance;


       OlaCabService(Driver *dr,Customer *cust,int dc)
       {
         d=dr;
         customer=cust;
         dcount=dc;
       }
       void assigning()
       {
          //cout<<"\nAvailable drivers are:\n\n";
          if(customer->vehicleType=="mini")
           {
             for(int i=0;i<dcount;i++)
                {
                   if(d[i].dtype=="mini"&&d[i].availability=="yes"&&d[i].location==customer->source)
                    {
                        d1=d[i];
                       cout<<"\nDriver "<<d[i].driverName<<" is near to your location. He will be reaching you in few minutes\n";
                       //d0[counter]=d[i];
                       counter++;
                       d[i].printDriver();
                       break;
                    }
                }
           }
           else if(customer->vehicleType=="macro")
           {
              for(int i=0;i<dcount;i++)
                {
                  if(d[i].dtype=="macro"&&d[i].availability=="yes"&&d[i].location==customer->source)
                    {
                       d1=d[i];
                       cout<<"Driver "<<d[i].driverName<<" is near to your location. He will be reaching you in few minutes\n";

                       //d0[counter]=d[i];
                       counter++;
                       d[i].printDriver();
                       break;
                    }
                }
           }
           else
                {
                    for(int i=0;i<dcount;i++)
                           {
                             if(d[i].dtype=="sedan"&&d[i].availability=="yes"&&d[i].location==customer->source)
                             {
                                d1=d[i];
                                cout<<"Driver "<<d[i].driverName<<" is near to your location. He will be reaching you in few minutes\n";

                                //d0[counter]=d[i];
                                counter++;
                                d[i].printDriver();
                                break;
                             }
                            }
                }
                if(counter==0)
                {
                    throw DisplayError("\n----Oops!!! No drivers found at your location. Please wait for few minutes----\n");
                }

        }


        int minDistance(int dist[], bool sptSet[])
    {
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
    }

void printSolution(int dist[],string pl[],int d)
{
    distance=dist[d];
	cout <<"\nShortest distance from your location to " <<pl[d]<<":"<<dist[d]<<" Km.\n";
		 //cout<<pl[d]<< "\t\t"<<dist[d]<< endl;
}

void dijkstra(int graph[V][V],int src,string pl[],int d)
{
	int dist[V];
	bool sptSet[V];
	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX, sptSet[i] = false;
	dist[src] = 0;
	for (int count = 0; count < V - 1; count++) {
		int u = minDistance(dist, sptSet);
		sptSet[u] = true;
		for (int v = 0; v < V; v++)
			if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
				&& dist[u] + graph[u][v] < dist[v])
				dist[v] = dist[u] + graph[u][v];
	}
	printSolution(dist,pl,d);
}

void search_place(int p)
{
    int d,si;
    if(p==1)
        {
            string pl[8]={"KLETU","THE_HANS","UNKAL_LAKE","KIMS","PEACE_CAFE","URBAN_OASIS_MALL", "RAILWAY_MUSEUM","ISKCON"};
            int graph[V][V] = { { 0, 1, 3, 2, 1, 0, 0, 0 },
                        { 1, 0, 4, 0, 0, 0, 0, 0},
                        { 3, 4, 0, 0, 0, 0, 0, 0},
                        { 2, 0, 0, 0, 0, 3, 0, 18},
                        { 1, 0, 0, 0, 0, 7, 0, 0},
                        { 0, 0, 0, 3, 7, 0, 5, 0},
                        { 0, 0, 0, 0, 0, 5, 0, 12},
                        { 0, 0, 0,18, 0, 0, 12, 0},};

            for(int i=0;i<8;i++)
           {
              if(customer->destination==pl[i])
              {
                d=i;
                break;
              }
           }

            for(int i=0;i<8;i++)
           {
              if(customer->source==pl[i])
              {
                si=i;
                break;
              }
           }
           dijkstra(graph,si,pl,d);
        }
      else if(p==2)
        {

         string po[8]={"hubli","dharwad","Dandeli","Goa","Belgavi", "Banglore", "Mysore","Udupi"};

         int graph[V][V] = { { 0, 17, 72, 0, 0, 0, 471, 303 },
                        { 17, 0, 0, 0, 76, 431, 0, 0},
                        { 72, 0, 0, 100, 0, 0, 0, 285},
                        { 0, 0, 100, 0, 104, 0, 0, 0},
                        { 0, 76, 0, 104, 0, 0, 0, 0},
                        { 0, 431, 0,0, 0, 0, 187, 0},
                        { 471, 0, 0, 0, 0, 187, 0,306},
                        { 303, 0, 285, 0, 0, 0, 306, 0},};
        for(int i=0;i<8;i++)
       {
          if(customer->destination==po[i])
          {
              d=i;
              break;
          }
       }

        for(int i=0;i<8;i++)
        {
              if(customer->source==po[i])
              {
                si=i;
                break;
              }
        }
           dijkstra(graph,si,po,d);
        }

}

};


class OlaRentalService
{
public:
    Customer* cust;
    int rcount;
    int counter=0;
    SedanRentalVehicle srv0;
    MiniRentalVehicle mrv0;
    MacroRentalVehicle mcrv0;

    OlaRentalService(Customer* c,int scnt)
    {
        cust=c;
        rcount=scnt;

    }

    void assigning(SedanRentalVehicle* srv)
       {

          //cout<<"\nAvailable drivers are:\n\n";
             for(int i=0;i<rcount;i++)
                {
                   if(srv[i].availability=="yes"&&srv[i].location==cust->source)
                    {
                        srv0=srv[i];
                       cout<<"\nSudo Rental vehicle with vehicle number "<<srv[i].vehicleNumber<<" is near by your location.Please pick the rental vehicle.\n";
                       //d0[counter]=d[i];
                       counter++;
                       //d[i].printDriver();
                       break;
                    }
                }
                if(counter==0)
                {
                    throw DisplayError("\n----Oops!!! No Rental vehicle found at your location. Please wait for few minutes----\n");
                    //cout<<"\n----Oops!!! No Rental vehicle found at your location. Please wait for few minutes----\n";
                }

           }

           void assigning(MiniRentalVehicle* mrv)
       {
          //cout<<"\nAvailable drivers are:\n\n";
             for(int i=0;i<rcount;i++)
                {

                   if(mrv[i].availability=="yes"&&mrv[i].location==cust->source)
                    {
                        mrv0=mrv[i];
                       cout<<"\Mini Rental vehicle with vehicle number "<<mrv[i].vehicleNumber<<" is near by your location.Please pick the rental vehicle.\n";
                       //d0[counter]=d[i];
                       counter++;
                       //d[i].printDriver();
                       break;
                    }
                }
                if(counter==0)
                {
                    throw DisplayError("\n----Oops!!! No Rental vehicle found at your location. Please wait for few minutes----\n");
                    //cout<<"\n----Oops!!! No Rental vehicle found at your location. Please wait for few minutes----\n";
                }

           }

           void assigning(MacroRentalVehicle* mcrv)
       {
          //cout<<"\nAvailable drivers are:\n\n";
             for(int i=0;i<rcount;i++)
                {

                   if(mcrv[i].availability=="yes"&&mcrv[i].location==cust->source)
                    {
                        mcrv0=mcrv[i];
                       cout<<"\nMacro Rental vehicle with vehicle number "<<mcrv[i].vehicleNumber<<" is near by your location.Please pick the rental vehicle.\n";
                       //d0[counter]=d[i];
                       counter++;
                       //d[i].printDriver();
                       break;
                    }
                }
                if(counter==0)
                {
                    throw DisplayError("\n----Oops!!! No Rental vehicle found at your location. Please wait for few minutes----\n");
                    //cout<<"\n----Oops!!! No Rental vehicle found at your location. Please wait for few minutes----\n";
                }

        }
};

class Fair
{
    public: //OlaCabService *oc;
            //OlaRentalService *ot;

            /*Fair(OlaCabService *oc1)
            {
                oc=oc1;
            }

            Fair(OlaRentalService *ot1)
            {
                ot=ot1;
            }*/

            void compute(OlaCabService *oc)
            {
                if(oc->customer->vehicleType=="mini")
                    oc->customer->price=(oc->distance*10)+oc->d1.mnv->minPrice;
                else if(oc->customer->vehicleType=="macro")
                    oc->customer->price=(oc->distance*7)+oc->d1.mcnv->minPrice;
                else
                    oc->customer->price=(oc->distance*7)+oc->d1.snv->minPrice;
                 cout<<"\nIncluding 50% service charge and 45%GST,\n";
                 cout<<"Total charge to be paid:"<<oc->customer->price;
            }

            void compute(OlaRentalService *ot)
            {
                cout<<"\n\nIncluding 75% service tax and insurance claim and 45% GST,";
                if(ot->cust->vehicleType=="mini")
                {
                    ot->cust->price=ot->mrv0.minPrice;
                  cout<<"\nTotal charge to be paid:"<<ot->cust->price;
                }
                else if(ot->cust->vehicleType=="macro")
                   {
                       ot->cust->price=ot->mcrv0.minPrice;
                       cout<<"\nTotal charge to be paid:"<<ot->cust->price;
                   }
                else
                   {
                       ot->cust->price=ot->srv0.minPrice;
                       cout<<"\nTotal charge to be paid:"<<ot->cust->price;

                   }

              cout<<"\n\n*Disclaimer: Petrol and diesel amount will not be provided by the service station,if any damages occur to the vehicle, penalty will be issued based on terms and conditions*\n";
            }
};


class Cancellation
{
    public: OlaCabService *oc;
            OlaRentalService *ot;
            string choice;
            string status="unpaid";

            Cancellation(OlaCabService *oc1)
            {
                oc=oc1;
            }

            Cancellation(OlaRentalService *ot1)
            {
                ot=ot1;
            }

            int cancel()
            {
                cout<<"\nAre u sure you want to cancel the booking?yes/no\n";
                cin>>choice;
                   if(choice=="yes")
                   {
                      status="cancelled";
                      return 0;
                   }
                   else if(choice=="no")
                   {
                    status="Paid";
                    return 1;
                   }
            }
};

class Strategy
{
public:
    virtual int pay(Customer *c)=0;
    //float amt=fare.compute();
    virtual ~Strategy(){}
};
class Cash:public Strategy
{
public:
    float cashPaid;
    int pay(Customer *c)
    {
        cout<<"Enter the cash amount that you are paying"<<endl;
        cin>>cashPaid;
        if(cashPaid>c->price)
        {
            int diff=cashPaid-(c->price);
            cout<<"Change of "<<diff<<"rs paid back successfully"<<endl;
            c->bank->balance=c->bank->balance+diff;
            cout<<"Thank you for paying!"<<endl;
            return 1;
        }
        else if(cashPaid<c->price)
        {
            cout<<"Amount to be paid is: "<<c->price<<endl;
            c->price=c->price-cashPaid;
            cout<<"Amount of "<<c->price<<"rs has to be paid"<<endl;
            return 0;
        }
        else
        {
            cout<<"Amount Paid successfully"<<endl;
            return 1;
        }
    }
     virtual ~Cash(){}
};
class Online:public Strategy
{
public:
    int pay(Customer *c)
    {

        if(c->bank->balance <c->price)
        {
            /*cout<<"Insufficient Balance.Amount to be paid is: "<<c->price<<endl;
            c->price=c->price-(c->bank->balance);

            cout<<"Amount of "<<c->price<<"rs has to be paid"<<endl;
            return 0;*/
            throw DisplayError("\n\n----Insufficient Balance.Your booking is denied----\n");
        }
        else
        {
            cout<<"Amount Paid successfully"<<endl;
             c->bank->balance=c->bank->balance-c->price;
             cout<<"amount in bank: "<<c->bank->balance<<endl;
             return 1;
        }
    }

    //cout<<amt<<" paid successfully,Current balance is: "<<b<<endl;
    virtual ~Online(){}
};
class Payment_Details
{
protected:
    Strategy *s;
public:
    Payment_Details(Strategy *s1)
    {
        s=s1;
    }
    int payment(Customer *c)
    {
        int p=s->pay(c);
        return p;

    }
};

class History
{
    public:
        static int i;
        float amt[10];
        History()
        {
            amt[i]=0;
        }
        History(Customer cust)
        {
          amt[i]=cust.price;
          i++;
        }
        void displayHistory()
            {
                for(int j=0;j<i;j++)
                {
                 cout<<"Price paid "<<amt[j] <<" during "<<j+1<<" booking"<<endl;

                 }

            }

};
int History::i=0;
class composite
{
    public:
            displayDriver(Driver d[10])
            {
                cout<<"\n-----------Available vehicles in our service station:------------\n\n";
              for(int i=0;i<10;i++)
              {
                d[i].printDriver();
              }
            }
};

int main()
{
    SedanNormalVehicle sn1("KA20M999","453E534AB12234398");
    SedanNormalVehicle sn2("KA20M934","175F347KL12734001");
    SedanNormalVehicle sn3("KA20M184","303I534YB12154368");

    MiniNormalVehicle mn1("KA16H179","153E504WB19234191");
    MiniNormalVehicle mn2("KA15F087","327B001AX98123140");
    MiniNormalVehicle mn3("KA26J220","143V101OS43231110");

    MacroNormalVehicle mc1("KA12N177","337B001AX99123190");
    MacroNormalVehicle mc2("KA45R114","365Y731AW19123199");
    MacroNormalVehicle mc3("KA90P437","960B301WX39193275");
    MacroNormalVehicle mc4("KA75T457","438B301WX39193916");

    SedanRentalVehicle sr1("KA25F887","317C001AX99123190","Vidyanagar","yes");
    SedanRentalVehicle sr2("KA35Q114","327B001AX91123143","Unkal","no");
    SedanRentalVehicle sr3("KA10D934","383J534YB47354362","Unkal","yes");
    SedanRentalVehicle sudo[3]={sr1,sr2,sr3};

    MiniRentalVehicle mr1("KA17D234","317D001KX99123276","Shirur_park","yes");
    MiniRentalVehicle mr2("KA25Q214","615Z731FW19123109","Seven_beans","yes");
    MiniRentalVehicle mr3("KA11N177","151E504WE12764751","Kallur_layout","yes");
    MiniRentalVehicle mini[3]={mr1,mr2,mr3};

    MacroRentalVehicle mcr1("KA10D934","717D031KX99123259","Vidyanagar","yes");
    MacroRentalVehicle mcr2("KA25K112","243J532YB47354301","Shivagiri","no");
    MacroRentalVehicle mcr3("KA48R134","970B301WX31193238","Kallur_layout","no");
    MacroRentalVehicle macro[3]={mcr1,mcr2,mcr3};

    Driver d1("SATISH",40,"ISKCON","yes",&sn1);
    Driver d2("GIRISH",27,"KIMS","yes",&mn1);
    Driver d3("YATISH",52,"KLETU","no",&mc3);
    Driver d4("Maruti",42,"THE_HANS","no",&sn2);
    Driver d5("Ram",39,"Hubli","yes",&mn2);
    Driver d6("Ramesh",41,"dharwad","yes",&mc1);
    Driver d7("Gaurav",44,"Belgavi","no",&mn3);
    Driver d8("Nagaraj",34,"Udupi","yes",&sn3);
    Driver d9("sanket",36,"RAILWAY_MUSEUM","yes",&mc2);
    Driver d10("Samarth",30,"Goa","yes",&mc4);
    Driver dv[10]={d1,d2,d3,d4,d5,d6,d7,d8,d9,d10};
 History h=History();

    try
{
    int choice,age,accno,p;
    string name,dest,vtype,ttype,bank,branch,source;
    float balance;

    Login l;
    l.load();

    cout<<"\n\n-----------------------------------------------------------\n";
    cout<<"WELCOME TO OLA CAB SERVICE\n";
    cout<<"-----------------------------------------------------------\n";

    cout<<"Please link your bank account\n";
    cout<<"Enter your bank name:\n";
    cin>>bank;
    cout<<"Enter your bank branch:\n";
    cin>>branch;
    cout<<"Enter your bank account number:\n";
    cin>>accno;
    cout<<"Enter your bank balance:\n";
    cin>>balance;

    BankAccount b(bank,branch,accno,balance);



    while(1)
   {
    cout<<"\n\nServices Available:\n";
    cout<<"1-Ola Cab Service\n";
    cout<<"2-Ola Rental Service\n";
    cout<<"3-Ola Manual Page\n";
    cout<<"4-Log Out\n";
    cout<<"Press 1, 2 ,3 or 4 to proceed\n";
    cin>>choice;

    switch(choice)
   {
       case 1:{
              cout<<"\n\nPlease fill the basic details to book the cab\n";
              cout<<"Name:"<<endl;
              cin>>name;
              cout<<"Age:"<<endl;
              cin>>age;
              cout<<"Enter:1.If your  location is Hubli\t2.if your location is out of Hubli\n";
              cin>>p;
              cout<<"Your current location:"<<endl;
              cin>>source;
              cout<<"Destination to be reached:\n";
              cin>>dest;
              cout<<"Available vehicle types are mini, macro, sedan\n";
              cout<<"Vehicle you prefer for travel\n";
              cin>>vtype;

              Customer c1(name,age,source,dest,vtype,"cab",&b);
              OlaCabService ol(dv,&c1,10);
              Fair f;
              int m,j;
              ol.assigning();
              ol.search_place(p);
              f.compute(&ol);
              Cancellation c(&ol);
              cout<<"\n\nFor further transaction click\n1-Payment\t2-Cancellation\n";
              cout<<"*Disclaimer: Once payment initialized booking cannot be cancelled*\n";
              cin>>j;
              if(j==1)
              {
                int r;
                cout<<"Enter 1 to pay online and 2 to pay in cash"<<endl;
                int choice;
                cin>>choice;
                if(choice==1)
                {
                    Payment_Details *p=new Payment_Details(new Online());
                    r=p->payment(&c1);
                    while(r!=1)
                        r=p->payment(&c1);
                     c.status="paid";

                }
                else if(choice==2)
                {
                    Payment_Details *p=new Payment_Details(new Cash());
                    r=p->payment(&c1);
                    while(r!=1)
                        r=p->payment(&c1);
                     c.status="paid";

                }
               }
               else if(j==2)
                  {
                      if(c.status=="cancelled")
                           cout<<"Booking is already cancelled\n";

                      else
                      {
                           m=c.cancel();
                           if(m==1)
                           {
                               int r;
                               cout<<"Enter 1 to pay online and 2 to pay in cash"<<endl;
                               int choice;
                               cin>>choice;
                               if(choice==1)
                               {
                                 Payment_Details *p=new Payment_Details(new Online());
                                 r=p->payment(&c1);
                                 while(r!=1)
                                   r=p->payment(&c1);
                                    h=History(c1);
                               }
                              else if(choice==2)
                               {
                                 Payment_Details *p=new Payment_Details(new Cash());
                                 r=p->payment(&c1);
                                 while(r!=1)
                                   r=p->payment(&c1);
                                    h=History(c1);
                                }
                            }
                         }
                     }
                cout<<"\nIf you want to check payment history click 1\n";
                  cin>>p;
                  if(p==1)
                  {
                       h=History(c1);
                    h.displayHistory();
                  }
                  else
                  {
                      cout<<"\n\n---Logging Out---\n";
                      exit(0);
                  }
               }

              break;

       case 2:{
              int j,m;
              cout<<"\n\nPlease fill the basic details to book the cab for rent\n";
              cout<<"Name:"<<endl;
              cin>>name;
              cout<<"Age:"<<endl;
              cin>>age;
              cout<<"Your current location:"<<endl;
              cin>>source;
              cout<<"Available vehicle types are mini, macro, sedan\n";
              cout<<"Vehicle you prefer for travel\n";
              cin>>vtype;
              Customer c1(name,age,source,vtype,"rental",&b);
              OlaRentalService ol(&c1,3);
              Fair f;

              if(vtype=="sedan")
              {
                  //OlaRentalService ol(&c1,3);

                  ol.assigning(sudo);
                  f.compute(&ol);

              }
              else if(vtype=="mini")
              {
                  //OlaRentalService ol(&c1,3);
                  ol.assigning(mini);
                  f.compute(&ol);

              }
              else if(vtype=="macro")
              {
                  //OlaRentalService ol(&c1,3);
                  ol.assigning(macro);
                  f.compute(&ol);
              }

              Cancellation c(&ol);
              cout<<"\n\nFor further transaction click\n1-Payment\t2-Cancellation\n";
              cout<<"*Disclaimer: Once payment initialized booking cannot be cancelled*\n";
              cin>>j;
              if(j==1)
              {
                int r;
                cout<<"Enter 1 to pay online and 2 to pay in cash"<<endl;
                int choice;
                cin>>choice;
                if(choice==1)
                {
                    Payment_Details *p=new Payment_Details(new Online());
                    r=p->payment(&c1);
                    while(r!=1)
                        r=p->payment(&c1);
                     c.status="paid";
                }
                else if(choice==2)
                {
                    Payment_Details *p=new Payment_Details(new Cash());
                    r=p->payment(&c1);
                    while(r!=1)
                        r=p->payment(&c1);
                     c.status="paid";
                }
               }
               else if(j==2)
                  {
                      if(c.status=="cancelled")
                           cout<<"Booking is already cancelled\n";

                      else
                      {
                           m=c.cancel();
                           if(m==1)
                           {
                               int r;
                               cout<<"Enter 1 to pay online and 2 to pay in cash"<<endl;
                               int choice;
                               cin>>choice;
                               if(choice==1)
                               {
                                 Payment_Details *p=new Payment_Details(new Online());
                                 r=p->payment(&c1);
                                 while(r!=1)
                                   r=p->payment(&c1);
                                   h=History(c1);
                               }
                              else if(choice==2)
                               {
                                 Payment_Details *p=new Payment_Details(new Cash());
                                 r=p->payment(&c1);
                                 while(r!=1)
                                   r=p->payment(&c1);
                                   h=History(c1);
                                }
                            }
                         }
                     }

                  cout<<"\nIf you want to check payment history click 1\n";
                  cin>>p;
                  if(p==1)
                  {
                    h.displayHistory();
                  }
                  else
                  {
                      cout<<"\n\n---Logging Out---\n";
                      exit(0);
                  }

              }
              break;
       case 3:composite co;
              co.displayDriver(dv);
              break;

       case 4:cout<<"\n\n---Logging Out---\n";
              exit(0);

    }
   }
}

catch(DisplayError &e)
{
    e.show();
}

    return 0;
}
