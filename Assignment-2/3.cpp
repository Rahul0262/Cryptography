#include<bits/stdc++.h>
using namespace std;

string Rcon[10] = {"01000000", "02000000", "04000000", "08000000", "10000000","20000000", "40000000", "80000000", "1B000000", "36000000"};

string S_Box[16][16] = {  
    {"63", "7C", "77", "7B", "F2", "6B", "6F", "C5", "30", "01", "67", "2B", "FE", "D7", "AB", "76"},  
    {"CA", "82", "C9", "7D", "FA", "59", "47", "F0", "AD", "D4", "A2", "AF", "9C", "A4", "72", "C0"},  
    {"B7", "FD", "93", "26", "36", "3F", "F7", "CC", "34", "A5", "E5", "F1", "71", "D8", "31", "15"},  
    {"04", "C7", "23", "C3", "18", "96", "05", "9A", "07", "12", "80", "E2", "EB", "27", "B2", "75"},  
    {"09", "83", "2C", "1A", "1B", "6E", "5A", "A0", "52", "3B", "D6", "B3", "29", "E3", "2F", "84"},  
    {"53", "D1", "00", "ED", "20", "FC", "B1", "5B", "6A", "CB", "BE", "39", "4A", "4C", "58", "CF"},  
    {"D0", "EF", "AA", "FB", "43", "4D", "33", "85", "45", "F9", "02", "7F", "50", "3C", "9F", "A8"},  
    {"51", "A3", "40", "8F", "92", "9D", "38", "F5", "BC", "B6", "DA", "21", "10", "FF", "F3", "D2"},  
    {"CD", "0C", "13", "EC", "5F", "97", "44", "17", "C4", "A7", "7E", "3D", "64", "5D", "19", "73"},  
    {"60", "81", "4F", "DC", "22", "2A", "90", "88", "46", "EE", "B8", "14", "DE", "5E", "0B", "DB"},  
    {"E0", "32", "3A", "0A", "49", "06", "24", "5C", "C2", "D3", "AC", "62", "91", "95", "E4", "79"},  
    {"E7", "C8", "37", "6D", "8D", "D5", "4E", "A9", "6C", "56", "F4", "EA", "65", "7A", "AE", "08"},  
    {"BA", "78", "25", "2E", "1C", "A6", "B4", "C6", "E8", "DD", "74", "1F", "4B", "BD", "8B", "8A"},  
    {"70", "3E", "B5", "66", "48", "03", "F6", "0E", "61", "35", "57", "B9", "86", "C1", "1D", "9E"},  
    {"E1", "F8", "98", "11", "69", "D9", "8E", "94", "9B", "1E", "87", "E9", "CE", "55", "28", "DF"},  
    {"8C", "A1", "89", "0D", "BF", "E6", "42", "68", "41", "99", "2D", "0F", "B0", "54", "BB", "16"}  
};

string xorT[16][16] = {
        {"0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"},
        {"1","0","3","2","5","4","7","6","9","8","B","A","D","C","F","E"},
        {"2","3","0","1","6","7","4","5","A","B","8","9","E","F","C","D"},
        {"3","2","1","0","7","6","5","4","B","A","9","8","F","E","D","C"},
        {"4","5","6","7","0","1","2","3","C","D","E","F","8","9","A","B"},
        {"5","4","7","6","1","0","3","2","D","C","F","E","9","8","B","A"},
        {"6","7","4","5","2","3","0","1","E","F","C","D","A","B","8","9"},
        {"7","6","5","4","3","2","1","0","F","E","D","C","B","A","9","8"},
        {"8","9","A","B","C","D","E","F","0","1","2","3","4","5","6","7"},
        {"9","8","B","A","D","C","F","E","1","0","3","2","5","4","7","6"},
        {"A","B","8","9","E","F","C","D","2","3","0","1","6","7","4","5"},
        {"B","A","9","8","F","E","D","C","3","2","1","0","7","6","5","4"},
        {"C","D","E","F","8","9","A","B","4","5","6","7","0","1","2","3"},
        {"D","C","F","E","9","8","B","A","5","4","7","6","1","0","3","2"},
        {"E","F","C","D","A","B","8","9","6","7","4","5","2","3","0","1"},
        {"F","E","D","C","B","A","9","8","7","6","5","4","3","2","1","0"}
    };

int getValue(char a){
    map<char,int> M;
    M['0'] = 0;
    M['1'] = 1;
    M['2'] = 2;
    M['3'] = 3;
    M['4'] = 4;
    M['5'] = 5;
    M['6'] = 6;
    M['7'] = 7;
    M['8'] = 8;
    M['9'] = 9;
    M['A'] = 10;
    M['B'] = 11;
    M['C'] = 12;
    M['D'] = 13;
    M['E'] = 14;
    M['F'] = 15;
    return M[a];
}

