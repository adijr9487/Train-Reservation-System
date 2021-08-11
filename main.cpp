//  g++ -std=c++11 main.cpp -o main && ./main

#include <bits/stdc++.h>
#include <iostream>
#include <conio.h>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;

//---------------------function declaration---------------------
//Utility Functions
void space(int);
void create_route_header();
void route_header();
string to_lower(string);

//----------------------Variable defnition----------------------

//train class
class Train
{
public:
    string Name, Train_no, from, to;

    string train_status_array[50][4];
    //[ ["class", total, avaible, "fare_charge"]]
    int status_counter = 0;
    Train()
    {
        //constructor without argument
        this->Name = "null";
    }
    Train(string Name, string from, string to, string Train_no)
    {
        this->Name = Name;
        this->Train_no = Train_no;
        this->from = from;
        this->to = to;
    }
    void set_train_status(string class_name, string total_seats, string fare_charge, string available = "no")
    {
        this->train_status_array[this->status_counter][0] = class_name;
        this->train_status_array[this->status_counter][1] = total_seats;
        if (available == "no")
            this->train_status_array[this->status_counter][2] = total_seats;
        else
        {
            this->train_status_array[this->status_counter][2] = available;
        }
        this->train_status_array[this->status_counter][3] = fare_charge;
        this->status_counter += 1;
    }
    void booked_value(int index, int no_of_seat)
    {
        this->train_status_array[index][2] =- no_of_seat;
    }

    void get_train_status(int index = -1)
    {
        if (this->status_counter > 0)
        {
            if (index == -1)
                for (int i = 0; i < this->status_counter; i++)
                {

                    cout << "+---------------------------------------------------------------------------------------+" << endl;
                    cout << "| " << i + 1;
                    space(5 - to_string(i + 1).length() - 1);
                    cout << "|        " << this->train_status_array[i][0];
                    space(22 - this->train_status_array[i][0].length() - 8);
                    cout << "|        " << this->train_status_array[i][1];
                    space(15 - this->train_status_array[i][1].length() - 8);
                    cout << "|        " << this->train_status_array[i][2];
                    space(19 - this->train_status_array[i][2].length() - 8);
                    cout << "|        " << this->train_status_array[i][3];
                    space(22 - this->train_status_array[i][3].length() - 8);
                    cout << "|" << endl;
                    cout << "+---------------------------------------------------------------------------------------+" << endl;
                }
            else
            {
                cout << "+---------------------------------------------------------------------------------------+" << endl;
                cout << "| " << 1;
                space(5 - to_string(1).length() - 1);
                cout << "|        " << this->train_status_array[index][0];
                space(22 - this->train_status_array[index][0].length() - 8);
                cout << "|        " << this->train_status_array[index][1];
                space(15 - this->train_status_array[index][1].length() - 8);
                cout << "|        " << this->train_status_array[index][2];
                space(19 - this->train_status_array[index][2].length() - 8);
                cout << "|        " << this->train_status_array[index][3];
                space(22 - this->train_status_array[index][3].length() - 8);
                cout << "|" << endl;
                cout << "+---------------------------------------------------------------------------------------+" << endl;
            }
        }
        else
        {
            cout << "No status recorded" << endl;
        }
    }
    void get_train_data(string counter)
    {

        cout << "+-------------------------------------------------------------------------------------------------------------------------+" << endl;
        cout << "| " << counter;
        space(6 - counter.length() - 1);
        cout << "|        " << this->Name;
        space(26 - this->Name.length() - 8);
        cout << "|        " << from;
        space(31 - this->from.length() - 8);
        cout << "|        " << to;
        space(27 - this->to.length() - 8);
        cout << "|        " << Train_no;
        space(27 - this->Train_no.length() - 8);
        cout << "|" << endl;
        cout << "+-------------------------------------------------------------------------------------------------------------------------+" << endl;
    }
};
//person class
class Person
{
public:
    string uid, username, Name, gender, DOB, contact, password;

    Person()
    {
        //constructor without argument
        this->Name = "null";
    }
    Person(string username, string Name, string gender, string DOB, string contact, string password, string uid = to_string(abs((int)floor(rand() * 100000000))))
    {
        this->username = to_lower(username);
        this->uid = uid;
        this->contact = contact;
        this->gender = gender;
        this->Name = Name;
        this->password = password;
        this->DOB = DOB;
    }
    void get_Profile()
    {
        cout << "Name : " << this->Name << endl;
        cout << "gender : " << this->gender << endl;
        cout << "Date of Birth : " << this->DOB << endl;
    }
};

class Booking
{
public:
    string user_id, train_no, class_name, date_of_journey, status, no_of_seat;
    string Booking_users[10][4]; //[[name,dob,age,gender]]
    int user_counter = 0;

    void set_booking_detail(string user_id, string train_no, string class_name, string date_of_journey, string status, string no_of_seat)
    {
        this->user_id = user_id;
        this->train_no = train_no;
        this->class_name = class_name;
        this->date_of_journey = date_of_journey;
        this->status = status; //Active
        this->no_of_seat = no_of_seat;
    }

    void set_booking_user(string name, string dob, string age, string gender)
    {
        this->Booking_users[this->user_counter][0] = name;
        this->Booking_users[this->user_counter][1] = dob;
        this->Booking_users[this->user_counter][2] = age;
        this->Booking_users[this->user_counter][3] = gender;
        this->user_counter++;
    }
    void show_tickets()
    {
        cout << "\n\n";
        cout << "+===============================================================+" << endl;
        cout << "|                            Ticket                             |" << endl;
        cout << "+===============================================================+" << endl;
        cout << "+---------------------------------------------------------------+" << endl;
        cout << "||        Name of Pass.        | age |  gender ||    |  Status  |" << endl;
        cout << "+---------------------------------------------------------------+" << endl;
        for (int i = 0; i < this->user_counter; i++)
        {
            cout << "||  " << this->Booking_users[i][0];
            space(29 - this->Booking_users[i][0].length() - 2);
            cout << "| " << this->Booking_users[i][2];
            space(5 - this->Booking_users[i][2].length() - 1);
            cout << "|  " << this->Booking_users[i][3];
            space(9 - this->Booking_users[i][3].length() - 2);
            cout << "||";
            space(15);
            cout << "|" << endl;
        }
        cout << "||";
        space(51);
        cout << "|" << this->status;
        space(10 - this->status.length());
        cout << "|\n";
        cout << "+---------------------------------------------------------------+" << endl;
        cout << "||        Date        | train number |  class |     User Id     |" << endl;
        cout << "+---------------------------------------------------------------+" << endl;
        cout << "|| " << this->date_of_journey;
        space(20 - this->date_of_journey.length() - 1);
        cout << "| " << this->train_no;
        space(14 - this->train_no.length() - 1);
        cout << "| " << this->class_name;
        space(8 - this->class_name.length() - 1);
        cout << "| " << this->user_id;
        space(17 - this->user_id.length() - 1);
        cout << "|" << endl;
        cout << "+---------------------------------------------------------------+" << endl
             << endl;
    }

    void show_last_ticket()
    {
        cout << this->train_no << " " << this->user_id << endl;
    }
};

class Logged_User
{
public:
    string user_id, name, username, contact;
    string user_bookings[50][5]; //["train number", "class_name", "date of journey", "status","no of seat"]
    int booking_counter = 0;

    Logged_User()
    {
        this->username = false;
        this->name = false;
        this->contact = false;
        this->user_id = false;
    }

    void set_booking_data(string train_no, string class_name, string date_of_journey, string status, string no_of_seat = "1")
    {
        this->user_bookings[this->booking_counter][0] = train_no;
        this->user_bookings[this->booking_counter][1] = class_name;
        this->user_bookings[this->booking_counter][2] = date_of_journey;
        this->user_bookings[this->booking_counter][2] = status;
        this->user_bookings[this->booking_counter][3] = no_of_seat;
        this->booking_counter += 1;
    }

