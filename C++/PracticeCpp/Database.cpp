#include "Database.h"

namespace Records {
	Database::Database() : mNextEmployeeNumber(kFirstEmployeeNumber)
	{
	}
	Database::~Database()
	{
	}

	Employee& Database::addEmployee(const std::string& firstName, const std::string& lastName)
	{
		// TODO: 여기에 return 문을 삽입합니다.

		Employee theEmployee;
		theEmployee.setFirstName(firstName);
		theEmployee.setLastName(lastName);
		theEmployee.setEmployeeNumber(++mNextEmployeeNumber);
		theEmployee.hire();
		
		mEmployees.push_back(theEmployee);

		return mEmployees[mEmployees.size() - 1];
	}

	Employee& Database::getEmployee(int employeeNumber)
	{
		// TODO: 여기에 return 문을 삽입합니다.
		for (auto& employee : mEmployees) 
		{
			if (employee.getEmployeeNumber() == employeeNumber)
			{
				return employee;
			}
		}
		throw std::runtime_error("No employee found.");
	}

	Employee& Database::getEmployee(const std::string& firstName, const std::string& lastName)
	{
		// TODO: 여기에 return 문을 삽입합니다.
		for (auto& employee : mEmployees)
		{
			if (employee.getFirstName() == firstName && employee.getLastName() == lastName)
			{
				return employee;
			}
		}
		throw std::runtime_error("No employee found.");
	}

	void Database::displayAll() const
	{
		for (const auto& employee : mEmployees)
		{
			employee.display();
		}
	}

	void Database::displayCurrent() const
	{
		for (const auto& employee : mEmployees) {
			if (true == employee.getIsHired())
			{
				employee.display();
			}
		}
	}
	
	void Database::displayFormer() const
	{
		for (const auto& employee : mEmployees)
		{
			if (false == employee.getIsHired())
			{
				employee.display();
			}
		}
	}
}
