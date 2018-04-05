We will base our examples on a variable named animals:

var animals = ['dog', 'cat', 'monkey', 'donkey', 'dino', 'elephant'];
Example 1 - when no parameters are passed or only a positive start index in passed

animals.slice();
// ["dog", "cat", "monkey", "donkey", "dino", "elephant"]
animals.slice(0);
// ["dog", "cat", "monkey", "donkey", "dino", "elephant"]
animals.slice(1);
// ["cat", "monkey", "donkey", "dino", "elephant"]
Example 2 - when a negative start index in passed

animals.slice(-1)
//["elephant"]
animals.slice(-2)
//["dino", "elephant"]
animals.slice(-999999)
//["dog", "cat", "monkey", "donkey", "dino", "elephant"]
Example 3 - when both the start and end indexes are passed (both positive)

animals.slice(0, 1)
//["dog"]
animals.slice(0, 2)
//["dog", "cat"]
animals.slice(2, 2)
//[]
animals.slice(2, 3)
//["monkey"]
animals.slice(2, 5)
//["monkey", "donkey", "dino"]
Example 4 - when both the start and end indexes are passed (end index negative)

animals.slice(1, -1)
//["cat", "monkey", "donkey", "dino"]
animals.slice(1, -2)
//["cat", "monkey", "donkey"]
Example 4 - when an end index is passed with a negative start index

animals.slice(-1, 0)
//[]
animals.slice(-1, -2)
//[]
animals.slice(-1, 1)
//[]
It may appear like slice() can be used to create copies of items in an array, but is unreliable. Take a look at this example:

var people = [{name:'John', age:32}, {name:'Peter', age:154}];
var clone = people.slice(1);
console.log(clone);
>> [Object { name="Peter", age=154}]
clone[0].age = 10;
console.log(people);
>> [Object { name="John", age=32}, Object { name="Peter", age=10}]