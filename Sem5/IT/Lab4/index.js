// let firstName = document.getElementById('')

handleSubmit = (event) => {
	event.preventDefault();
	const data = new FormData(event.target);
	const empData = Object.fromEntries(data.entries());
	var nameRegex = "^[A-Za-z][A-Za-z0-9_]{7,29}$";
	var phoneNumberRegex = "^(+d{1,2}s)?(?d{3})?[s.-]d{3}[s.-]d{4}$";
	if (empData["firstName"].match(nameRegex)) {
		console.log(empData);
	} else {
		alert("Invalid First Name");
	}
	if (empData["lastName"].match(nameRegex)) {
		console.log(empData);
	} else {
		alert("Invalid Last Name");
	}
	if (empData["phoneNumber"].match(phoneNumberRegex)) {
		console.log(empData);
	} else {
		alert("Invalid Phone Number");
	}
};

const submitListener = document.getElementById("recruitmentForm");
// submitListner.addEventListener("submit", handleSubmit);
submitListener.addEventListener("submit", handleSubmit);
