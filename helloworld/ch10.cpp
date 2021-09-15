#include <iostream>
using namespace std;

namespace gnadi{
    int n;
    void set(){
        gnadi::n = 10;
    }
}

struct TV{

private:
    bool powerOn;
    int channel;
    int volume;

public:
    TV(){
        cout<<"생성자 호출"<<endl;
    }
    ~TV(){
        cout<<"소멸자 호출"<<endl;
    }
    void setVolume(int vol){
        if(vol>=0 && vol <= 100){
            volume = vol;
        }
    }
};

int main(){

   
    TV mytv;
    // mytv.powerOn = true;
    // mytv.channel = 10;
    // mytv.volume = 50;

    return 0;
}