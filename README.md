# simple-atm

## Ongelma
Ohjelman tarkoitus on toimia yksinkertaisena pankkiautomaattisovelluksena. Käyttäjä
kirjautuu tililleen antamalla tilinumeronsa ja oikean PIN-koodin. Kirjautumisen jälkeen
käyttäjä voi suorittaa kolme erilaista toimintoa: tehdä nosto tililtään, tarkistaa tilinsä saldon
tai lopettaa ohjelman.

## Ratkaisu
Ohjelman ratkaisu jakautuu useisiin funktioihin, jotka suorittavat eri toiminnot. Pääfunktio
”main” hallinnoi käyttöliittymää ja kutsuu muita funktioita tarpeen mukaan. Ohjelman
tietorakenteet perustuvat yksinkertaiseen tilinumerolla varustettuun tiedostojärjestelmään,
missä jokaisella tilillä on omat tietonsa (esim. ”12345.acc”)
Käyttäjän kirjautuessa ”kirjautuminen”-funktio tarkistaa tilinumeron ja PIN-koodin
oikeellisuuden. Kun kirjautuminen onnistuu, käyttäjälle annetaan mahdollisuus tehdä nosto
”otto”-funktiolla, tarkistaa saldo ”saldokysely”-funktiolla tai lopettaa ohjelma ”lopetus”-
funktiolla. Nostotoiminnossa käytetään myös ”rahanjakoalgoritmi”-funktiota jakamaan
halutun summan 50€ ja 20€ seteleihin.

## Käyttöohjeet

### Kuvaus
Ohjelma käynnistetään suorittamalla se, ja käyttö aloitetaan antamalla oikea tilinumero.
Tämän jälkeen käyttäjä syöttää PIN-koodin. Jos kirjautuminen onnistuu, käyttäjä näkee
päävalikon, josta valitaan haluttu toiminto antamalla vastaava numero. Ohjelma ohjeistaa
käyttäjää syöttämään nostosumman ja näyttää sen jälkeen tuloksen tai ilmoittaa virheestä.

### Ohjelman käynnistäminen
- Ohjelma käynnistetään suorittamalla se.
- Ohjelma on käynnistynyt, kun näytölle tulee kirjautumisruutu.
  
### Kirjautuminen
- Syötä tilinumero kirjautumisruutuun. Ohjelma olettaa, että tilinumeron tiedosto
löytyy samasta hakemistosta ja on nimetty muodossa ”tilinumero.acc” (esim.
”12345.acc”).
- Paina Enter.
- Syötä oikea PIN-koodi, jonka löydät tilinumero.acc-tiedostosta.
- Paina Enter.
  
### Päävalikko
- Päävalikossa näet kolme vaihtoehtoa:
 - Otto: Nostaa rahaa tililtäsi.
 - Saldo: Näyttää tilin saldon.
 - Lopeta: Kirjaa sinut ulos ohjelmasta.

### Otto
- Valitse 1 ja paina Enter.
- Syötä nostettava summa euroina. Huomioi seuraavat rajoitukset:
  - Summan tulee olla positiivinen.
  - Automaatti antaa vain 20€ ja 50€ seteleitä.
  - Eli minimisumma 20, sitten 40, jonka jälkeen kymmenen euron välein.
  - Kertanosto voi olla enintään 1000€.

### Saldo
- Valitse 2 ja paina Enter.
- Ohjelma näyttää tilin saldon.

### Lopeta
- Valitse 3 ja paina Enter.
- Ohjelma kirjaa sinut ulos ja sulkeutuu.

### Syötteiden muoto ja tulosten tulkitseminen
- Kaikki syötteet annetaan numeroina.
- Tulokset ilmoitetaan teksti- ja numeromuodossa.
- Virheilmoitukset kertovat mahdollisista ongelmista syötteissä.

### Ohjelman käyttöön liittyvät rajoitukset
- Ohjelma olettaa, että tilinumeron tiedosto löytyy samasta hakemistosta ja on nimetty
muodossa ”tilinumero.acc” (esim. ”12345.acc”).
- Oikea PIN-koodi tulee löytyä tilinumero.acc-tiedostosta.
- Nostossa nostettavan summan rajoitukset (kts. Otto).
- Tilin saldo ei voi olla negatiivinen.
- Tilinumeron, sekä PIN-koodin maksimipituus on 256 merkkiä.
