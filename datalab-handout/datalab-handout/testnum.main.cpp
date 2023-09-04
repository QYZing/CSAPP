//
// Created by dying on 8/28/23.
//
#include "iostream"
#include "cmath"
#include <climits>
using  namespace  std;
int howManyBits(int x ) {
    int e1 = ~(x >> 31);
    int e2 = (~(x ^ e1));
    x = e2;
    // example : 00001000 00000000   // two byte
    int d1 = x & 0xFF;//0+
    x = x >> 8;
    int d2 = x & 0xFF;//8+
    x = x >> 8;
    int d3 = x & 0xFF;//16+
    x = x >> 8;
    int d4 = x & 0xFF; // 24+
    cout<<"d1 = " << d1<<endl;
    cout<<"d2 = " << d2<<endl;
    cout<<"d3 = " << d3<<endl;
    cout<<"d4 = " << d4<<endl;
    int p1 = 0;
    p1 = ((!!d4 << 31) >>31) & 24;
    p1 += (!p1 << 31) >> 31 & ((!!d3 << 31) >> 31 ) & 16;
    p1 += (!p1 << 31) >> 31 & ((!!d2 << 31) >> 31 ) & 8;
    //p1 = (!p1 << 31) >> 31 & ((!!d1 << 31) >> 31 ) & 0;

    cout<<"p1 = "<<p1<<endl;
    // get have 1 byte that high 8 bite
    int b = ((!!d4 << 31) >> 31) & d4;
    b = (((!b << 31) >> 31) & d3) | b;
    b = (((!b << 31) >> 31) & d2) | b;
    b = (((!b << 31) >> 31) & d1) | b;
    cout<<"b = " << b<<endl;
    d1 = b & 0xF; //0+
    b = b >> 4;
    d2 = b & 0xF;//4+
    cout<<"d1 = " << d1<<endl;
    cout<<"d2 = " << d2<<endl;
    int p2 = 0;
    p2 = ((!!d2 << 31) >> 31) & 4;
    //p2 = (!p2 << 31) >> 31 & (!!d1 << 31) >> 31 & 0
    cout<<"p2 = "<<p2<<endl;
    int b1 = (!!d2 << 31) >> 31 & d2;
    b1 = (((!b1 << 31) >> 31) & d1) | b1;
    cout<<"b1 = "<<b1<<endl;

    int p3 = 0;
    p3 = ((!!(b1 & 8) << 31) >> 31) & 4;
    p3 += (!p3 << 31) >> 31 & ((!!(b1 & 4) << 31) >> 31) & 3;
    p3 += (!p3 << 31) >> 31 & ((!!(b1 & 2) << 31) >> 31) & 2;
    p3 += (!p3 << 31) >> 31 & ((!!(b1 & 1) << 31) >> 31) & 1;

    cout<<"p3 = "<<p3<<endl;
    return p1 + p2 + p3 + 1;
}

unsigned floatScale2(unsigned uf) {
    // 32 bite 0 0000000 0 0000000 00000000 00000000
    if(uf == -1 || uf == 0){
        return uf;
    }
    int w = uf & 0x7FFFFF;
    int j = uf & 0x7F800000;
    int jj = 0x800000;
    int f = uf & 0x80000000;
    int dw = w + w ;
    std::cout << std::hex << f << std::endl;
    std::cout << std::hex << w << std::endl;
    std::cout << std::hex << j << std::endl;
    std::cout<<"=----------------="<<endl;
    if(!j){ // exponent is zero that represent 非规格化
        if(!!(dw & 0x800000)){
            j += jj;
            dw &= 0x7FFFFFFF;
        }
    } else{
        j += jj;
        dw >>= 1;
    }
    return f | dw | j;
    std::cout << std::hex << f << std::endl;
    std::cout << std::hex << dw << std::endl;
    std::cout << std::hex << j << std::endl;
    return f | dw | j;
}
float u2f(unsigned u) {
    union {
        unsigned u;
        float f;
    } a;
    a.u = u;
    return a.f;
}
int floatFloat2Int(unsigned uf) {
    int w = (uf & 0x7FFFFF )| 0x800000;
    int j = (uf & 0x7F800000) >> 23;
    int f = uf & 0x80000000;
    int p = j - 126;
    cout<<"w = " << w<<endl;
    cout<<"j = " << j<<endl;
    cout<<"f = " << f<<endl;
    cout<<"p = " << p<<endl;
    if((!j && !(w & 0x7FFFFF)) || ((p >> 31) & 1)){// 非规格化，且为0 或者是太小的数
        return 0;
    }
    if(((((p - 31)) >> 31) ^ 1) & 1){ // out range
        return 0x80000000u;
    }
    int y = p - 24;
    if(y >> 31 & 1){
        return ~(w >> (~y + 1)) + 1;
    }
    return (w << y) | f;
}

int main()
{
    /* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
     *  */
    //  0 0111111 1 0000000 00000000 00000000
    //  0 1000000 0 0000000 00000000 00000000
    //cout<<floatScale2(0x800000)<<endl;
    //cout<<(float)0x3f800000<<endl;

//    cout<<(u2f(0x800000))<<endl;
//    cout<<(u2f(0x1000000));
//    cout<<pow(2,31)<<endl; //31 + -126 = Emax 1001 1110
//    cout<<INT_MAX<<endl;
    cout<<floatFloat2Int(0xbf800000)<<endl;
    return 0;
}
