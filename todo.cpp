#include<iostream>
#include<string>
#include<vector>
using namespace std;
class ToDo{
public:
    void display_menu()
        {
         cout<<"\nTO-DO List:\n";
         cout<<"Menu:\n";
         cout<<"1.Add a new task.\n";
         cout<<"2.Mark task as completed.\n";
         cout<<"3.Display Tasks\n";
         cout<<"4.Exit\n";
         cout<<"Enter your choice:";

        };
        void add_tasks(string t)
        {
            tlist l={false,t};
            //tasks.push_back(t);
            tasks.push_back(l);
            cout<<"Task :"<<t<<" Created\n";
        };
        void display_tasks()
        {
           for (int i=0;i<tasks.size();i++){
        //cout <<i+1<<") "<<tasks[i].task_item << " \n";
        cout<<i+1<<") "<<(tasks[i].isdone ? "[done] " : "[Pending] ")<<tasks[i].task_item<<"\n";
           }
        };
        void mark_done(int tn)
        {
            if(tn<=tasks.size()){
            tasks[tn-1].isdone=true; //array starts from 0,so use -1,else will choose next task.
            cout<<"Task number: "<<tn<<" is marked as done\n";
        }
        else
            cout<<"Invalid Task number\n";
        };
private:
       //vector<string> tasks;
       //string tasks;
       //bool isdone;
       struct tlist{

           bool isdone;
           string task_item;
       };
       vector<tlist> tasks;
};
int main()
{
 string choice;
 string task_name;
 int int_choice;
 ToDo td;
 int task_num;


    while(choice!="4")
        {
        td.display_menu(); //to display everytime until exit
        cin>>choice;

        try{  //to ensure the input is valid
        int_choice=stoi(choice); //stoi to convert string to int
        if (int_choice>4)
        throw choice;
        }
        catch(...){
            int_choice=0;
        }

        switch(int_choice)
        {
        case 1:cout<<"\nEnter the Task:\n"; //to add and store tasks create an array,since we're not sure of size use vector
        cin.ignore(); //to ignore previous new line otherwise getline will not work properly
        getline(cin,task_name);
               //cin>>task_name;
            td.add_tasks(task_name);
            //td.display_menu();

        break;
        case 2:cout<<"\nEnter the task number to mark as completed: ";
        cin>>task_num;
        td.mark_done(task_num);

        break;
        case 3:cout<<"\nTasks are:\n";
               td.display_tasks();
        break;
        case 4:cout<<"\nExiting";
        break;
        default:cout<<"Bad Choice\n";
        break;

    }
    }

return 0;
}
