/*#include<iostream>
using namespace std;

class Employee {

public:
    string Name;
    string Company;
    int age;

    void Introduction(){
        cout<<"Name -"<<Name<<endl;
        cout<<"Company -"<<Company<<endl;
        cout<<"Age -"<<age<<endl;
    }
//Contructor.
    Employee(string name, string company, int Age){
        Name = name;
        Company = company;
        age = Age;
    }
};

int main()
{
    //First Employee.
    Employee emp1 = Employee("Prajwal","Google",25);
    emp1.Introduction();
    //Second Employee.
    Employee emp2 = Employee("Surya","Amazon",25);
    emp2.Name = "Surya";
    emp2.Company = "Amazon";
    emp2.age = 25;
    emp2.Introduction();
}
*/


/*Encapsulation.
#include<iostream>
using namespace std;
//Accessing using public fuction members.
class Employee{

private:
    string Name;
    string Company;
    int Age;

public:
    void setName(string name){
        Name = name;
    }
    string getName(){
        return Name;
    }
    void setCompany(string company){
        Company = company;
    }
    string getCompany(){
        return Company;
    }
    void setAge(int age){
        Age = age;
    }
    int getAge(){
        return Age;
    }

    void Introduction(){
        cout<<"Name -> "<<Name<<endl;
        cout<<"Company -> "<<Company<<endl;
        cout<<"Age -> "<<Age<<endl;
    }

    Employee(string name, string company, int age){
        Name = name;
        Company = company;
        Age = age;
    }
};

int main()
{
    Employee emp1 = Employee("Prajwal", "Google", 25);
    emp1.setAge(22);
    emp1.Introduction();
    return 0;
}*/

//Abstraction.
#include<iostream>
using namespace std;

//Abstract Class.
class AbstractionEmployee{
    virtual void AskForPromotion() = 0;
};

class Employee:AbstractionEmployee{

private:
    string Company;
    int Age;

protected:
    string Name;

public:
    void setName(string name){
        Name = name;
    }
    string getName(){
        return Name;
    }
    void setCompany(string company){
        Company = company;
    }
    string getCompany(){
        return Company;
    }
    void setAge(int age){
        Age = age;
    }
    int getAge(){
        return Age;
    }

    void Introduction(){
        cout<<"Name -> "<<Name<<endl;
        cout<<"Company -> "<<Company<<endl;
        cout<<"Age -> "<<Age<<endl;
    }

    Employee(string name, string company, int age){
        Name = name;
        Company = company;
        Age = age;
    }

    void AskForPromotion(){
        if(Age > 30){
            cout<<Name<<" Got Promoted!"<<endl;
        }
        else{
            cout<<Name<<" Soryy no promotion"<<endl;
        }
    }

    virtual void work(){
        cout<<"Checking emails and task backlog"<<endl;
    }
};
//Inheritance.
class Dev:public Employee{

public:
    string FavProgramminLang; 

    Dev(string name, string company, int age, string favProgramminLang)
        :Employee(name,company,age)
    {
        FavProgramminLang = favProgramminLang;
    }
    void Fixbug(){
        cout<<getName()<<"Fixed Bug Using "<<FavProgramminLang;
        cout<<Name<<"Fixed Bug Using "<<FavProgramminLang;
    }
    void work(){
        cout<<"I am writing code in "<<FavProgramminLang<<endl;
    }

};
//Deriving another class.
class teacher:public Employee {

public:
    string subject;
    void lessons(){
        cout<<Name<<" is preparing"<<subject<<" lesson"<<endl;
    }
    teacher(string name, string company, int age, string sub):Employee(name,company,age){
        subject = sub;
    }
    void work(){
        cout<<Name<<" is teaching "<<subject<<endl;
    }
};

int main()
{
    Employee emp1 = Employee("Prajwal","Google",35);
    Employee emp2 = Employee("Shreyas","Amazon",29);

//    emp1.AskForPromotion();
//    emp2.AskForPromotion();

    Dev d = Dev("Prajwal","Google",35,"c++");
//    d.Fixbug();
    teacher tech = teacher("Jack","Cool School",35,"History");
//    tech.lessons();
//    tech.AskForPromotion();
//Polymorphism.
    Employee *e1 = &d;
    Employee *e2 = &tech;

    e1->work();
    e2->work();
}
