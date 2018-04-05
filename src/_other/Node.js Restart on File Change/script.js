// this script will do interesting stuff only if the name is 'Sparrow'
if (name == 'Sparrow') {
  result = 'Captain ' + name + ' has ' + pets.length + ' pet' + (pets.length? 's' : '') + ': ';
  pets.forEach(function(pet) {
      result +=  pet.name + ' - the ' + pet.species + ', ';
  });
  
  result = result.replace(/, $/, '.');
}
else {
  result = 'Invalid User';
}