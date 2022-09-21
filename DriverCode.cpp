// libraries included in the code
#include <iostream>
#include <windows.h> //clean the terminal window
#include <conio.h>   //to use automatic enter and sleep inbuit function
#include <string>    //exit
#include <fstream>
#include <stack> //to make cart system and to use in return dvd;

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
{   //finding the total price items in the cart
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
    //payment page to depict real world buying services
    cout << "\nPRESS ENTER TO CONFIRM YOU ORDER";
    fflush(stdin);
    getchar();
    Sleep(1000);
    cout << "Redirecting you to our S.P.P.[Secure Payment Portal]" << endl;
    Redirecting();
    system("CLS");

    //processing payment page
    cout << "Processing your Payment..";
    for (int i = 0; i < 3; i++)
    {
        cout << i + 1 << " ";
        Sleep(2000);
    }
    cout << endl;
    int price = 0;
    price = total();

    //ReWriting Payment in dummy payment file as to make
    //some payments decline
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

//constructor setting up the constraints of customer
void Customer::setter(string Name)
{
    cout << "\n";
    NAME = Name;
    cout << "Enter your Age: ";
    cin >> Age;
}

//sign in process
//if user exists this opens the text files of the user
void Customer::SignIn(string Name)
{
    NAME = Name;
    int extracted_age;
    ifstream signin;
    signin.open("users\\" + Name + "age.txt");
    signin >> extracted_age;
    Age = extracted_age;
}

//sign in process
void Customer::SignUp()
{
    // animation of registering the userr
    cout << "Registering User in our database ";
    for (int i = 0; i < 3; i++)
    {
        cout << ". ";
        Sleep(1000);
    }

    //creating the required files needed to wark;
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
    sufile << 1000;
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
};
// hierarchical inheritance
// movie -> sub genre

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
};

