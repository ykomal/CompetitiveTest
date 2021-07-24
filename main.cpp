#include "main.h"
#include  <bits/stdc++.h>
using namespace std;

int getNumberOf5(int number) {
  int no = 0;
  while(number > 0){
    no += number/5;
    number = number/5; 
  }
  return no;
}

void myCode() {
  int t;
  cin>>t;
  while(t--) {
    int n;
    cin>>n;
    int noOf5 = getNumberOf5(n);
    cout<<noOf5<<endl;
  }
}

int main() {
  changingInputOutputStream();
  myCode(); // Enter your function 
  compareGeneratedOutput();
  return 0;
}