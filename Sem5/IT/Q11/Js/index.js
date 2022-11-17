var http = require('http')
var mysql = require('mysql')
var db = require('../Database/createDb')
var con = mysql.createConnection({
    user: 'root',
    host: 'localhost',
    password: 'khanbhai',
    database: 'itLab11'
})

con.connect(function (err) {
    if (err)
        throw err;
    console.log("Database connected successfully.");
    var table = "create table if not exists andc(Name varchar(20), Designation varchar(10), Email varchar(50) Primary Key, Password varchar(10)) "
    con.query(table, function (err) {
        if (err)
            console.log(err)
        console.log("Table created successfully.")
    })
})




http.createServer(function (req, res) {
    // Setting headers to bypass CROS policy
    res.setHeader('Access-Control-Allow-Origin', '*');
    res.setHeader('Access-Control-Request-Method', '*');
    res.setHeader('Access-Control-Allow-Methods', 'POST', 'GET', 'OPTIONS');
    res.setHeader('Access-Control-Allow-Headers', '*');

    if (req.method === "POST") { //Post method
        var body = "";
        req.on("data", function (chunk) {
            body += chunk;
        });
        req.on("end", function () {
            body = JSON.parse(body)
            console.log(body)
            if (req.url == '/signUp') {
                // check if the user already exists or not 
                let flag = true;
                var findUser = `select * from andc where Email = '${body.email}';`
                con.query(findUser, function (err, result) {
                    console.log("Here I am")
                    console.log(result, result.length)
                    if (result.length != 0) {
                        flag = false;
                        console.log("User already exists.")
                        res.statusMessage = 'User already exists!'
                        res.end()
                    }
                })
                if (flag) { // If new user
                    var query = `insert into andc (Name,Designation,Email,Password) values('${body.name}','${body.designation}','${body.email}','${body.password}')`
                    con.query(query, function (err) {
                        if (err) {
                            console.log(err)
                            res.statusMessage = 'Server Error!'
                            res.end()

                        } else {
                            res.statusMessage = 'Created'
                            res.end()
                        }
                    })
                }
            }
            else if (req.url == '/signIn') {
                var query = `select * from andc where Email = '${body.email}' AND Password = '${body.password}' `;
                con.query(query, function (err, result) {
                    if (err) {
                        console.log(err)
                        res.statusMessage = 'Server Error'
                        res.end()
                    } else if (result.length == 0) {
                        console.log("No entry found.")
                        res.statusMessage = "Not Found"
                        res.end();
                    } else {
                        console.log("Welcome.")
                        res.statusMessage = "Found"
                        res.end();
                    }
                })
            }

        });



    } else console.log(req.method, req.url)
    // res.end();
}).listen(3000)