    void Logout()
    {
        this->username = false;
        this->name = false;
        this->contact = false;
        this->user_id = false;

        cout << "User Successfully Logged Out: ->";
        getch();
    }

    void set_Logged_user(string user_id)
    {
        ifstream fin;
        fin.open("Users_Rec.txt");

        string ch;
        ch = fin.get();

        string temp_id;
        string username;
        string name;
        string contact;

        int comma_value = 0;

        while (!fin.eof())
        {
            if (ch == "-")
            {
                ch = fin.get();
            }
            if (ch == "|")
            {
                if (user_id == temp_id)
                {
                    this->username = username;
                    this->name = name;
                    this->contact = contact;
                    this->user_id = user_id;
                    break;
                }
                else
                {
                    ch = fin.get();
                    ch = fin.get();
                    comma_value = 0;
                    temp_id = "";
                    username = "";
                    name = "";
                    contact = "";
                    continue;
                }
            }

            if (ch == ",")
            {
                comma_value++;
                ch = fin.get();
                continue;
            }
            if (comma_value == 0)
            {
                temp_id += ch;
            }
            if (comma_value == 1)
            {
                username += ch;
            }
            if (comma_value == 2)
            {
                name += ch;
            }
            if (comma_value == 5)
            {
                contact += ch;
            }
            ch = fin.get();
        }
    }

} logged_user;

// --------------------------------------------------------Utility Functions--------------------------------------------------------

string to_lower(string state)
{
    string newString = "";
    for (int i = 0; i < state.length(); i++)
    {
        newString += tolower(state[i]);
    }
    return newString;
}
string to_upper(string state)
{
    string newString = "";
    for (int i = 0; i < state.length(); i++)
    {
        newString += toupper(state[i]);
    }
    return newString;
}

void space(int n)
{
    if (n > 0)
        for (int i = 0; i < n; i++)
            cout << " ";
}
//Admin Related
void create_new_route_header()
{
    cout << "+===========================================+" << endl;
    cout << "|            Create New Route               |" << endl;
    cout << "+===========================================+" << endl;
    cout << "+==================================================================================================================+" << endl;
    cout << "|        Train Name        ";
    cout << "|        Boarding Location      ";
    cout << "|        Destination        ";
    cout << "|        Train Number       |" << endl;
    cout << "+==================================================================================================================+" << endl;
}
void route_header()
{
    cout << "+===========================================+" << endl;
    cout << "|                  Route                    |" << endl;
    cout << "+===========================================+" << endl;
    cout << "+=========================================================================================================================+" << endl;
    cout << "| SrNo ";
    cout << "|        Train Name        ";
    cout << "|        Boarding Location      ";
    cout << "|        Destination        ";
    cout << "|        Train Number       |" << endl;
    cout << "+=========================================================================================================================+" << endl;
}
void create_train_chart()
{
    cout << "+===========================================+" << endl;
    cout << "|          Create Train Chart               |" << endl;
    cout << "+===========================================+" << endl;
    cout << "+=============================================================+" << endl;
    cout << "| Class(AC123, SL, CC) ";
    cout << "|   Total Seat  ";
    cout << "|   Fair Charge(Rs.)   |" << endl;
    cout << "+=============================================================+" << endl;
}

void train_chart()
{
    cout << "+===========================================+" << endl;
    cout << "|              Train Chart                  |" << endl;
    cout << "+===========================================+" << endl;
    cout << "+========================================================================================+" << endl;
    cout << "| SrNO ";
    cout << "| Class(AC123, SL, CC) ";
    cout << "|   Total Seat  ";
    cout << "|   Available Seat  ";
    cout << "|   Fair Charge(Rs.)   |" << endl;
    cout << "+========================================================================================+" << endl;
}
void retrieve_user_data()
{

    ifstream fin;
    fin.open("Users_Rec.txt");

    string ch;
    ch = fin.get();

    string temp_id;
    string username;
    string name;
    string gender;
    string DOB;
    string contact;

    int comma_value = 0;

    while (!fin.eof())
    {
        if (ch == "-")
        {
            ch = fin.get();
        }
        if (ch == "|")
        {
            cout << "+----------------------------------------------------------------------------------------------------------+" << endl;
            cout << "|        " << username;
            space(26 - username.length() - 8);
            cout << "|         " << name;
            space(31 - name.length() - 9);
            cout << "|  " << gender;
            space(8 - gender.length() - 2);
            cout << "|   " << DOB;
            space(19 - DOB.length() - 3);
            cout << "|     " << contact;
            space(18 - contact.length() - 5);
            cout << "|" << endl;
            cout << "+----------------------------------------------------------------------------------------------------------+" << endl;

            ch = fin.get();
            ch = fin.get();
            comma_value = 0;
            temp_id = "";
            username = "";
            name = "";
            contact = "";
            gender = "";
            DOB = "";
            continue;
        }

        if (ch == ",")
        {
            comma_value++;
            ch = fin.get();
            continue;
        }
        if (comma_value == 0)
        {
            temp_id += ch;
        }
        if (comma_value == 1)
        {
            username += ch;
        }
        if (comma_value == 2)
        {
            name += ch;
        }
        if (comma_value == 3)
        {
            gender += ch;
        }
        if (comma_value == 4)
        {
            DOB += ch;
        }
        if (comma_value == 5)
        {
            contact += ch;
        }
        ch = fin.get();
    }
}
//User Related
void register_user_header()
{

    cout << "+===========================================+" << endl;
    cout << "|              Register User                |" << endl;
    cout << "+===========================================+" << endl;
    cout << "+==========================================================================================================+" << endl;
    cout << "|         Username         ";
    cout << "|              Name             ";
    cout << "| Gender ";
    cout << "|   Date of Birth   ";
    cout << "|     Mobile No.   |" << endl;
    cout << "+==========================================================================================================+" << endl;
}

void register_user_header_2()
{

    cout << "+===================================================+" << endl;
    cout << "|         Password        ";
    cout << "|     Confirm Password    |" << endl;
    cout << "+===================================================+" << endl;
}

void login_user_header()
{

    cout << "+===========================================+" << endl;
    cout << "|                Login User                 |" << endl;
    cout << "+===========================================+" << endl;
    cout << "+=======================================================================+" << endl;
    cout << "|              Username             ";
    cout << "|              password             |" << endl;
    cout << "+=======================================================================+" << endl;
}

void booking_user_head()
{

    cout << "+===========================================+" << endl;
    cout << "|             Passengers Detail             |" << endl;
    cout << "+===========================================+" << endl;
    cout << "+==================================================================+" << endl;
    cout << "|              Name             ";
    cout << "| age ";
    cout << "|   Date of Birth   ";
    cout << "| Gender |" << endl;
    cout << "+==================================================================+" << endl;
}

//train upload and retrieve functions

void upload_train_data(Train *temp_train)
{

    ofstream fout;
    fout.open("Routes.txt", ios::app);

    while (fout)
    {
        fout << temp_train->Name << "," << temp_train->from << "," << temp_train->to << "," << temp_train->Train_no << "|\n";
        break;
    }
}
void upload_train_status(Train *train_temp_array[], int *counter)
{

    fstream fin;
    fin.open("Train_chart.txt");

    string ch;

    while (fin)
    {
        for (int i = 0; i < *counter; i++)
        {
            fin << "-" << train_temp_array[i]->Train_no << ":\n";
            for (int j = 0; j < train_temp_array[i]->status_counter; j++)
            {
                fin << train_temp_array[i]->train_status_array[j][0] << ",";
                fin << train_temp_array[i]->train_status_array[j][1] << ",";
                fin << train_temp_array[i]->train_status_array[j][2] << ",";
                fin << train_temp_array[i]->train_status_array[j][3] << "|" << endl;
            }
        }

        break;
    }
}

