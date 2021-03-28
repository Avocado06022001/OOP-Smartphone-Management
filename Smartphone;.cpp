#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<fstream>
class CPU{
protected:
    string maCPU;
    string loaiCPU;
    string hang;
    double socore;
    double xungnhip;
    double gianhap;
public:
    CPU(){}
    virtual void ganGiatri(){}
    double giathanhphan(){return this->gianhap;}
    void displayInfo(){
        cout<<"CPU: "<<maCPU<<" "<<loaiCPU<<" "<<hang<<" "<<socore<<" "<<xungnhip<<" "<<gianhap;
    }

    string ganvaoFile(){
        string output="CPU: "+ maCPU+" "+loaiCPU+" "+hang+" "+to_string(socore)+" "+ to_string(xungnhip)+" "+to_string(gianhap);
        return output;
    }
};

class Alpha: public CPU{
public:
    void ganGiatri(){
        string macpu;
        this->gianhap=200;
        this->socore=2;
        this->xungnhip=1.8;
        this->hang="Black";
        this->loaiCPU="Alpha";
        cout<<"Nhap ma CPU: ";
        cin>>macpu;
        this->maCPU=macpu;
    }
};

class Gamma:public CPU{
public:
    void ganGiatri(){
        string macpu;
        this->gianhap=600;
        this->socore=4;
        this->xungnhip=2.6;
        this->hang="White";
        this->loaiCPU="Gamma";
        cout<<"Nhap ma CPU: ";
        cin>>macpu;
        this->maCPU=macpu;
    }
};

class Beta:public CPU{
public:
    void ganGiatri(){
        string macpu;
        this->gianhap=400;
        this->socore=4;
        this->xungnhip=2.46;
        this->hang="Black";
        this->loaiCPU="Beta";
        cout<<"Nhap ma CPU: ";
        cin>>macpu;
        this->maCPU=macpu;
    }
};

class ManHinh{
protected:
    string mamanhinh;
    string hangsanxuat;
    string dophangiai;
    double gianhap;
    double kichthuoc;
public:
    ManHinh(){}
    void setGiatridau(){
        string code, producer;
        int num;
        this->kichthuoc=4.7;
        cout<<"Nhap ma man hinh: ";
        cin>>code;
        this->mamanhinh=code;
        cout<<"Hang san xuat: ";
        cin>>producer;
        this->hangsanxuat=producer;
    }
    double giathanhphan(){return this->gianhap;}
    void displayInfo(){
        if (gianhap==500){
            cout<<"Man hinh: "<<mamanhinh<<" "<<hangsanxuat<<" "<<dophangiai<<" "<<gianhap<<" "<<"co chong loa";
        }else{
            cout<<"Man hinh: "<<mamanhinh<<" "<<hangsanxuat<<" "<<dophangiai<<" "<<gianhap<<" "<<"khong chong loa";
        }
    }

    string ganvaoFile(){
        string output;
        if (gianhap==500){
            output="Man hinh: "+ mamanhinh+" "+hangsanxuat+" "+dophangiai+" "+to_string(gianhap)+" co chong loa";
        }else{
            output="Man hinh: "+ mamanhinh+" "+hangsanxuat+" "+dophangiai+" "+to_string(gianhap)+" khong chong loa";
        }
        return output;
    }

    double getGia(){return this->gianhap;}
};

class HD:public ManHinh{
public:
    void ganGiatri(){
        this->dophangiai="HD";
        this->gianhap=200;
    }
};

class FullHD:public ManHinh{
public:
    void ganGiatri(){
        this->dophangiai="FullHD";
        int num;
        cout<<"Chong loa hay khong (1-co, 2-khong): ";
        cin>>num;
        if (num==1){this->gianhap=500;}
        else{this->gianhap=300;}
    }
};

class Vo{
protected:
    string mavo;
    string loaivo;
    string hang;
    double gianhap;
    string mausac;
public:
    Vo(){}
    virtual void ganGiatri(){}
    double giathanhphan(){return this->gianhap;}
    void displayInfo(){
        cout<<"Vo Smartphone: "<<mavo<<" "<<loaivo<<" "<<hang<<" "<<mausac<<" "<<gianhap;
    }

    string ganvaoFile(){
        string output="Vo Smartphone: "+ mavo+" "+loaivo+" "+hang+" "+mausac+" "+ to_string(gianhap);
        return output;
    }
};

class voNhom: public Vo{
public:
    void ganGiatri(){
        this->loaivo="nhom";
        int num;
        string code;
        cout<<"Nhap ma vo: ";
        cin>>code;
        this->mavo=code;
        this->gianhap=400;
        this->hang="Black";
        cout<<"Nhap mau (1-do, 2-den): ";
        cin>>num;
        if (num==1){this->mausac="do";}
        else{this->mausac="den";}
    }
};

class voNhua: public Vo{
public:
    void ganGiatri(){
        this->loaivo="nhua";
        int num;
        string code;
        cout<<"Nhap ma vo: ";
        cin>>code;
        this->mavo=code;
        this->gianhap=200;
        this->hang="White";
        cout<<"Nhap mau (1-do, 2-den, 3-xanh): ";
        cin>>num;
        if (num==1){this->mausac="do";}
        else if (num==2){this->mausac="den";}
        else{this->mausac="xanh";}
    }
};

class Smartphone{
protected:
    string maso;
    string dongsmartphone;
    CPU cpu;
    ManHinh manhinh;
    Vo v;
public:
    Smartphone(){}
    virtual void setInput()=0;
    virtual double computeSum()=0;
    virtual string information()=0;
};

