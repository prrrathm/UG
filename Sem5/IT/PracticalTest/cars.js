$("#CarForm").on("submit", (event) => {
	event.preventDefault();
	const data = new FormData(event.target);
	const FormObj = Object.fromEntries(data.entries());
	console.log("JS Object", FormObj);
	console.log("JSON Object", JSON.stringify(FormObj));
});
