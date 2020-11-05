#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define INT_BIT_SIZE 32

static const char digits[] = {
    '0' , '1' , '2' , '3' , '4' , '5' ,
    '6' , '7' , '8' , '9' , 'a' , 'b' ,
    'c' , 'd' , 'e' , 'f' , 'g' , 'h' ,
    'i' , 'j' , 'k' , 'l' , 'm' , 'n' ,
    'o' , 'p' , 'q' , 'r' , 's' , 't' ,
    'u' , 'v' , 'w' , 'x' , 'y' , 'z'
};

// 计算i前面有多少个0
int numberOfLeadingZeros(int i) {
    // HD, Count leading 0's
    if (i <= 0)
        return i == 0 ? 32 : 0;

    // 如果n=32，则最后的返回值都要进行减一操作
    int n = 31;
    // 1111,1111,1111,1111,1111,1111,1111,1111
    //                   1,0000,0000,0000,0000 65536
    //                             1,0000,0000 256
    //                                  1,0000 16
    //                                     100 4
    //
    
    // i >= 65536
    if (i >= 1 << 16) { n -= 16; i >>= 16;  }
    // i >= 256
    if (i >= 1 <<  8) { n -=  8; i >>=  8;  }
    // i >= 16
    if (i >= 1 <<  4) { n -=  4; i >>=  4;  }
    // i >= 4
    if (i >= 1 <<  2) { n -=  2; i >>=  2;  }
    return n - (i >> 1);
}

void formatUnsignedInt(int val, int shift, char* buf, int offset, int len) {
    int charPos = offset + len;
    int radix = 1 << shift;
    int mask = radix - 1;
    do {
        buf[--charPos] = digits[val & mask];
        val >>= shift;

    } while (charPos > offset);

}

// 根据val分配空间
string toUnsignedString0(int val, int shift) {
    // assert shift > 0 && shift <=5 : "Illegal shift value";
    // val实际占用的位数
    int mag = INT_BIT_SIZE - numberOfLeadingZeros(val);
    // 根据进制计算所需要的空间
    int chars = max(((mag + (shift - 1)) / shift), 1);
    char * buf = new char[chars];
    formatUnsignedInt(val, shift, buf, 0, chars);
    return string(buf);
}

static string toBinaryString(int i) {
    return toUnsignedString0(i, 1);

}

static string toOctalString(int i) {
    return toUnsignedString0(i, 3);

}

static string toHexString(int i) {
    return toUnsignedString0(i, 4);

}

int main()
{
    cout << "--------:"<< toBinaryString(1233) <<endl;
    cout << "--------:"<< toOctalString(1233) <<endl;
    cout << "--------:"<< toHexString(1233) <<endl;

    cout << "--------15:"<< numberOfLeadingZeros(15) <<endl;//28
    cout << "--------14:"<< numberOfLeadingZeros(14) <<endl;//28
    cout << "--------13:"<< numberOfLeadingZeros(13) <<endl;//28
    cout << "--------12:"<< numberOfLeadingZeros(12) <<endl;//28
    cout << "--------11:"<< numberOfLeadingZeros(11) <<endl;//28
    cout << "--------10:"<< numberOfLeadingZeros(10) <<endl;//28
    cout << "--------9:"<< numberOfLeadingZeros(9) <<endl;//28
    cout << "--------8:"<< numberOfLeadingZeros(8) <<endl;//28
    cout << "--------7:"<< numberOfLeadingZeros(7) <<endl;//29
    cout << "--------6:"<< numberOfLeadingZeros(6) <<endl;//29
    cout << "--------5:"<< numberOfLeadingZeros(5) <<endl;//29
    cout << "--------4:"<< numberOfLeadingZeros(4) <<endl;//29
    cout << "--------3:"<< numberOfLeadingZeros(3) <<endl;//30
    std::cout << "Hello world" << std::endl;
    return 0;
}

