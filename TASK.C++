#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

// ================= TRAIN CLASS =================

class Train
{
public:

    int trainNumber;
    string trainName;
    string source;
    string destination;
    int totalSeats;
    int availableSeats;
    float fare;

    Train()
    {
    }

    Train(int no, string tn,
          string s, string d,
          int seats, float f)
    {
        trainNumber = no;
        trainName = tn;
        source = s;
        destination = d;
        totalSeats = seats;
        availableSeats = seats;
        fare = f;
    }

    void displayTrain()
    {
        cout << endl;

        cout << "Train Number : "
             << trainNumber << endl;

        cout << "Train Name : "
             << trainName << endl;

        cout << "Source : "
             << source << endl;

        cout << "Destination : "
             << destination << endl;

        cout << "Available Seats : "
             << availableSeats << endl;

        cout << "Fare : "
             << fare << endl;
    }
};

// ================= TICKET CLASS =================

class Ticket
{
public:

    string pnr;
    int trainNumber;

    string passengerName;
    int age;
    string gender;
    string phone;

    string bookingStatus;

    Ticket()
    {
    }

    Ticket(string p, int tNo,
           string name, int a,
           string g, string ph,
           string status)
    {
        pnr = p;
        trainNumber = tNo;

        passengerName = name;
        age = a;
        gender = g;
        phone = ph;

        bookingStatus = status;
    }

    void displayTicket()
    {
        cout << endl;

        cout << "PNR : "
             << pnr << endl;

        cout << "Train Number : "
             << trainNumber << endl;

        cout << "Passenger Name : "
             << passengerName << endl;

        cout << "Age : "
             << age << endl;

        cout << "Gender : "
             << gender << endl;

        cout << "Phone : "
             << phone << endl;

        cout << "Booking Status : "
             << bookingStatus << endl;
    }
};

// ================= LINKED LIST =================

class Node
{
public:

    string passengerName;
    Node *next;

    Node(string name)
    {
        passengerName = name;
        next = NULL;
    }
};

class LinkedList
{
    Node *head;

public:

    LinkedList()
    {
        head = NULL;
    }

    void insertPassenger(string name)
    {
        Node *newNode =
            new Node(name);

        newNode->next = head;

        head = newNode;
    }

    void displayPassengers()
    {
        if (head == NULL)
        {
            cout << endl;
            cout << "No Passenger Found"
                 << endl;

            return;
        }

        Node *temp = head;

        while (temp != NULL)
        {
            cout << endl;

            cout << "Passenger Name : "
                 << temp->passengerName
                 << endl;

            temp = temp->next;
        }
    }
};

// ================= QUEUE CLASS =================

class WaitlistQueue
{
    queue<string> q;

public:

    void enqueue(string name)
    {
        q.push(name);
    }

    void displayQueue()
    {
        if (q.empty())
        {
            cout << endl;
            cout << "Waitlist Empty"
                 << endl;

            return;
        }

        queue<string> temp = q;

        while (!temp.empty())
        {
            cout << temp.front()
                 << endl;

            temp.pop();
        }
    }
};

// ================= STACK CLASS =================

class CancellationStack
{
    stack<string> st;

public:

    void push(string pnr)
    {
        st.push(pnr);
    }

    void displayStack()
    {
        if (st.empty())
        {
            cout << endl;
            cout << "No Cancelled Ticket"
                 << endl;

            return;
        }

        stack<string> temp = st;

        while (!temp.empty())
        {
            cout << temp.top()
                 << endl;

            temp.pop();
        }
    }
};

// ================= RAILWAY SYSTEM =================

class RailwaySystem
{
    vector<Train> trainList;
    vector<Ticket> bookings;

    WaitlistQueue waitlist;
    CancellationStack cancellationStack;
    LinkedList passengerList;

public:

    // ================= ADD TRAIN =================

    void addTrain()
    {
        int no, seats;
        string name, src, dest;
        float fare;

        cout << endl;
        cout << "Enter Train Number : ";
        cin >> no;

        cout << "Enter Train Name : ";
        cin >> name;

        cout << "Enter Source : ";
        cin >> src;

        cout << "Enter Destination : ";
        cin >> dest;

        cout << "Enter Total Seats : ";
        cin >> seats;

        cout << "Enter Fare : ";
        cin >> fare;

        Train t(no, name,
                src, dest,
                seats, fare);

        trainList.push_back(t);

        cout << endl;
        cout << "Train Added Successfully"
             << endl;
    }

    // ================= DISPLAY TRAINS =================

