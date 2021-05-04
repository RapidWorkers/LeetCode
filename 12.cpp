class Solution {
public:
    string intToRoman(int num) {
        string converted;
        
        int d1 = num % 10;
        num /= 10;
        int d2 = num % 10;
        num /= 10;
        int d3 = num % 10;
        num /= 10;
        int d4 = num % 10;
        
        //Proc M
        for(int i = 0; i < d4; i++){
            converted += "M";
        }
        
        if(d3 == 4){
            converted += "CD";
        }
        else if(d3 == 9){
            converted += "CM";
        }
        else if(d3 >= 5){
            converted += "D";
            for(int i = 5; i < d3; i++){
                converted += "C";
            }
        }
        else{
            for(int i = 0; i < d3; i++){
                converted += "C";
            }
        }
        
        if(d2 == 4){
            converted += "XL";
        }
        else if(d2 == 9){
            converted += "XC";
        }
        else if(d2 >= 5){
            converted += "L";
            for(int i = 5; i < d2; i++){
                converted += "X";
            }
        }
        else{
            for(int i = 0; i < d2; i++){
                converted += "X";
            }
        }
        
        if(d1 == 4){
            converted += "IV";
        }
        else if(d1 == 9){
            converted += "IX";
        }
        else if(d1 >= 5){
            converted += "V";
            for(int i = 5; i < d1; i++){
                converted += "I";
            }
        }
        else{
            for(int i = 0; i < d1; i++){
                converted += "I";
            }
        }
        
        return converted;
        
    }
};
