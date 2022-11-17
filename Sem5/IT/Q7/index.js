var a = new XMLHttpRequest();
a.onload = function () {
	if (a.status === 200) {
		var jsonObj = JSON.parse(a.response);
		// do something with json
		var htmlData = '<table id="container">';
		htmlData += '<tr class="box">';
		htmlData += '<th>Name</th>';
		htmlData += '<th>Species</th>';
		htmlData += '<th>Birth Year</th>';
		htmlData += '<th>Photo</th>';
		htmlData += "</tr>";
		jsonObj["pets"].map((item, iter) => {
			htmlData += '<tr class="box">';
			htmlData += '<td>' + item.name + "</td>";
			htmlData += '<td>' + item.species + "</td>";
			htmlData += '<td>' + item.birthYear + "</td>";
			htmlData += '<td><img src=' + item.photo + ' /></td>';
			htmlData += "</tr>";
		});
		htmlData += "</table>";
		console.log(htmlData);
		document.getElementById("showData").innerHTML = htmlData;
	} else alert("HTTP error " + a.status + " " + a.statusText);
	// a.send();
};

document.getElementById("GetBtn").addEventListener("click", (e) => {
	a.open("GET", "data/pets.json", true);
	a.send();
});
