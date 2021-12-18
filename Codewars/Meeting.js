function meeting(s) {
  s = s.split(';');
  arr = [];
  arr_c = []
  for(let item of s){
    arr_c = item.split(':');
    arr.push([arr_c[1], arr_c[0]]);
  }
  arr.sort(function(a, b){
    var nameA = a[0].toUpperCase(); // ignore upper and lowercase
    var nameB = b[0].toUpperCase(); // ignore upper and lowercase
    if(nameA == nameB){ // redefine!
      nameA = a[1].toUpperCase(); // ignore upper and lowercase
      nameB = b[1].toUpperCase(); // ignore upper and lowercase
    }
    if (nameA < nameB) {
      return -1;
    }
    if (nameA > nameB) {
      return 1;
    }
    // names must be equal
    return 0;
  });
  return arr.map(value=>'('+ value[0].toUpperCase() + ', ' + value[1].toUpperCase()+')').join('');
}
