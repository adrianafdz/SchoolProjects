#include <iostream>
#include <sstream>
#include <queue>
#include <stack>
using namespace std;

int main()
{
    string d,data;
    int num, resQ, resP, resS, numQ1, numQ2, numP1, numP2, numS1, numS2;
    queue <int> listaQueue;
    priority_queue <int, vector<int>,greater<int>> listaPrior;
    stack <int> listaStack;
    getline(cin, data);
    while (data != "#"){
        stringstream ss;
        ss<< data;
        while (ss >> d){
            if (d=="/"||d=="+"||d=="*"||d=="-") {
                // QUEUE
                numQ2 = listaQueue.front();
                listaQueue.pop();
                numQ1 = listaQueue.front();
                listaQueue.pop();
                // PRIORITY QUEUE
                numP2 = listaPrior.top();
                listaPrior.pop();
                numP1 = listaPrior.top();
                listaPrior.pop();
                //STACK
                numS2 = listaStack.top();
                listaStack.pop();
                numS1 = listaStack.top();
                listaStack.pop();
                if (d=="+") {
                    resQ = numQ1 + numQ2;
                    resP = numP1 + numP2;
                    resS = numS1 + numS2;
                }
                if (d=="-") {
                    resQ = numQ1 - numQ2;
                    resP = numP1 - numP2;
                    resS = numS1 - numS2;
                }
                if (d=="/") {
                    resQ = numQ1 / numQ2;
                    resP = numP1 / numP2;
                    resS = numS1 / numS2;
                }
                if (d=="*") {
                    resQ = numQ1 * numQ2;
                    resP = numP1 * numP2;
                    resS = numS1 * numS2;
                }
                listaQueue.push(resQ);
                listaPrior.push(resP);
                listaStack.push(resS);
            } else {
                num = stoi(d);
                listaQueue.push(num);
                listaPrior.push(num);
                listaStack.push(num);
            }
        }
        cout << listaStack.top() << " " << listaQueue.front() << " " << listaPrior.top() << endl;

        listaQueue.pop();
        listaPrior.pop();
        listaStack.pop();
        //cout <<  "Termine linea" << endl;
        getline(cin, data);
    }
}
