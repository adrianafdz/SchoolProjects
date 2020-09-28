// Adriana Fernandez

#include <iostream>
#include <map>
#include <queue>

using namespace std;


bool lookBook (map<int,string> book, int phone) {
    map<int, string>::iterator itr;
    for (itr=book.begin(); itr != book.end(); itr++) {
        if (itr->first==phone) {
            //cout<<itr->first << " " << itr->second<<endl;
            return true;
        }
    }
    return false;
}

int main()
{
    map<int,string> book;
    int n, phone;
    string query, name;
    map<int, string>::iterator itr;
    queue<string> result;

    cout<<"Number of queries: ";
    cin>>n;
    for (int i=0; i<n; i++) {
        cout<<"Options: add, find, del"<<endl;
        cin>>query;
        cout<<"Phone: ";
        cin>>phone;
        if (query=="add") {
            cin>>name;
            if (lookBook(book, phone)) {
                book[phone]=name;
            } else {
                book.insert(pair<int,string>(phone,name));
            }

        } else if (query=="find") {
            if (lookBook(book, phone)) {
                result.push(book[phone]);
                //cout<<book[phone]<<endl;
            } else {
                result.push("not found");
                //cout<<"not found"<<endl;
            }
        } else if(query=="del") {
            if (lookBook(book, phone)) {
                book.erase(phone);
            }
        }
    }
    //cout<<endl<<"Find query results:"<<endl;
    int tam=result.size();
    for (int i=0; i<tam; i++) {
        cout<<result.front()<<endl;
        result.pop();
    }

//    cout<<endl<<"PHONE BOOK"<<endl;
//    for (itr=book.begin(); itr != book.end() ;itr++) {
//        cout<<itr->first << " " << itr->second<<endl;
//    }
}
