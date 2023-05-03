// libraries included in the code
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <windows.h> //clean the terminal window
#include <conio.h>   //to use automatic enter and sleep inbuit function
#include <string>    //exit
#include <string.h>
#include <fstream>
#include <limits>
#include <stack> //to make cart system and to use in return dvd;
#include <algorithm>
// int MovieCost;
using namespace std;

// making a CART to store many DVD price at leave the at a simple
stack<int> cart;

// three prototyping
void Redirecting();
// two classes
class Customer;
// -have name
// -have age
// +type -> whether old or new
// +make payment
// +set name and age if user is new
// +signup -> creates 4 files || balance || name ||age || movie rented || overwrite user data
// +signin -> access database file and set private members
// +name && age -> return user name and age as on demand

class movie;
// an abstract class
// cart get filled in main function
// here cart prices sum gets evaluated
// defined above -> used in member function of class customer

int total()
{ // finding the total price items in the cart
    // NOTE: this actually sums the price of buying cacets
    int sum(0);
    while (!cart.empty())
    {
        sum += cart.top();
        cart.pop();
    }
    return sum;
}

class Customer
{
private:
    int Age;
    string NAME;

public:
    int TypeOfUser;                // user type is 0  if user is new else is 1
    void SignUp();                 // sets-up sign up process
    void SignIn(string);           // sets up sign in  process
    string name() { return NAME; } // if user is in need to have name
    int age() { return Age; }      // if user is in need to have age
    void setter(string);           // to set name and age
    void MakePayment();            // payment
    Customer(){};
};

void Customer::MakePayment()
{
    // payment page to depict real world buying services
    cout << "\nPRESS ENTER TO CONFIRM YOU ORDER";
    fflush(stdin);
    getchar();
    Sleep(1000);
    cout << "Redirecting you to our S.P.P.[Secure Payment Portal]" << endl;
    Redirecting();
    system("CLS");

    // processing payment page
    cout << "Processing your Payment..";
    for (int i = 0; i < 3; i++)
    {
        cout << i + 1 << " ";
        Sleep(2000);
    }
    cout << endl;
    int price = 0;
    price = total();

    // ReWriting Payment in dummy payment file as to make
    // some payments decline
    ifstream abstracting_Balance;
    abstracting_Balance.open("DATABASE\\DummyPaymentData\\" + NAME + "bal.txt");
    int balance = 0;
    abstracting_Balance >> balance;
    abstracting_Balance.close();

    if (price > balance)
    {
        cout << "OH NO!! ";
        for (int i = 0; i < 3; i++)
        {
            cout << i + 1 << " ";
            Sleep(1000);
        }
        cout << endl;
        cout << "Transaction failed" << endl;
        cout << "REASON: NOT ENOUGH BALANCE IN YOUR ACCOUNT" << endl;
    }
    else
    {
        ofstream writing_newbalance;
        writing_newbalance.open("DATABASE\\DummyPaymentData\\" + NAME + "bal.txt");
        int int_val = 0;
        cout << endl
             << "Your order is successfully placed" << endl;
        cout << "You can check a receipt that has been saved in your computer " << endl;
        int_val = balance - price;
        // pay.open("DATABASE\\DummyPaymentData\\"+NAME+"bal.txt",ios_base::out);
        writing_newbalance << int_val;
        cout << endl;
        writing_newbalance.close();

        ofstream writing_Receipt;
        writing_Receipt.open("Receipt\\" + NAME + "_receipt.txt", ios_base::out);
        writing_Receipt << "Thanks! for the purchase " << endl;
        writing_Receipt << NAME << "! Hope you liked our service" << endl;
        writing_Receipt << "You had successfully made a transaction " << endl
                        << endl;
        writing_Receipt << "AMOUNT PAID: " << price << endl;
        writing_Receipt.close();
    }
}

// constructor setting up the constraints of customer
void Customer::setter(string Name)
{
    cout << "\n";
    NAME = Name;
    cout << "Enter your Age: ";
    cin >> Age;
}

// sign in process
// if user exists this opens the text files of the user
void Customer::SignIn(string Name)
{
    NAME = Name;
    int extracted_age;
    ifstream signin;
    signin.open("users\\" + Name + "age.txt");
    signin >> extracted_age;
    Age = extracted_age;
}

