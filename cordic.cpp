
#include<bits/stdc++.h>

using namespace std;

int main() {
/*
Values of angles used are stored
*/
float angl[8];
angl[0] = 45;
angl[1] = 26;
angl[2] = 14;
angl[3] = 7;
angl[4] = 3.5;
angl[5] = 1.8;
angl[6] = 0.9;
angl[7] = 0.45;
float sigma = 0.61;

float theta , current_theta;     //we need to calculate cos(theta) and sin(theta)
cin>>theta;
current_theta = 0;
float cos_val, sin_val;         
float X[9],Y[9], Z[9];
for(int i=0;i<9;i++){
    if(i==0){
        X[0] = 1;
        Y[0] = 0;
         
    }
    else{
        Z[i] = theta - current_theta;
        int sign = Z[i]>0 ? 1 : 2;
        X[i] = X[i-1] + pow(-1, sign)*Y[i-1]*pow(2,1-i);                        //rotation equation for next X coordinate
        Y[i] = X[i-1]*pow(-1, sign+1)*pow(2,1-i) + Y[i-1];                      //rotation equation for next Y coordinate
        current_theta = current_theta + pow(-1,sign+1 )*angl[i-1];
    }
    
    
}
cos_val = X[8]*sigma;
sin_val = Y[8]*sigma;

cout<<cos_val<<endl;
cout<<sin_val;
  return 0;
}
