regexBelow = (n, ds = n - 1 + '') =>
  '^(?!$|0)('
  + `\\d{1,${ds.length - 1}}|`.repeat(ds.length > 1)
  + function go([d, ...ds]) {
      return !d ? '' : `[0-${d - 1}]\\d{${ds.length}}|`.repeat(d != 0) + d + '(' + go(ds) + ')';
    }(ds)
  + ')$';

function regexBelow(n) {
  if (n < 2) return "^[^-01\\d]$";
  const isDiv10 = n % 10 === 0;
  n = String(n - isDiv10);
  const l = n.length;
  let regex = `[1-${l > 1 || isDiv10 ? 9 : n - 1}]\\d{0,${
    (x = l - 2) < 1 ? 0 : x
  }}`;
  if (l > 1) {
    n.split``.forEach((d, i) => {
      d=+d
      const a = +!i;
      const b = (x = d - !(isDiv10 && i === l - 1)) < 1 ? 0 : x;
      if ((d === 1 && i === 0) || (d === 0 && b===0)) return;
      regex += `|${n.substr(0, i)}[${a}-${b}]\\d{${l - ++i}}`;
    });
  }
  return `^(${regex})$`;
}
