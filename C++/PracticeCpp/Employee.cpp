#include "Employee.h"

namespace Records {
	Employee::Employee()
		: mFirstName("")
		, mLastName("")
		, mEmployeeNumber(-1)
		, mSalary(kDefaultStartingSalary)
		, mHired(false)
	{
	}

	Employee::~Employee()
	{
	}

	void Employee::promote(int raiseAmount) 
	{
		setSalary(getSalary() + raiseAmount);
	}

	void Employee::demote(int demeritAmount)
	{
		setSalary(getSalary() - demeritAmount);
	}

	void Employee::hire()
	{
		mHired = true;
	}

	void Employee::fire()
	{
		mHired = false;
	}

	void Employee::display() const
	{
		std::cout << "Employee: " << getLastName() << ", " << getFirstName() << std::endl;
		std::cout << "----------------------------------" << std::endl;
		std::cout << (mHired ? "Current Employee" : "Former Employee") << std::endl;
		std::cout << "Employee Number: " << getEmployeeNumber() << std::endl;
		std::cout << "Salary: $" << getSalary() << "\n" << std::endl;
	}

	// Setter & Getter
	void Employee::setFirstName(const std::string& firstName)
	{
		mFirstName = firstName;
	}
	const std::string& Employee::getFirstName() const
	{
		// TODO: 여기에 return 문을 삽입합니다.
		return mFirstName;
	}

	void Employee::setLastName(const std::string& lastName)
	{
		mLastName = lastName;
	}
	
	const std::string& Employee::getLastName() const
	{
		return mLastName;
	}

	void Employee::setEmployeeNumber(int employeeNumber)
	{
		mEmployeeNumber = employeeNumber;
	}

	int Employee::getEmployeeNumber() const
	{
		return mEmployeeNumber;
	}

	void Employee::setSalary(int newSalary)
	{
		mSalary = newSalary;
	}

	int Employee::getSalary() const
	{
		return mSalary;
	}

	bool Employee::getIsHired() const
	{
		return mHired;
	}
}