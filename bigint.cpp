#include <vector>
using std::vector;

class bigint{
    private:
        vector<unsigned char> digits;
        int nbdigits;
        bool positive;
    public:
        //Constructors: Default, from integer, and copy
        bigint():nbdigits(0),positive(false){};
        bigint(int val);
        bigint(const bigint&val):digits(val.digits),positive(val.positive),nbdigits(val.nbdigits){}
        
        //Compound assignment operators
        
        bigint& operator+=(const bigint&rhs){
            if(positive==rhs.positive){
                if(nbdigits<rhs.nbdigits){
                    digits.resize(rhs.nbdigits,0);
                    nbdigits=rhs.nbdigits;
                }
                bool carry = false;
                for(int i=0;i<nbdigits;++i){
                    if(carry){
                        ++digits[i];
                        carry=false;
                    }
                    if(i<rhs.nbdigits){
                        digits[i]+=rhs.digits[i];
                    }
                    if(digits[i]>9){
                        carry=true;
                        digits[i]%=10;
                    }
                    if(!carry && i<rhs.nbdigits){
                        break;
                    }
                }
            }else if(positive){
                operator-(rhs);
            }else{
                operator=(rhs-*this);
            }
            return *this;
        }
        bigint& operator-=(const bigint&rhs);
        bigint& operator*=(const bigint&rhs);
        bigint& operator/=(const bigint&rhs);
        bigint& operator%=(const bigint&rhs);
        
        //Arithmetic operators
        
        bigint operator-()const{bigint ret(*this);ret.positive=!positive;return ret;}
        bigint operator+(const bigint&rhs)const{bigint ret(*this);ret+=rhs;return ret;}
        bigint operator-(const bigint&rhs)const{bigint ret(*this);ret-=rhs;return ret;}
        bigint operator*(const bigint&rhs)const{bigint ret(*this);ret*=rhs;return ret;}
        bigint operator/(const bigint&rhs)const{bigint ret(*this);ret/=rhs;return ret;}
        bigint operator%(const bigint&rhs)const{bigint ret(*this);ret%=rhs;return ret;}
        
        //Comparison operators
        
        bool operator< (const bigint&rhs) const{ /*TODO do actual comparison */ }
        bool operator> (const bigint&rhs) const{return rhs < *this;}
        bool operator<=(const bigint&rhs) const{return !(*this > rhs);}
        bool operator>=(const bigint&rhs) const{return !(*this < rhs);}
        
};