#include<iostream>
#include<string>

using namespace std;

// Base class for single inheritance 
class Employee {
    protected :
        string name;
        int employeeId;

    // This is a constructor is member initalizer list 
    // Instead of writing like this 

    // Employee(string &empName, int empID) {
    //     this -> name = empName;
    //     this -> employeeId = empID;
    // }

    // This is short-cut way
    public:
        Employee(const string &empName, int empID) : name(empName), employeeId(empID) {

        }

        void display() const
        {
            cout << "Employee " << name << "ID: " << employeeId << endl;    
        }
};

// Derived class for Single Inheritance

class Developer : public Employee
{
    private:
        string programmingLanguage;
    
    public: 
        Developer(const string &empName, int empID, const string &lang) : Employee(empName, empID) 
        {
            this -> programmingLanguage = lang;
        }

        void show() 
        {
            display();
            cout << "specialization Developer, Programming Language: " << programmingLanguage << endl;
        }
};

// Base Class for Multiple Inheritance 
class ProjectManager
{
    protected: 
        string projectManaged;
    
    // This constructor is member initializer list 
    public: 
        ProjectManager(const string &project) : projectManaged(project)
        {

        }   
    
    void manageProject() const
    {
        cout << "Project manager managing project: " << projectManaged << endl;
    }
};

// Another class as base class for Multiple inheritance 
class TeamLead 
{
    protected: 
        int teamSize;
    public: 
        TeamLead(int size) : teamSize(size) {}

    void leadTeam() const
    {
        cout << "Team Lead leading a team of " << teamSize << " members " << endl;
    }

};

// Derived Class for multiple Inheritance : here I am Inheriting from the three classes Employee, ProjectManager, TeamLead
class TechLead : public Employee , public ProjectManager, public TeamLead
{
    // member initalizer contructor for this derived class 
    public: 
        TechLead(const string &empName, int empID, const string &project, int teamSize) : Employee(empName, empID), ProjectManager(project), TeamLead(teamSize) {}

    void  displayInfo() const
    {
        display();
        manageProject();
        leadTeam();
    }
};

// Base class for Multi-level Inheritance
class HRManager : public Employee  
{
    public: 
        HRManager(const string empName, int empID) : Employee(empName, empID)
        {
            cout << __FUNCTION__ << endl;  // This simply return the function name in Output
        }
    void HandleHRDuties() const
    {
        cout << "HR Manager handling human resource duties." << endl;
    }    
};

// Derived class for Multi-level Inheritance 
class HRDirector : public HRManager
{
    public:
        HRDirector(const string empName, int empID) : HRManager(empName,empID)
        {
            cout << __FUNCTION__ << endl;
        }

        void manageHRDepartment() const 
        {
            cout << "HR director, " << name << " managing HR department. " << endl;
        }
};

// Base class for Hierarchical Inheritance 
class Executive : public Employee
{
    public:
        Executive(const string &empName, int empID): Employee(empName, empID) {}

        void makeExecutiveDecisions() const 
        {
            cout << "Executive making executive decisions. " << endl;
        } 
};

// Derived class for Hierarchical Inheritance 
class CEO : public Executive
{
    public: 
        CEO(const string &empName, int empID) : Executive(empName, empID) {}

        void leadCompany() const 
        {
            makeExecutiveDecisions();
            cout << "CEO " << name << " leading the company" << endl;
        }
};

// Base class for Hybrid Inheritance 
class MarketingManager : public Employee
{
    public: 
        MarketingManager(const string &empName, int empID) : Employee(empName, empID) {}
        
        void createMarketingStrategy() const
        {
            cout << "Marketing manager creating a marketing strategy. " << endl;
        }
};

class SalesManager : public Employee
{
    public:
        SalesManager(const string &empName, int empID) : Employee(empName, empID) {}

        void boostSales() const
        {
            cout << "Sales Manager boosting sales. " << endl;
        }
};

class BusinessDevelopmentManager : public MarketingManager, public SalesManager
{
    public:
    BusinessDevelopmentManager(const string &empName, int empID) : MarketingManager(empName, empID), SalesManager(empName, empID) {}

    void coordinateBusinessDevelopment() const
    {
        createMarketingStrategy();
        boostSales();
        cout << "Business Development Manager coordinating business development efforts. " << endl;
    }
    
};


int main() 
{
    // // single inheritance 
    // Developer dev("Ramu Kaka", 101, "C++");
    // dev.show();

    // Multiple Inheritance 
    // TechLead techLead ("Ashish ", 202, "Project X", 5);
    // techLead.displayInfo();

    // Multi-level Inheritance 
    // HRDirector hrDirector("Gauri Madam", 302);
    // hrDirector.HandleHRDuties();
    // hrDirector.manageHRDepartment();

    // Hierarical Inheritance 
    // CEO ceo("Devi", 404);
    // ceo.leadCompany();

    // Hybrid Inheritance
    BusinessDevelopmentManager bdManager ("Sam Uncle", 706);
    bdManager.coordinateBusinessDevelopment();

    return 0;

}
