function sort(a){ // use the traditional "bubble-sort" and just count up the swaps!
    sorted = false;
    temp = null;
    c = 0;
    while(!sorted) {
        sorted = true;
        for (let i = 0; i < a.length - 1; i++) {
            if (a[i] > a[i+1]) {
                temp = a[i];
                a[i] = a[i+1];
                a[i+1] = temp;
                sorted = false;
              c++;
            }
        }
    }
  return c;
}

function countInversions( array ){
  return sort(array);
}
