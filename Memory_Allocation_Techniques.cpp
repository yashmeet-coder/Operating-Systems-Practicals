#include <iostream>
using namespace std;
class memory_allocation_technique
{
public:
    int n;
    int *block_no;
    int *process_size;
    int *block_size;
    memory_allocation_technique(int no_of_process){
        n = no_of_process;
    }
    void input( )
    {   
        block_no = new int[n+1];
        process_size = new int[n];
        block_size = new int[n+1];
        for (int i = 0; i < n + 1; i++)
        {
            block_no[i] = i + 1;
            cout << "ENTER THE BLOCK SIZE " + to_string(i + 1) + ":";
            cin >> block_size[i];
        }
        for (int i = 0; i < n; i++)
        {
            cout << "ENTER THE PROCESS SIZE P" + to_string(i + 1) + ":";
            cin >> process_size[i];
        }
    }
    void display()
    {
        cout << "BLOCK NO :";
        for (int i = 0; i < n + 1; i++)
        {
            cout << to_string(block_no[i]) + " ";
        }
        cout << endl;
        cout << "PROCESS SIZE :";
        for (int i = 0; i < n; i++)
        {
            cout << to_string(process_size[i]) << " ";
        }
        cout << endl;
        cout << "BLOCK SIZE :";
        for (int i = 0; i < n + 1; i++)
        {
            cout << to_string(block_size[i]) + " ";
        }
        cout << endl;
    }
    void first_fit()
    {

        cout << "PROCESS\t\tPROCESS SIZE\t\tBLOCK NO" << endl;
        for (int i = 0; i < n; i++)
        {
            int temp = -1;
            for (int j = 0; j < n + 1; j++)
            {
                if (process_size[i] <= block_size[j])
                {
                    temp = j;
                    block_size[j] -= process_size[j];
                    cout << "P" + to_string(i + 1) + " \t\t" + to_string(process_size[i]) + "\t\t\t  " + to_string(temp + 1) << endl;
                    break;
                }
            }
            if (temp == -1)
            {
                    cout << "P" + to_string(i + 1) + " \t\t" + to_string(process_size[i]) + "\t\t\t" + "NOT ALLOCATED" << endl;
            }
        }
    }

    void worst_fit(){
          cout << "PROCESS\t\tPROCESS SIZE\t\tBLOCK NO" << endl;
          for (int i = 0; i < n; i++)
          {
            int max=0 ;
            int temp = -1;
            for (int j = 0; j < n+1; j++)
            {
                if(block_size[j]>process_size[i]){
                    int k = block_size[j]-process_size[i];
                    if(k>max)
                    {
                        max = k;
                        temp = j;
                    }
                }
            }
            block_size[temp]=0;
            if(temp == -1){
                cout << "P" + to_string(i + 1) + " \t\t" + to_string(process_size[i]) + "\t\t\t" + "NOT ALLOCATED" << endl;
            }
            else{
                cout << "P" + to_string(i + 1) + " \t\t" + to_string(process_size[i]) + "\t\t\t  " + to_string(temp + 1) << endl;
            }
          }
          
    }
    void best_fit(){
           cout << "PROCESS\t\tPROCESS SIZE\t\tBLOCK NO" << endl;
           for (int i = 0; i < n; i++)
           {
                int minimum = 999999;
                int temp;
                for (int j = 0; j < n+1; j++)
                {
                    if(block_size[j]>process_size[i]){
                        int k=block_size[j]-process_size[i];
                        if(abs(k)<minimum){
                            minimum = k;
                            temp =j;
                        }
                    }
                }
                block_size[temp]=0;
                cout << "P" + to_string(i + 1) + " \t\t" + to_string(process_size[i]) + "\t\t\t  " + to_string(temp + 1) << endl;
           }
           
    }
};
int main()
{   int n;
    cout<<"ENTER THE NUMBER OF PROCESSES :";
    cin>>n;
    memory_allocation_technique obj1(n);
   
    while(true){
         obj1.input();
         obj1.display();
        int choice;
        cout<<endl;
        cout<<"PRESS 0 TO EXIT"<<endl;
        cout<<"PRESS 1 FOR FIRST FIT ALLOCATION"<<endl;
        cout<<"PRESS 2 FOR WORST FIT ALLOCATION"<<endl;
        cout<<"PRESS 3 FOR BEST FIT ALLOCATION"<<endl;
        cout<<"ENTER YOUR CHOICE :";
        cin>>choice;
        switch (choice)
        {
        case 0:
            break;
        case 1:
            obj1.first_fit();
            //return 0;
            break;
        case 2:
            obj1.worst_fit();
           // return 0;
            break;
        case 3:
            obj1.best_fit();
            //return 0;
            break;
        default:
            cout<<"ENTER A VALID CHOICE"<<endl;
            break;
        }
    }
    return 0;
}
