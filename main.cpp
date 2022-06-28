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
void flipDownard(const string name){
    ofstream file(name);
    //ifstream i(name);

    //of<<"P3"<<endl<<n*2<<" "<<2<<endl<<"255"<<endl;

}

/*
copy of a ppm image file 
the process consist of reading the width and the height, and  P3 code(that indicate the software reader that the ppm image is of type P3)
then copy the data, and pate them in a new created file
*/
void copyFile(const string& name){
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



void deux(const string &name){
    ofstream file("deux_"+name);
    ifstream ist(name);
    if(!ist || !file)return;
    string p3;int height,width;
    ist>>p3>>width>>height>>p3;
    file<<"P3"<<endl<<height<<" "<<width<<endl<<"255"<<endl;

    //creating of a 2Dtable that will store the image data (input data)
    vector<vector<Pixel>>v(height,vector<Pixel>(width));
    for(int h=0;h<height;h++){
        for(int w=0;w<width;w++){
            ist>>v[h][w].r>>v[h][w].g>>v[h][w].b;
        }
    }
    
    /*
    for(int newHeight=0;newHeight<=width-1;newHeight++){
        for(int newWidth=0;newWidth<=height-1;newWidth++){
            file<<v[newWidth][newHeight].r<<" "<<v[newWidth][newHeight].g<<" "<<v[newWidth][newHeight].b<<" ";
        }file<<endl;
    }*/
}
void trois(const string &name){
    ofstream file("trois_"+name);
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


























void firstFunction(const string& s){
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
            f<<v[x].r<<" "<<v[x].g<<" "<<v[x].b<<" ";
        }f<<endl;
    }
    iff.close();
    f.close();
}
void secondFunction(const string& s){
    ofstream f("second_"+s);
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
void thirdFunction(const string& val){
    ofstream f("third_"+val);
    ifstream iff(val);
    if(!f or !iff)return;
    int width=0,height=0;
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
        for(int x=height-1;x>=0;x--){
            f<<v[x][y].r<<" "<<v[x][y].g<<" "<<v[x][y].b<<" ";
        }f<<endl;
    }
    f.close();
    iff.close();
}
void addTwoImages(const string val1,const string & val2,int rrr=250,int ggg=250,int bbb=250){
    ifstream iff1(val1);
    ifstream iff2(val2);
    ofstream f(val1+"_"+val2);
    if(not iff1 or not iff2 or not f)return;
    int height1=0,width1=0;
    int height2=0,width2=0;
    string p3="";
    iff1>>p3>>width1>>height1>>p3;
    iff2>>p3>>width2>>height2>>p3;
    int finalHeight=0,finalWidth=0;
    finalWidth=width1+width2 ;
    finalHeight=height1>height2? height1:height2;
    f<<"P3"<<endl<<finalWidth<<" "<<finalHeight<<endl<<"255"<<endl;
    int hIter=height1>height2? height2:height1;
    for(int y=0;y<hIter;y++){
        vector<Pixel>v1(width1);
        vector<Pixel>v2(width2);
        for(int x=0;x<width1;x++)
            iff1>>v1[x].r>>v1[x].g>>v1[x].b;
        for(int x=0;x<width1;x++)
            f<<v1[x].r<<" "<<v1[x].g<<" "<<v1[x].b<<" ";
        for(int x=0;x<width2;x++)
            iff2>>v2[x].r>>v2[x].g>>v2[x].b;
        for(int x=0;x<width2;x++)
            f<<v2[x].r<<" "<<v2[x].g<<" "<<v2[x].b<<" ";
    }

    if(height1>height2){
        cout<<">>>height1>height2";
        vector<Pixel>v1(width1);
        for(int x=0;x<width1;x++)
            iff1>>v1[x].r>>v1[x].g>>v1[x].b;
        for(int x=0;x<width1;x++)
            f<<v1[x].r<<" "<<v1[x].g<<" "<<v1[x].b<<" ";
        for(int x=0;x<width2;x++)
            f<<rrr<<" "<<ggg<<" "<<bbb<<" ";
    }else if(height2>height1){
        cout<<">>>height1<height2";
        vector<Pixel>v1(width2);
        for(int x=0;x<width2;x++)
            f<<rrr<<" "<<ggg<<" "<<bbb<<" ";
        for(int x=0;x<width2;x++)
            iff1>>v1[x].r>>v1[x].g>>v1[x].b;
        for(int x=0;x<width2;x++)
            f<<v1[x].r<<" "<<v1[x].g<<" "<<v1[x].b<<" ";
    }
}
void laisseRouge(const string& val1){
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
void rotationD(const string & val){
    ifstream iff(val);
    ofstream off("rotationD.ppm");
    if(not iff or not off)return;
    int l,h;
    string p3;
    iff>>p3>>l>>h>>p3;
    off<<"P3"<<endl<<h<<" "<<l<<endl<<"255"<<endl;
    vector<vector<Pixel>>v(h,vector<Pixel>(l));
    for(int x=0;x<h;x++){
        for(int y=0;y<l;y++){
            iff>>v[x][y].r>>v[x][y].g>>v[x][y].b;
        }
    }
    for(int x=0;x<l;x++){
        for(int y=h-1;y>=0;y--){
            off<<v[y][x].r<<" "<<v[y][x].g<<" "<<v[y][x].b<<" ";
        }off<<endl;
    }
}
int main(){
    string p="Poissons.ppm";
    rotationD(p);
    cout<<"hello world"<<endl;
    return 0;
}