void upload_booking_data(Booking *booking_array[], int *counter)
{

    fstream fin;
    fin.open("User_chart.txt", ios::in | ios::out | ios::app);

    string ch;

    while (fin)
    {
        fin << "-" << booking_array[*counter - 1]->user_id << ","
            << booking_array[*counter - 1]->train_no << ","
            << booking_array[*counter - 1]->class_name << ","
            << booking_array[*counter - 1]->date_of_journey << ","
            << booking_array[*counter - 1]->status << ","
            << booking_array[*counter - 1]->no_of_seat << "|" << endl;

        cout << "Hello" << endl;
        cout << booking_array[*counter - 1]->user_counter << endl;

        for (int j = 0; j < booking_array[*counter - 1]->user_counter; j++)
        {
            fin << booking_array[*counter - 1]->Booking_users[j][0] << ",";
            fin << booking_array[*counter - 1]->Booking_users[j][1] << ",";
            fin << booking_array[*counter - 1]->Booking_users[j][2] << ",";
            fin << booking_array[*counter - 1]->Booking_users[j][3] << "|" << endl;
        }
        break;
    }
}

int retrieve_booking_data(Booking *booking_array[])
{

    string user_id, train_no, class_name, date_of_journey, status, no_of_seat, ch;
    string name, dob, age, gender;
    int counter = 0, sub_counter = 0, user_detail_filling = 0, comma_count1 = 0, comma_count2 = 0;
    ifstream fin;
    fin.open("User_chart.txt");
    ch = fin.get();

    while (!fin.eof())
    {
        if (ch == "-")
        {
            user_id = "";
            train_no = "";
            class_name = "";
            date_of_journey = "";
            status = "";
            no_of_seat = "";

            user_detail_filling = 0;
            comma_count1 = 0;

            ch = fin.get();
            continue;
        }
        else if (ch == "|")
        {
            if (user_detail_filling == 0)
            {
                Booking *new_booking = new Booking();
                // cout << user_id << train_no << class_name << date_of_journey << status << no_of_seat << endl;
                new_booking->set_booking_detail(user_id, train_no, class_name, date_of_journey, status, no_of_seat);

                // reading user booking data
                ch = fin.get();
                ch = fin.get();

                while (!fin.eof())
                {

                    if (ch == "-")
                    {
                        booking_array[counter++] = new_booking;
                        break;
                    }
                    if (ch == "|")
                    {
                        new_booking->set_booking_user(name, dob, age, gender);
                        name = "";
                        dob = "";
                        age = "";
                        gender = "";
                        comma_count2 = 0;
                        ch = fin.get();
                        ch = fin.get();
                    }
                    if (ch == ",")
                    {
                        comma_count2++;
                        ch = fin.get();
                    }
                    if (ch != "," && ch != "-" && ch != "|")
                    {
                        if (comma_count2 == 0)
                        {
                            name += ch;
                        }
                        else if (comma_count2 == 1)
                        {
                            dob += ch;
                        }
                        else if (comma_count2 == 2)
                        {
                            age += ch;
                        }
                        else if (comma_count2 == 3)
                        {
                            gender += ch;
                        }
                        ch = fin.get();
                    }
                }
            }
        }
        else
        {
            if (ch == ",")
            {
                comma_count1++;
                ch = fin.get();
            }
            if (comma_count1 == 0)
            {
                user_id += ch;
            }
            if (comma_count1 == 1)
            {
                train_no += ch;
            }
            if (comma_count1 == 2)
            {
                class_name += ch;
            }
            if (comma_count1 == 3)
            {
                date_of_journey += ch;
            }
            if (comma_count1 == 4)
            {
                status += ch;
            }
            if (comma_count1 == 5)
            {
                no_of_seat += ch;
            }
            ch = fin.get();
        }
    }
    return counter;
}

void retrieve_train_status(Train *train_array[], int counter)
{

    // get data from file
    // insert into train object inside the array with pointer
    string temp_train_nu = "";
    int get_number = 1;

    fstream fin;
    fin.open("Train_chart.txt");

    string ch;
    ch = fin.get();

    while (!fin.eof())
    {
        // getTrain number

        if (ch == "-")
        {
            ch = fin.get();
            temp_train_nu = "";
            get_number = 1;
        }
        else if (get_number == 1 && ch != ":")
        {
            temp_train_nu += ch;
            ch = fin.get();
        }
        else if (ch == ":")
        {
            // cout << temp_train_nu;
            // train number store complete
            for (int i = 0; i < counter; i++)
            {
                if (train_array[i]->Train_no == temp_train_nu)
                {

                    ch = fin.get(); //---> next line to train number;
                    ch = fin.get(); //---> next line to train number;
                    // train number matched
                    string class_name = "", total_seat = "", available = "", fare_charge = "";
                    int comma_counter = 0;

                    while (!fin.eof())
                    {
                        if (ch == "-")
                        {
                            get_number = 0;
                            break;
                        }

                        if (ch == "|")
                        {
                            // save to train object
                            // cout << class_name << " " << total_seat << " " << fare_charge << " " << available << endl;
                            train_array[i]->set_train_status(class_name, total_seat, fare_charge, available);

                            // cout << train_array[i]->Name << " have any record" << endl;
                            ch = fin.get();
                            ch = fin.get();
                            class_name = "", total_seat = "", available = "", fare_charge = "";
                            comma_counter = 0;
                            continue;
                        }
                        else if (ch == ",")
                        {
                            comma_counter++;
                            ch = fin.get();
                            continue;
                        }
                        else
                        {
                            if (comma_counter == 0)
                            {
                                class_name += ch;
                            }
                            else if (comma_counter == 1)
                            {
                                total_seat += ch;
                            }
                            else if (comma_counter == 2)
                            {
                                available += ch;
                            }
                            else if (comma_counter == 3)
                            {
                                fare_charge += ch;
                            }
                            ch = fin.get();
                        }
                    }
                    break;
                }
                else
                {

                    // train number not matched
                    // cout << train_array[i]->Name << " don't have any record" << endl;
                }
            }
        }
    }
}

int retrieve_train_data(Train *train_array[])
{
    string name = "", from = "", to = "", number = "", ch;

    int counter = 0, sub_counter = 0;
    ifstream fin;
    fin.open("Routes.txt");
    ch = fin.get();
    while (!fin.eof())
    {
        if (ch == "|")
        {
            Train *train_pointer = new Train(name, from, to, number);
            // train_pointer->get_train_data();
            train_array[counter++] = train_pointer;

            sub_counter = 0;
            ch = fin.get();
            ch = fin.get();
            name = "", from = "", to = "", number = "";
            continue;
        }
        if (ch == ",")
        {
            ch = fin.get();
            sub_counter++;
            continue;
        }
        if (sub_counter == 0)
        {
            name += ch;
        }
        else if (sub_counter == 1)
        {
            from += ch;
        }
        else if (sub_counter == 2)
        {
            to += ch;
        }
        else if (sub_counter == 3)
        {
            number += ch;
        }
        ch = fin.get();
    }
    return counter;
}