// sign in process
void Customer::SignUp()
{
    // animation of registering the userr
    cout << "Registering User in our database ";
    for (int i = 0; i < 3; i++)
    {
        cout << ". ";
        Sleep(1000);
    }

    // creating the required files needed to wark;
    cout << "User is successfully registered in our database" << endl;
    Sleep(1000);
    cout << "You can now proceeds further\n";
    ofstream sufile;
    sufile.open("users\\" + NAME + ".txt");
    sufile << NAME;
    sufile.close();
    sufile.open("users\\" + NAME + "age.txt");
    sufile << Age;
    sufile.close();
    sufile.open("users\\" + NAME + "MR.txt");
    sufile.close();
    sufile.open("DATABASE\\DummyPaymentData\\" + NAME + "bal.txt");
    sufile << 3000;
    sufile.close();
    sufile.open("DATABASE\\User_Data\\userdatabase.txt", ios_base::app);
    sufile << NAME << "\n";
    sufile.close();
}

// class movie - abstract class
// pure virtual function - movie show function()=0;
// movie show function() - *READS THE SHOWCASE||GENERAL FILE* to print movie list
class movie
{
public:
    virtual void MovieList() = 0;
    virtual void SpecificMovie(int,int) = 0;
};
// hierarchical inheritance
// movie -> sub genre