class Venus:public Smartphone, public Alpha, public Beta, public HD, public FullHD, public voNhua, public voNhom{
public:
    Venus(){}
    double sum=0;
    string output, output1, output2, output3;
    void setInput(){
        cout<<"Nhap ma so: ";
        cin>>this->maso;
        int num, num1, num2;
        cout<<"Loai CPU (1-loai Alpha, 2-loai Beta): ";
        cin>>num;
        if (num==1){Alpha::ganGiatri(); sum+=Alpha::giathanhphan(); output1+=Alpha::ganvaoFile()+'\n';}
        else{Beta::ganGiatri();sum+=Beta::giathanhphan();output1+=Beta::ganvaoFile()+'\n';}
        cout<<"Man hinh: "<<endl;
        FullHD::setGiatridau();
        cout<<"Do phan giai (1-HD, 2-Full HD): ";
        cin>>num1;
        if (num1==1){HD::ganGiatri();sum+=HD::giathanhphan();output2+=HD::ganvaoFile()+'\n';}
        else{FullHD::ganGiatri();sum+=FullHD::giathanhphan();output2+=FullHD::ganvaoFile()+'\n';}
        cout<<"Loai vo Smartphone (1-loai nhom, 2-loai nhua): ";
        cin>>num2;
        if (num2==1){voNhom::ganGiatri();sum+=voNhom::giathanhphan(); output3+=voNhom::ganvaoFile()+'\n';}
        else{voNhua::ganGiatri();sum+=voNhua::giathanhphan();output3+=voNhua::ganvaoFile()+'\n';}
    }
    double computeSum(){
        return 1.3*sum;
    }
    string information(){
        output="Smartphone: "+ maso+" "+"Venus"+" "+to_string(Venus::computeSum())+'\n';
        return output+output1+output2+output3;
    }

};

class Mars:public Smartphone, public Alpha, public Beta, public Gamma, public FullHD, public voNhom{
public:
    double sum=0;
    string output, output1, output2, output3;
    void setInput(){
        int num;
        cout<<"Nhap ma so: ";
        cin>>this->maso;
        output="Smartphone: "+ maso+" "+"Mars"+" "+to_string(Mars::computeSum())+'\n';
        cout<<"Loai CPU (1-loai Alpha, 2-loai Beta, 3-loaiGamma): ";
        cin>>num;
        if (num==1){Alpha::ganGiatri(); sum+=Alpha::giathanhphan();output1+=Alpha::ganvaoFile()+'\n';}
        else if (num==2){Beta::ganGiatri();sum+=Beta::giathanhphan();output1+=Beta::ganvaoFile()+'\n';}
        else{Gamma::ganGiatri();sum+=Gamma::giathanhphan();output1+=Gamma::ganvaoFile()+'\n';}
        cout<<"Man hinh: "<<endl;
        FullHD::setGiatridau();
        cout<<"Do phan giai: FullHD"<<endl;
        FullHD::ganGiatri();sum+=FullHD::giathanhphan();output2+=FullHD::ganvaoFile()+'\n';
        cout<<"Loai vo Smartphone: Vo Nhom"<<endl;
        voNhom::ganGiatri();sum+=voNhom::giathanhphan();output3+=voNhom::ganvaoFile()+'\n';
    }
    double computeSum(){
        return 1.5*sum;
    }
    string information(){
        output="Smartphone: "+ maso+" "+"Mars"+" "+to_string(Mars::computeSum())+'\n';
        return output+output1+output2+output3;
    }
};

class Jupiter: public Smartphone, public Gamma, public FullHD, public voNhom{
public:
    double sum=0;
    string output, output1, output2, output3;
    void setInput(){
        cout<<"Nhap ma so: ";
        cin>>this->maso;
        output="Smartphone: "+ maso+" "+"Jupiter"+" "+to_string(Jupiter::computeSum())+'\n';
        cout<<"Loai CPU: Gamma";
        Gamma::ganGiatri();sum+=Gamma::giathanhphan();output1+=Gamma::ganvaoFile()+'\n';
        cout<<"Man hinh: "<<endl;
        FullHD::setGiatridau();
        cout<<"Do phan giai: FullHD chong loa";
        FullHD::ganGiatri();sum+=FullHD::getGia();output2+=FullHD::ganvaoFile()+'\n';
        cout<<"Loai vo Smartphone: Vo Nhom";
        voNhom::ganGiatri();sum+=voNhom::giathanhphan();output3+=voNhom::ganvaoFile()+'\n';
    }
    double computeSum(){
        return 1.8*sum;
    }
    string information(){
        output="Smartphone: "+ maso+" "+"Jupiter"+" "+to_string(Jupiter::computeSum())+'\n';
        return output+output1+output2+output3;
    }
};

int main(){
    int num, k;
    ofstream file("danh_sach_san_pham.txt");
    cout<<"Nhap so luong Smartphone: ";
    cin>>num;
    for (int i=1; i<=num; i++){
        string h;
        cout<<"Dong Smartphone (1-dong Venus, 2-dong Mars, 3-dong Jupiter): ";
        cin>>k;
        if (k==1){
            Venus v;
            v.setInput();
            h=v.information();
            cout<<h;
            file<<h<<endl;
        }else if (k==2){
            Mars m;
            m.setInput();
            h=m.information();
            cout<<h;
            file<<h<<endl;
        }else{
            Jupiter j;
            j.setInput();
            h=j.information();
            cout<<h;
            file<<h<<endl;
        }  
        cout<<endl;
    }
    file.close();
}
