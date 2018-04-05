var hero = new Array();
hero['name'] = 'batman';
hero['id'] = 'Bruce Wayne';
hero['city'] = 'Gotham City';

for (var p in hero) {
    console.log(p+': '+hero[p]);
}

console.log(hero['id']);
console.log(hero.id);


console.log(hero.length);
hero[0] = 'Joker';
console.log(hero.length);


