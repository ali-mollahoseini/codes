int bubblesort(int x){
    int tmpx=x;
    for(int j=0;j<x;j++){
        for(int i=0;i<tmpx-1;i++){
            if(ar[i][0]>ar[i+1][0]){
                int tmp=ar[i+1][0],tmp2=ar[i+1][1];
                ar[i+1][0]=ar[i][0];
                ar[i][0]=tmp;
                ar[i+1][1]=ar[i][1];
                ar[i][1]=tmp2;
            }
        }
    }
}
