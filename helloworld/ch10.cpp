#include <iostream>
using namespace std;

// namespace gnadi{
//     int n;
//     void set(){
//         gnadi::n = 10;
//     }
// }

// struct TV{

// private:
//     bool powerOn;
//     int channel;
//     int volume;

// public:
//     TV(){
//         cout<<"생성자 호출"<<endl;
//     }
//     ~TV(){
//         cout<<"소멸자 호출"<<endl;
//     }
//     void setVolume(int vol){
//         if(vol>=0 && vol <= 100){
//             volume = vol;
//         }
//     }
// };

class Color{
public:
    Color() : r(0), g(0), b(0) {}
    Color(float r, float g, float b) : r(r), g(g), b(b) {}

    float GetR(){
        return r;
    }
    float GetG(){
        return g;
    }
    float GetB(){
        return b;
    }

    static Color MixColors(Color aa, Color bb){
        Color result((aa.r+bb.r)/2, (aa.g+bb.g)/2, (aa.b+bb.b)/2);
        return result;
    }  

private:
    float r;
    float g;
    float b;

};



int main(){

   
    // TV mytv;
    // mytv.powerOn = true;
    // mytv.channel = 10;
    // mytv.volume = 50;

    Color a(1,1,0);
    Color b(1,0,1);
    Color c;

    c = Color::MixColors(a,b);
    cout<<c.GetR()<<' '<<c.GetG()<<' '<<c.GetB()<<endl;


    return 0;
}