std::fstream &GotoLine(std::fstream &file, unsigned int num)
{
    file.seekg(std::ios::beg);
    for (int i = 0; i < num - 1; ++i)
    {
        file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return file;
}
// encapsulation
class Action : public movie
{
public:
    void MovieList()
    {
        // open showcase files
        fstream in("DATABASE\\Movies\\Action.txt");
        string Action;
        while (getline(in, Action))
        {
            cout << Action << endl;
        }
        in.close();
    }
    void SpecificMovie(int MovieNumber,int indexing_element)
    {
        fstream file("DATABASE\\Movies\\Action.txt");
        GotoLine(file, (MovieNumber - 1) * 8);
        string print;

        for (int i = 0; i < 5; i++)
        {
            getline(file, print);
            if (i==0)
            {
                print[0]=indexing_element;    
                cout << print <<endl;
            }
            else
                cout << print << endl;
        }
        cout << endl;
    }
};

class Adventure : public movie
{
public:
    void MovieList()
    {
        fstream in("DATABASE\\Movies\\Adventure.txt");
        string Adventure;
        while (getline(in, Adventure))
        {
            cout << Adventure << endl;
        }
        in.close();
    }
    void SpecificMovie(int MovieNumber,int indexing_element)
    {
        fstream file("DATABASE\\Movies\\Adventure.txt");
        GotoLine(file, (MovieNumber - 1) * 8);
        string print;
        for (int i = 0; i < 5; i++)
        {
            getline(file,print);
            if (i==0)
            {
                print[0]=indexing_element;    
                cout << print <<endl;
            }
            else
                cout << print << endl;
        }
        cout << endl;
    }
};

class Animation : public movie
{
public:
    void MovieList()
    {
        fstream in("DATABASE\\Movies\\Animation.txt");
        string Animation;
        while (getline(in, Animation))
        {
            cout << Animation << endl;
        }
        in.close();
    }
    void SpecificMovie(int MovieNumber,int indexing_element)
    {
        fstream file("DATABASE\\Movies\\Animation.txt");
        GotoLine(file, (MovieNumber - 1) * 8);
        string print;
        for (int i = 0; i < 5; i++)
        {
            getline(file, print);
            if (i==0)
            {
                print[0]=indexing_element;    
                cout << print <<endl;
            }
            else
                cout << print << endl;
        }
        cout << endl;
    }
};

class Comedy : public movie
{
public:
    void MovieList()
    {
        fstream in("DATABASE\\Movies\\Comedy.txt");
        string Comedy;
        while (getline(in, Comedy))
        {
            cout << Comedy << endl;
        }
        in.close();
    }
    void SpecificMovie(int MovieNumber,int indexing_element)
    {
        fstream file("DATABASE\\Movies\\Comedy.txt");
        GotoLine(file, (MovieNumber - 1) * 8);
        string print;
        for (int i = 0; i < 5; i++)
        {
            getline(file, print);
            if (i==0)
            {
                print[0]=indexing_element;    
                cout << print <<endl;
            }
            else
                cout << print << endl;
        }
        cout << endl;
    }
};

class Documentary : public movie
{
public:
    void MovieList()
    {
        fstream in("DATABASE\\Movies\\Documentary.txt");
        string Documentary;
        while (getline(in, Documentary))
        {
            cout << Documentary << endl;
        }
        in.close();
    }
    void SpecificMovie(int MovieNumber,int indexing_element)
    {
        fstream file("DATABASE\\Movies\\Documentary.txt");
        GotoLine(file, (MovieNumber - 1) * 8);
        string print;
        for (int i = 0; i < 5; i++)
        {
            getline(file, print);
            if (i==0)
            {
                print[0]=indexing_element;    
                cout << print <<endl;
            }
            else
                cout << print << endl;
        }
        cout << endl;
    }
};

class Drama : public movie
{
public:
    void MovieList()
    {
        fstream in("DATABASE\\Movies\\Drama.txt");
        string Drama;
        while (getline(in, Drama))
        {
            cout << Drama << endl;
        }
        in.close();
    }
    void SpecificMovie(int MovieNumber,int indexing_element)
    {
        fstream file("DATABASE\\Movies\\Drama.txt");
        GotoLine(file, (MovieNumber - 1) * 8);
        string print;
        for (int i = 0; i < 5; i++)
        {
            getline(file, print);
            if (i==0)
            {
                print[0]=indexing_element;    
                cout << print <<endl;
            }
            else
                cout << print << endl;
        }
        cout << endl;
    }
};

class Horror : public movie
{
public:
    void MovieList()
    {
        fstream in("DATABASE\\Movies\\Horror.txt");
        string Horror;
        while (getline(in, Horror))
        {
            cout << Horror << endl;
        }
        in.close();
    }
    void SpecificMovie(int MovieNumber,int indexing_element)
    {
        fstream file("DATABASE\\Movies\\Horror.txt");
        GotoLine(file, (MovieNumber - 1) * 8);
        string print;
        for (int i = 0; i < 5; i++)
        {
            getline(file, print);
            if (i==0)
            {
                print[0]=indexing_element;    
                cout << print <<endl;
            }
            else
                cout << print << endl;
        }
        cout << endl;
    }
};

class Romantic : public movie
{
public:
    void MovieList()
    {
        fstream in("DATABASE\\Movies\\Romantic.txt");
        string Romantic;
        while (getline(in, Romantic))
        {
            cout << Romantic << endl;
        }
        in.close();
    }
    void SpecificMovie(int MovieNumber,int indexing_element)
    {
        fstream file("DATABASE\\Movies\\Romantic.txt");
        GotoLine(file, (MovieNumber - 1) * 8);
        string print;
        for (int i = 0; i < 5; i++)
        {
            getline(file, print);
            if (i==0)
            {
                print[0]=indexing_element;    
                cout << print <<endl;
            }
            else
                cout << print << endl;
        }
        cout << endl;
    }
};

class ScienceFiction : public movie
{
public:
    void MovieList()
    {
        ifstream in("DATABASE\\Movies\\Sciencefiction.txt");
        string SciFi;
        while (getline(in, SciFi))
        {
            cout << SciFi << endl;
        }
        in.close();
    }
    void SpecificMovie(int MovieNumber,int indexing_element)
    {
        fstream file("DATABASE\\Movies\\Sciencefiction.txt");
        GotoLine(file, (MovieNumber - 1) * 8);
        string print;
        for (int i = 0; i < 5; i++)
        {
            getline(file, print);
            if (i==0)
            {
                print[0]=indexing_element;    
                cout << print <<endl;
            }
            else
                cout << print << endl;
        }
        cout << endl;
    }
};

class Thriller : public movie
{
public:
    void MovieList()
    {
        ifstream in("DATABASE\\Movies\\Thriller.txt");
        string thriller;
        while (getline(in, thriller))
        {
            cout << thriller << endl;
        }
        in.close();
    }
    void SpecificMovie(int MovieNumber,int indexing_element)
    {
        fstream file("DATABASE\\Movies\\Thriller.txt");
        GotoLine(file, (MovieNumber - 1) * 8);
        string print;
        for (int i = 0; i < 5; i++)
        {
            getline(file, print);
            if (i==0)
            {
                print[0]=indexing_element;    
                cout << print <<endl;
            }
            else
                cout << print << endl;
        }
        cout << endl;
    }
};
// objects of moive claSSES
Action AC;
Adventure AD;
Animation AN;
Comedy CO;
Documentary DO;
Drama DR;
Horror HO;
Romantic RO;
ScienceFiction SF;
Thriller TH;

// These two functions are clubed
// Text  Animation  of showing output
void ManageOutput_MCS()
{
    cout << endl;
    cout << "Thanks for choosing....." << endl;
    Sleep(1000);
    cout << "Searching up database....." << endl;
    Sleep(1000);
    cout << "Proceeding list in ";
    for (int i = 0; i < 3; i++)
    {
        cout << i + 1 << " ";
        Sleep(1000);
    }
}
// condition to check a user can buy movies which could be inappropriate for some user
int Appropriate_Age_Finder(int x, Customer C)
{
    int m = C.age();
    if ((x == 8 || x == 7) && m < 18)
    {
        cout << "\nYou can not access this genre as you are underaged\n";
        return 1;
    }
    else
    {
        return 0;
    }
}
// movie choice selector
void MovieChoiceSelector(int &no, Customer C)
{
    int x;

re_enter_choice:
start:
    fflush(stdin);
    cout << "\nSelect Genre:\n1:Action\t\t2:Adventure\n3:Animation\t\t4:Comedy\n5:Documentary\t\t6:Drama\n7:Horror\t\t8:Romantic\n9:Science Fiction\t10:Thriller\n\nEnter Your Choice: ";
    cin >> x;
    no = x;
    while (Appropriate_Age_Finder(x, C))
    {
        goto re_enter_choice;
    }

    ManageOutput_MCS();
    system("CLS");
    switch (x)
    {
    case 1:
        AC.MovieList();
        break;
    case 2:
        AD.MovieList();
        break;
    case 3:
        AN.MovieList();
        break;
    case 4:
        CO.MovieList();
        break;
    case 5:
        DO.MovieList();
        break;
    case 6:
        DR.MovieList();
        break;
    case 7:
        HO.MovieList();
        break;
    case 8:
        RO.MovieList();
        break;
    case 9:
        SF.MovieList();
        break;
    case 10:
        TH.MovieList();
        break;
    default:
        cout << "\nYou have entered Wrong Option\nPlease Enter Right option :(";
        goto start;
        break;
    }
    cout << endl;
}
// Redirecting ANIMATIONS
void Redirecting()
{
    cout << "Re-directing you in ";
    for (int i = 0; i < 3; i++)
    {
        // print number i.e 1 2 3
        cout << i + 1 << " ";
        // pause program for time effect
        Sleep(1000);
    }
    cout << endl;
}
// used for internal working of system
// this actually give the slected movie a unique  identification that
//  will in future wiil be used to extract movie name
void GivingRightSequence(int &ms)
{
    if (ms == 1)
    {
        ms = 0;
    }
    else if (ms == 2)
    {
        ms = 5;
    }
    else if (ms == 3)
    {
        ms = 10;
    }
    else if (ms == 4)
    {
        ms = 15;
    }
    else if (ms == 5)
    {
        ms = 20;
    }
    else if (ms == 6)
    {
        ms = 25;
    }
    else if (ms == 7)
    {
        ms = 30;
    }
    else if (ms == 8)
    {
        ms = 35;
    }
    else if (ms == 9)
    {
        ms = 40;
    }
    else if (ms == 10)
    {
        ms = 45;
    }
}
// writes the movies rented code on the text file
void movie_on_rent(int movie_code, string name, int n)
{
    if (n == 2)
    {
        fstream fout("users\\" + name + "MR.txt", ios_base::app);
        fout << movie_code << "\n";
    }
}
// sum up the stacck and find total price to be paid
// type referse as the what you what to do buy or rent
int movieCostfinder_fromfile(int type, int number)
{
    if (type == 1)
    {
        ifstream price;
        price.open("DATABASE\\workingFiles\\Buy_Rates.txt");
        int paise;
        for (int i = 1; i < number; i++)
        {
            price >> paise;
        }
        return paise;
        price.close();
    }
    else if (type == 2)
    {
        ifstream price;
        price.open("DATABASE\\workingFiles\\Rent_Rates.txt");
        int paise;
        for (int i = 1; i < number; i++)
        {
            price >> paise;
        }
        return paise;
        price.close();
    }
    else
    {
        int a = 0;
        return a;
    }
}
// handlinng price deduction frmt dummy payment
void movie_return_recipt(string name, int rentbe_paid)
{
    ifstream in;
    in.open("DATABASE\\DummyPaymentData\\" + name + "bal.txt");
    int last_amount;
    in >> last_amount;
    in.close();
    ofstream out;
    out.open("DATABASE\\DummyPaymentData\\" + name + "bal.txt");
    out << last_amount - rentbe_paid;
    out.close();

    ofstream writing_Receipt;
    writing_Receipt.open("Receipt\\" + name + "_receipt.txt", ios_base::out);
    writing_Receipt << name << " Thanks! for clearing your dues" << endl;
    writing_Receipt << "transaction made succesfully" << endl
                    << endl;
    writing_Receipt << "AMOUNT PAID: " << rentbe_paid << endl;
    writing_Receipt.close();
}

// feature to return a book
void return_feature(string name, int &vapsi)
{
a1:
    fflush(stdin);
    int movie_number, eye = 0;
    cout << "Enter Movie ID of movie you want to Return: ";
    cin >> movie_number;

    stack<int> User_rented_movie;

    ifstream returnfetr;
    returnfetr.open("users\\" + name + "MR.txt");
    int movies, condition = 1;
    while (returnfetr >> movies)
    {
        if (movie_number == movies)
        {
            condition = 0;
        }
        else
        {
            eye++;
            User_rented_movie.push(movies);
        }
    }
    returnfetr.close();
    if (condition)
    {
        int dhikana;
        cout << "You Doesn't have this movie" << endl;
    a2:
        cout << "1:Re-Enter movie number\n2:Rent or Buy More movie\n3:exit\nEnter your choice: ";
        cin >> dhikana;
        switch (dhikana)
        {
        case 1:
            goto a1;
            break;
        case 2:
            vapsi = 1;
            return;
            break;
        case 3:
            exit(0);
            break;
        default:
            cout << "\nWrong Choice!! \n";
            goto a2;
            break;
        }
    }
    ofstream x;
    x.open("users\\" + name + "MR.txt");
    for (int i = 0; i < eye; i++)
    {
        int last;
        last = User_rented_movie.top();
        x << last << "\n";
        User_rented_movie.pop();
    }
    x.close();

    cout << endl
         << "connecting to bank for clearing dues " << endl
         << "paying dues " << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << ". ";
        Sleep(1000);
    }
    int rent_to_be_paid;
    // there is a catvh that after entering
    // movie number it shows the price of one less movie hence always use the function with +1
    rent_to_be_paid = movieCostfinder_fromfile(2, movie_number + 1);
    cout << rent_to_be_paid << endl;
    movie_return_recipt(name, rent_to_be_paid);
    cout << "Dues cleared" << endl;
    if (!condition)
    {
        cout << "Thanks for Returning movie\n";
        cout << "You are now no more subjected to Rents anymore\n";
    reenter:
        fflush(stdin);
        cout << "Do you want to buy or rent more?\n1]YES\t\t2]NO\nEnter command as string: ";
        string answer;
        cin >> answer;
        cout << endl;
        if (answer == "YES")
        {
            vapsi = 1;
            return;
        }
        else if (answer == "NO")
        {
            exit(0);
        }
        else
        {
            cout << "Wrong choice :(" << endl;
            cout << "Re-enter your command\n";
            goto reenter;
        }
    }
}
//  a thing to be corrected we can just simply use the modulus to back trace the
//  the name of movie
//  could be  improved once finding the number and genre
//  we can remove switch case
//  by overloading the abstract class

