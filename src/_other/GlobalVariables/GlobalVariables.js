> global.name
undefined
> global.name = 'El Capitan'
> global.name
'El Capitan'
> GLOBAL.name
'El Capitan'
> delete global.name
true
> GLOBAL.name
undefined
> name = 'El Capitan'
'El Capitan'
> global.name
'El Capitan'
> GLOBAL.name
'El Capitan'
> var name = 'Sparrow'
undefined
> global.name
'Sparrow'




var company = 'Yahoo';
console.log(global.company); // 'Google'
console.log(company); // 'Yahoo'








