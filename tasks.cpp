#include <bits/stdc++.h>
#define nl cout << '\n'
using namespace std;
int table_print(map <string,bool> mp){
    int count = 0;
    for(auto s : mp){
        if(s.first.size() > count) count = s.first.size();
    }
    for(int i = 0 ; i < count + 20;i++){
    cout << '-' ;
    }
    nl;
    cout << setw(count / 2 + 5) << "TASK";
    cout << setw((count + 5) - (count / 2 + 2) - 1) << '|';
    cout << setw(9) << "state";
    cout << setw(4) << '|';
    nl;
    for(int i = 0 ; i < count + 20;i++){
        cout << '-' ;
    }
    nl;
    int i = 1;
    for(auto ele : mp){
        string s = to_string(i) + " - " + ele.first;
        cout << left << setw(count + 5) << s << " | ";
        if(ele.second){
            cout << right << setw(10) << "Completed";
        }
        else{
            cout << right << setw(7) << "---";
        }if(ele.second){
            cout << right << setw(2) << '|';
        }
        else{
            cout << right << setw(5) << '|';
        }
        i++;
        nl;
    }
    for(int i = 0 ; i < count + 20;i++){
        cout << '-' ;
    }
    return 0;
}
int choose_check(string s,int limit){
    int number = 0;
    int mul = 1;
    for(int i = s.length() - 1;i >= 0;i--){
        if(!isdigit(s[i])) return 0;
        else{
            number += (s[i] - 48) * mul;
            mul *= 10;
        }
    }
    if(number > limit) return 0;
    return number;
}

int main(){
    map <string,bool> Tasks;
    cout << "<<<<<<TASK Management Program>>>>>>";
    nl;
    nl;
    cout << "Enter Your First Task : ";
    string s;
    getline(cin,s);
    nl;
    Tasks[s] = false;
    while(true){
        cout << "1- Enter New Task";
        nl;
        cout << "2- Show My Tasks";
        nl;
        cout << "3- Change State of Task";
        nl;
        cout << "4- Delete Task";
        nl;
        cout << "5- Exit";
        nl;
        cout << "Enter Your Choose From 1 To 5 : ";
        string w;
        cin >> w;
        int choose = choose_check(w,5);
        while(!choose){
            cout << "Please Enter a Correct Choose : ";
            cin >> w;
            choose = choose_check(w,5);
        }
        if(choose == 1){
            cout << "Enter Your Task : ";
            string e;
            cin.ignore();
            getline(cin,e);
            cout << "<<*The Task Added Successfully*>>";
            nl;
            Tasks[e] = false;
        }
        else if(choose == 2){
            table_print(Tasks);
            nl;
        }
        else if(choose == 3){
            table_print(Tasks);
            nl;
            cout << "Please enter The Number Of The Task : ";
            string e;
            cin >> e;
            int choose2 = choose_check(e,Tasks.size());
            while(!choose2){
                cout << "Please Enter a Correct Choose : ";
                cin >> e;
                choose2 = choose_check(e,Tasks.size());
            }
            choose2--;
            auto it = Tasks.begin();
            while(choose2--) it++;
            it -> second = !(it -> second);
            cout << "<<*The State Of The Task changed Successfully*>>";
            nl;
        }
        else if(choose == 4){
            table_print(Tasks);
            nl;
            cout << "Please enter The Number Of The Task : ";
            string e;
            cin >> e;
            int choose2 = choose_check(e,Tasks.size());
            while(!choose2){
                cout << "Please Enter a Correct Choose : ";
                cin >> e;
                choose2 = choose_check(e,Tasks.size());
            }
            choose2--;
            auto it = Tasks.begin();
            while(choose2--) it++;
            Tasks.erase(it -> first);
        }else{
            cout << "<<<<<<Thanks For Using Our Program>>>>>>";
            break;
        }

    }
return 0;
}