// function to decode movie genre
int genre_decoder(int value)
{    
    if (value>0&&value<10)
    {
        if (value > 5)
            return 2;
        else
            return 1;
    }
    int Once_place = value%10;
    int Tens_place = value/10;
    switch (Tens_place)
    {
    case 1:
        if (Once_place==0)
            return 2;
        else if(Once_place>5)
            return 4;
        else
            return 3;
        break;
    case 2:
        if (Once_place==0)
            return 4;
        else if(Once_place>5)
            return 6;
        else
            return 5;
        break;
    case 3:
        if (Once_place==0)
            return 6;
        else if(Once_place>5)
            return 8;
        else
            return 7;
        break;
    case 4:
        if (Once_place==0)
            return 8;
        else if(Once_place>5)
            return 10;
        else
            return 9;
    case 5:
        if (Once_place==0)
            return 10;
        break;
    }
}
// function to find movie number
int number_decoder(int value)
{
    int Once_place = value%10;
    int Tens_place = value/10;
    if (value>0&&value<10)
    {
        if (value > 5)
            return value-5;
        else
            return value;
    }
    else
    {
        if (Once_place == 0)
        {
            return 5;
        }
        else if (Once_place > 5)
        {
            return Once_place-5;
        }
        else
        {
            return Once_place;
        }
    }
}
void know_your_movie(string naame)
{
    int value;
    ifstream showRentMovie;
    showRentMovie.open("users\\" + naame + "MR.txt");
    int indexing = 0;
    cout << endl;
    cout << "Movie rented by you from us are:" << endl;
    while (showRentMovie >> value)
    {
        indexing++;
        int Decoded_genre = genre_decoder(value);
        int Decoded_MovieSno = number_decoder(value);
        switch (Decoded_genre)
        {
        case 1:

            AC.SpecificMovie(Decoded_MovieSno,indexing);
            break;
        case 2:

            AD.SpecificMovie(Decoded_MovieSno,indexing);
            break;
        case 3:

            AN.SpecificMovie(Decoded_MovieSno,indexing);
            break;
        case 4:

            CO.SpecificMovie(Decoded_MovieSno,indexing);
            break;
        case 5:

            DO.SpecificMovie(Decoded_MovieSno,indexing);
            break;
        case 6:
            DR.SpecificMovie(Decoded_MovieSno,indexing);
            break;
        case 7:

            HO.SpecificMovie(Decoded_MovieSno,indexing);
            break;
        case 8:

            RO.SpecificMovie(Decoded_MovieSno,indexing);
            break;
        case 9:

            SF.SpecificMovie(Decoded_MovieSno,indexing);
            break;
        case 10:

            TH.SpecificMovie(Decoded_MovieSno,indexing);
            break;
        }
    }
    cout << endl;

    if (indexing == 0)
    {
        cout << "You Doesn't Rent any books '-' ";
    }

    showRentMovie.close();
    exit(0);
}