    void displayAllTrains()
    {
        if (trainList.empty())
        {
            cout << endl;
            cout << "No Train Available"
                 << endl;

            return;
        }

        int i = 0;

        while (i < trainList.size())
        {
            trainList[i].displayTrain();

            i++;
        }
    }

    // ================= BOOK TICKET =================

    void bookTicket()
    {
        int trainNo;

        cout << endl;
        cout << "Enter Train Number : ";
        cin >> trainNo;

        int i = 0;

        while (i < trainList.size())
        {
            if (trainList[i].trainNumber
                == trainNo)
            {
                string name;
                int age;
                string gender;
                string phone;

                cout << "Enter Passenger Name : ";
                cin >> name;

                cout << "Enter Age : ";
                cin >> age;

                cout << "Enter Gender : ";
                cin >> gender;

                cout << "Enter Phone : ";
                cin >> phone;

                passengerList.insertPassenger(name);

                int number;

                number = bookings.size() + 1;

                char ch;

                ch = number + 48;

                string pnr = "PNR";

                pnr = pnr + ch;

                if (trainList[i].availableSeats > 0)
                {
                    trainList[i].availableSeats--;

                    Ticket t(
                        pnr,
                        trainNo,
                        name,
                        age,
                        gender,
                        phone,
                        "CONFIRMED"
                    );

                    bookings.push_back(t);

                    cout << endl;
                    cout << "Ticket Booked Successfully"
                         << endl;

                    t.displayTicket();
                }
                else
                {
                    waitlist.enqueue(name);

                    Ticket t(
                        pnr,
                        trainNo,
                        name,
                        age,
                        gender,
                        phone,
                        "WAITLIST"
                    );

                    bookings.push_back(t);

                    cout << endl;
                    cout << "Train Full"
                         << endl;

                    cout << "Passenger Added To Waitlist"
                         << endl;
                }

                return;
            }

            i++;
        }

        cout << endl;
        cout << "Train Not Found"
             << endl;
    }

    // ================= CANCEL TICKET =================

    void cancelTicket()
    {
        string pnr;

        cout << endl;
        cout << "Enter PNR : ";
        cin >> pnr;

        int i = 0;

        while (i < bookings.size())
        {
            if (bookings[i].pnr == pnr)
            {
                bookings[i].bookingStatus =
                    "CANCELLED";

                cancellationStack.push(pnr);

                cout << endl;
                cout << "Ticket Cancelled Successfully"
                     << endl;

                return;
            }

            i++;
        }

        cout << endl;
        cout << "PNR Not Found"
             << endl;
    }

    // ================= DISPLAY BOOKINGS =================

    void displayBookings()
    {
        if (bookings.empty())
        {
            cout << endl;
            cout << "No Booking Found"
                 << endl;

            return;
        }

        int i = 0;

        while (i < bookings.size())
        {
            bookings[i].displayTicket();

            i++;
        }
    }

    // ================= DISPLAY WAITLIST =================

    void displayWaitlist()
    {
        waitlist.displayQueue();
    }

    // ================= DISPLAY PASSENGERS =================

    void displayPassengers()
    {
        passengerList.displayPassengers();
    }

    // ================= DISPLAY CANCELLED =================

    void displayCancelledTickets()
    {
        cancellationStack.displayStack();
    }

    // ================= MAIN MENU =================

    void run()
    {
        int choice = 0;

        while (choice != 9)
        {
            cout << endl;

            cout << "<---- Railway Booking System ----->"
                 << endl;

            cout << "1. Add Train"
                 << endl;

            cout << "2. Display Trains"
                 << endl;

            cout << "3. Book Ticket"
                 << endl;

            cout << "4. Cancel Ticket"
                 << endl;

            cout << "5. Display Bookings"
                 << endl;

            cout << "6. Display Waitlist"
                 << endl;

            cout << "7. Display Passengers"
                 << endl;

            cout << "8. Display Cancelled Tickets"
                 << endl;

            cout << "9. Exit"
                 << endl;

            cout << "Enter Choice : ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                addTrain();
                break;

            case 2:
                displayAllTrains();
                break;

            case 3:
                bookTicket();
                break;

            case 4:
                cancelTicket();
                break;

            case 5:
                displayBookings();
                break;

            case 6:
                displayWaitlist();
                break;

            case 7:
                displayPassengers();
                break;

            case 8:
                displayCancelledTickets();
                break;

            case 9:
                cout << endl;
                cout << "Thank You"
                     << endl;
                break;

            default:
                cout << endl;
                cout << "Invalid Choice"
                     << endl;
            }
        }
    }
};

// ================= MAIN FUNCTION =================

int main()
{
    RailwaySystem system;

    system.run();

    return 0;
}