void make_train_chart(Train *train_array[], int *counter)
{

    string class_name;
    string total_seats;
    string fare_charge;
    string to_save;

    system("cls");

    create_train_chart();
    cout << "Enter Class name (AC123, SL, CC): ";
    cin >> class_name;
    class_name = to_upper(class_name);

    system("cls");

    create_train_chart();
    cout << "+-------------------------------------------------------------+" << endl;
    cout << "|        " << class_name;
    space(22 - class_name.length() - 8);
    cout << "|" << endl;
    cout << "+-------------------------------------------------------------+" << endl
         << endl;

    cout << "Enter the number of Seats that class can hold: ";
    cin >> total_seats;

    system("cls");

    create_train_chart();
    cout << "+-------------------------------------------------------------+" << endl;
    cout << "|        " << class_name;
    space(22 - class_name.length() - 8);
    cout << "|        " << total_seats;
    space(15 - total_seats.length() - 8);
    cout << "|" << endl;
    cout << "+-------------------------------------------------------------+" << endl
         << endl;

    cout << "Enter the fare charge per seat: ";
    cin >> fare_charge;

    while (1)
    {
        system("cls");

        create_train_chart();
        cout << "+-------------------------------------------------------------+" << endl;
        cout << "|        " << class_name;
        space(22 - class_name.length() - 8);
        cout << "|        " << total_seats;
        space(15 - total_seats.length() - 8);
        cout << "|        " << fare_charge;
        space(22 - fare_charge.length() - 8);
        cout << "|" << endl;
        cout << "+-------------------------------------------------------------+" << endl
             << endl;

        cout << "Do you want to Save-> (Y/N): ";
        cin >> to_save;
        if (to_save == "y" || to_save == "Y")
        {
            train_array[*counter]->set_train_status(class_name, total_seats, fare_charge);
            break;
        }
        else if (to_save == "n" || to_save == "N")
        {
            cout << "Train status dropped successfully: Press Enter to continue-> ";
            break;
            getch();
        }
        else
        {
            cout << "Enter a valid input -> Press Enter: ";
            getch();
        }
    }
    string to_app;
    while (1)
    {
        cout << endl
             << endl
             << "Do you want to append more chart(Y/N): ";

        cin >> to_app;
        if (to_app == "Y" || to_app == "y")
        {
            make_train_chart(train_array, counter);
            break;
        }
        else if (to_app == "N" || to_app == "n")
        {
            break;
        }
        cout << "Enter valid input : Press Enter to continue-> ";
        getch();
    }
}

//person upload and retrieve functions
void upload_user_data(Person temp_person)
{

    ofstream fout;
    fout.open("Users_Rec.txt", ios::app);

    while (fout)
    {
        fout << "-" << temp_person.uid << "," << temp_person.username << "," << temp_person.Name << "," << temp_person.gender << "," << temp_person.DOB << "," << temp_person.contact << "|\n";
        break;
    }
}

void upload_user_key(Person temp_person)
{

    ofstream fout;
    fout.open("Users_Key.txt", ios::app);

    while (fout)
    {
        fout << "-" << temp_person.uid << "," << temp_person.password << "|\n";
        break;
    }
}

int booking_process(Train *train_array[], int *data_counter, Booking *booking_array[], int *booking_counter, int compart_index, int train_SrNo)
{

    string doj;
    int no_of_seat;

    system("cls");
    cout << "+===========================================+" << endl;
    cout << "|             New Booking Status            |" << endl;
    cout << "+===========================================+" << endl
         << endl;

    cin.ignore();
    cout << "Enter Date od Journey(DD MM YYYY): ->";
    getline(cin, doj);

    system("cls");
    cout << "+===========================================+" << endl;
    cout << "|             New Booking Status            |" << endl;
    cout << "+===========================================+" << endl
         << endl;

    cout << "Enter number of passenger you want to book ticket: ->";
    cin >> no_of_seat;

    Booking *new_booking = new Booking();
    new_booking->set_booking_detail(logged_user.user_id, train_array[train_SrNo - 1]->Train_no, train_array[train_SrNo - 1]->train_status_array[compart_index - 1][0], doj, "Active", to_string(no_of_seat));

    int n = no_of_seat;
    // int f = no_of_seat;
    while (n--)
    {
        string name, age, dob, gender;

        system("cls");
        cout << "+===========================================+" << endl;
        cout << "|             New Booking Status            |" << endl;
        cout << "+===========================================+" << endl
             << endl;

        route_header();
        train_array[train_SrNo - 1]->get_train_data(to_string(1));
        cout << endl
             << endl;
        train_chart();
        train_array[train_SrNo - 1]->get_train_status(compart_index - 1);

        cout << "Above is you booking status ->" << endl
             << endl
             << endl;

        cout << "Enter Passenger " << no_of_seat - n << " details->" << endl;
        booking_user_head();

        cin.ignore();
        cout << "Enter Passenger's Name: -> ";
        getline(cin, name);

        system("cls");
        cout << "+===========================================+" << endl;
        cout << "|             New Booking Status            |" << endl;
        cout << "+===========================================+" << endl
             << endl;

        route_header();
        train_array[train_SrNo - 1]->get_train_data(to_string(1));
        cout << endl
             << endl;
        train_chart();
        train_array[train_SrNo - 1]->get_train_status(compart_index - 1);

        cout << "Above is you booking status ->" << endl
             << endl
             << endl;

        cout << "Enter Passenger " << no_of_seat - n << " details->" << endl;
        booking_user_head();

        cout << "+------------------------------------------------------------------+" << endl;
        cout << "|        " << name;
        space(31 - name.length() - 8);
        cout << "|" << endl;
        cout << "+------------------------------------------------------------------+" << endl
             << endl;

        cout << "Enter Passenger's age: -> ";
        cin >> age;

        system("cls");
        cout << "+===========================================+" << endl;
        cout << "|             New Booking Status            |" << endl;
        cout << "+===========================================+" << endl
             << endl;

        route_header();
        train_array[train_SrNo - 1]->get_train_data(to_string(1));
        cout << endl
             << endl;
        train_chart();
        train_array[train_SrNo - 1]->get_train_status(compart_index - 1);

        cout << "Above is you booking status ->" << endl
             << endl
             << endl;

        cout << "Enter Passenger " << no_of_seat - n << " details->" << endl;
        booking_user_head();

        cout << "+------------------------------------------------------------------+" << endl;
        cout << "|        " << name;
        space(31 - name.length() - 8);
        cout << "| " << age;
        space(5 - age.length() - 1);
        cout << "|" << endl;

        cout << "+------------------------------------------------------------------+" << endl
             << endl;

        cin.ignore();
        cout << "Enter Passenger's date of birth (DD MM YYYY):-> ";
        getline(cin, dob);

        system("cls");
        cout << "+===========================================+" << endl;
        cout << "|             New Booking Status            |" << endl;
        cout << "+===========================================+" << endl
             << endl;

        route_header();
        train_array[train_SrNo - 1]->get_train_data(to_string(1));
        cout << endl
             << endl;
        train_chart();
        train_array[train_SrNo - 1]->get_train_status(compart_index - 1);

        cout << "Above is you booking status ->" << endl
             << endl
             << endl;

        cout << "Enter Passenger " << no_of_seat - n << " details->" << endl;
        booking_user_head();

        cout << "+------------------------------------------------------------------+" << endl;
        cout << "|        " << name;
        space(31 - name.length() - 8);
        cout << "| " << age;
        space(5 - age.length() - 1);
        cout << "|   " << dob;
        space(19 - dob.length() - 3);
        cout << "|" << endl;

        cout << "+------------------------------------------------------------------+" << endl
             << endl;

        cout << "Enter Passenger's gender: (M/F)-> ";
        cin >> gender;

        system("cls");
        cout << "+===========================================+" << endl;
        cout << "|             New Booking Status            |" << endl;
        cout << "+===========================================+" << endl
             << endl;

        route_header();
        train_array[train_SrNo - 1]->get_train_data(to_string(1));
        cout << endl
             << endl;
        train_chart();
        train_array[train_SrNo - 1]->get_train_status(compart_index - 1);

        cout << "Above is you booking status ->" << endl
             << endl
             << endl;

        cout << "Enter Passenger " << no_of_seat - n << " details->" << endl;
        booking_user_head();

        cout << "+------------------------------------------------------------------+" << endl;
        cout << "|        " << name;
        space(31 - name.length() - 8);
        cout << "| " << age;
        space(5 - age.length() - 1);
        cout << "|   " << dob;
        space(19 - dob.length() - 3);
        cout << "| " << gender;
        space(8 - gender.length() - 1);
        cout << "|" << endl;

        cout << "+------------------------------------------------------------------+" << endl
             << endl;

        cout << "Do you want to save this passenger (Y/N):";
        string to_save;
        cin >> to_save;
        if (to_lower(to_save) == "y")
        {
            new_booking->set_booking_user(name, dob, age, gender);
            continue;
        }
        else if (to_lower(to_save) == "n")
        {
            n++;
            continue;
        }
    }

    string to_save;
    cout << "Do you want to comfirm you booking(Y/N):";
    cin >> to_save;
    if (to_lower(to_save) == "y")
    {
        train_array[train_SrNo - 1]->booked_value(compart_index - 1, no_of_seat);
        booking_array[*booking_counter++] = new_booking;
        upload_train_status(train_array, data_counter);
        return 1;
    }
    else if (to_lower(to_save) == "n")
        return 0;

    return 0;
}

