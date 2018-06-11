#include <string.h>
#include <klima_defines.h>

/*
Funktion zum festlegen der standartwerte neuer KLIMADATEN 
*/
KLIMADATEN new_klimadaten(void){
	KLIMADATEN new_klima;
	new_klima.stat = 0;
	new_klima.jjjjmmdd = 0;
	new_klima.qn = 0;
	new_klima.tg = 0.0;
	new_klima.tn = 0.0;
	new_klima.tm = 0.0;
	new_klima.tx = 0.0;
	new_klima.rfm = 0.0;
	new_klima.fm = 0.0;
	new_klima.fx = 0.0;
	new_klima.so = 0.0;
	new_klima.nm = 0.0;
	new_klima.rr = 0.0;
	new_klima.pm = 0.0;
	return new_klima;
}

/*
Funktion zum 0 setzten der werte ab einschliesslich tg bei formatfehler
*/
void setze_werte_0(KLIMADATEN *k){
	k->tg = 0.0;
	k->tn = 0.0;
	k->tm = 0.0;
	k->tx = 0.0;
	k->rfm = 0.0;
	k->fm = 0.0;
	k->fx = 0.0;
	k->so = 0.0;
	k->nm = 0.0;
	k->rr = 0.0;
	k->pm = 0.0;
	return;
}

/*
Funktion zum festlegen der standartwerte eines DATUM Struct
*/
DATUM new_datum(void){
	DATUM new_dat;
	new_dat.jahr = 0;
	memset(new_dat.monat, '\0', 16);
	new_dat.tag = 0;
	return new_dat;
}

/*
Funktion zum festlegen der standartwerte neuer TEMPERATUREN
*/
TEMPERATUR new_temperatur(void){
	TEMPERATUR new_temp;
	new_temp.stat = 0;
	new_temp.datum = new_datum();
	new_temp.tg = 0.0;
	new_temp.tn = 0.0;
	new_temp.tm = 0.0;
	new_temp.tx = 0.0;
	return new_temp;
}

/*
Funktion zum festlegen der standartwerte neuer FILEINFORMATION
*/
FILEINFORMATION new_fileinformation(void){
	FILEINFORMATION new_info;
	new_info.kopfzeilen = 0;
	new_info.anzahl_datensaetze = 0;
	return new_info;
}
