var _mysql = require('mysql');

var HOST = 'localhost';
var PORT = 3306;
var MYSQL_USER = 'nodehacker';
var MYSQL_PASS = 'lulwut';
var DATABASE = 'nodedb';
var TABLE = 'gadgets';

var mysql = _mysql.createClient({
    host: HOST,
    port: PORT,
    user: MYSQL_USER,
    password: MYSQL_PASS,
});

mysql.query('use ' + DATABASE);




mysql.query('select id, name, price from ' + TABLE + ' where price < 100',
function(err, result, fields) {
    if (err) throw err;
    else {
        console.log('Gadgets which costs less than $100');
        console.log('----------------------------------');
        for (var i in result) {
            var gadget = result[i];
            console.log(gadget.name +': '+ gadget.price);
        }
    }
});




mysql.query('insert into '+ TABLE +' (name, price) values ("' + req.body.name + '", "' + req.body.name.price + '")',
function selectCb(err, results, fields) {
    if (err) throw err;
    else res.send('success');
});



client.query('INSERT INTO my_table SET title = "Node and MySQL"', function(err, info) {
  console.log(info.insertId);
});

