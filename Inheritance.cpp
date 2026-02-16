#include <iostream>
#include <string>

using namespace std;

class Vehicle {

    // When a member is private we can access this private member using getter setter function 
    protected:
        string name;

    // by-default if we don't specify access modifier it is private
        string model;
        int noOfTyres;

// Below I am writing getter function since this getter is in public scope and we are inheriting it in public mode now this will 
// after inheriting 
    
    string getName() {
        return this -> name;
    }

        // Below I am writing the constructor block
        Vehicle(string _name, string _model, int _noOfTyres){

            cout << "I am inside Vehicle ctor" << endl;

            this->name = _name;
            this->model = _model;
            this->noOfTyres = _noOfTyres;
        }

    public:
        void start_Engine(){
            cout << "Engine is starting " << name << " " << model << endl;
        }

        void stop_Engine() {
            cout << "Engine is stopping " << name << " " << model << endl;
        }
};

class Car : public Vehicle
{
    public:
        int noOfDoors;
        string transmissionType;

// below I have created a constructor block for method Car, since car is child of vehicle so we also need to initialize specific properties 
// of Vehicle like name,model,noOfTyres and we can do this by adding : then adding the properties
    Car(string _name, string _model, int _noOfTyres, int _noOfDoors, string _transmissionType): Vehicle(_name,_model,_noOfTyres) 
    {
        cout << "I am inside car ctor" << endl;
        this -> noOfDoors =  _noOfDoors;
        this -> transmissionType = _transmissionType;
    } 

    void startAC()
    {
        cout << "AC has started of " << getName() << endl;
    }
};

class MotorCycle : public Vehicle
{
    protected :
        string handleBarStyle;
        string suspensionType;

    public: 
        MotorCycle(string _name, string _model, int _noOfTyres, string _handleBarStyle, string _suspensionType) : Vehicle(_name, _model, _noOfTyres)
        {
            cout << "Motorcycle ctor called" << endl;
            this -> handleBarStyle = _handleBarStyle;
            this -> suspensionType = _suspensionType;
        }

        void wheelie() 
        {
            cout << "wheelie kar rahi hai" << " " << name << endl;
        }

        ~MotorCycle()
        {
            cout << "I am inside MotorCycle dtor" << endl;
        }
};

int main() {

    Car A("Maruti 800", "LXI", 4, 4, "Manual" );
    A.start_Engine();
    A.startAC();

    MotorCycle M("BMW", "VXI", 2 , "U", "Stiff" );
    M.start_Engine();
    M.wheelie();
    M.stop_Engine();
    return 0;
}