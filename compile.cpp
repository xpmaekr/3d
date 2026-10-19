#include<cstdlib>
using namespace std;

int main(){
    system("g++ main.cpp -o game -I/home/nazk/prs/cppcours/vcpkg/installed/x64-linux/include -L/home/nazk/prs/cppcours/vcpkg/installed/x64-linux/lib -lraylib -lglfw -lGL -lX11 -lXrandr -lXi -lXcursor -lm -lpthread -ldl");
}