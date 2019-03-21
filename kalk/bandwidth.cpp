
#include "bandwidth.h"

Bandwidth::Bandwidth(int p, double d, double u){
    if(p < 0)
        ping = 0;
    else
        ping = p;

    if(d < 0)
        download = 0;
    else
        download = d;

    if(u < 0)
        upload = 0;
    else
        upload = u;
}//bandwidth()

Bandwidth::Bandwidth(const Bandwidth& x){
    ping = x.ping;
    download = x.download;
    upload = x.upload;
}//costruttore di copia

Bandwidth::~Bandwidth(){
}//~bandwidth()

int Bandwidth::getPing() const{
    return ping;
}

double Bandwidth::getDown() const{
    return download;
}

double Bandwidth::getUp() const{
    return upload;
}

Bandwidth* Bandwidth::operator+(const Bandwidth& x) const{
    return new Bandwidth(ping + x.ping, download + x.download, upload + x.upload);
}//operator+

Bandwidth* Bandwidth::operator-(const Bandwidth& x) const{
    return new Bandwidth(ping - x.ping, download - x.download, upload - x.upload);
}//operator-

Bandwidth* Bandwidth::operator*(int x) const{
    return new Bandwidth(ping * x, download * x, upload * x);
}//operator*

Bandwidth* Bandwidth::operator/(int x) const{
    if(x == 0){
        std::cout << "Divisione per 0!!!";
        return new Bandwidth();
    }
    return new Bandwidth(ping / x, download / x, upload / x);
}//operator/

Bandwidth* Bandwidth::operator%(int x) const{
    if(x == 0){
        std::cout << "Divisione per 0!!!";
        return new Bandwidth();
    }
    return new Bandwidth(ping % x, static_cast<int>(download) % x, static_cast<int>(upload) % x);
}//operator%

std::string Bandwidth::print() const{

    std::string text = "<i>Ping:</i><br>";
    text += std::to_string(ping);
    text += "<br><i>Download(Mbps):</i><br>";
    text += std::to_string(download).substr(0, std::to_string(download).size()-4);
    text += "<br><i>Upload(Mbps):</i><br>";
    text += std::to_string(upload).substr(0, std::to_string(upload).size()-4);

    return text;

}

void Bandwidth::setBand(int p, double d, double u){
    if(p < 0)
        ping = 0;
    else
        ping = p;

    if(d < 0)
        download = 0;
    else
        download = d;

    if(u < 0)
        upload = 0;
    else
        upload = u;
}

Bandwidth Bandwidth::operator=(const Bandwidth& x){
    ping = x.ping;
    download = x.download;
    upload = x.upload;
    return *this;
}//operator=

bool Bandwidth::operator==(const Bandwidth& x){
    return ping == x.ping && download == x.download && upload == x.upload;
}//operator==

bool Bandwidth::operator>(const Bandwidth& x){
    double  temp1, temp2;
    temp1 = upload + download;
    temp2 = x.upload + x.download;

    if(temp1 == temp2)
        return ping < x.ping;
    else
        return temp1 > temp2;
}//operator>

bool Bandwidth::operator<(const Bandwidth& x){
    double  temp1, temp2;
    temp1 = upload + download;
    temp2 = x.upload + x.download;

    if(temp1 == temp2)
        return ping > x.ping;
    else
        return temp1 < temp2;
}//operator<
