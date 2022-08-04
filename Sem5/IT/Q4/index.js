function productTable(n) {
  var table = "<table>";
  for (var j = 1; j <= 10; j++) {
    table +=
      "<tr><td>" +
      n +
      "</td><td>x</td><td>" +
      j +
      "</td><td>=</td><td>" +
      n * j +
      "</td></tr>";
  }
  table += "</tabel>";
  return table;
}

for (var i = 1; i <= 10; i++) {
    // setInterval(function(i){
      document.getElementById("container").innerHTML += productTable(i);
      console.log(i)
    // }, 1000);
}
// console.log(groupTable());

// setInterval(groupTable, 5000);
// document.getElementById("container").innerHTML =
// document.getElementById("container").innerHTML = groupTable();
