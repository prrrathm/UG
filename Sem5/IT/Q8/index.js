$(document).ready(function () {
	$("button").on("click", function () {
		$("table").addClass("tdesign");
		$("tr:nth-child(even)").css("background-color", "#BB6060");
		$("h1").addClass("heading_h1");
		$("h2").css({ color: "crimson", "font-family": "Courier" });
		$("button").addClass("button_style");
	});
});
