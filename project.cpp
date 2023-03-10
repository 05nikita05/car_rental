#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <iomanip>

using namespace std;
class Menu
{
public:
    void price_menu()
    {
        cout << "<---------------------CAR RENTAL SYSTEM--------------------------->" << endl;
        cout << "*******************************************************************" << endl;
        cout << "          Welcome to the ''CAR RENT PRICE LIST''         " << endl;
        cout << "*******************************************************************" << endl;
        cout << "S.NO" << setw(3) << "NAME" << setw(10) << "PRICE" << endl;
        cout << "1." << setw(3) << "Hyundai" << setw(10) << "Rs.2000" << endl;
        cout << "2." << setw(3) << "BMW" << setw(10) << "Rs.4000" << endl;
        cout << "3." << setw(3) << "Audi" << setw(10) << "Rs.4500" << endl;
        cout << "4." << setw(3) << "Ford" << setw(10) << "Rs.2000" << endl;
        cout << "5." << setw(3) << "Maruti" << setw(10) << "Rs.2000" << endl;
        cout << "6" << setw(3) << "Inova" << setw(10) << "Rs.2100" << endl
             << endl;
        cout << "The prices which are displayed above,are for renting a car per day" << endl;
        cout << " *Important* customers please check the price list before forwarding." << endl;
    }
    void Main_menu()
    {
        cout << "<---------------CAR RENTAL SYSTEM----------------->" << endl;
        cout << "*********************************************" << endl;
        cout << "            Welcome to the ''MENU PAGE''           " << endl;
        cout << "*********************************************" << endl;
        cout << "1. Admin " << endl;
        cout << "2. Customer " << endl;
        cout << "3. Car menu" << endl;
        cout << "4. Price list" << endl;
        cout << "5. Exit " << endl;
    }
    void Admin_menu()
    {
        cout << "<------------CAR RENTAL SYSTEM-------------->" << endl;
        cout << "*********************************************" << endl;
        cout << "        Welcome to the ''ADMIN PAGE''     " << endl;
        cout << "*********************************************" << endl;
        cout << " 1. Add a new car" << endl;
        cout << " 2. Show all cars" << endl;
        cout << " 3. Show customer list" << endl;
        cout << " 4. Exit" << endl;
    }
    void Customer_menu()
    {
        cout << "<------------CAR RENTAL SYSTEM-------------->" << endl;
        cout << "*********************************************" << endl;
        cout << "      Welcome to the ''CUSTOMER PAGE''     " << endl;
        cout << "*********************************************" << endl;
        cout << " 1. New Registration " << endl;
        cout << " 2. Existing user" << endl;
        cout << " 3. Rent a car " << endl;
        cout << " 4. Exit" << endl;
    }
    void Car_menu()
    {
        cout << " Welcome to our car rental company " << endl;
        cout << " These are the car models that we provide you to rent for days." << endl;
        cout << "the days you want for." << endl;
        cout << " Now you can select from here:\n " << endl;
        cout << "1.Hyundai\n 2.BMW\n 3.Audi\n 4.Ford\n 5.Maruti\n 6.Inova\n"
             << endl;
        cout << "And for more options you can directly contact to our admin." << endl;
        cout << " contact no: 0000000000" << endl;
        cout << "*T/c applied." << endl;
    }
};
class admin : public Menu
{
    char c_name[20];
    int c_No;
    int car;
    int c_price;
    char c_ar[20];

public:
    void customer_list();
    void add_cars()
    {
        fstream open;
        open.open("newcar.txt");
        if (!open)
        {
            cerr << "Unable to  open file!!!!!!" << endl;
            return;
        }
        cout << "enter no. of cars you want to add." << endl;
        cin >> car;
        for (int i = 0; i < car; i++)
        {
            cout << "Now you can add more cars." << endl;
            cout << " enter car name:" << endl;
            cin >> c_name;
            cout << "enter car no.:" << endl;
            cin >> c_No;
            cout << "enter car price:" << endl;
            cin >> c_price;
        }

        open << "NAME" << "     " << "CAR NO." << "     " << "PRICE" << endl;
        open << "Hyundai" << "     " << "666" << "     " << "Rs.2000" << endl;
        open << "BMW" << "     " << "373" << "     "<< "Rs.4000" << endl;
        open << "Audi" << "     " << "609" << "     " << "Rs.4500" << endl;
        open << "Ford" << "     " << "973" << "     "<< "Rs.2000" << endl;
        open << "Maruti" << "     " << "693" << "     "<< "Rs.2000" << endl;
        open << "Inova" << "     " << "673" << "     " << "Rs.2100" << endl
             << endl;
        for (int i = 0; i < car; i++)
        {
            open << c_name <<  "     " << c_No <<  "     " << c_price << endl;
        }
        open.close();
    }
    void show_cars()
    {
        ifstream car;
        string st;
        car.open("newcar.txt");

        while (car.eof() == 0)
        {
            getline(car, st);
            cout << st << endl;
        }
        car.close();
    }
    void rent_car()
    {
        cout << "now you can access!!!" << endl;
        int sleep(2000);

        cout << "first you have to enter the car name which you want:" << endl;
        cin >> c_ar;
        admin a1;
        fstream rent;
        rent.open("newcar.txt");
        if (!rent)
        {
            cerr << "Unable to  open file!!!!!!" << endl;
            return;
        }
        while (rent.eof() == 0)
        {
            if (strcmp(c_ar, a1.c_name) == 1)
            {
                cout << "you can go for it." << endl;
                cout << "Car you have rented:" << c_ar << endl;
                cout << "CONNGRATULATIONS!!!!!" << endl;
            }
            else
                cout << "The car is not available." << endl;
            return;
        }
        rent.close();
    }
    void existing()
    {
        rent_car();
    }
};
class customer
{
    string name;
    string address;
    int id_no;
    int cont_no;

public:
    void new_regi()
    {

        fstream ofp;
        ofp.open("newcus.txt");
        if (!ofp)
        {
            cerr << "Unable to  open file!!!!!!" << endl;
            return;
        }

        customer C;
        cout << "enter your name please:" << endl;
        cin.ignore();
        getline(cin, name);
        cout << "enter your address please:" << endl;
        cin.ignore();
        getline(cin, address);
        cout << "enter your id no.:" << endl;
        cin >> C.id_no;
        cout << "enter your contact no.:" << endl;
        cin >> C.cont_no;
        cout << "you are successfully registered!!!!!" << endl;
        ofp << "NAME" << setw(20) << "ADDRESS" << setw(20) << "ID NO." << setw(20) << "contact no." << endl;

        ofp << name << setw(20) << address << setw(20) << id_no << setw(20) << cont_no << endl;
        ofp.close();
    }
};

