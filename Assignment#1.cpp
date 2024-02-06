#include <cstdlib>
#include <iostream>
using namespace std;

int main(){
    int returnCode = system("dir");
    if(returnCode == 0){
        cout << "Command executed successfully!" << endl;
    }
    else{
        cout << "Command failed to execute or returned non-zero: " << returnCode << endl;
    }
}