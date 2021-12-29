function len(value){
  return value.length;
}

function compare(a, b) {
  var nameA = a.fullName.split(' ')[1][0];
  var nameB = b.fullName.split(' ')[1][0];
  if(a.gpa < b.gpa)
    return 1;
  if(a.gpa > b.gpa)
    return 0;
  if (nameA < nameB)
    return -1;
  if (nameA > nameB)
    return 1;
  if(a.age < b.age)
    return -1;
  if(a.age > b.age)
    return 1;
  return 0;
}

function sort(students) {
  students.sort(compare);
  return students.map(v=>v.fullName).join(',');
};

/*
  // codewars
function sort(students) {
  return students.sort((a, b) => {
    const gpaDiff = b.gpa - a.gpa;
    const nameDiff = (a.fullName.split(' ')[1][0].charCodeAt(0) - b.fullName.split(' ')[1][0].charCodeAt(0));
    const ageDiff = a.age - b.age
    return gpaDiff || nameDiff || ageDiff;
  })
    .map(s => s.fullName)
    .join(',')
};
*/
