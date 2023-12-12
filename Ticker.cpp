#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>
#include <math.h> 
#include <array>
#include <algorithm>
#include <cmath>
using namespace std;

class State{
public:
std::array<float, 2> state; 
State(std::array<float, 2>& st){ std::copy_n(st.begin(), st.size(), state.begin()); }
};

class Hoin{
public:
float dt;
float w;
float k;
float t;
float w2;
Hoin(float dt, float w, float k, float w2) : dt(dt), w(w), k(k), t(0), w2(w2) {}
void iterate (State &s) {

float vi1;
if (sin(w2*t) > 0) {vi1 = s.state[1] + dt*(-w*w*((s.state[0]))) -k*s.state[1]*dt;}
else {vi1 = s.state[1] + dt*(-w*w*((s.state[0]))) -k*s.state[1]*dt + 2*sin(w2*t)*dt;}

float xi1 = s.state[0] + dt*s.state[1];
s.state[0] = xi1;
s.state[1] = vi1;
t+=dt;};
};

class Iler{
public:
float dt;
float w;
float k;
Iler(float dt, float w, float k) : dt(dt), w(w), k(k) {}
void iterate (State &s) {
float xi1 = s.state[0] + dt*s.state[1];
float vi1 = s.state[1] + dt*(-w*w*((s.state[0]))) - k*s.state[1]*dt; 
s.state[0] = xi1;
s.state[1] = vi1;};
};



int main(){

vector<float> x = {};
vector<float> v = {};
vector<float> Ti = {};
vector<float> E_K = {};
vector<float> E_P = {};
vector<float> E	 = {};
ofstream f("Data.txt");


std::array<float, 2> n = {0.0f, 0.1f};
State ticker(n);
Hoin hoin(0.001, 1, 0.1, 1.05);

for (float t = 0; t <= 400; t+= 0.001){
hoin.iterate(ticker);
x.push_back(ticker.state[0]);
v.push_back(ticker.state[1]);
Ti.push_back(t);
E_K.push_back(ticker.state[1]*ticker.state[1]/2);
E_P.push_back(ticker.state[0]*ticker.state[0]/2);
E.push_back(ticker.state[1]*ticker.state[1]/2 + ticker.state[0]*ticker.state[0]/2);}

ofstream("Data.txt", ios::app);
for (int i =0; i< Ti.size(); i++){
f << Ti[i] << " " << x[i] << " " << v[i] << " " << E_K[i] << " " << E_P[i] << " " << E[i] << endl;}
f.close();

return 0;}

