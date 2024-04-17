var bellBoy =
{
    boyname : "Ayush",
    yearsofexp : 15,
    places:["Delhi"]
}

function BellBoy(boyname, yearsofexp, places)
{
    this.boyname = boyname;
    this.yearsofexp = yearsofexp;
    this.places = places;
}

var bellBoy = new BellBoy("Krishna", 12, ["Delhi", "Banglore"]);

console.log(bellBoy.boyname);