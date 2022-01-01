function cache(func) {
  var calls = {};
  return function() {
    var key = JSON.stringify(arguments); // "Way to go, Javascript!"
    if (!(key in calls)) {
      calls[key] = func.apply(null, arguments);
    }
    return calls[key];
  };
}
