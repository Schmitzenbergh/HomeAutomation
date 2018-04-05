var o = {'name':'Batman', 'age':33, 'city':'Gotham City'};
for (var p in o) {
    console.log(p+': '+o[p]);
}


var animals = ['cat', 'dog', 'monkey', 'donkey'];
for (var p in animals) {
    console.log(animals[p]);
}

for (var p in document) { console.log(p + ': '+ document[p]); }

for (var p in window) { console.log(p + ': '+ window[p]); }

