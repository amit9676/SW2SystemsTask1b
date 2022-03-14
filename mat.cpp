#include "mat.hpp"
#include <stdexcept>

namespace ariel
{
    void errorThrower(int a, int b, char c1, char c2){
        //aid - https://stackoverflow.com/questions/8480640/how-to-throw-a-c-exception
        const int space = 32;
        const int maxAscii = 127;
        if ((a*b) % 2 == 0){
            throw std::invalid_argument( "height and width must be even number" );
        }
        if(a <= 0 || b<=0){
            throw std::invalid_argument( "height and width must be positive integer");
        }
        if(c1 <= space || c2 <= space || c1 >= maxAscii || c2 >= maxAscii){
            throw std::invalid_argument("invalid ascii");
        }
    }

    std::string mat(int w, int h, char a, char b){
        errorThrower(w,h,a,b);
        //std::string result = "";
        std::string carpet (w*h, a);
        int k = 0;
        char key = a;
        while(k <= w-k-1 && k<=h-k-1){
            key = k % 2 == 0 ? a:b;
            for(int i = k; i <= w-k-1; i++) {
                carpet[w*k + i] = key;
                carpet[w*(h-k-1) + i] = key;
            }

            for(int i = k; i <= h-k-1; i++) {
                carpet[w*i + k] = key;
                carpet[(w*i - k) + (w-1)] = key;
            }
            k++;
        }

        std::string result;
        for (int i = 0; i < h; ++i)
        {
            for (int j = 0; j < w; ++j)
            {
                result += carpet[i*w+j];
            }

            if(i < h-1){
                result += '\n';
            }
            
        }
        return result;

    }
} 