// Delete your account feature

// main code to delete user account
int Delete_your_Account(Customer object)
{
    ifstream Dues;
    Dues.open("users\\" + object.name() + "MR.txt");
    if (!Dues)
    {
        // file failed to open
        cout << "Oops! error occured" << endl;
        return -1;
    }
    int flag = 0;
    Dues.seekg(0, ios::end);
    if (Dues.tellg() == 0)
    {
        flag = 1;
    }
    if (flag)
    {
        // movie rented by user text file is empty
        // remove function return 0 when delteion is success
        // remove only allow char

        // removing username file
        string way = "users\\" + object.name() + ".txt";
        int size = way.length();
        char path[size + 1];
        strcpy(path, way.c_str());
        remove(path);

        // removing user age file
        way = "users\\" + object.name() + "age.txt";
        size = way.length();
        char path_age[size + 1];
        strcpy(path_age, way.c_str());
        remove(path_age);

        Dues.close();

        // rmeoving movie rented file
        way = "users\\" + object.name() + "MR.txt";
        size = way.length();
        char path_mr[size + 1];
        strcpy(path_mr, way.c_str());
        remove(path_mr);

        // deleting recipt
        way = "DATABASE\\DummyPaymentData\\" + object.name() + "bal.txt";
        size = way.length();
        char path_pay[size + 1];
        strcpy(path_pay, way.c_str());
        remove(path_pay);

        // deleting reci[t]
        way = "Receipt\\" + object.name() + "_receipt.txt";
        size = way.length();
        char path_r[size + 1];
        strcpy(path_r, way.c_str());
        remove(path_r);

        // copying the data of user database except deleted accounnt name
        stack<string> tempstorage;
        ifstream database;
        database.open("DATABASE\\User_Data\\userdatabase.txt", ios_base::app);
        database.seekg(0, ios::beg);
        string user_namez;
        while (getline(database, user_namez))
        {
            if (user_namez == object.name())
            { // skipping writing user name
            }
            else if (user_namez == "")
            { // skipping writing white  spaces
            }
            else
            {
                tempstorage.push(user_namez);
            }
        }
        database.close();
        ofstream database2;
        database2.open("DATABASE\\User_Data\\userdatabase.txt");
        while (!tempstorage.empty())
        {
            database2 << tempstorage.top() << endl;
            tempstorage.pop();
        }
        database2.close();
        return 1;
    }
    else
    {
        Dues.close();
        return 0;
    }
}

