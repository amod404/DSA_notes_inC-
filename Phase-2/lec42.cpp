//OOPS-->skkiping as it is basic and theoritical

#include<iostream>
#include<string.h>
#include<strings.h>
#include<string>
#include "lec42_extra.cpp"
//included villan class from a different file
using namespace std;

class Hero{
    private: //can only be accessed inside class
    int ID;

    public:  //can be accessed anywhere    
    char *name;   //properties
    char level;
    int health;

    Hero(){}

    Hero(Hero &temp){
        //deep copy
        char *ch=new char[strlen(temp.name)+1];
        strcpy(ch,temp.name);
        this->name = ch;

        // this->name=temp.name;  //shallow copy

        this->health=temp.health;
        this->level=temp.level;
    }

    void setname(char name[]){
        this->name=name;
    }

    void printdata();
    // {
    //     cout<< "level: "<< this->level<<endl;
    //     cout<< "health: "<< this->health<<endl;
    //     cout<< "name: "<<this->name<<endl;
    // }
};

//difining outside the class
void Hero::printdata(){
        cout<< "level: "<< this->level<<endl;
        cout<< "health: "<< this->health<<endl;
        cout<< "name: "<<this->name<<endl;

}

int main()
{

    // cout << sizeof(Amod) << endl; //4 as int is size 4, health
    //if i take an int and a char -->then 8, as contigous memory of 5 cant be taken, so have to take even 8 byte
    //for empty class size-->1, just for identification
    //(pending)HW-->padding and greedy allignment? and constant keyword and initialization list

    //class includes from another file
    // Villan amod;
    // cout<< sizeof(amod) <<endl;

    Hero Amod;
    char x[12]="Amod_Yadav";
    Amod.setname(x);
    Amod.health=999;
    Amod.level='S';
    Amod.printdata();

    Hero amod(Amod);
    amod.printdata();

    Amod.name[0]='a';
    Amod.printdata();
    amod.printdata();


    return 0;
}