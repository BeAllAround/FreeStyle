function wordCount(s) {
  let words = ["a", "the", "on", "at", "of", "upon", "in", "as"];
  return s.split(/[^\w]|\d+|\_/gi).filter(v=>!words.includes(v.toLowerCase()) && v!='').length;
}
