---
type: university
date: 2024-06-19
subjectId: 2202
year: 2
semester: 2
---
#university #studying #subject-2202
### Protocollo LRDC
> [!summary] Reti di Calcolatori

LRDC = Laboratorio di Reti Di Calcolatori
xd

#### Configurazione Reti

Ricordo che: in IPv6 ho 128 bit.
Sono 8 campi da 4 cifre esadecimali (ovvero 16 bit per blocco)

es.
```
--- Networks ---
LAN 1
	149.54.0.0/22

LAN 2
	149.54.4.0/22

LAN 3
	149.54.8.0/22

LAN R
	149.54.12.0/30


--- Hosts ---
[LAN 1]: Client 1
	- Address: 149.58.0.100/22
	- Gateway: 149.58.0.1
[LAN 2]: Client 2
	- Address: 149.58.4.100/22
	- Gateway: 149.58.4.1
[LAN 3]: Server
	- Address: 149.58.8.100/22
	- Gateway: 149.58.8.1
Router A
	- enp0s8: 149.58.0.1/22	[LAN 1]
	- enp0s9: 149.58.4.1/22	[LAN 2]
	- enp0s10: 149.58.12.1/30 [LAN R]
Router B
	- enp0s8: 149.58.12.2/30 [LAN R]
	- enp0s9: 149.58.8.1/22 [LAN 3]
```

1. Riordino le reti per numero di host in ordine decrescente.
2. Per ogni LAN, tramite numero di host, mi ricavo la subnet (e quindi la rete)
3. Per ogni host: scrivo IP/subnet + gateway + LAN di appartenenza
4. Per ogni interfaccia di ogni router: scrivo IP/subnet + LAN di appartenenza

Convenzione nodi in IPv4 (se la rete è abbastanza grande):
- `.100`, `.101`,  `...` sono gli host
- `.1`, `.2`,  `...` sono i router (nelle LAN tra router, ci sono più router)

Convenzione nodi in IPv6:
- non prevista

Esempio calcolo subnet IPv6:
```
Rete di partenza = `3:1::0`

LAN 1 (5000 host)
	Prendo la potenza di due più piccola maggiore di 5000
	Siccome 2^10 = 1024, mi servono 13 bits (8*1024).
	Devo lasciare liberi il primo e l'ultimo indirizzo

	Blocco i 128-13 bit della "maschera di bit"
	[:000x xxxx xxxx xxxx]

	Ottengo intervallo rete
	[:0000 0000 0000 0000] -> 3:1::0
	[:0001 1111 1111 1111] -> 3:1::1FFF

	Ottengo intervallo utilizzabile (escludo primo e ultimo indirizzo)
	[:0000 0000 0000 0001] -> 3:1::1
	[:0001 1111 1111 1110] -> 3:1::1FFE

LAN 2 (2046 host)
	Mi servono 11 bit
	L'ultimo indirizzo occupato è da 3:1::1FFF
	A questo indirizzo sommo `1`
	[:0001 1111 1111 1111] + 1 = [:0010 0000 0000 0000]

	Parto quindi da [:0010 0000 0000 0000] e blocco i 128-11 bit della maschera
	[:0010 0xxx xxxx xxxx]
		
	Ottengo intervallo rete
	[:0010 0000 0000 0000] -> 3:1::20
	[:0010 0111 1111 1111] -> 3:1::27FF

	Ottengo intervallo utilizzabile (escludo primo e ultimo indirizzo)
	[:0010 0000 0000 0001] -> 3:1::21
	[:0010 0111 1111 1110] -> 3:1::27FE
```


#### Configurazione VirtualBox (VB)

Controllare se è presente la "host-only network" su VirtualBox "vboxnet0".
Nella duplicazione mettere sempre **linked-clone** e **generate new mac**.

##### se client/server
1. Copia macchina originale
2. Crea due schede di reti:
	- una Host-Only (vboxnet0)
	- una Internal Network (metti la LAN corretta - rispetta lo schema di sopra)
3. Avvia la macchina
4. Abilita le interfacce con `ip link set dev enp0s8 up`
5. Modifica `/etc/network/interfaces`:
	- Copia la configurazione della scheda di rete default (`allow-hotplug enp0s3` e `iface enp0s3 inet dhcp)
		- se IPv6 al posto di `inet` metti `inet6` 
	- Modifica `enp0s3` in `enp0s8`
	- Modifica `dhcp` in `static`.
	- Aggiungi `address 192.168.1.100/24` e `gateway 192.168.1.1`

per i client/server successivi:
1. Chiudere il primo client/server con Save Current State
2. Duplicare la macchina
3. Modificare il nome della LAN nell'interfaccia della nuova macchina (da VB)
4. Avviare la macchina
5. Modificare IP e gateway

Riavviare tutte le macchine per il cambio di configurazione

##### se router
Come client/server ma non c'è gateway.
Poi:
- Aggiungi più interfacce
- Abilita il forwarding andando in `/etc/sysctl.conf` e scommentando la riga `net.ipv4.ip_forwarding=1`
	- se IPv6 va scommentato `net.ipv6.conf.all.forwarding=1`
- Aggiungere le route sempre in `/etc/network/interfaces` aggiungendo `up ip route add <address> via <host>` (host è senza `/xx`)
	- come `<address>` puoi mettere un ip o `default`.
	- in IPv6 si mette `up ip -6 route ...` al posto di `up ip route ...`

