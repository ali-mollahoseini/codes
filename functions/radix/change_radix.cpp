void change_radix(int input,int scndbase){
     while(input>0){
        vec.push_back(input%scndbase);
        input/=scndbase;
     }
 }