// void get_booking_data(Person *person_array[], ){ //File handeling

//         string temp_train_nu="";
//         int get_number = 0;

//         fstream fin;
//         fin.open("User_chart.txt");

//         string ch;
//         ch = fin.get();

//         while(!fin.eof()){
//             // getTrain number

//             if(ch == "-"){
//                 ch = fin.get();
//                 temp_train_nu="";
//                 get_number = 1;
//             }
//             else if(get_number == 1 && ch != ":"){
//                 temp_train_nu += ch;
//                 ch = fin.get();
//             }
//             else if(ch == ":"){
//                 // cout << temp_train_nu;
//                 // train number store complete
//                 for(int i=0; i<counter; i++){
//                     if(train_array[i]->Train_no == temp_train_nu){

//                         ch = fin.get();//---> next line to train number;
//                         ch = fin.get();//---> next line to train number;
//                         // train number matched
//                         string class_name ="", total_seat = "", available = "", fare_charge = "";
//                         int comma_counter = 0;

//                         while(!fin.eof()){
//                             if(ch == "-"){
//                                 get_number = 0;
//                                 break;
//                             }

//                             if(ch=="|"){
//                                 // save to train object
//                                 // cout << class_name << " " << total_seat << " " << fare_charge << " " << available << endl;
//                                 train_array[i]->set_train_status(class_name, total_seat, fare_charge, available);

//                                 ch = fin.get();
//                                 ch = fin.get();
//                                 class_name ="", total_seat = "", available = "", fare_charge = "";
//                                 comma_counter = 0;
//                                 continue;
//                             }
//                             else if(ch==","){
//                                 comma_counter++;
//                                 ch = fin.get();
//                                 continue;
//                             }
//                             else{
//                                 if(comma_counter == 0){
//                                     class_name += ch;
//                                 }
//                                 else if(comma_counter == 1){
//                                     total_seat += ch;
//                                 }
//                                 else if(comma_counter == 2){
//                                     available += ch;
//                                 }
//                                 else if(comma_counter == 3){
//                                     fare_charge += ch;
//                                 }
//                                 ch=fin.get();
//                             }

//                         }
//                         break;
//                     }
//                     else{
//                         // train number not matched
//                         // cout << train_array[i]->Name << " don't have any record" << endl;
//                     }
//                 }
//             }
//             // retrieve curresponding class elements
//         }
//     }

int retrieve_person_data(Person *person_array[])
{
    string uid = "", name = "", gender = "", dob = "", username = "", contact = "", ch;

    int counter = 0, sub_counter = 0;
    ifstream fin;
    fin.open("Users_Rec.txt");
    ch = fin.get();
    while (!fin.eof())
    {
        if (ch == "|")
        {
            Person *train_pointer = new Person(username, name, gender, dob, contact, uid);
            // train_pointer->get_train_data();
            person_array[counter++] = train_pointer;

            sub_counter = 0;
            ch = fin.get();
            ch = fin.get();
            cout << ch << endl;
            getch();
            name = "", gender = "", dob = "", username = "", contact = "", uid = "";
            continue;
        }
        if (ch == ",")
        {
            ch = fin.get();
            sub_counter++;
            continue;
        }
        if (sub_counter == 0)
        {
            uid += ch;
        }
        else if (sub_counter == 1)
        {
            username += ch;
        }
        else if (sub_counter == 2)
        {
            name += ch;
        }
        else if (sub_counter == 3)
        {
            gender += ch;
        }
        else if (sub_counter == 4)
        {
            dob += ch;
        }
        else if (sub_counter == 5)
        {
            contact += ch;
        }
        ch = fin.get();
    }
    return counter;
}

int search_password(string id, string password)
{

    ifstream fin;
    fin.open("Users_Key.txt");

    string ch;
    ch = fin.get();

    string temp_id = "";
    string temp_password = "";

    int comma_value = 0;

    while (!fin.eof())
    {
        if (ch == "-")
        {
            ch = fin.get();
            continue;
        }
        if (ch == "|")
        {

            if (password == temp_password && temp_id == id)
            {
                // cout << "Password Matched" << endl;
                //User Logged
                logged_user.set_Logged_user(id);
                return 4;
            }
            else
            {
                ch = fin.get();
                comma_value = 0;
                temp_password = "";
                temp_id = "";
                while (!fin.eof())
                {
                    if (ch == "-")
                        break;
                    ch = fin.get();
                }
                continue;
            }
        }

        if (ch == "," && comma_value == 0)
        {
            comma_value = 1;
            ch = fin.get();
            continue;
        }
        if (comma_value == 0)
        {
            temp_id += ch;
        }
        if (comma_value == 1)
        {
            temp_password += ch;
        }
        ch = fin.get();
    }

    cout << "Incorrect Password " << endl;
    return 0;
}

int search_username(string username, string password)
{

    ifstream fin;
    fin.open("Users_Rec.txt");

    string ch;
    ch = fin.get();

    string temp_id;
    string temp_username;

    int comma_value = 0;

    while (!fin.eof())
    {

        if (ch == "," && comma_value == 1)
        {
            // cout << temp_username << ", " << temp_id << endl;
            if (to_lower(username) == temp_username)
            {
                // cout << "Username Matched" << endl;
                return search_password(temp_id, password);
            }

            while (!fin.eof())
            {
                ch = fin.get();
                if (ch == "|")
                {
                    ch = fin.get();
                    comma_value = 0;
                    temp_username = "";
                    temp_id = "";
                }
                if (ch == "-")
                {
                    ch = fin.get();
                    break;
                }
            }
        }

        if (ch == "," && comma_value == 0)
        {
            comma_value = 1;
            ch = fin.get();
            continue;
        }
        if (comma_value == 0)
        {

            temp_id += ch;
        }
        if (comma_value == 1)
        {
            temp_username += ch;
        }
        ch = fin.get();
    }

    cout << "No User found with given username!" << endl;
    return 0;
}

int search_train_number(string Train_no, Train *train_array[], int *array_counter)
{

    for (int i = 0; i < *array_counter; i++)
    {
        if (train_array[i]->Train_no == Train_no)
            return 0; //Train number match (Try another);
    }
    return 1; //Train number unmatch (allowed to initialize new train route);
}

//----------------------------------Booking----------------------------------

void Book_Ticket(Train *train_array[], int *data_counter, Booking *booking_array[], int *booking_counter)
{

    //sare routes dikhenge
    int compart_index;
    int train_SrNo;
    system("cls");
    cout << "+===========================================+" << endl;
    cout << "|                New Booking                |" << endl;
    cout << "+===========================================+" << endl
         << endl;

    *data_counter = retrieve_train_data(train_array);
    route_header();
    for (int i = 0; i < *data_counter; i++)
    {
        train_array[i]->get_train_data(to_string(i + 1));
    }

    cout << endl
         << endl
         << "Enter the SrNo of the Train you want Booking for:-> ";
reInput:
    cin >> train_SrNo;
    retrieve_train_status(train_array, *data_counter);
    cout << "+===========================================+" << endl;
    cout << "|                New Booking                |" << endl;
    cout << "+===========================================+" << endl
         << endl;
    system("cls");
    if (train_SrNo <= *data_counter && train_SrNo > 0)
    {
        train_chart();
        train_array[train_SrNo - 1]->get_train_status();
        cout << endl
             << "Enter the serial no. to book the compartment you want";
        cin >> compart_index;
        int to_save = booking_process(train_array, data_counter, booking_array, booking_counter, compart_index, train_SrNo);
        *booking_counter = 1 + *booking_counter;
        if (to_save)
        {
            system("cls");
            booking_array[*booking_counter - 1]->show_tickets();
            upload_booking_data(booking_array, booking_counter);
            cout << "Your data saved Successfully: ";
            getch();
        }
    }
    else
    {
        system("cls");
        cout << "Enter a valid Serial number or '0': " << endl;
        goto reInput;
    }

    cout << "Press Enter to go back to Profile Menu:";
    getch();

    // 1 routes vo select karega

    //fir train status dikhega "ac1"etc

    //fir vo train status select karega

    //
}

