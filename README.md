Jag döpte spelet till flappy slime för det var lite för korngligt att rita en hel fågel eller nått annat så kanske hermade han taco snubben förutom med två ögon :)

Det blev lite ändringar, nu är det enklare att röra olika iconer upp och ner och till sidan, innan var det lite hackigt. 
Nu för att skapa en icon så skapar man två uint8_t grejer i mipslabsdata där en innehåller rader (rows) och den andra innehåller kolummner(col)
det är lite mycket men det gjorde det mycket enklare att få allt att röra sig och man kan se det som en lista typ,
för nu kan man ta allt och kasta in i de olika metoderna så funkar det ganska bra.

Det finns inte några pipes än men det går snabbt att fixa, vi kan antingen göra några och sen bara göra en randommizer metod som välje vilken pipe den ska displaya typ (om du vet nått om sånna funktioner), eller göra några fler och får de rulla i nån loop dock blir det upprepning. 
Nu när det är lite enklare att röra allt så kan vi ha en "pekare" i main sidan som väljer start eller nått annat genom att använda dens koordinater och knapparna för att avgöra vad som ska hända. 

Det största vi har att göra är collisionen med pipsen och knappar och allt.
Med collisionen kan man kanske checka om coordinaterna på nått sätt matchar med pipsen, annars nördade erik ner sig och tyckte att vi kan använda algebra och geometri för att se om slimen träffar pipsen och har nått sätt att göra. 





