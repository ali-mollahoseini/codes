 bool is_palindrome(){
     bool tf=true;
     vector<int>rev;
     for(int i=0;i<vec.size();i++){
        rev.push_back(vec.at(vec.size()-1-i));
     }
     for(int i=0;i<vec.size();i++){
        if(rev.at(i)!=vec.at(i)){
            tf =false;
        }
     }
     return(tf==true)? true : false;
 }
