class Solution {
  public:
    int getLastDigit(string& a, string& b) {
        int n = a.size();
        if(a[n-1]=='0') return 0;
        if(a[n-1] =='1') return 1;
        if(b=="0") return 1;
        if(b=="1") return a[n-1]-'0';
        
        long long power;
        if(b.size()>=2) power = (b[b.size()-2]-'0')*10 + b[b.size()-1]-'0';
        else power = stoi(b);
        
        if(a[n-1]=='2'){
            if(power%4==1) return 2;
            if(power%4 == 2) return 4;
            if(power%4 == 3) return 8;
            return 6;
            
        }
        else if(a[n-1]=='3'){
            if(power%4==1) return 3;
            if(power%4 == 2) return 9;
            if(power%4 == 3) return 7;
            return 1;
        }
        else if(a[n-1]=='4'){
            if(power%2==1) return 4;
            return 6;
        }
        else if(a[n-1]=='5'){
            return 5;
        }
        else if(a[n-1]=='6'){
            return 6;
        }
        else if(a[n-1]=='7'){
            if(power%4==1) return 7;
            if(power%4 == 2) return 9;
            if(power%4 == 3) return 3;
            return 1;
        }
        else if(a[n-1]=='8'){
            if(power%4==1) return 8;
            if(power%4 == 2) return 4;
            if(power%4 == 3) return 2;
            return 6;
        }
        else if(a[n-1]=='9'){
            if(power%2==1) return 9;
            return 1;
        }
        else return 0;
        
    }
};
//GFG POTD solution for 20 June
