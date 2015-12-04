#include <cstdlib>

void generate_exponents(const int min, const int max, int *exponents){
    int total = max - min;

    // Generate our
    int i;
    for(i = 0; i <= total; i++){
        exponents[i] = i + min;
    }

    int j, tmp;
    for(i = 0; i <= total; i++){
        j = std::rand() % (total + 1);

        tmp = exponents[i];
        exponents[i] = exponents[j];
        exponents[j] = tmp;
    }

}

long long power_2(const int exponent){
    long long n = 1;
    int i;
    for(i = 1; i <= exponent; i++){
        n *= 2;
    }
    return n;
}

long long string_to_number(const char *str){
    int i;
    char v;
    long long num = 0;
    for(i = 0; str[i]; i++){
        v = str[i];
        if(v <= '9'){
            num *= 10;
            num += v - '0';
        }else{
            if(v == 'k'){
                num *= power_2(10);
                break;
            }else if(v == 'm'){
                num *= power_2(20);
                break;
            }else if(v == 'b'){
                num *= power_2(30);
                break;
            }else if(v == 't'){
                num *= power_2(40);
                break;
            }
        }
    }
    return num;
}
