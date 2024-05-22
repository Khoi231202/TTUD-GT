/*
S0[i]: dãy con lớn nhất có tổng chẵn dãy a1,a2,...ai kết thúc tại ai
S1[i]: dãy con lớn nhất có tổng lẻ dãy a1,a2,...ai kết thúc tại ai
B0[i]: true nếu S0[i] có lời giải
B1[i]: true nếu S1[i] có lời giản

cơ sở i=1
nếu a1 lẻ: B0[i]=false; S1[1]=a[1]; B1[1]=true;
néu a1 chẵn: S0[1]=a1; B0[1]=true; B1[1] =false;

công thức truy hồi
nếu ai chẵn:
    nếu B0[i-1] = true:
        S0[i]=max(ai, ai + S0[i-1]); B0[i]=true;
    else B0[i-1] = false:
        S0[i]=ai; B0[i]=true;
    nếu B1[i-1]=true:
        S1[i] = ai + S1[i-1]; B1[i] = true;
    else:
        B1[i]=false;
nếu ai lẻ:
    nếu B0[i-1]=true:
        S0[i] = ai + S1[i-1]; B0[i]=true;
    else: B0[i]=false;
    nếu B0[i-1]=true;
        S1[i]=max(ai, ai + S0[i-1]); B1[i] = true;
    else: S1[i] = ai; B1[i] = true;
*/
#include<iostream>
using namespace std;

    