int main()
{
    // welcome line
    std::cout << "\033[1;33m"; // Set text color to bright yellow
    cout << "\t\t||- WELCOME TO MITS VIDEO LIBRARY -||" << endl;
    cout << "\t\t         YOUR MOVIE PARADISE" << endl;
    std::cout << "\033[0m"; // Reset text color to default
    std::cout << "\033[1;36m"; // Set text color to bright cyan
    cout << "PRESS ANY KEY TO CONTINUE" << endl;
    std::cout << "\033[0m"; // Reset text color to default
    getchar();
    cout << endl;

    // creating important variable
    int user_available = 0;
    string username;
    ifstream login("DATABASE\\User_Data\\userdatabase.txt");
    string line;

SectionA:
    // ask for sign up and sign in
    fflush(stdin);
    cout << "Click   1 for SIGNUP\n\t2 for SIGNIN\nEnter your Choice: ";
    int sign_choice;
    cin >> sign_choice;
    // after learing exception handing this is can be removed
    if (sign_choice > 2 || sign_choice < 1)
    {
        cout << "Wrong choice\nEnter correct choice: \n " << endl;
        fflush(stdin);
        goto SectionA;
    }

    // sign in process that can automatically done once
    // as if file exist data can be extraced from them
    // else direct the user in sign up
    // sign up process includes creating files and writing user info

    Customer New;
    if (sign_choice == 1)
    {
        cout << "Enter your Name: ";
        cin >> username;

        while (getline(login, line))
        {
            if (username == line)
            {
                user_available = 1;
                break;
            }
        }
        if (user_available == 1)
        {
            cout << "\nYour are already registered! \n";
            cout << "Synchronizing your information ";
            for (int i = 0; i < 4; i++)
            {
                cout << ". ";
                Sleep(1000);
            }

            goto login;
        }

    section1_signup:
        fflush(stdin);
        New.TypeOfUser = 1;
        New.setter(username);
        New.SignUp();
    }
    else if (sign_choice == 2)
    {
    section1_re:
        fflush(stdin);

        cout << "Enter your user name: ";
        cin >> username;
        while (getline(login, line))
        {
            if (username == line)
            {
                user_available = 1;
                break;
            }
        }
        if (user_available == 0)
        {
            cout << "\nEntered user name is not available in database" << endl;
            Sleep(500);
            int x;
            cout << "!!This username seems incorrect" << endl;
        wrng_section1:
            fflush(stdin);
            cout << "1:Re-enter user name" << endl
                 << "2:SIGNUP" << endl
                 << "Enter your choice: ";
            fflush(stdin);
            cin >> x;
            if (x == 1)
            {
                cout << "\nBe carefull this time\n"
                     << endl;
                Redirecting();
                goto section1_re;
            }
            else if (x == 2)
            {
                goto section1_signup;
            }
            else
            {
                cout << "Wrong option selected" << endl;
                Redirecting();
                cout << endl;
                goto wrng_section1;
            }
        }
    login:
        New.TypeOfUser = 0;
        New.SignIn(username);
    }

    login.close();
    // section 2
    // giving userr choices
    // rewriting files
    // making payments
    cout << "\nWelcome " << New.name() << "! You can now proceeds further" << endl
         << endl;
    int MovieSequence;
faalana_dhikana:
failed_deletion_redirection:
failed_account_deletion_dueTOdues:
    fflush(stdin);
    cout << "What you want to perform:" << endl;
    cout << "1:Return Item" << endl;
    cout << "2:Buy or Rent" << endl;
    cout << "3:Know what movie you rent" << endl;
    cout << "4:Delete your account" << endl;
    cout << "5:EXIT" << endl;
    cout << "Enter choice: ";
    int BRR;
    fflush(stdin);
    cin >> BRR;
    if (BRR == 1)
    {
        int falanaa = 0;
        return_feature(New.name(), falanaa);
        if (falanaa == 1)
        {
            goto section2_BRR;
        }
    }
    else if (BRR == 5)
    {
        exit(0);
    }
    else if (BRR == 4)
    {
        int account_deletion = Delete_your_Account(New);
        if (account_deletion == 1)
        {
            cout << endl
                 << "Deleting your information ";
            for (int i = 0; i < 4; i++)
            {
                cout << ". ";
                Sleep(1000);
            }
            cout << endl
                 << "your account is successfully Deleted" << endl;
            cout << "Feel free to give us feedback" << endl;
            cout << "thanks! for using our services '-' bye!\n"
                 << endl;
            exit(0);
        }
        else if (account_deletion == -1)
        {
            cout << endl
                 << "Sorry! for the inconvience " << endl;
            cout << "Please try again" << endl;
            goto failed_deletion_redirection;
        }
        else
        {
            cout << endl
                 << "something went wrong " << endl
                 << "Fetching more details " << endl;
            for (int i = 0; i < 4; i++)
            {
                cout << ". ";
                Sleep(1000);
            }
            cout << endl
                 << "Your Account can't be deleted " << endl;
            cout << "Please! clear your dues first" << endl;
            cout << "You can clear dues by returning the books" << endl;
            cout << "till then use our other services\n"
                 << endl;
            goto failed_account_deletion_dueTOdues;
        }
    }
    else if (BRR == 3)
    {
        know_your_movie(New.name());
    }
    if (BRR < 1 || BRR > 5)
    {
        cout << "\nWrong input chooose right \n";
        goto faalana_dhikana;
    }
section2:
section2_BRR:
    fflush(stdin);
    cout << endl;
    MovieChoiceSelector(MovieSequence, New);
    GivingRightSequence(MovieSequence);
    int choose;

section2_MN:
    fflush(stdin);
    cout << "\nEnter Movie Number [one at a time]: ";
    cin >> choose;
    if (choose < 1 || choose > 5)
    {
        cout << "Enter valid movie number:\n";
        goto section2_MN;
    }

    MovieSequence = MovieSequence + choose;

    int BR;
section2_BR:
    cout << "\nDo you want to-\n1:BUY\n2:RENT\nEnter your command: ";
    cin >> BR;
    if (BR != 1 && BR != 2)
    {
        cout << "Wrong choice :( \n";
        goto section2_BR;
    }
    cart.push(movieCostfinder_fromfile(BR, MovieSequence + 1));
    movie_on_rent(MovieSequence, New.name(), BR);
    cout << "\nDo you want to add more to the cart??\n1:YES\n2:NO\nEnter Your Choice: ";
    int falana;
    cin >> falana;
    if (falana == 1)
    {
        cout << "Taking you to the choices\n";
        Redirecting();
        cout << endl;
        goto section2;
    }

    New.MakePayment();
    cout << endl
         << "THANKS!! FOR THE PURCHASE" << endl;
    cout << "WE HOPE YOU WILL ENJOY THE MOVIE" << endl;
    cout << "HAVE A GREAT DAY " << New.name();

    return 0;
}
