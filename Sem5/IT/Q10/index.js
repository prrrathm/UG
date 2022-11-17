var http = require("http");
http
	.createServer(function (req, res) {
		res.write("Hello World, This is my Node.js server.");
		res.end();
	})
	.listen(8000);
