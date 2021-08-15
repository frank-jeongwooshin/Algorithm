/**
	������ �Ѹ��� �����͸� �߻�ȭ
*/
#pragma once
#include <string>
#include <iostream>

namespace Records {
	// ���� ����� ù �޿� �׼�
	const int kDefaultStartingSalary = 30000;

	class Employee
	{
	public:
		Employee();
		~Employee();

		void promote(int raiseAmount = 1000);
		void demote(int demeritAmount = 1000);
		void hire();
		void fire();
		// �ֿܼ� ������ ���� ���
		void display() const;

		// Setter & Getter
		void setFirstName(const std::string& firstName);
		const std::string& getFirstName() const;

		void setLastName(const std::string& lastName);
		const std::string& getLastName() const;

		void setEmployeeNumber(int employeeNumber);
		int getEmployeeNumber() const;

		void setSalary(int newSalary);
		int getSalary() const;

		bool getIsHired() const;

	private:
		std::string mFirstName;
		std::string mLastName;
		int mEmployeeNumber;
		int mSalary;
		bool mHired;
	};
}

