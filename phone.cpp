#include <iostream>
#include <vector>
#include <fstream>

struct Contact
{
    std::string _name{};
    std::string _surname{};
    std::string _dateofBirth{};
    std::string _passportID{};
    std::string _phoneNumber{};
    std::string _email{};
};

std::vector<Contact> allContacts;

void addContact();
void contactList();
void searchContact();
void editContact();
void deleteContact();
void mainMenu();
void exitFromApp();
void browseData(std::string&);

int main()
{
    std::ifstream file;
    std::string path{};
    std::cout << "Please enter the path : ";
    std::cin >> path;
    file.open(path);
    if(file.is_open())
    {
        browseData(path);
        mainMenu();
    }
    else
    {
        std::cout << "File isn't open" << std::endl;
    }
    file.close();
}

void mainMenu()
{
    int choice = 0;
    std::cout << "\t\tMAIN\tMENU\t" << std::endl;
    std::cout << "\t==========================" << std::endl;
    std::cout << "\t[1] Add Contact\n\t[2] List all Contacts\n"
    <<"\t[3] Search a Contact\n\t"
    << "[4] Delete a Contact\n\t[5] Edit a Contact\n\t[6] Exit" << std::endl;
    std::cout << "\t==========================" << std::endl;
    do
    {
        std::cout << "Please enter your choice [*]\b\b";
        std::cin >> choice;
    } 
    while (choice < 0 && choice > 6);
    switch(choice)
    {
        case 1:
        addContact();
        break;
        case 2:
        contactList();
        break;
        case 3:
        searchContact();
        break;
        case 4:
        deleteContact();
        break;
        case 5:
        editContact();
        break;
        case 6:
        exitFromApp();
        break;
        default:
        break;
    }
}

void exitFromApp()
{
    std::ofstream text;
    std::string save_to = "contactList";
    text.open(save_to);
    text.clear();
    text << "contactsCount: " << allContacts.size() << "\n";
    for (size_t i = 0; i < allContacts.size(); ++i)
    {
        text << allContacts[i]._name << " name\n";
        text << allContacts[i]._surname << " surname\n";
        text << allContacts[i]._dateofBirth << " date of birth\n";
        text << allContacts[i]._passportID << " passport ID\n";
        text << "+374" << allContacts[i]._phoneNumber << " phone Number\n";
        text << allContacts[i]._email << " email\n";
        if (i != (allContacts.size() - 1))
        {
            text << "next contact\n";
        }    
    }    
    text.close();
    std::cout << "App is going to close...\n\tGoodbye !" << std::endl;
    exit(0);
}

void addContact()
{
    Contact myContact;
    std::cout << "Fill the information about the contact below \n";
    std::cout << "Contact name : ";
    std::cin >> myContact._name;
    std::cout << "Contact surname : ";
    std::cin >> myContact._surname;
    std::cout << "Date of birth (DD/MM/YYYY)\b\b\b\b\b\b\b\b\b\b\b";
    std::cin >> myContact._dateofBirth;
    std::string check{};
    bool flag{};
    do
    {
        std::cout << "Phone number +374--------\b\b\b\b\b\b\b\b";
        std::cin >> check;
        flag = false;
        for(int i = 0; i < allContacts.size(); ++i)
        {   
            if(check == allContacts[i]._phoneNumber)
            {
                std::cout << "This number is already used , enter a valid phone number !\n";
                flag = true;
            }
        }
    }
    while (flag);
    myContact._phoneNumber = check;
    check.clear();
    do
    {
        std::cout << "Passport ID : ";
        std::cin >> check;
        flag = false;
        for(int i = 0; i < allContacts.size(); ++i)
        {
            if(check == allContacts[i]._passportID)
            {
                flag = true;
                std::cout << "This passport ID is already used , enter a valis passport ID !\n";
            }
        }   
    } 
    while (flag);
    myContact._passportID = check;
    check.clear();
    do
    {
        std::cout << "Email address : ";
        std::cin >> check;
        flag = false;
        for(int i = 0; i < allContacts.size(); ++i)
        {
            if(check == allContacts[i]._email)
            {
                flag = true;
                std::cout << "This email address is already used , enter a valis passport ID !\n";
            }
        }   
    } 
    while (flag);
    myContact._email = check;
    check.clear();
    allContacts.push_back(myContact);
    std::string tmp{};
    do
    {
        std::cout << "Do you want to do any operations ? (yes/no) : ";
        std::cin >> tmp;
    }
    while(tmp != "yes" && tmp != "no");
    if(tmp == "yes")
    {
        mainMenu();
    }
    else
    {
        exitFromApp();
    }
}

void contactList()
{
    const u_int contactCount = allContacts.size();
    for(u_int i = 0; i < contactCount; ++i)
    {
        std::cout << "Contact no" << i + 1 << std::endl;
        std::cout << "Name : " << allContacts[i]._name << std::endl;
        std::cout << "Surname : " << allContacts[i]._surname << std::endl;
        std::cout << "Email : " << allContacts[i]._email << std::endl;
        std::cout << "Date of birth : " << allContacts[i]._dateofBirth << std::endl;
        std::cout << "Phone number : +374" << allContacts[i]._phoneNumber << std::endl;
        std::cout << "Passport ID : " << allContacts[i]._passportID << std::endl;
    }
    std::cout << std::endl;
    std::string tmp{};
    do
    {
        std::cout << "Do you want to do any operations ? (yes/no) : ";
        std::cin >> tmp;
    }
    while(tmp != "yes" && tmp != "no");
    if(tmp == "yes")
    {
        mainMenu();
    }
    else
    {
        exitFromApp();
    }
}

