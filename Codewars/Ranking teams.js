function nbaCup(resultSheet, toFind) {
  let data = [0, 0, 0, 0, 0, 0], s;
  if(toFind=='')
    return '';
  if(resultSheet.search(toFind+' ')== -1)
    return toFind+':This team didn\'t play!';
  for(let item of (resultSheet.split(','))){
    if((s = item.search(toFind))!=-1){
      validate = [];
      let[score_1, score_2] = (validate = (item.match(/\b(\d+)\b/g))).map(v=>parseInt(v));
      if(item.includes('.')) // amateur
        return 'Error(float number):' + item;
      if(s == 0){
        data[3]+=score_1;
        data[4]+=score_2;
        if(score_1 > score_2){
          data[0]++;
          data[5]+=3;
        }
        else if(score_1 == score_2){
          data[1]++;
          data[5] += 1;
        }
        else if(score_1 < score_2)
          data[2]++;
      }
      else{
        data[3]+=score_2;
        data[4]+=score_1;
        if(score_2 > score_1){
          data[0]++;
          data[5]+=3;
        }
        else if(score_1 == score_2){
          data[1]++;
          data[5] += 1;
        }
        else if(score_2 < score_1)
          data[2]++;
      }
    }
  }
  return toFind + ':' + 'W=' + data[0] + ';'+ 'D=' + data[1] + ';' + 'L=' + data[2] + ';' + 'Scored=' + data[3] + ';' + 'Conceded=' + data[4] + ';' + 'Points=' + data[5];
}
