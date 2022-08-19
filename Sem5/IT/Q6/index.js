handleSubmit = (event) => {
	event.preventDefault();
	const data = new FormData(event.target);
	const PetObject = Object.fromEntries(data.entries());
	console.log(PetObject);
};

const petForm = document.getElementById("pet-form");
petForm.addEventListener("submit", handleSubmit);