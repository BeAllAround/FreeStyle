function second_max(a){
    let b = Buffer.alloc(2);
    let m = a[0];
    let i, c = -1;
    b[++c] = m;
    for(i = 1; i < a.length; i++){
        if(a[i] > m){
            m = a[i];
            if(c == 1){
                c = -1;
            }
            b[++c] = m;
        }
    }
    return Math.min(b[0], b[1]);
}