void admin::customer_list()
{
    ifstream list;
    string s;
    list.open("newcus.txt");

    while (list.eof() == 0)
    {
        getline(list, s);
        cout << s << endl;
    }
    list.close();
}
int main()
{
    Menu m1;

    int choice;

    m1.Main_menu();
    cout << "Now enter valid input from above:\n";
    cin >> choice;
    switch (choice)
    {
    case 1:
{
        m1.Admin_menu();
        admin A;
        int choice1;
        cout << "Enter any valid input from above:\n ";
        cin >> choice1;
        switch (choice1)
        {
        case 1:
            A.add_cars();
            break;
        case 2:
            A.show_cars();
            break;
        case 3:
            A.customer_list();
            break;
        default:
            cout << "EXIT" << endl;
            break;
        }
        break;
}
    case 2:
    {
        m1.Customer_menu();
        customer c1;
        admin A;
        
            int choice2;
            cout << "Enter the valid input from above:\n";
            cin >> choice2;
            switch (choice2)
            {
            case 1:

                c1.new_regi();
                break;
            case 2:
                A.existing();
                break;
            case 3:
                A.rent_car();
                break;

        default:
            cout << "EXIT" << endl;

            break;
            }
        break;
    }
    case 3:
{
        m1.Car_menu();
        break;
    }
    case 4:
{
        m1.price_menu();
        break;
}
    default:
    {
        cout << "Thankyou!!!!" << endl;
        break;
    }

    return 0;
}
    }