//----------------------------------creating new User--------------------------------------------------

Person resgister_new_user()
{ // From User Menu
    string name, username, gender, DOB, contact, to_save, password, c_password;
    system("cls");

    register_user_header();
    cin.ignore();
    cout << "Enter Train Username: ";
    getline(cin, username);

    system("cls");

    register_user_header();
    cout << "+----------------------------------------------------------------------------------------------------------+" << endl;
    cout << "|        " << username;
    space(26 - username.length() - 8);
    cout << "|" << endl;
    cout << "+----------------------------------------------------------------------------------------------------------+" << endl
         << endl;

    cout << "Enter your name: ";
    getline(cin, name);

    system("cls");

    register_user_header();
    cout << "+----------------------------------------------------------------------------------------------------------+" << endl;
    cout << "|        " << username;
    space(26 - username.length() - 8);
    cout << "|         " << name;
    space(31 - name.length() - 9);
    cout << "|" << endl;
    cout << "+----------------------------------------------------------------------------------------------------------+" << endl
         << endl;

    cout << "Gender (M/F): ";
    cin >> gender;

    system("cls");

    register_user_header();
    cout << "+----------------------------------------------------------------------------------------------------------+" << endl;
    cout << "|        " << username;
    space(26 - username.length() - 8);
    cout << "|         " << name;
    space(31 - name.length() - 9);
    cout << "|    " << gender;
    space(3);
    cout << "|" << endl;
    cout << "+----------------------------------------------------------------------------------------------------------+" << endl
         << endl;

    cin.ignore();
    cout << "Enter your Date of Birth (DD MM YYYY): ";
    getline(cin, DOB);

    system("cls");

    register_user_header();
    cout << "+----------------------------------------------------------------------------------------------------------+" << endl;
    cout << "|        " << username;
    space(26 - username.length() - 8);
    cout << "|         " << name;
    space(31 - name.length() - 9);
    cout << "|  " << gender;
    space(8 - gender.length() - 2);
    cout << "|   " << DOB;
    space(19 - DOB.length() - 3);
    cout << "|" << endl;
    cout << "+----------------------------------------------------------------------------------------------------------+" << endl
         << endl;

    cout << "Enter your mobile number: ";
    cin >> contact;

re_enter_password:
    system("cls");

    register_user_header();
    cout << "+----------------------------------------------------------------------------------------------------------+" << endl;
    cout << "|        " << username;
    space(26 - username.length() - 8);
    cout << "|         " << name;
    space(31 - name.length() - 9);
    cout << "|  " << gender;
    space(8 - gender.length() - 2);
    cout << "|   " << DOB;
    space(19 - DOB.length() - 3);
    cout << "|     " << contact;
    space(18 - contact.length() - 5);
    cout << "|" << endl;
    cout << "+----------------------------------------------------------------------------------------------------------+" << endl;

    register_user_header_2();

    cout << "Create a password: ";
    cin >> password;

    system("cls");

    register_user_header();
    cout << "+----------------------------------------------------------------------------------------------------------+" << endl;
    cout << "|        " << username;
    space(26 - username.length() - 8);
    cout << "|         " << name;
    space(31 - name.length() - 9);
    cout << "|  " << gender;
    space(8 - gender.length() - 2);
    cout << "|   " << DOB;
    space(19 - DOB.length() - 3);
    cout << "|     " << contact;
    space(18 - contact.length() - 5);
    cout << "|" << endl;
    cout << "+----------------------------------------------------------------------------------------------------------+" << endl;

    register_user_header_2();
    cout << "+---------------------------------------------------+" << endl;
    cout << "|        " << password;
    space(25 - password.length() - 8);
    cout << "|" << endl;
    cout << "+---------------------------------------------------+" << endl
         << endl;

    cout << "Confirm password: ";
    cin >> c_password;

    if (c_password != password)
    {
        cout << "Password not Matched press Enter:-> ";
        getch();
        cout << endl;
        goto re_enter_password;
    }
    system("cls");

    register_user_header();
    cout << "+----------------------------------------------------------------------------------------------------------+" << endl;
    cout << "|        " << username;
    space(26 - username.length() - 8);
    cout << "|         " << name;
    space(31 - name.length() - 9);
    cout << "|  " << gender;
    space(8 - gender.length() - 2);
    cout << "|   " << DOB;
    space(19 - DOB.length() - 3);
    cout << "|     " << contact;
    space(18 - contact.length() - 5);
    cout << "|" << endl;
    cout << "+----------------------------------------------------------------------------------------------------------+" << endl;

    register_user_header_2();
    cout << "+---------------------------------------------------+" << endl;
    cout << "|        " << password;
    space(25 - password.length() - 8);
    cout << "|        " << c_password;
    space(25 - c_password.length() - 8);
    cout << "|" << endl;
    cout << "+---------------------------------------------------+" << endl
         << endl;

    cout << "Password Matched " << endl
         << endl;

    cout << "Do you want to save this data?: (Y/N)";
    while (1)
    {

        cin >> to_save;
        if (to_save == "Y" || to_save == "y")
        {

            //saving train data to a pointer
            Person temp_person(username, name, gender, DOB, contact, password);
            cout << endl
                 << "User successfully saved" << endl
                 << endl;

            upload_user_data(temp_person);
            upload_user_key(temp_person);

            cout << "Press Enter to proceed:-> ";
            getch();
            return temp_person; // returning object
        }
        else if (to_save == "N" || to_save == "n")
        {
            cout << "User Successfully droped." << endl
                 << endl;
            cout << "Press Enter to proceed:-> ";
            getch();
            cout << endl;
        }
        else
        {
            cout << "Enter a valid input (Y/N): ";
            continue;
        }
        break;
    }
    Person null_user;
    return null_user;
}

//----------------------------------------------Login User----------------------------------------------
int login_user()
{
    string username, password;
    int matched = 0, choice = 0;
    cin.ignore();

re_enter_credential:

    system("cls");

    login_user_header();
    cout << "Enter Username: ";
    cin >> username;

    system("cls");

    login_user_header();
    cout << "+-----------------------------------------------------------------------+" << endl;
    cout << "|         " << username;
    space(35 - username.length() - 9);
    cout << "|" << endl;
    cout << "+-----------------------------------------------------------------------+" << endl
         << endl;

    cout << "Enter Password: ";
    cin >> password;

    system("cls");

    login_user_header();
    cout << "+-----------------------------------------------------------------------+" << endl;
    cout << "|         " << username;
    space(35 - username.length() - 9);
    cout << "|         " << password;
    space(35 - password.length() - 9);
    cout << "|" << endl;
    cout << "+-----------------------------------------------------------------------+" << endl
         << endl;

    // searching username and password

    matched = search_username(username, password);
    if (!matched)
    {
    login_failed:

        cout << "\n\n+===========================================+" << endl;
        cout << "|               Login Failed                |" << endl;
        cout << "+===========================================+" << endl;
        cout << "+-------------------------------------------+" << endl;
        cout << "|   1.    Login Again                       |" << endl;
        cout << "+-------------------------------------------+" << endl;
        cout << "|   2.    Register as new User              |" << endl;
        cout << "+-------------------------------------------+" << endl;
        cout << "|   3.    Go back to User Menu              |" << endl;
        cout << "+-------------------------------------------+" << endl;
        cout << "|   4.    Go back to Main Menu              |" << endl;
        cout << "+-------------------------------------------+" << endl
             << endl;

        cout << "Enter you Choice (1-4): ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            goto re_enter_credential;
        case 2:
            return 1;
        case 3:
            return 2;
        case 4:
            return 3;
        default:
            system("cls");
            cout << "Please Make a Valid Choice->(1-4)" << endl;
            goto login_failed;
        };
    }

    //if code flow reaches here then you are logged In
    return 4;
}

