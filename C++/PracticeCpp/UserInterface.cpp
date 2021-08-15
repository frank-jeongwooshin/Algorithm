#include "UserInterface.h"

UserInterface::UserInterface()
{
    done = false;
}

void UserInterface::run()
{
    while (false == done) 
    {
        int selection = displayMenu();

        switch (selection) 
        {
        case 1:
            doHire(mEmployeeDb);
            break;

        case 2:
            doFire(mEmployeeDb);
            break;

        case 3:
            doPromote(mEmployeeDb);
            break;

        case 4:
            doDemote(mEmployeeDb);
            break;

        case 5:
            mEmployeeDb.displayAll();
            break;

        case 6:
            mEmployeeDb.displayCurrent();
            break;

        case 7:
            mEmployeeDb.displayFormer();
            break;

        case 0:
            done = true;
            break;

        default:
            std::cerr << "Unkown Command !!" << std::endl;
            break;
        }
    }
}

int UserInterface::displayMenu()
{
    int selection;
    std::cout << std::endl;
    std::cout << "Employee Database" << std::endl;
    std::cout << "-------------------" << std::endl;

    std::cout << "1) Hire a New Employee" << std::endl;
    std::cout << "2) Fire an Employee" << std::endl;
    std::cout << "3) Promote an Employee" << std::endl;
    std::cout << "4) Demote an Employee" << std::endl;
    std::cout << "5) List All Employees" << std::endl;
    std::cout << "6) List Current Employees" << std::endl;
    std::cout << "7) List Former Employees" << std::endl;
    std::cout << "0) Quit\n" << std::endl;
    std::cout << "--->";
    std::cin >> selection;

    return selection;
}

void UserInterface::doHire(Records::Database& db)
{
    std::string firstName;
    std::string lastName;

    std::cout << "First Name? ";
    std::cin >> firstName;
    std::cout << "Last Name? ";
    std::cin >> lastName;

    try
    {
        db.addEmployee(firstName, lastName);
    }
    catch (const std::exception& exception)
    {
        std::cerr << "Unable to Add New Employee: " << exception.what() << std::endl;
    }
}

void UserInterface::doFire(Records::Database& db)
{
    int employeeNumber;
    std::cout << "Employee Number? ";
    std::cin >> employeeNumber;

    try
    {
        Records::Employee& emp = db.getEmployee(employeeNumber);
        emp.fire();
        std::cout << "Employee " << employeeNumber << " terminated." << std::endl;
    }
    catch (const std::exception& exception)
    {
        std::cerr << "Unable to Terminate Employee: " << exception.what() << std::endl;
    }
}

void UserInterface::doPromote(Records::Database& db)
{
    int employeeNumber;
    int raiseAmount;

    std::cout << "Employee Number? ";
    std::cin >> employeeNumber;
    std::cout << "How Much of a Raise? ";
    std::cin >> raiseAmount;

    try
    {
        Records::Employee& emp = db.getEmployee(employeeNumber);
        emp.promote(raiseAmount);
    }
    catch (const std::exception& exception)
    {
        std::cerr << "Unable to Promote Employee: " << exception.what() << std::endl;
    }
}

void UserInterface::doDemote(Records::Database& db)
{
    int employeeNumber;
    int layAmount;

    std::cout << "Employee Number? ";
    std::cin >> employeeNumber;
    std::cout << "How Much of a lay? ";
    std::cin >> layAmount;

    try
    {
        Records::Employee& emp = db.getEmployee(employeeNumber);
        emp.demote(layAmount);
    }
    catch (const std::exception& exception)
    {
        std::cout << "Unable to Demote Employee: " << exception.what() << std::endl;
    }
}

