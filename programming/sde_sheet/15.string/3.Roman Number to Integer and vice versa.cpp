// Roman to Integer

class Solution {
public:
    int romanToInt(string s) {
        int sum = 0 ;
        for (int i = 0 ; i < s.size() ; i++){
            if (s[i] == 'I') sum += 1 ;
            else if (s[i] == 'V') sum += 5 ;
            else if (s[i] == 'X') sum += 10 ;
            else if (s[i] == 'L') sum += 50 ;
            else if (s[i] == 'C') sum += 100 ;
            else if (s[i] == 'D') sum += 500 ;
            else if (s[i] == 'M') sum += 1000 ;
            if(i+1 < s.size()){
                if (s[i] == 'I' && (s[i+1] == 'V' || s[i+1] == 'X') ) sum -= 2;
                else if (s[i] == 'X' && (s[i+1] == 'L' || s[i+1] == 'C') ) sum -= 20 ;
                else if (s[i] == 'C' && (s[i+1] == 'D' || s[i+1] == 'M') ) sum -= 200;
            }
        }
        return sum ;
    }
};

// Integer to Roman

class Solution {
public:
    string intToRoman(int num) {
        string ones[] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
        string tens[] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        string hrns[] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        string ths[]={"","M","MM","MMM"};
        
        return ths[num/1000] + hrns[(num%1000)/100] + tens[(num%100)/10] + ones[num%10];
    }
};

