//OOPs-4 pillar (imp)

#include<iostream>
#include<vector>
#include<string>
#include<string.h>
#include<strings.h>
using namespace std;

//encapsulation
class Student {

    private:
        string name;
        int age=18;
        int height;
    public:
        int getAge(){
            return age;
        } 
};

//inheritance.....skipping some parts
class Human {

    public:
        int height;
        int weight;
        int age;

        Human(){
            cout<<"\nI am awake\n\n";
        }
        int getAge(){
            return age;
        }

        void setage(int age){
            this->age=age;
        }

};

class Male : public Human {
    
    public:
        string cloth;

        int getWeight(){
            return weight;
        }
        void setWeight(int weight){
            this->weight=weight;
        }
        string getCloth(){
            return cloth;
        }
        void setcloth(string cloth){
            this->cloth=cloth;
        }
        ~Male(){
            cout<< "\nI slept\n";
        }

};

int main()
{
    // Student first;
    // cout<< first.getAge()<<endl;
    // cout<<"Sab sahi chl rha hai"<<endl;
    
    //Inheritance
    // Male Satvik;   //constructor of parent class will be called
    // Satvik.setage(16);
    // cout<<"Age is: "<<Satvik.getAge()<<endl;
    // Satvik.setcloth("Nikkar");
    // cout<<"wearing "<<Satvik.getCloth()<<endl;
    //destructor of child class will be called
    
    
    return 0;
}