//---------------------- creating new Route/creating new train------------------------------------------
void create_new_route(Train *train_array[], int *array_counter)
{ // From Admin Menu
    string name, from, to, to_save, Train_no;
    system("cls");

    create_new_route_header();
    cin.ignore();
    cout << "Enter Train Name: ";
    getline(cin, name);

    system("cls");

    create_new_route_header();
    cout << "+------------------------------------------------------------------------------------------------------------------+" << endl;
    cout << "|         " << name;
    space(26 - name.length() - 9);
    cout << "|" << endl;
    cout << "+------------------------------------------------------------------------------------------------------------------+" << endl
         << endl;

    cout << "Boarding Location: ";
    getline(cin, from);

    system("cls");

    create_new_route_header();
    cout << "+------------------------------------------------------------------------------------------------------------------+" << endl;
    cout << "|         " << name;
    space(26 - name.length() - 9);
    cout << "|        " << from;
    space(31 - from.length() - 8);
    cout << "|" << endl;
    cout << "+------------------------------------------------------------------------------------------------------------------+" << endl
         << endl;

    cout << "Destination: ";
    getline(cin, to);

re_enter_train_number:
    system("cls");

    create_new_route_header();
    cout << "+------------------------------------------------------------------------------------------------------------------+" << endl;
    cout << "|         " << name;
    space(26 - name.length() - 9);
    cout << "|        " << from;
    space(31 - from.length() - 8);
    cout << "|        " << to;
    space(27 - to.length() - 8);
    cout << "|" << endl;
    cout << "+------------------------------------------------------------------------------------------------------------------+" << endl
         << endl;

    cout << "Train Number: ";
    cin >> Train_no;

    system("cls");

    create_new_route_header();
    cout << "+------------------------------------------------------------------------------------------------------------------+" << endl;
    cout << "|         " << name;
    space(26 - name.length() - 9);
    cout << "|        " << from;
    space(31 - from.length() - 8);
    cout << "|        " << to;
    space(27 - to.length() - 8);
    cout << "|        " << Train_no;
    space(27 - Train_no.length() - 8);
    cout << "|" << endl;
    cout << "+------------------------------------------------------------------------------------------------------------------+" << endl
         << endl;

    int allow_train_number = search_train_number(Train_no, train_array, array_counter);

    if (!allow_train_number)
    {
        cout << "Train number is already exist: Press enter to type train number again->";
        getch();
        goto re_enter_train_number;
    }
    cout << "Do you want to save this data?: (Y/N)";
    while (1)
    {

        cin >> to_save;
        if (to_save == "Y" || to_save == "y")
        {

            //saving train data to a pointer
            train_array[*array_counter] = new Train(name, from, to, Train_no);

            cout << endl
                 << "Route successfully saved" << endl
                 << endl;
            cout << "Press Enter to store Status for your new Route:-> ";
            // cout << *array_counter << endl;

            getch();

            upload_train_data(train_array[*array_counter]); //Route data Uploaded

            make_train_chart(train_array, array_counter); //Train chart is stored int temp_Train.

            system("cls");
            train_chart();
            train_array[*array_counter]->get_train_status();
            break;
        }
        else if (to_save == "N" || to_save == "n")
        {
            cout << "Route Successfully droped." << endl
                 << endl;
            cout << "Press Enter to proceed:-> ";
            getch();
        }
        else
        {
            cout << "Enter a valid input (Y/N): ";
            continue;
        }
    }
}

//---------------------------------------------Train Enquiry---------------------------------------------
void train_enquiry()
{
    // search via station (from to)
    // search via train details
}

//--------------------------Admin Menu------------------------
void Admin_Menu(Train *train_array[], int *data_counter)
{

    // variable declaration
    int admin_choice = 0, onLoop = 1;

    int nested_choice = 3;
    while (onLoop)
    {

        //Loading train status
        retrieve_train_status(train_array, *data_counter);

        if (nested_choice == 4)
        {
            admin_choice = 4;
        }
        else if (nested_choice == 3)
        { // go back to admin menu && menu section
            system("cls");

            cout << "+===========================================+" << endl;
            cout << "|                Admin Menu                 |" << endl;
            cout << "+===========================================+" << endl;
            cout << "+-------------------------------------------+" << endl;
            cout << "|   1.    Create new Route                  |" << endl;
            cout << "+-------------------------------------------+" << endl;
            cout << "|   2.    Display existing Route            |" << endl;
            cout << "+-------------------------------------------+" << endl;
            cout << "|   3.    Display User details              |" << endl;
            cout << "+-------------------------------------------+" << endl;
            cout << "|   4.    Go back to Main Menu              |" << endl;
            cout << "+-------------------------------------------+" << endl
                 << endl;

            cout << "Enter your Choice: ";
            cin >> admin_choice;
        }
        else if (nested_choice == 2)
        { // Show previously stored Route
            // cout << endl << "This is your stored route----" << endl;
            admin_choice = 2;
        }
        else if (nested_choice == 1)
        { //Create new Route
            admin_choice = 1;
        }

        switch (admin_choice)
        {
        case 1:
            // system("cls");
            //Create new Route
            // if(nested_choice != 2){
            //     Train_instance = create_new_route(); // This will return a pointer of new route.
            create_new_route(train_array, data_counter);
            *data_counter = *data_counter + 1;
            // cout << "This is data counter: " << *data_counter << endl;

            upload_train_status(train_array, data_counter); //File Handeling part

            cout << "Your Data saved Successfully: Press Enter to continue";
            getch();

            system("cls");

            cout << "+===========================================+" << endl;
            cout << "|                Route Menu                 |" << endl;
            cout << "+===========================================+" << endl;
            cout << "+-------------------------------------------+" << endl;
            cout << "|   1.    Create new Route                  |" << endl;
            cout << "+-------------------------------------------+" << endl;
            cout << "|   2.    Show previously stored Route      |" << endl;
            cout << "+-------------------------------------------+" << endl;
            cout << "|   3.    Go Back to Admin Menu             |" << endl;
            cout << "+-------------------------------------------+" << endl;
            cout << "|   4.    Go back to Main Menu              |" << endl;
            cout << "+-------------------------------------------+" << endl
                 << endl;

            cout << "Enter your Choice: ";
            cin >> nested_choice;

            // t1->getValue();
            break;
        case 2:
            // "Display existing Train details";

            system("cls");
            int train_SrNo;
            *data_counter = retrieve_train_data(train_array);
            route_header();
            for (int i = 0; i < *data_counter; i++)
            {
                train_array[i]->get_train_data(to_string(i + 1));
            }

            cout << endl
                 << endl
                 << "Enter the SrNo to get Train Status or '0' to go back to Admim Menu:-> ";
        reInput:
            cin >> train_SrNo;
            if (train_SrNo == 0)
            {
                nested_choice = 3;
                break;
            }
            retrieve_train_status(train_array, *data_counter);

            system("cls");
            if (train_SrNo <= *data_counter && train_SrNo > 0)
            {
                train_chart();
                train_array[train_SrNo - 1]->get_train_status();
            }
            else
            {
                system("cls");
                cout << "Enter a valid Serial number or '0': " << endl;
                goto reInput;
            }
            cout << endl
                 << endl
                 << "Press enter to go back to previous Route-> ";
            getch();
            nested_choice = 2;
            break;
        case 3:
            cout << "Display User details" << endl;
            system("cls");
            register_user_header();
            retrieve_user_data();
            cout << "\n\nPress Enter to go back:";
            getch();
            break;
        case 4:
            cout << "Main Menu" << endl;
            onLoop = 0;
            break;
        default:
            cout << "Message: ENTER A VALID CHOICE" << endl;
            break;
        };
    }
}