// These two functions are clubed
//Text  Animation  of showing output
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
//condition to check a user can buy movies which could be inappropriate for some user
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
//movie choice selector
void MovieChoiceSelector(int &no, Customer C)
{
    int x;
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
//Redirecting ANIMATIONS
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
//used for internal working of system
//this actually give the slected movie a unique  identification that 
// will in future wiil be used to extract movie name
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
//writes the movies rented code on the text file
void movie_on_rent(int movie_code, string name, int n)
{
    if (n == 2)
    {
        fstream fout("users\\" + name + "MR.txt", ios_base::app);
        fout << movie_code << "\n";
    }
}
//sum up the stacck and find total price to be paid
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
//feature to return a book
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
    if (condition == 0)
    {
        cout << "Thanks for Returning movie\n";
        cout << "You are now no more subjected to Rents anymore\n";
    reenter:
        fflush(stdin);
        cout << "Do you want to buy or rent more?\n1]YES\t\t2]NO\nEnter: ";
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
void know_your_movie(string naame)
{
    int value;
    ifstream showRentMovie;
    showRentMovie.open("users\\" + naame + "MR.txt");
    int indexing = 0;
    cout << endl;
    while (showRentMovie >> value)
    {
        cout << "Movie rented by you from us are:" << endl;
        indexing++;
        cout << indexing << ")";
        switch (value)
        {
        case 1:
            cout << "Doctor Strange\n";
            break;
        case 2:
            cout << "Fast and Furious 9\n";
            break;
        case 3:
            cout << "K.G.F ch-2\n";
            break;
        case 4:
            cout << "Morbius\n";
            break;
        case 5:
            cout << "Pushpa:The Rise\n";
            break;
        case 6:
            cout << "Fantastic Beasts: The Secrets of Dumbledore\n";
            break;
        case 7:
            cout << "Jungle Cruise\n";
            break;
        case 8:
            cout << "Jurassic World: Fallen Kingdom\n";
            break;
        case 9:
            cout << "Spider-Man: No Way Home\n";
            break;
        case 10:
            cout << "Uncharted\n";
            break;
        case 11:
            cout << "How to Train Your Dragon: The Hidden World\n";
            break;
        case 12:
            cout << "Incredibles 2\n";
            break;
        case 13:
            cout << "Madagascar 3: Europe's Most Wanted\n";
            break;
        case 14:
            cout << "Ratatouille\n";
            break;
        case 15:
            cout << "The Angry Birds Movie\n";
            break;
        case 16:
            cout << "Golmaal 3\n";
            break;
        case 17:
            cout << "Housefull 4\n";
            break;
        case 18:
            cout << "Hungama 2\n";
            break;
        case 19:
            cout << "Red Notice\n";
            break;
        case 20:
            cout << "The Lost City\n";
            break;
        case 21:
            cout << "An Insignificant Man\n";
            break;
        case 22:
            cout << "Beyond All Boundaries\n";
            break;
        case 23:
            cout << "Bombay: Our City\n";
            break;
        case 24:
            cout << "Gulabi Gang\n";
            break;
        case 25:
            cout << "Sachin: A Billion Dreams\n";
            break;
        case 26:
            cout << "Gangubai Kathiawadi\n";
            break;
        case 27:
            cout << " Jersey\n";
            break;
        case 28:
            cout << "Legend\n";
            break;
        case 29:
            cout << "Shiddat\n";
            break;
        case 30:
            cout << "Super 30\n";
            break;
        case 31:
            cout << "Annabelle Comes Home\n";
            break;
        case 32:
            cout << "IT\n";
            break;
        case 33:
            cout << "Malignant\n";
            break;
        case 34:
            cout << "Resident Evil: Welcome to Raccoon City\n";
            break;
        case 35:
            cout << "Scream\n";
            break;
        case 36:
            cout << "Fifty Shades of Grey \n";
            break;
        case 37:
            cout << "Indecent Proposal\n";
            break;
        case 38:
            cout << "Little Children\n";
            break;
        case 39:
            cout << "Love & Other Drug\n";
            break;
        case 40:
            cout << " The Girl Next Door\n";
            break;
        case 41:
            cout << "Gravity\n";
            break;
        case 42:
            cout << "Tenet\n";
            break;
        case 43:
            cout << "The Adam Project\n";
            break;
        case 44:
            cout << "The Martian\n";
            break;
        case 45:
            cout << "The Tomorrow War\n";
            break;
        case 46:
            cout << "Glass\n";
            break;
        case 47:
            cout << "Haseen Dillruba\n";
            break;
        case 48:
            cout << "Khuda Haafiz\n";
            break;
        case 49:
            cout << "Mission: Impossible - Fallout\n";
            break;
        case 50:
            cout << "The Conjuring: The Devil Made Me Do It\n";
            break;
        default:
            cout << "Error\n";
            break;
        }
    }
    if (indexing == 0)
    {
        cout << "You Doesn't Rent any books '-' ";
    }

    showRentMovie.close();
    exit(0);
}

int main()
{
    //welcome line
    cout << "\t\t||- WELCOME TO MITS VIDEO LIBRARY -||" << endl;
    cout << "\t\t         YOUR MOVIE PARADISE" << endl;
    cout << "PRESS ANY KEY TO CONTINUE";
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
    //after learing exception handing this is can be removed
    if (sign_choice > 2 || sign_choice < 1)
    {
        cout << "Wrong choice\n Enter correct choice: " << endl;
        goto SectionA;
    }

    //sign in process that can automatically done once 
    //as if file exist data can be extraced from them 
    //else direct the user in sign up
    //sign up process includes creating files and writing user info

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
            cout << "Entered user name is not available in database" << endl;
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

    // section 2
    //giving userr choices
    //rewriting files 
    //making payments
    cout << "\nWelcome " << New.name() << "! You can now proceeds further" << endl
         << endl;
    int MovieSequence;
faalana_dhikana:
    fflush(stdin);
    cout << "What you want to perform:" << endl;
    cout << "1:Return Item" << endl;
    cout << "2:Buy or Rent" << endl;
    cout << "3:Know what movie you rent" << endl;
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
    else if (BRR == 3)
    {
        know_your_movie(New.name());
    }
    if (BRR != 1 && BRR != 2 && BRR != 3)
    {
        cout << "Wrong input chooose right\n";
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
    cout << "\nEnter Movie Number: ";
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