string getBinaryToDecimal(string a){
    map<string,string> M;
    M["0000"] = "0";
    M["0001"] = "1";
    M["0010"] = "2";
    M["0011"] = "3";
    M["0100"] = "4";
    M["0101"] = "5";
    M["0110"] = "6";
    M["0111"] = "7";
    M["1000"] = "8";
    M["1001"] = "9";
    M["1010"] = "A";
    M["1011"] = "B";
    M["1100"] = "C";
    M["1101"] = "D";
    M["1110"] = "E";
    M["1111"] = "F";
    return M[a];
}

string getDecimalToBinary(char a){
    map<char,string> M;
    M['0'] = "0000";
    M['1'] = "0001";
    M['2'] = "0010";
    M['3'] = "0011";
    M['4'] = "0100";
    M['5'] = "0101";
    M['6'] = "0110";
    M['7'] = "0111";
    M['8'] = "1000";
    M['9'] = "1001";
    M['A'] = "1010";
    M['B'] = "1011";
    M['C'] = "1100";
    M['D'] = "1101";
    M['E'] = "1110";
    M['F'] = "1111";
    return M[a];
}

string getXorOfString(string a,string b){
    string temp = "";
    for(int i = 0; i < a.size(); i++)   temp += xorT[getValue(a[i])][getValue(b[i])];
    return temp;
}

string getProduct(string s, int x){
    string ans;
    string t1 = getDecimalToBinary(s.at(0)) + getDecimalToBinary(s.at(1));
    t1.append("0");
    t1 = t1.substr(1);
    ans = getBinaryToDecimal(t1.substr(0,4)) + getBinaryToDecimal(t1.substr(4,4));
    if(s.at(0) == '8' || s.at(0) == '9' || s.at(0) == 'A' || s.at(0) == 'B' || s.at(0) == 'C' || s.at(0) == 'D' || s.at(0) == 'E' || s.at(0) == 'F'){
        ans = getXorOfString(ans,"1B");
        if(x == 3){
            ans = getXorOfString(ans,s);
        }
    }
    else{
        if(x == 3){
            ans = getXorOfString(ans,s);
        }
    }
    return ans;
}

string getAfterSubBox(string x){
    for(int i = 0; i < x.size(); i+=2){
            x.replace(i,2,S_Box[getValue(x.at(i))][getValue(x.at(i+1))]);
        }
    return x;
}

string getAfterShiftRows(string x){
    for(int j = 0; j < 4; j++){
        for(int rowCnt = 0; rowCnt < j; rowCnt++){
            string temp = x.substr(2*j ,2);
            for(int i = 0; i < 3; i++){
                x.replace(2*j + 8*i, 2, x.substr(2*j + 8*(i+1), 2));
            }
            x.replace(2*j + 8*3, 2, temp);
        }
    }
    return x;
}

string getAterMixCols(string x){
    int mixColMat[4][4] = {
        {2,3,1,1},
        {1,2,3,1},
        {1,1,2,3},
        {3,1,1,2}
    };

    string temp="00000000000000000000000000000000";
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            string ans = temp.substr(2*i + 8*j,2);
            for (int k = 0; k < 4; k++){
                if(mixColMat[i][k] != 1){
                    ans = getXorOfString(ans,getProduct(x.substr(2*k + 8*j,2),mixColMat[i][k]));
                }
                else{
                    ans = getXorOfString(ans,x.substr(2*k + 8*j,2));
                }
            }
            temp.replace(2*i + 8*j, 2, ans);
        } 
    }
    return temp;
}

int main(){

    string KEY,PT;
    string roundKeys[10];

    cin >> PT;
    cin >> KEY;
    string curKey = KEY;
    
    for (int i = 0; i < 10; i++){
        string w_0 = curKey.substr(0,8);
        string w_1 = curKey.substr(8,8);
        string w_2 = curKey.substr(16,8);
        string w_3 = curKey.substr(24,8);

        string g = "";
        g.append(w_3.substr(2,6) + w_3.substr(0,2));
        string BS = "";
        for(int i = 0; i < 8; i+=2){
            BS += S_Box[getValue(g.at(i))][getValue(g.at(i+1))];
        }
        string q = getXorOfString(Rcon[i],BS);
        w_0 = getXorOfString(w_0, q);
        w_1 = getXorOfString(w_1, w_0);
        w_2 = getXorOfString(w_2, w_1);
        w_3 = getXorOfString(w_3, w_2);

        curKey = w_0 + w_1 + w_2 + w_3;
        roundKeys[i] = curKey;
    }

    string preRound_PT = getXorOfString(PT,KEY);

    string currStateMatrix = preRound_PT;

    for(int Round = 1; Round <= 10; Round++){
        //Substitution Box
        currStateMatrix = getAfterSubBox(currStateMatrix);

        // Shift rows
        currStateMatrix = getAfterShiftRows(currStateMatrix);
        
        // Mix Columns
        if(Round != 10){
            currStateMatrix = getAterMixCols(currStateMatrix);    
        }
        
        // Xor with Round Key
        currStateMatrix = getXorOfString(currStateMatrix,roundKeys[Round-1]);
    }
    
    for(int i = 0; i < 10; i++){
        cout << roundKeys[i] << endl;
    }

    cout << currStateMatrix;
}