void deleteContact()
{
    std::string check{};
    std::cout << "Enter the contact's passport ID : ";
    std::cin >> check;
    for(u_int i = 0; i < allContacts.size(); ++i)
    {
        if(check == allContacts[i]._passportID)
        {
            allContacts.erase(allContacts.begin() + i);
            std::cout << "The contact was deleted SUCCESSFULLY !" << std::endl;
            return;
        }
    }
    std::cout << "Found nothing by " << check << std::endl; 
    std::string tmp{};
    do
    {
        std::cout << "Do you want to do any operations ? (yes/no) : ";
        std::cin >> tmp;
    }
    while(tmp != "yes" && tmp != "no");
    if(tmp == "yes")
    {
        mainMenu();
    }
    else
    {
        exitFromApp();
    }
}

void searchContact()
{
    std::string id{};
    std::cout << "Enter the contact's password ID : ";
    std::cin >> id;
    for (u_int i = 0; i < allContacts.size(); ++i)
    {
        if(allContacts[i]._passportID == id)
        {
            std::cout << "Contact name : " << allContacts[i]._name << std::endl;
            std::cout << "Contact surname : " << allContacts[i]._surname << std::endl;
            std::cout << "Contact date of birth : " << allContacts[i]._dateofBirth << std::endl;
            std::cout << "Contact phone number : " << allContacts[i]._phoneNumber << std::endl;
            std::cout << "Contact email : " << allContacts[i]._email << std::endl;
            return;
        }
    }
    std::cout << "Found nothing by " << id << std::endl;
    std::string tmp{};
    do
    {
        std::cout << "Do you want to do any operations ? (yes/no) : ";
        std::cin >> tmp;
    }
    while(tmp != "yes" && tmp != "no");
    if(tmp == "yes")
    {
        mainMenu();
    }
    else
    {
        exitFromApp();
    }
}

void editContact()
{
    std::string id{};
    std::string str{};
    std::cout << "Enter the contact's password ID : ";
    std::cin >> id;
    for(u_int i = 0; i < allContacts.size(); ++i)
    {
        if(allContacts[i]._passportID == id)
        {
            int choice = 0;
            std::cout << "What do you want to change ?\n"
            "[1] Name\n[2] Surname\n[3] Date of birth\n"
            "[4] Email\n[5] Phone number\n[6] Passport ID" << std::endl;
            std::cout << "Enter the index [*]\b\b";
            std::cin >> choice;
            switch(choice)
            {
                case 1 : 
                std::cout << "Enter the name you want to change : ";
                std::cin >> str;
                allContacts[i]._name = str;
                str.clear();
                break;
                case 2 :
                std::cout << "Enter the surname you want to change : ";
                std::cin >> str;
                allContacts[i]._surname = str;
                str.clear();
                break;
                case 3 :
                std::cout << "Enter the date of birth you want to change (DD/MM/YYYY)\b\b\b\b\b\b\b\b\b\b";
                std::cin >> str;
                allContacts[i]._dateofBirth = str;
                str.clear();
                break;
                case 4 : 
                std::cout << "Enter the email you want to change : ";
                std::cin >> str;
                allContacts[i]._email = str;
                str.clear();
                break;
                case 5 : 
                std::cout << "Enter the phone number you want to change : ";
                std::cin >> str;
                allContacts[i]._phoneNumber = str;
                str.clear();
                break;
                case 6 : 
                std::cout << "Enter the passport ID you want to change : ";
                std::cin >> str;
                allContacts[i]._passportID = str;
                str.clear();
                break;
            }
        }
    }
    std::string tmp{};
    do
    {
        std::cout << "Do you want to do any operations ? (yes/no) : ";
        std::cin >> tmp;
    }
    while(tmp != "yes" && tmp != "no");
    if(tmp == "yes")
    {
        mainMenu();
    }
    else
    {
        exitFromApp();
    }
}

void browseData(std::string& file)
{
    std::string info{};
    std::string token{};
    std::ifstream text;
    text.open(file);
    text >> info;
    text >> info;
    int count = 0;
    for(int i = 0; i < info.length(); ++i)
    {
        count += i;
    }
    if(count)
    {
        Contact newContact{};
        while (!text.eof())
        {
            text >> token;
            text >> info;
            if (token == "next" && info == "contact" || token == "end")
            {
                allContacts.push_back(newContact);
            }
            if (info == "name")
            {
                newContact._name = token;
            }

            if (info == "surname")
            {
                newContact._surname = token;
            }

            if (info == "date")
            {
                newContact._dateofBirth = token;
            }

            else if (info == "passport")
            {
                newContact._passportID = token;
            }

            else if (info == "phone")
            {
                newContact._phoneNumber = token;
            }

            else if (info == "email")
            {
                newContact._email = token;
            }    
        }   
    }
    text.close();
}