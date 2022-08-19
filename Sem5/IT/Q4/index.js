function productTable(n) {
	var randomColor = `#` + Math.floor(Math.random() * 16777215).toString(16);
	console.log(randomColor);
	var table =
		`<div style="font-size: ` + 5 * n + `px; color:` + randomColor + `;">`;
	for (var j = 1; j <= 10; j++) {
		table += n * j + " ";
	}
	table += "</div>";
	return table;
}

var counter = 2;
var i = setInterval(function () {
	document.getElementById("container").innerHTML += productTable(counter);
	counter++;
	if (counter > 10) {
		clearInterval(i);
	}
}, 500);
