#include<iostream>
#include <fstream>
#include <istream>
#include<vector>
using namespace std;

struct Pixel{
    int r,g,b;
};
//generate a square file with height=n*2, and width=n*2
void genereCarre(int n,const string &name){
    ofstream file(name);
    if(!file)return;
    file<<"P3"<<endl<<n*2<<" "<<n*2<<endl<<"255"<<endl;
    for(int y=0;y<n;y++){
        for(int x=0;x<n;x++){
            file<<"255 255 0 ";
        }
        for(int x=0;x<n;x++){
            file<<"255 0 255 ";
        }
    }
    for(int y=0;y<n;y++){
        for(int x=0;x<n;x++){
            file<<"0 255 255 ";
        }
        for(int x=0;x<n;x++){
            file<<"255 255 255 ";
        }
    }
}

void rotateClockwise(const string &name){
    ofstream file("rotated_clockwise_"+name);
    ifstream ist(name);
    if(!ist || !file)return;
    string p3;int height,width;
    ist>>p3>>width>>height>>p3;
    file<<"P3"<<endl<<height<<" "<<width<<endl<<"255"<<endl;

    vector<vector<Pixel>>v(height,vector<Pixel>(width));
    for(int h=0;h<height;h++){
        for(int w=0;w<width;w++){
            ist>>v[h][w].r>>v[h][w].g>>v[h][w].b;
        }
    }
    for(int newHeight=0;newHeight<=width-1;newHeight++){
        for(int newWidth=height-1;newWidth>=0;newWidth--){
            file<<v[newWidth][newHeight].r<<" "<<v[newWidth][newHeight].g<<" "<<v[newWidth][newHeight].b<<" ";
        }file<<endl;
    }
}

void transform2(const string& s){
    ofstream f("first_function"+s);
    ifstream iff(s);
    if(!f or !iff)return;
    string p3="";
    int width=0,height=0;
    iff>>p3>>width>>height>>p3>>p3;
    f<<"P3"<<endl<<width<<" "<<height<<endl<<"255"<<endl;
    vector<Pixel>v;
    v.clear();
    v.resize(width);
    for(int y=0;y<height;y++){
        for(int x=0;x<width;x++){
            iff>>v[x].r>>v[x].g>>v[x].b;
        }
        for(int x=width-1;x>=0;x--){
            //f<<v[x].r<<" "<<v[x].g<<" "<<v[x].b<<" ";
            f<<" "<<v[x].r<<" "<<v[x].g<<" "<<v[x].b<<" ";
        }f<<endl;
    }
    iff.close();
    f.close();
}
void rotateAnticlockwiseAndFlip(const string& s){
    ofstream f("rotateAnticlockwiseAndFlip_"+s);
    ifstream iff(s);
    if(!f or !iff)return;
    int height=0,width=0;
    string p3="";
    iff>>p3>>width>>height>>p3;
    f<<"P3"<<endl<<height<<" "<<width<<endl<<"255"<<endl;
    vector<vector<Pixel>>v(height,vector<Pixel>(width));
    for(int y=0;y<height;y++){
        for(int x=0;x<width;x++){
            iff>>v[y][x].r>>v[y][x].g>>v[y][x].b;
        }
    }
    for(int y=0;y<width;y++){
        for(int x=0;x<height;x++){
            f<<v[x][y].r<<" "<<v[x][y].g<<" "<<v[x][y].b<<" ";
        }f<<endl;
    }
    f.close();
    iff.close();

}
void onlyRouge(const string& val1){
    ifstream iff1(val1);

    ofstream f("Rouge.ppm");
    if(not iff1 or not f)return;
    int l,h,nul,rr;

    string p3="";
    iff1>>p3>>l>>h>>p3;
    f<<"P3"<<endl<<l<<" "<<h<<endl<<"255"<<endl;
    for(int x=0;x<h;x++){
        for(int y=0;y<l;y++){
            iff1>>rr>>nul>>nul;
            f<<rr<<" 0 0 ";
        }f<<endl;
    }
}

void transform(const string& name){
    //output image
    ofstream file("copy_"+name);
    ifstream ist(name);

    //if the image is not not readable or not found ,..
    if(!file || !ist)return;
    string p3;
    int height,width;
    ist>>p3>>height>>width>>p3;
    file<<"P3"<<endl<<height<<" "<<width<<endl<<"255"<<endl;
    vector<Pixel>v;
    v.resize(width);
    for(int h=0;h<height;h++){
        for(int w=0;w<width;w++){
            ist>>v[w].r>>v[w].g>>v[w].b;
        }
        for(int w=width-1;w>=0;w--){
            file<<v[w].r<<" "<<v[w].g<<" "<<v[w].b<<" ";
        }file<<endl;
    }
}
int main(){
    string p="Poissons.ppm";
    genereCarre(50,"generated.ppm");
    genereCarre(150,"generated_again.ppm");
    rotateAnticlockwiseAndFlip(p);
    cout<<"hello world"<<endl;
    


    return 0;
}