//--------------------------User Menu------------------------
void User_Menu(Train *train_array[], int *data_counter, Booking *booking_array[], int *booking_counter)
{
    // menu section
    int user_choice = 0, onLoop = 1;
    int nested_choice = 2;

    while (onLoop)
    {
        if (nested_choice == 1)
        { // go to login
            user_choice = 2;
        }

        else if (nested_choice == 2)
        {
            system("cls");

            cout << "+===========================================+" << endl;
            cout << "|                 User Menu                 |" << endl;
            cout << "+===========================================+" << endl;
            cout << "+-------------------------------------------+" << endl;
            cout << "|   1.    Register new User                 |" << endl;
            cout << "+-------------------------------------------+" << endl;
            cout << "|   2.    LogIn                             |" << endl;
            cout << "+-------------------------------------------+" << endl;
            cout << "|   3.    Enquiry: Get your Train status    |" << endl;
            cout << "+-------------------------------------------+" << endl;
            cout << "|   4.    Go back to Main Menu              |" << endl;
            cout << "+-------------------------------------------+" << endl
                 << endl;

            // variable declaration
            cout << "Enter your Choice: ";
            cin >> user_choice;
        }
        else if (nested_choice == 4)
        {
            user_choice = 1; // for register
        }
        else if (nested_choice == 3)
        {
            user_choice = 4; //Go back to Main Menu
        }

        switch (user_choice)
        {
        case 1:
            resgister_new_user();
            cin.ignore();
            system("cls");
            while (1)
            {

                cout << "+===========================================+" << endl;
                cout << "|              Register Menu                |" << endl;
                cout << "+===========================================+" << endl;
                cout << "+-------------------------------------------+" << endl;
                cout << "|   1.    Login                             |" << endl;
                cout << "+-------------------------------------------+" << endl;
                cout << "|   2.    Go Back to User Menu              |" << endl;
                cout << "+-------------------------------------------+" << endl;
                cout << "|   3.    Go back to Main Menu              |" << endl;
                cout << "+-------------------------------------------+" << endl
                     << endl;

                cout << "Enter your Choice: ";
                cin >> nested_choice;
                if (nested_choice != 1 && nested_choice != 2 && nested_choice != 3)
                {
                    system("cls");
                    cout << "Make a valide choice: " << endl
                         << endl;
                    continue;
                }
                break;
            }
            break;
        case 2:
            //Login section
            system("cls");
            // 4-Logged In , 3-Main Menu, 2-User Menu 1-Register;
            int login_return;
            login_return = login_user();
            switch (login_return)
            {
            case 4:
                system("cls");
                cout << "+-----------------------+" << endl;
                cout << "| Successfully Loged In |" << endl;
                cout << "+-----------------------+" << endl;
                cout << "\n\n Press Enter to continue-> ";
                getch();

                while (1)
                {
                    if (login_return == 2)
                    {
                        break;
                    }
                    system("cls");
                    cout << "*********************************************" << endl;
                    cout << "| Hello " << logged_user.name << "";
                    space(45 - logged_user.name.length() - 9);
                    cout << "|" << endl;
                    cout << "*********************************************" << endl
                         << endl
                         << endl;

                    cout << "+===========================================+" << endl;
                    cout << "|              Profile Menu                 |" << endl;
                    cout << "+===========================================+" << endl;
                    cout << "+-------------------------------------------+" << endl;
                    cout << "|   1.    Book a Ticket                     |" << endl;
                    cout << "+-------------------------------------------+" << endl;
                    cout << "|   2.    Cancel a Ticket                   |" << endl;
                    cout << "+-------------------------------------------+" << endl;
                    cout << "|   3.    Show my Train Status              |" << endl;
                    cout << "+-------------------------------------------+" << endl;
                    cout << "|   4.    Logout                            |" << endl;
                    cout << "+-------------------------------------------+" << endl
                         << endl;

                    int nested_choice_2;
                    cout << "Enter your choice: " << endl;
                re_enter_selection:
                    cin >> nested_choice_2;
                    if (nested_choice_2 < 1 && nested_choice_2 > 4)
                    {
                        cout << "Make a valid selection:(1-4): ";
                        goto re_enter_selection;
                    }
                    switch (nested_choice_2)
                    {
                    case 1:
                        // Book Ticket
                        Book_Ticket(train_array, data_counter, booking_array, booking_counter);
                        break;

                    case 2:
                        // Cancel Ticket
                        for (int i = 0; i < *booking_counter; i++)
                        {
                            if (booking_array[i]->user_id == logged_user.user_id)
                            {
                                cout << i << "---->" << endl;
                                booking_array[i]->show_tickets();
                            }
                        }
                        cout << "select the ticket you want to cancel";
                        int a;
                        cin >> a;

                        break;

                    case 3:
                        // Show Train status
                        for (int i = 0; i < *booking_counter; i++)
                        {
                            if (booking_array[i]->user_id == logged_user.user_id)
                            {
                                cout << i << "---->" << endl;
                                booking_array[i]->show_tickets();
                            }
                        }
                        cout << "Press Enter to go back to Profile Menu:->";
                        getch();
                        break;

                    case 4:
                        // Logout
                        logged_user.Logout();
                        login_return = 2;
                        break;
                    }
                }
                break;
            case 3: //Main Menu
                nested_choice = 3;
                break;
            case 2: //User Menu
                nested_choice = 2;
                break;
            case 1: //Register
                nested_choice = 4;
                break;
            default:
                NULL;
            };
            break;
        case 3:
            cout << endl
                 << "Hello this is Enquiry" << endl;
            train_enquiry();

            break;
        case 4:
            onLoop = 0; // Go back to main menu
            break;
        default:
            cout << endl
                 << "Message: ENTER A VALID CHOICE" << endl;
            break;
        };
    }
}
// Global Variable Definition;
// int top_pointer = 0;

//-------------------------------------------------------main-------------------------------------------------------

int main()
{
    srand(time(0));
    static Train *train_array[50];
    static Person *person_array[50];
    static Booking *booking_array[50];
    // main variable declaration

    //INCLUDING FILE DATA
    // ---------------------------------------.

    int counter = retrieve_train_data(train_array);
    retrieve_train_status(train_array, counter);
    int booking_counter = retrieve_booking_data(booking_array);

    // for(int i=0; i<counter; i++){
    // train_array[i]->get_train_status();
    // }

    // ---------------------------------------
    // temp variable declaration
    int choice = 0, onLoop = 1;
    bool getMenu = true;

    // system("cls");
    // for(int i=0; i<4; i++){
    //     cout << train_array[i] << ": " ;
    //     train_array[i]->get_train_data();
    //     cout << endl;
    // }

    system("cls"); //clear screen
    cout << endl
         << endl
         << "All Data loaded Successfully Press Enter to Start: ";
    getch();

    while (onLoop)
    {
        if (getMenu)
        {
            if (choice != -1)
                system("cls"); //clear screen
            // menu section

            cout << "+===========================+" << endl;
            cout << "|         Main Menu         |" << endl;
            cout << "+===========================+" << endl;
            cout << "+---------------------------+" << endl;
            cout << "|   1.    Admin Menu        |" << endl;
            cout << "+---------------------------+" << endl;
            cout << "|   2.    User Menu         |" << endl;
            cout << "+---------------------------+" << endl;
            cout << "|   3.    Exit              |" << endl;
            cout << "+---------------------------+" << endl
                 << endl;
        }
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            //This is Admin Mode
            Admin_Menu(train_array, &counter);
            getMenu = true;
            break;
        case 2:
            cout << endl
                 << "--User Mode--" << endl;
            User_Menu(train_array, &counter, booking_array, &booking_counter);
            getMenu = true;
            break;
        case 3:
            exit(0);
            break;
        default:
            system("cls");
            cout << "Message: ENTER A VALID CHOICE" << endl;
            choice = -1;
            break;
        }
    }

    // input choice

    return 0;
}